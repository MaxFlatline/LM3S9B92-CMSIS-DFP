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

#ifndef __SYS_LM3S9B92_H
#define __SYS_LM3S9B92_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "lm3s9b92.h"
#include "SYS_LM3S9B92_Config.h"

typedef const struct LM3S_AF_Pin_Config_s {
    uint32_t   pinNum;
    GPIO_Type* pinPort;
    uint32_t   portClkMask;
    uint32_t   pinCtlMsk;
    uint32_t   pinCtlCode;
}LM3S_AF_Pin_Config_t;

void LM3S_PinInitializeAF (LM3S_AF_Pin_Config_t* pin);
void LM3S_PinUninitializeAF (LM3S_AF_Pin_Config_t* pin);

#ifdef __cplusplus
}
#endif

#endif  // __SYS_LM3S9B92_H
