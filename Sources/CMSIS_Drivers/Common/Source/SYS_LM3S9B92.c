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

#include "driver_utils.h"
#include "SYS_LM3S9B92.h"

void LM3S_PinInitializeAF (LM3S_AF_Pin_Config_t* pin) {
    MODIFY_REG(pin->pinPort->PCTL, pin->pinCtlMsk, pin->pinCtlCode);
    SET_BIT(pin->pinPort->AFSEL,   pin->pinNum);
    SET_BIT(pin->pinPort->ODR,     pin->pinNum);
    SET_BIT(pin->pinPort->PUR,     pin->pinNum);
    SET_BIT(pin->pinPort->DEN,     pin->pinNum);
}

void LM3S_PinUninitializeAF (LM3S_AF_Pin_Config_t* pin) {
    CLEAR_BIT(pin->pinPort->DEN,   pin->pinNum);
    CLEAR_BIT(pin->pinPort->AFSEL, pin->pinNum);
    CLEAR_REG(pin->pinPort->PCTL,  pin->pinCtlMsk);
    CLEAR_BIT(pin->pinPort->ODR,   pin->pinNum);
    CLEAR_BIT(pin->pinPort->PUR,   pin->pinNum);
    CLEAR_BIT(pin->pinPort->DIR,   pin->pinNum);
}
