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

#include "Driver_I2C.h"

#define ARM_I2C_DRV_VERSION    ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0)

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

typedef struct LM3S_I2C_DrvInstance_s {
    I2C_MASTER_Type      *master;
    I2C_SLAVE_Type       *slave;
    ARM_I2C_SignalEvent_t cbEvent;
    ARM_I2C_STATUS        status;
    bool                  isInitialized;
} LM3S_I2C_DrvInstance_t;

static LM3S_I2C_DrvInstance_t I2C0_Ctrl = {
    I2C_MASTER0,
    I2C_SLAVE0,
    NULL,
    {0},
    false
};

static LM3S_I2C_DrvInstance_t I2C1_Ctrl = {
    I2C_MASTER1,
    I2C_SLAVE1,
    NULL,
    {0},
    false
};

static ARM_DRIVER_VERSION LM3S_I2C_GetVersion(void) {
  return DriverVersion;
}

static ARM_I2C_CAPABILITIES LM3S_I2C_GetCapabilities(void) {
  return DriverCapabilities;
}

static int32_t LM3S_I2C_Initialize(LM3S_I2C_DrvInstance_t *i2c, ARM_I2C_SignalEvent_t cb_event) {
    if (i2c->isInitialized) {
        if (i2c->status.busy == 0U) {
            i2c->cbEvent = cb_event;
        }
        return ARM_DRIVER_OK;
    }

    i2c->cbEvent       = cb_event;
    i2c->isInitialized = true;
    
    i2c->status.busy             = 0U;
    i2c->status.mode             = 0U;
    i2c->status.direction        = 0U;
    i2c->status.general_call     = 0U;
    i2c->status.arbitration_lost = 0U;
    i2c->status.bus_error        = 0U;

    return ARM_DRIVER_OK;

    return ARM_DRIVER_OK;
}

static int32_t LM3S_I2C0_Initialize(ARM_I2C_SignalEvent_t cb_event){
    return LM3S_I2C_Initialize(&I2C0_Ctrl, cb_event);
}

static int32_t LM3S_I2C1_Initialize(ARM_I2C_SignalEvent_t cb_event){
    return LM3S_I2C_Initialize(&I2C1_Ctrl, cb_event);
}

static int32_t ARM_I2C_Uninitialize(void)
{
}

static int32_t ARM_I2C0_Uninitialize(void)
{
}

static int32_t ARM_I2C1_Uninitialize(void)
{
}

