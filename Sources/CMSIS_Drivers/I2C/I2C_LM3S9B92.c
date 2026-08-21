/*
 * Copyright (c) 2013-2020 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdbool.h>

#ifdef   _RTE_
#include "RTE_Components.h"
#ifdef    RTE_RTX_CONFIG_H
#include  RTE_RTX_CONFIG_H
#endif
#endif

#include CMSIS_device_header
#include "I2C_LM3S9B92_Config.h"
#include "SYS_LM3S9B92_Config.h"

#include "driver_utils.h"

#include "Driver_I2C.h"

#define ARM_I2C_DRV_VERSION    ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0)

#define I2C_STATUS_BUSY_MASK   (*(const uint32_t *)&(const ARM_I2C_STATUS){.busy = 1U })
#define I2C_STATUS_MASTER_MASK (*(const uint32_t *)&(const ARM_I2C_STATUS){.mode = 1U })
#define I2C_MTPR_TPR_BIT_WIDTH (7U)

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_I2C_API_VERSION,
    ARM_I2C_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_I2C_CAPABILITIES DriverCapabilities = {
    0,  /* supports 10-bit addressing */
    0
};

typedef const struct LM3S_I2C_Pin_Config_s {
    uint32_t   pinNum;
    GPIO_Type* pinPort;
    uint32_t   portClkMask;
    uint32_t   pinCtlMsk;
    uint32_t   pinCtlCode;
}LM3S_I2C_Pin_Config_t;

typedef struct LM3S_I2C_DrvControl_s{
    ARM_I2C_SignalEvent_t cbEvent;
    ARM_I2C_STATUS        status;
    bool                  isInitialized;
    bool                  isPowered;
    uint8_t*              pData;
    uint32_t              numBytes;
    uint32_t              cntBytes;
    uint16_t              slaveAddr;
    bool                  slaveSelected;
    bool                  pendingStop;
} LM3S_I2C_DrvControl_t;

typedef const struct LM3S_I2C_DrvResources_s{
    I2C_MASTER_Type*       master;
    I2C_SLAVE_Type*        slave;
    uint32_t               irqNum;
    uint32_t               runClockMask;
#if defined(SYS_USE_ACG) && (SYS_USE_ACG == 1)
    uint32_t               sleepClockMask;
    uint32_t               deepsleepClockMask;
#endif
    LM3S_I2C_Pin_Config_t* sclPin;
    LM3S_I2C_Pin_Config_t* sdaPin;
} LM3S_I2C_DrvResources_t;

typedef const struct LM3S_I2C_DrvInstance_s {
    LM3S_I2C_DrvControl_t*                control;
    const LM3S_I2C_DrvResources_t* const resources;
} LM3S_I2C_DrvInstance_t;

static LM3S_I2C_Pin_Config_t I2C0_Scl_pin = {
    RTE_I2C0_SCL_PIN,
    RTE_I2C0_SCL_PORT,
    RTE_I2C0_SCL_PORT_CLOCK_EN_Msk,
    RTE_I2C0_SCL_PCTL_MASK,
    RTE_I2C0_SCL_PCTL_CODE
};

static LM3S_I2C_Pin_Config_t I2C0_Sda_pin = {
    RTE_I2C0_SDA_PIN,
    RTE_I2C0_SDA_PORT,
    RTE_I2C0_SDA_PORT_CLOCK_EN_Msk,
    RTE_I2C0_SDA_PCTL_MASK,
    RTE_I2C0_SDA_PCTL_CODE
};

static LM3S_I2C_Pin_Config_t I2C1_Scl_pin = {
    RTE_I2C1_SCL_PIN,
    RTE_I2C1_SCL_PORT,
    RTE_I2C1_SCL_PORT_CLOCK_EN_Msk,
    RTE_I2C1_SCL_PCTL_MASK,
    RTE_I2C1_SCL_PCTL_CODE
};

static LM3S_I2C_Pin_Config_t I2C1_Sda_pin = {
    RTE_I2C1_SDA_PIN,
    RTE_I2C1_SDA_PORT,
    RTE_I2C1_SDA_PORT_CLOCK_EN_Msk,
    RTE_I2C1_SDA_PCTL_MASK,
    RTE_I2C1_SDA_PCTL_CODE
    
};

static LM3S_I2C_DrvResources_t I2C0_Resources = {
    I2C_MASTER0,
    I2C_SLAVE0,
    I2C0_IRQn,
    SYSCTL_RCGC1_I2C0_Msk,
#if defined(SYS_USE_ACG) && (SYS_USE_ACG == 1)
#if defined(RTE_I2C0_SLEEP_USER_SET) && (RTE_I2C0_SLEEP_USER_SET == 1)
    SYSCTL_SCGC1_I2C0_Msk,
#elif (RTE_I2C0_SLEEP_USER_SET == 0)
    0
#else
    #error "Inconsistency in Config file, check I2C_LM3S9B92_Config.h!"
#endif
#if defined(RTE_I2C0_DEEPSLEEP_USER_SET) && (RTE_I2C0_DEEPSLEEP_USER_SET == 1)
    SYSCTL_DCGC1_I2C0_Msk,
#elif (RTE_I2C0_DEEPSLEEP_USER_SET == 0)
    0
#else
    #error "Inconsistency in Config file, check I2C_LM3S9B92_Config.h!"
#endif
#endif
    &I2C0_Scl_pin,
    &I2C0_Sda_pin
};

