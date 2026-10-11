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
#include "SPI_LM3S9B92_Config.h"
#include "SYS_LM3S9B92.h"
#include "SYS_LM3S9B92_Config.h"

#include "driver_utils.h"

#include "Driver_SPI.h"

#define ARM_SPI_DRV_VERSION    ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0) /* driver version */

#define ARM_DRIVER_SPI_STATUS_BUSY_MASK (1U<<0U)

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_SPI_API_VERSION,
    ARM_SPI_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_SPI_CAPABILITIES DriverCapabilities = {
    0, /* Reserved (must be zero) */
    1, /* TI Synchronous Serial Interface */
    1, /* Microwire Interface */
    0, /* Signal Mode Fault event: \ref ARM_SPI_EVENT_MODE_FAULT */
    0  /* Reserved (must be zero) */
};

typedef LM3S_AF_Pin_Config_t LM3S_SPI_Pin_Config_t;

typedef struct LM3S_SPI_DrvControl_s {
    ARM_SPI_SignalEvent_t  cbEvent;
    ARM_SPI_STATUS         status;
    bool                   isInitialized;
    bool                   isPowered;
    uint8_t*               txData;
    uint8_t*               rxData;
    uint32_t               txCnt;
    uint32_t               rxCnt;
    uint32_t               num;
    uint32_t               dataSize;
    uint32_t               mode;
} LM3S_SPI_DrvControl_t;

typedef const struct LM3S_SPI_DrvResources_s {
    SSI_Type*              instance;
    uint32_t               irqNum;
    uint32_t               runClockMask;
#if defined(SYS_USE_ACG) && (SYS_USE_ACG == 1)
    uint32_t               sleepClockMask;
    uint32_t               deepsleepClockMask;
#endif
    LM3S_SPI_Pin_Config_t* clkPin;
    LM3S_SPI_Pin_Config_t* ssPin;
    LM3S_SPI_Pin_Config_t* misoPin;
    LM3S_SPI_Pin_Config_t* mosiPin;
} LM3S_SPI_DrvResources_t;

typedef const struct LM3S_SPI_DrvInstance_s {
    LM3S_SPI_DrvControl_t*                control;
    const LM3S_SPI_DrvResources_t* const resources;
} LM3S_SPI_DrvInstance_t;

static LM3S_SPI_Pin_Config_t SPI0_Clk_pin = {
    RTE_SPI0_CLK_PIN,
    RTE_SPI0_CLK_PORT,
    RTE_SPI0_CLK_PORT_CLOCK_EN_Msk,
    RTE_SPI0_CLK_PCTL_MASK,
    RTE_SPI0_CLK_PCTL_CODE
};

#if (RTE_SPI0_HW_SS) == 1
static LM3S_SPI_Pin_Config_t SPI0_Ss_pin = {
    RTE_SPI0_SS_PIN,
    RTE_SPI0_SS_PORT,
    RTE_SPI0_SS_PORT_CLOCK_EN_Msk,
    RTE_SPI0_SS_PCTL_MASK,
    RTE_SPI0_SS_PCTL_CODE
};
#endif

static LM3S_SPI_Pin_Config_t SPI0_Miso_pin = {
    RTE_SPI0_MISO_PIN,
    RTE_SPI0_MISO_PORT,
    RTE_SPI0_MISO_PORT_CLOCK_EN_Msk,
    RTE_SPI0_MISO_PCTL_MASK,
    RTE_SPI0_MISO_PCTL_CODE
};

static LM3S_SPI_Pin_Config_t SPI0_Mosi_pin = {
    RTE_SPI0_MOSI_PIN,
    RTE_SPI0_MOSI_PORT,
    RTE_SPI0_MOSI_PORT_CLOCK_EN_Msk,
    RTE_SPI0_MOSI_PCTL_MASK,
    RTE_SPI0_MOSI_PCTL_CODE
};

