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

//-------- <<< Use Configuration Wizard in Context Menu >>> --------------------

#ifndef __I2C_LM3S9B92_CONFIG_H
#define __I2C_LM3S9B92_CONFIG_H

// <e> I2C0 (Inter-integrated Circuit Interface 0)
// <i> Configuration settings for Driver_I2C0 in component ::CMSIS Driver:I2C
#define RTE_I2C0                        0
// <q> Use ROM
// <i> Use ROM-placed functions for I2C2 interface (accessable via MAP_)
#define I2C0_ROM_SELECTED               0
// <q> Use Stellaris Peripherial Library
// <i> Use STELLARIS functions for I2C0 interface
#define I2C0_STELLARIS_SELECTED               0
//   <o> I2C0_SCL Pin <1=>PB2
#define RTE_I2C0_SCL_PORT_ID_DEF       1
#if    (RTE_I2C0_SCL_PORT_ID_DEF == 1)
#define RTE_I2C0_SCL_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOB_Msk
#define RTE_I2C0_SCL_PORT              GPIOB
#define RTE_I2C0_SCL_PIN               (2U)
#define RTE_I2C0_SCL_PCTL_CODE         (1U << (4*RTE_I2C0_SCL_PIN))
#define RTE_I2C0_SCL_PCTL_MASK         GPIO_PCTL_PMC2_Msk
#else
#error "Invalid I2C0_SCL Pin Configuration!"
#endif

//   <o> I2C0_SDA Pin <1=>PB3
#define RTE_I2C0_SDA_PORT_ID_DEF       1
#if    (RTE_I2C0_SDA_PORT_ID_DEF == 1)
#define RTE_I2C0_SDA_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOB_Msk
#define RTE_I2C0_SDA_PORT              GPIOG
#define RTE_I2C0_SDA_PIN               (3U)
#define RTE_I2C0_SDA_PCTL_CODE         (1U << (4*RTE_I2C0_SDA_PIN))
#define RTE_I2C0_SDA_PCTL_MASK         GPIO_PCTL_PMC3_Msk
#else
#error "Invalid I2C0_SDA Pin Configuration!"
#endif

//   <h> uDMA Management
//     <e> DMA Rx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <7=>7
//       <i>  Selects DMA Channel (only Channel 7 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_I2C0_RX_DMA                 0
#define RTE_I2C0_RX_DMA_NUMBER          1
#define RTE_I2C0_RX_DMA_CHANNEL         7
#define RTE_I2C0_RX_DMA_PRIORITY        0

//     <e> DMA Tx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <6=>6
//       <i>  Selects DMA Channel (only Channel 6 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_I2C0_TX_DMA                 0
#define RTE_I2C0_TX_DMA_NUMBER          1
#define RTE_I2C0_TX_DMA_CHANNEL         6
#define RTE_I2C0_TX_DMA_PRIORITY        0
//   </h>

//   <h> Power and Clock Management
//     <i> Settings for Sleep and Deep-Sleep modes.
//     <i> Warning: Settings will work only with ACG (check SYS_LM3S9B92_Config.h)
//     <q> Enable in SLEEP Mode (SCGC)
//     <i> Allows clock for the I2C0 in Sleep Mode.
#define RTE_I2C0_SLEEP_USER_SET         1

//     <q> Enable in DEEP-SLEEP Mode (DCGC)
//     <i> Allows clock for the I2C0 in Deep-Sleep Mode.
#define RTE_I2C0_DEEPSLEEP_USER_SET     1
//   </h>
// </e>

// <e> I2C1 (Inter-integrated Circuit Interface 1)
// <i> Configuration settings for Driver_I2C1 in component ::CMSIS Driver:I2C
#define RTE_I2C1                        1
// <q> Use ROM
// <i> Use ROM-placed functions for I2C2 interface (accessable via MAP_)
#define I2C1_ROM_SELECTED               0
// <q> Use Stellaris Peripherial Library
// <i> Use STELLARIS functions for I2C1 interface
#define I2C1_STELLARIS_SELECTED               0
//   <o> I2C1_SCL Pin <1=>PJ0 <2=>PG0 <3=>PA0 <4=>PA6
#define RTE_I2C1_SCL_PORT_ID_DEF       1
#if    (RTE_I2C1_SCL_PORT_ID_DEF == 1)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOJ_Msk
#define RTE_I2C1_SCL_PORT              GPIOJ
#define RTE_I2C1_SCL_PIN               (0U)
#define RTE_I2C1_SCL_PCTL_CODE         (11U << (4*RTE_I2C1_SCL_PIN))
#define RTE_I2C1_SCL_PCTL_MASK         GPIO_PCTL_PMC0_Msk
#elif  (RTE_I2C1_SCL_PORT_ID_DEF == 2)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOG_Msk
#define RTE_I2C1_SCL_PORT              GPIOG
#define RTE_I2C1_SCL_PIN               (0U)
#define RTE_I2C1_SCL_PCTL_CODE         (3U << (4*RTE_I2C1_SCL_PIN))
#define RTE_I2C1_SCL_PCTL_MASK         GPIO_PCTL_PMC0_Msk
#elif  (RTE_I2C1_SCL_PORT_ID_DEF == 3)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SCL_PORT              GPIOA
#define RTE_I2C1_SCL_PIN               (0U)
#define RTE_I2C1_SCL_PCTL_CODE         (8U << (4*RTE_I2C1_SCL_PIN))
#define RTE_I2C1_SCL_PCTL_MASK         GPIO_PCTL_PMC0_Msk
#elif  (RTE_I2C1_SCL_PORT_ID_DEF == 4)
#define RTE_I2C1_SCL_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SCL_PORT              GPIOA
#define RTE_I2C1_SCL_PIN               (6U)
#define RTE_I2C1_SCL_PCTL_CODE         (1U << (4*RTE_I2C1_SCL_PIN))
#define RTE_I2C1_SCL_PCTL_MASK         GPIO_PCTL_PMC6_Msk
#else
#error "Invalid I2C1_SCL Pin Configuration!"
#endif

