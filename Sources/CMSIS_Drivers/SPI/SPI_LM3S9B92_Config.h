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

#ifndef __SPI_LM3S9B92_CONFIG_H
#define __SPI_LM3S9B92_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

// <e> SPI0 (Inter-integrated Circuit Interface 0)
// <i> Configuration settings for Driver_SPI0 in component ::CMSIS Driver:SPI
#define RTE_SPI0                        1
// <q> Use ROM
// <i> Use ROM-placed functions for SPI2 interface (accessable via MAP_)
#define SPI0_ROM_SELECTED               0
// <q> Use Stellaris Peripherial Library
// <i> Use STELLARIS functions for SPI0 interface
#define SPI0_STELLARIS_SELECTED               0

//   <o> SPI0_CLK Pin <1=>PA2
#define RTE_SPI0_CLK_PORT_ID_DEF        1
#if    (RTE_SPI0_CLK_PORT_ID_DEF == 1)
#define RTE_SPI0_CLK_PORT_CLOCK_EN_Msk  SYSCTL_RCGC2_GPIOB_Msk
#define RTE_SPI0_CLK_PORT               GPIOA
#define RTE_SPI0_CLK_PIN                (2U)
#define RTE_SPI0_CLK_PCTL_CODE          (1U << (4*RTE_SPI0_CLK_PIN))
#define RTE_SPI0_CLK_PCTL_MASK          GPIO_PCTL_PMC2_Msk
#else
#error "Invalid SPI0_CLK Pin Configuration!"
#endif

// <e> SPI0 Hardware SS control
#define RTE_SPI0_HW_SS                  1
//   <o> SPI0_SS Pin <1=>PA3
#define RTE_SPI0_SS_PORT_ID_DEF         1
#if    (RTE_SPI0_SS_PORT_ID_DEF == 1)
#define RTE_SPI0_SS_PORT_CLOCK_EN_Msk   SYSCTL_RCGC2_GPIOA_Msk
#define RTE_SPI0_SS_PORT                GPIOA
#define RTE_SPI0_SS_PIN                 (3U)
#define RTE_SPI0_SS_PCTL_CODE           (1U << (4*RTE_SPI0_SS_PIN))
#define RTE_SPI0_SS_PCTL_MASK           GPIO_PCTL_PMC3_Msk
#else
#error "Invalid SPI0_SDA Pin Configuration!"
#endif
// </e>

//   <o> SPI0_MISO Pin <1=>PA4
#define RTE_SPI0_MISO_PORT_ID_DEF       1
#if    (RTE_SPI0_MISO_PORT_ID_DEF == 1)
#define RTE_SPI0_MISO_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_SPI0_MISO_PORT              GPIOA
#define RTE_SPI0_MISO_PIN               (4U)
#define RTE_SPI0_MISO_PCTL_CODE         (1U << (4*RTE_SPI0_MISO_PIN))
#define RTE_SPI0_MISO_PCTL_MASK         GPIO_PCTL_PMC4_Msk
#else
#error "Invalid SPI0_SDA Pin Configuration!"
#endif

//   <o> SPI0_MOSI Pin <1=>PA5
#define RTE_SPI0_MOSI_PORT_ID_DEF       1
#if    (RTE_SPI0_MOSI_PORT_ID_DEF == 1)
#define RTE_SPI0_MOSI_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_SPI0_MOSI_PORT              GPIOA
#define RTE_SPI0_MOSI_PIN               (5U)
#define RTE_SPI0_MOSI_PCTL_CODE         (1U << (4*RTE_SPI0_MOSI_PIN))
#define RTE_SPI0_MOSI_PCTL_MASK         GPIO_PCTL_PMC5_Msk
#else
#error "Invalid SPI0_SDA Pin Configuration!"
#endif





//   <h> uDMA Management
//     <e> DMA Rx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <10=>10
//       <i>  Selects DMA Channel (only Channel 10 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_SPI0_RX_DMA                 1
#define RTE_SPI0_RX_DMA_NUMBER          1
#define RTE_SPI0_RX_DMA_CHANNEL         7
#define RTE_SPI0_RX_DMA_PRIORITY        0

//     <e> DMA Tx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <11=>11
//       <i>  Selects DMA Channel (only Channel 11 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_SPI0_TX_DMA                 1
#define RTE_SPI0_TX_DMA_NUMBER          1
#define RTE_SPI0_TX_DMA_CHANNEL         6
#define RTE_SPI0_TX_DMA_PRIORITY        0
//   </h>

//   <h> Power and Clock Management
//     <i> Settings for Sleep and Deep-Sleep modes.
//     <i> Warning: Settings will work only with ACG (check SYS_LM3S9B92_Config.h)
//     <q> Enable in SLEEP Mode (SCGC)
//     <i> Allows clock for the SPI0 in Sleep Mode.
#define RTE_SPI0_SLEEP_USER_SET         1

//     <q> Enable in DEEP-SLEEP Mode (DCGC)
//     <i> Allows clock for the SPI0 in Deep-Sleep Mode.
#define RTE_SPI0_DEEPSLEEP_USER_SET     1
//   </h>
// </e>