static LM3S_SPI_Pin_Config_t SPI1_Clk_pin = {
    RTE_SPI0_CLK_PIN,
    RTE_SPI0_CLK_PORT,
    RTE_SPI0_CLK_PORT_CLOCK_EN_Msk,
    RTE_SPI0_CLK_PCTL_MASK,
    RTE_SPI0_CLK_PCTL_CODE
};

#if (RTE_SPI0_HW_SS) == 1
static LM3S_SPI_Pin_Config_t SPI1_Ss_pin = {
    RTE_SPI0_SS_PIN,
    RTE_SPI0_SS_PORT,
    RTE_SPI0_SS_PORT_CLOCK_EN_Msk,
    RTE_SPI0_SS_PCTL_MASK,
    RTE_SPI0_SS_PCTL_CODE
};
#endif

static LM3S_SPI_Pin_Config_t SPI1_Miso_pin = {
    RTE_SPI0_MISO_PIN,
    RTE_SPI0_MISO_PORT,
    RTE_SPI0_MISO_PORT_CLOCK_EN_Msk,
    RTE_SPI0_MISO_PCTL_MASK,
    RTE_SPI0_MISO_PCTL_CODE
};

static LM3S_SPI_Pin_Config_t SPI1_Mosi_pin = {
    RTE_SPI0_MOSI_PIN,
    RTE_SPI0_MOSI_PORT,
    RTE_SPI0_MOSI_PORT_CLOCK_EN_Msk,
    RTE_SPI0_MOSI_PCTL_MASK,
    RTE_SPI0_MOSI_PCTL_CODE
};

static LM3S_SPI_DrvResources_t SPI0_Resources = {
    SSI0,
    SSI0_IRQn,
    SYSCTL_RCGC1_SSI0_Msk,
#if defined(SYS_USE_ACG) && (SYS_USE_ACG == 1)
#if defined(RTE_SPI0_SLEEP_USER_SET) && (RTE_SPI0_SLEEP_USER_SET == 1)
    SYSCTL_SCGC1_SSI0_Msk,
#elif (RTE_SPI0_SLEEP_USER_SET == 0)
    0
#else
#error "Inconsistency in Config file, check I2C_LM3S9B92_Config.h!"
#endif
#if defined(RTE_SPI0_DEEPSLEEP_USER_SET) && (RTE_SPI0_DEEPSLEEP_USER_SET == 1)
    SYSCTL_DCGC1_SSI0_Msk,
#elif (RTE_SPI0_DEEPSLEEP_USER_SET == 0)
    0,
#else
#error "Inconsistency in Config file, check I2C_LM3S9B92_Config.h!"
#endif
#endif
    &SPI0_Clk_pin,
#if (RTE_SPI0_HW_SS) == 1
    &SPI0_Ss_pin,
#else
    0,
#endif
    &SPI0_Miso_pin,
    &SPI0_Mosi_pin
};

static LM3S_SPI_DrvResources_t SPI1_Resources = {
    SSI1,
    SSI1_IRQn,
    SYSCTL_RCGC1_SSI1_Msk,
#if defined(SYS_USE_ACG) && (SYS_USE_ACG == 1)
#if defined(RTE_SPI1_SLEEP_USER_SET) && (RTE_SPI1_SLEEP_USER_SET == 1)
    SYSCTL_SCGC1_SSI1_Msk,
#elif (RTE_SPI1_SLEEP_USER_SET == 0)
    0,
#else
#error "Inconsistency in Config file, check SPI_LM3S9B92_Config.h!"
#endif
#if defined(RTE_SPI1_DEEPSLEEP_USER_SET) && (RTE_SPI1_DEEPSLEEP_USER_SET == 1)
    SYSCTL_DCGC1_SSI1_Msk,
#elif (RTE_SPI1_DEEPSLEEP_USER_SET == 0)
    0,
#else
#error "Inconsistency in Config file, check SPI_LM3S9B92_Config.h!"
#endif
#endif
    &SPI1_Clk_pin,
#if (RTE_SPI1_HW_SS) == 1
    &SPI1_Ss_pin,
#else
    0,
#endif
    &SPI1_Miso_pin,
    &SPI1_Mosi_pin
};