static int32_t ARM_I2C_PowerControl(ARM_POWER_STATE state)
{
    #if defined (SYS_USE_ACG) && (SYS_USE_ACG == 1)
    SYSCTL->RCGC1 |= SYSCTL_RCGC1_I2C0_Msk;
    SYSCTL->RCGC2 |= RTE_I2C1_SDA_PORT_CLOCK_EN_Msk;
    SYSCTL->RCGC2 |= RTE_I2C1_SCL_PORT_CLOCK_EN_Msk;
#if defined (RTE_I2C1_SLEEP_USER_SET) && (RTE_I2C1_SLEEP_USER_SET == 1)
    SYSCTL->SCGC1 |= SYSCTL_RCGC1_I2C0_Msk;
    SYSCTL->SCGC2 |= RTE_I2C1_SDA_PORT_CLOCK_EN_Msk;
    SYSCTL->SCGC2 |= RTE_I2C1_SCL_PORT_CLOCK_EN_Msk;
#endif
#if defined (RTE_I2C1_DEEPSLEEP_USER_SET) && (RTE_I2C1_DEEPSLEEP_USER_SET == 1)
    SYSCTL->DCGC1 |= SYSCTL_RCGC1_I2C0_Msk;
    SYSCTL->DCGC2 |= RTE_I2C1_SDA_PORT_CLOCK_EN_Msk;
    SYSCTL->DCGC2 |= RTE_I2C1_SCL_PORT_CLOCK_EN_Msk;
#endif
#elif defined (SYS_USE_ACG) && (SYS_USE_ACG == 0)
    SYSCTL->RCGC1 |= SYSCTL_RCGC1_I2C0_Msk;
    SYSCTL->RCGC2 |= RTE_I2C1_SDA_PORT_CLOCK_EN_Msk;
    SYSCTL->RCGC2 |= RTE_I2C1_SCL_PORT_CLOCK_EN_Msk;
#else
    #error "Global system setting (ACG) is missing! Check SYS_LM3S9B92_Config.h"
#endif
    switch (state)
    {
    case ARM_POWER_OFF:
        break;

    case ARM_POWER_LOW:
        break;

    case ARM_POWER_FULL:
        break;
    }
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C0_PowerControl(ARM_POWER_STATE state)
{
    switch (state)
    {
    case ARM_POWER_OFF:
        break;

    case ARM_POWER_LOW:
        break;

    case ARM_POWER_FULL:
        break;
    }
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C1_PowerControl(ARM_POWER_STATE state)
{
    switch (state)
    {
    case ARM_POWER_OFF:
        break;

    case ARM_POWER_LOW:
        break;

    case ARM_POWER_FULL:
        break;
    }
    return ARM_DRIVER_OK;
}

static int32_t ARM_I2C_MasterTransmit(uint32_t addr, const uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C0_MasterTransmit(uint32_t addr, const uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C1_MasterTransmit(uint32_t addr, const uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C_MasterReceive(uint32_t addr, uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C0_MasterReceive(uint32_t addr, uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C1_MasterReceive(uint32_t addr, uint8_t *data, uint32_t num, bool xfer_pending)
{
}

static int32_t ARM_I2C_SlaveTransmit(const uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C0_SlaveTransmit(const uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C1_SlaveTransmit(const uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C_SlaveReceive(uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C0_SlaveReceive(uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C1_SlaveReceive(uint8_t *data, uint32_t num)
{
}

static int32_t ARM_I2C_GetDataCount(void)
{
}

static int32_t ARM_I2C0_GetDataCount(void)
{
}

static int32_t ARM_I2C1_GetDataCount(void)
{
}

static int32_t ARM_I2C_Control(uint32_t control, uint32_t arg)
{
    switch (control)
    {
    case ARM_I2C_OWN_ADDRESS:
        break;

    case ARM_I2C_BUS_SPEED:
        switch (arg)
        {
        case ARM_I2C_BUS_SPEED_STANDARD:
            break;
        case ARM_I2C_BUS_SPEED_FAST:
            break;
        case ARM_I2C_BUS_SPEED_FAST_PLUS:
            break;
        default:
            return ARM_DRIVER_ERROR_UNSUPPORTED;
        }
        break;

    case ARM_I2C_BUS_CLEAR:
        break;

    case ARM_I2C_ABORT_TRANSFER:
        break;

    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }
}

static int32_t ARM_I2C0_Control(uint32_t control, uint32_t arg)
{
    switch (control)
    {
    case ARM_I2C_OWN_ADDRESS:
        break;

    case ARM_I2C_BUS_SPEED:
        switch (arg)
        {
        case ARM_I2C_BUS_SPEED_STANDARD:
            break;
        case ARM_I2C_BUS_SPEED_FAST:
            break;
        case ARM_I2C_BUS_SPEED_FAST_PLUS:
            break;
        default:
            return ARM_DRIVER_ERROR_UNSUPPORTED;
        }
        break;

    case ARM_I2C_BUS_CLEAR:
        break;

    case ARM_I2C_ABORT_TRANSFER:
        break;

    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }
}

static int32_t ARM_I2C1_Control(uint32_t control, uint32_t arg)
{
    switch (control)
    {
    case ARM_I2C_OWN_ADDRESS:
        break;

    case ARM_I2C_BUS_SPEED:
        switch (arg)
        {
        case ARM_I2C_BUS_SPEED_STANDARD:
            break;
        case ARM_I2C_BUS_SPEED_FAST:
            break;
        case ARM_I2C_BUS_SPEED_FAST_PLUS:
            break;
        default:
            return ARM_DRIVER_ERROR_UNSUPPORTED;
        }
        break;

    case ARM_I2C_BUS_CLEAR:
        break;

    case ARM_I2C_ABORT_TRANSFER:
        break;

    default:
        return ARM_DRIVER_ERROR_UNSUPPORTED;
    }
}

static ARM_I2C_STATUS ARM_I2C_GetStatus(void)
{
}

static ARM_I2C_STATUS ARM_I2C0_GetStatus(void)
{
}

static ARM_I2C_STATUS ARM_I2C1_GetStatus(void)
{
}

static void ARM_I2C_SignalEvent(uint32_t event)
{
    // function body
}

// End I2C Interface

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