// <e> SPI1 (Inter-integrated Circuit Interface 0)
// <i> Configuration settings for Driver_SPI1 in component ::CMSIS Driver:SPI
#define RTE_SPI1                        1
// <q> Use ROM
// <i> Use ROM-placed functions for SPI2 interface (accessable via MAP_)
#define SPI1_ROM_SELECTED               0
// <q> Use Stellaris Peripherial Library
// <i> Use STELLARIS functions for SPI1 interface
#define SPI1_STELLARIS_SELECTED               0

//   <o> SPI1_CLK Pin <1=>PA2
#define RTE_SPI1_CLK_PORT_ID_DEF        1
#if    (RTE_SPI1_CLK_PORT_ID_DEF == 1)
#define RTE_SPI1_CLK_PORT_CLOCK_EN_Msk  SYSCTL_RCGC2_GPIOB_Msk
#define RTE_SPI1_CLK_PORT               GPIOA
#define RTE_SPI1_CLK_PIN                (2U)
#define RTE_SPI1_CLK_PCTL_CODE          (1U << (4*RTE_SPI1_CLK_PIN))
#define RTE_SPI1_CLK_PCTL_MASK          GPIO_PCTL_PMC2_Msk
#else
#error "Invalid SPI1_CLK Pin Configuration!"
#endif

// <e> SPI1 Hardware SS control
#define RTE_SPI1_HW_SS                  1
//   <o> SPI1_SS Pin <1=>PA3
#define RTE_SPI1_SS_PORT_ID_DEF         1
#if    (RTE_SPI1_SS_PORT_ID_DEF == 1)
#define RTE_SPI1_SS_PORT_CLOCK_EN_Msk   SYSCTL_RCGC2_GPIOA_Msk
#define RTE_SPI1_SS_PORT                GPIOA
#define RTE_SPI1_SS_PIN                 (3U)
#define RTE_SPI1_SS_PCTL_CODE           (1U << (4*RTE_SPI1_SS_PIN))
#define RTE_SPI1_SS_PCTL_MASK           GPIO_PCTL_PMC3_Msk
#else
#error "Invalid SPI1_SDA Pin Configuration!"
#endif
// </e>

//   <o> SPI1_MISO Pin <1=>PA4
#define RTE_SPI1_MISO_PORT_ID_DEF       1
#if    (RTE_SPI1_MISO_PORT_ID_DEF == 1)
#define RTE_SPI1_MISO_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_SPI1_MISO_PORT              GPIOA
#define RTE_SPI1_MISO_PIN               (4U)
#define RTE_SPI1_MISO_PCTL_CODE         (1U << (4*RTE_SPI1_MISO_PIN))
#define RTE_SPI1_MISO_PCTL_MASK         GPIO_PCTL_PMC4_Msk
#else
#error "Invalid SPI1_SDA Pin Configuration!"
#endif

//   <o> SPI1_MOSI Pin <1=>PA5
#define RTE_SPI1_MOSI_PORT_ID_DEF       1
#if    (RTE_SPI1_MOSI_PORT_ID_DEF == 1)
#define RTE_SPI1_MOSI_PORT_CLOCK_EN_Msk SYSCTL_RCGC2_GPIOA_Msk
#define RTE_SPI1_MOSI_PORT              GPIOA
#define RTE_SPI1_MOSI_PIN               (5U)
#define RTE_SPI1_MOSI_PCTL_CODE         (1U << (4*RTE_SPI1_MOSI_PIN))
#define RTE_SPI1_MOSI_PCTL_MASK         GPIO_PCTL_PMC5_Msk
#else
#error "Invalid SPI1_SDA Pin Configuration!"
#endif





//   <h> uDMA Management
//     <e> DMA Rx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <10=>10
//       <i>  Selects DMA Channel (only Channel 10 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_SPI1_RX_DMA                 1
#define RTE_SPI1_RX_DMA_NUMBER          1
#define RTE_SPI1_RX_DMA_CHANNEL         7
#define RTE_SPI1_RX_DMA_PRIORITY        0

//     <e> DMA Tx
//       <o1> Number <1=>1
//       <i>  Selects DMA Number (only DMA1 can be used)
//       <o2> Channel <11=>11
//       <i>  Selects DMA Channel (only Channel 11 can be used)
//       <o3> Priority <0=>Low <1=>Medium <2=>High <3=>Very High
//       <i>  Selects DMA Priority
//     </e>
#define RTE_SPI1_TX_DMA                 1
#define RTE_SPI1_TX_DMA_NUMBER          1
#define RTE_SPI1_TX_DMA_CHANNEL         6
#define RTE_SPI1_TX_DMA_PRIORITY        0
//   </h>

//   <h> Power and Clock Management
//     <i> Settings for Sleep and Deep-Sleep modes.
//     <i> Warning: Settings will work only with ACG (check SYS_LM3S9B92_Config.h)
//     <q> Enable in SLEEP Mode (SCGC)
//     <i> Allows clock for the SPI1 in Sleep Mode.
#define RTE_SPI1_SLEEP_USER_SET         1

//     <q> Enable in DEEP-SLEEP Mode (DCGC)
//     <i> Allows clock for the SPI1 in Deep-Sleep Mode.
#define RTE_SPI1_DEEPSLEEP_USER_SET     1
//   </h>
// </e>

//------------- <<< end of configuration section >>> ---------------------------

#ifdef __cplusplus
}
#endif

#endif  /* __SPI_LM3S9B92_CONFIG_H */