static LM3S_SPI_DrvControl_t SPI0_Ctrl = {
    NULL,
    {0},
    false,
    false,
    NULL,
    0,
    0,
    false,
    false
};

static LM3S_SPI_DrvControl_t SPI1_Ctrl = {
    NULL,
    {0},
    false,
    false,
    NULL,
    0,
    0,
    false,
    false
};


const LM3S_SPI_DrvInstance_t SPI0_Inst = {
    .control   = &SPI0_Ctrl,
    .resources = &SPI0_Resources
};

const LM3S_SPI_DrvInstance_t SPI1_Inst = {
    .control   = &SPI1_Ctrl,
    .resources = &SPI1_Resources
};

//
//  Functions
//


__STATIC_INLINE int32_t ATOMIC_Bit_Lock (volatile uint32_t *reg, uint32_t bit_mask);
__STATIC_INLINE void ATOMIC_Bit_Unlock (volatile uint32_t *reg, uint32_t bit_mask);
static int32_t ARM_SPI_PowerControl(LM3S_SPI_DrvInstance_t *spi, ARM_POWER_STATE state);

static ARM_DRIVER_VERSION ARM_SPI_GetVersion(void) {
    return DriverVersion;
}

static ARM_SPI_CAPABILITIES ARM_SPI_GetCapabilities(void) {
    return DriverCapabilities;
}

static int32_t ARM_SPI_Initialize(LM3S_SPI_DrvInstance_t *spi, ARM_SPI_SignalEvent_t cb_event) {
    if (spi->control->isInitialized) {
        if (spi->control->status.busy == 0U) {
            spi->control->cbEvent = cb_event;
        }
        return ARM_DRIVER_OK;
    }

    SET_REG(SYSCTL->RCGC2, spi->resources->clkPin->portClkMask);
    if(spi->resources->ssPin) {
        SET_REG(SYSCTL->RCGC2, spi->resources->ssPin->portClkMask);
    }
    SET_REG(SYSCTL->RCGC2, spi->resources->misoPin->portClkMask);
    SET_REG(SYSCTL->RCGC2, spi->resources->mosiPin->portClkMask);
#if defined (SYS_USE_ACG) && (SYS_USE_ACG == 1)
    if (spi->resources->sleepClockMask) {
        SET_REG(SYSCTL->SCGC2, spi->resources->clkPin->portClkMask);
        if(spi->resources->ssPin) {
            SET_REG(SYSCTL->SCGC2, spi->resources->ssPin->portClkMask);
        }
        SET_REG(SYSCTL->SCGC2, spi->resources->misoPin->portClkMask);
        SET_REG(SYSCTL->SCGC2, spi->resources->mosiPin->portClkMask);
    }
    if (spi->resources->deepsleepClockMask) {
        SET_REG(SYSCTL->DCGC2, spi->resources->clkPin->portClkMask);
        if(spi->resources->ssPin) {
            SET_REG(SYSCTL->DCGC2, spi->resources->ssPin->portClkMask);
        }
        SET_REG(SYSCTL->DCGC2, spi->resources->misoPin->portClkMask);
        SET_REG(SYSCTL->DCGC2, spi->resources->mosiPin->portClkMask);
    }
#elif !defined (SYS_USE_ACG)
#error "Global system setting (ACG) is missing! Check SYS_LM3S9B92_Config.h"
#endif

    __NOP();
    __NOP();
    __NOP();

    LM3S_PinInitializeAF(spi->resources->clkPin);
    if(spi->resources->ssPin) {
        LM3S_PinInitializeAF(spi->resources->ssPin);
    }
    LM3S_PinInitializeAF(spi->resources->misoPin);
    LM3S_PinInitializeAF(spi->resources->mosiPin);


    return 0;
}

