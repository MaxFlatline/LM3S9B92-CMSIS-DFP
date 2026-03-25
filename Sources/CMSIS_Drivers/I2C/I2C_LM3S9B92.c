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
 
#include "Driver_I2C.h"

#include "RTE_Components.h"
#include CMSIS_device_header
#include "I2C_LM3S9B92_Config.h"

#if (I2C1_ROM_SELECTED==1)
#include "rom_map.h"
#endif

#define ARM_I2C_DRV_VERSION    ARM_DRIVER_VERSION_MAJOR_MINOR(1, 0) /* driver version */

#define LM3S_I2C_NUM           2

typedef struct lm3s_i2c_s {
    ARM_I2C_SignalEvent_t cb_event;
}lm3s_i2c_t;

lm3s_i2c_t I2C_Instance[LM3S_I2C_NUM];

typedef enum I2C_Instance_e {
    INST_I2C0 = 0x00U,
    INST_I2C1 = 0x01U
} I2C_Instance_t;

/* Driver Version */
static const ARM_DRIVER_VERSION DriverVersion = {
    ARM_I2C_API_VERSION,
    ARM_I2C_DRV_VERSION
};

/* Driver Capabilities */
static const ARM_I2C_CAPABILITIES DriverCapabilities = {
    0  /* supports 10-bit addressing */
};

//
//  Functions
//

static ARM_DRIVER_VERSION ARM_I2C_GetVersion(void)
{
  return DriverVersion;
}

static ARM_I2C_CAPABILITIES ARM_I2C_GetCapabilities(void)
{
  return DriverCapabilities;
}

static int32_t ARM_I2C_Initialize(ARM_I2C_SignalEvent_t cb_event, I2C_Instance_t Inst){
    int32_t Result;
    
    Result = ARM_DRIVER_OK;
    
    // Enable clock for I2C SDA pin (currently - in RUN MODE only)
    if(!(LM3S_SYSCTL->RCGC2 & RTE_I2C1_SDA_PORT_CLOCK_EN_Msk)){
        LM3S_SYSCTL->RCGC2 |= RTE_I2C1_SDA_PORT_CLOCK_EN_Msk;
    }
    
    // Enable clock for I2C SCL pin (currently - in RUN MODE only)
    if(!(LM3S_SYSCTL->RCGC2 & RTE_I2C1_SCL_PORT_CLOCK_EN_Msk)){
        LM3S_SYSCTL->RCGC2 |= RTE_I2C1_SCL_PORT_CLOCK_EN_Msk;
    }
    
    // Register Callback
    I2C_Instance[Inst].cb_event = cb_event;
    
    return Result;
}

static int32_t ARM_I2C0_Initialize(ARM_I2C_SignalEvent_t cb_event){
    int32_t Result;
    Result = ARM_I2C_Initialize(cb_event, INST_I2C0);
    return Result;
}

static int32_t ARM_I2C1_Initialize(ARM_I2C_SignalEvent_t cb_event){
    int32_t Result;
    Result = ARM_I2C_Initialize(cb_event, INST_I2C1);
    return Result;
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
    ARM_I2C_GetVersion,
    ARM_I2C_GetCapabilities,
    ARM_I2C0_Initialize,
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
    ARM_I2C_GetVersion,
    ARM_I2C_GetCapabilities,
    ARM_I2C1_Initialize,
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
