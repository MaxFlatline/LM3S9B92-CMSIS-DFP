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

#ifndef __SYS_LM3S9B92_CONFIG_H
#define __SYS_LM3S9B92_CONFIG_H

#ifdef   _RTE_
#include "RTE_Components.h"
#ifdef    RTE_RTX_CONFIG_H
#include  RTE_RTX_CONFIG_H
#endif
#endif

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

// <h> System NVIC Configuration
//   <i> Global pre-init settings for NVIC priorities

//   <o> Interrupt Priority Grouping (PRIGROUP) <3=> Group 3 (8 Preemption / 0 Sub) <4=> Group 4 (4 Preemption / 2 Sub) <5=> Group 5 (2 Preemption / 4 Sub) <6=> Group 6 (0 Preemption / 8 Sub)
//   <i> Defines division between displacing priority groups and sub-priorities in each group.
//   <i> Warning: This setting will be meaningful only if there is no RTOS hijacking PRIGROUP control.
//   <i>   Group 3: 8 levels of displacement, no sub-priorities
//   <i>   Group 4: 4 levels of displacement, 2 sub-priorities each.
//   <i>   Group 5: 2 levels of displacement, 4 sub-priorities each.
//   <i>   Group 6: Displacement disabled. 8 sub-priorities define turn order.
// </h>
#define SYS_NVIC_PRIGROUP            3

// <h> System Clock Gating Configuration
//   <q> Set Auto Clock Gating
//   <i> If enabled, system will use registers Sleep-Mode Clock
//   <i> Gating Control (SCGCn) registers and Deep-Sleep-Mode Clock
//   <i> Gating Control (DCGCn) registers if the microcontroller enters a Sleep
//   <i> or Deep-Sleep mode (respectively)
// </h>
#define SYS_USE_ACG            1


//------------- <<< end of configuration section >>> ---------------------------

#endif  // __SYS_LM3S9B92_CONFIG_H