static int32_t ARM_SPI0_Initialize(ARM_SPI_SignalEvent_t cb_event) {
    return ARM_SPI_Initialize(&SPI0_Inst,cb_event);
}

static int32_t ARM_SPI1_Initialize(ARM_SPI_SignalEvent_t cb_event) {
    return ARM_SPI_Initialize(&SPI1_Inst,cb_event);
}

static int32_t ARM_SPI_Uninitialize(LM3S_SPI_DrvInstance_t *spi) {
    if(spi->control->isInitialized == false) {
        return ARM_DRIVER_OK;
    }

    if (spi->control->isPowered != 0) {
        (void)ARM_SPI_PowerControl(spi, ARM_POWER_OFF);
    }

    LM3S_PinUninitializeAF(spi->resources->clkPin);
    if(spi->resources->ssPin) {
        LM3S_PinUninitializeAF(spi->resources->ssPin);
    }
    LM3S_PinUninitializeAF(spi->resources->misoPin);
    LM3S_PinUninitializeAF(spi->resources->mosiPin);

    spi->control->cbEvent       = NULL;
    spi->control->txData        = NULL;
    spi->control->rxData        = NULL;
    spi->control->rxCnt         = 0;
    spi->control->num           = 0;
    spi->control->dataSize      = 0;
    spi->control->status        = (ARM_SPI_STATUS) {
        0
    };
    spi->control->isInitialized = false;

    return ARM_DRIVER_OK;
}

static int32_t ARM_SPI0_Uninitialize(void) {
    return ARM_SPI_Uninitialize(&SPI0_Inst);
}

static int32_t ARM_SPI_PowerControl(LM3S_SPI_DrvInstance_t *spi, ARM_POWER_STATE state) {
    int32_t status;

    status = ARM_DRIVER_OK;
    switch (state) {
    case ARM_POWER_OFF:
        if (spi->control->isPowered == false) {
            break;
        }

        spi->control->txData        = NULL;
        spi->control->rxData        = NULL;
        spi->control->rxCnt         = 0;
        spi->control->num           = 0;
        spi->control->txCnt         = 0;
        spi->control->dataSize      = 0;
        spi->control->mode          = ARM_SPI_MODE_INACTIVE;
        spi->control->status        = (ARM_SPI_STATUS) {
            0
        };

        NVIC_DisableIRQ(spi->resources->irqNum);
        WRITE_REG(spi->resources->instance->CR1,  0x00UL);
        WRITE_REG(spi->resources->instance->IM,  0x00UL);

        CLEAR_REG(SYSCTL->RCGC1, spi->resources->runClockMask);
#if defined (SYS_USE_ACG) && (SYS_USE_ACG == 1)
        CLEAR_REG(SYSCTL->SCGC1, spi->resources->runClockMask);
        CLEAR_REG(SYSCTL->DCGC1, spi->resources->runClockMask);
#elif !defined(SYS_USE_ACG)
#error "Global system setting (ACG) is missing! Check SYS_LM3S9B92_Config.h"
#endif
        break;
    case ARM_POWER_LOW:
        status = ARM_DRIVER_ERROR_UNSUPPORTED;
        break;
    case ARM_POWER_FULL:
        if (spi->control->isInitialized == false) {
            status = ARM_DRIVER_ERROR;
            break;
        }
        if (spi->control->isPowered != false) {
            break;
        }
        SET_REG(SYSCTL->RCGC1, spi->resources->runClockMask);
#if defined (SYS_USE_ACG) && (SYS_USE_ACG == 1)
        if (spi->resources->sleepClockMask) {
            SET_REG(SYSCTL->SCGC1, spi->resources->sleepClockMask);
        }
        if (spi->resources->deepsleepClockMask) {
            SET_REG(SYSCTL->DCGC1, spi->resources->deepsleepClockMask);
        }
        spi->control->txData        = NULL;
        spi->control->rxData        = NULL;
        spi->control->rxCnt         = 0;
        spi->control->num           = 0;
        spi->control->txCnt         = 0;
        spi->control->dataSize      = 0;
        spi->control->mode          = ARM_SPI_MODE_INACTIVE;
        spi->control->status        = (ARM_SPI_STATUS) {
            0
        };
#elif !defined (SYS_USE_ACG)
#error "Global system setting (ACG) is missing! Check SYS_LM3S9B92_Config.h"
#endif
        WRITE_REG(spi->resources->instance->IC, SSI_IC_RORIC_Msk | SSI_IC_RTIC_Msk);
        break;
    default:
        break;
    }

    return status;
}

