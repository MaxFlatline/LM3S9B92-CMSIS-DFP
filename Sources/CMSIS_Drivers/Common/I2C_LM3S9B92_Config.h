/* -----------------------------------------------------------------------------
 * Copyright (c) 2013-2016 Arm Limited (or its affiliates). All 
 * rights reserved.
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
 *
 *
 * $Date:        09. September 2016
 * $Revision:    V1.1.2
 *
 * Project:      RTE Device Configuration for STMicroelectronics STM32F1xx
 *
 * -------------------------------------------------------------------------- */

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#ifndef __RTE_DEVICE_H
#define __RTE_DEVICE_H

// <e> I2C1 (Inter-integrated Circuit Interface 1)
// <i> Configuration settings for Driver_I2C1 in component ::CMSIS Driver:I2C
#define RTE_I2C1                        1
// <q> Use ROM
// <i> Use ROM-placed functions for I2C2 interface (accessable via MAP_)
#define I2C1_ROM_SELECTED               0
// <q> Use Stellaris Peripherial Library
// <i> Use STELLARIS functions for I2C2 interface
#define I2C1_STELLARIS_SELECTED               0
//   <o> I2C1_SCL Pin <1=>PJ0 <2=>PG0 <3=>PA0 <4=>PA6
#define RTE_I2C1_SCL_PORT_ID_DEF       1
#if    (RTE_I2C1_SCL_PORT_ID_DEF == 1)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOJ_Msk
#define RTE_I2C1_SCL_PORT_DEF          LM3S_GPIOJ
#define RTE_I2C1_SCL_BIT_DEF           0
#elif  (RTE_I2C1_SCL_PORT_ID_DEF == 2)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOG_Msk
#define RTE_I2C1_SCL_PORT_DEF          LM3S_GPIOG
#define RTE_I2C1_SCL_BIT_DEF           0
#elif  (RTE_I2C1_SCL_PORT_ID_DEF == 3)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SCL_PORT_DEF          LM3S_GPIOA
#define RTE_I2C1_SCL_BIT_DEF           0
#elif  (RTE_I2C1_SCL_PORT_ID_DEF == 4)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SCL_PORT_DEF          LM3S_GPIOA
#define RTE_I2C1_SCL_BIT_DEF           6
#else
#error "Invalid I2C1_SCL Pin Configuration!"
#endif

//   <o> I2C1_SDA Pin <1=>PG1 <2=>PA1 <3=>PA7 <4=>PJ1
#define RTE_I2C1_SDA_PORT_ID_DEF       4
#if    (RTE_I2C1_SDA_PORT_ID_DEF == 1)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOG_Msk
#define RTE_I2C1_SDA_PORT_DEF          LM3S_GPIOG
#define RTE_I2C1_SDA_BIT_DEF           1
#elif  (RTE_I2C1_SDA_PORT_ID_DEF == 2)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SDA_PORT_DEF          LM3S_GPIOA
#define RTE_I2C1_SDA_BIT_DEF           1
#elif  (RTE_I2C1_SDA_PORT_ID_DEF == 3)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SDA_PORT_DEF          LM3S_GPIOA
#define RTE_I2C1_SDA_BIT_DEF           7
#elif  (RTE_I2C1_SDA_PORT_ID_DEF == 4)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk LM3S_SYSCTL_RCGC2_GPIOJ_Msk
#define RTE_I2C1_SDA_PORT_DEF          LM3S_GPIOJ
#define RTE_I2C1_SDA_BIT_DEF           1
#else
#error "Invalid I2C1_SCL Pin Configuration!"
#endif

//   <e> DMA Rx
//     <o1> Number <1=>1
//     <i>  Selects DMA Number (only DMA1 can be used)
//     <o2> Channel <7=>7
//     <i>  Selects DMA Channel (only Channel 7 can be used)
//     <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//     <i>  Selects DMA Priority
//   </e>
#define RTE_I2C1_RX_DMA                 1
#define RTE_I2C1_RX_DMA_NUMBER          1
#define RTE_I2C1_RX_DMA_CHANNEL         7
#define RTE_I2C1_RX_DMA_PRIORITY        0

//   <e> DMA Tx
//     <o1> Number <1=>1
//     <i>  Selects DMA Number (only DMA1 can be used)
//     <o2> Channel <6=>6
//     <i>  Selects DMA Channel (only Channel 6 can be used)
//     <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//     <i>  Selects DMA Priority
//   </e>
#define RTE_I2C1_TX_DMA                 1
#define RTE_I2C1_TX_DMA_NUMBER          1
#define RTE_I2C1_TX_DMA_CHANNEL         6
#define RTE_I2C1_TX_DMA_PRIORITY        0





// </e>

#endif  /* __RTE_DEVICE_H */