static LM3S_I2C_DrvResources_t I2C1_Resources = {
    I2C_MASTER1,
    I2C_SLAVE1,
    I2C1_IRQn,
    SYSCTL_RCGC1_I2C1_Msk,
#if defined(SYS_USE_ACG) && (SYS_USE_ACG == 1)
#if defined(RTE_I2C1_SLEEP_USER_SET) && (RTE_I2C1_SLEEP_USER_SET == 1)
    SYSCTL_SCGC1_I2C1_Msk,
#elif (RTE_I2C1_SLEEP_USER_SET == 0)
    0
#else
    #error "Inconsistency in Config file, check I2C_LM3S9B92_Config.h!"
#endif
#if defined(RTE_I2C1_DEEPSLEEP_USER_SET) && (RTE_I2C1_DEEPSLEEP_USER_SET == 1)
    SYSCTL_DCGC1_I2C1_Msk,
#elif (RTE_I2C1_DEEPSLEEP_USER_SET == 0)
    0
#else
    #error "Inconsistency in Config file, check I2C_LM3S9B92_Config.h!"
#endif
#endif
    &I2C1_Scl_pin,
    &I2C1_Sda_pin
};

static LM3S_I2C_DrvControl_t I2C0_Ctrl = {
    NULL,
    {0},
    false,
    false,
    NULL,
    0,
    0,
    0,
    false,
    false
};

static LM3S_I2C_DrvControl_t I2C1_Ctrl = {
    NULL,
    {0},
    false,
    false,
    NULL,
    0,
    0,
    0,
    false,
    false
};

const LM3S_I2C_DrvInstance_t I2C0_Inst = {
    .control   = &I2C0_Ctrl,
    .resources = &I2C0_Resources
};

const LM3S_I2C_DrvInstance_t I2C1_Inst = {
    .control   = &I2C1_Ctrl,
    .resources = &I2C1_Resources
};

static const ARM_I2C_STATUS clean_status = {0};

static ARM_DRIVER_VERSION LM3S_I2C_GetVersion(void);
static ARM_I2C_CAPABILITIES LM3S_I2C_GetCapabilities(void);
static int32_t LM3S_I2C_Initialize(LM3S_I2C_DrvInstance_t *i2c, ARM_I2C_SignalEvent_t cb_event);
static int32_t ARM_I2C_Uninitialize(LM3S_I2C_DrvInstance_t *i2c);
static int32_t ARM_I2C_PowerControl(LM3S_I2C_DrvInstance_t *i2c, ARM_POWER_STATE state);
static int32_t I2C_Buffer_Lock(ARM_I2C_STATUS *status);
__STATIC_INLINE uint32_t I2C_CalcMTPR(uint32_t sys_clk, uint32_t i2c_clk);
static void I2C_Delay_BitBang(void);
static int32_t I2C_BusClear(LM3S_I2C_DrvInstance_t *i2c);

static ARM_DRIVER_VERSION LM3S_I2C_GetVersion(void) {
  return DriverVersion;
}

static ARM_I2C_CAPABILITIES LM3S_I2C_GetCapabilities(void) {
  return DriverCapabilities;
}

static int32_t LM3S_I2C_Initialize(LM3S_I2C_DrvInstance_t *i2c, ARM_I2C_SignalEvent_t cb_event) {
    if (i2c->control->isInitialized) {
        if (i2c->control->status.busy == 0U) {
            i2c->control->cbEvent = cb_event;
        }
        return ARM_DRIVER_OK;
    }

    SET_REG(SYSCTL->RCGC2, i2c->resources->sclPin->portClkMask);
    SET_REG(SYSCTL->RCGC2, i2c->resources->sdaPin->portClkMask);
#if defined (SYS_USE_ACG) && (SYS_USE_ACG == 1)
    if (i2c->resources->sleepClockMask){
        SET_REG(SYSCTL->SCGC2, i2c->resources->sclPin->portClkMask);
        SET_REG(SYSCTL->SCGC2, i2c->resources->sdaPin->portClkMask);
    }
    if (i2c->resources->deepsleepClockMask){
        SET_REG(SYSCTL->DCGC2, i2c->resources->sclPin->portClkMask);
        SET_REG(SYSCTL->DCGC2, i2c->resources->sdaPin->portClkMask);
    }
#elif !defined (SYS_USE_ACG)
    #error "Global system setting (ACG) is missing! Check SYS_LM3S9B92_Config.h"
#endif
    
    __NOP(); __NOP(); __NOP();
    
    MODIFY_REG(i2c->resources->sclPin->pinPort->PCTL, i2c->resources->sclPin->pinCtlMsk, i2c->resources->sclPin->pinCtlCode);
    SET_BIT(i2c->resources->sclPin->pinPort->AFSEL,   i2c->resources->sclPin->pinNum);
    SET_BIT(i2c->resources->sclPin->pinPort->ODR,     i2c->resources->sclPin->pinNum);
    SET_BIT(i2c->resources->sclPin->pinPort->PUR,     i2c->resources->sclPin->pinNum);
    SET_BIT(i2c->resources->sclPin->pinPort->DEN,     i2c->resources->sclPin->pinNum);
    
    MODIFY_REG(i2c->resources->sdaPin->pinPort->PCTL, i2c->resources->sdaPin->pinCtlMsk, i2c->resources->sdaPin->pinCtlCode);
    SET_BIT(i2c->resources->sdaPin->pinPort->AFSEL,   i2c->resources->sdaPin->pinNum);
    SET_BIT(i2c->resources->sdaPin->pinPort->ODR,     i2c->resources->sdaPin->pinNum);
    SET_BIT(i2c->resources->sdaPin->pinPort->PUR,     i2c->resources->sdaPin->pinNum);
    SET_BIT(i2c->resources->sdaPin->pinPort->DEN,     i2c->resources->sdaPin->pinNum);
    
    i2c->control->slaveSelected = false;
    i2c->control->cbEvent       = cb_event;
    i2c->control->isInitialized = true;
    
    return ARM_DRIVER_OK;
}