static int32_t ARM_SPI0_PowerControl(ARM_POWER_STATE state) {
    return ARM_SPI_PowerControl(&SPI0_Inst,state);
}

static int32_t ARM_SPI1_PowerControl(ARM_POWER_STATE state) {
    return ARM_SPI_PowerControl(&SPI1_Inst,state);
}

static int32_t ARM_SPI_Send(LM3S_SPI_DrvInstance_t *spi, const void *data, uint32_t num) {
    int32_t status = ARM_DRIVER_OK;
    if ((data == NULL) || (num == 0)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    if (spi->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }

    if (spi->control->mode == ARM_SPI_MODE_INACTIVE) {
        return ARM_DRIVER_ERROR;
    }

    if(ATOMIC_Bit_Lock((volatile uint32_t *)&spi->control->status, ARM_DRIVER_SPI_STATUS_BUSY_MASK) != ARM_DRIVER_OK) {
        return ARM_DRIVER_ERROR_BUSY;
    }

    spi->control->txData           = (uint8_t *)data;
    spi->control->rxData           = NULL;
    spi->control->rxCnt            = 0;
    spi->control->txCnt            = 0;
    spi->control->num              = num;
    spi->control->status.data_lost = 0;


    while (spi->resources->instance->SR & SSI_SR_RNE_Msk) {
        volatile uint32_t dummy = spi->resources->instance->DR;
        (void)dummy;
    }

    if (spi->control->mode == ARM_SPI_MODE_MASTER) {
        while ((spi->control->txCnt < spi->control->num) && (spi->resources->instance->SR & SSI_SR_TNF_Msk)) {
            if (spi->control->dataSize <= 8U) {
                spi->resources->instance->DR = spi->control->txData[spi->control->txCnt++];
            } else {
                spi->resources->instance->DR = ((const uint16_t *)(spi->control->txData))[spi->control->txCnt++];
            }
        }
    }
    SET_REG(spi->resources->instance->IM, SSI_IM_TXIM_Msk | SSI_IM_RXIM_Msk | SSI_IM_RTIM_Msk);

    return status;
}

static int32_t ARM_SPI0_Send(const void *data, uint32_t num) {
    return ARM_SPI_Send(&SPI0_Inst, data, num);
}

static int32_t ARM_SPI1_Send(const void *data, uint32_t num) {
    return ARM_SPI_Send(&SPI1_Inst, data, num);
}

static int32_t ARM_SPI_Receive(LM3S_SPI_DrvInstance_t *spi, void *data, uint32_t num) {
    int32_t status = ARM_DRIVER_OK;
    if ((data == NULL) || (num == 0)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    if (spi->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }

    if (spi->control->mode == ARM_SPI_MODE_INACTIVE) {
        return ARM_DRIVER_ERROR;
    }

    if(ATOMIC_Bit_Lock((volatile uint32_t *)&spi->control->status, ARM_DRIVER_SPI_STATUS_BUSY_MASK) != ARM_DRIVER_OK) {
        return ARM_DRIVER_ERROR_BUSY;
    }

    spi->control->txData           = NULL;
    spi->control->rxData           = (uint8_t *)data;
    spi->control->rxCnt            = 0;
    spi->control->txCnt            = 0;
    spi->control->num              = num;
    spi->control->status.data_lost = 0;

    while (spi->resources->instance->SR & SSI_SR_RNE_Msk) {
        volatile uint32_t dummy = spi->resources->instance->DR;
        (void)dummy;
    }

    if (spi->control->mode == ARM_SPI_MODE_MASTER) {

        while ((spi->control->txCnt < spi->control->num) && (spi->resources->instance->SR & SSI_SR_TNF_Msk)) {

            if (spi->control->dataSize <= 8U) {
                spi->resources->instance->DR = 0xFFU;
            } else {
                spi->resources->instance->DR = 0xFFFFU;
            }
        }
    }

    SET_REG(spi->resources->instance->IM, SSI_IM_TXIM_Msk | SSI_IM_RXIM_Msk | SSI_IM_RTIM_Msk);

    return status;
}

static int32_t ARM_SPI0_Receive(void *data, uint32_t num) {
    return ARM_SPI_Receive(&SPI1_Inst, data, num);
}

static int32_t ARM_SPI1_Receive(void *data, uint32_t num) {
    return ARM_SPI_Receive(&SPI1_Inst, data, num);
}

static int32_t ARM_SPI_Transfer(LM3S_SPI_DrvInstance_t *spi, const void *data_out, void *data_in, uint32_t num) {
    int32_t status = ARM_DRIVER_OK;
    if ((data_out == NULL) || (data_in == NULL) || (num == 0)) {
        return ARM_DRIVER_ERROR_PARAMETER;
    }

    if (spi->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }

    if (spi->control->mode == ARM_SPI_MODE_INACTIVE) {
        return ARM_DRIVER_ERROR;
    }

    if(ATOMIC_Bit_Lock((volatile uint32_t *)&spi->control->status, ARM_DRIVER_SPI_STATUS_BUSY_MASK) != ARM_DRIVER_OK) {
        return ARM_DRIVER_ERROR_BUSY;
    }

    spi->control->txData           = (uint8_t *)data_out;
    spi->control->rxData           = (uint8_t *)data_in;
    spi->control->rxCnt            = 0;
    spi->control->txCnt            = 0;
    spi->control->num              = num;
    spi->control->status.data_lost = 0;


    while (spi->resources->instance->SR & SSI_SR_RNE_Msk) {
        volatile uint32_t dummy = spi->resources->instance->DR;
        (void)dummy;
    }

    if (spi->control->mode == ARM_SPI_MODE_MASTER) {
        while ((spi->control->txCnt < spi->control->num) && (spi->resources->instance->SR & SSI_SR_TNF_Msk)) {

            if (spi->control->dataSize <= 8U) {
                spi->resources->instance->DR = spi->control->txData[spi->control->txCnt++];
            } else {
                spi->resources->instance->DR = ((const uint16_t *)(spi->control->txData))[spi->control->txCnt++];
            }
        }
    }

    SET_REG(spi->resources->instance->IM, SSI_IM_TXIM_Msk | SSI_IM_RXIM_Msk | SSI_IM_RTIM_Msk);

    return status;
}

static int32_t ARM_SPI0_Transfer(const void *data_out, void *data_in, uint32_t num) {
    return ARM_SPI_Transfer(&SPI0_Inst, data_out, data_in, num);
}

static int32_t ARM_SPI1_Transfer(const void *data_out, void *data_in, uint32_t num) {
    return ARM_SPI_Transfer(&SPI1_Inst, data_out, data_in, num);
}

static uint32_t ARM_SPI_GetDataCount(LM3S_SPI_DrvInstance_t *spi) {
    return spi->control->rxCnt;
}

static uint32_t ARM_SPI0_GetDataCount(void) {
    return ARM_SPI_GetDataCount(&SPI0_Inst);
}

static uint32_t ARM_SPI1_GetDataCount(void) {
    return ARM_SPI_GetDataCount(&SPI1_Inst);
}

static int32_t ARM_SPI_Control(LM3S_SPI_DrvInstance_t *spi, uint32_t control, uint32_t arg) {
    if (spi->control->isPowered == false) {
        return ARM_DRIVER_ERROR;
    }

    if ((spi->control->status.busy == 1U) &&
            ((control & ARM_SPI_CONTROL_Msk) != ARM_SPI_ABORT_TRANSFER)) {
        return ARM_DRIVER_ERROR_BUSY;
    }

    switch (control & ARM_SPI_CONTROL_Msk) {
    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;

    case ARM_SPI_MODE_INACTIVE:
        CLEAR_REG(spi->resources->instance->IM, SSI_IM_TXIM_Msk | SSI_IM_RXIM_Msk | SSI_IM_RTIM_Msk | SSI_IM_RORIM_Msk);
        CLEAR_BIT(spi->resources->instance->CR1, SSI_CR1_SSE_Pos);
        ATOMIC_Bit_Unlock((volatile uint32_t *)&spi->control->status, ARM_DRIVER_SPI_STATUS_BUSY_MASK);
        spi->control->mode = ARM_SPI_MODE_INACTIVE;
        return ARM_DRIVER_OK;

    case ARM_SPI_MODE_MASTER:               // SPI Master (Output on MOSI, Input on MISO); arg = Bus Speed in bps
        break;

    case ARM_SPI_MODE_SLAVE:                // SPI Slave  (Output on MISO, Input on MOSI)
        break;

    case ARM_SPI_SET_BUS_SPEED:             // Set Bus Speed in bps; arg = value
        break;

    case ARM_SPI_GET_BUS_SPEED:             // Get Bus Speed in bps
        break;

    case ARM_SPI_SET_DEFAULT_TX_VALUE:      // Set default Transmit value; arg = value
        break;

    case ARM_SPI_CONTROL_SS:                // Control Slave Select; arg = 0:inactive, 1:active
        break;

    case ARM_SPI_ABORT_TRANSFER:            // Abort current data transfer
        break;
    }
}

static ARM_SPI_STATUS ARM_SPI_GetStatus(LM3S_SPI_DrvInstance_t *spi) {
    return spi->control->status;
}

static uint32_t ARM_SPI0_GetStatus(void) {
    return ARM_SPI_GetDataCount(&SPI0_Inst);
}

static uint32_t ARM_SPI1_GetStatus(void) {
    return ARM_SPI_GetDataCount(&SPI1_Inst);
}

static void ARM_SPI_SignalEvent(uint32_t event) {
    // function body
}

// End SPI Interface

void SSI0_Handler (void) {
    uint32_t Status, IrqReqMasked, IrqReqRaw;
    IrqReqMasked = SPI0_Inst.resources->instance->MIS;
    IrqReqRaw = SPI0_Inst.resources->instance->RIS;


}

void SSI1_Handler (void) {

}

__STATIC_INLINE int32_t ATOMIC_Bit_Lock (volatile uint32_t *reg, uint32_t bit_mask) {
    uint32_t reg_val;

    do {
        reg_val = __LDREXW(reg);

        if (reg_val & bit_mask) {
            __CLREX();
            return ARM_DRIVER_ERROR_BUSY;
        }

        reg_val |= bit_mask;

    } while (__STREXW(reg_val, reg) != 0U);

    return ARM_DRIVER_OK;
}

__STATIC_INLINE void ATOMIC_Bit_Unlock (volatile uint32_t *reg, uint32_t bit_mask) {
    uint32_t reg_val;

    do {
        reg_val = __LDREXW(reg);
        reg_val &= ~bit_mask;
    } while (__STREXW(reg_val, reg) != 0U);
}

extern \
ARM_DRIVER_SPI Driver_SPI0;
ARM_DRIVER_SPI Driver_SPI0 = {
    ARM_SPI_GetVersion,
    ARM_SPI_GetCapabilities,
    ARM_SPI0_Initialize,
    ARM_SPI0_Uninitialize,
    ARM_SPI0_PowerControl,
    ARM_SPI0_Send,
    ARM_SPI0_Receive,
    ARM_SPI0_Transfer,
    ARM_SPI0_GetDataCount,
    ARM_SPI_Control,
    ARM_SPI0_GetStatus
};