//   <o> I2C1_SDA Pin <1=>PG1 <2=>PA1 <3=>PA7 <4=>PJ1
#define RTE_I2C1_SDA_PORT_ID_DEF       4
#if    (RTE_I2C1_SDA_PORT_ID_DEF == 1)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOG_Msk
#define RTE_I2C1_SDA_PORT              GPIOG
#define RTE_I2C1_SDA_PIN               (1U)
#define RTE_I2C1_SDA_PCTL_CODE         (3U << (4*RTE_I2C1_SDA_PIN))
#define RTE_I2C1_SDA_PCTL_MASK         GPIO_PCTL_PMC1_Msk
#elif  (RTE_I2C1_SDA_PORT_ID_DEF == 2)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SDA_PORT              GPIOA
#define RTE_I2C1_SDA_PIN               (1U)
#define RTE_I2C1_SDA_PCTL_CODE         (8U << (4*RTE_I2C1_SDA_PIN))
#define RTE_I2C1_SDA_PCTL_MASK         GPIO_PCTL_PMC1_Msk
#elif  (RTE_I2C1_SDA_PORT_ID_DEF == 3)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_I2C1_SDA_PORT              GPIOA
#define RTE_I2C1_SDA_PIN               (7U)
#define RTE_I2C1_SDA_PCTL_CODE         (1U << (4*RTE_I2C1_SDA_PIN))
#define RTE_I2C1_SDA_PCTL_MASK         GPIO_PCTL_PMC7_Msk
#elif  (RTE_I2C1_SDA_PORT_ID_DEF == 4)
#define RTE_I2C1_SDA_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOJ_Msk
#define RTE_I2C1_SDA_PORT              GPIOJ
#define RTE_I2C1_SDA_PIN               (1U)
#define RTE_I2C1_SDA_PCTL_CODE         (11U << (4*RTE_I2C1_SDA_PIN))
#define RTE_I2C1_SDA_PCTL_MASK         GPIO_PCTL_PMC1_Msk
#else
#error "Invalid I2C1_SDA Pin Configuration!"
#endif

//   <h> uDMA Management
//     <e> DMA Rx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <7=>7
//       <i>  Selects DMA Channel (only Channel 7 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_I2C1_RX_DMA                 0
#define RTE_I2C1_RX_DMA_NUMBER          1
#define RTE_I2C1_RX_DMA_CHANNEL         7
#define RTE_I2C1_RX_DMA_PRIORITY        0

//     <e> DMA Tx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <6=>6
//       <i>  Selects DMA Channel (only Channel 6 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_I2C1_TX_DMA                 0
#define RTE_I2C1_TX_DMA_NUMBER          1
#define RTE_I2C1_TX_DMA_CHANNEL         6
#define RTE_I2C1_TX_DMA_PRIORITY        0
//   </h>

//   <h> Power and Clock Management
//     <i> Settings for Sleep and Deep-Sleep modes.
//     <i> Warning: Settings will work only with ACG (check SYS_LM3S9B92_Config.h)
//     <q> Enable in SLEEP Mode (SCGC)
//     <i> Allows clock for the I2C1 in Sleep Mode.
#define RTE_I2C1_SLEEP_USER_SET         1

//     <q> Enable in DEEP-SLEEP Mode (DCGC)
//     <i> Allows clock for the I2C1 in Deep-Sleep Mode.
#define RTE_I2C1_DEEPSLEEP_USER_SET     1
//   </h>
// </e>



//------------- <<< end of configuration section >>> ---------------------------




#endif  /* __I2C_LM3S9B92_CONFIG_H */