static int32_t LM3S_I2C0_Initialize(ARM_I2C_SignalEvent_t cb_event) {
    return LM3S_I2C_Initialize(&I2C0_Inst, cb_event);
}

static int32_t LM3S_I2C1_Initialize(ARM_I2C_SignalEvent_t cb_event) {
    return LM3S_I2C_Initialize(&I2C1_Inst, cb_event);
}

static int32_t ARM_I2C_Uninitialize(LM3S_I2C_DrvInstance_t *i2c) {
    if(i2c->control->isInitialized == false) {
        return ARM_DRIVER_OK;
    }
    
    if (i2c->control->isPowered != 0) {
        (void)ARM_I2C_PowerControl(i2c, ARM_POWER_OFF);
    }
    
    CLEAR_BIT(i2c->resources->sclPin->pinPort->DEN,   i2c->resources->sclPin->pinNum);
    CLEAR_BIT(i2c->resources->sclPin->pinPort->AFSEL, i2c->resources->sclPin->pinNum);
    CLEAR_REG(i2c->resources->sclPin->pinPort->PCTL,  i2c->resources->sclPin->pinCtlMsk);
    CLEAR_BIT(i2c->resources->sclPin->pinPort->ODR,   i2c->resources->sclPin->pinNum);
    CLEAR_BIT(i2c->resources->sclPin->pinPort->PUR,   i2c->resources->sclPin->pinNum);
    CLEAR_BIT(i2c->resources->sclPin->pinPort->DIR,   i2c->resources->sclPin->pinNum);
    
    CLEAR_BIT(i2c->resources->sdaPin->pinPort->DEN,   i2c->resources->sdaPin->pinNum);
    CLEAR_BIT(i2c->resources->sdaPin->pinPort->AFSEL, i2c->resources->sdaPin->pinNum);
    CLEAR_REG(i2c->resources->sdaPin->pinPort->PCTL,  i2c->resources->sdaPin->pinCtlMsk);
    CLEAR_BIT(i2c->resources->sdaPin->pinPort->ODR,   i2c->resources->sdaPin->pinNum);
    CLEAR_BIT(i2c->resources->sdaPin->pinPort->PUR,   i2c->resources->sdaPin->pinNum);
    CLEAR_BIT(i2c->resources->sdaPin->pinPort->DIR,   i2c->resources->sdaPin->pinNum);
    
    i2c->control->cbEvent       = NULL;
    i2c->control->pData         = NULL;
    i2c->control->numBytes      = 0U;
    i2c->control->cntBytes      = 0U;
    i2c->control->status        = (ARM_I2C_STATUS){0};
    i2c->control->slaveSelected = false;
    i2c->control->isInitialized = false;
    
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C0_Uninitialize(void) {
    return ARM_I2C_Uninitialize(&I2C0_Inst);
}

static int32_t ARM_I2C1_Uninitialize(void) {
    return ARM_I2C_Uninitialize(&I2C1_Inst);
}

static int32_t ARM_I2C_PowerControl(LM3S_I2C_DrvInstance_t *i2c, ARM_POWER_STATE state) {
    int32_t status;
    
    status = ARM_DRIVER_OK;
    switch (state) {
        case ARM_POWER_OFF:
            if (i2c->control->isPowered == false) {
                break;
            }
            i2c->resources->master->CTRL = 0;
            i2c->resources->slave->CTRL  = 0;
            i2c->control->pData        = NULL;
            i2c->control->numBytes     = 0U;
            i2c->control->cntBytes     = 0U;
            i2c->control->status       = (ARM_I2C_STATUS){0};
            
            NVIC_DisableIRQ(i2c->resources->irqNum);
            WRITE_REG(i2c->resources->slave->IMR,  0x00UL);
            WRITE_REG(i2c->resources->master->IMR, 0x00UL);
            WRITE_REG(i2c->resources->master->CR,  0x00UL);
            WRITE_REG(i2c->resources->slave->CTRL, 0x00UL);
            
            CLEAR_REG(SYSCTL->RCGC1, i2c->resources->runClockMask);
#if defined (SYS_USE_ACG) && (SYS_USE_ACG == 1)
            CLEAR_REG(SYSCTL->SCGC1, i2c->resources->runClockMask);
            CLEAR_REG(SYSCTL->DCGC1, i2c->resources->runClockMask);
#elif !defined(SYS_USE_ACG)
#error "Global system setting (ACG) is missing! Check SYS_LM3S9B92_Config.h"
#endif
            i2c->control->slaveSelected = false;
            i2c->control->isPowered = false;
            break;

        case ARM_POWER_LOW:
            status = ARM_DRIVER_ERROR_UNSUPPORTED;
            break;

        case ARM_POWER_FULL:
            if (i2c->control->isInitialized == false) {
                status = ARM_DRIVER_ERROR;
                break;
            }
            if (i2c->control->isPowered != false) {
                break;
            }
            SET_REG(SYSCTL->RCGC1, i2c->resources->runClockMask);
#if defined (SYS_USE_ACG) && (SYS_USE_ACG == 1)
            if (i2c->resources->sleepClockMask){
                SET_REG(SYSCTL->SCGC1, i2c->resources->sleepClockMask);
            }
            if (i2c->resources->deepsleepClockMask){
                SET_REG(SYSCTL->DCGC1, i2c->resources->deepsleepClockMask);
            }
#elif !defined (SYS_USE_ACG)
#error "Global system setting (ACG) is missing! Check SYS_LM3S9B92_Config.h"
#endif
            __NOP();__NOP();__NOP();
            
            WRITE_REG(i2c->resources->master->CR, I2C_MASTER_CR_SFE_Msk | I2C_MASTER_CR_MFE_Msk);
            __NOP(); __NOP(); __NOP(); __NOP(); __NOP();
            WRITE_REG(i2c->resources->slave->OA, 0x7FUL);
            SET_REG(i2c->resources->master->IMR, I2C_MASTER_IMR_IM_Msk);
            SET_REG(i2c->resources->slave->IMR, I2C_SLAVE_IMR_STOPIM_Msk | I2C_SLAVE_IMR_STARTIM_Msk | I2C_SLAVE_IMR_DATAIM_Msk);
            
            NVIC_EnableIRQ(i2c->resources->irqNum);
            
            i2c->control->isPowered = true;
            break;
    }

    return status;
}

static int32_t ARM_I2C0_PowerControl(ARM_POWER_STATE state) {
    return ARM_I2C_PowerControl(&I2C0_Inst, state);
}

static int32_t ARM_I2C1_PowerControl(ARM_POWER_STATE state) {
    return ARM_I2C_PowerControl(&I2C1_Inst, state);
}

static int32_t ARM_I2C_MasterTransmit(LM3S_I2C_DrvInstance_t *i2c, uint16_t addr, const uint8_t *data, uint32_t num, bool xfer_pending) {
    if ((data == NULL) || (num == 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    if (i2c->control->isInitialized == false) {
        return ARM_DRIVER_ERROR;
    }
    if (i2c->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }

    if (I2C_Buffer_Lock(&i2c->control->status) != ARM_DRIVER_OK) {
        return ARM_DRIVER_ERROR_BUSY;
    }
    
    i2c->control->pData    = (uint8_t *)data;
    i2c->control->numBytes = num;
    i2c->control->cntBytes = 0U;
    i2c->control->pendingStop = !xfer_pending;
    i2c->control->status.mode      = 1U;
    i2c->control->status.direction = 0U;
    
    WRITE_REG(i2c->resources->master->SA, (addr << 1));
    WRITE_REG(i2c->resources->master->DR, i2c->control->pData[0]);
    i2c->control->cntBytes++;
    
    if (i2c->control->numBytes == 1U) {
        if (i2c->control->pendingStop) {
            WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_START_Msk | I2C_MASTER_CTRL_RUN_Msk | I2C_MASTER_CTRL_STOP_Pos);
        } else {
            WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_START_Msk | I2C_MASTER_CTRL_RUN_Msk);
        }
    } 
    else {
        WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_START_Msk | I2C_MASTER_CTRL_RUN_Msk);
    }
    
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C0_MasterTransmit(uint32_t addr, const uint8_t *data, uint32_t num, bool xfer_pending) {
    return ARM_I2C_MasterTransmit(&I2C0_Inst, addr, data, num, xfer_pending);
}

static int32_t ARM_I2C1_MasterTransmit(uint32_t addr, const uint8_t *data, uint32_t num, bool xfer_pending) {
    return ARM_I2C_MasterTransmit(&I2C1_Inst, addr, data, num, xfer_pending);
}

static int32_t ARM_I2C_MasterReceive(LM3S_I2C_DrvInstance_t *i2c, uint32_t addr, uint8_t *data, uint32_t num, bool xfer_pending) {
    if ((data == NULL) || (num == 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    if (i2c->control->isInitialized == false) {
        return ARM_DRIVER_ERROR;
    }
    if (i2c->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }

    if (I2C_Buffer_Lock(&i2c->control->status) != ARM_DRIVER_OK) {
        return ARM_DRIVER_ERROR_BUSY;
    }
    
    i2c->control->pData    = data;
    i2c->control->numBytes = num;
    i2c->control->cntBytes = 0U;
    
    i2c->control->pendingStop = !xfer_pending;
    
    WRITE_REG(i2c->resources->master->SA, (addr << 1) | I2C_MASTER_SA_R_S_Msk);
    
    if (i2c->control->numBytes == 1U) {
        if (i2c->control->pendingStop) {
            WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_START_Msk | I2C_MASTER_CTRL_RUN_Msk | I2C_MASTER_CTRL_STOP_Pos);
        } else {
            WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_START_Msk | I2C_MASTER_CTRL_RUN_Msk);
        }
    } 
    else {
        WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_ACK_Msk | I2C_MASTER_CTRL_START_Msk | I2C_MASTER_CTRL_RUN_Msk);
    }
    
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C0_MasterReceive(uint32_t addr, uint8_t *data, uint32_t num, bool xfer_pending) {
    return ARM_I2C_MasterReceive(&I2C0_Inst, addr, data, num, xfer_pending);
}

static int32_t ARM_I2C1_MasterReceive(uint32_t addr, uint8_t *data, uint32_t num, bool xfer_pending) {
    return ARM_I2C_MasterReceive(&I2C1_Inst, addr, data, num, xfer_pending);
}

static int32_t ARM_I2C_SlaveTransmit(LM3S_I2C_DrvInstance_t *i2c, const uint8_t *data, uint32_t num) {
    if ((data == NULL) || (num == 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    if (i2c->control->isInitialized == false) {
        return ARM_DRIVER_ERROR;
    }
    if (i2c->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }
    
    if (I2C_Buffer_Lock(&i2c->control->status) != ARM_DRIVER_OK) {
        return ARM_DRIVER_ERROR_BUSY;
    }
    
    i2c->control->pData    = (uint8_t *)data;
    i2c->control->numBytes = num;
    i2c->control->cntBytes = 0U;
    
    i2c->control->status.mode      = 0U;
    i2c->control->status.direction = 0U;
    WRITE_REG(i2c->resources->slave->CTRL, I2C_SLAVE_CTRL_DA_Msk);
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C0_SlaveTransmit(const uint8_t *data, uint32_t num) {
    return ARM_I2C_SlaveTransmit(&I2C0_Inst, data, num);
}

static int32_t ARM_I2C1_SlaveTransmit(const uint8_t *data, uint32_t num) {
    return ARM_I2C_SlaveTransmit(&I2C1_Inst, data, num);
}

static int32_t ARM_I2C_SlaveReceive(LM3S_I2C_DrvInstance_t *i2c, uint8_t *data, uint32_t num) {
    if ((data == NULL) || (num == 0U)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }
    if (i2c->control->isInitialized == false) {
        return ARM_DRIVER_ERROR;
    }
    if (i2c->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }
    
    if (I2C_Buffer_Lock(&i2c->control->status) != ARM_DRIVER_OK) {
        return ARM_DRIVER_ERROR_BUSY;
    }
    
    i2c->control->pData    = data;
    i2c->control->numBytes = num;
    i2c->control->cntBytes = 0U;
    
    i2c->control->status.mode      = 0U;
    i2c->control->status.direction = 1U;
    WRITE_REG(i2c->resources->slave->CTRL, I2C_SLAVE_CTRL_DA_Msk);
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C0_SlaveReceive(uint8_t *data, uint32_t num) {
    return ARM_I2C_SlaveReceive(&I2C1_Inst, data, num);
}

static int32_t ARM_I2C1_SlaveReceive(uint8_t *data, uint32_t num) {
    return ARM_I2C_SlaveReceive(&I2C1_Inst, data, num);
}

static int32_t ARM_I2C_GetDataCount(LM3S_I2C_DrvInstance_t *i2c) {
    if (i2c->control->isInitialized == false) {
        return 0U;
    }
    return i2c->control->cntBytes;
}

static int32_t ARM_I2C0_GetDataCount(void) {
    return ARM_I2C_GetDataCount(&I2C0_Inst);
}

static int32_t ARM_I2C1_GetDataCount(void) {
    return ARM_I2C_GetDataCount(&I2C1_Inst);
}

static int32_t ARM_I2C_Control(LM3S_I2C_DrvInstance_t *i2c, uint32_t control, uint32_t arg) {
    uint32_t current_sys_clk;
    if (i2c->control->isInitialized == false) {
        return ARM_DRIVER_ERROR;
    }
    
    if (i2c->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }
    if (i2c->control->status.busy) {
        return ARM_DRIVER_ERROR_BUSY;
    }
    
    switch (control) {
        case ARM_I2C_OWN_ADDRESS:
            if (arg & ARM_I2C_ADDRESS_10BIT) {
                return ARM_DRIVER_ERROR_UNSUPPORTED;
            }
            WRITE_REG(i2c->resources->slave->OA, arg & I2C_SLAVE_OA_OAR_Msk);
            break;
        case ARM_I2C_BUS_SPEED:
            current_sys_clk = SystemCoreClock;
            switch (arg) {
                case ARM_I2C_BUS_SPEED_STANDARD:
                    WRITE_REG(i2c->resources->master->TPR, I2C_CalcMTPR(current_sys_clk, 100000U));
                    break;
                case ARM_I2C_BUS_SPEED_FAST:
                    WRITE_REG(i2c->resources->master->TPR, I2C_CalcMTPR(current_sys_clk, 400000U));
                    break;
                default:
                    return ARM_DRIVER_ERROR_UNSUPPORTED;
            }
            break;
        case ARM_I2C_BUS_CLEAR:
            return I2C_BusClear(i2c);
        case ARM_I2C_ABORT_TRANSFER:
            WRITE_REG(i2c->resources->master->CTRL, 0x00UL);
            WRITE_REG(i2c->resources->slave->CTRL, 0x00UL);
            i2c->control->pData    = NULL;
            i2c->control->numBytes = 0U;
            i2c->control->cntBytes = 0U;
            i2c->control->slaveSelected = false;
            i2c->control->status   = (ARM_I2C_STATUS){0};
            break;
        default:
            return ARM_DRIVER_ERROR_UNSUPPORTED;
    }
    
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C0_Control(uint32_t control, uint32_t arg) {
    return ARM_I2C_Control(&I2C0_Inst, control, arg);
}

static int32_t ARM_I2C1_Control(uint32_t control, uint32_t arg) {
    return ARM_I2C_Control(&I2C1_Inst, control, arg);
}

static ARM_I2C_STATUS ARM_I2C_GetStatus(LM3S_I2C_DrvInstance_t *i2c) {
    if ((i2c->control->isInitialized == false) || (i2c->control->isPowered == false)) {
        return (ARM_I2C_STATUS){0};
    }
    return i2c->control->status;
}

static ARM_I2C_STATUS ARM_I2C0_GetStatus(void) {
    return ARM_I2C_GetStatus(&I2C0_Inst);
}

static ARM_I2C_STATUS ARM_I2C1_GetStatus(void) {
    return ARM_I2C_GetStatus(&I2C1_Inst);
}
// End I2C Interface

static int32_t I2C_Buffer_Lock(ARM_I2C_STATUS *status) {
    uint32_t status_val;
    do {
        status_val = __LDREXW((volatile uint32_t *)status);
        if (status_val & I2C_STATUS_BUSY_MASK) {
            __CLREX();
            return ARM_DRIVER_ERROR_BUSY;
        }
        status_val |= I2C_STATUS_BUSY_MASK;
    } while (__STREXW(status_val, (volatile uint32_t *)status) != 0U);
    return ARM_DRIVER_OK;
}

static __inline uint32_t I2C_CalcMTPR(uint32_t sys_clk, uint32_t i2c_clk) {
    uint32_t tpr = ((sys_clk + (10U * i2c_clk)) / (20U * i2c_clk)) - 1U;
    
    return __USAT(tpr, I2C_MTPR_TPR_BIT_WIDTH);
}

static void I2C_Delay_BitBang(void) {
    for (volatile uint32_t i = 0; i < 100; i++) {
        __NOP();
    }
}

static int32_t I2C_BusClear(LM3S_I2C_DrvInstance_t *i2c) {
    
    WRITE_REG(i2c->resources->slave->IMR, 0x00UL);
    __NOP();
    CLEAR_BIT(i2c->resources->sclPin->pinPort->AFSEL, i2c->resources->sclPin->pinNum);
    CLEAR_BIT(i2c->resources->sdaPin->pinPort->AFSEL, i2c->resources->sdaPin->pinNum);
    CLEAR_REG(i2c->resources->sclPin->pinPort->PCTL,  i2c->resources->sclPin->pinCtlMsk);
    CLEAR_REG(i2c->resources->sdaPin->pinPort->PCTL,  i2c->resources->sdaPin->pinCtlMsk);

    SET_BIT  (i2c->resources->sclPin->pinPort->DIR,   i2c->resources->sclPin->pinNum);
    CLEAR_BIT(i2c->resources->sdaPin->pinPort->DIR,   i2c->resources->sdaPin->pinNum);

    for (uint32_t i = 0; i < 9U; i++) {
        if (i2c->resources->sdaPin->pinPort->DATA[1<<i2c->resources->sdaPin->pinNum] != 0x00UL) {
            break; 
        }
        i2c->resources->sclPin->pinPort->DATA[1<<i2c->resources->sclPin->pinNum] = 0x00UL;
        I2C_Delay_BitBang();
        i2c->resources->sclPin->pinPort->DATA[1<<i2c->resources->sclPin->pinNum] = 1<<i2c->resources->sclPin->pinNum;
        I2C_Delay_BitBang();
    }

    SET_BIT(i2c->resources->sdaPin->pinPort->DIR, i2c->resources->sdaPin->pinNum);  

    i2c->resources->sclPin->pinPort->DATA[1<<i2c->resources->sclPin->pinNum] = 0x00UL;
    i2c->resources->sdaPin->pinPort->DATA[1<<i2c->resources->sdaPin->pinNum] = 0x00UL;
    I2C_Delay_BitBang();

    i2c->resources->sclPin->pinPort->DATA[1<<i2c->resources->sclPin->pinNum] = 1<<i2c->resources->sclPin->pinNum;
    I2C_Delay_BitBang();

    i2c->resources->sdaPin->pinPort->DATA[1<<i2c->resources->sdaPin->pinNum] = 1<<i2c->resources->sdaPin->pinNum;
    I2C_Delay_BitBang();

    CLEAR_BIT(i2c->resources->sdaPin->pinPort->DIR, 1<<i2c->resources->sdaPin->pinNum);
    
    
    MODIFY_REG(i2c->resources->sdaPin->pinPort->PCTL, i2c->resources->sdaPin->pinCtlMsk, i2c->resources->sdaPin->pinCtlCode);
    MODIFY_REG(i2c->resources->sclPin->pinPort->PCTL, i2c->resources->sclPin->pinCtlMsk, i2c->resources->sclPin->pinCtlCode);
    SET_BIT(i2c->resources->sclPin->pinPort->AFSEL, i2c->resources->sclPin->pinNum);
    SET_BIT(i2c->resources->sdaPin->pinPort->AFSEL, i2c->resources->sdaPin->pinNum);
    __NOP();
    WRITE_REG(i2c->resources->slave->IC, I2C_SLAVE_IC_STARTIC_Msk | I2C_SLAVE_IC_STOPIC_Msk | I2C_SLAVE_IC_DATAIC_Msk);
    SET_REG(i2c->resources->slave->IMR, I2C_SLAVE_IMR_STOPIM_Msk | I2C_SLAVE_IMR_STARTIM_Msk | I2C_SLAVE_IMR_DATAIM_Msk);
    return ARM_DRIVER_OK;
}

static void I2C_Master_ISR(LM3S_I2C_DrvInstance_t *i2c) {
    uint32_t mcs = READ_REG(i2c->resources->master->STATUS, I2C_MASTER_STATUS_BUSBSY_Msk | \
                                                            I2C_MASTER_STATUS_IDLE_Msk   | \
                                                            I2C_MASTER_STATUS_ARBLST_Msk | \
                                                            I2C_MASTER_STATUS_DATACK_Msk | \
                                                            I2C_MASTER_STATUS_ADRACK_Msk | \
                                                            I2C_MASTER_STATUS_ERROR_Msk  | \
                                                            I2C_MASTER_STATUS_BUSY_Msk      );

    if (mcs & (I2C_MASTER_STATUS_ARBLST_Msk | I2C_MASTER_STATUS_ERROR_Msk)) {
        uint32_t event = ARM_I2C_EVENT_TRANSFER_INCOMPLETE;

        if (mcs & I2C_MASTER_STATUS_ERROR_Msk) {
            i2c->control->status.arbitration_lost = 1U;
            event |= ARM_I2C_EVENT_ARBITRATION_LOST;
        }
        if (mcs & (I2C_MASTER_STATUS_ADRACK_Msk | I2C_MASTER_STATUS_DATACK_Msk)) {
            i2c->control->status.bus_error = 1U;
            event |= ARM_I2C_EVENT_BUS_ERROR;
        }

        WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_STOP_Msk);

        i2c->control->status.busy = 0U;
        i2c->control->pData       = NULL;
        i2c->control->numBytes    = 0U;

        if (i2c->control->cbEvent) {
            i2c->control->cbEvent(event);
        }
        return;
    }

    if (i2c->control->status.direction == 0U) {
        if (i2c->control->numBytes > 0U) {
            WRITE_REG(i2c->resources->master->DR, *i2c->control->pData);
            i2c->control->pData++;
            i2c->control->numBytes--;
            i2c->control->cntBytes++; 
            if (i2c->control->numBytes == 0U) {
                if (i2c->control->pendingStop) {
                    WRITE_REG(i2c->resources->master->CTRL, (I2C_MASTER_CTRL_STOP_Msk | I2C_MASTER_CTRL_RUN_Msk));
                } else {
                    WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_RUN_Msk);
                }
            } else {
                WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_RUN_Msk);
            }
        } 
        else {
            i2c->control->status.busy = 0U;
            i2c->control->pData       = NULL;
            if (i2c->control->cbEvent) {
                i2c->control->cbEvent(ARM_I2C_EVENT_TRANSFER_DONE);
            }
        }
    }

    else {
        *i2c->control->pData = (uint8_t)READ_REG(i2c->resources->master->DR, 0xFFUL);
        i2c->control->pData++;
        i2c->control->numBytes--;
        i2c->control->cntBytes++;

        if (i2c->control->numBytes > 0U) {
            if (i2c->control->numBytes == 1U) {
                if (i2c->control->pendingStop) {
                    WRITE_REG(i2c->resources->master->CTRL, (I2C_MASTER_CTRL_STOP_Msk | I2C_MASTER_CTRL_RUN_Msk));
                } else {
                    WRITE_REG(i2c->resources->master->CTRL, I2C_MASTER_CTRL_RUN_Msk);
                }
            } else {
                WRITE_REG(i2c->resources->master->CTRL, (I2C_MASTER_CTRL_ACK_Msk | I2C_MASTER_CTRL_RUN_Msk));
            }
        }
        else {
            i2c->control->status.busy = 0U;
            i2c->control->pData       = NULL;
            if (i2c->control->cbEvent) {
                i2c->control->cbEvent(ARM_I2C_EVENT_TRANSFER_DONE);
            }
        }
    }
}

static void I2C_Slave_ISR(LM3S_I2C_DrvInstance_t *i2c, uint32_t mis_slave) {
    uint32_t ris = i2c->resources->slave->RIS;
    uint32_t imr = i2c->resources->slave->IMR;
    uint32_t slave_status = ris & imr;

    if (slave_status & I2C_SLAVE_RIS_STARTRIS_Msk) {
        WRITE_REG(i2c->resources->slave->IC, I2C_SLAVE_IC_STARTIC_Msk);
        if(i2c->control->slaveSelected){
            i2c->control->status.busy = 0U;
            if (i2c->control->cbEvent) {
                if (i2c->control->status.bus_error) {
                    i2c->control->cbEvent(ARM_I2C_EVENT_TRANSFER_INCOMPLETE);
                } else {
                    i2c->control->cbEvent(ARM_I2C_EVENT_TRANSFER_DONE);
                }
            }
            i2c->control->pData = NULL;
        }
        i2c->control->cntBytes      = 0U;
        i2c->control->slaveSelected = false; 
    }
    
    if (slave_status & I2C_SLAVE_RIS_DATARIS_Msk) {
        WRITE_REG(i2c->resources->slave->IC, I2C_SLAVE_IC_DATAIC_Msk);
        uint32_t csr = READ_REG(i2c->resources->slave->STATUS, I2C_SLAVE_STATUS_FBR_Msk | I2C_SLAVE_STATUS_TREQ_Msk | I2C_SLAVE_STATUS_RREQ_Msk);

        if (csr & I2C_SLAVE_STATUS_FBR_Msk) {
            i2c->control->slaveSelected = true;
            if (i2c->control->pData == NULL) {
                WRITE_REG(i2c->resources->slave->CTRL, 0x00UL);
                if (i2c->control->cbEvent) {
                    if (csr & I2C_SLAVE_STATUS_TREQ_Msk) {
                        i2c->control->cbEvent(ARM_I2C_EVENT_SLAVE_TRANSMIT);
                    }
                    else {
                        i2c->control->cbEvent(ARM_I2C_EVENT_SLAVE_RECEIVE);
                    }
                }
            }
        }
        if(i2c->control->slaveSelected){
            if (csr & I2C_SLAVE_STATUS_RREQ_Msk) {
                uint8_t rx_byte = (uint8_t)READ_REG(i2c->resources->slave->DR, 0xFFUL);
                if (i2c->control->numBytes > 0U) {
                    *(i2c->control->pData) = rx_byte;
                    i2c->control->pData++;
                    i2c->control->numBytes--;
                } else {
                    i2c->control->status.bus_error = 1U; 
                }
            }
            else if (csr & I2C_SLAVE_STATUS_TREQ_Msk) {
                if (i2c->control->numBytes > 0U) {
                    WRITE_REG(i2c->resources->slave->DR, *(i2c->control->pData));
                    i2c->control->pData++;
                    i2c->control->numBytes--;
                } else {
                    WRITE_REG(i2c->resources->slave->DR, 0xFFUL);
                }
            }
        }
        WRITE_REG(i2c->resources->slave->CTRL, I2C_SLAVE_CTRL_DA_Msk);
    }

    if (slave_status & I2C_SLAVE_RIS_STOPRIS_Msk) {
        WRITE_REG(i2c->resources->slave->IC, I2C_SLAVE_IC_STOPIC_Msk);
        if(i2c->control->slaveSelected){
            i2c->control->status.busy = 0U; 
            WRITE_REG(i2c->resources->slave->CTRL, 0x00UL);
            if (i2c->control->cbEvent) {
                if (i2c->control->status.bus_error) {
                    i2c->control->cbEvent(ARM_I2C_EVENT_TRANSFER_INCOMPLETE);
                } else {
                    i2c->control->cbEvent(ARM_I2C_EVENT_TRANSFER_DONE);
                }
            }
            i2c->control->pData = NULL;
            i2c->control->numBytes       = 0U;
            i2c->control->slaveSelected = false;
        }
    }
}

void I2C_Interrupt_Handler(LM3S_I2C_DrvInstance_t *i2c) {
    uint32_t mis_master = READ_REG(i2c->resources->master->MIS, I2C_MASTER_MIS_MIS_Msk);
    uint32_t ris_slave  = i2c->resources->slave->RIS & i2c->resources->slave->IMR;
    if (mis_master != 0U) {
        WRITE_REG(i2c->resources->master->IC, I2C_MASTER_MIS_MIS_Msk); 
    }
    if (ris_slave != 0U) {
        I2C_Slave_ISR(i2c, ris_slave);
    }
    if (mis_master != 0U) {
        I2C_Master_ISR(i2c);
    }
}


/* Вектора NVIC просто пробрасывают свои инстанции */
void I2C0_Handler(void) { I2C_Interrupt_Handler(&I2C0_Inst); }
void I2C1_Handler(void) { I2C_Interrupt_Handler(&I2C1_Inst); }

extern \
ARM_DRIVER_I2C Driver_I2C0;
ARM_DRIVER_I2C Driver_I2C0 = {
    LM3S_I2C_GetVersion,
    LM3S_I2C_GetCapabilities,
    LM3S_I2C0_Initialize,
    ARM_I2C0_Uninitialize,
    ARM_I2C0_PowerControl,
    ARM_I2C0_MasterTransmit,
    ARM_I2C0_MasterReceive,
    ARM_I2C0_SlaveTransmit,
    ARM_I2C0_SlaveReceive,
    ARM_I2C0_GetDataCount,
    ARM_I2C0_Control,
    ARM_I2C0_GetStatus
};

ARM_DRIVER_I2C Driver_I2C1 = {
    LM3S_I2C_GetVersion,
    LM3S_I2C_GetCapabilities,
    LM3S_I2C1_Initialize,
    ARM_I2C1_Uninitialize,
    ARM_I2C1_PowerControl,
    ARM_I2C1_MasterTransmit,
    ARM_I2C1_MasterReceive,
    ARM_I2C1_SlaveTransmit,
    ARM_I2C1_SlaveReceive,
    ARM_I2C1_GetDataCount,
    ARM_I2C1_Control,
    ARM_I2C1_GetStatus
};
