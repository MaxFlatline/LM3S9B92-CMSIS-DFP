/**************************************************************************//**
 * @file     lm3s9b92.h
 * @brief    CMSIS-Core(M) Device Header File for Device LM3S9B92
 *
 * @version  V1.0.0
 * @date     21. September 2025
 ******************************************************************************/
/*
 * Copyright (c) ToDo: Set Copyright owner
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


#ifndef LM3S9B92_H
#define LM3S9B92_H

#ifdef __cplusplus
extern "C" {
#endif


/* ========================================================================= */
/* ============           Interrupt Number Definition           ============ */
/* ========================================================================= */

typedef enum IRQn
{
/* ================     Cortex-M Core Exception Numbers     ================ */

  Reset_IRQn             = -15,  /*  1 Reset Vector
                                       invoked on Power up and warm reset */
  NonMaskableInt_IRQn    = -14,  /*  2 Non maskable Interrupt
                                       cannot be stopped or preempted */
  HardFault_IRQn         = -13,  /*  3 Hard Fault
                                       all classes of Fault */
  MemoryManagement_IRQn  = -12,  /*  4 Memory Management
                                       MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn          = -11,  /*  5 Bus Fault
                                       Pre-Fetch-, Memory Access, other address/memory Fault */
  UsageFault_IRQn        = -10,  /*  6 Usage Fault
                                       i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn       =  -9,  /*  7 Secure Fault Interrupt */
  SVCall_IRQn            =  -5,  /* 11 System Service Call via SVC instruction */
  DebugMonitor_IRQn      =  -4,  /* 12 Debug Monitor */
  PendSV_IRQn            =  -2,  /* 14 Pendable request for system service */
  SysTick_IRQn           =  -1,  /* 15 System Tick Timer */

/* ---------------------  LM3S9B92 Specific Interrupt Numbers  -------------------- */
  GPIOA_IRQn             =   0,  /*  0  GPIOA Interrupt Handler */
  GPIOB_IRQn             =   1,  /*  1  GPIOB Interrupt Handler */
  GPIOC_IRQn             =   2,  /*  2  GPIOC Interrupt Handler */
  GPIOD_IRQn             =   3,  /*  3  GPIOD Interrupt Handler */
  GPIOE_IRQn             =   4,  /*  4  GPIOE Interrupt Handler */
  UART0_IRQn             =   5,  /*  5  UART0 Interrupt Handler */
  UART1_IRQn             =   6,  /*  6  UART1 Interrupt Handler */
  SSI0_IRQn              =   7,  /*  7  SSI0 Interrupt Handler */
  I2C0_IRQn              =   8,  /*  8  I2C0 Interrupt Handler */
  PWM0_FAULT_IRQn        =   9,  /*  9  PWM0 Fault Interrupt Handler */
  PWM0_0_IRQn            =  10,  /* 10  PWM0 Generator 0 Interrupt Handler */
  PWM0_1_IRQn            =  11,  /* 11  PWM0 Generator 1 Interrupt Handler */
  PWM0_2_IRQn            =  12,  /* 12  PWM0 Generator 2 Interrupt Handler */
  QEI0_IRQn              =  13,  /* 13  Quadrature Encoder 0 Interrupt Handler */
  ADC0SS0_IRQn           =  14,  /* 14  ADC0 Sequence 0 Interrupt Handler */
  ADC0SS1_IRQn           =  15,  /* 15  ADC0 Sequence 1 Interrupt Handler */
  ADC0SS2_IRQn           =  16,  /* 16  ADC0 Sequence 2 Interrupt Handler */
  ADC0SS3_IRQn           =  17,  /* 17  ADC0 Sequence 3 Interrupt Handler */
  WATCHDOG0_IRQn         =  18,  /* 18  WATCHDOG0 Interrupt Handler */
  TIMER0A_IRQn           =  19,  /* 19  Timer 0 Subtimer A Interrupt Handler */
  TIMER0B_IRQn           =  20,  /* 20  Timer 0 Subtimer B Interrupt Handler */
  TIMER1A_IRQn           =  21,  /* 21  Timer 1 Subtimer A Interrupt Handler */
  TIMER1B_IRQn           =  22,  /* 22  Timer 1 Subtimer B Interrupt Handler */
  TIMER2A_IRQn           =  23,  /* 23  Timer 2 Subtimer A Interrupt Handler */
  TIMER2B_IRQn           =  24,  /* 24  Timer 2 Subtimer B Interrupt Handler */
  COMP0_IRQn             =  25,  /* 25  COMP0 Interrupt Handler */
  COMP1_IRQn             =  26,  /* 26  COMP1 Interrupt Handler */
  COMP2_IRQn             =  27,  /* 27  COMP2 Interrupt Handler */
  SYSCTL_IRQn            =  28,  /* 28  SYSCTL Interrupt Handler */
  FLASH_CTRL_IRQn        =  29,  /* 29  FLASH_CTRL Interrupt Handler */
  GPIOF_IRQn             =  30,  /* 30  GPIOF Interrupt Handler */
  GPIOG_IRQn             =  31,  /* 31  GPIOG Interrupt Handler */
  GPIOH_IRQn             =  32,  /* 32  GPIOH Interrupt Handler */
  UART2_IRQn             =  33,  /* 33  UART2 Interrupt Handler */
  SSI1_IRQn              =  34,  /* 34  SSI1 Interrupt Handler */
  TIMER3A_IRQn           =  35,  /* 35  Timer 3 Subtimer A Interrupt Handler */
  TIMER3B_IRQn           =  36,  /* 36  Timer 3 Subtimer B Interrupt Handler */
  I2C1_IRQn              =  37,  /* 37  I2C1 Interrupt Handler */
  QEI1_IRQn              =  38,  /* 38  Quadrature Encoder 1 Interrupt Handler */
  CAN0_IRQn              =  39,  /* 39  CAN0 Interrupt Handler */
  CAN1_IRQn              =  40,  /* 40  CAN1 Interrupt Handler */
  ETH_IRQn               =  42,  /* 42  Ethernet Controller Interrupt Handler */
  USB0_IRQn              =  44,  /* 44  USB0 Interrupt Handler */
  PWM0_3_IRQn            =  45,  /* 45  PWM0 Generator 3 Interrupt Handler */
  UDMA_IRQn              =  46,  /* 46  uDMA Interrupt Handler */
  UDMAERR_IRQn           =  47,  /* 47  uDMA Error Interrupt Handler */
  ADC1SS0_IRQn           =  48,  /* 48  ADC1 Sequence 0 Interrupt Handler */
  ADC1SS1_IRQn           =  49,  /* 49  ADC1 Sequence 1 Interrupt Handler */
  ADC1SS2_IRQn           =  50,  /* 50  ADC1 Sequence 2 Interrupt Handler */
  ADC1SS3_IRQn           =  51,  /* 51  ADC1 Sequence 3 Interrupt Handler */
  I2S0_IRQn              =  52,  /* 52  I2S0 Interrupt Handler */
  EPI0_IRQn              =  53,  /* 53  External Peripheral Interface 0 Interrupt Handler */
  GPIOJ_IRQn             =  54   /* 54  GPIOJ Interrupt Handler */
} IRQn_Type;


/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM3_REV               0x0200U  /* Core Revision r2p0 */
#define __Vendor_SysTickConfig  0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        3U       /* Number of Bits used for Priority Levels */
#define __VTOR_PRESENT          0U       /* Set to 1 if VTOR is present */
#define __MPU_PRESENT           0U       /* Set to 1 if MPU is present */
#define __FPU_PRESENT           0U       /* Set to 1 if FPU is present */
#define __FPU_DP                0U       /* Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __DSP_PRESENT           0U       /* Set to 1 if DSP extension are present */
#define __SAUREGION_PRESENT     0U       /* Set to 1 if SAU regions are present */
#define __PMU_PRESENT           0U       /* Set to 1 if PMU is present */
#define __PMU_NUM_EVENTCNT      0U       /* Set number of PMU Event Counters */
#define __ICACHE_PRESENT        0U       /* Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT        0U       /* Set to 1 if D-Cache is present */
#define __DTCM_PRESENT          0U       /* Set to 1 if DTCM is present */


#include <core_cm3.h>                           /* Processor and core peripherals */
#include "system_lm3s9b92.h"                    /* System Header */



/* ========================================================================= */
/* ============       Device Specific Peripheral Section        ============ */
/* ========================================================================= */


/* ================================================================================ */
/* ================                      WDT                       ================ */
/* ================================================================================ */

/**
  * @brief Register map for WATCHDOG peripheral (LM3S_WDT)
  */
typedef struct {
  __IOM uint32_t  LOAD;                 /* Offset: 0x000 (R/W) Load */
  __IOM uint32_t  VALUE;                /* Offset: 0x004 (R/W) Value */
  __IOM uint32_t  CTL;                  /* Offset: 0x008 (R/W) Control */
  __OM  uint32_t  ICR;                  /* Offset: 0x00C ( /W) Interrupt Clear */
  __IOM uint32_t  RIS;                  /* Offset: 0x010 (R/W) Raw Interrupt Status */
  __IOM uint32_t  MIS;                  /* Offset: 0x014 (R/W) Masked Interrupt Status */
  __IM  uint32_t  RESERVED0[256];
  __IOM uint32_t  TEST;                 /* Offset: 0x418 (R/W)  Test */
  __IM  uint32_t  RESERVED1[505];
  __IOM uint32_t  LOCK;                 /* Offset: 0xC00 (R/W) Lock */
  __IM  uint32_t  RESERVED2[243];
  __IM  uint32_t  PID4;                 /* Offset: 0xFD0 (R/ ) Peripheral Identification Register 4 */
  __IM  uint32_t  PID5;                 /* Offset: 0xFD4 (R/ ) Peripheral Identification Register 5 */
  __IM  uint32_t  PID6;                 /* Offset: 0xFD8 (R/ ) Peripheral Identification Register 6 */
  __IM  uint32_t  PID7;                 /* Offset: 0xFDC (R/ ) Peripheral Identification Register 7 */
  __IM  uint32_t  PID0;                 /* Offset: 0xFE0 (R/ ) Peripheral Identification Register 0 */
  __IM  uint32_t  PID1;                 /* Offset: 0xFE4 (R/ ) Peripheral Identification Register 1 */
  __IM  uint32_t  PID2;                 /* Offset: 0xFE8 (R/ ) Peripheral Identification Register 2 */
  __IM  uint32_t  PID3;                 /* Offset: 0xFEC (R/ ) Peripheral Identification Register 3 */
  __IM  uint32_t  PCID0;                /* Offset: 0xFF0 (R/ ) PrimeCell Identification Register 0 */
  __IM  uint32_t  PCID1;                /* Offset: 0xFF4 (R/ ) PrimeCell Identification Register 1 */
  __IM  uint32_t  PCID2;                /* Offset: 0xFF8 (R/ ) PrimeCell Identification Register 2 */
  __IM  uint32_t  PCID3;                /* Offset: 0xFFC (R/ ) PrimeCell Identification Register 3 */
} LM3S_WDT_TypeDef;

/* LM3S_WDT LOAD Register Definitions */
#define LM3S_WDT_LOAD_Pos                         0
#define LM3S_WDT_LOAD_Msk                        (0xFFFFFFFFUL /*<< LM3S_WDT_LOAD_Pos*/)

/* LM3S_WDT VALUE Register Definitions */
#define LM3S_WDT_VALUE_Pos                        0
#define LM3S_WDT_VALUE_Msk                       (0xFFFFFFFFUL /*<< LM3S_WDT_VALUE_Pos*/)

/* LM3S_WDT CTL Register Definitions */
#define LM3S_WDT_CTL_WRC_Pos                     31
#define LM3S_WDT_CTL_WRC_Msk                     (1UL << LM3S_WDT_CTL_WRC_Pos)

#define LM3S_WDT_CTL_RESEN_Pos                    1
#define LM3S_WDT_CTL_RESEN_Msk                   (1UL << LM3S_WDT_CTL_RESEN_Pos)

#define LM3S_WDT_CTL_INTEN_Pos                    0
#define LM3S_WDT_CTL_INTEN_Msk                   (1UL /*<< LM3S_WDT_CTL_INTEN_Pos*/)

/* LM3S_WDT ICR Register Definitions */
#define LM3S_WDT_ICR_Pos                          0
#define LM3S_WDT_ICR_Msk                         (0xFFFFFFFFUL /*<< LM3S_WDT_ICR_Pos*/)

/* LM3S9B92_WDT RIS Register Definitions */
#define LM3S_WDT_RIS_WDTRIS_Pos                   0
#define LM3S_WDT_RIS_WDTRIS_Msk                  (1UL /*<< LM3S_WDT_RIS_WDTRIS_Pos*/)

/* LM3S_WDT MIS Register Definitions */
#define LM3S_WDT_MIS_WDTMIS_Pos                   0
#define LM3S_WDT_MIS_WDTMIS_Msk                  (1UL /*<< LM3S_WDT_MIS_WDTMIS_Pos*/)

/* LM3S_WDT TEST Register Definitions */
#define LM3S_WDT_TEST_STALL_Pos                   8
#define LM3S_WDT_TEST_STALL_Msk                  (1UL << LM3S_WDT_TEST_STALL_Pos)

/* LM3S_WDT LOCK Register Definitions */
#define LM3S_WDT_LOCK_Pos                         0
#define LM3S_WDT_LOCK_Msk                        (0xFFFFFFFFUL /*<< LM3S_WDT_LOCK_Pos*/)

/* LM3S_WDT PID4 Register Definitions */
#define LM3S_WDT_PID4_PID4_Pos                    0
#define LM3S_WDT_PID4_PID4_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID4_PID4_Pos*/)

/* LM3S_WDT PID5 Register Definitions */
#define LM3S_WDT_PID5_PID5_Pos                    0
#define LM3S_WDT_PID5_PID5_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID5_PID5_Pos*/)

/* LM3S_WDT PID6 Register Definitions */
#define LM3S_WDT_PID6_PID6_Pos                    0
#define LM3S_WDT_PID6_PID6_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID6_PID6_Pos*/)

/* LM3S_WDT PID7 Register Definitions */
#define LM3S_WDT_PID7_PID7_Pos                    0
#define LM3S_WDT_PID7_PID7_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID7_PID7_Pos*/)

/* LM3S_WDT PID0 Register Definitions */
#define LM3S_WDT_PID0_PID0_Pos                    0
#define LM3S_WDT_PID0_PID0_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID0_PID0_Pos*/)

/* LM3S_WDT PID1 Register Definitions */
#define LM3S_WDT_PID1_PID1_Pos                    0
#define LM3S_WDT_PID1_PID1_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID1_PID1_Pos*/)

/* LM3S_WDT PID2 Register Definitions */
#define LM3S_WDT_PID2_PID2_Pos                    0
#define LM3S_WDT_PID2_PID2_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID2_PID2_Pos*/)

/* LM3S_WDT PID3 Register Definitions */
#define LM3S_WDT_PID3_PID3_Pos                    0
#define LM3S_WDT_PID3_PID3_Msk                   (0x000000FFUL /*<< LM3S_WDT_PID3_PID3_Pos*/)

/* LM3S_WDT PCID0 Register Definitions */
#define LM3S_WDT_PCID0_PCID0_Pos                  0
#define LM3S_WDT_PCID0_PCID0_Msk                 (0x000000FFUL /*<< LM3S_WDT_PCID0_PCID0_Pos*/)

/* LM3S_WDT PCID1 Register Definitions */
#define LM3S_WDT_PCID1_PCID1_Pos                  0
#define LM3S_WDT_PCID1_PCID1_Msk                 (0x000000FFUL /*<< LM3S_WDT_PCID1_PCID1_Pos*/)

/* LM3S_WDT PCID2 Register Definitions */
#define LM3S_WDT_PCID2_PCID2_Pos                  0
#define LM3S_WDT_PCID2_PCID2_Msk                 (0x000000FFUL /*<< LM3S_WDT_PCID2_PCID2_Pos*/)

/* LM3S_WDT PCID3 Register Definitions */
#define LM3S_WDT_PCID3_PCID3_Pos                  0
#define LM3S_WDT_PCID3_PCID3_Msk                 (0x000000FFUL /*<< LM3S_WDT_PCID3_PCID3_Pos*/)

/* ================================================================================ */
/* ================                     GPIO                       ================ */
/* ================================================================================ */

/**
  * @brief Register map for GPIO peripheral (LM3S_GPIO)
  */
typedef struct {
  __IOM uint32_t  DATA[256];            /* Offset: 0x000 (R/W) Data Register (individual)*/
  __IOM uint32_t  DIR;                  /* Offset: 0x400 (R/W) Direction Register */
  __IOM uint32_t  IS;                   /* Offset: 0x404 (R/W) Interrupt Sense Register */
  __IOM uint32_t  IBE;                  /* Offset: 0x408 (R/W) Interrupt Both Edges Register */
  __IOM uint32_t  IEV;                  /* Offset: 0x40C (R/W) Interrupt Event Register */
  __IOM uint32_t  IM;                   /* Offset: 0x410 (R/W) Interrupt Mask Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x414 (R/ ) Raw Interrupt Status Register */
  __IM  uint32_t  MIS;                  /* Offset: 0x418 (R/W) Masked Interrupt Status Register */
  __OM  uint32_t  ICR;                  /* Offset: 0x41C ( /W) Interrupt Clear Register (Write 1 to clear) */
  __IOM uint32_t  AFSEL;                /* Offset: 0x420 (R/W) Alternate Function Select Register */
  __IM  uint32_t  RESERVED1[55];
  __IOM uint32_t  DR2R;                 /* Offset: 0x500 (R/W) 2-ma Drive Select Register */
  __IOM uint32_t  DR4R;                 /* Offset: 0x504 (R/W) 4-ma Drive Select Register */
  __IOM uint32_t  DR8R;                 /* Offset: 0x508 (R/W) 8-ma Drive Select Register */
  __IOM uint32_t  ODR;                  /* Offset: 0x50C (R/W) Open Drain Select Register */
  __IOM uint32_t  PUR;                  /* Offset: 0x510 (R/W) Pull-Up Select Register */
  __IOM uint32_t  PDR;                  /* Offset: 0x514 (R/W) Pull-Down Select Register */
  __IOM uint32_t  SLR;                  /* Offset: 0x518 (R/W) Slew Rate Control Select Register */
  __IOM uint32_t  DEN;                  /* Offset: 0x51C (R/W) Digital Enable Register */
  __IOM uint32_t  LOCK;                 /* Offset: 0x520 (R/W) Lock Register */
  __IOM uint32_t  CR;                   /* Offset: 0x524 (R/W) Commit Register (RO for every pin other than JTAG/SWD and NMI pins)*/
  __IOM uint32_t  AMSEL;                /* Offset: 0x528 (R/W) Analog Mode Select Register */
  __IOM uint32_t  PCTL;                 /* Offset: 0x52C (R/W) Port Control Register */
  __IM  uint32_t  RESERVED2[680];
  __IM  uint32_t  PID4;                 /* Offset: 0xFD0 (R/ ) Peripheral Identification Register 4 */
  __IM  uint32_t  PID5;                 /* Offset: 0xFD4 (R/ ) Peripheral Identification Register 5 */
  __IM  uint32_t  PID6;                 /* Offset: 0xFD8 (R/ ) Peripheral Identification Register 6 */
  __IM  uint32_t  PID7;                 /* Offset: 0xFDC (R/ ) Peripheral Identification Register 7 */
  __IM  uint32_t  PID0;                 /* Offset: 0xFE0 (R/ ) Peripheral Identification Register 0 */
  __IM  uint32_t  PID1;                 /* Offset: 0xFE4 (R/ ) Peripheral Identification Register 1 */
  __IM  uint32_t  PID2;                 /* Offset: 0xFE8 (R/ ) Peripheral Identification Register 2 */
  __IM  uint32_t  PID3;                 /* Offset: 0xFEC (R/ ) Peripheral Identification Register 3 */
  __IM  uint32_t  PCID0;                /* Offset: 0xFF0 (R/ ) PrimeCell Identification Register 0 */
  __IM  uint32_t  PCID1;                /* Offset: 0xFF4 (R/ ) PrimeCell Identification Register 1 */
  __IM  uint32_t  PCID2;                /* Offset: 0xFF8 (R/ ) PrimeCell Identification Register 2 */
  __IM  uint32_t  PCID3;                /* Offset: 0xFFC (R/ ) PrimeCell Identification Register 3 */
} LM3S_GPIO_TypeDef;


/* LM3S_GPIO DATA Register Definitions */
#define LM3S_GPIO_DATA_PIN7_Pos                   7
#define LM3S_GPIO_DATA_PIN7_Msk                  (1UL << LM3S_GPIO_DATA_PIN7_Pos)

#define LM3S_GPIO_DATA_PIN6_Pos                   6
#define LM3S_GPIO_DATA_PIN6_Msk                  (1UL << LM3S_GPIO_DATA_PIN6_Pos)

#define LM3S_GPIO_DATA_PIN5_Pos                   5
#define LM3S_GPIO_DATA_PIN5_Msk                  (1UL << LM3S_GPIO_DATA_PIN5_Pos)

#define LM3S_GPIO_DATA_PIN4_Pos                   4
#define LM3S_GPIO_DATA_PIN4_Msk                  (1UL << LM3S_GPIO_DATA_PIN4_Pos)

#define LM3S_GPIO_DATA_PIN3_Pos                   3
#define LM3S_GPIO_DATA_PIN3_Msk                  (1UL << LM3S_GPIO_DATA_PIN3_Pos)

#define LM3S_GPIO_DATA_PIN2_Pos                   2
#define LM3S_GPIO_DATA_PIN2_Msk                  (1UL << LM3S_GPIO_DATA_PIN2_Pos)

#define LM3S_GPIO_DATA_PIN1_Pos                   1
#define LM3S_GPIO_DATA_PIN1_Msk                  (1UL << LM3S_GPIO_DATA_PIN1_Pos)

#define LM3S_GPIO_DATA_PIN0_Pos                   0
#define LM3S_GPIO_DATA_PIN0_Msk                  (1UL /*<< LM3S_GPIO_DATA_PIN0_Pos*/)

/* LM3S_GPIO DIR Register Definitions */
#define LM3S_GPIO_DIR_DIR7_Pos                    7
#define LM3S_GPIO_DIR_DIR7_Msk                   (1UL << LM3S_GPIO_DIR_DIR7_Pos)

#define LM3S_GPIO_DIR_DIR6_Pos                    6
#define LM3S_GPIO_DIR_DIR6_Msk                   (1UL << LM3S_GPIO_DIR_DIR6_Pos)

#define LM3S_GPIO_DIR_DIR5_Pos                    5
#define LM3S_GPIO_DIR_DIR5_Msk                   (1UL << LM3S_GPIO_DIR_DIR5_Pos)

#define LM3S_GPIO_DIR_DIR4_Pos                    4
#define LM3S_GPIO_DIR_DIR4_Msk                   (1UL << LM3S_GPIO_DIR_DIR4_Pos)

#define LM3S_GPIO_DIR_DIR3_Pos                    3
#define LM3S_GPIO_DIR_DIR3_Msk                   (1UL << LM3S_GPIO_DIR_DIR3_Pos)

#define LM3S_GPIO_DIR_DIR2_Pos                    2
#define LM3S_GPIO_DIR_DIR2_Msk                   (1UL << LM3S_GPIO_DIR_DIR2_Pos)

#define LM3S_GPIO_DIR_DIR1_Pos                    1
#define LM3S_GPIO_DIR_DIR1_Msk                   (1UL << LM3S_GPIO_DIR_DIR1_Pos)

#define LM3S_GPIO_DIR_DIR0_Pos                    0
#define LM3S_GPIO_DIR_DIR0_Msk                   (1UL /*<< LM3S_GPIO_DIR_DIR0_Pos*/)

/* LM3S_GPIO IS Register Definitions */
#define LM3S_GPIO_IS_IS7_Pos                      7
#define LM3S_GPIO_IS_IS7_Msk                     (1UL << LM3S_GPIO_IS_IS7_Pos)

#define LM3S_GPIO_IS_IS6_Pos                      6
#define LM3S_GPIO_IS_IS6_Msk                     (1UL << LM3S_GPIO_IS_IS6_Pos)

#define LM3S_GPIO_IS_IS5_Pos                      5
#define LM3S_GPIO_IS_IS5_Msk                     (1UL << LM3S_GPIO_IS_IS5_Pos)

#define LM3S_GPIO_IS_IS4_Pos                      4
#define LM3S_GPIO_IS_IS4_Msk                     (1UL << LM3S_GPIO_IS_IS4_Pos)

#define LM3S_GPIO_IS_IS3_Pos                      3
#define LM3S_GPIO_IS_IS3_Msk                     (1UL << LM3S_GPIO_IS_IS3_Pos)

#define LM3S_GPIO_IS_IS2_Pos                      2
#define LM3S_GPIO_IS_IS2_Msk                     (1UL << LM3S_GPIO_IS_IS2_Pos)

#define LM3S_GPIO_IS_IS1_Pos                      1
#define LM3S_GPIO_IS_IS1_Msk                     (1UL << LM3S_GPIO_IS_IS1_Pos)

#define LM3S_GPIO_IS_IS0_Pos                      0
#define LM3S_GPIO_IS_IS0_Msk                     (1UL /*<< LM3S_GPIO_IS_IS0_Pos*/)

/* LM3S_GPIO IBE Register Definitions */
#define LM3S_GPIO_IBE_IBE0_Pos                    0
#define LM3S_GPIO_IBE_IBE0_Msk                   (1UL /*<< LM3S_GPIO_IBE_IBE0_Pos*/)

#define LM3S_GPIO_IBE_IBE1_Pos                    1
#define LM3S_GPIO_IBE_IBE1_Msk                   (1UL << LM3S_GPIO_IBE_IBE1_Pos)

#define LM3S_GPIO_IBE_IBE2_Pos                    2
#define LM3S_GPIO_IBE_IBE2_Msk                   (1UL << LM3S_GPIO_IBE_IBE2_Pos)

#define LM3S_GPIO_IBE_IBE3_Pos                    3
#define LM3S_GPIO_IBE_IBE3_Msk                   (1UL << LM3S_GPIO_IBE_IBE3_Pos)

#define LM3S_GPIO_IBE_IBE4_Pos                    4
#define LM3S_GPIO_IBE_IBE4_Msk                   (1UL << LM3S_GPIO_IBE_IBE4_Pos)

#define LM3S_GPIO_IBE_IBE5_Pos                    5
#define LM3S_GPIO_IBE_IBE5_Msk                   (1UL << LM3S_GPIO_IBE_IBE5_Pos)

#define LM3S_GPIO_IBE_IBE6_Pos                    6
#define LM3S_GPIO_IBE_IBE6_Msk                   (1UL << LM3S_GPIO_IBE_IBE6_Pos)

#define LM3S_GPIO_IBE_IBE7_Pos                    7
#define LM3S_GPIO_IBE_IBE7_Msk                   (1UL << LM3S_GPIO_IBE_IBE7_Pos)

/* LM3S_GPIO IEV Register Definitions */
#define LM3S_GPIO_IEV_IEV7_Pos                    7
#define LM3S_GPIO_IEV_IEV7_Msk                   (1UL << LM3S_GPIO_IEV_IEV7_Pos)

#define LM3S_GPIO_IEV_IEV6_Pos                    6
#define LM3S_GPIO_IEV_IEV6_Msk                   (1UL << LM3S_GPIO_IEV_IEV6_Pos)

#define LM3S_GPIO_IEV_IEV5_Pos                    5
#define LM3S_GPIO_IEV_IEV5_Msk                   (1UL << LM3S_GPIO_IEV_IEV5_Pos)

#define LM3S_GPIO_IEV_IEV4_Pos                    4
#define LM3S_GPIO_IEV_IEV4_Msk                   (1UL << LM3S_GPIO_IEV_IEV4_Pos)

#define LM3S_GPIO_IEV_IEV3_Pos                    3
#define LM3S_GPIO_IEV_IEV3_Msk                   (1UL << LM3S_GPIO_IEV_IEV3_Pos)

#define LM3S_GPIO_IEV_IEV2_Pos                    2
#define LM3S_GPIO_IEV_IEV2_Msk                   (1UL << LM3S_GPIO_IEV_IEV2_Pos)

#define LM3S_GPIO_IEV_IEV1_Pos                    1
#define LM3S_GPIO_IEV_IEV1_Msk                   (1UL << LM3S_GPIO_IEV_IEV1_Pos)

#define LM3S_GPIO_IEV_IEV0_Pos                    0
#define LM3S_GPIO_IEV_IEV0_Msk                   (1UL /*<< LM3S_GPIO_IEV_IEV0_Pos*/)

/* LM3S_GPIO IM Register Definitions */
#define LM3S_GPIO_IM_IME7_Pos                     7
#define LM3S_GPIO_IM_IME7_Msk                    (1UL << LM3S_GPIO_IM_IME7_Pos)

#define LM3S_GPIO_IM_IME6_Pos                     6
#define LM3S_GPIO_IM_IME6_Msk                    (1UL << LM3S_GPIO_IM_IME6_Pos)

#define LM3S_GPIO_IM_IME5_Pos                     5
#define LM3S_GPIO_IM_IME5_Msk                    (1UL << LM3S_GPIO_IM_IME5_Pos)

#define LM3S_GPIO_IM_IME4_Pos                     4
#define LM3S_GPIO_IM_IME4_Msk                    (1UL << LM3S_GPIO_IM_IME4_Pos)

#define LM3S_GPIO_IM_IME3_Pos                     3
#define LM3S_GPIO_IM_IME3_Msk                    (1UL << LM3S_GPIO_IM_IME3_Pos)

#define LM3S_GPIO_IM_IME2_Pos                     2
#define LM3S_GPIO_IM_IME2_Msk                    (1UL << LM3S_GPIO_IM_IME2_Pos)

#define LM3S_GPIO_IM_IME1_Pos                     1
#define LM3S_GPIO_IM_IME1_Msk                    (1UL << LM3S_GPIO_IM_IME1_Pos)

#define LM3S_GPIO_IM_IME0_Pos                     0
#define LM3S_GPIO_IM_IME0_Msk                    (1UL /*<< LM3S_GPIO_IM_IME0_Pos*/)

/* LM3S_GPIO RIS Register Definitions */
#define LM3S_GPIO_RIS_RIS7_Pos                    7
#define LM3S_GPIO_RIS_RIS7_Msk                   (1UL << LM3S_GPIO_RIS_RIS7_Pos)

#define LM3S_GPIO_RIS_RIS6_Pos                    6
#define LM3S_GPIO_RIS_RIS6_Msk                   (1UL << LM3S_GPIO_RIS_RIS6_Pos)

#define LM3S_GPIO_RIS_RIS5_Pos                    5
#define LM3S_GPIO_RIS_RIS5_Msk                   (1UL << LM3S_GPIO_RIS_RIS5_Pos)

#define LM3S_GPIO_RIS_RIS4_Pos                    4
#define LM3S_GPIO_RIS_RIS4_Msk                   (1UL << LM3S_GPIO_RIS_RIS4_Pos)

#define LM3S_GPIO_RIS_RIS3_Pos                    3
#define LM3S_GPIO_RIS_RIS3_Msk                   (1UL << LM3S_GPIO_RIS_RIS3_Pos)

#define LM3S_GPIO_RIS_RIS2_Pos                    2
#define LM3S_GPIO_RIS_RIS2_Msk                   (1UL << LM3S_GPIO_RIS_RIS2_Pos)

#define LM3S_GPIO_RIS_RIS1_Pos                    1
#define LM3S_GPIO_RIS_RIS1_Msk                   (1UL << LM3S_GPIO_RIS_RIS1_Pos)

#define LM3S_GPIO_RIS_RIS0_Pos                    0
#define LM3S_GPIO_RIS_RIS0_Msk                   (1UL /*<< LM3S_GPIO_RIS_RIS0_Pos*/)

/* LM3S_GPIO MIS Register Definitions */
#define LM3S_GPIO_MIS_MIS7_Pos                    7
#define LM3S_GPIO_MIS_MIS7_Msk                   (1UL << LM3S_GPIO_MIS_MIS7_Pos)

#define LM3S_GPIO_MIS_MIS6_Pos                    6
#define LM3S_GPIO_MIS_MIS6_Msk                   (1UL << LM3S_GPIO_MIS_MIS6_Pos)

#define LM3S_GPIO_MIS_MIS5_Pos                    5
#define LM3S_GPIO_MIS_MIS5_Msk                   (1UL << LM3S_GPIO_MIS_MIS5_Pos)

#define LM3S_GPIO_MIS_MIS4_Pos                    4
#define LM3S_GPIO_MIS_MIS4_Msk                   (1UL << LM3S_GPIO_MIS_MIS4_Pos)

#define LM3S_GPIO_MIS_MIS3_Pos                    3
#define LM3S_GPIO_MIS_MIS3_Msk                   (1UL << LM3S_GPIO_MIS_MIS3_Pos)

#define LM3S_GPIO_MIS_MIS2_Pos                    2
#define LM3S_GPIO_MIS_MIS2_Msk                   (1UL << LM3S_GPIO_MIS_MIS2_Pos)

#define LM3S_GPIO_MIS_MIS1_Pos                    1
#define LM3S_GPIO_MIS_MIS1_Msk                   (1UL << LM3S_GPIO_MIS_MIS1_Pos)

#define LM3S_GPIO_MIS_MIS0_Pos                    0
#define LM3S_GPIO_MIS_MIS0_Msk                   (1UL /*<< LM3S_GPIO_MIS_MIS0_Pos*/)

/* LM3S_GPIO ICR Register Definitions */
#define LM3S_GPIO_ICR_IC7_Pos                     7
#define LM3S_GPIO_ICR_IC7_Msk                    (1UL << LM3S_GPIO_ICR_IC7_Pos)

#define LM3S_GPIO_ICR_IC6_Pos                     6
#define LM3S_GPIO_ICR_IC6_Msk                    (1UL << LM3S_GPIO_ICR_IC6_Pos)

#define LM3S_GPIO_ICR_IC5_Pos                     5
#define LM3S_GPIO_ICR_IC5_Msk                    (1UL << LM3S_GPIO_ICR_IC5_Pos)

#define LM3S_GPIO_ICR_IC4_Pos                     4
#define LM3S_GPIO_ICR_IC4_Msk                    (1UL << LM3S_GPIO_ICR_IC4_Pos)

#define LM3S_GPIO_ICR_IC3_Pos                     3
#define LM3S_GPIO_ICR_IC3_Msk                    (1UL << LM3S_GPIO_ICR_IC3_Pos)

#define LM3S_GPIO_ICR_IC2_Pos                     2
#define LM3S_GPIO_ICR_IC2_Msk                    (1UL << LM3S_GPIO_ICR_IC2_Pos)

#define LM3S_GPIO_ICR_IC1_Pos                     1
#define LM3S_GPIO_ICR_IC1_Msk                    (1UL << LM3S_GPIO_ICR_IC1_Pos)

#define LM3S_GPIO_ICR_IC0_Pos                     0
#define LM3S_GPIO_ICR_IC0_Msk                    (1UL /*<< LM3S_GPIO_ICR_IC0_Pos*/)

/* LM3S_GPIO AFSEL Register Definitions */
#define LM3S_GPIO_AFSEL_AFSEL7_Pos                7
#define LM3S_GPIO_AFSEL_AFSEL7_Msk               (1UL << LM3S_GPIO_AFSEL_AFSEL7_Pos)

#define LM3S_GPIO_AFSEL_AFSEL6_Pos                6
#define LM3S_GPIO_AFSEL_AFSEL6_Msk               (1UL << LM3S_GPIO_AFSEL_AFSEL6_Pos)

#define LM3S_GPIO_AFSEL_AFSEL5_Pos                5
#define LM3S_GPIO_AFSEL_AFSEL5_Msk               (1UL << LM3S_GPIO_AFSEL_AFSEL5_Pos)

#define LM3S_GPIO_AFSEL_AFSEL4_Pos                4
#define LM3S_GPIO_AFSEL_AFSEL4_Msk               (1UL << LM3S_GPIO_AFSEL_AFSEL4_Pos)

#define LM3S_GPIO_AFSEL_AFSEL3_Pos                3
#define LM3S_GPIO_AFSEL_AFSEL3_Msk               (1UL << LM3S_GPIO_AFSEL_AFSEL3_Pos)

#define LM3S_GPIO_AFSEL_AFSEL2_Pos                2
#define LM3S_GPIO_AFSEL_AFSEL2_Msk               (1UL << LM3S_GPIO_AFSEL_AFSEL2_Pos)

#define LM3S_GPIO_AFSEL_AFSEL1_Pos                1
#define LM3S_GPIO_AFSEL_AFSEL1_Msk               (1UL << LM3S_GPIO_AFSEL_AFSEL1_Pos)

#define LM3S_GPIO_AFSEL_AFSEL0_Pos                0
#define LM3S_GPIO_AFSEL_AFSEL0_Msk               (1UL /*<< LM3S_GPIO_AFSEL_AFSEL0_Pos*/)

/* LM3S_GPIO DR2R Register Definitions */
#define LM3S_GPIO_DR2R_DRV2_7_Pos                 7
#define LM3S_GPIO_DR2R_DRV2_7_Msk                (1UL << LM3S_GPIO_DR2R_DRV2_7_Pos)

#define LM3S_GPIO_DR2R_DRV2_6_Pos                 6
#define LM3S_GPIO_DR2R_DRV2_6_Msk                (1UL << LM3S_GPIO_DR2R_DRV2_6_Pos)

#define LM3S_GPIO_DR2R_DRV2_5_Pos                 5
#define LM3S_GPIO_DR2R_DRV2_5_Msk                (1UL << LM3S_GPIO_DR2R_DRV2_5_Pos)

#define LM3S_GPIO_DR2R_DRV2_4_Pos                 4
#define LM3S_GPIO_DR2R_DRV2_4_Msk                (1UL << LM3S_GPIO_DR2R_DRV2_4_Pos)

#define LM3S_GPIO_DR2R_DRV2_3_Pos                 3
#define LM3S_GPIO_DR2R_DRV2_3_Msk                (1UL << LM3S_GPIO_DR2R_DRV2_3_Pos)

#define LM3S_GPIO_DR2R_DRV2_2_Pos                 2
#define LM3S_GPIO_DR2R_DRV2_2_Msk                (1UL << LM3S_GPIO_DR2R_DRV2_2_Pos)

#define LM3S_GPIO_DR2R_DRV2_1_Pos                 1
#define LM3S_GPIO_DR2R_DRV2_1_Msk                (1UL << LM3S_GPIO_DR2R_DRV2_1_Pos)

#define LM3S_GPIO_DR2R_DRV2_0_Pos                 0
#define LM3S_GPIO_DR2R_DRV2_0_Msk                (1UL /*<< LM3S_GPIO_DR2R_DRV2_0_Pos*/)

/* LM3S_GPIO DR4R Register Definitions */
#define LM3S_GPIO_DR4R_DRV4_7_Pos                 7
#define LM3S_GPIO_DR4R_DRV4_7_Msk                (1UL << LM3S_GPIO_DR4R_DRV4_7_Pos)

#define LM3S_GPIO_DR4R_DRV4_6_Pos                 6
#define LM3S_GPIO_DR4R_DRV4_6_Msk                (1UL << LM3S_GPIO_DR4R_DRV4_6_Pos)

#define LM3S_GPIO_DR4R_DRV4_5_Pos                 5
#define LM3S_GPIO_DR4R_DRV4_5_Msk                (1UL << LM3S_GPIO_DR4R_DRV4_5_Pos)

#define LM3S_GPIO_DR4R_DRV4_4_Pos                 4
#define LM3S_GPIO_DR4R_DRV4_4_Msk                (1UL << LM3S_GPIO_DR4R_DRV4_4_Pos)

#define LM3S_GPIO_DR4R_DRV4_3_Pos                 3
#define LM3S_GPIO_DR4R_DRV4_3_Msk                (1UL << LM3S_GPIO_DR4R_DRV4_3_Pos)

#define LM3S_GPIO_DR4R_DRV4_2_Pos                 2
#define LM3S_GPIO_DR4R_DRV4_2_Msk                (1UL << LM3S_GPIO_DR4R_DRV4_2_Pos)

#define LM3S_GPIO_DR4R_DRV4_1_Pos                 1
#define LM3S_GPIO_DR4R_DRV4_1_Msk                (1UL << LM3S_GPIO_DR4R_DRV4_1_Pos)

#define LM3S_GPIO_DR4R_DRV4_0_Pos                 0
#define LM3S_GPIO_DR4R_DRV4_0_Msk                (1UL /*<< LM3S_GPIO_DR4R_DRV4_0_Pos*/)

/* LM3S_GPIO DR8R Register Definitions */
#define LM3S_GPIO_DR8R_DRV8_7_Pos                 7
#define LM3S_GPIO_DR8R_DRV8_7_Msk                (1UL << LM3S_GPIO_DR8R_DRV8_7_Pos)

#define LM3S_GPIO_DR8R_DRV8_6_Pos                 6
#define LM3S_GPIO_DR8R_DRV8_6_Msk                (1UL << LM3S_GPIO_DR8R_DRV8_6_Pos)

#define LM3S_GPIO_DR8R_DRV8_5_Pos                 5
#define LM3S_GPIO_DR8R_DRV8_5_Msk                (1UL << LM3S_GPIO_DR8R_DRV8_5_Pos)

#define LM3S_GPIO_DR8R_DRV8_4_Pos                 4
#define LM3S_GPIO_DR8R_DRV8_4_Msk                (1UL << LM3S_GPIO_DR8R_DRV8_4_Pos)

#define LM3S_GPIO_DR8R_DRV8_3_Pos                 3
#define LM3S_GPIO_DR8R_DRV8_3_Msk                (1UL << LM3S_GPIO_DR8R_DRV8_3_Pos)

#define LM3S_GPIO_DR8R_DRV8_2_Pos                 2
#define LM3S_GPIO_DR8R_DRV8_2_Msk                     (1UL << LM3S_GPIO_DR8R_DRV8_2_Pos)

#define LM3S_GPIO_DR8R_DRV8_1_Pos                 1
#define LM3S_GPIO_DR8R_DRV8_1_Msk                (1UL << LM3S_GPIO_DR8R_DRV8_1_Pos)

#define LM3S_GPIO_DR8R_DRV8_0_Pos                 0
#define LM3S_GPIO_DR8R_DRV8_0_Msk                (1UL /*<< LM3S_GPIO_DR8R_DRV8_0_Pos*/)

/* LM3S_GPIO ODR Register Definitions */
#define LM3S_GPIO_ODR_ODE7_Pos                    7
#define LM3S_GPIO_ODR_ODE7_Msk                   (1UL << LM3S_GPIO_ODR_ODE7_Pos)

#define LM3S_GPIO_ODR_ODE6_Pos                    6
#define LM3S_GPIO_ODR_ODE6_Msk                   (1UL << LM3S_GPIO_ODR_ODE6_Pos)

#define LM3S_GPIO_ODR_ODE5_Pos                    5
#define LM3S_GPIO_ODR_ODE5_Msk                   (1UL << LM3S_GPIO_ODR_ODE5_Pos)

#define LM3S_GPIO_ODR_ODE4_Pos                    4
#define LM3S_GPIO_ODR_ODE4_Msk                   (1UL << LM3S_GPIO_ODR_ODE4_Pos)

#define LM3S_GPIO_ODR_ODE3_Pos                    3
#define LM3S_GPIO_ODR_ODE3_Msk                   (1UL << LM3S_GPIO_ODR_ODE3_Pos)

#define LM3S_GPIO_ODR_ODE2_Pos                    2
#define LM3S_GPIO_ODR_ODE2_Msk                   (1UL << LM3S_GPIO_ODR_ODE2_Pos)

#define LM3S_GPIO_ODR_ODE1_Pos                    1
#define LM3S_GPIO_ODR_ODE1_Msk                   (1UL << LM3S_GPIO_ODR_ODE1_Pos)

#define LM3S_GPIO_ODR_ODE0_Pos                    0
#define LM3S_GPIO_ODR_ODE0_Msk                   (1UL /*<< LM3S_GPIO_ODR_ODE0_Pos*/)

/* LM3S_GPIO PUR Register Definitions */
#define LM3S_GPIO_PUR_PUE7_Pos                    7
#define LM3S_GPIO_PUR_PUE7_Msk                   (1UL << LM3S_GPIO_PUR_PUE7_Pos)

#define LM3S_GPIO_PUR_PUE6_Pos                    6
#define LM3S_GPIO_PUR_PUE6_Msk                   (1UL << LM3S_GPIO_PUR_PUE6_Pos)

#define LM3S_GPIO_PUR_PUE5_Pos                    5
#define LM3S_GPIO_PUR_PUE5_Msk                   (1UL << LM3S_GPIO_PUR_PUE5_Pos)

#define LM3S_GPIO_PUR_PUE4_Pos                    4
#define LM3S_GPIO_PUR_PUE4_Msk                   (1UL << LM3S_GPIO_PUR_PUE4_Pos)

#define LM3S_GPIO_PUR_PUE3_Pos                    3
#define LM3S_GPIO_PUR_PUE3_Msk                   (1UL << LM3S_GPIO_PUR_PUE3_Pos)

#define LM3S_GPIO_PUR_PUE2_Pos                    2
#define LM3S_GPIO_PUR_PUE2_Msk                   (1UL << LM3S_GPIO_PUR_PUE2_Pos)

#define LM3S_GPIO_PUR_PUE1_Pos                    1
#define LM3S_GPIO_PUR_PUE1_Msk                   (1UL << LM3S_GPIO_PUR_PUE1_Pos)

#define LM3S_GPIO_PUR_PUE0_Pos                    0
#define LM3S_GPIO_PUR_PUE0_Msk                   (1UL /*<< LM3S_GPIO_PUR_PUE0_Pos*/)

/* LM3S_GPIO PDR Register Definitions */
#define LM3S_GPIO_PDR_PDE7_Pos                    7
#define LM3S_GPIO_PDR_PDE7_Msk                   (1UL << LM3S_GPIO_PDR_PDE7_Pos)

#define LM3S_GPIO_PDR_PDE6_Pos                    6
#define LM3S_GPIO_PDR_PDE6_Msk                   (1UL << LM3S_GPIO_PDR_PDE6_Pos)

#define LM3S_GPIO_PDR_PDE5_Pos                    5
#define LM3S_GPIO_PDR_PDE5_Msk                   (1UL << LM3S_GPIO_PDR_PDE5_Pos)

#define LM3S_GPIO_PDR_PDE4_Pos                    4
#define LM3S_GPIO_PDR_PDE4_Msk                   (1UL << LM3S_GPIO_PDR_PDE4_Pos)

#define LM3S_GPIO_PDR_PDE3_Pos                    3
#define LM3S_GPIO_PDR_PDE3_Msk                   (1UL << LM3S_GPIO_PDR_PDE3_Pos)

#define LM3S_GPIO_PDR_PDE2_Pos                    2
#define LM3S_GPIO_PDR_PDE2_Msk                   (1UL << LM3S_GPIO_PDR_PDE2_Pos)

#define LM3S_GPIO_PDR_PDE1_Pos                    1
#define LM3S_GPIO_PDR_PDE1_Msk                   (1UL << LM3S_GPIO_PDR_PDE1_Pos)

#define LM3S_GPIO_PDR_PDE0_Pos                    0
#define LM3S_GPIO_PDR_PDE0_Msk                   (1UL /*<< LM3S_GPIO_PDR_PDE0_Pos*/)

/* LM3S_GPIO SLR Register Definitions */
#define LM3S_GPIO_SLR_SRL7_Pos                    7
#define LM3S_GPIO_SLR_SRL7_Msk                   (1UL << LM3S_GPIO_SLR_SRL7_Pos)

#define LM3S_GPIO_SLR_SRL6_Pos                    6
#define LM3S_GPIO_SLR_SRL6_Msk                   (1UL << LM3S_GPIO_SLR_SRL6_Pos)

#define LM3S_GPIO_SLR_SRL5_Pos                    5
#define LM3S_GPIO_SLR_SRL5_Msk                   (1UL << LM3S_GPIO_SLR_SRL5_Pos)

#define LM3S_GPIO_SLR_SRL4_Pos                    4
#define LM3S_GPIO_SLR_SRL4_Msk                   (1UL << LM3S_GPIO_SLR_SRL4_Pos)

#define LM3S_GPIO_SLR_SRL3_Pos                    3
#define LM3S_GPIO_SLR_SRL3_Msk                   (1UL << LM3S_GPIO_SLR_SRL3_Pos)

#define LM3S_GPIO_SLR_SRL2_Pos                    2
#define LM3S_GPIO_SLR_SRL2_Msk                   (1UL << LM3S_GPIO_SLR_SRL2_Pos)

#define LM3S_GPIO_SLR_SRL1_Pos                    1
#define LM3S_GPIO_SLR_SRL1_Msk                   (1UL << LM3S_GPIO_SLR_SRL1_Pos)

#define LM3S_GPIO_SLR_SRL0_Pos                    0
#define LM3S_GPIO_SLR_SRL0_Msk                   (1UL /*<< LM3S_GPIO_SLR_SRL0_Pos*/)

/* LM3S_GPIO DEN Register Definitions */
#define LM3S_GPIO_DEN_DEN7_Pos                    7
#define LM3S_GPIO_DEN_DEN7_Msk                   (1UL << LM3S_GPIO_DEN_DEN7_Pos)

#define LM3S_GPIO_DEN_DEN6_Pos                    6
#define LM3S_GPIO_DEN_DEN6_Msk                   (1UL << LM3S_GPIO_DEN_DEN6_Pos)

#define LM3S_GPIO_DEN_DEN5_Pos                    5
#define LM3S_GPIO_DEN_DEN5_Msk                   (1UL << LM3S_GPIO_DEN_DEN5_Pos)

#define LM3S_GPIO_DEN_DEN4_Pos                    4
#define LM3S_GPIO_DEN_DEN4_Msk                   (1UL << LM3S_GPIO_DEN_DEN4_Pos)

#define LM3S_GPIO_DEN_DEN3_Pos                    3
#define LM3S_GPIO_DEN_DEN3_Msk                   (1UL << LM3S_GPIO_DEN_DEN3_Pos)

#define LM3S_GPIO_DEN_DEN2_Pos                    2
#define LM3S_GPIO_DEN_DEN2_Msk                   (1UL << LM3S_GPIO_DEN_DEN2_Pos)

#define LM3S_GPIO_DEN_DEN1_Pos                    1
#define LM3S_GPIO_DEN_DEN1_Msk                   (1UL << LM3S_GPIO_DEN_DEN1_Pos)

#define LM3S_GPIO_DEN_DEN0_Pos                    0
#define LM3S_GPIO_DEN_DEN0_Msk                   (1UL /*<< LM3S_GPIO_DEN_DEN0_Pos*/)

/* LM3S_GPIO LOCK Register Definitions */
#define LM3S_GPIO_LOCK_Pos                        0
#define LM3S_GPIO_LOCK_Msk                       (0xFFFFFFFFUL /*<< LM3S_GPIO_LOCK_Pos*/)

/* LM3S_GPIO CR Register Definitions */
#define LM3S_GPIO_CR_CR7_Pos                      7
#define LM3S_GPIO_CR_CR7_Msk                     (1UL << LM3S_GPIO_CR_CR7_Pos)

#define LM3S_GPIO_CR_CR6_Pos                      6
#define LM3S_GPIO_CR_CR6_Msk                     (1UL << LM3S_GPIO_CR_CR6_Pos)

#define LM3S_GPIO_CR_CR5_Pos                      5
#define LM3S_GPIO_CR_CR5_Msk                     (1UL << LM3S_GPIO_CR_CR5_Pos)

#define LM3S_GPIO_CR_CR4_Pos                      4
#define LM3S_GPIO_CR_CR4_Msk                     (1UL << LM3S_GPIO_CR_CR4_Pos)

#define LM3S_GPIO_CR_CR3_Pos                      3
#define LM3S_GPIO_CR_CR3_Msk                     (1UL << LM3S_GPIO_CR_CR3_Pos)

#define LM3S_GPIO_CR_CR2_Pos                      2
#define LM3S_GPIO_CR_CR2_Msk                     (1UL << LM3S_GPIO_CR_CR2_Pos)

#define LM3S_GPIO_CR_CR1_Pos                      1
#define LM3S_GPIO_CR_CR1_Msk                     (1UL << LM3S_GPIO_CR_CR1_Pos)

#define LM3S_GPIO_CR_CR0_Pos                      0
#define LM3S_GPIO_CR_CR0_Msk                     (1UL /*<< LM3S_GPIO_CR_CR0_Pos*/)

/* LM3S_GPIO AMSEL Register Definitions */
#define LM3S_GPIO_AMSEL_GPIOAMSEL7_Pos            7
#define LM3S_GPIO_AMSEL_GPIOAMSEL7_Msk           (1UL << LM3S_GPIO_AMSEL_GPIOAMSEL7_Pos)

#define LM3S_GPIO_AMSEL_GPIOAMSEL6_Pos            6
#define LM3S_GPIO_AMSEL_GPIOAMSEL6_Msk           (1UL << LM3S_GPIO_AMSEL_GPIOAMSEL6_Pos)

#define LM3S_GPIO_AMSEL_GPIOAMSEL5_Pos            5
#define LM3S_GPIO_AMSEL_GPIOAMSEL5_Msk                (1UL << LM3S_GPIO_AMSEL_GPIOAMSEL5_Pos)

#define LM3S_GPIO_AMSEL_GPIOAMSEL4_Pos            4
#define LM3S_GPIO_AMSEL_GPIOAMSEL4_Msk           (1UL << LM3S_GPIO_AMSEL_GPIOAMSEL4_Pos)

/* LM3S_GPIO PCTL Register Definitions */
#define LM3S_GPIO_PCTL_PMC7_3_Pos                31
#define LM3S_GPIO_PCTL_PMC7_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC7_3_Pos)
#define LM3S_GPIO_PCTL_PMC7_2_Pos                30
#define LM3S_GPIO_PCTL_PMC7_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC7_2_Pos)
#define LM3S_GPIO_PCTL_PMC7_1_Pos                29
#define LM3S_GPIO_PCTL_PMC7_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC7_1_Pos)
#define LM3S_GPIO_PCTL_PMC7_0_Pos                28
#define LM3S_GPIO_PCTL_PMC7_0_Msk                (1UL << LM3S_GPIO_PCTL_PMC7_0_Pos)
#define LM3S_GPIO_PCTL_PMC7_Pos                  28
#define LM3S_GPIO_PCTL_PMC7_Msk                  (0x0000000FUL << LM3S_GPIO_PCTL_PMC7_Pos)

#define LM3S_GPIO_PCTL_PMC6_3_Pos                27
#define LM3S_GPIO_PCTL_PMC6_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC6_3_Pos)
#define LM3S_GPIO_PCTL_PMC6_2_Pos                26
#define LM3S_GPIO_PCTL_PMC6_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC6_2_Pos)
#define LM3S_GPIO_PCTL_PMC6_1_Pos                25
#define LM3S_GPIO_PCTL_PMC6_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC6_1_Pos)
#define LM3S_GPIO_PCTL_PMC6_0_Pos                24
#define LM3S_GPIO_PCTL_PMC6_0_Msk                (1UL << LM3S_GPIO_PCTL_PMC6_0_Pos)
#define LM3S_GPIO_PCTL_PMC6_Pos                  24
#define LM3S_GPIO_PCTL_PMC6_Msk                  (0x0000000FUL << LM3S_GPIO_PCTL_PMC6_Pos)

#define LM3S_GPIO_PCTL_PMC5_3_Pos                23
#define LM3S_GPIO_PCTL_PMC5_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC5_3_Pos)
#define LM3S_GPIO_PCTL_PMC5_2_Pos                22
#define LM3S_GPIO_PCTL_PMC5_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC5_2_Pos)
#define LM3S_GPIO_PCTL_PMC5_1_Pos                21
#define LM3S_GPIO_PCTL_PMC5_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC5_1_Pos)
#define LM3S_GPIO_PCTL_PMC5_0_Pos                20
#define LM3S_GPIO_PCTL_PMC5_0_Msk                (1UL << LM3S_GPIO_PCTL_PMC5_0_Pos)
#define LM3S_GPIO_PCTL_PMC5_Pos                  20
#define LM3S_GPIO_PCTL_PMC5_Msk                  (0x0000000FUL << LM3S_GPIO_PCTL_PMC5_Pos)

#define LM3S_GPIO_PCTL_PMC4_3_Pos                19
#define LM3S_GPIO_PCTL_PMC4_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC4_3_Pos)
#define LM3S_GPIO_PCTL_PMC4_2_Pos                18
#define LM3S_GPIO_PCTL_PMC4_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC4_2_Pos)
#define LM3S_GPIO_PCTL_PMC4_1_Pos                17
#define LM3S_GPIO_PCTL_PMC4_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC4_1_Pos)
#define LM3S_GPIO_PCTL_PMC4_0_Pos                16
#define LM3S_GPIO_PCTL_PMC4_0_Msk                (1UL << LM3S_GPIO_PCTL_PMC4_0_Pos)
#define LM3S_GPIO_PCTL_PMC4_Pos                  16
#define LM3S_GPIO_PCTL_PMC4_Msk                  (0x0000000FUL << LM3S_GPIO_PCTL_PMC4_Pos)

#define LM3S_GPIO_PCTL_PMC3_3_Pos                15
#define LM3S_GPIO_PCTL_PMC3_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC3_3_Pos)
#define LM3S_GPIO_PCTL_PMC3_2_Pos                14
#define LM3S_GPIO_PCTL_PMC3_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC3_2_Pos)
#define LM3S_GPIO_PCTL_PMC3_1_Pos                13
#define LM3S_GPIO_PCTL_PMC3_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC3_1_Pos)
#define LM3S_GPIO_PCTL_PMC3_0_Pos                12
#define LM3S_GPIO_PCTL_PMC3_0_Msk                (1UL << LM3S_GPIO_PCTL_PMC3_0_Pos)
#define LM3S_GPIO_PCTL_PMC3_Pos                  12
#define LM3S_GPIO_PCTL_PMC3_Msk                  (0x0000000FUL << LM3S_GPIO_PCTL_PMC3_Pos)

#define LM3S_GPIO_PCTL_PMC2_3_Pos                11
#define LM3S_GPIO_PCTL_PMC2_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC2_3_Pos)
#define LM3S_GPIO_PCTL_PMC2_2_Pos                10
#define LM3S_GPIO_PCTL_PMC2_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC2_2_Pos)
#define LM3S_GPIO_PCTL_PMC2_1_Pos                 9
#define LM3S_GPIO_PCTL_PMC2_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC2_1_Pos)
#define LM3S_GPIO_PCTL_PMC2_0_Pos                 8
#define LM3S_GPIO_PCTL_PMC2_0_Msk                (1UL << LM3S_GPIO_PCTL_PMC2_0_Pos)
#define LM3S_GPIO_PCTL_PMC2_Pos                   8
#define LM3S_GPIO_PCTL_PMC2_Msk                  (0x0000000FUL << LM3S_GPIO_PCTL_PMC2_Pos)

#define LM3S_GPIO_PCTL_PMC1_3_Pos                 7
#define LM3S_GPIO_PCTL_PMC1_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC1_3_Pos)
#define LM3S_GPIO_PCTL_PMC1_2_Pos                 6
#define LM3S_GPIO_PCTL_PMC1_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC1_2_Pos)
#define LM3S_GPIO_PCTL_PMC1_1_Pos                 5
#define LM3S_GPIO_PCTL_PMC1_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC1_1_Pos)
#define LM3S_GPIO_PCTL_PMC1_0_Pos                 4
#define LM3S_GPIO_PCTL_PMC1_0_Msk                (1UL << LM3S_GPIO_PCTL_PMC1_0_Pos)
#define LM3S_GPIO_PCTL_PMC1_Pos                   4
#define LM3S_GPIO_PCTL_PMC1_Msk                  (0x0000000FUL << LM3S_GPIO_PCTL_PMC1_Pos)

#define LM3S_GPIO_PCTL_PMC0_3_Pos                 3
#define LM3S_GPIO_PCTL_PMC0_3_Msk                (1UL << LM3S_GPIO_PCTL_PMC0_3_Pos)
#define LM3S_GPIO_PCTL_PMC0_2_Pos                 2
#define LM3S_GPIO_PCTL_PMC0_2_Msk                (1UL << LM3S_GPIO_PCTL_PMC0_2_Pos)
#define LM3S_GPIO_PCTL_PMC0_1_Pos                 1
#define LM3S_GPIO_PCTL_PMC0_1_Msk                (1UL << LM3S_GPIO_PCTL_PMC0_1_Pos)
#define LM3S_GPIO_PCTL_PMC0_0_Pos                 0
#define LM3S_GPIO_PCTL_PMC0_0_Msk                (1UL /*<< LM3S_GPIO_PCTL_PMC0_Pos*/)
#define LM3S_GPIO_PCTL_PMC0_Pos                   0
#define LM3S_GPIO_PCTL_PMC0_Msk                  (0x0000000FUL /*<< LM3S_GPIO_PCTL_PMC0_Pos*/)

/* LM3S_GPIO PID4 Register Definitions */
#define LM3S_GPIO_PID4_PID4_Pos                   0
#define LM3S_GPIO_PID4_PID4_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID4_PID4_Pos*/)

/* LM3S_GPIO PID5 Register Definitions */
#define LM3S_GPIO_PID5_PID5_Pos                   0
#define LM3S_GPIO_PID5_PID5_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID5_PID5_Pos*/)

/* LM3S_GPIO PID6 Register Definitions */
#define LM3S_GPIO_PID6_PID6_Pos                   0
#define LM3S_GPIO_PID6_PID6_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID6_PID6_Pos*/)

/* LM3S_GPIO PID7 Register Definitions */
#define LM3S_GPIO_PID7_PID7_Pos                   0
#define LM3S_GPIO_PID7_PID7_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID7_PID7_Pos*/)

/* LM3S_GPIO PID0 Register Definitions */
#define LM3S_GPIO_PID0_PID0_Pos                   0
#define LM3S_GPIO_PID0_PID0_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID0_PID0_Pos*/)

/* LM3S_GPIO PID1 Register Definitions */
#define LM3S_GPIO_PID1_PID1_Pos                   0
#define LM3S_GPIO_PID1_PID1_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID1_PID1_Pos*/)

/* LM3S_GPIO PID2 Register Definitions */
#define LM3S_GPIO_PID2_PID2_Pos                   0
#define LM3S_GPIO_PID2_PID2_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID2_PID2_Pos*/)

/* LM3S_GPIO PID3 Register Definitions */
#define LM3S_GPIO_PID3_PID3_Pos                   0
#define LM3S_GPIO_PID3_PID3_Msk                  (0x000000FFUL /*<< LM3S_GPIO_PID3_PID3_Pos*/)

/* LM3S_GPIO PCID0 Register Definitions */
#define LM3S_GPIO_PCID0_PCID0_Pos                 0
#define LM3S_GPIO_PCID0_PCID0_Msk                (0x000000FFUL /*<< LM3S_GPIO_PCID0_PCID0_Pos*/)

/* LM3S_GPIO PCID1 Register Definitions */
#define LM3S_GPIO_PCID1_PCID1_Pos                 0
#define LM3S_GPIO_PCID1_PCID1_Msk                (0x000000FFUL /*<< LM3S_GPIO_PCID1_PCID1_Pos*/)

/* LM3S_GPIO PCID2 Register Definitions */
#define LM3S_GPIO_PCID2_PCID2_Pos                 0
#define LM3S_GPIO_PCID2_PCID2_Msk                (0x000000FFUL /*<< LM3S_GPIO_PCID2_PCID2_Pos*/)

/* LM3S_GPIO PCID3 Register Definitions */
#define LM3S_GPIO_PCID3_PCID3_Pos                 0
#define LM3S_GPIO_PCID3_PCID3_Msk                (0x000000FFUL /*<< LM3S_GPIO_PCID3_PCID3_Pos*/)

/* ========================================================================= */
/* ============                       SSI                       ============ */
/* ========================================================================= */

typedef struct
{
  __IOM uint32_t  CR0;                  /* Offset: 0x000 (R/W) Control 0 Register */
  __IOM uint32_t  CR1;                  /* Offset: 0x004 (R/R) Control 1 Register */
  __IOM uint32_t  DR;                   /* Offset: 0x008 (R/W) Data Register */
  __IOM uint32_t  SR;                   /* Offset: 0x00C (R/W) Status Register */
  __IM  uint32_t  CPSR;                 /* Offset: 0x010 (R/W) Clock Prescale Register */
  __IOM uint32_t  IM;                   /* Offset: 0x014 (R/W) Interrupt Mask Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x018 (R/ ) Raw Interrupt Status Register */
  __IM  uint32_t  MIS;                  /* Offset: 0x01C (R/ ) Masked Interrupt Status Register */
  __OM  uint32_t  ICR;                  /* Offset: 0x020 ( /W) Interrupt Clear Register */
  __IOM uint32_t  DMACTL;               /* Offset: 0x024 (R/W) DMA Control Register */
  __IM  uint32_t  RESERVED[1002];       
  __IM  uint32_t  PID4;                 /* Offset: 0xFD0 (R/ ) Peripheral Identification 4 Register */
  __IM  uint32_t  PID5;                 /* Offset: 0xFD4 (R/ ) Peripheral Identification 5 Register */
  __IM  uint32_t  PID6;                 /* Offset: 0xFD8 (R/ ) Peripheral Identification 6 Register */
  __IM  uint32_t  PID7;                 /* Offset: 0xFDC (R/ ) Peripheral Identification 7 Register */
  __IM  uint32_t  PID0;                 /* Offset: 0xFE0 (R/ ) Peripheral Identification 0 Register */
  __IM  uint32_t  PID1;                 /* Offset: 0xFE4 (R/ ) Peripheral Identification 1 Register */
  __IM  uint32_t  PID2;                 /* Offset: 0xFE8 (R/ ) Peripheral Identification 2 Register */
  __IM  uint32_t  PID3;                 /* Offset: 0xFEC (R/ ) Peripheral Identification 3 Register */
  __IM  uint32_t  PCID0;                /* Offset: 0xFF0 (R/ ) PrimeCell Identification 0 Register */
  __IM  uint32_t  PCID1;                /* Offset: 0xFF4 (R/ ) PrimeCell Identification 1 Register */
  __IM  uint32_t  PCID2;                /* Offset: 0xFF8 (R/ ) PrimeCell Identification 2 Register */
  __IM  uint32_t  PCID3;                /* Offset: 0xFFC (R/ ) PrimeCell Identification 3 Register */
} LM3S_SSI_TypeDef;

/* LM3S_SSI CR0 Register Definitions */
#define LM3S_SSI_CR0_SCR_Pos                      8
#define LM3S_SSI_CR0_SCR_Msk                     (0x000000FFUL << LM3S_SSI_CR0_SCR_Pos)

#define LM3S_SSI_CR0_SPH_Pos                      7
#define LM3S_SSI_CR0_SPH_Msk                     (1UL << LM3S_SSI_CR0_SPH_Pos)

#define LM3S_SSI_CR0_SP0_Pos                      6
#define LM3S_SSI_CR0_SP0_Msk                     (1UL << LM3S_SSI_CR0_SP0_Pos)

#define LM3S_SSI_CR0_FRF_Pos                      4
#define LM3S_SSI_CR0_FRF_Msk                     (0x00000003UL << LM3S_SSI_CR0_FRF_Pos)

#define LM3S_SSI_CR0_DSS_Pos                      0
#define LM3S_SSI_CR0_DSS_Msk                     (0x0000000FUL /*<< LM3S_SSI_CR0_DSS_Pos*/)

/* LM3S_SSI CR1 Register Definitions */
#define LM3S_SSI_CR1_EOT_Pos                      4
#define LM3S_SSI_CR1_EOT_Msk                     (1UL << LM3S_SSI_CR1_EOT_Pos)

#define LM3S_SSI_CR1_SOD_Pos                      3
#define LM3S_SSI_CR1_SOD_Msk                     (1UL << LM3S_SSI_CR1_SOD_Pos)

#define LM3S_SSI_CR1_MS_Pos                       2
#define LM3S_SSI_CR1_MS_Msk                      (1UL << LM3S_SSI_CR1_MS_Pos)

#define LM3S_SSI_CR1_SSE_Pos                      1
#define LM3S_SSI_CR1_SSE_Msk                     (1UL << LM3S_SSI_CR1_SSE_Pos)

#define LM3S_SSI_CR1_LBM_Pos                      0
#define LM3S_SSI_CR1_LBM_Msk                     (1UL /*<< LM3S_SSI_CR1_LBM_Pos*/)

/* LM3S_SSI SSIDR Register Definitions */
#define LM3S_SSI_DR_DATA_Pos                      0
#define LM3S_SSI_DR_DATA_Msk                     (0x000000FFUL /*<< LM3S_SSI_SSIDR_DATA_Pos*/)

/* LM3S_SSI SSISR Register Definitions */
#define LM3S_SSI_SR_BSY_Pos                       4
#define LM3S_SSI_SR_BSY_Msk                      (1UL << LM3S_SSI_SR_BSY_Pos)

#define LM3S_SSI_SR_RFF_Pos                       3
#define LM3S_SSI_SR_RFF_Msk                      (1UL << LM3S_SSI_SR_RFF_Pos)

#define LM3S_SSI_SR_RNE_Pos                       2
#define LM3S_SSI_SR_RNE_Msk                      (1UL << LM3S_SSI_SR_RNE_Pos)

#define LM3S_SSI_SR_TNF_Pos                       1
#define LM3S_SSI_SR_TNF_Msk                      (1UL << LM3S_SSI_SR_TNF_Pos)

#define LM3S_SSI_SR_TFE_Pos                       0
#define LM3S_SSI_SR_TFE_Msk                      (1UL /*<< LM3S_SSI_SR_TFE_Pos*/)

/* LM3S_SSI SSICPSR Register Definitions */
#define LM3S_SSI_CPSR_CPSDVSR_Pos                 0
#define LM3S_SSI_CPSR_CPSDVSR_Msk                (0x000000FFUL /*<< LM3S_SSI_SSICPSR_CPSDVSR_Pos*/)

/* LM3S_SSI SSIIM Register Definitions */
#define LM3S_SSI_IM_TXIM_Pos                      3
#define LM3S_SSI_IM_TXIM_Msk                     (1UL << LM3S_SSI_SSIIM_TXIM_Pos)

#define LM3S_SSI_IM_RXIM_Pos                      2
#define LM3S_SSI_IM_RXIM_Msk                     (1UL << LM3S_SSI_SSIIM_RXIM_Pos)

#define LM3S_SSI_IM_RTIM_Pos                      1
#define LM3S_SSI_IM_RTIM_Msk                     (1UL << LM3S_SSI_SSIIM_RTIM_Pos)

#define LM3S_SSI_IM_RORIM_Pos                     0
#define LM3S_SSI_IM_RORIM_Msk                    (1UL /*<< LM3S_SSI_SSIIM_RORIM_Pos*/)

/* LM3S_SSI RIS Register Definitions */
#define LM3S_SSI_RIS_TXRIS_Pos                    3
#define LM3S_SSI_RIS_TXRIS_Msk                   (1UL << LM3S_SSI_RIS_TXRIS_Pos)

#define LM3S_SSI_RIS_RXRIS_Pos                    2
#define LM3S_SSI_RIS_RXRIS_Msk                   (1UL << LM3S_SSI_RIS_RXRIS_Pos)

#define LM3S_SSI_RIS_RTRIS_Pos                    1
#define LM3S_SSI_RIS_RTRIS_Msk                   (1UL << LM3S_SSI_RIS_RTRIS_Pos)

#define LM3S_SSI_RIS_RORRIS_Pos                   0
#define LM3S_SSI_RIS_RORRIS_Msk                  (1UL /*<< LM3S_SSI_RIS_RORRIS_Pos*/)

/* LM3S_SSI MIS Register Definitions */
#define LM3S_SSI_MIS_TXMIS_Pos                    3
#define LM3S_SSI_MIS_TXMIS_Msk                   (1UL << LM3S_SSI_MIS_TXMIS_Pos)

#define LM3S_SSI_MIS_RXMIS_Pos                    2
#define LM3S_SSI_MIS_RXMIS_Msk                   (1UL << LM3S_SSI_MIS_RXMIS_Pos)

#define LM3S_SSI_MIS_RTMIS_Pos                    1
#define LM3S_SSI_MIS_RTMIS_Msk                   (1UL << LM3S_SSI_MIS_RTMIS_Pos)

#define LM3S_SSI_MIS_RORMIS_Pos                   0
#define LM3S_SSI_MIS_RORMIS_Msk                  (1UL /*<< LM3S_SSI_MIS_RORMIS_Pos*/)

/* LM3S_SSI ICR Register Definitions */
#define LM3S_SSI_ICR_RTIC_Pos                     1
#define LM3S_SSI_ICR_RTIC_Msk                    (1UL << LM3S_SSI_ICR_RTIC_Pos)

#define LM3S_SSI_ICR_RORIC_Pos                    0
#define LM3S_SSI_ICR_RORIC_Msk                   (1UL /*<< LM3S_SSI_ICR_RORIC_Pos*/)

/* LM3S_SSI DMACTL Register Definitions */
#define LM3S_SSI_DMACTL_TXDMAE_Pos                1
#define LM3S_SSI_DMACTL_TXDMAE_Msk               (1UL << LM3S_SSI_DMACTL_TXDMAE_Pos)

#define LM3S_SSI_DMACTL_RXDMAE_Pos                0
#define LM3S_SSI_DMACTL_RXDMAE_Msk               (1UL /*<< LM3S_SSI_DMACTL_RXDMAE_Pos*/)

/* LM3S_SSI PID4 Register Definitions */
#define LM3S_SSI_PID4_PID4_Pos                    0
#define LM3S_SSI_PID4_PID4_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID4_PID4_Pos*/)

/* LM3S_SSI PID5 Register Definitions */
#define LM3S_SSI_PID5_PID5_Pos                    0
#define LM3S_SSI_PID5_PID5_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID5_PID5_Pos*/)

/* LM3S_SSI PID6 Register Definitions */
#define LM3S_SSI_PID6_PID6_Pos                    0
#define LM3S_SSI_PID6_PID6_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID6_PID6_Pos*/)

/* LM3S_SSI PID7 Register Definitions */
#define LM3S_SSI_PID7_PID7_Pos                    0
#define LM3S_SSI_PID7_PID7_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID7_PID7_Pos*/)

/* LM3S_SSI PID0 Register Definitions */
#define LM3S_SSI_PID0_PID0_Pos                    0
#define LM3S_SSI_PID0_PID0_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID0_PID0_Pos*/)

/* LM3S_SSI PID1 Register Definitions */
#define LM3S_SSI_PID1_PID1_Pos                    0
#define LM3S_SSI_PID1_PID1_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID1_PID1_Pos*/)

/* LM3S_SSI PID2 Register Definitions */
#define LM3S_SSI_PID2_PID2_Pos                    0
#define LM3S_SSI_PID2_PID2_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID2_PID2_Pos*/)

/* LM3S_SSI PID3 Register Definitions */
#define LM3S_SSI_PID3_PID3_Pos                    0
#define LM3S_SSI_PID3_PID3_Msk                   (0x000000FFUL /*<< LM3S_SSI_PID3_PID3_Pos*/)

/* LM3S_SSI PCID0 Register Definitions */
#define LM3S_SSI_PCID0_PCID0_Pos                  0
#define LM3S_SSI_PCID0_PCID0_Msk                 (0x000000FFUL /*<< LM3S_SSI_PCID0_PCID0_Pos*/)

/* LM3S_SSI PCID1 Register Definitions */
#define LM3S_SSI_PCID1_PCID1_Pos                  0
#define LM3S_SSI_PCID1_PCID1_Msk                 (0x000000FFUL /*<< LM3S_SSI_PCID1_PCID1_Pos*/)

/* LM3S_SSI PID2 Register Definitions */
#define LM3S_SSI_PCID2_PCID2_Pos                  0
#define LM3S_SSI_PCID2_PCID2_Msk                 (0x000000FFUL /*<< LM3S_SSI_PCID2_PCID2_Pos*/)

/* LM3S_SSI PCID3 Register Definitions */
#define LM3S_SSI_PCID3_PCID3_Pos                  0
#define LM3S_SSI_PCID3_PCID3_Msk                 (0x000000FFUL /*<< LM3S_SSI_PCID3_PCID3_Pos*/)

/* ========================================================================= */
/* ============                      UART                       ============ */
/* ========================================================================= */

typedef struct
{
  __IOM uint32_t  DR;                   /* Offset: 0x000 (R/W) Data Register */
    union {
  __IOM uint32_t  RSR;                  /* Offset: 0x004 (R/ ) Receive Status Register */
  __IOM uint32_t  ECR;                  /* Offset: 0x004 ( /W) Error Clear Register */
    };
  __IM  uint32_t  RESERVED0;
  __IM  uint32_t  FR;                   /* Offset: 0x018 (R/ ) Flag Register */
  __IM  uint32_t  RESERVED1[4];
  __IOM uint32_t  ILPR;                 /* Offset: 0x020 (R/W) IrDA Low-Power Register */
  __IOM uint32_t  IBDR;                 /* Offset: 0x024 (R/W) Integer Baud-Rate Divisor Register */
  __IOM uint32_t  FBRD;                 /* Offset: 0x028 (R/W) Fractional Baud-Rate Divisor Register */
  __IOM uint32_t  LCRH;                 /* Offset: 0x02C (R/W) Line Control Register */
  __IOM uint32_t  CTL;                  /* Offset: 0x030 (R/W) Control Register */
  __IOM uint32_t  IFLS;                 /* Offset: 0x034 (R/W) Interrupt Level FIFO Select Register */
  __IOM uint32_t  IM;                   /* Offset: 0x038 (R/W) Interrupt Mask Register */
  __IOM uint32_t  RIS;                  /* Offset: 0x03C (R/ ) Raw Interrupt Status Register */
  __IOM uint32_t  MIS;                  /* Offset: 0x040 (R/ ) Masked Interrupt Status Register */
  __IOM uint32_t  ICR;                  /* Offset: 0x044 ( /W) Interrupt Clear Register */
  __IOM uint32_t  DMACTL;               /* Offset: 0x048 (R/W) DMA Control Register */
  __IM  uint32_t  RESERVED2[17];
  __IOM uint32_t  LINCTL;               /* Offset: 0x090 (R/W) LIN Control Register */
  __IOM uint32_t  LSS;                  /* Offset: 0x094 (R/ ) LIN Snap Shot Register */
  __IOM uint32_t  LTIM;                 /* Offset: 0x098 (R/ ) LIN Timer Register */
  __IM  uint32_t  RESERVED3[973];
  __IM  uint32_t  PID4;                 /* Offset: 0xFD0 (R/ ) Peripheral Identification 4 Register */
  __IM  uint32_t  PID5;                 /* Offset: 0xFD4 (R/ ) Peripheral Identification 5 Register */
  __IM  uint32_t  PID6;                 /* Offset: 0xFD8 (R/ ) Peripheral Identification 6 Register */
  __IM  uint32_t  PID7;                 /* Offset: 0xFDC (R/ ) Peripheral Identification 7 Register */
  __IM  uint32_t  PID0;                 /* Offset: 0xFE0 (R/ ) Peripheral Identification 0 Register */
  __IM  uint32_t  PID1;                 /* Offset: 0xFE4 (R/ ) Peripheral Identification 1 Register */
  __IM  uint32_t  PID2;                 /* Offset: 0xFE8 (R/ ) Peripheral Identification 2 Register */
  __IM  uint32_t  PID3;                 /* Offset: 0xFEC (R/ ) Peripheral Identification 3 Register */
  __IM  uint32_t  PCID0;                /* Offset: 0xFF0 (R/ ) PrimeCell Identification 0 Register */
  __IM  uint32_t  PCID1;                /* Offset: 0xFF4 (R/ ) PrimeCell Identification 1 Register */
  __IM  uint32_t  PCID2;                /* Offset: 0xFF8 (R/ ) PrimeCell Identification 2 Register */
  __IM  uint32_t  PCID3;                /* Offset: 0xFFC (R/ ) PrimeCell Identification 3 Register */
} LM3S_UART_TypeDef;

/* LM3S_UART DR Register Definitions */
#define LM3S_UART_DR_OE_Pos                      11
#define LM3S_UART_DR_OE_Msk                      (1UL << LM3S_UART_DR_OE_Pos)

#define LM3S_UART_DR_BE_Pos                      10
#define LM3S_UART_DR_BE_Msk                      (1UL << LM3S_UART_DR_BE_Pos)

#define LM3S_UART_DR_PE_Pos                       9
#define LM3S_UART_DR_PE_Msk                      (1UL << LM3S_UART_DR_PE_Pos)

#define LM3S_UART_DR_FE_Pos                       8
#define LM3S_UART_DR_FE_Msk                      (1UL << LM3S_UART_DR_FE_Pos)

#define LM3S_UART_DR_DATA_Pos                     0
#define LM3S_UART_DR_DATA_Msk                    (0x000000FFUL /*<< LM3S_UART_DR_DATA_Pos*/)

/* LM3S_UART RSR/ECR Register Definitions */
#define LM3S_UART_RSR_OE_Pos                      3
#define LM3S_UART_RSR_OE_Msk                     (1UL << LM3S_UART_RSR_OE_Pos)

#define LM3S_UART_RSR_BE_Pos                      2
#define LM3S_UART_RSR_BE_Msk                     (1UL << LM3S_UART_RSR_BE_Pos)

#define LM3S_UART_RSR_PE_Pos                      1
#define LM3S_UART_RSR_PE_Msk                     (1UL << LM3S_UART_RSR_PE_Pos)

#define LM3S_UART_RSR_FE_Pos                      0
#define LM3S_UART_RSR_FE_Msk                     (1UL /*<< LM3S_UART_RSR_FE_Pos*/)

#define LM3S_UART_ECR_DATA_Pos                    0
#define LM3S_UART_ECR_DATA_Msk                   (0x000000FFUL /*<< LM3S_UART_ECR_DATA_Pos*/)

/* LM3S_UART FR Register Definitions */
#define LM3S_UART_FR_RI_Pos                       8
#define LM3S_UART_FR_RI_Msk                      (1UL << LM3S_UART_FR_RI_Pos)

#define LM3S_UART_FR_TXFE_Pos                     7
#define LM3S_UART_FR_TXFE_Msk                    (1UL << LM3S_UART_FR_TXFE_Pos)

#define LM3S_UART_FR_RXFF_Pos                     6
#define LM3S_UART_FR_RXFF_Msk                    (1UL << LM3S_UART_FR_RXFF_Pos)

#define LM3S_UART_FR_TXFF_Pos                     5
#define LM3S_UART_FR_TXFF_Msk                    (1UL << LM3S_UART_FR_TXFF_Pos)

#define LM3S_UART_FR_RXFE_Pos                     4
#define LM3S_UART_FR_RXFE_Msk                    (1UL << LM3S_UART_FR_RXFE_Pos)

#define LM3S_UART_FR_BUSY_Pos                     3
#define LM3S_UART_FR_BUSY_Msk                    (1UL << LM3S_UART_FR_BUSY_Pos)

#define LM3S_UART_FR_DCD_Pos                      2
#define LM3S_UART_FR_DCD_Msk                     (1UL << LM3S_UART_FR_DCD_Pos)

#define LM3S_UART_FR_DSR_Pos                      1
#define LM3S_UART_FR_DSR_Msk                     (1UL << LM3S_UART_FR_DSR_Pos)

#define LM3S_UART_FR_CTS_Pos                      0
#define LM3S_UART_FR_CTS_Msk                     (1UL /*<< LM3S_UART_FR_CTS_Pos*/)

/* LM3S_UART ILPR Register Definitions */
#define LM3S_UART_ILPR_ILPDVSR_Pos                0
#define LM3S_UART_ILPR_ILPDVSR_Msk               (0x000000FFUL /*<< LM3S_UART_ILPR_ILPDVSR_Pos*/)

/* LM3S_UART IBDR Register Definitions */
#define LM3S_UART_IBDR_DIVINT_Pos                 0
#define LM3S_UART_IBDR_DIVINT_Msk                (0x0000FFFFUL /*<< LM3S_UART_IBDR_DIVINT_Pos*/)

/* LM3S_UART FBRD Register Definitions */
#define LM3S_UART_FBRD_DIVFRAC_Pos                0
#define LM3S_UART_FBRD_DIVFRAC_Msk               (0x000000FFUL /*<< LM3S_UART_FBRD_DIVFRAC_Pos*/)

/* LM3S_UART LCRH Register Definitions */
#define LM3S_UART_LCRH_SPS_Pos                    7
#define LM3S_UART_LCRH_SPS_Msk                   (1UL << LM3S_UART_LCRH_SPS_Pos)

#define LM3S_UART_LCRH_WLEN_Pos                   5
#define LM3S_UART_LCRH_WLEN_Msk                  (0x00000003UL << LM3S_UART_LCRH_WLEN_Pos)
#define LM3S_UART_LCRH_WLEN1_Pos                  6
#define LM3S_UART_LCRH_WLEN1_Msk                 (1UL << LM3S_UART_LCRH_WLEN1_Pos)
#define LM3S_UART_LCRH_WLEN0_Pos                  5
#define LM3S_UART_LCRH_WLEN0_Msk                 (1UL << LM3S_UART_LCRH_WLEN0_Pos)

#define LM3S_UART_LCRH_FEN_Pos                    4
#define LM3S_UART_LCRH_FEN_Msk                   (1UL << LM3S_UART_LCRH_FEN_Pos)

#define LM3S_UART_LCRH_STP2_Pos                   3
#define LM3S_UART_LCRH_STP2_Msk                  (1UL << LM3S_UART_LCRH_STP2_Pos)

#define LM3S_UART_LCRH_EPS_Pos                    2
#define LM3S_UART_LCRH_EPS_Msk                   (1UL << LM3S_UART_LCRH_EPS_Pos)

#define LM3S_UART_LCRH_PEN_Pos                    1
#define LM3S_UART_LCRH_PEN_Msk                   (1UL << LM3S_UART_LCRH_PEN_Pos)

#define LM3S_UART_LCRH_BRK_Pos                    0
#define LM3S_UART_LCRH_BRK_Msk                   (1UL /*<< LM3S_UART_LCRH_BRK_Pos*/)

/* LM3S_UART CTL Register Definitions */
#define LM3S_UART_CTL_CTSEN_Pos                  15
#define LM3S_UART_CTL_CTSEN_Msk                  (1UL << LM3S_UART_CTL_CTSEN_Pos)

#define LM3S_UART_CTL_RTSEN_Pos                  14
#define LM3S_UART_CTL_RTSEN_Msk                  (1UL << LM3S_UART_CTL_RTSEN_Pos)

#define LM3S_UART_CTL_RTS_Pos                    11
#define LM3S_UART_CTL_RTS_Msk                    (1UL << LM3S_UART_CTL_RTS_Pos)

#define LM3S_UART_CTL_DTR_Pos                    10
#define LM3S_UART_CTL_DTR_Msk                    (1UL << LM3S_UART_CTL_DTR_Pos)

#define LM3S_UART_CTL_RXE_Pos                     9
#define LM3S_UART_CTL_RXE_Msk                    (1UL << LM3S_UART_CTL_RXE_Pos)

#define LM3S_UART_CTL_TXE_Pos                     8
#define LM3S_UART_CTL_TXE_Msk                    (1UL << LM3S_UART_CTL_TXE_Pos)

#define LM3S_UART_CTL_LBE_Pos                     7
#define LM3S_UART_CTL_LBE_Msk                    (1UL << LM3S_UART_CTL_LBE_Pos)

#define LM3S_UART_CTL_LIN_Pos                     6
#define LM3S_UART_CTL_LIN_Msk                    (1UL << LM3S_UART_CTL_LIN_Pos)

#define LM3S_UART_CTL_HSE_Pos                     5
#define LM3S_UART_CTL_HSE_Msk                    (1UL << LM3S_UART_CTL_HSE_Pos)

#define LM3S_UART_CTL_EOT_Pos                     4
#define LM3S_UART_CTL_EOT_Msk                    (1UL << LM3S_UART_CTL_EOT_Pos)

#define LM3S_UART_CTL_SMART_Pos                   3
#define LM3S_UART_CTL_SMART_Msk                  (1UL << LM3S_UART_CTL_SMART_Pos)

#define LM3S_UART_CTL_SIRLP_Pos                   2
#define LM3S_UART_CTL_SIRLP_Msk                  (1UL << LM3S_UART_CTL_SIRLP_Pos)

#define LM3S_UART_CTL_SIREN_Pos                   1
#define LM3S_UART_CTL_SIREN_Msk                  (1UL << LM3S_UART_CTL_SIREN_Pos)

#define LM3S_UART_CTL_UARTEN_Pos                  0
#define LM3S_UART_CTL_UARTEN_Msk                 (1UL /*<< LM3S_UART_CTL_UARTEN_Pos*/)

/* LM3S_UART IFLS Register Definitions */
#define LM3S_UART_IFLS_RXIFLSEL_Pos               3
#define LM3S_UART_IFLS_RXIFLSEL_Msk              (0x0000000FUL << LM3S_UART_IFLS_RXIFLSEL_Pos)

#define LM3S_UART_IFLS_TXIFLSEL_Pos               0
#define LM3S_UART_IFLS_TXIFLSEL_Msk              (0x0000000FUL /*<< LM3S_UART_IFLS_TXIFLSEL_Pos*/)

/* LM3S_UART IM Register Definitions */
#define LM3S_UART_IM_LME5IM_Pos                  15
#define LM3S_UART_IM_LME5IM_Msk                  (1UL << LM3S_UART_IM_LME5IM_Pos)

#define LM3S_UART_IM_LME1IM_Pos                  14
#define LM3S_UART_IM_LME1IM_Msk                  (1UL << LM3S_UART_IM_LME1IM_Pos)

#define LM3S_UART_IM_LMSBIM_Pos                  13
#define LM3S_UART_IM_LMSBIM_Msk                  (1UL << LM3S_UART_IM_LMSBIM_Pos)

#define LM3S_UART_IM_OEIM_Pos                    10
#define LM3S_UART_IM_OEIM_Msk                    (1UL << LM3S_UART_IM_OEIM_Pos)

#define LM3S_UART_IM_BEIM_Pos                     9
#define LM3S_UART_IM_BEIM_Msk                    (1UL << LM3S_UART_IM_BEIM_Pos)

#define LM3S_UART_IM_PEIM_Pos                     8
#define LM3S_UART_IM_PEIM_Msk                    (1UL << LM3S_UART_IM_PEIM_Pos)

#define LM3S_UART_IM_FEIM_Pos                     7
#define LM3S_UART_IM_FEIM_Msk                    (1UL << LM3S_UART_IM_FEIM_Pos)

#define LM3S_UART_IM_RTIM_Pos                     6
#define LM3S_UART_IM_RTIM_Msk                    (1UL << LM3S_UART_IM_RTIM_Pos)

#define LM3S_UART_IM_TXIM_Pos                     5
#define LM3S_UART_IM_TXIM_Msk                    (1UL << LM3S_UART_IM_TXIM_Pos)

#define LM3S_UART_IM_RXIM_Pos                     4
#define LM3S_UART_IM_RXIM_Msk                    (1UL << LM3S_UART_IM_RXIM_Pos)

#define LM3S_UART_IM_DSRIM_Pos                    3
#define LM3S_UART_IM_DSRIM_Msk                   (1UL << LM3S_UART_IM_DSRIM_Pos)

#define LM3S_UART_IM_DCDIM_Pos                    2
#define LM3S_UART_IM_DCDIM_Msk                   (1UL << LM3S_UART_IM_DCDIM_Pos)

#define LM3S_UART_IM_CTSIM_Pos                    1
#define LM3S_UART_IM_CTSIM_Msk                   (1UL << LM3S_UART_IM_CTSIM_Pos)

#define LM3S_UART_IM_RIIM_Pos                     0
#define LM3S_UART_IM_RIIM_Msk                    (1UL /*<< LM3S_UART_IM_RIIM_Pos*/)

/* LM3S_UART RIS Register Definitions */
#define LM3S_UART_RIS_LME5RIS_Pos                15
#define LM3S_UART_RIS_LME5RIS_Msk                (1UL << LM3S_UART_RIS_LME5RIS_Pos)

#define LM3S_UART_RIS_LME1RIS_Pos                14
#define LM3S_UART_RIS_LME1RIS_Msk                (1UL << LM3S_UART_RIS_LME1RIS_Pos)

#define LM3S_UART_RIS_LMSBRIS_Pos                13
#define LM3S_UART_RIS_LMSBRIS_Msk                (1UL << LM3S_UART_RIS_LMSBRIS_Pos)

#define LM3S_UART_RIS_OERIS_Pos                  10
#define LM3S_UART_RIS_OERIS_Msk                  (1UL << LM3S_UART_RIS_OERIS_Pos)

#define LM3S_UART_RIS_BERIS_Pos                   9
#define LM3S_UART_RIS_BERIS_Msk                  (1UL << LM3S_UART_RIS_BERIS_Pos)

#define LM3S_UART_RIS_PERIS_Pos                   8
#define LM3S_UART_RIS_PERIS_Msk                  (1UL << LM3S_UART_RIS_PERIS_Pos)

#define LM3S_UART_RIS_FERIS_Pos                   7
#define LM3S_UART_RIS_FERIS_Msk                  (1UL << LM3S_UART_RIS_FERIS_Pos)

#define LM3S_UART_RIS_RTRIS_Pos                   6
#define LM3S_UART_RIS_RTRIS_Msk                  (1UL << LM3S_UART_RIS_RTRIS_Pos)

#define LM3S_UART_RIS_TXRIS_Pos                   5
#define LM3S_UART_RIS_TXRIS_Msk                  (1UL << LM3S_UART_RIS_TXRIS_Pos)

#define LM3S_UART_RIS_RXRIS_Pos                   4
#define LM3S_UART_RIS_RXRIS_Msk                  (1UL << LM3S_UART_RIS_RXRIS_Pos)

#define LM3S_UART_RIS_DSRRIS_Pos                  3
#define LM3S_UART_RIS_DSRRIS_Msk                 (1UL << LM3S_UART_RIS_DSRRIS_Pos)

#define LM3S_UART_RIS_DCDRIS_Pos                  2
#define LM3S_UART_RIS_DCDRIS_Msk                 (1UL << LM3S_UART_RIS_DCDRIS_Pos)

#define LM3S_UART_RIS_CTSRIS_Pos                  1
#define LM3S_UART_RIS_CTSRIS_Msk                 (1UL << LM3S_UART_RIS_CTSRIS_Pos)

#define LM3S_UART_RIS_RIRIS_Pos                   0
#define LM3S_UART_RIS_RIRIS_Msk                  (1UL /*<< LM3S_UART_RIS_RIRIS_Pos*/)

/* LM3S_UART MIS Register Definitions */
#define LM3S_UART_MIS_LME5MIS_Pos                15
#define LM3S_UART_MIS_LME5MIS_Msk                (1UL << LM3S_UART_MIS_LME5MIS_Pos)

#define LM3S_UART_MIS_LME1MIS_Pos                14
#define LM3S_UART_MIS_LME1MIS_Msk                (1UL << LM3S_UART_MIS_LME1MIS_Pos)

#define LM3S_UART_MIS_LMSBMIS_Pos                13
#define LM3S_UART_MIS_LMSBMIS_Msk                (1UL << LM3S_UART_MIS_LMSBMIS_Pos)

#define LM3S_UART_MIS_OEMIS_Pos                  10
#define LM3S_UART_MIS_OEMIS_Msk                  (1UL << LM3S_UART_MIS_OEMIS_Pos)

#define LM3S_UART_MIS_BEMIS_Pos                   9
#define LM3S_UART_MIS_BEMIS_Msk                  (1UL << LM3S_UART_MIS_BEMIS_Pos)

#define LM3S_UART_MIS_PEMIS_Pos                   8
#define LM3S_UART_MIS_PEMIS_Msk                  (1UL << LM3S_UART_MIS_PEMIS_Pos)

#define LM3S_UART_MIS_FEMIS_Pos                   7
#define LM3S_UART_MIS_FEMIS_Msk                  (1UL << LM3S_UART_MIS_FEMIS_Pos)

#define LM3S_UART_MIS_RTMIS_Pos                   6
#define LM3S_UART_MIS_RTMIS_Msk                  (1UL << LM3S_UART_MIS_RTMIS_Pos)

#define LM3S_UART_MIS_TXMIS_Pos                   5
#define LM3S_UART_MIS_TXMIS_Msk                  (1UL << LM3S_UART_MIS_TXMIS_Pos)

#define LM3S_UART_MIS_RXMIS_Pos                   4
#define LM3S_UART_MIS_RXMIS_Msk                  (1UL << LM3S_UART_MIS_RXMIS_Pos)

#define LM3S_UART_MIS_DSRMIS_Pos                  3
#define LM3S_UART_MIS_DSRMIS_Msk                 (1UL << LM3S_UART_MIS_DSRMIS_Pos)

#define LM3S_UART_MIS_DCDMIS_Pos                  2
#define LM3S_UART_MIS_DCDMIS_Msk                 (1UL << LM3S_UART_MIS_DCDMIS_Pos)

#define LM3S_UART_MIS_CTSMIS_Pos                  1
#define LM3S_UART_MIS_CTSMIS_Msk                 (1UL << LM3S_UART_MIS_CTSMIS_Pos)

#define LM3S_UART_MIS_RIMIS_Pos                   0
#define LM3S_UART_MIS_RIMIS_Msk                  (1UL /*<< LM3S_UART_MIS_RIMIS_Pos*/)

/* LM3S_UART ICR Register Definitions */
#define LM3S_UART_ICR_LME5MIC_Pos                15
#define LM3S_UART_ICR_LME5MIC_Msk                (1UL << LM3S_UART_ICR_LME5MIC_Pos)

#define LM3S_UART_ICR_LME1MIC_Pos                14
#define LM3S_UART_ICR_LME1MIC_Msk                (1UL << LM3S_UART_ICR_LME1MIC_Pos)

#define LM3S_UART_ICR_LMSBMIC_Pos                13
#define LM3S_UART_ICR_LMSBMIC_Msk                (1UL << LM3S_UART_ICR_LMSBMIC_Pos)

#define LM3S_UART_ICR_OEIC_Pos                   10
#define LM3S_UART_ICR_OEIC_Msk                   (1UL << LM3S_UART_ICR_OEIC_Pos)

#define LM3S_UART_ICR_BEIC_Pos                    9
#define LM3S_UART_ICR_BEIC_Msk                   (1UL << LM3S_UART_ICR_BEIC_Pos)

#define LM3S_UART_ICR_PEIC_Pos                    8
#define LM3S_UART_ICR_PEIC_Msk                   (1UL << LM3S_UART_ICR_PEIC_Pos)

#define LM3S_UART_ICR_FEIC_Pos                    7
#define LM3S_UART_ICR_FEIC_Msk                   (1UL << LM3S_UART_ICR_FEIC_Pos)

#define LM3S_UART_ICR_RTIC_Pos                    6
#define LM3S_UART_ICR_RTIC_Msk                   (1UL << LM3S_UART_ICR_RTIC_Pos)

#define LM3S_UART_ICR_TXIC_Pos                    5
#define LM3S_UART_ICR_TXIC_Msk                   (1UL << LM3S_UART_ICR_TXIC_Pos)

#define LM3S_UART_ICR_RXIC_Pos                    4
#define LM3S_UART_ICR_RXIC_Msk                   (1UL << LM3S_UART_ICR_RXIC_Pos)

#define LM3S_UART_ICR_DSRMIC_Pos                  3
#define LM3S_UART_ICR_DSRMIC_Msk                 (1UL << LM3S_UART_ICR_DSRMIC_Pos)

#define LM3S_UART_ICR_DCDMIC_Pos                  2
#define LM3S_UART_ICR_DCDMIC_Msk                 (1UL << LM3S_UART_ICR_DCDMIC_Pos)

#define LM3S_UART_ICR_CTSMIC_Pos                  1
#define LM3S_UART_ICR_CTSMIC_Msk                 (1UL << LM3S_UART_ICR_CTSMIC_Pos)

#define LM3S_UART_ICR_RIMIC_Pos                   0
#define LM3S_UART_ICR_RIMIC_Msk                  (1UL /*<< LM3S_UART_ICR_RIMIC_Pos*/)

/* LM3S_UART DMACTL Register Definitions */
#define LM3S_UART_DMACTL_DMAERR_Pos               2
#define LM3S_UART_DMACTL_DMAERR_Msk              (1UL << LM3S_UART_DMACTL_DMAERR_Pos)

#define LM3S_UART_DMACTL_TXDMAE_Pos               1
#define LM3S_UART_DMACTL_TXDMAE_Msk              (1UL << LM3S_UART_DMACTL_TXDMAE_Pos)

#define LM3S_UART_DMACTL_RXDMAE_Pos               0
#define LM3S_UART_DMACTL_RXDMAE_Msk              (1UL /*<< LM3S_UART_DMACTL_RXDMAE_Pos*/)

/* LM3S_UART LCTL Register Definitions */
#define LM3S_UART_LCTL_BLEN_Pos                   4
#define LM3S_UART_LCTL_BLEN_Msk                  (0x00000003UL << LM3S_UART_LCTL_BLEN_Pos)
#define LM3S_UART_LCTL_BLEN1_Pos                  5
#define LM3S_UART_LCTL_BLEN1_Msk                 (1UL << LM3S_UART_LCTL_BLEN1_Pos)
#define LM3S_UART_LCTL_BLEN0_Pos                  4
#define LM3S_UART_LCTL_BLEN0_Msk                 (1UL << LM3S_UART_LCTL_BLEN0_Pos)

#define LM3S_UART_LCTL_MASTER_Pos                 0
#define LM3S_UART_LCTL_MASTER_Msk                (1UL /*<< LM3S_UART_LCTL_MASTER_Pos*/)

/* LM3S_UART LSS Register Definitions */
#define LM3S_UART_LSS_TSS_Pos                     0
#define LM3S_UART_LSS_TSS_Msk                    (0x0000FFFFUL /*<< LM3S_UART_LSS_TSS_Pos*/)

/* LM3S_UART LTIM Register Definitions */
#define LM3S_UART_LTIM_TIMER_Pos                  0
#define LM3S_UART_LTIM_TIMER_Msk                 (0x0000FFFFUL /*<< LM3S_UART_LTIM_TIMER_Pos*/)

/* LM3S_UART PID4 Register Definitions */
#define LM3S_UART_PID4_PID4_Pos                   0
#define LM3S_UART_PID4_PID4_Msk                  (0x000000FFUL /*<< LM3S_UART_PID4_PID4_Pos*/)

/* LM3S_UART PID5 Register Definitions */
#define LM3S_UART_PID5_PID5_Pos                   0
#define LM3S_UART_PID5_PID5_Msk                  (0x000000FFUL /*<< LM3S_UART_PID5_PID5_Pos*/)

/* LM3S_UART PID6 Register Definitions */
#define LM3S_UART_PID6_PID6_Pos                   0
#define LM3S_UART_PID6_PID6_Msk                  (0x000000FFUL /*<< LM3S_UART_PID6_PID6_Pos*/)

/* LM3S_UART PID7 Register Definitions */
#define LM3S_UART_PID7_PID7_Pos                   0
#define LM3S_UART_PID7_PID7_Msk                  (0x000000FFUL /*<< LM3S_UART_PID7_PID7_Pos*/)

/* LM3S_UART PID0 Register Definitions */
#define LM3S_UART_PID0_PID0_Pos                   0
#define LM3S_UART_PID0_PID0_Msk                  (0x000000FFUL /*<< LM3S_UART_PID0_PID0_Pos*/)

/* LM3S_UART PID1 Register Definitions */
#define LM3S_UART_PID1_PID1_Pos                   0
#define LM3S_UART_PID1_PID1_Msk                  (0x000000FFUL /*<< LM3S_UART_PID1_PID1_Pos*/)

/* LM3S_UART PID2 Register Definitions */
#define LM3S_UART_PID2_PID2_Pos                   0
#define LM3S_UART_PID2_PID2_Msk                  (0x000000FFUL /*<< LM3S_UART_PID2_PID2_Pos*/)

/* LM3S_UART PID3 Register Definitions */
#define LM3S_UART_PID3_PID3_Pos                   0
#define LM3S_UART_PID3_PID3_Msk                  (0x000000FFUL /*<< LM3S_UART_PID3_PID3_Pos*/)

/* LM3S_UART PCID0 Register Definitions */
#define LM3S_UART_PCID0_PCID0_Pos                 0
#define LM3S_UART_PCID0_PCID0_Msk                (0x000000FFUL /*<< LM3S_UART_PCID0_PCID0_Pos*/)

/* LM3S_UART PCID1 Register Definitions */
#define LM3S_UART_PCID1_PCID1_Pos                 0
#define LM3S_UART_PCID1_PCID1_Msk                (0x000000FFUL /*<< LM3S_UART_PCID1_PCID1_Pos*/)

/* LM3S_UART PID2 Register Definitions */
#define LM3S_UART_PCID2_PCID2_Pos                 0
#define LM3S_UART_PCID2_PCID2_Msk                (0x000000FFUL /*<< LM3S_UART_PCID2_PCID2_Pos*/)

/* LM3S_UART PCID3 Register Definitions */
#define LM3S_UART_PCID3_PCID3_Pos                 0
#define LM3S_UART_PCID3_PCID3_Msk                (0x000000FFUL /*<< LM3S_UARTI_PCID3_PCID3_Pos*/)

/* ========================================================================= */
/* ============                       I2C                       ============ */
/* ========================================================================= */

typedef struct
{
  __IOM uint32_t  MSA;                  /* Offset: 0x000 (R/W) Master Slave Address Register */
  union {
      __IM  uint32_t  MC;               /* Offset: 0x004 (R/ ) Master Control/Status Register Read-Only */
      __OM  uint32_t  MS;               /* Offset: 0x004 ( /W) Master Control/Status Register Write-Only */
  }MCS;                                 /* Offset: 0x004 (R/W) Master Control/Status Register */
  __IOM uint32_t  MDR;                  /* Offset: 0x008 (R/W) Master Data Register */
  __IOM uint32_t  MTPR;                 /* Offset: 0x00C (R/W) Master Timer Period Register */
  __IOM uint32_t  MIMR;                 /* Offset: 0x010 (R/W) Master Interrupt Mask Register */
  __IM  uint32_t  MRIS;                 /* Offset: 0x014 (R/ ) Master Raw Interrupt Status Register */
  __IM  uint32_t  MMIS;                 /* Offset: 0x018 (R/ ) Master Masked Interrupt Status Register */
  __OM  uint32_t  MICR;                 /* Offset: 0x01C ( /W) Master Interrupt Clear Register */
  __IOM uint32_t  MCR;                  /* Offset: 0x020 (R/W) Master Configuration Register */
  __IM  uint32_t  RESERVED0[194];
  __IOM uint32_t  SOAR;                 /* Offset: 0x800 (R/W) Slave Own Address Register */
  union {
      __IM  uint32_t  SCR;              /* Offset: 0x004 (R/ ) Slave Control/Status Register Read-Only */
      __OM  uint32_t  SSR;              /* Offset: 0x004 ( /W) Slave Control/Status Register Write-Only */
  }SCSR;                                /* Offset: 0x004 (R/W) Slave Control/Status Register */
  __IOM uint32_t  SDR;                  /* Offset: 0x808 (R/W) Slave Data Register */
  __IOM uint32_t  SIMR;                 /* Offset: 0x80C (R/W) Slave Interrupt Mask Register */
  __IM  uint32_t  SRIS;                 /* Offset: 0x810 (R/ ) Slave Raw Interrupt Status Register */
  __IM  uint32_t  SMIS;                 /* Offset: 0x814 (R/ ) Slave Masked Interrupt Status Register */
  __IM  uint32_t  SICR;                 /* Offset: 0x818 (R/ ) Slave Interrupt Clear Register */
} LM3S_I2C_TypeDef;

/* LM3S_I2C MSA Register Definitions */
#define LM3S_I2C_MSA_SA_Pos                       1
#define LM3S_I2C_MSA_SA_Msk                      (0x000000FFUL << LM3S_I2C_MSA_SA_Pos)

#define LM3S_I2C_MSA_RS_Pos                       0
#define LM3S_I2C_MSA_RS_Msk                      (1UL /*<< LM3S_I2C_MSA_RS_Pos*/)

/* LM3S_I2C MCS Register Definitions */
/* LM3S_I2C MS Register Definitions */
#define LM3S_I2C_MS_BUSBSY_Pos                    6
#define LM3S_I2C_MS_BUSBSY_Msk                   (1UL << LM3S_I2C_MS_BUSBSY_Pos)

#define LM3S_I2C_MS_IDLE_Pos                      5
#define LM3S_I2C_MS_IDLE_Msk                     (1UL << LM3S_I2C_MS_IDLE_Pos)

#define LM3S_I2C_MS_ARBLST_Pos                    4
#define LM3S_I2C_MS_ARBLST_Msk                   (1UL << LM3S_I2C_MS_ARBLST_Pos)

#define LM3S_I2C_MS_DATACK_Pos                    3
#define LM3S_I2C_MS_DATACK_Msk                   (1UL << LM3S_I2C_MS_DATACK_Pos)

#define LM3S_I2C_MS_ADRACK_Pos                    2
#define LM3S_I2C_MS_ADRACK_Msk                   (1UL << LM3S_I2C_MS_ADRACK_Pos)

#define LM3S_I2C_MS_ERROR_Pos                     1
#define LM3S_I2C_MS_ERROR_Msk                    (1UL << LM3S_I2C_MS_ERROR_Pos)

#define LM3S_I2C_MS_BUSY_Pos                      0
#define LM3S_I2C_MS_BUSY_Msk                     (1UL /*<< LM3S_I2C_MS_BUSY_Pos*/)
/* LM3S_I2C MC Register Definitions */
#define LM3S_I2C_MC_ACK_Pos                       3
#define LM3S_I2C_MC_ACK_Msk                      (1UL << LM3S_I2C_MC_ACK_Pos)

#define LM3S_I2C_MC_STOP_Pos                      2
#define LM3S_I2C_MC_STOP_Msk                     (1UL << LM3S_I2C_MC_STOP_Pos)

#define LM3S_I2C_MC_START_Pos                     1
#define LM3S_I2C_MC_START_Msk                    (1UL << LM3S_I2C_MC_START_Pos)

#define LM3S_I2C_MC_RUN_Pos                       0
#define LM3S_I2C_MC_RUN_Msk                      (1UL /*<< LM3S_I2C_MC_RUN_Pos*/)

/* LM3S_I2C MDR Register Definitions */
#define LM3S_I2C_MDR_DATA_Pos                     0
#define LM3S_I2C_MDR_DATA_Msk                    (0x000000FFUL /*<< LM3S_I2C_MDR_DATA_Pos*/)

/* LM3S_I2C MTPR Register Definitions */
#define LM3S_I2C_MTPR_TPR_Pos                     0
#define LM3S_I2C_MTPR_TPR_Msk                    (0x000000FFUL /*<< LM3S_I2C_MTPR_TPR_Pos*/)

/* LM3S_I2C MIMR Register Definitions */
#define LM3S_I2C_MIMR_IM_Pos                      0
#define LM3S_I2C_MIMR_IM_Msk                     (1UL /*<< LM3S_I2C_MIMR_IM_Pos*/)

/* LM3S_I2C MRIS Register Definitions */
#define LM3S_I2C_MRIS_RIS_Pos                     0
#define LM3S_I2C_MRIS_RIS_Msk                    (1UL /*<< LM3S_I2C_MRIS_RIS_Pos*/)

/* LM3S_I2C MMIS Register Definitions */
#define LM3S_I2C_MMIS_MIS_Pos                     0
#define LM3S_I2C_MMIS_MIS_Msk                    (1UL /*<< LM3S_I2C_MMIS_MIS_Pos*/)

/* LM3S_I2C MICR Register Definitions */
#define LM3S_I2C_MICR_IC_Pos                      0
#define LM3S_I2C_MICR_IC_Msk                     (1UL /*<< LM3S_I2C_MICR_IC_Pos*/)

/* LM3S_I2C MCR Register Definitions */
#define LM3S_I2C_MCR_SFE_Pos                      5
#define LM3S_I2C_MCR_SFE_Msk                     (1UL << LM3S_I2C_MCR_SFE_Pos)

#define LM3S_I2C_MCR_MFE_Pos                      4
#define LM3S_I2C_MCR_MFE_Msk                     (1UL << LM3S_I2C_MCR_MFE_Pos)

#define LM3S_I2C_MCR_LPBK_Pos                     0
#define LM3S_I2C_MCR_LPBK_Msk                    (1UL /*<< LM3S_I2C_MCR_LPBK_Pos*/)

/* LM3S_I2C SOAR Register Definitions */
#define LM3S_I2C_SOAR_OAR_Pos                     0
#define LM3S_I2C_SOAR_OAR_Msk                    (1UL /*<< LM3S_I2C_SOAR_OAR_Pos*/)

/* LM3S_I2C SCSR Register Definitions */
/* LM3S_I2C SCR Register Definitions */
#define LM3S_I2C_SSR_FBR_Pos                      2
#define LM3S_I2C_SSR_FBR_Msk                     (1UL << LM3S_I2C_SSR_FBR_Pos)

#define LM3S_I2C_SSR_TREQ_Pos                     1
#define LM3S_I2C_SSR_TREQ_Msk                    (1UL << LM3S_I2C_SSR_TREQ_Pos)

#define LM3S_I2C_SSR_RREQ_Pos                     0
#define LM3S_I2C_SSR_RREQ_Msk                    (1UL /*<< LM3S_I2C_SSR_RREQ_Pos*/)
/* LM3S_I2C MC Register Definitions */
#define LM3S_I2C_SCR_DA_Pos                       0
#define LM3S_I2C_SCR_DA_Msk                      (1UL /*<< LM3S_I2C_SCR_DA_Pos*/)

/* LM3S_I2C SDR Register Definitions */
#define LM3S_I2C_SDR_DATA_Pos                     0
#define LM3S_I2C_SDR_DATA_Msk                    (0x000000FFUL /*<< LM3S_I2C_SDR_DATA_Pos*/)

/* LM3S_I2C SIMR Register Definitions */
#define LM3S_I2C_SIMR_STOPIM_Pos                  2
#define LM3S_I2C_SIMR_STOPIM_Msk                 (1UL << LM3S_I2C_SIMR_STOPIM_Pos)

#define LM3S_I2C_SIMR_STARTIM_Pos                 1
#define LM3S_I2C_SIMR_STARTIM_Msk                (1UL << LM3S_I2C_SIMR_STARTIM_Pos)

#define LM3S_I2C_SIMR_DATAIM_Pos                  0
#define LM3S_I2C_SIMR_DATAIM_Msk                 (1UL /*<< LM3S_I2C_SIMR_DATAIM_Pos*/)

/* LM3S_I2C SRIS Register Definitions */
#define LM3S_I2C_SRIS_STOPRIS_Pos                 2
#define LM3S_I2C_SRIS_STOPRIS_Msk                (1UL << LM3S_I2C_SRIS_STOPRIS_Pos)

#define LM3S_I2C_SRIS_STARTRIS_Pos                1
#define LM3S_I2C_SRIS_STARTRIS_Msk               (1UL << LM3S_I2C_SRIS_STARTRIS_Pos)

#define LM3S_I2C_SRIS_DATARIS_Pos                 0
#define LM3S_I2C_SRIS_DATARIS_Msk                (1UL /*<< LM3S_I2C_SRIS_DATARIS_Pos*/)

/* LM3S_I2C SMIS Register Definitions */
#define LM3S_I2C_SMIS_STOPMIS_Pos                 2
#define LM3S_I2C_SMIS_STOPMIS_Msk                (1UL << LM3S_I2C_SMIS_STOPMIS_Pos)

#define LM3S_I2C_SMIS_STARTMIS_Pos                1
#define LM3S_I2C_SMIS_STARTMIS_Msk               (1UL << LM3S_I2C_SMIS_STARTMIS_Pos)

#define LM3S_I2C_SMIS_DATAMIS_Pos                 0
#define LM3S_I2C_SMIS_DATAMIS_Msk                (1UL /*<< LM3S_I2C_SMIS_DATAMIS_Pos*/)

/* LM3S_I2C SICR Register Definitions */
#define LM3S_I2C_SICR_STOPIC_Pos                  2
#define LM3S_I2C_SICR_STOPIC_Msk                 (1UL << LM3S_I2C_SMIS_STOPIC_Pos)

#define LM3S_I2C_SICR_STARTIC_Pos                 1
#define LM3S_I2C_SICR_STARTIC_Msk                (1UL << LM3S_I2C_SMIS_STARTIC_Pos)

#define LM3S_I2C_SICR_DATAIC_Pos                  0
#define LM3S_I2C_SICRS_DATAIC_Msk                (1UL /*<< LM3S_I2C_SMIS_DATAIC_Pos*/)

/* ========================================================================= */
/* ============                       PWM                       ============ */
/* ========================================================================= */

typedef struct
{
  __IOM uint32_t  CTL;                  /* Offset: 0x000 (R/W) Master Control Register */
  __IOM uint32_t  SYNC;                 /* Offset: 0x004 (R/W) Time Base Sync Register */
  __IOM uint32_t  ENABLE;               /* Offset: 0x008 (R/W) Output Enable Register */
  __IOM uint32_t  INVERT;               /* Offset: 0x00C (R/W) Output Inversion Register */
  __IOM uint32_t  FAULT;                /* Offset: 0x010 (R/W) Output Fault Register */
  __IOM uint32_t  INTEN;                /* Offset: 0x014 (R/W) Interrupt Enable Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x018 (R/ ) Raw Interrupt Status Register */
  __IOM uint32_t  ISC;                  /* Offset: 0x01C (R/W) Interrupt Status and Clear Register */
  __IM  uint32_t  STATUS;               /* Offset: 0x020 (R/ ) Status Register */
  __IOM uint32_t  FAULTVAL;             /* Offset: 0x024 (R/W) Fault Condition Value Register */
  __IOM uint32_t  ENUPD;                /* Offset: 0x028 (R/W) Fault Condition Value Register */
  __IM  uint32_t  RESERVED0[5];
  __IOM uint32_t  PWM0CTL;              /* Offset: 0x040 (R/W) PWM0 Control Register */
  __IOM uint32_t  PWM0INTEN;            /* Offset: 0x044 (R/W) PWM0 Interrupt and Trigger Enable Register */
  __IM  uint32_t  PWM0RIS;              /* Offset: 0x048 (R/ ) PWM0 Raw Interrupt Status Register */
  __IOM uint32_t  PWM0ISC;              /* Offset: 0x04C (R/W) PWM0 Interrupt Status and Clear Register */
  __IOM uint32_t  PWM0LOAD;             /* Offset: 0x050 (R/W) PWM0 Load Register */
  __IOM uint32_t  PWM0COUNT;            /* Offset: 0x054 (R/ ) PWM0 Counter Register */
  __IOM uint32_t  PWM0CMPA;             /* Offset: 0x058 (R/W) PWM0 Compare A Register */
  __IOM uint32_t  PWM0CMPB;             /* Offset: 0x05C (R/W) PWM0 Compare B Register */
  __IOM uint32_t  PWM0GENA;             /* Offset: 0x060 (R/W) PWM0 Generator A Control Register */
  __IOM uint32_t  PWM0GENB;             /* Offset: 0x064 (R/W) PWM0 Generator B Control Register */
  __IOM uint32_t  PWM0DBCTL;            /* Offset: 0x068 (R/W) PWM0 Dead-Band Control Register */
  __IOM uint32_t  PWM0DBRISE;           /* Offset: 0x06C (R/W) PWM0 Dead-Band Rising-Edge Delay Register */
  __IOM uint32_t  PWM0DBFALL;           /* Offset: 0x070 (R/W) PWM0 Dead-Band Falling-Edge-Delay Register */
  __IOM uint32_t  PWM0FLTSRC0;          /* Offset: 0x074 (R/W) PWM0 Fault Source 0 Register */
  __IOM uint32_t  PWM0FLTSRC1;          /* Offset: 0x078 (R/W) PWM0 Fault Source 1 Register */
  __IOM uint32_t  PWM0MINFLTPER;        /* Offset: 0x07C (R/W) PWM0 Minimum Fault Period Register */
  __IOM uint32_t  PWM1CTL;              /* Offset: 0x080 (R/W) PWM1 Control Register */
  __IOM uint32_t  PWM1INTEN;            /* Offset: 0x084 (R/W) PWM1 Interrupt and Trigger Enable Register */
  __IM  uint32_t  PWM1RIS;              /* Offset: 0x088 (R/ ) PWM1 Raw Interrupt Status Register */
  __IOM uint32_t  PWM1ISC;              /* Offset: 0x08C (R/W) PWM1 Interrupt Status and Clear Register */
  __IOM uint32_t  PWM1LOAD;             /* Offset: 0x090 (R/W) PWM1 Load Register */
  __IOM uint32_t  PWM1COUNT;            /* Offset: 0x094 (R/ ) PWM1 Counter Register */
  __IOM uint32_t  PWM1CMPA;             /* Offset: 0x098 (R/W) PWM1 Compare A Register */
  __IOM uint32_t  PWM1CMPB;             /* Offset: 0x09C (R/W) PWM1 Compare B Register */
  __IOM uint32_t  PWM1GENA;             /* Offset: 0x0A0 (R/W) PWM1 Generator A Control Register */
  __IOM uint32_t  PWM1GENB;             /* Offset: 0x0A4 (R/W) PWM1 Generator B Control Register */
  __IOM uint32_t  PWM1DBCTL;            /* Offset: 0x0A8 (R/W) PWM1 Dead-Band Control Register */
  __IOM uint32_t  PWM1DBRISE;           /* Offset: 0x0AC (R/W) PWM1 Dead-Band Rising-Edge Delay Register */
  __IOM uint32_t  PWM1DBFALL;           /* Offset: 0x0B0 (R/W) PWM1 Dead-Band Falling-Edge-Delay Register */
  __IOM uint32_t  PWM1FLTSRC0;          /* Offset: 0x0B4 (R/W) PWM1 Fault Source 0 Register */
  __IOM uint32_t  PWM1FLTSRC1;          /* Offset: 0x0B8 (R/W) PWM1 Fault Source 1 Register */
  __IOM uint32_t  PWM1MINFLTPER;        /* Offset: 0x0BC (R/W) PWM1 Minimum Fault Period Register */
  __IOM uint32_t  PWM2CTL;              /* Offset: 0x0C0 (R/W) PWM2 Control Register */
  __IOM uint32_t  PWM2INTEN;            /* Offset: 0x0C4 (R/W) PWM2 Interrupt and Trigger Enable Register */
  __IM  uint32_t  PWM2RIS;              /* Offset: 0x0C8 (R/ ) PWM2 Raw Interrupt Status Register */
  __IOM uint32_t  PWM2ISC;              /* Offset: 0x0CC (R/W) PWM2 Interrupt Status and Clear Register */
  __IOM uint32_t  PWM2LOAD;             /* Offset: 0x0D0 (R/W) PWM2 Load Register */
  __IOM uint32_t  PWM2COUNT;            /* Offset: 0x0D4 (R/ ) PWM2 Counter Register */
  __IOM uint32_t  PWM2CMPA;             /* Offset: 0x0D8 (R/W) PWM2 Compare A Register */
  __IOM uint32_t  PWM2CMPB;             /* Offset: 0x0DC (R/W) PWM2 Compare B Register */
  __IOM uint32_t  PWM2GENA;             /* Offset: 0x0E0 (R/W) PWM2 Generator A Control Register */
  __IOM uint32_t  PWM2GENB;             /* Offset: 0x0E4 (R/W) PWM2 Generator B Control Register */
  __IOM uint32_t  PWM2DBCTL;            /* Offset: 0x0E8 (R/W) PWM2 Dead-Band Control Register */
  __IOM uint32_t  PWM2DBRISE;           /* Offset: 0x0EC (R/W) PWM2 Dead-Band Rising-Edge Delay Register */
  __IOM uint32_t  PWM2DBFALL;           /* Offset: 0x0F0 (R/W) PWM2 Dead-Band Falling-Edge-Delay Register */
  __IOM uint32_t  PWM2FLTSRC0;          /* Offset: 0x0F4 (R/W) PWM2 Fault Source 0 Register */
  __IOM uint32_t  PWM2FLTSRC1;          /* Offset: 0x0F8 (R/W) PWM2 Fault Source 1 Register */
  __IOM uint32_t  PWM2MINFLTPER;        /* Offset: 0x0FC (R/W) PWM2 Minimum Fault Period Register */
  __IOM uint32_t  PWM3CTL;              /* Offset: 0x100 (R/W) PWM3 Control Register */
  __IOM uint32_t  PWM3INTEN;            /* Offset: 0x104 (R/W) PWM3 Interrupt and Trigger Enable Register */
  __IM  uint32_t  PWM3RIS;              /* Offset: 0x108 (R/ ) PWM3 Raw Interrupt Status Register */
  __IOM uint32_t  PWM3ISC;              /* Offset: 0x10C (R/W) PWM3 Interrupt Status and Clear Register */
  __IOM uint32_t  PWM3LOAD;             /* Offset: 0x110 (R/W) PWM3 Load Register */
  __IOM uint32_t  PWM3COUNT;            /* Offset: 0x114 (R/ ) PWM3 Counter Register */
  __IOM uint32_t  PWM3CMPA;             /* Offset: 0x118 (R/W) PWM3 Compare A Register */
  __IOM uint32_t  PWM3CMPB;             /* Offset: 0x11C (R/W) PWM3 Compare B Register */
  __IOM uint32_t  PWM3GENA;             /* Offset: 0x120 (R/W) PWM3 Generator A Control Register */
  __IOM uint32_t  PWM3GENB;             /* Offset: 0x124 (R/W) PWM3 Generator B Control Register */
  __IOM uint32_t  PWM3DBCTL;            /* Offset: 0x128 (R/W) PWM3 Dead-Band Control Register */
  __IOM uint32_t  PWM3DBRISE;           /* Offset: 0x12C (R/W) PWM3 Dead-Band Rising-Edge Delay Register */
  __IOM uint32_t  PWM3DBFALL;           /* Offset: 0x130 (R/W) PWM3 Dead-Band Falling-Edge-Delay Register */
  __IOM uint32_t  PWM3FLTSRC0;          /* Offset: 0x134 (R/W) PWM3 Fault Source 0 Register */
  __IOM uint32_t  PWM3FLTSRC1;          /* Offset: 0x138 (R/W) PWM3 Fault Source 1 Register */
  __IOM uint32_t  PWM3MINFLTPER;        /* Offset: 0x13C (R/W) PWM3 Minimum Fault Period Register */
  __IM  uint32_t  RESERVED1[432];
  __IOM uint32_t  PWM0FLTSEN;           /* Offset: 0x800 (R/W) PWM0 Fault Pin Logic Sense Register */
        uint32_t  PWM0FLTSTAT0;         /* Offset: 0x804 (R/W) PWM0 Fault Status 0 Register */
        uint32_t  PWM0FLTSTAT1;         /* Offset: 0x808 (R/W) PWM0 Fault Status 1 Period Register */
  __IM  uint32_t  RESERVED2[29];
  __IOM uint32_t  PWM1FLTSEN;           /* Offset: 0x880 (R/W) PWM1 Fault Pin Logic Sense Register */
        uint32_t  PWM1FLTSTAT0;         /* Offset: 0x884 (R/W) PWM1 Fault Status 0 Register */
        uint32_t  PWM1FLTSTAT1;         /* Offset: 0x888 (R/W) PWM1 Fault Status 1 Period Register */
  __IM  uint32_t  RESERVED3[29];
  __IOM uint32_t  PWM2FLTSEN;           /* Offset: 0x900 (R/W) PWM2 Fault Pin Logic Sense Register */
        uint32_t  PWM2FLTSTAT0;         /* Offset: 0x904 (R/W) PWM2 Fault Status 0 Register */
        uint32_t  PWM2FLTSTAT1;         /* Offset: 0x908 (R/W) PWM2 Fault Status 1 Period Register */
  __IM  uint32_t  RESERVED4[29];
  __IOM uint32_t  PWM3FLTSEN;           /* Offset: 0x980 (R/W) PWM3 Fault Pin Logic Sense Register */
        uint32_t  PWM3FLTSTAT0;         /* Offset: 0x984 ( / ) PWM3 Fault Status 0 Register */
        uint32_t  PWM3FLTSTAT1;         /* Offset: 0x988 ( / ) PWM3 Fault Status 1 Period Register */
} LM3S_PWM_TypeDef;

/* LM3S_PWM CTL Register Definitions */
#define LM3S_PWM_CTL_GLOBALSYNC3_Pos              3
#define LM3S_PWM_CTL_GLOBALSYNC3_Msk             (1UL << LM3S_PWM_CTL_GLOBALSYNC3_Pos)

#define LM3S_PWM_CTL_GLOBALSYNC2_Pos              2
#define LM3S_PWM_CTL_GLOBALSYNC2_Msk             (1UL << LM3S_PWM_CTL_GLOBALSYNC2_Pos)

#define LM3S_PWM_CTL_GLOBALSYNC1_Pos              1
#define LM3S_PWM_CTL_GLOBALSYNC1_Msk             (1UL << LM3S_PWM_CTL_GLOBALSYNC1_Pos)

#define LM3S_PWM_CTL_GLOBALSYNC0_Pos              0
#define LM3S_PWM_CTL_GLOBALSYNC0_Msk             (1UL /*<< LM3S_PWM_CTL_GLOBALSYNC0_Pos*/)

/* LM3S_PWM SYNC Register Definitions */
#define LM3S_PWM_SYNC_SYNC3_Pos                   3
#define LM3S_PWM_SYNC_SYNC3_Msk                  (1UL << LM3S_PWM_SYNC_SYNC3_Pos)

#define LM3S_PWM_SYNC_SYNC2_Pos                   2
#define LM3S_PWM_SYNC_SYNC2_Msk                  (1UL << LM3S_PWM_SYNC_SYNC2_Pos)

#define LM3S_PWM_SYNC_SYNC1_Pos                   1
#define LM3S_PWM_SYNC_SYNC1_Msk                  (1UL << LM3S_PWM_SYNC_SYNC1_Pos)

#define LM3S_PWM_SYNC_SYNC0_Pos                   0
#define LM3S_PWM_SYNC_SYNC0_Msk                  (1UL /*<< LM3S_PWM_SYNC_SYNC3_Pos*/)

/* LM3S_PWM ENABLE Register Definitions */
#define LM3S_PWM_ENABLE_PWM7EN_Pos                7
#define LM3S_PWM_ENABLE_PWM7EN_Msk               (1UL << LM3S_PWM_ENABLE_PWM7EN_Pos)

#define LM3S_PWM_ENABLE_PWM6EN_Pos                6
#define LM3S_PWM_ENABLE_PWM6EN_Msk               (1UL << LM3S_PWM_ENABLE_PWM6EN_Pos)

#define LM3S_PWM_ENABLE_PWM5EN_Pos                5
#define LM3S_PWM_ENABLE_PWM5EN_Msk               (1UL << LM3S_PWM_ENABLE_PWM5EN_Pos)

#define LM3S_PWM_ENABLE_PWM4EN_Pos                4
#define LM3S_PWM_ENABLE_PWM4EN_Msk               (1UL << LM3S_PWM_ENABLE_PWM4EN_Pos)

#define LM3S_PWM_ENABLE_PWM3EN_Pos                3
#define LM3S_PWM_ENABLE_PWM3EN_Msk               (1UL << LM3S_PWM_ENABLE_PWM3EN_Pos)

#define LM3S_PWM_ENABLE_PWM2EN_Pos                2
#define LM3S_PWM_ENABLE_PWM2EN_Msk               (1UL << LM3S_PWM_ENABLE_PWM2EN_Pos)

#define LM3S_PWM_ENABLE_PWM1EN_Pos                1
#define LM3S_PWM_ENABLE_PWM1EN_Msk               (1UL << LM3S_PWM_ENABLE_PWM1EN_Pos)

#define LM3S_PWM_ENABLE_PWM0EN_Pos                0
#define LM3S_PWM_ENABLE_PWM0EN_Msk               (1UL /*<< LM3S_PWM_ENABLE_PWM0EN_Pos*/)

/* LM3S_PWM INVERT Register Definitions */
#define LM3S_PWM_INVERT_PWM7INV_Pos               7
#define LM3S_PWM_INVERT_PWM7INV_Msk              (1UL << LM3S_PWM_INVERT_PWM7INV_Pos)

#define LM3S_PWM_INVERT_PWM6INV_Pos               6
#define LM3S_PWM_INVERT_PWM6INV_Msk              (1UL << LM3S_PWM_INVERT_PWM6INV_Pos)

#define LM3S_PWM_INVERT_PWM5INV_Pos               5
#define LM3S_PWM_INVERT_PWM5INV_Msk              (1UL << LM3S_PWM_INVERT_PWM5INV_Pos)

#define LM3S_PWM_INVERT_PWM4INV_Pos               4
#define LM3S_PWM_INVERT_PWM4INV_Msk              (1UL << LM3S_PWM_INVERT_PWM4INV_Pos)

#define LM3S_PWM_INVERT_PWM3INV_Pos               3
#define LM3S_PWM_INVERT_PWM3INV_Msk              (1UL << LM3S_PWM_INVERT_PWM3INV_Pos)

#define LM3S_PWM_INVERT_PWM2INV_Pos               2
#define LM3S_PWM_INVERT_PWM2INV_Msk              (1UL << LM3S_PWM_INVERT_PWM2INV_Pos)

#define LM3S_PWM_INVERT_PWM1INV_Pos               1
#define LM3S_PWM_INVERT_PWM1INV_Msk              (1UL << LM3S_PWM_INVERT_PWM1INV_Pos)

#define LM3S_PWM_INVERT_PWM0INV_Pos               0
#define LM3S_PWM_INVERT_PWM0INV_Msk              (1UL /*<< LM3S_PWM_INVERT_PWM0INV_Pos*/)

/* LM3S_PWM FAULT Register Definitions */
#define LM3S_PWM_FAULT_FAULT7_Pos                 7
#define LM3S_PWM_FAULT_FAULT7_Msk                (1UL << LM3S_PWM_FAULT_FAULT7_Pos)

#define LM3S_PWM_FAULT_FAULT6_Pos                 6
#define LM3S_PWM_FAULT_FAULT6_Msk                (1UL << LM3S_PWM_FAULT_FAULT6_Pos)

#define LM3S_PWM_FAULT_FAULT5_Pos                 5
#define LM3S_PWM_FAULT_FAULT5_Msk                (1UL << LM3S_PWM_FAULT_FAULT5_Pos)

#define LM3S_PWM_FAULT_FAULT4_Pos                 4
#define LM3S_PWM_FAULT_FAULT4_Msk                (1UL << LM3S_PWM_FAULT_FAULT4_Pos)

#define LM3S_PWM_FAULT_FAULT3_Pos                 3
#define LM3S_PWM_FAULT_FAULT3_Msk                (1UL << LM3S_PWM_FAULT_FAULT3_Pos)

#define LM3S_PWM_FAULT_FAULT2_Pos                 2
#define LM3S_PWM_FAULT_FAULT2_Msk                (1UL << LM3S_PWM_FAULT_FAULT2_Pos)

#define LM3S_PWM_FAULT_FAULT1_Pos                 1
#define LM3S_PWM_FAULT_FAULT1_Msk                (1UL << LM3S_PWM_FAULT_FAULT1_Pos)

#define LM3S_PWM_FAULT_FAULT0_Pos                 0
#define LM3S_PWM_FAULT_FAULT0_Msk                (1UL /*<< LM3S_PWM_FAULT_FAULT0_Pos*/)

/* LM3S_PWM INTEN Register Definitions */
#define LM3S_PWM_INTEN_INTFAULT3_Pos              7
#define LM3S_PWM_INTEN_INTFAULT3_Msk             (1UL << LM3S_PWM_INTEN_INTFAULT3_Pos)

#define LM3S_PWM_INTEN_INTFAULT2_Pos              6
#define LM3S_PWM_INTEN_INTFAULT2_Msk             (1UL << LM3S_PWM_INTEN_INTFAULT2_Pos)

#define LM3S_PWM_INTEN_INTFAULT1_Pos              5
#define LM3S_PWM_INTEN_INTFAULT1_Msk             (1UL << LM3S_PWM_INTEN_INTFAULT1_Pos)

#define LM3S_PWM_INTEN_INTFAULT0_Pos              4
#define LM3S_PWM_INTEN_INTFAULT0_Msk             (1UL << LM3S_PWM_INTEN_INTFAULT0_Pos)

#define LM3S_PWM_INTEN_INTPWM3_Pos                3
#define LM3S_PWM_INTEN_INTPWM3_Msk               (1UL << LM3S_PWM_INTEN_INTPWM3_Pos)

#define LM3S_PWM_INTEN_INTPWM2_Pos                2
#define LM3S_PWM_INTEN_INTPWM2_Msk               (1UL << LM3S_PWM_INTEN_INTPWM2_Pos)

#define LM3S_PWM_INTEN_INTPWM1_Pos                1
#define LM3S_PWM_INTEN_INTPWM1_Msk               (1UL << LM3S_PWM_INTEN_INTPWM1_Pos)

#define LM3S_PWM_INTEN_INTPWM0_Pos                0
#define LM3S_PWM_INTEN_INTPWM0_Msk               (1UL /*<< LM3S_PWM_INTEN_INTPWM0_Pos*/)

/* LM3S_PWM RIS Register Definitions */
#define LM3S_PWM_RIS_INTFAULT3_Pos                7
#define LM3S_PWM_RIS_INTFAULT3_Msk               (1UL << LM3S_PWM_RIS_INTFAULT3_Pos)

#define LM3S_PWM_RIS_INTFAULT2_Pos                6
#define LM3S_PWM_RIS_INTFAULT2_Msk               (1UL << LM3S_PWM_RIS_INTFAULT2_Pos)

#define LM3S_PWM_RIS_INTFAULT1_Pos                5
#define LM3S_PWM_RIS_INTFAULT1_Msk               (1UL << LM3S_PWM_RIS_INTFAULT1_Pos)

#define LM3S_PWM_RIS_INTFAULT0_Pos                4
#define LM3S_PWM_RIS_INTFAULT0_Msk               (1UL << LM3S_PWM_RIS_INTFAULT0_Pos)

#define LM3S_PWM_RIS_INTPWM3_Pos                  3
#define LM3S_PWM_RIS_INTPWM3_Msk                 (1UL << LM3S_PWM_RIS_INTPWM3_Pos)

#define LM3S_PWM_RIS_INTPWM2_Pos                  2
#define LM3S_PWM_RIS_INTPWM2_Msk                 (1UL << LM3S_PWM_RIS_INTPWM2_Pos)

#define LM3S_PWM_RIS_INTPWM1_Pos                  1
#define LM3S_PWM_RIS_INTPWM1_Msk                 (1UL << LM3S_PWM_RIS_INTPWM1_Pos)

#define LM3S_PWM_RIS_INTPWM0_Pos                  0
#define LM3S_PWM_RIS_INTPWM0_Msk                 (1UL /*<< LM3S_PWM_RIS_INTPWM0_Pos*/)

/* LM3S_PWM ISC Register Definitions */
#define LM3S_PWM_ISC_INTFAULT3_Pos                7
#define LM3S_PWM_ISC_INTFAULT3_Msk               (1UL << LM3S_PWM_ISC_INTFAULT3_Pos)

#define LM3S_PWM_ISC_INTFAULT2_Pos                6
#define LM3S_PWM_ISC_INTFAULT2_Msk               (1UL << LM3S_PWM_ISC_INTFAULT2_Pos)

#define LM3S_PWM_ISC_INTFAULT1_Pos                5
#define LM3S_PWM_ISC_INTFAULT1_Msk               (1UL << LM3S_PWM_ISC_INTFAULT1_Pos)

#define LM3S_PWM_ISC_INTFAULT0_Pos                4
#define LM3S_PWM_ISC_INTFAULT0_Msk               (1UL << LM3S_PWM_ISC_INTFAULT0_Pos)

#define LM3S_PWM_ISC_INTPWM3_Pos                  3
#define LM3S_PWM_ISC_INTPWM3_Msk                 (1UL << LM3S_PWM_ISC_INTPWM3_Pos)

#define LM3S_PWM_ISC_INTPWM2_Pos                  2
#define LM3S_PWM_ISC_INTPWM2_Msk                 (1UL << LM3S_PWM_ISC_INTPWM2_Pos)

#define LM3S_PWM_ISC_INTPWM1_Pos                  1
#define LM3S_PWM_ISC_INTPWM1_Msk                 (1UL << LM3S_PWM_ISC_INTPWM1_Pos)

#define LM3S_PWM_ISC_INTPWM0_Pos                  0
#define LM3S_PWM_ISC_INTPWM0_Msk                 (1UL /*<< LM3S_PWM_ISC_INTPWM0_Pos*/)

/* LM3S_PWM STATUS Register Definitions */
#define LM3S_PWM_STATUS_FAULT3_Pos                3
#define LM3S_PWM_STATUS_FAULT3_Msk               (1UL << LM3S_PWM_STATUS_FAULT3_Pos)

#define LM3S_PWM_STATUS_FAULT2_Pos                2
#define LM3S_PWM_STATUS_FAULT2_Msk               (1UL << LM3S_PWM_STATUS_FAULT2_Pos)

#define LM3S_PWM_STATUS_FAULT1_Pos                1
#define LM3S_PWM_STATUS_FAULT1_Msk               (1UL << LM3S_PWM_STATUS_FAULT1_Pos)

#define LM3S_PWM_STATUS_FAULT0_Pos                0
#define LM3S_PWM_STATUS_FAULT0_Msk               (1UL /*<< LM3S_PWM_STATUS_FAULT0_Pos*/)

/* LM3S_PWM FAULTVAL Register Definitions */
#define LM3S_PWM_FAULTVAL_PWM7_Pos                7
#define LM3S_PWM_FAULTVAL_PWM7_Msk               (1UL << LM3S_PWM_FAULTVAL_PWM7_Pos)

#define LM3S_PWM_FAULTVAL_PWM6_Pos                6
#define LM3S_PWM_FAULTVAL_PWM6_Msk               (1UL << LM3S_PWM_FAULTVAL_PWM6_Pos)

#define LM3S_PWM_FAULTVAL_PWM5_Pos                5
#define LM3S_PWM_FAULTVAL_PWM5_Msk               (1UL << LM3S_PWM_FAULTVAL_PWM5_Pos)

#define LM3S_PWM_FAULTVAL_PWM4_Pos                4
#define LM3S_PWM_FAULTVAL_PWM4_Msk               (1UL << LM3S_PWM_FAULTVAL_PWM4_Pos)

#define LM3S_PWM_FAULTVAL_PWM3_Pos                3
#define LM3S_PWM_FAULTVAL_PWM3_Msk               (1UL << LM3S_PWM_FAULTVAL_PWM3_Pos)

#define LM3S_PWM_FAULTVAL_PWM2_Pos                2
#define LM3S_PWM_FAULTVAL_PWM2_Msk               (1UL << LM3S_PWM_FAULTVAL_PWM2_Pos)

#define LM3S_PWM_FAULTVAL_PWM1_Pos                1
#define LM3S_PWM_FAULTVAL_PWM1_Msk               (1UL << LM3S_PWM_FAULTVAL_PWM1_Pos)

#define LM3S_PWM_FAULTVAL_PWM0_Pos                0
#define LM3S_PWM_FAULTVAL_PWM0_Msk               (1UL /*<< LM3S_PWM_FAULTVAL_PWM0_Pos*/)

/* LM3S_PWM ENUPD Register Definitions */
#define LM3S_PWM_ENUPD_ENUPD7_Pos                14
#define LM3S_PWM_ENUPD_ENUPD7_Msk                (0x00000003UL << LM3S_PWM_ENUPD_ENUPD7_Pos)
#define LM3S_PWM_ENUPD_ENUPD7_1_Pos              15
#define LM3S_PWM_ENUPD_ENUPD7_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD7_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD7_0_Pos              14
#define LM3S_PWM_ENUPD_ENUPD7_0_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD7_0_Pos)

#define LM3S_PWM_ENUPD_ENUPD6_Pos                12
#define LM3S_PWM_ENUPD_ENUPD6_Msk                (0x00000003UL << LM3S_PWM_ENUPD_ENUPD6_Pos)
#define LM3S_PWM_ENUPD_ENUPD6_1_Pos              13
#define LM3S_PWM_ENUPD_ENUPD6_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD6_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD6_0_Pos              12
#define LM3S_PWM_ENUPD_ENUPD6_0_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD6_0_Pos)

#define LM3S_PWM_ENUPD_ENUPD5_Pos                10
#define LM3S_PWM_ENUPD_ENUPD5_Msk                (0x00000003UL << LM3S_PWM_ENUPD_ENUPD5_Pos)
#define LM3S_PWM_ENUPD_ENUPD5_1_Pos              11
#define LM3S_PWM_ENUPD_ENUPD5_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD5_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD5_0_Pos              10
#define LM3S_PWM_ENUPD_ENUPD5_0_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD5_0_Pos)

#define LM3S_PWM_ENUPD_ENUPD4_Pos                 8
#define LM3S_PWM_ENUPD_ENUPD4_Msk                (0x00000003UL << LM3S_PWM_ENUPD_ENUPD4_Pos)
#define LM3S_PWM_ENUPD_ENUPD4_1_Pos               9
#define LM3S_PWM_ENUPD_ENUPD4_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD4_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD4_0_Pos               8
#define LM3S_PWM_ENUPD_ENUPD4_0_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD4_0_Pos)

#define LM3S_PWM_ENUPD_ENUPD3_Pos                 6
#define LM3S_PWM_ENUPD_ENUPD3_Msk                (0x00000003UL << LM3S_PWM_ENUPD_ENUPD3_Pos)
#define LM3S_PWM_ENUPD_ENUPD3_1_Pos               7
#define LM3S_PWM_ENUPD_ENUPD3_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD3_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD3_0_Pos               6
#define LM3S_PWM_ENUPD_ENUPD3_0_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD3_0_Pos)

#define LM3S_PWM_ENUPD_ENUPD2_Pos                 4
#define LM3S_PWM_ENUPD_ENUPD2_Msk                (0x00000003UL << LM3S_PWM_ENUPD_ENUPD2_Pos)
#define LM3S_PWM_ENUPD_ENUPD2_1_Pos               5
#define LM3S_PWM_ENUPD_ENUPD2_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD2_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD2_0_Pos               4
#define LM3S_PWM_ENUPD_ENUPD2_0_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD2_0_Pos)

#define LM3S_PWM_ENUPD_ENUPD1_Pos                 2
#define LM3S_PWM_ENUPD_ENUPD1_Msk                (0x00000003UL << LM3S_PWM_ENUPD_ENUPD1_Pos)
#define LM3S_PWM_ENUPD_ENUPD1_1_Pos               3
#define LM3S_PWM_ENUPD_ENUPD1_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD1_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD1_0_Pos               2
#define LM3S_PWM_ENUPD_ENUPD1_0_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD1_0_Pos)

#define LM3S_PWM_ENUPD_ENUPD0_Pos                 0
#define LM3S_PWM_ENUPD_ENUPD0_Msk                (0x00000003UL /*<< LM3S_PWM_ENUPD_ENUPD0_Pos*/)
#define LM3S_PWM_ENUPD_ENUPD0_1_Pos               1
#define LM3S_PWM_ENUPD_ENUPD0_1_Msk              (1UL << LM3S_PWM_ENUPD_ENUPD0_1_Pos)
#define LM3S_PWM_ENUPD_ENUPD0_0_Pos               0
#define LM3S_PWM_ENUPD_ENUPD0_0_Msk              (1UL /*<< LM3S_PWM_ENUPD_ENUPD0_0_Pos*/)

/* LM3S_PWM PWMNCTL Register Definitions */
#define LM3S_PWM_PWMNCTL_LATCH_Pos               18
#define LM3S_PWM_PWMNCTL_LATCH_Msk               (1UL << LM3S_PWM_PWMNCTL_LATCH_Pos)

#define LM3S_PWM_PWMNCTL_MINFLTPER_Pos           17
#define LM3S_PWM_PWMNCTL_MINFLTPER_Msk           (1UL << LM3S_PWM_PWMNCTL_MINFLTPER_Pos)

#define LM3S_PWM_PWMNCTL_FLTSRC_Pos              16
#define LM3S_PWM_PWMNCTL_FLTSRC_Msk              (1UL << LM3S_PWM_PWMNCTL_FLTSRC_Pos)

#define LM3S_PWM_PWMNCTL_DBFALLUPD_Pos           14
#define LM3S_PWM_PWMNCTL_DBFALLUPD_Msk           (0x00000003UL << LM3S_PWM_PWMNCTL_DBFALLUPD_Pos)
#define LM3S_PWM_PWMNCTL_DBFALLUPD_1_Pos         15
#define LM3S_PWM_PWMNCTL_DBFALLUPD_1_Msk         (1UL << LM3S_PWM_PWMNCTL_DBFALLUPD_1_Pos)
#define LM3S_PWM_PWMNCTL_DBFALLUPD_0_Pos         14
#define LM3S_PWM_PWMNCTL_DBFALLUPD_0_Msk         (1UL << LM3S_PWM_PWMNCTL_DBFALLUPD_0_Pos)

#define LM3S_PWM_PWMNCTL_DBRISEUPD_Pos           12
#define LM3S_PWM_PWMNCTL_DBRISEUPD_Msk           (0x00000003UL << LM3S_PWM_PWMNCTL_DBRISEUPD_Pos)
#define LM3S_PWM_PWMNCTL_DBRISEUPD_1_Pos         13
#define LM3S_PWM_PWMNCTL_DBRISEUPD_1_Msk         (1UL << LM3S_PWM_PWMNCTL_DBRISEUPD_1_Pos)
#define LM3S_PWM_PWMNCTL_DBRISEUPD_0_Pos         12
#define LM3S_PWM_PWMNCTL_DBRISEUPD_0_Msk         (1UL << LM3S_PWM_PWMNCTL_DBRISEUPD_0_Pos)

#define LM3S_PWM_PWMNCTL_DBCTLUPD_Pos            10
#define LM3S_PWM_PWMNCTL_DBCTLUPD_Msk            (0x00000003UL << LM3S_PWM_PWMNCTL_DBCTLUPD_Pos)
#define LM3S_PWM_PWMNCTL_DBCTLUPD_1_Pos          11
#define LM3S_PWM_PWMNCTL_DBCTLUPD_1_Msk          (1UL << LM3S_PWM_PWMNCTL_DBCTLUPD_1_Pos)
#define LM3S_PWM_PWMNCTL_DBCTLUPD_0_Pos          10
#define LM3S_PWM_PWMNCTL_DBCTLUPD_0_Msk          (1UL << LM3S_PWM_PWMNCTL_DBCTLUPD_0_Pos)

#define LM3S_PWM_PWMNCTL_GENBUPD_Pos              8
#define LM3S_PWM_PWMNCTL_GENBUPD_Msk             (0x00000003UL << LM3S_PWM_PWMNCTL_GENBUPD_Pos)
#define LM3S_PWM_PWMNCTL_GENBUPD_1_Pos            9
#define LM3S_PWM_PWMNCTL_GENBUPD_1_Msk           (1UL << LM3S_PWM_PWMNCTL_GENBUPD_1_Pos)
#define LM3S_PWM_PWMNCTL_GENBUPD_0_Pos            8
#define LM3S_PWM_PWMNCTL_GENBUPD_0_Msk           (1UL << LM3S_PWM_PWMNCTL_GENBUPD_0_Pos)

#define LM3S_PWM_PWMNCTL_GENAUPD_Pos              6
#define LM3S_PWM_PWMNCTL_GENAUPD_Msk             (0x00000003UL << LM3S_PWM_PWMNCTL_GENAUPD_Pos)
#define LM3S_PWM_PWMNCTL_GENAUPD_1_Pos            7
#define LM3S_PWM_PWMNCTL_GENAUPD_1_Msk           (1UL << LM3S_PWM_PWMNCTL_GENAUPD_1_Pos)
#define LM3S_PWM_PWMNCTL_GENAUPD_0_Pos            6
#define LM3S_PWM_PWMNCTL_GENAUPD_0_Msk           (1UL << LM3S_PWM_PWMNCTL_GENAUPD_0_Pos)

#define LM3S_PWM_PWMNCTL_CMPBUPD_Pos              5
#define LM3S_PWM_PWMNCTL_CMPBUPD_Msk             (1UL << LM3S_PWM_PWMNCTL_CMPBUPD_Pos)

#define LM3S_PWM_PWMNCTL_CMPAUPD_Pos              4
#define LM3S_PWM_PWMNCTL_CMPAUPD_Msk             (1UL << LM3S_PWM_PWMNCTL_CMPAUPD_Pos)

#define LM3S_PWM_PWMNCTL_LOADUPD_Pos              3
#define LM3S_PWM_PWMNCTL_LOADUPD_Msk             (1UL << LM3S_PWM_PWMNCTL_LOADUPD_Pos)

#define LM3S_PWM_PWMNCTL_DEBUG_Pos                2
#define LM3S_PWM_PWMNCTL_DEBUG_Msk               (1UL << LM3S_PWM_PWMNCTL_DEBUG_Pos)

#define LM3S_PWM_PWMNCTL_MODE_Pos                 1
#define LM3S_PWM_PWMNCTL_MODE_Msk                (1UL << LM3S_PWM_PWMNCTL_MODE_Pos)

#define LM3S_PWM_PWMNCTL_ENABLE_Pos               0
#define LM3S_PWM_PWMNCTL_ENABLE_Msk              (1UL /*<< LM3S_PWM_PWMNCTL_ENABLE_Pos*/)

/* LM3S_PWM PWMNINTEN Register Definitions */
#define LM3S_PWM_PWMNINTEN_TRCMPBD_Pos           13
#define LM3S_PWM_PWMNINTEN_TRCMPBD_Msk           (1UL << LM3S_PWM_PWMNINTEN_TRCMPBD_Pos)

#define LM3S_PWM_PWMNINTEN_TRCMPBU_Pos           12
#define LM3S_PWM_PWMNINTEN_TRCMPBU_Msk           (1UL << LM3S_PWM_PWMNINTEN_TRCMPBU_Pos)

#define LM3S_PWM_PWMNINTEN_TRCMPAD_Pos           11
#define LM3S_PWM_PWMNINTEN_TRCMPAD_Msk           (1UL << LM3S_PWM_PWMNINTEN_TRCMPAD_Pos)

#define LM3S_PWM_PWMNINTEN_TRCMPAU_Pos           10
#define LM3S_PWM_PWMNINTEN_TRCMPAU_Msk           (1UL << LM3S_PWM_PWMNINTEN_TRCMPAU_Pos)

#define LM3S_PWM_PWMNINTEN_TRCNTLOAD_Pos          9
#define LM3S_PWM_PWMNINTEN_TRCNTLOAD_Msk         (1UL << LM3S_PWM_PWMNINTEN_TRCNTLOAD_Pos)

#define LM3S_PWM_PWMNINTEN_TRCNTZERO_Pos          8
#define LM3S_PWM_PWMNINTEN_TRCNTZERO_Msk         (1UL << LM3S_PWM_PWMNINTEN_TRCNTZERO_Pos)

#define LM3S_PWM_PWMNINTEN_INTCMPBD_Pos           5
#define LM3S_PWM_PWMNINTEN_INTCMPBD_Msk          (1UL << LM3S_PWM_PWMNINTEN_INTCMPBD_Pos)

#define LM3S_PWM_PWMNINTEN_INTCMPBU_Pos           4
#define LM3S_PWM_PWMNINTEN_INTCMPBU_Msk          (1UL << LM3S_PWM_PWMNINTEN_INTCMPBU_Pos)

#define LM3S_PWM_PWMNINTEN_INTCMPAD_Pos           3
#define LM3S_PWM_PWMNINTEN_INTCMPAD_Msk          (1UL << LM3S_PWM_PWMNINTEN_INTCMPAD_Pos)

#define LM3S_PWM_PWMNINTEN_INTCMPAU_Pos           2
#define LM3S_PWM_PWMNINTEN_INTCMPAU_Msk          (1UL << LM3S_PWM_PWMNINTEN_INTCMPAU_Pos)

#define LM3S_PWM_PWMNINTEN_INTCNTLOAD_Pos         1
#define LM3S_PWM_PWMNINTEN_INTCNTLOAD_Msk        (1UL << LM3S_PWM_PWMNINTEN_INTCNTLOAD_Pos)

#define LM3S_PWM_PWMNINTEN_INTCNTZERO_Pos         0
#define LM3S_PWM_PWMNINTEN_INTCNTZERO_Msk        (1UL /*<< LM3S_PWM_PWMNINTEN_INTCNTZERO_Pos*/)

/* LM3S_PWM PWMNRIS Register Definitions */
#define LM3S_PWM_PWMNRIS_INTCMPBD_Pos             5
#define LM3S_PWM_PWMNRIS_INTCMPBD_Msk            (1UL << LM3S_PWM_PWMNRIS_INTCMPBD_Pos)

#define LM3S_PWM_PWMNRIS_INTCMPBU_Pos             4
#define LM3S_PWM_PWMNRIS_INTCMPBU_Msk            (1UL << LM3S_PWM_PWMNRIS_INTCMPBU_Pos)

#define LM3S_PWM_PWMNRIS_INTCMPAD_Pos             3
#define LM3S_PWM_PWMNRIS_INTCMPAD_Msk            (1UL << LM3S_PWM_PWMNRIS_INTCMPAD_Pos)

#define LM3S_PWM_PWMNRIS_INTCMPAU_Pos             2
#define LM3S_PWM_PWMNRIS_INTCMPAU_Msk            (1UL << LM3S_PWM_PWMNRIS_INTCMPAU_Pos)

#define LM3S_PWM_PWMNRIS_INTCNTLOAD_Pos           1
#define LM3S_PWM_PWMNRIS_INTCNTLOAD_Msk          (1UL << LM3S_PWM_PWMNRIS_INTCNTLOAD_Pos)

#define LM3S_PWM_PWMNRIS_INTCNTZERO_Pos           0
#define LM3S_PWM_PWMNRIS_INTCNTZERO_Msk          (1UL /*<< LM3S_PWM_PWMNRIS_TRCMPBD_Pos*/)

/* LM3S_PWM PWMNISC Register Definitions */
#define LM3S_PWM_PWMNISC_INTCMPBD_Pos             5
#define LM3S_PWM_PWMNISC_INTCMPBD_Msk            (1UL << LM3S_PWM_PWMNISC_INTCMPBD_Pos)

#define LM3S_PWM_PWMNISC_INTCMPBU_Pos             4
#define LM3S_PWM_PWMNISC_INTCMPBU_Msk            (1UL << LM3S_PWM_PWMNISC_INTCMPBU_Pos)

#define LM3S_PWM_PWMNISC_INTCMPAD_Pos             3
#define LM3S_PWM_PWMNISC_INTCMPAD_Msk            (1UL << LM3S_PWM_PWMNISC_INTCMPAD_Pos)

#define LM3S_PWM_PWMNISC_INTCMPAU_Pos             2
#define LM3S_PWM_PWMNISC_INTCMPAU_Msk            (1UL << LM3S_PWM_PWMNISC_INTCMPAU_Pos)

#define LM3S_PWM_PWMNISC_INTCNTLOAD_Pos           1
#define LM3S_PWM_PWMNISC_INTCNTLOAD_Msk          (1UL << LM3S_PWM_PWMNISC_TRCMPBD_Pos)

#define LM3S_PWM_PWMNISC_INTCNTZERO_Pos           0
#define LM3S_PWM_PWMNISC_INTCNTZERO_Msk          (1UL /*<< LM3S_PWM_PWMNISC_INTCNTZERO_Pos*/)

/* LM3S_PWM PWMNLOAD Register Definitions */
#define LM3S_PWM_PWMNLOAD_LOAD_Pos                0
#define LM3S_PWM_PWMNLOAD_LOAD_Msk               (0x0000FFFFUL /*<< LM3S_PWM_PWMNLOAD_LOAD_Pos*/)

/* LM3S_PWM PWMNCOUNT Register Definitions */
#define LM3S_PWM_PWMNCOUNT_COUNT_Pos              0
#define LM3S_PWM_PWMNCOUNT_COUNT_Msk             (0x0000FFFFUL /*<< LM3S_PWM_PWMNCOUNT_COUNT_Pos*/)

/* LM3S_PWM PWMNCMPA Register Definitions */
#define LM3S_PWM_PWMNCMPA_COMPA_Pos               0
#define LM3S_PWM_PWMNCMPA_COMPA_Msk              (0x0000FFFFUL /*<< LM3S_PWM_PWMNCMPA_COMPA_Pos*/)

/* LM3S_PWM PWMNCMPB Register Definitions */
#define LM3S_PWM_PWMNCMPB_COMPB_Pos               0
#define LM3S_PWM_PWMNCMPB_COMPB_Msk              (0x0000FFFFUL /*<< LM3S_PWM_PWMNCMPB_COMPB_Pos*/)

/* LM3S_PWM PWMNGENA Register Definitions */
#define LM3S_PWM_PWMNGENA_ACTCMPBD_Pos           10
#define LM3S_PWM_PWMNGENA_ACTCMPBD_Msk           (0x00000003UL << LM3S_PWM_PWMNGENA_ACTCMPBD_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPBD_1_Pos         11
#define LM3S_PWM_PWMNGENA_ACTCMPBD_1_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPBD_1_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPBD_0_Pos         10
#define LM3S_PWM_PWMNGENA_ACTCMPBD_0_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPBD_0_Pos)

#define LM3S_PWM_PWMNGENA_ACTCMPBU_Pos            8
#define LM3S_PWM_PWMNGENA_ACTCMPBU_Msk           (0x00000003UL << LM3S_PWM_PWMNGENA_ACTCMPBU_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPBU_1_Pos          9
#define LM3S_PWM_PWMNGENA_ACTCMPBU_1_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPBU_1_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPBU_0_Pos          8
#define LM3S_PWM_PWMNGENA_ACTCMPBU_0_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPBU_0_Pos)

#define LM3S_PWM_PWMNGENA_ACTCMPAD_Pos            6
#define LM3S_PWM_PWMNGENA_ACTCMPAD_Msk           (0x00000003UL << LM3S_PWM_PWMNGENA_ACTCMPAD_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPAD_1_Pos          7
#define LM3S_PWM_PWMNGENA_ACTCMPAD_1_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPAD_1_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPAD_0_Pos          6
#define LM3S_PWM_PWMNGENA_ACTCMPAD_0_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPAD_0_Pos)

#define LM3S_PWM_PWMNGENA_ACTCMPAU_Pos            4
#define LM3S_PWM_PWMNGENA_ACTCMPAU_Msk           (0x00000003UL << LM3S_PWM_PWMNGENA_ACTCMPAU_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPAU_1_Pos          5
#define LM3S_PWM_PWMNGENA_ACTCMPAU_1_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPAU_1_Pos)
#define LM3S_PWM_PWMNGENA_ACTCMPAU_0_Pos          4
#define LM3S_PWM_PWMNGENA_ACTCMPAU_0_Msk         (1UL << LM3S_PWM_PWMNGENA_ACTCMPAU_0_Pos)

#define LM3S_PWM_PWMNGENA_ACTLOAD_Pos             2
#define LM3S_PWM_PWMNGENA_ACTLOAD_Msk            (0x00000003UL << LM3S_PWM_PWMNGENA_ACTLOAD_Pos)
#define LM3S_PWM_PWMNGENA_ACTLOAD_1_Pos           3
#define LM3S_PWM_PWMNGENA_ACTLOAD_1_Msk          (1UL << LM3S_PWM_PWMNGENA_ACTLOAD_1_Pos)
#define LM3S_PWM_PWMNGENA_ACTLOAD_0_Pos           2
#define LM3S_PWM_PWMNGENA_ACTLOAD_0_Msk          (1UL << LM3S_PWM_PWMNGENA_ACTLOAD_0_Pos)

#define LM3S_PWM_PWMNGENA_ACTZERO_Pos             0
#define LM3S_PWM_PWMNGENA_ACTZERO_Msk            (0x00000003UL /*<< LM3S_PWM_PWMNGENA_ACTZERO_Pos*/)
#define LM3S_PWM_PWMNGENA_ACTZERO_1_Pos           1
#define LM3S_PWM_PWMNGENA_ACTZERO_1_Msk          (1UL << LM3S_PWM_PWMNGENA_ACTZERO_1_Pos)
#define LM3S_PWM_PWMNGENA_ACTZERO_0_Pos           0
#define LM3S_PWM_PWMNGENA_ACTZERO_0_Msk          (1UL /*<< LM3S_PWM_PWMNGENA_ACTZERO_0_Pos*/)

/* LM3S_PWM PWMNGENB Register Definitions */
#define LM3S_PWM_PWMNGENB_ACTCMPBD_Pos           10
#define LM3S_PWM_PWMNGENB_ACTCMPBD_Msk           (0x00000003UL << LM3S_PWM_PWMNGENB_ACTCMPBD_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPBD_1_Pos         11
#define LM3S_PWM_PWMNGENB_ACTCMPBD_1_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPBD_1_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPBD_0_Pos         10
#define LM3S_PWM_PWMNGENB_ACTCMPBD_0_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPBD_0_Pos)

#define LM3S_PWM_PWMNGENB_ACTCMPBU_Pos            8
#define LM3S_PWM_PWMNGENB_ACTCMPBU_Msk           (0x00000003UL << LM3S_PWM_PWMNGENB_ACTCMPBU_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPBU_1_Pos          9
#define LM3S_PWM_PWMNGENB_ACTCMPBU_1_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPBU_1_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPBU_0_Pos          8
#define LM3S_PWM_PWMNGENB_ACTCMPBU_0_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPBU_0_Pos)

#define LM3S_PWM_PWMNGENB_ACTCMPAD_Pos            6
#define LM3S_PWM_PWMNGENB_ACTCMPAD_Msk           (0x00000003UL << LM3S_PWM_PWMNGENB_ACTCMPAD_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPAD_1_Pos          7
#define LM3S_PWM_PWMNGENB_ACTCMPAD_1_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPAD_1_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPAD_0_Pos          6
#define LM3S_PWM_PWMNGENB_ACTCMPAD_0_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPAD_0_Pos)

#define LM3S_PWM_PWMNGENB_ACTCMPAU_Pos            4
#define LM3S_PWM_PWMNGENB_ACTCMPAU_Msk           (0x00000003UL << LM3S_PWM_PWMNGENB_ACTCMPAU_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPAU_1_Pos          5
#define LM3S_PWM_PWMNGENB_ACTCMPAU_1_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPAU_1_Pos)
#define LM3S_PWM_PWMNGENB_ACTCMPAU_0_Pos          4
#define LM3S_PWM_PWMNGENB_ACTCMPAU_0_Msk         (1UL << LM3S_PWM_PWMNGENB_ACTCMPAU_0_Pos)

#define LM3S_PWM_PWMNGENB_ACTLOAD_Pos             2
#define LM3S_PWM_PWMNGENB_ACTLOAD_Msk            (0x00000003UL << LM3S_PWM_PWMNGENB_ACTLOAD_Pos)
#define LM3S_PWM_PWMNGENB_ACTLOAD_1_Pos           3
#define LM3S_PWM_PWMNGENB_ACTLOAD_1_Msk          (1UL << LM3S_PWM_PWMNGENB_ACTLOAD_1_Pos)
#define LM3S_PWM_PWMNGENB_ACTLOAD_0_Pos           2
#define LM3S_PWM_PWMNGENB_ACTLOAD_0_Msk          (1UL << LM3S_PWM_PWMNGENB_ACTLOAD_0_Pos)

#define LM3S_PWM_PWMNGENB_ACTZERO_Pos             0
#define LM3S_PWM_PWMNGENB_ACTZERO_Msk            (0x00000003UL /*<< LM3S_PWM_PWMNGENB_ACTZERO_Pos*/)
#define LM3S_PWM_PWMNGENB_ACTZERO_1_Pos           1
#define LM3S_PWM_PWMNGENB_ACTZERO_1_Msk          (1UL << LM3S_PWM_PWMNGENB_ACTZERO_1_Pos)
#define LM3S_PWM_PWMNGENB_ACTZERO_0_Pos           0
#define LM3S_PWM_PWMNGENB_ACTZERO_0_Msk          (1UL /*<< LM3S_PWM_PWMNGENB_ACTZERO_0_Pos*/)

/* LM3S_PWM PWMNDBCTL Register Definitions */
#define LM3S_PWM_PWMNDBCTL_ENABLE_Pos             0
#define LM3S_PWM_PWMNDBCTL_ENABLE_Msk            (1UL /*<< LM3S_PWM_PWMNDBCTL_ENABLE_Pos*/)

/* LM3S_PWM PWMNDBRISE Register Definitions */
#define LM3S_PWM_PWMNDBRISE_RISEDELAY_Pos         0
#define LM3S_PWM_PWMNDBRISE_RISEDELAY_Msk        (0x00000FFFUL /*<< LM3S_PWM_PWMNDBRISE_RISEDELAY_Pos*/)

/* LM3S_PWM PWMNDBFALL Register Definitions */
#define LM3S_PWM_PWMNDBFALL_FALLDELAY_Pos         0
#define LM3S_PWM_PWMNDBFALL_FALLDELAY_Msk        (0x00000FFFUL /*<< LM3S_PWM_PWMNDBRISE_FALLDELAY_Pos*/)

/* LM3S_PWM PWMNFLTSRC0 Register Definitions */
#define LM3S_PWM_PWMNFLTSRC0_FAULT3_Pos           3
#define LM3S_PWM_PWMNFLTSRC0_FAULT3_Msk          (1UL << LM3S_PWM_PWMNFLTSRC0_FAULT3_Pos)

#define LM3S_PWM_PWMNFLTSRC0_FAULT2_Pos           2
#define LM3S_PWM_PWMNFLTSRC0_FAULT2_Msk          (1UL << LM3S_PWM_PWMNFLTSRC0_FAULT2_Pos)

#define LM3S_PWM_PWMNFLTSRC0_FAULT1_Pos           1
#define LM3S_PWM_PWMNFLTSRC0_FAULT1_Msk          (1UL << LM3S_PWM_PWMNFLTSRC0_FAULT1_Pos)

#define LM3S_PWM_PWMNFLTSRC0_FAULT0_Pos           0
#define LM3S_PWM_PWMNFLTSRC0_FAULT0_Msk          (1UL /*<< LM3S_PWM_PWMNFLTSRC0_FAULT0_Pos*/)

/* LM3S_PWM PWMNFLTSRC0 Register Definitions */
#define LM3S_PWM_PWMNFLTSRC1_DCMP7_Pos            7
#define LM3S_PWM_PWMNFLTSRC1_DCMP7_Msk           (1UL << LM3S_PWM_PWMNFLTSRC1_DCMP7_Pos)

#define LM3S_PWM_PWMNFLTSRC1_DCMP6_Pos            6
#define LM3S_PWM_PWMNFLTSRC1_DCMP6_Msk           (1UL << LM3S_PWM_PWMNFLTSRC1_DCMP6_Pos)

#define LM3S_PWM_PWMNFLTSRC1_DCMP5_Pos            5
#define LM3S_PWM_PWMNFLTSRC1_DCMP5_Msk           (1UL << LM3S_PWM_PWMNFLTSRC1_DCMP5_Pos)

#define LM3S_PWM_PWMNFLTSRC1_DCMP4_Pos            4
#define LM3S_PWM_PWMNFLTSRC1_DCMP4_Msk           (1UL << LM3S_PWM_PWMNFLTSRC1_DCMP4_Pos)

#define LM3S_PWM_PWMNFLTSRC1_DCMP3_Pos            3
#define LM3S_PWM_PWMNFLTSRC1_DCMP3_Msk           (1UL << LM3S_PWM_PWMNFLTSRC1_DCMP3_Pos)

#define LM3S_PWM_PWMNFLTSRC1_DCMP2_Pos            2
#define LM3S_PWM_PWMNFLTSRC1_DCMP2_Msk           (1UL << LM3S_PWM_PWMNFLTSRC1_DCMP2_Pos)

#define LM3S_PWM_PWMNFLTSRC1_DCMP1_Pos            1
#define LM3S_PWM_PWMNFLTSRC1_DCMP1_Msk           (1UL << LM3S_PWM_PWMNFLTSRC1_DCMP1_Pos)

#define LM3S_PWM_PWMNFLTSRC1_DCMP0_Pos            0
#define LM3S_PWM_PWMNFLTSRC1_DCMP0_Msk           (1UL /*<< LM3S_PWM_PWMNFLTSRC1_DCMP0_Pos*/)

/* LM3S_PWM PWMNMINFLTPER Register Definitions */
#define LM3S_PWM_PWMNMINFLTPER_MFP_Pos            7
#define LM3S_PWM_PWMNMINFLTPER_MFP_Msk           (0x0000FFFFUL << LM3S_PWM_PWMNMINFLTPER_MFP_Pos)

/* LM3S_PWM PWMNFLTSEN Register Definitions */
#define LM3S_PWM_PWMNFLTSEN_FAULT3_Pos            3
#define LM3S_PWM_PWMNFLTSEN_FAULT3_Msk           (1UL << LM3S_PWM_PWMNFLTSEN_FAULT3_Pos)

#define LM3S_PWM_PWMNFLTSEN_FAULT2_Pos            2
#define LM3S_PWM_PWMNFLTSEN_FAULT2_Msk           (1UL << LM3S_PWM_PWMNFLTSEN_FAULT2_Pos)

#define LM3S_PWM_PWMNFLTSEN_FAULT1_Pos            1
#define LM3S_PWM_PWMNFLTSEN_FAULT1_Msk           (1UL << LM3S_PWM_PWMNFLTSEN_FAULT1_Pos)

#define LM3S_PWM_PWMNFLTSEN_FAULT0_Pos            0
#define LM3S_PWM_PWMNFLTSEN_FAULT0_Msk           (1UL /*<< LM3S_PWM_PWMNFLTSEN_FAULT0_Pos*/)

/* LM3S_PWM PWMNFLTSTAT0 Register Definitions */
#define LM3S_PWM_PWMNFLTSTAT0_FAULT3_Pos          3
#define LM3S_PWM_PWMNFLTSTAT0_FAULT3_Msk         (1UL << LM3S_PWM_PWMNFLTSTAT0_FAULT3_Pos)

#define LM3S_PWM_PWMNFLTSTAT0_FAULT2_Pos          2
#define LM3S_PWM_PWMNFLTSTAT0_FAULT2_Msk         (1UL << LM3S_PWM_PWMNFLTSTAT0_FAULT2_Pos)

#define LM3S_PWM_PWMNFLTSTAT0_FAULT1_Pos          1
#define LM3S_PWM_PWMNFLTSTAT0_FAULT1_Msk         (1UL << LM3S_PWM_PWMNFLTSTAT0_FAULT1_Pos)

#define LM3S_PWM_PWMNFLTSTAT0_FAULT0_Pos          0
#define LM3S_PWM_PWMNFLTSTAT0_FAULT0_Msk         (1UL /*<< LM3S_PWM_PWMNFLTSTAT0_FAULT0_Pos*/)

/* LM3S_PWM PWMNFLTSTAT1 Register Definitions */
#define LM3S_PWM_PWMNFLTSTAT1_DCMP7_Pos           7
#define LM3S_PWM_PWMNFLTSTAT1_DCMP7_Msk          (1UL << LM3S_PWM_PWMNFLTSTAT1_DCMP7_Pos)

#define LM3S_PWM_PWMNFLTSTAT1_DCMP6_Pos           6
#define LM3S_PWM_PWMNFLTSTAT1_DCMP6_Msk          (1UL << LM3S_PWM_PWMNFLTSTAT1_DCMP6_Pos)

#define LM3S_PWM_PWMNFLTSTAT1_DCMP5_Pos           5
#define LM3S_PWM_PWMNFLTSTAT1_DCMP5_Msk          (1UL << LM3S_PWM_PWMNFLTSTAT1_DCMP5_Pos)

#define LM3S_PWM_PWMNFLTSTAT1_DCMP4_Pos           4
#define LM3S_PWM_PWMNFLTSTAT1_DCMP4_Msk          (1UL << LM3S_PWM_PWMNFLTSTAT1_DCMP4_Pos)

#define LM3S_PWM_PWMNFLTSTAT1_DCMP3_Pos           3
#define LM3S_PWM_PWMNFLTSTAT1_DCMP3_Msk          (1UL << LM3S_PWM_PWMNFLTSTAT1_DCMP3_Pos)

#define LM3S_PWM_PWMNFLTSTAT1_DCMP2_Pos           2
#define LM3S_PWM_PWMNFLTSTAT1_DCMP2_Msk          (1UL << LM3S_PWM_PWMNFLTSTAT1_DCMP2_Pos)

#define LM3S_PWM_PWMNFLTSTAT1_DCMP1_Pos           1
#define LM3S_PWM_PWMNFLTSTAT1_DCMP1_Msk          (1UL << LM3S_PWM_PWMNFLTSTAT1_DCMP1_Pos)

#define LM3S_PWM_PWMNFLTSTAT1_DCMP0_Pos           0
#define LM3S_PWM_PWMNFLTSTAT1_DCMP0_Msk          (1UL /*<< LM3S_PWM_PWMNFLTSTAT1_DCMP0_Pos*/)

/* ================================================================================ */
/* ================                       QEI                      ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  CTL;                  /* Offset: 0x000 (R/W) Control Register */
  __IM  uint32_t  STAT;                 /* Offset: 0x004 (R/ ) Status Register */
  __IOM uint32_t  POS;                  /* Offset: 0x008 (R/W) Position Register */
  __IOM uint32_t  MAXPOS;               /* Offset: 0x00C (R/W) Maximum Position Register */
  __IOM uint32_t  LOAD;                 /* Offset: 0x010 (R/W) Timer Load Register */
  __IM  uint32_t  TIME;                 /* Offset: 0x014 (R/ ) Timer Register */
  __IM  uint32_t  COUNT;                /* Offset: 0x018 (R/ ) Velocity Counter Register */
  __IM  uint32_t  SPEED;                /* Offset: 0x01C (R/ ) Velocity Register */
  __IOM uint32_t  INTEN;                /* Offset: 0x020 (R/W) Interrupt Enable Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x024 (R/ ) Raw Interrupt Status Register */
  __IOM uint32_t  ISC;                  /* Offset: 0x01C (R/W) Interrupt Status & Clear Register */
} LM3S_QEI_TypeDef;

/* LM3S_QEI CTL Register Definitions */
#define LM3S_QEI_CTL_FILTCNT_Pos                 16
#define LM3S_QEI_CTL_FILTCNT_Msk                 (0x0000000FUL << LM3S_QEI_CTL_FILTCNT_Pos)
#define LM3S_QEI_CTL_FILTCNT_3_Pos               19
#define LM3S_QEI_CTL_FILTCNT_3_Msk               (1UL << LM3S_QEI_CTL_FILTCNT_3_Pos)
#define LM3S_QEI_CTL_FILTCNT_2_Pos               18
#define LM3S_QEI_CTL_FILTCNT_2_Msk               (1UL << LM3S_QEI_CTL_FILTCNT_2_Pos)
#define LM3S_QEI_CTL_FILTCNT_1_Pos               17
#define LM3S_QEI_CTL_FILTCNT_1_Msk               (1UL << LM3S_QEI_CTL_FILTCNT_1_Pos)
#define LM3S_QEI_CTL_FILTCNT_0_Pos               16
#define LM3S_QEI_CTL_FILTCNT_0_Msk               (1UL << LM3S_QEI_CTL_FILTCNT_0_Pos)

#define LM3S_QEI_CTL_FILTEN_Pos                  13
#define LM3S_QEI_CTL_FILTEN_Msk                  (1UL << LM3S_QEI_CTL_FILTEN_Pos)

#define LM3S_QEI_CTL_STALLEN_Pos                 12
#define LM3S_QEI_CTL_STALLEN_Msk                 (1UL << LM3S_QEI_CTL_STALLEN_Pos)

#define LM3S_QEI_CTL_INVI_Pos                    11
#define LM3S_QEI_CTL_INVI_Msk                    (1UL << LM3S_QEI_CTL_INVI_Pos)

#define LM3S_QEI_CTL_INVB_Pos                    10
#define LM3S_QEI_CTL_INVB_Msk                    (1UL << LM3S_QEI_CTL_INVB_Pos)

#define LM3S_QEI_CTL_INVA_Pos                     9
#define LM3S_QEI_CTL_INVA_Msk                    (1UL << LM3S_QEI_CTL_INVA_Pos)

#define LM3S_QEI_CTL_VELDIV_Pos                   6
#define LM3S_QEI_CTL_VELDIV_Msk                  (0x00000007UL << LM3S_QEI_CTL_VELDIV_Pos)
#define LM3S_QEI_CTL_VELDIV_2_Pos                 8
#define LM3S_QEI_CTL_VELDIV_2_Msk                (1UL << LM3S_QEI_CTL_VELDIV_2_Pos)
#define LM3S_QEI_CTL_VELDIV_1_Pos                 7
#define LM3S_QEI_CTL_VELDIV_1_Msk                (1UL << LM3S_QEI_CTL_VELDIV_1_Pos)
#define LM3S_QEI_CTL_VELDIV_0_Pos                 6
#define LM3S_QEI_CTL_VELDIV_0_Msk                (1UL << LM3S_QEI_CTL_VELDIV_0_Pos)

#define LM3S_QEI_CTL_VELEN_Pos                    5
#define LM3S_QEI_CTL_VELEN_Msk                   (1UL << LM3S_QEI_CTL_VELEN_Pos)

#define LM3S_QEI_CTL_RESMODE_Pos                  4
#define LM3S_QEI_CTL_RESMODE_Msk                 (1UL << LM3S_QEI_CTL_RESMODE_Pos)

#define LM3S_QEI_CTL_CAPMODE_Pos                  3
#define LM3S_QEI_CTL_CAPMODE_Msk                 (1UL << LM3S_QEI_CTL_CAPMODE_Pos)

#define LM3S_QEI_CTL_SIGMODE_Pos                  2
#define LM3S_QEI_CTL_SIGMODE_Msk                 (1UL << LM3S_QEI_CTL_SIGMODE_Pos)

#define LM3S_QEI_CTL_SWAP_Pos                     1
#define LM3S_QEI_CTL_SWAP_Msk                    (1UL << LM3S_QEI_CTL_SWAP_Pos)

#define LM3S_QEI_CTL_ENABLE_Pos                   0
#define LM3S_QEI_CTL_ENABLE_Msk                  (1UL /*<< LM3S_QEI_CTL_ENABLE_Pos*/)

/* LM3S_QEI STAT Register Definitions */
#define LM3S_QEI_STAT_DIRECTION_Pos               1
#define LM3S_QEI_STAT_DIRECTION_Msk              (1UL << LM3S_QEI_STAT_DIRECTION_Pos)

#define LM3S_QEI_STAT_ERROR_Pos                   0
#define LM3S_QEI_STAT_ERROR_Msk                  (1UL /*<< LM3S_QEI_STAT_ERROR_Pos*/)

/* LM3S_QEI POS Register Definitions */
#define LM3S_QEI_POS_POSITION_Pos                 0
#define LM3S_QEI_POS_POSITION_Msk                (0xFFFFFFFFUL /*<< LM3S_QEI_POS_POSITION_Pos*/)

/* LM3S_QEI MAXPOS Register Definitions */
#define LM3S_QEI_MAXPOS_MAXPOS_Pos                0
#define LM3S_QEI_MAXPOS_MAXPOS_Msk               (0xFFFFFFFFUL /*<< LM3S_QEI_MAXPOS_MAXPOS_Pos*/)

/* LM3S_QEI LOAD Register Definitions */
#define LM3S_QEI_LOAD_LOAD_Pos                    0
#define LM3S_QEI_LOAD_LOAD_Msk                   (0xFFFFFFFFUL /*<< LM3S_QEI_LOAD_LOAD_Pos*/)

/* LM3S_QEI TIME Register Definitions */
#define LM3S_QEI_TIME_TIME_Pos                    0
#define LM3S_QEI_TIME_TIME_Msk                   (0xFFFFFFFFUL /*<< LM3S_QEI_TIME_TIME_Pos*/)

/* LM3S_QEI COUNT Register Definitions */
#define LM3S_QEI_COUNT_COUNT_Pos                  0
#define LM3S_QEI_COUNT_COUNT_Msk                 (0xFFFFFFFFUL /*<< LM3S_QEI_COUNT_COUNT_Pos*/)

/* LM3S_QEI SPEED Register Definitions */
#define LM3S_QEI_SPEED_SPEED_Pos                  0
#define LM3S_QEI_SPEED_SPEED_Msk                 (0xFFFFFFFFUL /*<< LM3S_QEI_SPEED_SPEED_Pos*/)

/* LM3S_QEI INTEN Register Definitions */
#define LM3S_QEI_INTEN_INTERROR_Pos               3
#define LM3S_QEI_INTEN_INTERROR_Msk              (1UL << LM3S_QEI_INTEN_INTERROR_Pos)

#define LM3S_QEI_INTEN_INTDIR_Pos                 2
#define LM3S_QEI_INTEN_INTDIR_Msk                (1UL << LM3S_QEI_INTEN_INTDIR_Pos)

#define LM3S_QEI_INTEN_INTTIMER_Pos               1
#define LM3S_QEI_INTEN_INTTIMER_Msk              (1UL << LM3S_QEI_INTEN_INTTIMER_Pos)

#define LM3S_QEI_INTEN_INTINDEX_Pos               0
#define LM3S_QEI_INTEN_INTINDEX_Msk              (1UL /*<< LM3S_QEI_INTEN_INTINDEX_Pos*/)

/* LM3S_QEI RIS Register Definitions */
#define LM3S_QEI_RIS_INTERROR_Pos                 3
#define LM3S_QEI_RIS_INTERROR_Msk                (1UL << LM3S_QEI_RIS_INTERROR_Pos)

#define LM3S_QEI_RIS_INTDIR_Pos                   2
#define LM3S_QEI_RIS_INTDIR_Msk                  (1UL << LM3S_QEI_RIS_INTDIR_Pos)

#define LM3S_QEI_RIS_INTTIMER_Pos                 1
#define LM3S_QEI_RIS_INTTIMER_Msk                (1UL << LM3S_QEI_RIS_INTTIMER_Pos)

#define LM3S_QEI_RIS_INTINDEX_Pos                 0
#define LM3S_QEI_RIS_INTINDEX_Msk                (1UL /*<< LM3S_QEI_RIS_INTINDEX_Pos*/)

/* LM3S_QEI ISC Register Definitions */
#define LM3S_QEI_ISC_INTERROR_Pos                 3
#define LM3S_QEI_ISC_INTERROR_Msk                (1UL << LM3S_QEI_ISC_INTERROR_Pos)

#define LM3S_QEI_ISC_INTDIR_Pos                   2
#define LM3S_QEI_ISC_INTDIR_Msk                  (1UL << LM3S_QEI_ISC_INTDIR_Pos)

#define LM3S_QEI_ISC_INTTIMER_Pos                 1
#define LM3S_QEI_ISC_INTTIMER_Msk                (1UL << LM3S_QEI_ISC_INTTIMER_Pos)

#define LM3S_QEI_ISC_INTINDEX_Pos                 0
#define LM3S_QEI_ISC_INTINDEX_Msk                (1UL /*<< LM3S_QEI_ISC_INTINDEX_Pos*/)

/* ================================================================================ */
/* ================                      GPTM                     ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  CFG;                  /* Offset: 0x000 (R/W) Configuration Register */
  __IOM uint32_t  TAMR;                 /* Offset: 0x004 (R/W) Timer A Mode Register */
  __IOM uint32_t  TBMR;                 /* Offset: 0x008 (R/W) Timer B Mode Register */
  __IOM uint32_t  CTL;                  /* Offset: 0x010 (R/W) Control Register */
  __IOM uint32_t  IMR;                  /* Offset: 0x014 (R/W) Interrupt Mask Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x018 (R/ ) Raw Interrupt Status Register */
  __IM  uint32_t  MIS;                  /* Offset: 0x01C (R/ ) Masked Interrupt Status Register */
  __OM  uint32_t  ICR;                  /* Offset: 0x020 ( /W) Interrupt Clear Register */
  __IOM uint32_t  TAILR;                /* Offset: 0x024 (R/W) Timer A Interval Load Register */
  __IOM uint32_t  TBILR;                /* Offset: 0x028 (R/W) Timer B Interval Load Register */
  __IOM uint32_t  TAMATCHR;             /* Offset: 0x02C (R/W) Timer A Match Register */
  __IOM uint32_t  TBMATCHR;             /* Offset: 0x030 (R/W) Timer B Match Register */
  __IOM uint32_t  TAPR;                 /* Offset: 0x040 (R/W) Timer A Prescale Register */
  __IOM uint32_t  TBPR;                 /* Offset: 0x044 (R/W) Timer B Prescale Register */
  __IOM uint32_t  TAPMR;                /* Offset: 0x048 (R/W) Timer A Prescale Match Register */
  __IOM uint32_t  TBPMR;                /* Offset: 0x050 (R/W) Timer B Prescale Match Register */
  __IM  uint32_t  TAR;                  /* Offset: 0x054 (R/ ) Timer A Register */
  __IM  uint32_t  TBR;                  /* Offset: 0x058 (R/ ) Timer B Register */
  __IOM uint32_t  TAV;                  /* Offset: 0x05C (R/W) Timer A Value Register */
  __IOM uint32_t  TBV;                  /* Offset: 0x060 (R/W) Timer B Value Register */
} LM3S_GPTM_TypeDef;

/* LM3S_GPTM CFG Register Definitions */
#define LM3S_GPTM_CFG_GPTMCFG_Pos                 0
#define LM3S_GPTM_CFG_GPTMCFG_Msk                (0x00000007UL /*<< LM3S_GPTM_CFG_GPTMCFG_Pos*/)
#define LM3S_GPTM_CFG_GPTMCFG_2_Pos               2
#define LM3S_GPTM_CFG_GPTMCFG_2_Msk              (1UL << LM3S_GPTM_CFG_GPTMCFG_2_Pos)
#define LM3S_GPTM_CFG_GPTMCFG_1_Pos               1
#define LM3S_GPTM_CFG_GPTMCFG_1_Msk              (1UL << LM3S_GPTM_CFG_GPTMCFG_1_Pos)
#define LM3S_GPTM_CFG_GPTMCFG_0_Pos               0
#define LM3S_GPTM_CFG_GPTMCFG_0_Msk              (1UL /*<< LM3S_GPTM_CFG_GPTMCFG_0_Pos*/)

/* LM3S_GPTM TAMR Register Definitions */
#define LM3S_GPTM_TAMR_TASNAPS_Pos                7
#define LM3S_GPTM_TAMR_TASNAPS_Msk               (1UL << LM3S_GPTM_TAMR_TASNAPS_Pos)

#define LM3S_GPTM_TAMR_TAWOT_Pos                  6
#define LM3S_GPTM_TAMR_TAWOT_Msk                 (1UL << LM3S_GPTM_TAMR_TAWOT_Pos)

#define LM3S_GPTM_TAMR_TAMIE_Pos                  5
#define LM3S_GPTM_TAMR_TAMIE_Msk                 (1UL << LM3S_GPTM_TAMR_TAMIE_Pos)

#define LM3S_GPTM_TAMR_TACDIR_Pos                 4
#define LM3S_GPTM_TAMR_TACDIR_Msk                (1UL << LM3S_GPTM_TAMR_TACDIR_Pos)

#define LM3S_GPTM_TAMR_TAAMS_Pos                  3
#define LM3S_GPTM_TAMR_TAAMS_Msk                 (1UL << LM3S_GPTM_TAMR_TAAMS_Pos)

#define LM3S_GPTM_TAMR_TACMR_Pos                  2
#define LM3S_GPTM_TAMR_TACMR_Msk                 (1UL << LM3S_GPTM_TAMR_TACMR_Pos)

#define LM3S_GPTM_TAMR_TAMR_Pos                   0
#define LM3S_GPTM_TAMR_TAMR_Msk                  (0x00000003UL /*<< LM3S_GPTM_TAMR_TAMR_Pos*/)
#define LM3S_GPTM_TAMR_TAMR_1_Pos                 1
#define LM3S_GPTM_TAMR_TAMR_1_Msk                (1UL << LM3S_GPTM_TAMR_TAMR_1_Pos)
#define LM3S_GPTM_TAMR_TAMR_0_Pos                 0
#define LM3S_GPTM_TAMR_TAMR_0_Msk                (1UL /*<< LM3S_GPTM_TAMR_TAMR_0_Pos*/)

/* LM3S_GPTM TBMR Register Definitions */
#define LM3S_GPTM_TBMR_TBSNAPS_Pos                7
#define LM3S_GPTM_TBMR_TBSNAPS_Msk               (1UL << LM3S_GPTM_TBMR_TBSNAPS_Pos)

#define LM3S_GPTM_TBMR_TBWOT_Pos                  6
#define LM3S_GPTM_TBMR_TBWOT_Msk                 (1UL << LM3S_GPTM_TBMR_TBWOT_Pos)

#define LM3S_GPTM_TBMR_TBMIE_Pos                  5
#define LM3S_GPTM_TBMR_TBMIE_Msk                 (1UL << LM3S_GPTM_TBMR_TBMIE_Pos)

#define LM3S_GPTM_TBMR_TBCDIR_Pos                 4
#define LM3S_GPTM_TBMR_TBCDIR_Msk                (1UL << LM3S_GPTM_TBMR_TBCDIR_Pos)

#define LM3S_GPTM_TBMR_TBAMS_Pos                  3
#define LM3S_GPTM_TBMR_TBAMS_Msk                 (1UL << LM3S_GPTM_TBMR_TBAMS_Pos)

#define LM3S_GPTM_TBMR_TBCMR_Pos                  2
#define LM3S_GPTM_TBMR_TBCMR_Msk                 (1UL << LM3S_GPTM_TBMR_TBCMR_Pos)

#define LM3S_GPTM_TBMR_TBMR_Pos                   0
#define LM3S_GPTM_TBMR_TBMR_Msk                  (0x00000003UL /*<< LM3S_GPTM_TBMR_TBMR_Pos*/)
#define LM3S_GPTM_TBMR_TBMR_1_Pos                 1
#define LM3S_GPTM_TBMR_TBMR_1_Msk                (1UL << LM3S_GPTM_TBMR_TBMR_1_Pos)
#define LM3S_GPTM_TBMR_TBMR_0_Pos                 0
#define LM3S_GPTM_TBMR_TBMR_0_Msk                (1UL /*<< LM3S_GPTM_TBMR_TBMR_0_Pos*/)

/* LM3S_GPTM CTL Register Definitions */
#define LM3S_GPTM_CTL_TBPWML_Pos                 14
#define LM3S_GPTM_CTL_TBPWML_Msk                 (1UL << LM3S_GPTM_CTL_TBPWML_Pos)

#define LM3S_GPTM_CTL_TBPWML_Pos                 14
#define LM3S_GPTM_CTL_TBPWML_Msk                 (1UL << LM3S_GPTM_CTL_TBPWML_Pos)

#define LM3S_GPTM_CTL_TBEVENT_Pos                10
#define LM3S_GPTM_CTL_TBEVENT_Msk                (0x00000003UL << LM3S_GPTM_CTL_TBEVENT_Pos)
#define LM3S_GPTM_CTL_TBEVENT_1_Pos              11
#define LM3S_GPTM_CTL_TBEVENT_1_Msk              (1UL << LM3S_GPTM_CTL_TBEVENT_1_Pos)
#define LM3S_GPTM_CTL_TBEVENT_0_Pos              10
#define LM3S_GPTM_CTL_TBEVENT_0_Msk              (1UL << LM3S_GPTM_CTL_TBEVENT_0_Pos)

#define LM3S_GPTM_CTL_TBSTALL_Pos                 7
#define LM3S_GPTM_CTL_TBSTALL_Msk                (1UL << LM3S_GPTM_CTL_TBSTALL_Pos)

#define LM3S_GPTM_CTL_TBEN_Pos                    8
#define LM3S_GPTM_CTL_TBEN_Msk                   (1UL << LM3S_GPTM_CTL_TBEN_Pos)

#define LM3S_GPTM_CTL_TAPWML_Pos                  6
#define LM3S_GPTM_CTL_TAPWML_Msk                 (1UL << LM3S_GPTM_CTL_TAPWML_Pos)

#define LM3S_GPTM_CTL_TAOTE_Pos                   5
#define LM3S_GPTM_CTL_TAOTE_Msk                  (1UL << LM3S_GPTM_CTL_TAOTE_Pos)

#define LM3S_GPTM_CTL_RTCEN_Pos                   4
#define LM3S_GPTM_CTL_RTCEN_Msk                  (1UL << LM3S_GPTM_CTL_RTCEN_Pos)

#define LM3S_GPTM_CTL_TAEVENT_Pos                 2
#define LM3S_GPTM_CTL_TAEVENT_Msk                (0x00000003UL << LM3S_GPTM_CTL_TAEVENT_Pos)
#define LM3S_GPTM_CTL_TAEVENT_1_Pos               2
#define LM3S_GPTM_CTL_TAEVENT_1_Msk              (1UL << LM3S_GPTM_CTL_TAEVENT_1_Pos)
#define LM3S_GPTM_CTL_TAEVENT_0_Pos               1
#define LM3S_GPTM_CTL_TAEVENT_0_Msk              (1UL << LM3S_GPTM_CTL_TAEVENT_0_Pos)

#define LM3S_GPTM_CTL_TASTALL_Pos                 1
#define LM3S_GPTM_CTL_TASTALL_Msk                (1UL << LM3S_GPTM_CTL_TASTALL_Pos)

#define LM3S_GPTM_CTL_TAEN_Pos                    0
#define LM3S_GPTM_CTL_TAEN_Msk                   (1UL /*<< LM3S_GPTM_CTL_TBPWML_Pos*/)

/* LM3S_GPTM IMR Register Definitions */
#define LM3S_GPTM_IMR_TBMIM_Pos                  11
#define LM3S_GPTM_IMR_TBMIM_Msk                  (1UL << LM3S_GPTM_IMR_TBMIM_Pos)

#define LM3S_GPTM_IMR_CBEIM_Pos                  10
#define LM3S_GPTM_IMR_CBEIM_Msk                  (1UL << LM3S_GPTM_IMR_CBEIM_Pos)

#define LM3S_GPTM_IMR_CBMIM_Pos                   9
#define LM3S_GPTM_IMR_CBMIM_Msk                  (1UL << LM3S_GPTM_IMR_CBMIM_Pos)

#define LM3S_GPTM_IMR_TBTOIM_Pos                  8
#define LM3S_GPTM_IMR_TBTOIM_Msk                 (1UL << LM3S_GPTM_IMR_TBTOIM_Pos)

#define LM3S_GPTM_IMR_TAMIM_Pos                   4
#define LM3S_GPTM_IMR_TAMIM_Msk                  (1UL << LM3S_GPTM_IMR_TAMIM_Pos)

#define LM3S_GPTM_IMR_RTCIM_Pos                   3
#define LM3S_GPTM_IMR_RTCIM_Msk                  (1UL << LM3S_GPTM_IMR_RTCIM_Pos)

#define LM3S_GPTM_IMR_CAEIM_Pos                   2
#define LM3S_GPTM_IMR_CAEIM_Msk                  (1UL << LM3S_GPTM_IMR_CAEIM_Pos)

#define LM3S_GPTM_IMR_CAMIM_Pos                   1
#define LM3S_GPTM_IMR_CAMIM_Msk                  (1UL << LM3S_GPTM_IMR_CAMIM_Pos)

#define LM3S_GPTM_IMR_TATOIM_Pos                  0
#define LM3S_GPTM_IMR_TATOIM_Msk                 (1UL /*<< LM3S_GPTM_IMR_TATOIM_Pos*/)

/* LM3S_GPTM RIS Register Definitions */
#define LM3S_GPTM_RIS_TBMRIS_Pos                 11
#define LM3S_GPTM_RIS_TBMRIS_Msk                 (1UL << LM3S_GPTM_RIS_TBMRIS_Pos)

#define LM3S_GPTM_RIS_CBERIS_Pos                 10
#define LM3S_GPTM_RIS_CBERIS_Msk                 (1UL << LM3S_GPTM_RIS_CBERIS_Pos)

#define LM3S_GPTM_RIS_CBMRIS_Pos                  9
#define LM3S_GPTM_RIS_CBMRIS_Msk                 (1UL << LM3S_GPTM_RIS_CBMRIS_Pos)

#define LM3S_GPTM_RIS_TBTORIS_Pos                 8
#define LM3S_GPTM_RIS_TBTORIS_Msk                (1UL << LM3S_GPTM_RIS_TBTORIS_Pos)

#define LM3S_GPTM_RIS_TAMRIS_Pos                  4
#define LM3S_GPTM_RIS_TAMRIS_Msk                 (1UL << LM3S_GPTM_RIS_TAMRIS_Pos)

#define LM3S_GPTM_RIS_RTCRIS_Pos                  3
#define LM3S_GPTM_RIS_RTCRIS_Msk                 (1UL << LM3S_GPTM_RIS_RTCRIS_Pos)

#define LM3S_GPTM_RIS_CAERIS_Pos                  2
#define LM3S_GPTM_RIS_CAERIS_Msk                 (1UL << LM3S_GPTM_RIS_CAERIS_Pos)

#define LM3S_GPTM_RIS_CAMRIS_Pos                  1
#define LM3S_GPTM_RIS_CAMRIS_Msk                 (1UL << LM3S_GPTM_RIS_CAMRIS_Pos)

#define LM3S_GPTM_RIS_TATORIS_Pos                 0
#define LM3S_GPTM_RIS_TATORIS_Msk                (1UL /*<< LM3S_GPTM_RIS_TATORIS_Pos*/)

/* LM3S_GPTM MIS Register Definitions */
#define LM3S_GPTM_MIS_TBMMIS_Pos                 11
#define LM3S_GPTM_MIS_TBMMIS_Msk                 (1UL << LM3S_GPTM_MIS_TBMMIS_Pos)

#define LM3S_GPTM_MIS_CBEMIS_Pos                 10
#define LM3S_GPTM_MIS_CBEMIS_Msk                 (1UL << LM3S_GPTM_MIS_CBEMIS_Pos)

#define LM3S_GPTM_MIS_CBMMIS_Pos                  9
#define LM3S_GPTM_MIS_CBMMIS_Msk                 (1UL << LM3S_GPTM_MIS_CBMMIS_Pos)

#define LM3S_GPTM_MIS_TBTOMIS_Pos                 8
#define LM3S_GPTM_MIS_TBTOMIS_Msk                (1UL << LM3S_GPTM_MIS_TBTOMIS_Pos)

#define LM3S_GPTM_MIS_TAMMIS_Pos                  4
#define LM3S_GPTM_MIS_TAMMIS_Msk                 (1UL << LM3S_GPTM_MIS_TAMMIS_Pos)

#define LM3S_GPTM_MIS_RTCMIS_Pos                  3
#define LM3S_GPTM_MIS_RTCMIS_Msk                 (1UL << LM3S_GPTM_MIS_RTCMIS_Pos)

#define LM3S_GPTM_MIS_CAEMIS_Pos                  2
#define LM3S_GPTM_MIS_CAEMIS_Msk                 (1UL << LM3S_GPTM_MIS_CAEMIS_Pos)

#define LM3S_GPTM_MIS_CAMMIS_Pos                  1
#define LM3S_GPTM_MIS_CAMMIS_Msk                 (1UL << LM3S_GPTM_MIS_CAMMIS_Pos)

#define LM3S_GPTM_MIS_TATOMIS_Pos                 0
#define LM3S_GPTM_MIS_TATOMIS_Msk                (1UL /*<< LM3S_GPTM_MIS_TATOMIS_Pos*/)

/* LM3S_GPTM ICR Register Definitions */
#define LM3S_GPTM_ICR_TBMCINT_Pos                11
#define LM3S_GPTM_ICR_TBMCINT_Msk                (1UL << LM3S_GPTM_ICR_TBMCINT_Pos)

#define LM3S_GPTM_ICR_CBECINT_Pos                10
#define LM3S_GPTM_ICR_CBECINT_Msk                (1UL << LM3S_GPTM_ICR_CBECINT_Pos)

#define LM3S_GPTM_ICR_CBMCINT_Pos                 9
#define LM3S_GPTM_ICR_CBMCINT_Msk                (1UL << LM3S_GPTM_ICR_CBMCINT_Pos)

#define LM3S_GPTM_ICR_TBTOCINT_Pos                8
#define LM3S_GPTM_ICR_TBTOCINT_Msk               (1UL << LM3S_GPTM_ICR_TBTOCINT_Pos)

#define LM3S_GPTM_ICR_TAMCINT_Pos                 4
#define LM3S_GPTM_ICR_TAMCINT_Msk                (1UL << LM3S_GPTM_ICR_TAMCINT_Pos)

#define LM3S_GPTM_ICR_RTCCINT_Pos                 3
#define LM3S_GPTM_ICR_RTCCINT_Msk                (1UL << LM3S_GPTM_ICR_RTCCINT_Pos)

#define LM3S_GPTM_ICR_CAECINT_Pos                 2
#define LM3S_GPTM_ICR_CAECINT_Msk                (1UL << LM3S_GPTM_ICR_CAECINT_Pos)

#define LM3S_GPTM_ICR_CAMCINT_Pos                 1
#define LM3S_GPTM_ICR_CAMCINT_Msk                (1UL << LM3S_GPTM_ICR_CAMCINT_Pos)

#define LM3S_GPTM_ICR_TATOCINT_Pos                0
#define LM3S_GPTM_ICR_TATOCINT_Msk               (1UL /*<< LM3S_GPTM_ICR_TATOCINT_Pos*/)

/* LM3S_GPTM TAILR Register Definitions */
#define LM3S_GPTM_TAILR_TAILRH_Pos               16
#define LM3S_GPTM_TAILR_TAILRH_Msk               (0x0000FFFFUL << LM3S_GPTM_TAILR_TAILRH_Pos)

#define LM3S_GPTM_TAILR_TAILRL_Pos                0
#define LM3S_GPTM_TAILR_TAILRL_Msk               (0x0000FFFFUL /*<< LM3S_GPTM_TAILR_TAILRL_Pos*/)

/* LM3S_GPTM TBILR Register Definitions */
#define LM3S_GPTM_TBILR_TBILRL_Pos                0
#define LM3S_GPTM_TBILR_TBILRL_Msk               (0x0000FFFFUL /*<< LM3S_GPTM_TBILR_TBILRL_Pos*/)

/* LM3S_GPTM TAMATCHR Register Definitions */
#define LM3S_GPTM_TAMATCHR_TAMRH_Pos             16
#define LM3S_GPTM_TAMATCHR_TAMRH_Msk             (0x0000FFFFUL << LM3S_GPTM_TAMATCHR_TAMRH_Pos)

#define LM3S_GPTM_TAMATCHR_TAMRL_Pos              0
#define LM3S_GPTM_TAMATCHR_TAMRL_Msk             (0x0000FFFFUL /*<< LM3S_GPTM_TAMATCHR_TAMRL_Pos*/)

/* LM3S_GPTM TBMATCHR Register Definitions */
#define LM3S_GPTM_TBMATCHR_TBMRL_Pos              0
#define LM3S_GPTM_TBMATCHR_TBMRL_Msk             (0x0000FFFFUL /*<< LM3S_GPTM_TBMATCHR_TBMRL_Pos*/)

/* LM3S_GPTM TAPR Register Definitions */
#define LM3S_GPTM_TAPR_TAPSR_Pos                  0
#define LM3S_GPTM_TAPR_TAPSR_Msk                 (0x000000FFUL /*<< LM3S_GPTM_TAPR_TAPSR_Pos*/)

/* LM3S_GPTM TBPR Register Definitions */
#define LM3S_GPTM_TBPR_TBPSR_Pos                  0
#define LM3S_GPTM_TBPR_TBPSR_Msk                 (0x000000FFUL /*<< LM3S_GPTM_TBPR_TBPSR_Pos*/)

/* LM3S_GPTM TAPMR Register Definitions */
#define LM3S_GPTM_TAPMR_TAPSMR_Pos                0
#define LM3S_GPTM_TAPMR_TAPSMR_Msk               (0x000000FFUL /*<< LM3S_GPTM_TAPMR_TAPSMR_Pos*/)

/* LM3S_GPTM TBPMR Register Definitions */
#define LM3S_GPTM_TBPMR_TBPSMR_Pos                0
#define LM3S_GPTM_TBPMR_TBPSMR_Msk               (0x000000FFUL /*<< LM3S_GPTM_TBPMR_TBPSMR_Pos*/)

/* LM3S_GPTM TAR Register Definitions */
#define LM3S_GPTM_TAR_TARH_Pos                   16
#define LM3S_GPTM_TAR_TARH_Msk                   (0x000000FFUL << LM3S_GPTM_TAR_TARH_Pos)

#define LM3S_GPTM_TAR_TARL_Pos                    0
#define LM3S_GPTM_TAR_TARL_Msk                   (0x000000FFUL /*<< LM3S_GPTM_TAR_TARL_Pos*/)

/* LM3S_GPTM TBR Register Definitions */
#define LM3S_GPTM_TBR_TBRL_EDGE_Pos               0
#define LM3S_GPTM_TBR_TBRL_EDGE_Msk              (0x0000FFFFUL /*<< LM3S_GPTM_TBR_TBRL_EDGE_Pos*/)

#define LM3S_GPTM_TBR_TBRL_Pos                    0
#define LM3S_GPTM_TBR_TBRL_Msk                   (0x000000FFUL /*<< LM3S_GPTM_TBR_TBRL_Pos*/)

/* LM3S_GPTM TAV Register Definitions */
#define LM3S_GPTM_TAV_TAVH_Pos                   16
#define LM3S_GPTM_TAV_TAVH_Msk                   (0x000000FFUL << LM3S_GPTM_TAV_TAVH_Pos)

#define LM3S_GPTM_TAV_TAVL_Pos                    0
#define LM3S_GPTM_TAV_TAVL_Msk                   (0x000000FFUL /*<< LM3S_GPTM_TAV_TAVL_Pos*/)

/* LM3S_GPTM TBV Register Definitions */
#define LM3S_GPTM_TBV_TBVL_Pos                    0
#define LM3S_GPTM_TBV_TBVL_Msk                   (0x000000FFUL /*<< LM3S_GPTM_TBV_TBVL_Pos*/)

/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  ACTSS;                /* Offset: 0x000 (R/W) Active Sample Sequencer Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x004 (R/ ) Raw Interrupt Status Register */
  __IOM uint32_t  IM;                   /* Offset: 0x008 (R/W) Interrupt Mask Register */
  __IOM uint32_t  ISC;                  /* Offset: 0x00C (R/W) Interrupt Status and Clear Register */
  __IOM uint32_t  OSTAT;                /* Offset: 0x010 (R/W) Overflow Status Register */
  __IOM uint32_t  EMUX;                 /* Offset: 0x014 (R/W) Event Multiplexer Select Register */
  __IOM uint32_t  USTAT;                /* Offset: 0x018 (R/W) Underflow Status Register */
  __IM  uint32_t  RESERVED0;
  __IOM uint32_t  SSPRI;                /* Offset: 0x020 (R/W) Sample Sequencer Priority Register */
  __IOM uint32_t  SPC;                  /* Offset: 0x024 (R/W) Sample Phase Control Register */
  __IOM uint32_t  PSSI;                 /* Offset: 0x028 (R/W) Processor Sample Sequence Initiate Register */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  SAC;                  /* Offset: 0x030 (R/W) Sample Averaging Control Register */
  __IOM uint32_t  DCISC;                /* Offset: 0x034 (R/W) Digital Comparator Interrupt Status and Clear Register */
  __IOM uint32_t  CTL;                  /* Offset: 0x038 (R/W) Control Register */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  SSMUX0;               /* Offset: 0x040 (R/W) Sample Sequence Input Multiplexer Select 0 Register */
  __IOM uint32_t  SSCTL0;               /* Offset: 0x044 (R/W) Sample Sequence Control 0 Register */
  __IM  uint32_t  SSFIFO0;              /* Offset: 0x048 (R/ ) Sample Sequence Result FIFO 0 Register */
  __IOM uint32_t  SSFSTAT0;             /* Offset: 0x04C (R/W) Sample Sequence FIFO 0 Status Register */
  __IOM uint32_t  SSOP0;                /* Offset: 0x050 (R/W) Sample Sequence 0 Operation Register */
  __IOM uint32_t  SSDC0;                /* Offset: 0x054 (R/W) Sample Sequence 0 Digital Comparator Select Register */
  __IM  uint32_t  RESERVED3[2];
  __IOM uint32_t  SSMUX1;               /* Offset: 0x060 (R/W) Sample Sequence Input Multiplexer Select 1 Register */
  __IOM uint32_t  SSCTL1;               /* Offset: 0x064 (R/W) Sample Sequence Control 1 Register */
  __IM  uint32_t  SSFIFO1;              /* Offset: 0x068 (R/ ) Sample Sequence Result FIFO 1 Register */
  __IM  uint32_t  SSFSTAT1;             /* Offset: 0x06C (R/ ) Sample Sequence FIFO 1 Status Register */
  __IOM uint32_t  SSOP1;                /* Offset: 0x070 (R/W) Sample Sequence 1 Operation Register */
  __IOM uint32_t  SSDC1;                /* Offset: 0x074 (R/W) Sample Sequence 1 Digital Comparator Select Register */
  __IM  uint32_t  RESERVED4[2];
  __IOM uint32_t  SSMUX2;               /* Offset: 0x080 (R/W) Sample Sequence Input Multiplexer Select 2 Register */
  __IOM uint32_t  SSCTL2;               /* Offset: 0x084 (R/W) Sample Sequence Control 2 Register */
  __IM  uint32_t  SSFIFO2;              /* Offset: 0x088 (R/ ) Sample Sequence Result FIFO 2 Register */
  __IM  uint32_t  SSFSTAT2;             /* Offset: 0x08C (R/ ) Sample Sequence FIFO 2 Status Register */
  __IOM uint32_t  SSOP2;                /* Offset: 0x090 (R/W) Sample Sequence 2 Operation Register */
  __IOM uint32_t  SSDC2;                /* Offset: 0x094 (R/W) Sample Sequence 2 Digital Comparator Select Register */
  __IM  uint32_t  RESERVED5;
  __IOM uint32_t  SSMUX3;               /* Offset: 0x0A0 (R/W) Sample Sequence Input Multiplexer Select 3 Register */
  __IOM uint32_t  SSCTL3;               /* Offset: 0x0A4 (R/W) Sample Sequence Control 3 Register */
  __IM  uint32_t  SSFIFO3;              /* Offset: 0x0A8 (R/ ) Sample Sequence Result FIFO 3 Register */
  __IM  uint32_t  SSFSTAT3;             /* Offset: 0x0AC (R/ ) Sample Sequence FIFO 3 Status Register */
  __IOM uint32_t  SSOP3;                /* Offset: 0x0B0 (R/W) Sample Sequence 3 Operation Register */
  __IOM uint32_t  SSDC3;                /* Offset: 0x0B4 (R/W) Sample Sequence 3 Digital Comparator Select Register */
  __IOM uint32_t  DCRIC;                /* Offset: 0xD00 (R/W) Digital Comparator Reset Initial Conditions Register */
  __IM  uint32_t  RESERVED6[63];
  __IOM uint32_t  DCCTL0;               /* Offset: 0xE00 (R/W) Digital Comparator Control 0 Register */
  __IOM uint32_t  DCCTL1;               /* Offset: 0xE04 (R/W) Digital Comparator Control 1 Register */
  __IOM uint32_t  DCCTL2;               /* Offset: 0xE08 (R/W) Digital Comparator Control 2 Register */
  __IOM uint32_t  DCCTL3;               /* Offset: 0xE0C (R/W) Digital Comparator Control 3 Register */
  __IOM uint32_t  DCCTL4;               /* Offset: 0xE10 (R/W) Digital Comparator Control 4 Register */
  __IOM uint32_t  DCCTL5;               /* Offset: 0xE14 (R/W) Digital Comparator Control 5 Register */
  __IOM uint32_t  DCCTL6;               /* Offset: 0xE18 (R/W) Digital Comparator Control 6 Register */
  __IOM uint32_t  DCCTL7;               /* Offset: 0xE1C (R/W) Digital Comparator Control 7 Register */
  __IM  uint32_t  RESERVED7[8];
  __IOM uint32_t  DCCMP0;               /* Offset: 0xE40 (R/W) Digital Comparator Range 0 Register */
  __IOM uint32_t  DCCMP1;               /* Offset: 0xE44 (R/W) Digital Comparator Range 1 Register */
  __IOM uint32_t  DCCMP2;               /* Offset: 0xE48 (R/W) Digital Comparator Range 2 Register */
  __IOM uint32_t  DCCMP3;               /* Offset: 0xE4C (R/W) Digital Comparator Range 3 Register */
  __IOM uint32_t  DCCMP4;               /* Offset: 0xE50 (R/W) Digital Comparator Range 4 Register */
  __IOM uint32_t  DCCMP5;               /* Offset: 0xE54 (R/W) Digital Comparator Range 5 Register */
  __IOM uint32_t  DCCMP6;               /* Offset: 0xE58 (R/W) Digital Comparator Range 6 Register */
  __IOM uint32_t  DCCMP7;               /* Offset: 0xE5C (R/W) Digital Comparator Range 7 Register */
} LM3S_ADC_TypeDef;

/* LM3S_ADC ACTSS Register Definitions */
#define LM3S_ADC_ACTSS_ASEN3_Pos                  3
#define LM3S_ADC_ACTSS_ASEN3_Msk                 (1UL << LM3S_ADC_ACTSS_ASEN3_Pos)

#define LM3S_ADC_ACTSS_ASEN2_Pos                  2
#define LM3S_ADC_ACTSS_ASEN2_Msk                 (1UL << LM3S_ADC_ACTSS_ASEN2_Pos)

#define LM3S_ADC_ACTSS_ASEN1_Pos                  1
#define LM3S_ADC_ACTSS_ASEN1_Msk                 (1UL << LM3S_ADC_ACTSS_ASEN1_Pos)

#define LM3S_ADC_ACTSS_ASEN0_Pos                  0
#define LM3S_ADC_ACTSS_ASEN0_Msk                 (1UL /*<< LM3S_ADC_ACTSS_ASEN0_Pos*/)

/* LM3S_ADC RIS Register Definitions */
#define LM3S_ADC_RIS_INRDC_Pos                   16
#define LM3S_ADC_RIS_INRDC_Msk                   (1UL << LM3S_ADC_RIS_INRDC_Pos)

#define LM3S_ADC_RIS_INR3_Pos                     3
#define LM3S_ADC_RIS_INR3_Msk                    (1UL << LM3S_ADC_RIS_INR3_Pos)

#define LM3S_ADC_RIS_INR2_Pos                     2
#define LM3S_ADC_RIS_INR2_Msk                    (1UL << LM3S_ADC_RIS_INR2_Pos)

#define LM3S_ADC_RIS_INR1_Pos                     1
#define LM3S_ADC_RIS_INR1_Msk                    (1UL << LM3S_ADC_RIS_INR1_Pos)

#define LM3S_ADC_RIS_INR0_Pos                     0
#define LM3S_ADC_RIS_INR0_Msk                    (1UL /*<< LM3S_ADC_RIS_INR0_Pos*/)

/* LM3S_ADC IM Register Definitions */
#define LM3S_ADC_IM_DCONSS3_Pos                  19
#define LM3S_ADC_IM_DCONSS3_Msk                  (1UL << LM3S_ADC_IM_DCONSS3_Pos)

#define LM3S_ADC_IM_DCONSS2_Pos                  18
#define LM3S_ADC_IM_DCONSS2_Msk                  (1UL << LM3S_ADC_IM_DCONSS2_Pos)

#define LM3S_ADC_IM_DCONSS1_Pos                  17
#define LM3S_ADC_IM_DCONSS1_Msk                  (1UL << LM3S_ADC_IM_DCONSS1_Pos)

#define LM3S_ADC_IM_DCONSS0_Pos                  16
#define LM3S_ADC_IM_DCONSS0_Msk                  (1UL << LM3S_ADC_IM_DCONSS0_Pos)

#define LM3S_ADC_IM_MASK3_Pos                     3
#define LM3S_ADC_IM_MASK3_Msk                    (1UL << LM3S_ADC_IM_MASK3_Pos)

#define LM3S_ADC_IM_MASK2_Pos                     2
#define LM3S_ADC_IM_MASK2_Msk                    (1UL << LM3S_ADC_IM_MASK2_Pos)

#define LM3S_ADC_IM_MASK1_Pos                     1
#define LM3S_ADC_IM_MASK1_Msk                    (1UL << LM3S_ADC_IM_MASK1_Pos)

#define LM3S_ADC_IM_MASK0_Pos                     0
#define LM3S_ADC_IM_MASK0_Msk                    (1UL /*<< LM3S_ADC_IM_MASK0_Pos*/)

/* LM3S_ADC ISC Register Definitions */
#define LM3S_ADC_ISC_DCINSS3_Pos                 19
#define LM3S_ADC_ISC_DCINSS3_Msk                 (1UL << LM3S_ADC_ISC_DCINSS3_Pos)

#define LM3S_ADC_ISC_DCINSS2_Pos                 18
#define LM3S_ADC_ISC_DCINSS2_Msk                 (1UL << LM3S_ADC_ISC_DCINSS2_Pos)

#define LM3S_ADC_ISC_DCINSS1_Pos                 17
#define LM3S_ADC_ISC_DCINSS1_Msk                 (1UL << LM3S_ADC_ISC_DCINSS1_Pos)

#define LM3S_ADC_ISC_DCINSS0_Pos                 16
#define LM3S_ADC_ISC_DCINSS0_Msk                 (1UL << LM3S_ADC_ISC_DCINSS0_Pos)

#define LM3S_ADC_ISC_IN3_Pos                      3
#define LM3S_ADC_ISC_IN3_Msk                     (1UL << LM3S_ADC_ISC_IN3_Pos)

#define LM3S_ADC_ISC_IN2_Pos                      2
#define LM3S_ADC_ISC_IN2_Msk                     (1UL << LM3S_ADC_ISC_IN2_Pos)

#define LM3S_ADC_ISC_IN1_Pos                      1
#define LM3S_ADC_ISC_IN1_Msk                     (1UL << LM3S_ADC_ISC_IN1_Pos)

#define LM3S_ADC_ISC_IN0_Pos                      0
#define LM3S_ADC_ISC_IN0_Msk                     (1UL /*<< LM3S_ADC_ISC_IN0_Pos*/)

/* LM3S_ADC OSTAT Register Definitions */
#define LM3S_ADC_OSTAT_OV3_Pos                    3
#define LM3S_ADC_OSTAT_OV3_Msk                   (1UL << LM3S_ADC_OSTAT_OV3_Pos)

#define LM3S_ADC_OSTAT_OV2_Pos                    2
#define LM3S_ADC_OSTAT_OV2_Msk                   (1UL << LM3S_ADC_OSTAT_OV2_Pos)

#define LM3S_ADC_OSTAT_OV1_Pos                    1
#define LM3S_ADC_OSTAT_OV1_Msk                   (1UL << LM3S_ADC_OSTAT_OV1_Pos)

#define LM3S_ADC_OSTAT_OV0_Pos                    0
#define LM3S_ADC_OSTAT_OV0_Msk                   (1UL /*<< LM3S_ADC_OSTAT_OV0_Pos*/)

/* LM3S_ADC EMUX Register Definitions */
#define LM3S_ADC_EMUX_EM3_Pos                    12
#define LM3S_ADC_EMUX_EM3_Msk                    (0x0000000FUL << LM3S_ADC_EMUX_EM3_Pos)
#define LM3S_ADC_EMUX_EM3_3_Pos                  15
#define LM3S_ADC_EMUX_EM3_3_Msk                  (1UL << LM3S_ADC_EMUX_EM3_3_Pos)
#define LM3S_ADC_EMUX_EM3_2_Pos                  14
#define LM3S_ADC_EMUX_EM3_2_Msk                  (1UL << LM3S_ADC_EMUX_EM3_2_Pos)
#define LM3S_ADC_EMUX_EM3_1_Pos                  13
#define LM3S_ADC_EMUX_EM3_1_Msk                  (1UL << LM3S_ADC_EMUX_EM3_1_Pos)
#define LM3S_ADC_EMUX_EM3_0_Pos                  12
#define LM3S_ADC_EMUX_EM3_0_Msk                  (1UL << LM3S_ADC_EMUX_EM3_0_Pos)

#define LM3S_ADC_EMUX_EM2_Pos                     8
#define LM3S_ADC_EMUX_EM2_Msk                    (0x0000000FUL << LM3S_ADC_EMUX_EM2_Pos)
#define LM3S_ADC_EMUX_EM2_3_Pos                  11
#define LM3S_ADC_EMUX_EM2_3_Msk                  (1UL << LM3S_ADC_EMUX_EM2_3_Pos)
#define LM3S_ADC_EMUX_EM2_2_Pos                  10
#define LM3S_ADC_EMUX_EM2_2_Msk                  (1UL << LM3S_ADC_EMUX_EM2_2_Pos)
#define LM3S_ADC_EMUX_EM2_1_Pos                   9
#define LM3S_ADC_EMUX_EM2_1_Msk                  (1UL << LM3S_ADC_EMUX_EM2_1_Pos)
#define LM3S_ADC_EMUX_EM2_0_Pos                   8
#define LM3S_ADC_EMUX_EM2_0_Msk                  (1UL << LM3S_ADC_EMUX_EM2_0_Pos)

#define LM3S_ADC_EMUX_EM1_Pos                     4
#define LM3S_ADC_EMUX_EM1_Msk                    (0x0000000FUL << LM3S_ADC_EMUX_EM1_Pos)
#define LM3S_ADC_EMUX_EM1_3_Pos                   7
#define LM3S_ADC_EMUX_EM1_3_Msk                  (1UL << LM3S_ADC_EMUX_EM1_3_Pos)
#define LM3S_ADC_EMUX_EM1_2_Pos                   6
#define LM3S_ADC_EMUX_EM1_2_Msk                  (1UL << LM3S_ADC_EMUX_EM1_2_Pos)
#define LM3S_ADC_EMUX_EM1_1_Pos                   5
#define LM3S_ADC_EMUX_EM1_1_Msk                  (1UL << LM3S_ADC_EMUX_EM1_1_Pos)
#define LM3S_ADC_EMUX_EM1_0_Pos                   4
#define LM3S_ADC_EMUX_EM1_0_Msk                  (1UL << LM3S_ADC_EMUX_EM1_0_Pos)

#define LM3S_ADC_EMUX_EM0_Pos                     0
#define LM3S_ADC_EMUX_EM0_Msk                    (0x0000000FUL /*<< LM3S_ADC_EMUX_EM0_Pos*/)
#define LM3S_ADC_EMUX_EM0_3_Pos                   3
#define LM3S_ADC_EMUX_EM0_3_Msk                  (1UL << LM3S_ADC_EMUX_EM0_3_Pos)
#define LM3S_ADC_EMUX_EM0_2_Pos                   2
#define LM3S_ADC_EMUX_EM0_2_Msk                  (1UL << LM3S_ADC_EMUX_EM0_2_Pos)
#define LM3S_ADC_EMUX_EM0_1_Pos                   1
#define LM3S_ADC_EMUX_EM0_1_Msk                  (1UL << LM3S_ADC_EMUX_EM0_1_Pos)
#define LM3S_ADC_EMUX_EM0_0_Pos                   0
#define LM3S_ADC_EMUX_EM0_0_Msk                  (1UL /*<< LM3S_ADC_EMUX_EM0_0_Pos*/)

/* LM3S_ADC USTAT Register Definitions */
#define LM3S_ADC_USTAT_UV3_Pos                    3
#define LM3S_ADC_USTAT_UV3_Msk                   (1UL << LM3S_ADC_USTAT_UV3_Pos)

#define LM3S_ADC_USTAT_UV2_Pos                    2
#define LM3S_ADC_USTAT_UV2_Msk                   (1UL << LM3S_ADC_USTAT_UV2_Pos)

#define LM3S_ADC_USTAT_UV1_Pos                    1
#define LM3S_ADC_USTAT_UV1_Msk                   (1UL << LM3S_ADC_USTAT_UV1_Pos)

#define LM3S_ADC_USTAT_UV0_Pos                    0
#define LM3S_ADC_USTAT_UV0_Msk                   (1UL /*<< LM3S_ADC_USTAT_UV0_Pos*/)

/* LM3S_ADC SSPRI Register Definitions */
#define LM3S_ADC_SSPRI_SS3_Pos                   12
#define LM3S_ADC_SSPRI_SS3_Msk                   (0x00000003UL << LM3S_ADC_SSPRI_SS3_Pos)
#define LM3S_ADC_SSPRI_SS3_1_Pos                 13
#define LM3S_ADC_SSPRI_SS3_1_Msk                 (1UL << LM3S_ADC_SSPRI_SS3_1_Pos)
#define LM3S_ADC_SSPRI_SS3_0_Pos                 12
#define LM3S_ADC_SSPRI_SS3_0_Msk                 (1UL << LM3S_ADC_SSPRI_SS3_0_Pos)

#define LM3S_ADC_SSPRI_SS2_Pos                    8
#define LM3S_ADC_SSPRI_SS2_Msk                   (0x00000003UL << LM3S_ADC_SSPRI_SS2_Pos)
#define LM3S_ADC_SSPRI_SS2_1_Pos                  9
#define LM3S_ADC_SSPRI_SS2_1_Msk                 (1UL << LM3S_ADC_SSPRI_SS2_1_Pos)
#define LM3S_ADC_SSPRI_SS2_0_Pos                  8
#define LM3S_ADC_SSPRI_SS2_0_Msk                 (1UL << LM3S_ADC_SSPRI_SS2_0_Pos)

#define LM3S_ADC_SSPRI_SS1_Pos                    4
#define LM3S_ADC_SSPRI_SS1_Msk                   (0x00000003UL << LM3S_ADC_SSPRI_SS1_Pos)
#define LM3S_ADC_SSPRI_SS1_1_Pos                  5
#define LM3S_ADC_SSPRI_SS1_1_Msk                 (1UL << LM3S_ADC_SSPRI_SS1_1_Pos)
#define LM3S_ADC_SSPRI_SS1_0_Pos                  4
#define LM3S_ADC_SSPRI_SS1_0_Msk                 (1UL << LM3S_ADC_SSPRI_SS1_0_Pos)

#define LM3S_ADC_SSPRI_SS0_Pos                    0
#define LM3S_ADC_SSPRI_SS0_Msk                   (0x00000003UL /*<< LM3S_ADC_SSPRI_SS0_Pos*/)
#define LM3S_ADC_SSPRI_SS0_1_Pos                  1
#define LM3S_ADC_SSPRI_SS0_1_Msk                 (1UL << LM3S_ADC_SSPRI_SS0_1_Pos)
#define LM3S_ADC_SSPRI_SS0_0_Pos                  0
#define LM3S_ADC_SSPRI_SS0_0_Msk                 (1UL /*<< LM3S_ADC_SSPRI_SS0_0_Pos*/)

/* LM3S_ADC SPC Register Definitions */
#define LM3S_ADC_SPC_PHASE_Pos                    0
#define LM3S_ADC_SPC_PHASE_Msk                   (0x0000000FUL /*<< LM3S_ADC_SPC_PHASE_Pos*/)
#define LM3S_ADC_SPC_PHASE_3_Pos                  3
#define LM3S_ADC_SPC_PHASE_3_Msk                 (1UL << LM3S_ADC_SPC_PHASE_2_Pos)
#define LM3S_ADC_SPC_PHASE_2_Pos                  2
#define LM3S_ADC_SPC_PHASE_2_Msk                 (1UL << LM3S_ADC_SPC_PHASE_2_Pos)
#define LM3S_ADC_SPC_PHASE_1_Pos                  1
#define LM3S_ADC_SPC_PHASE_1_Msk                 (1UL << LM3S_ADC_SPC_PHASE_1_Pos)
#define LM3S_ADC_SPC_PHASE_0_Pos                  0
#define LM3S_ADC_SPC_PHASE_0_Msk                 (1UL /*<< LM3S_ADC_SPC_PHASE_0_Pos*/)

/* LM3S_ADC PSSI Register Definitions */
#define LM3S_ADC_PSSI_GSYNC_Pos                  31
#define LM3S_ADC_PSSI_GSYNC_Msk                  (1UL << LM3S_ADC_PSSI_GSYNC_Pos)

#define LM3S_ADC_PSSI_SYNCWAIT_Pos               27
#define LM3S_ADC_PSSI_SYNCWAIT_Msk               (1UL << LM3S_ADC_PSSI_SYNCWAIT_Pos)

#define LM3S_ADC_PSSI_SS3_Pos                     3
#define LM3S_ADC_PSSI_SS3_Msk                    (1UL << LM3S_ADC_PSSI_SS3_Pos)

#define LM3S_ADC_PSSI_SS2_Pos                     2
#define LM3S_ADC_PSSI_SS2_Msk                    (1UL << LM3S_ADC_PSSI_SS2_Pos)

#define LM3S_ADC_PSSI_SS1_Pos                     1
#define LM3S_ADC_PSSI_SS1_Msk                    (1UL << LM3S_ADC_PSSI_SS1_Pos)

#define LM3S_ADC_PSSI_SS0_Pos                     0
#define LM3S_ADC_PSSI_SS0_Msk                    (1UL /*<< LM3S_ADC_PSSI_SS0_Pos*/)

/* LM3S_ADC SAC Register Definitions */
#define LM3S_ADC_SAC_AVG_Pos                      0
#define LM3S_ADC_SAC_AVG_Msk                     (0x00000007UL /*<< LM3S_ADC_SAC_AVG_Pos*/)
#define LM3S_ADC_SAC_AVG_2_Pos                    2
#define LM3S_ADC_SAC_AVG_2_Msk                   (1UL << LM3S_ADC_SAC_AVG_2_Pos)
#define LM3S_ADC_SAC_AVG_1_Pos                    1
#define LM3S_ADC_SAC_AVG_1_Msk                   (1UL << LM3S_ADC_SAC_AVG_1_Pos)
#define LM3S_ADC_SAC_AVG_0_Pos                    0
#define LM3S_ADC_SAC_AVG_0_Msk                   (1UL /*<< LM3S_ADC_SAC_AVG_0_Pos*/)

/* LM3S_ADC DCISC Register Definitions */
#define LM3S_ADC_DCISC_DCINT7_Pos                 7
#define LM3S_ADC_DCISC_DCINT7_Msk                (1UL << LM3S_ADC_DCISC_DCINT7_Pos)

#define LM3S_ADC_DCISC_DCINT6_Pos                 6
#define LM3S_ADC_DCISC_DCINT6_Msk                (1UL << LM3S_ADC_DCISC_DCINT6_Pos)

#define LM3S_ADC_DCISC_DCINT5_Pos                 5
#define LM3S_ADC_DCISC_DCINT5_Msk                (1UL << LM3S_ADC_DCISC_DCINT5_Pos)

#define LM3S_ADC_DCISC_DCINT4_Pos                 4
#define LM3S_ADC_DCISC_DCINT4_Msk                (1UL << LM3S_ADC_DCISC_DCINT4_Pos)

#define LM3S_ADC_DCISC_DCINT3_Pos                 3
#define LM3S_ADC_DCISC_DCINT3_Msk                (1UL << LM3S_ADC_DCISC_DCINT3_Pos)

#define LM3S_ADC_DCISC_DCINT2_Pos                 2
#define LM3S_ADC_DCISC_DCINT2_Msk                (1UL << LM3S_ADC_DCISC_DCINT2_Pos)

#define LM3S_ADC_DCISC_DCINT1_Pos                 1
#define LM3S_ADC_DCISC_DCINT1_Msk                (1UL << LM3S_ADC_DCISC_DCINT1_Pos)

#define LM3S_ADC_DCISC_DCINT0_Pos                 0
#define LM3S_ADC_DCISC_DCINT0_Msk                (1UL /*<< LM3S_ADC_DCISC_DCINT0_Pos*/)

/* LM3S_ADC CTL Register Definitions */
#define LM3S_ADC_CTL_VREF_Pos                     0
#define LM3S_ADC_CTL_VREF_Msk                    (1UL /*<< LM3S_ADC_CTL_DCINT7_Pos*/)

/* LM3S_ADC SSMUX0 Register Definitions */
#define LM3S_ADC_SSMUX0_MUX7_Pos                 28
#define LM3S_ADC_SSMUX0_MUX7_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX0_MUX7_Pos)
#define LM3S_ADC_SSMUX0_MUX7_3_Pos               31
#define LM3S_ADC_SSMUX0_MUX7_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX7_3_Pos)
#define LM3S_ADC_SSMUX0_MUX7_2_Pos               30
#define LM3S_ADC_SSMUX0_MUX7_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX7_2_Pos)
#define LM3S_ADC_SSMUX0_MUX7_1_Pos               29
#define LM3S_ADC_SSMUX0_MUX7_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX7_1_Pos)
#define LM3S_ADC_SSMUX0_MUX7_0_Pos               28
#define LM3S_ADC_SSMUX0_MUX7_0_Msk               (1UL << LM3S_ADC_SSMUX0_MUX7_0_Pos)

#define LM3S_ADC_SSMUX0_MUX6_Pos                 24
#define LM3S_ADC_SSMUX0_MUX6_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX0_MUX6_Pos)
#define LM3S_ADC_SSMUX0_MUX6_3_Pos               27
#define LM3S_ADC_SSMUX0_MUX6_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX6_3_Pos)
#define LM3S_ADC_SSMUX0_MUX6_2_Pos               26
#define LM3S_ADC_SSMUX0_MUX6_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX6_2_Pos)
#define LM3S_ADC_SSMUX0_MUX6_1_Pos               25
#define LM3S_ADC_SSMUX0_MUX6_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX6_1_Pos)
#define LM3S_ADC_SSMUX0_MUX6_0_Pos               24
#define LM3S_ADC_SSMUX0_MUX6_0_Msk               (1UL << LM3S_ADC_SSMUX0_MUX6_0_Pos)

#define LM3S_ADC_SSMUX0_MUX5_Pos                 20
#define LM3S_ADC_SSMUX0_MUX5_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX0_MUX5_Pos)
#define LM3S_ADC_SSMUX0_MUX5_3_Pos               23
#define LM3S_ADC_SSMUX0_MUX5_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX5_3_Pos)
#define LM3S_ADC_SSMUX0_MUX5_2_Pos               22
#define LM3S_ADC_SSMUX0_MUX5_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX5_2_Pos)
#define LM3S_ADC_SSMUX0_MUX5_1_Pos               21
#define LM3S_ADC_SSMUX0_MUX5_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX5_1_Pos)
#define LM3S_ADC_SSMUX0_MUX5_0_Pos               20
#define LM3S_ADC_SSMUX0_MUX5_0_Msk               (1UL << LM3S_ADC_SSMUX0_MUX5_0_Pos)

#define LM3S_ADC_SSMUX0_MUX4_Pos                 16
#define LM3S_ADC_SSMUX0_MUX4_Msk                      (0x0000000FUL << LM3S_ADC_SSMUX0_MUX4_Pos)
#define LM3S_ADC_SSMUX0_MUX4_3_Pos               19
#define LM3S_ADC_SSMUX0_MUX4_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX4_3_Pos)
#define LM3S_ADC_SSMUX0_MUX4_2_Pos               18
#define LM3S_ADC_SSMUX0_MUX4_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX4_2_Pos)
#define LM3S_ADC_SSMUX0_MUX4_1_Pos               17
#define LM3S_ADC_SSMUX0_MUX4_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX4_1_Pos)
#define LM3S_ADC_SSMUX0_MUX4_0_Pos               16
#define LM3S_ADC_SSMUX0_MUX4_0_Msk               (1UL << LM3S_ADC_SSMUX0_MUX4_0_Pos)

#define LM3S_ADC_SSMUX0_MUX3_Pos                 12
#define LM3S_ADC_SSMUX0_MUX3_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX0_MUX3_Pos)
#define LM3S_ADC_SSMUX0_MUX3_3_Pos               15
#define LM3S_ADC_SSMUX0_MUX3_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX3_3_Pos)
#define LM3S_ADC_SSMUX0_MUX3_2_Pos               14
#define LM3S_ADC_SSMUX0_MUX3_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX3_2_Pos)
#define LM3S_ADC_SSMUX0_MUX3_1_Pos               13
#define LM3S_ADC_SSMUX0_MUX3_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX3_1_Pos)
#define LM3S_ADC_SSMUX0_MUX3_0_Pos               12
#define LM3S_ADC_SSMUX0_MUX3_0_Msk               (1UL << LM3S_ADC_SSMUX0_MUX3_0_Pos)

#define LM3S_ADC_SSMUX0_MUX2_Pos                  8
#define LM3S_ADC_SSMUX0_MUX2_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX0_MUX2_Pos)
#define LM3S_ADC_SSMUX0_MUX2_3_Pos               11
#define LM3S_ADC_SSMUX0_MUX2_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX2_3_Pos)
#define LM3S_ADC_SSMUX0_MUX2_2_Pos               10
#define LM3S_ADC_SSMUX0_MUX2_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX2_2_Pos)
#define LM3S_ADC_SSMUX0_MUX2_1_Pos                9
#define LM3S_ADC_SSMUX0_MUX2_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX2_1_Pos)
#define LM3S_ADC_SSMUX0_MUX2_0_Pos                8
#define LM3S_ADC_SSMUX0_MUX2_0_Msk               (1UL << LM3S_ADC_SSMUX0_MUX2_0_Pos)

#define LM3S_ADC_SSMUX0_MUX1_Pos                  4
#define LM3S_ADC_SSMUX0_MUX1_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX0_MUX1_Pos)
#define LM3S_ADC_SSMUX0_MUX1_3_Pos                7
#define LM3S_ADC_SSMUX0_MUX1_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX1_3_Pos)
#define LM3S_ADC_SSMUX0_MUX1_2_Pos                6
#define LM3S_ADC_SSMUX0_MUX1_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX1_2_Pos)
#define LM3S_ADC_SSMUX0_MUX1_1_Pos                5
#define LM3S_ADC_SSMUX0_MUX1_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX1_1_Pos)
#define LM3S_ADC_SSMUX0_MUX1_0_Pos                4
#define LM3S_ADC_SSMUX0_MUX1_0_Msk               (1UL << LM3S_ADC_SSMUX0_MUX1_0_Pos)

#define LM3S_ADC_SSMUX0_MUX0_Pos                  0
#define LM3S_ADC_SSMUX0_MUX0_Msk                 (0x0000000FUL /*<< LM3S_ADC_SSMUX0_MUX0_Pos*/)
#define LM3S_ADC_SSMUX0_MUX0_3_Pos                3
#define LM3S_ADC_SSMUX0_MUX0_3_Msk               (1UL << LM3S_ADC_SSMUX0_MUX0_3_Pos)
#define LM3S_ADC_SSMUX0_MUX0_2_Pos                2
#define LM3S_ADC_SSMUX0_MUX0_2_Msk               (1UL << LM3S_ADC_SSMUX0_MUX0_2_Pos)
#define LM3S_ADC_SSMUX0_MUX0_1_Pos                1
#define LM3S_ADC_SSMUX0_MUX0_1_Msk               (1UL << LM3S_ADC_SSMUX0_MUX0_1_Pos)
#define LM3S_ADC_SSMUX0_MUX0_0_Pos                0
#define LM3S_ADC_SSMUX0_MUX0_0_Msk               (1UL /*<< LM3S_ADC_SSMUX0_MUX0_0_Pos*/)

/* LM3S_ADC SSCTL0 Register Definitions */
#define LM3S_ADC_SSCTL0_TS7_Pos                  31
#define LM3S_ADC_SSCTL0_TS7_Msk                  (1UL << LM3S_ADC_SSCTL0_TS7_Pos)

#define LM3S_ADC_SSCTL0_IE7_Pos                  30
#define LM3S_ADC_SSCTL0_IE7_Msk                  (1UL << LM3S_ADC_SSCTL0_IE7_Pos)

#define LM3S_ADC_SSCTL0_END7_Pos                 29
#define LM3S_ADC_SSCTL0_END7_Msk                 (1UL << LM3S_ADC_SSCTL0_END7_Pos)

#define LM3S_ADC_SSCTL0_D7_Pos                   28
#define LM3S_ADC_SSCTL0_D7_Msk                   (1UL << LM3S_ADC_SSCTL0_D7_Pos)

#define LM3S_ADC_SSCTL0_TS6_Pos                  27
#define LM3S_ADC_SSCTL0_TS6_Msk                  (1UL << LM3S_ADC_SSCTL0_TS6_Pos)

#define LM3S_ADC_SSCTL0_IE6_Pos                  26
#define LM3S_ADC_SSCTL0_IE6_Msk                  (1UL << LM3S_ADC_SSCTL0_IE6_Pos)

#define LM3S_ADC_SSCTL0_END6_Pos                 25
#define LM3S_ADC_SSCTL0_END6_Msk                 (1UL << LM3S_ADC_SSCTL0_END6_Pos)

#define LM3S_ADC_SSCTL0_D6_Pos                   24
#define LM3S_ADC_SSCTL0_D6_Msk                   (1UL << LM3S_ADC_SSCTL0_D6_Pos)

#define LM3S_ADC_SSCTL0_TS5_Pos                  23
#define LM3S_ADC_SSCTL0_TS5_Msk                  (1UL << LM3S_ADC_SSCTL0_TS5_Pos)

#define LM3S_ADC_SSCTL0_IE5_Pos                  22
#define LM3S_ADC_SSCTL0_IE5_Msk                  (1UL << LM3S_ADC_SSCTL0_IE5_Pos)

#define LM3S_ADC_SSCTL0_END5_Pos                 21
#define LM3S_ADC_SSCTL0_END5_Msk                 (1UL << LM3S_ADC_SSCTL0_END5_Pos)

#define LM3S_ADC_SSCTL0_D5_Pos                   20
#define LM3S_ADC_SSCTL0_D5_Msk                   (1UL << LM3S_ADC_SSCTL0_D5_Pos)

#define LM3S_ADC_SSCTL0_TS4_Pos                  19
#define LM3S_ADC_SSCTL0_TS4_Msk                  (1UL << LM3S_ADC_SSCTL0_TS4_Pos)

#define LM3S_ADC_SSCTL0_IE4_Pos                  18
#define LM3S_ADC_SSCTL0_IE4_Msk                  (1UL << LM3S_ADC_SSCTL0_IE4_Pos)

#define LM3S_ADC_SSCTL0_END4_Pos                 17
#define LM3S_ADC_SSCTL0_END4_Msk                 (1UL << LM3S_ADC_SSCTL0_END4_Pos)

#define LM3S_ADC_SSCTL0_D4_Pos                   16
#define LM3S_ADC_SSCTL0_D4_Msk                   (1UL << LM3S_ADC_SSCTL0_D4_Pos)

#define LM3S_ADC_SSCTL0_TS3_Pos                  15
#define LM3S_ADC_SSCTL0_TS3_Msk                  (1UL << LM3S_ADC_SSCTL0_TS3_Pos)

#define LM3S_ADC_SSCTL0_IE3_Pos                  14
#define LM3S_ADC_SSCTL0_IE3_Msk                  (1UL << LM3S_ADC_SSCTL0_IE3_Pos)

#define LM3S_ADC_SSCTL0_END3_Pos                 13
#define LM3S_ADC_SSCTL0_END3_Msk                 (1UL << LM3S_ADC_SSCTL0_END3_Pos)

#define LM3S_ADC_SSCTL0_D3_Pos                   12
#define LM3S_ADC_SSCTL0_D3_Msk                   (1UL << LM3S_ADC_SSCTL0_D3_Pos)

#define LM3S_ADC_SSCTL0_TS2_Pos                  11
#define LM3S_ADC_SSCTL0_TS2_Msk                  (1UL << LM3S_ADC_SSCTL0_TS2_Pos)

#define LM3S_ADC_SSCTL0_IE2_Pos                  10
#define LM3S_ADC_SSCTL0_IE2_Msk                  (1UL << LM3S_ADC_SSCTL0_IE2_Pos)

#define LM3S_ADC_SSCTL0_END2_Pos                  9
#define LM3S_ADC_SSCTL0_END2_Msk                 (1UL << LM3S_ADC_SSCTL0_END2_Pos)

#define LM3S_ADC_SSCTL0_D2_Pos                    8
#define LM3S_ADC_SSCTL0_D2_Msk                   (1UL << LM3S_ADC_SSCTL0_D2_Pos)

#define LM3S_ADC_SSCTL0_TS1_Pos                   7
#define LM3S_ADC_SSCTL0_TS1_Msk                  (1UL << LM3S_ADC_SSCTL0_TS1_Pos)

#define LM3S_ADC_SSCTL0_IE1_Pos                   6
#define LM3S_ADC_SSCTL0_IE1_Msk                  (1UL << LM3S_ADC_SSCTL0_IE1_Pos)

#define LM3S_ADC_SSCTL0_END1_Pos                  5
#define LM3S_ADC_SSCTL0_END1_Msk                 (1UL << LM3S_ADC_SSCTL0_END1_Pos)

#define LM3S_ADC_SSCTL0_D1_Pos                    4
#define LM3S_ADC_SSCTL0_D1_Msk                   (1UL << LM3S_ADC_SSCTL0_D1_Pos)

#define LM3S_ADC_SSCTL0_TS0_Pos                   3
#define LM3S_ADC_SSCTL0_TS0_Msk                  (1UL << LM3S_ADC_SSCTL0_TS0_Pos)

#define LM3S_ADC_SSCTL0_IE0_Pos                   2
#define LM3S_ADC_SSCTL0_IE0_Msk                  (1UL << LM3S_ADC_SSCTL0_IE0_Pos)

#define LM3S_ADC_SSCTL0_END0_Pos                  1
#define LM3S_ADC_SSCTL0_END0_Msk                 (1UL << LM3S_ADC_SSCTL0_END0_Pos)

#define LM3S_ADC_SSCTL0_D0_Pos                    0
#define LM3S_ADC_SSCTL0_D0_Msk                   (1UL /*<< LM3S_ADC_SSCTL0_D0_Pos*/)

/* LM3S_ADC SSFIFO Register Definitions */
#define LM3S_ADC_SSFIFON_DATA_Pos                 0
#define LM3S_ADC_SSFIFON_DATA_Msk                (0x000003FFUL /*<< LM3S_ADC_SSFIFON_DATA_Pos*/)

/* LM3S_ADC SSFSTAT Register Definitions */
#define LM3S_ADC_SSFSTAT_FULL_Pos                12
#define LM3S_ADC_SSFSTAT_FULL_Msk                (1UL << LM3S_ADC_SSFSTAT_FULL_Pos)

#define LM3S_ADC_SSFSTAT_EMPTY_Pos                8
#define LM3S_ADC_SSFSTAT_EMPTY_Msk               (1UL << LM3S_ADC_SSFSTAT_EMPTY_Pos)

#define LM3S_ADC_SSFSTAT_HPTR_Pos                 4
#define LM3S_ADC_SSFSTAT_HPTR_Msk                (0x0000000FUL << LM3S_ADC_SSFSTAT_HPTR_Pos)

#define LM3S_ADC_SSFSTAT_TPTR_Pos                 0
#define LM3S_ADC_SSFSTAT_TPTR_Msk                (0x0000000FUL /*<< LM3S_ADC_SSFSTAT_TPTR_Pos*/)

/* LM3S_ADC SSOP0 Register Definitions */
#define LM3S_ADC_SSOP0_S7DCOP_Pos                28
#define LM3S_ADC_SSOP0_S7DCOP_Msk                (1UL << LM3S_ADC_SSOP0_S7DCOP_Pos)

#define LM3S_ADC_SSOP0_S6DCOP_Pos                24
#define LM3S_ADC_SSOP0_S6DCOP_Msk                (1UL << LM3S_ADC_SSOP0_S6DCOP_Pos)

#define LM3S_ADC_SSOP0_S5DCOP_Pos                20
#define LM3S_ADC_SSOP0_S5DCOP_Msk                (1UL << LM3S_ADC_SSOP0_S5DCOP_Pos)

#define LM3S_ADC_SSOP0_S4DCOP_Pos                16
#define LM3S_ADC_SSOP0_S4DCOP_Msk                (1UL << LM3S_ADC_SSOP0_S4DCOP_Pos)

#define LM3S_ADC_SSOP0_S3DCOP_Pos                12
#define LM3S_ADC_SSOP0_S3DCOP_Msk                (1UL << LM3S_ADC_SSOP0_S3DCOP_Pos)

#define LM3S_ADC_SSOP0_S2DCOP_Pos                 8
#define LM3S_ADC_SSOP0_S2DCOP_Msk                (1UL << LM3S_ADC_SSOP0_S2DCOP_Pos)

#define LM3S_ADC_SSOP0_S1DCOP_Pos                 4
#define LM3S_ADC_SSOP0_S1DCOP_Msk                (1UL << LM3S_ADC_SSOP0_S1DCOP_Pos)

#define LM3S_ADC_SSOP0_S0DCOP_Pos                 0
#define LM3S_ADC_SSOP0_S0DCOP_Msk                (1UL /*<< LM3S_ADC_SSOP0_S0DCOP_Pos*/)

/* LM3S_ADC SSDC0 Register Definitions */
#define LM3S_ADC_SSDC0_S7DCSEL_Pos               28
#define LM3S_ADC_SSDC0_S7DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC0_S7DCSEL_Pos)
#define LM3S_ADC_SSDC0_S7DCSEL_3_Pos             31
#define LM3S_ADC_SSDC0_S7DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S7DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S7DCSEL_2_Pos             30
#define LM3S_ADC_SSDC0_S7DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S7DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S7DCSEL_1_Pos             29
#define LM3S_ADC_SSDC0_S7DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S7DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S7DCSEL_0_Pos             28
#define LM3S_ADC_SSDC0_S7DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC0_S7DCSEL_0_Pos)

#define LM3S_ADC_SSDC0_S6DCSEL_Pos               24
#define LM3S_ADC_SSDC0_S6DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC0_S6DCSEL_Pos)
#define LM3S_ADC_SSDC0_S6DCSEL_3_Pos             27
#define LM3S_ADC_SSDC0_S6DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S6DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S6DCSEL_2_Pos             26
#define LM3S_ADC_SSDC0_S6DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S6DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S6DCSEL_1_Pos             25
#define LM3S_ADC_SSDC0_S6DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S6DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S6DCSEL_0_Pos             24
#define LM3S_ADC_SSDC0_S6DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC0_S6DCSEL_0_Pos)

#define LM3S_ADC_SSDC0_S5DCSEL_Pos               20
#define LM3S_ADC_SSDC0_S5DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC0_S5DCSEL_Pos)
#define LM3S_ADC_SSDC0_S5DCSEL_3_Pos             23
#define LM3S_ADC_SSDC0_S5DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S5DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S5DCSEL_2_Pos             22
#define LM3S_ADC_SSDC0_S5DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S5DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S5DCSEL_1_Pos             21
#define LM3S_ADC_SSDC0_S5DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S5DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S5DCSEL_0_Pos             20
#define LM3S_ADC_SSDC0_S5DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC0_S5DCSEL_0_Pos)

#define LM3S_ADC_SSDC0_S4DCSEL_Pos               16
#define LM3S_ADC_SSDC0_S4DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC0_S4DCSEL_Pos)
#define LM3S_ADC_SSDC0_S4DCSEL_3_Pos             19
#define LM3S_ADC_SSDC0_S4DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S4DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S4DCSEL_2_Pos             18
#define LM3S_ADC_SSDC0_S4DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S4DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S4DCSEL_1_Pos             17
#define LM3S_ADC_SSDC0_S4DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S4DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S4DCSEL_0_Pos             16
#define LM3S_ADC_SSDC0_S4DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC0_S4DCSEL_0_Pos)

#define LM3S_ADC_SSDC0_S3DCSEL_Pos               12
#define LM3S_ADC_SSDC0_S3DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC0_S3DCSEL_Pos)
#define LM3S_ADC_SSDC0_S3DCSEL_3_Pos             15
#define LM3S_ADC_SSDC0_S3DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S3DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S3DCSEL_2_Pos             14
#define LM3S_ADC_SSDC0_S3DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S3DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S3DCSEL_1_Pos             13
#define LM3S_ADC_SSDC0_S3DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S3DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S3DCSEL_0_Pos             12
#define LM3S_ADC_SSDC0_S3DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC0_S3DCSEL_0_Pos)

#define LM3S_ADC_SSDC0_S2DCSEL_Pos                8
#define LM3S_ADC_SSDC0_S2DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC0_S2DCSEL_Pos)
#define LM3S_ADC_SSDC0_S2DCSEL_3_Pos             11
#define LM3S_ADC_SSDC0_S2DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S2DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S2DCSEL_2_Pos             10
#define LM3S_ADC_SSDC0_S2DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S2DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S2DCSEL_1_Pos              9
#define LM3S_ADC_SSDC0_S2DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S2DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S2DCSEL_0_Pos              8
#define LM3S_ADC_SSDC0_S2DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC0_S2DCSEL_0_Pos)

#define LM3S_ADC_SSDC0_S1DCSEL_Pos                4
#define LM3S_ADC_SSDC0_S1DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC0_S1DCSEL_Pos)
#define LM3S_ADC_SSDC0_S1DCSEL_3_Pos              7
#define LM3S_ADC_SSDC0_S1DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S1DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S1DCSEL_2_Pos              6
#define LM3S_ADC_SSDC0_S1DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S1DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S1DCSEL_1_Pos              5
#define LM3S_ADC_SSDC0_S1DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S1DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S1DCSEL_0_Pos              4
#define LM3S_ADC_SSDC0_S1DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC0_S1DCSEL_0_Pos)

#define LM3S_ADC_SSDC0_S0DCSEL_Pos                0
#define LM3S_ADC_SSDC0_S0DCSEL_Msk               (0x0000000FUL /*<< LM3S_ADC_SSDC0_S0DCSEL_Pos*/)
#define LM3S_ADC_SSDC0_S0DCSEL_3_Pos              3
#define LM3S_ADC_SSDC0_S0DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC0_S0DCSEL_3_Pos)
#define LM3S_ADC_SSDC0_S0DCSEL_2_Pos              2
#define LM3S_ADC_SSDC0_S0DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC0_S0DCSEL_2_Pos)
#define LM3S_ADC_SSDC0_S0DCSEL_1_Pos              1
#define LM3S_ADC_SSDC0_S0DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC0_S0DCSEL_1_Pos)
#define LM3S_ADC_SSDC0_S0DCSEL_0_Pos              0
#define LM3S_ADC_SSDC0_S0DCSEL_0_Msk             (1UL /*<< LM3S_ADC_SSDC0_S0DCSEL_0_Pos*/)

/* LM3S_ADC SSMUX1 Register Definitions */
#define LM3S_ADC_SSMUX1_MUX3_Pos                 12
#define LM3S_ADC_SSMUX1_MUX3_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX1_MUX3_Pos)
#define LM3S_ADC_SSMUX1_MUX3_3_Pos               15
#define LM3S_ADC_SSMUX1_MUX3_3_Msk               (1UL << LM3S_ADC_SSMUX1_MUX3_3_Pos)
#define LM3S_ADC_SSMUX1_MUX3_2_Pos               14
#define LM3S_ADC_SSMUX1_MUX3_2_Msk               (1UL << LM3S_ADC_SSMUX1_MUX3_2_Pos)
#define LM3S_ADC_SSMUX1_MUX3_1_Pos               13
#define LM3S_ADC_SSMUX1_MUX3_1_Msk               (1UL << LM3S_ADC_SSMUX1_MUX3_1_Pos)
#define LM3S_ADC_SSMUX1_MUX3_0_Pos               12
#define LM3S_ADC_SSMUX1_MUX3_0_Msk               (1UL << LM3S_ADC_SSMUX1_MUX3_0_Pos)

#define LM3S_ADC_SSMUX1_MUX2_Pos                  8
#define LM3S_ADC_SSMUX1_MUX2_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX1_MUX2_Pos)
#define LM3S_ADC_SSMUX1_MUX2_3_Pos               11
#define LM3S_ADC_SSMUX1_MUX2_3_Msk               (1UL << LM3S_ADC_SSMUX1_MUX2_3_Pos)
#define LM3S_ADC_SSMUX1_MUX2_2_Pos               10
#define LM3S_ADC_SSMUX1_MUX2_2_Msk               (1UL << LM3S_ADC_SSMUX1_MUX2_2_Pos)
#define LM3S_ADC_SSMUX1_MUX2_1_Pos                9
#define LM3S_ADC_SSMUX1_MUX2_1_Msk               (1UL << LM3S_ADC_SSMUX1_MUX2_1_Pos)
#define LM3S_ADC_SSMUX1_MUX2_0_Pos                8
#define LM3S_ADC_SSMUX1_MUX2_0_Msk               (1UL << LM3S_ADC_SSMUX1_MUX2_0_Pos)

#define LM3S_ADC_SSMUX1_MUX1_Pos                  4
#define LM3S_ADC_SSMUX1_MUX1_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX1_MUX1_Pos)
#define LM3S_ADC_SSMUX1_MUX1_3_Pos                7
#define LM3S_ADC_SSMUX1_MUX1_3_Msk               (1UL << LM3S_ADC_SSMUX1_MUX1_3_Pos)
#define LM3S_ADC_SSMUX1_MUX1_2_Pos                6
#define LM3S_ADC_SSMUX1_MUX1_2_Msk               (1UL << LM3S_ADC_SSMUX1_MUX1_2_Pos)
#define LM3S_ADC_SSMUX1_MUX1_1_Pos                5
#define LM3S_ADC_SSMUX1_MUX1_1_Msk               (1UL << LM3S_ADC_SSMUX1_MUX1_1_Pos)
#define LM3S_ADC_SSMUX1_MUX1_0_Pos                4
#define LM3S_ADC_SSMUX1_MUX1_0_Msk               (1UL << LM3S_ADC_SSMUX1_MUX1_0_Pos)

#define LM3S_ADC_SSMUX1_MUX0_Pos                  0
#define LM3S_ADC_SSMUX1_MUX0_Msk                 (0x0000000FUL /*<< LM3S_ADC_SSMUX1_MUX0_Pos*/)
#define LM3S_ADC_SSMUX1_MUX0_3_Pos                3
#define LM3S_ADC_SSMUX1_MUX0_3_Msk               (1UL << LM3S_ADC_SSMUX1_MUX0_3_Pos)
#define LM3S_ADC_SSMUX1_MUX0_2_Pos                2
#define LM3S_ADC_SSMUX1_MUX0_2_Msk               (1UL << LM3S_ADC_SSMUX1_MUX0_2_Pos)
#define LM3S_ADC_SSMUX1_MUX0_1_Pos                1
#define LM3S_ADC_SSMUX1_MUX0_1_Msk               (1UL << LM3S_ADC_SSMUX1_MUX0_1_Pos)
#define LM3S_ADC_SSMUX1_MUX0_0_Pos                0
#define LM3S_ADC_SSMUX1_MUX0_0_Msk               (1UL /*<< LM3S_ADC_SSMUX1_MUX0_0_Pos*/)

/* LM3S_ADC SSMUX2 Register Definitions */
#define LM3S_ADC_SSMUX2_MUX3_Pos                 12
#define LM3S_ADC_SSMUX2_MUX3_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX2_MUX3_Pos)
#define LM3S_ADC_SSMUX2_MUX3_3_Pos               15
#define LM3S_ADC_SSMUX2_MUX3_3_Msk               (1UL << LM3S_ADC_SSMUX2_MUX3_3_Pos)
#define LM3S_ADC_SSMUX2_MUX3_2_Pos               14
#define LM3S_ADC_SSMUX2_MUX3_2_Msk               (1UL << LM3S_ADC_SSMUX2_MUX3_2_Pos)
#define LM3S_ADC_SSMUX2_MUX3_1_Pos               13
#define LM3S_ADC_SSMUX2_MUX3_1_Msk               (1UL << LM3S_ADC_SSMUX2_MUX3_1_Pos)
#define LM3S_ADC_SSMUX2_MUX3_0_Pos               12
#define LM3S_ADC_SSMUX2_MUX3_0_Msk               (1UL << LM3S_ADC_SSMUX2_MUX3_0_Pos)

#define LM3S_ADC_SSMUX2_MUX2_Pos                  8
#define LM3S_ADC_SSMUX2_MUX2_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX2_MUX2_Pos)
#define LM3S_ADC_SSMUX2_MUX2_3_Pos               11
#define LM3S_ADC_SSMUX2_MUX2_3_Msk               (1UL << LM3S_ADC_SSMUX2_MUX2_3_Pos)
#define LM3S_ADC_SSMUX2_MUX2_2_Pos               10
#define LM3S_ADC_SSMUX2_MUX2_2_Msk               (1UL << LM3S_ADC_SSMUX2_MUX2_2_Pos)
#define LM3S_ADC_SSMUX2_MUX2_1_Pos                9
#define LM3S_ADC_SSMUX2_MUX2_1_Msk               (1UL << LM3S_ADC_SSMUX2_MUX2_1_Pos)
#define LM3S_ADC_SSMUX2_MUX2_0_Pos                8
#define LM3S_ADC_SSMUX2_MUX2_0_Msk               (1UL << LM3S_ADC_SSMUX2_MUX2_0_Pos)

#define LM3S_ADC_SSMUX2_MUX1_Pos                  4
#define LM3S_ADC_SSMUX2_MUX1_Msk                 (0x0000000FUL << LM3S_ADC_SSMUX2_MUX1_Pos)
#define LM3S_ADC_SSMUX2_MUX1_3_Pos                7
#define LM3S_ADC_SSMUX2_MUX1_3_Msk               (1UL << LM3S_ADC_SSMUX2_MUX1_3_Pos)
#define LM3S_ADC_SSMUX2_MUX1_2_Pos                6
#define LM3S_ADC_SSMUX2_MUX1_2_Msk               (1UL << LM3S_ADC_SSMUX2_MUX1_2_Pos)
#define LM3S_ADC_SSMUX2_MUX1_1_Pos                5
#define LM3S_ADC_SSMUX2_MUX1_1_Msk               (1UL << LM3S_ADC_SSMUX2_MUX1_1_Pos)
#define LM3S_ADC_SSMUX2_MUX1_0_Pos                4
#define LM3S_ADC_SSMUX2_MUX1_0_Msk               (1UL << LM3S_ADC_SSMUX2_MUX1_0_Pos)

#define LM3S_ADC_SSMUX2_MUX0_Pos                  0
#define LM3S_ADC_SSMUX2_MUX0_Msk                 (0x0000000FUL /*<< LM3S_ADC_SSMUX2_MUX0_Pos*/)
#define LM3S_ADC_SSMUX2_MUX0_3_Pos                3
#define LM3S_ADC_SSMUX2_MUX0_3_Msk               (1UL << LM3S_ADC_SSMUX2_MUX0_3_Pos)
#define LM3S_ADC_SSMUX2_MUX0_2_Pos                2
#define LM3S_ADC_SSMUX2_MUX0_2_Msk               (1UL << LM3S_ADC_SSMUX2_MUX0_2_Pos)
#define LM3S_ADC_SSMUX2_MUX0_1_Pos                1
#define LM3S_ADC_SSMUX2_MUX0_1_Msk               (1UL << LM3S_ADC_SSMUX2_MUX0_1_Pos)
#define LM3S_ADC_SSMUX2_MUX0_0_Pos                0
#define LM3S_ADC_SSMUX2_MUX0_0_Msk               (1UL /*<< LM3S_ADC_SSMUX2_MUX0_0_Pos*/)

/* LM3S_ADC SSCTL1 Register Definitions */
#define LM3S_ADC_SSCTL1_TS3_Pos                  15
#define LM3S_ADC_SSCTL1_TS3_Msk                  (1UL << LM3S_ADC_SSCTL1_TS3_Pos)

#define LM3S_ADC_SSCTL1_IE3_Pos                  14
#define LM3S_ADC_SSCTL1_IE3_Msk                  (1UL << LM3S_ADC_SSCTL1_IE3_Pos)

#define LM3S_ADC_SSCTL1_END3_Pos                 13
#define LM3S_ADC_SSCTL1_END3_Msk                 (1UL << LM3S_ADC_SSCTL1_END3_Pos)

#define LM3S_ADC_SSCTL1_D3_Pos                   12
#define LM3S_ADC_SSCTL1_D3_Msk                   (1UL << LM3S_ADC_SSCTL1_D3_Pos)

#define LM3S_ADC_SSCTL1_TS2_Pos                  11
#define LM3S_ADC_SSCTL1_TS2_Msk                  (1UL << LM3S_ADC_SSCTL1_TS2_Pos)

#define LM3S_ADC_SSCTL1_IE2_Pos                  10
#define LM3S_ADC_SSCTL1_IE2_Msk                  (1UL << LM3S_ADC_SSCTL1_IE2_Pos)

#define LM3S_ADC_SSCTL1_END2_Pos                  9
#define LM3S_ADC_SSCTL1_END2_Msk                 (1UL << LM3S_ADC_SSCTL1_END2_Pos)

#define LM3S_ADC_SSCTL1_D2_Pos                    8
#define LM3S_ADC_SSCTL1_D2_Msk                   (1UL << LM3S_ADC_SSCTL1_D2_Pos)

#define LM3S_ADC_SSCTL1_TS1_Pos                   7
#define LM3S_ADC_SSCTL1_TS1_Msk                  (1UL << LM3S_ADC_SSCTL1_TS1_Pos)

#define LM3S_ADC_SSCTL1_IE1_Pos                   6
#define LM3S_ADC_SSCTL1_IE1_Msk                  (1UL << LM3S_ADC_SSCTL1_IE1_Pos)

#define LM3S_ADC_SSCTL1_END1_Pos                  5
#define LM3S_ADC_SSCTL1_END1_Msk                 (1UL << LM3S_ADC_SSCTL1_END1_Pos)

#define LM3S_ADC_SSCTL1_D1_Pos                    4
#define LM3S_ADC_SSCTL1_D1_Msk                   (1UL << LM3S_ADC_SSCTL1_D1_Pos)

#define LM3S_ADC_SSCTL1_TS0_Pos                   3
#define LM3S_ADC_SSCTL1_TS0_Msk                  (1UL << LM3S_ADC_SSCTL1_TS0_Pos)

#define LM3S_ADC_SSCTL1_IE0_Pos                   2
#define LM3S_ADC_SSCTL1_IE0_Msk                  (1UL << LM3S_ADC_SSCTL1_IE0_Pos)

#define LM3S_ADC_SSCTL1_END0_Pos                  1
#define LM3S_ADC_SSCTL1_END0_Msk                 (1UL << LM3S_ADC_SSCTL1_END0_Pos)

#define LM3S_ADC_SSCTL1_D0_Pos                    0
#define LM3S_ADC_SSCTL1_D0_Msk                   (1UL /*<< LM3S_ADC_SSCTL1_D0_Pos*/)

/* LM3S_ADC SSCTL2 Register Definitions */
#define LM3S_ADC_SSCTL2_TS3_Pos                  15
#define LM3S_ADC_SSCTL2_TS3_Msk                  (1UL << LM3S_ADC_SSCTL2_TS3_Pos)

#define LM3S_ADC_SSCTL2_IE3_Pos                  14
#define LM3S_ADC_SSCTL2_IE3_Msk                  (1UL << LM3S_ADC_SSCTL2_IE3_Pos)

#define LM3S_ADC_SSCTL2_END3_Pos                 13
#define LM3S_ADC_SSCTL2_END3_Msk                 (1UL << LM3S_ADC_SSCTL2_END3_Pos)

#define LM3S_ADC_SSCTL2_D3_Pos                   12
#define LM3S_ADC_SSCTL2_D3_Msk                   (1UL << LM3S_ADC_SSCTL2_D3_Pos)

#define LM3S_ADC_SSCTL2_TS2_Pos                  11
#define LM3S_ADC_SSCTL2_TS2_Msk                  (1UL << LM3S_ADC_SSCTL2_TS2_Pos)

#define LM3S_ADC_SSCTL2_IE2_Pos                  10
#define LM3S_ADC_SSCTL2_IE2_Msk                  (1UL << LM3S_ADC_SSCTL2_IE2_Pos)

#define LM3S_ADC_SSCTL2_END2_Pos                  9
#define LM3S_ADC_SSCTL2_END2_Msk                 (1UL << LM3S_ADC_SSCTL2_END2_Pos)

#define LM3S_ADC_SSCTL2_D2_Pos                    8
#define LM3S_ADC_SSCTL2_D2_Msk                   (1UL << LM3S_ADC_SSCTL2_D2_Pos)

#define LM3S_ADC_SSCTL2_TS1_Pos                   7
#define LM3S_ADC_SSCTL2_TS1_Msk                  (1UL << LM3S_ADC_SSCTL2_TS1_Pos)

#define LM3S_ADC_SSCTL2_IE1_Pos                   6
#define LM3S_ADC_SSCTL2_IE1_Msk                  (1UL << LM3S_ADC_SSCTL2_IE1_Pos)

#define LM3S_ADC_SSCTL2_END1_Pos                  5
#define LM3S_ADC_SSCTL2_END1_Msk                 (1UL << LM3S_ADC_SSCTL2_END1_Pos)

#define LM3S_ADC_SSCTL2_D1_Pos                    4
#define LM3S_ADC_SSCTL2_D1_Msk                   (1UL << LM3S_ADC_SSCTL2_D1_Pos)

#define LM3S_ADC_SSCTL2_TS0_Pos                   3
#define LM3S_ADC_SSCTL2_TS0_Msk                  (1UL << LM3S_ADC_SSCTL2_TS0_Pos)

#define LM3S_ADC_SSCTL2_IE0_Pos                   2
#define LM3S_ADC_SSCTL2_IE0_Msk                  (1UL << LM3S_ADC_SSCTL2_IE0_Pos)

#define LM3S_ADC_SSCTL2_END0_Pos                  1
#define LM3S_ADC_SSCTL2_END0_Msk                 (1UL << LM3S_ADC_SSCTL2_END0_Pos)

#define LM3S_ADC_SSCTL2_D0_Pos                    0
#define LM3S_ADC_SSCTL2_D0_Msk                   (1UL /*<< LM3S_ADC_SSCTL2_D0_Pos*/)

/* LM3S_ADC SSOP1 Register Definitions */
#define LM3S_ADC_SSOP1_S3DCOP_Pos                12
#define LM3S_ADC_SSOP1_S3DCOP_Msk                (1UL << LM3S_ADC_SSOP1_S3DCOP_Pos)

#define LM3S_ADC_SSOP1_S2DCOP_Pos                 8
#define LM3S_ADC_SSOP1_S2DCOP_Msk                (1UL << LM3S_ADC_SSOP1_S2DCOP_Pos)

#define LM3S_ADC_SSOP1_S1DCOP_Pos                 4
#define LM3S_ADC_SSOP1_S1DCOP_Msk                (1UL << LM3S_ADC_SSOP1_S1DCOP_Pos)

#define LM3S_ADC_SSOP1_S0DCOP_Pos                 0
#define LM3S_ADC_SSOP1_S0DCOP_Msk                (1UL /*<< LM3S_ADC_SSOP1_S0DCOP_Pos*/)

/* LM3S_ADC SSOP2 Register Definitions */
#define LM3S_ADC_SSOP2_S3DCOP_Pos                12
#define LM3S_ADC_SSOP2_S3DCOP_Msk                (1UL << LM3S_ADC_SSOP2_S3DCOP_Pos)

#define LM3S_ADC_SSOP2_S2DCOP_Pos                 8
#define LM3S_ADC_SSOP2_S2DCOP_Msk                (1UL << LM3S_ADC_SSOP2_S2DCOP_Pos)

#define LM3S_ADC_SSOP2_S1DCOP_Pos                 4
#define LM3S_ADC_SSOP2_S1DCOP_Msk                (1UL << LM3S_ADC_SSOP2_S1DCOP_Pos)

#define LM3S_ADC_SSOP2_S0DCOP_Pos                 0
#define LM3S_ADC_SSOP2_S0DCOP_Msk                (1UL /*<< LM3S_ADC_SSOP2_S0DCOP_Pos*/)

/* LM3S_ADC SSDC1 Register Definitions */
#define LM3S_ADC_SSDC1_S3DCSEL_Pos               12
#define LM3S_ADC_SSDC1_S3DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC1_S3DCSEL_Pos)
#define LM3S_ADC_SSDC1_S3DCSEL_3_Pos             15
#define LM3S_ADC_SSDC1_S3DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC1_S3DCSEL_3_Pos)
#define LM3S_ADC_SSDC1_S3DCSEL_2_Pos             14
#define LM3S_ADC_SSDC1_S3DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC1_S3DCSEL_2_Pos)
#define LM3S_ADC_SSDC1_S3DCSEL_1_Pos             13
#define LM3S_ADC_SSDC1_S3DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC1_S3DCSEL_1_Pos)
#define LM3S_ADC_SSDC1_S3DCSEL_0_Pos             12
#define LM3S_ADC_SSDC1_S3DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC1_S3DCSEL_0_Pos)

#define LM3S_ADC_SSDC1_S2DCSEL_Pos                8
#define LM3S_ADC_SSDC1_S2DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC1_S2DCSEL_Pos)
#define LM3S_ADC_SSDC1_S2DCSEL_3_Pos             11
#define LM3S_ADC_SSDC1_S2DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC1_S2DCSEL_3_Pos)
#define LM3S_ADC_SSDC1_S2DCSEL_2_Pos             10
#define LM3S_ADC_SSDC1_S2DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC1_S2DCSEL_2_Pos)
#define LM3S_ADC_SSDC1_S2DCSEL_1_Pos              9
#define LM3S_ADC_SSDC1_S2DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC1_S2DCSEL_1_Pos)
#define LM3S_ADC_SSDC1_S2DCSEL_0_Pos              8
#define LM3S_ADC_SSDC1_S2DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC1_S2DCSEL_0_Pos)

#define LM3S_ADC_SSDC1_S1DCSEL_Pos                4
#define LM3S_ADC_SSDC1_S1DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC1_S1DCSEL_Pos)
#define LM3S_ADC_SSDC1_S1DCSEL_3_Pos              7
#define LM3S_ADC_SSDC1_S1DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC1_S1DCSEL_3_Pos)
#define LM3S_ADC_SSDC1_S1DCSEL_2_Pos              6
#define LM3S_ADC_SSDC1_S1DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC1_S1DCSEL_2_Pos)
#define LM3S_ADC_SSDC1_S1DCSEL_1_Pos              5
#define LM3S_ADC_SSDC1_S1DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC1_S1DCSEL_1_Pos)
#define LM3S_ADC_SSDC1_S1DCSEL_0_Pos              4
#define LM3S_ADC_SSDC1_S1DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC1_S1DCSEL_0_Pos)

#define LM3S_ADC_SSDC1_S0DCSEL_Pos                0
#define LM3S_ADC_SSDC1_S0DCSEL_Msk               (0x0000000FUL /*<< LM3S_ADC_SSDC1_S0DCSEL_Pos*/)
#define LM3S_ADC_SSDC1_S0DCSEL_3_Pos              3
#define LM3S_ADC_SSDC1_S0DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC1_S0DCSEL_3_Pos)
#define LM3S_ADC_SSDC1_S0DCSEL_2_Pos              2
#define LM3S_ADC_SSDC1_S0DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC1_S0DCSEL_2_Pos)
#define LM3S_ADC_SSDC1_S0DCSEL_1_Pos              1
#define LM3S_ADC_SSDC1_S0DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC1_S0DCSEL_1_Pos)
#define LM3S_ADC_SSDC1_S0DCSEL_0_Pos              0
#define LM3S_ADC_SSDC1_S0DCSEL_0_Msk             (1UL /*<< LM3S_ADC_SSDC1_S0DCSEL_0_Pos*/)

/* LM3S_ADC SSDC2 Register Definitions */
#define LM3S_ADC_SSDC2_S3DCSEL_Pos               12
#define LM3S_ADC_SSDC2_S3DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC2_S3DCSEL_Pos)
#define LM3S_ADC_SSDC2_S3DCSEL_3_Pos             15
#define LM3S_ADC_SSDC2_S3DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC2_S3DCSEL_3_Pos)
#define LM3S_ADC_SSDC2_S3DCSEL_2_Pos             14
#define LM3S_ADC_SSDC2_S3DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC2_S3DCSEL_2_Pos)
#define LM3S_ADC_SSDC2_S3DCSEL_1_Pos             13
#define LM3S_ADC_SSDC2_S3DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC2_S3DCSEL_1_Pos)
#define LM3S_ADC_SSDC2_S3DCSEL_0_Pos             12
#define LM3S_ADC_SSDC2_S3DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC2_S3DCSEL_0_Pos)

#define LM3S_ADC_SSDC2_S2DCSEL_Pos                8
#define LM3S_ADC_SSDC2_S2DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC2_S2DCSEL_Pos)
#define LM3S_ADC_SSDC2_S2DCSEL_3_Pos             11
#define LM3S_ADC_SSDC2_S2DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC2_S2DCSEL_3_Pos)
#define LM3S_ADC_SSDC2_S2DCSEL_2_Pos             10
#define LM3S_ADC_SSDC2_S2DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC2_S2DCSEL_2_Pos)
#define LM3S_ADC_SSDC2_S2DCSEL_1_Pos              9
#define LM3S_ADC_SSDC2_S2DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC2_S2DCSEL_1_Pos)
#define LM3S_ADC_SSDC2_S2DCSEL_0_Pos              8
#define LM3S_ADC_SSDC2_S2DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC2_S2DCSEL_0_Pos)

#define LM3S_ADC_SSDC2_S1DCSEL_Pos                4
#define LM3S_ADC_SSDC2_S1DCSEL_Msk               (0x0000000FUL << LM3S_ADC_SSDC2_S1DCSEL_Pos)
#define LM3S_ADC_SSDC2_S1DCSEL_3_Pos              7
#define LM3S_ADC_SSDC2_S1DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC2_S1DCSEL_3_Pos)
#define LM3S_ADC_SSDC2_S1DCSEL_2_Pos              6
#define LM3S_ADC_SSDC2_S1DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC2_S1DCSEL_2_Pos)
#define LM3S_ADC_SSDC2_S1DCSEL_1_Pos              5
#define LM3S_ADC_SSDC2_S1DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC2_S1DCSEL_1_Pos)
#define LM3S_ADC_SSDC2_S1DCSEL_0_Pos              4
#define LM3S_ADC_SSDC2_S1DCSEL_0_Msk             (1UL << LM3S_ADC_SSDC2_S1DCSEL_0_Pos)

#define LM3S_ADC_SSDC2_S0DCSEL_Pos                0
#define LM3S_ADC_SSDC2_S0DCSEL_Msk               (0x0000000FUL /*<< LM3S_ADC_SSDC2_S0DCSEL_Pos*/)
#define LM3S_ADC_SSDC2_S0DCSEL_3_Pos              3
#define LM3S_ADC_SSDC2_S0DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC2_S0DCSEL_3_Pos)
#define LM3S_ADC_SSDC2_S0DCSEL_2_Pos              2
#define LM3S_ADC_SSDC2_S0DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC2_S0DCSEL_2_Pos)
#define LM3S_ADC_SSDC2_S0DCSEL_1_Pos              1
#define LM3S_ADC_SSDC2_S0DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC2_S0DCSEL_1_Pos)
#define LM3S_ADC_SSDC2_S0DCSEL_0_Pos              0
#define LM3S_ADC_SSDC2_S0DCSEL_0_Msk             (1UL /*<< LM3S_ADC_SSDC2_S0DCSEL_0_Pos*/)

/* LM3S_ADC SSMUX3 Register Definitions */
#define LM3S_ADC_SSMUX3_MUX0_Pos                  0
#define LM3S_ADC_SSMUX3_MUX0_Msk                 (0x0000000FUL /*<< LM3S_ADC_SSMUX3_MUX0_Pos*/)
#define LM3S_ADC_SSMUX3_MUX0_3_Pos                3
#define LM3S_ADC_SSMUX3_MUX0_3_Msk               (1UL << LM3S_ADC_SSMUX3_MUX0_3_Pos)
#define LM3S_ADC_SSMUX3_MUX0_2_Pos                2
#define LM3S_ADC_SSMUX3_MUX0_2_Msk               (1UL << LM3S_ADC_SSMUX3_MUX0_2_Pos)
#define LM3S_ADC_SSMUX3_MUX0_1_Pos                1
#define LM3S_ADC_SSMUX3_MUX0_1_Msk               (1UL << LM3S_ADC_SSMUX3_MUX0_1_Pos)
#define LM3S_ADC_SSMUX3_MUX0_0_Pos                0
#define LM3S_ADC_SSMUX3_MUX0_0_Msk               (1UL /*<< LM3S_ADC_SSMUX3_MUX0_0_Pos*/)

/* LM3S_ADC SSCTL3 Register Definitions */
#define LM3S_ADC_SSCTL3_TS0_Pos                   3
#define LM3S_ADC_SSCTL3_TS0_Msk                  (1UL << LM3S_ADC_SSCTL3_TS0_Pos)

#define LM3S_ADC_SSCTL3_IE0_Pos                   2
#define LM3S_ADC_SSCTL3_IE0_Msk                  (1UL << LM3S_ADC_SSCTL3_IE0_Pos)

#define LM3S_ADC_SSCTL3_END0_Pos                  1
#define LM3S_ADC_SSCTL3_END0_Msk                 (1UL << LM3S_ADC_SSCTL3_END0_Pos)

#define LM3S_ADC_SSCTL3_D0_Pos                    0
#define LM3S_ADC_SSCTL3_D0_Msk                   (1UL /*<< LM3S_ADC_SSCTL3_D0_Pos*/)

/* LM3S_ADC SSOP3 Register Definitions */
#define LM3S_ADC_SSOP3_S0DCOP_Pos                 0
#define LM3S_ADC_SSOP3_S0DCOP_Msk                (1UL /*<< LM3S_ADC_SSOP3_S0DCOP_Pos*/)

/* LM3S_ADC SSDC3 Register Definitions */
#define LM3S_ADC_SSDC3_S0DCSEL_Pos                0
#define LM3S_ADC_SSDC3_S0DCSEL_Msk               (0x0000000FUL /*<< LM3S_ADC_SSDC3_S0DCSEL_Pos*/)
#define LM3S_ADC_SSDC3_S0DCSEL_3_Pos              3
#define LM3S_ADC_SSDC3_S0DCSEL_3_Msk             (1UL << LM3S_ADC_SSDC3_S0DCSEL_3_Pos)
#define LM3S_ADC_SSDC3_S0DCSEL_2_Pos              2
#define LM3S_ADC_SSDC3_S0DCSEL_2_Msk             (1UL << LM3S_ADC_SSDC3_S0DCSEL_2_Pos)
#define LM3S_ADC_SSDC3_S0DCSEL_1_Pos              1
#define LM3S_ADC_SSDC3_S0DCSEL_1_Msk             (1UL << LM3S_ADC_SSDC3_S0DCSEL_1_Pos)
#define LM3S_ADC_SSDC3_S0DCSEL_0_Pos              0
#define LM3S_ADC_SSDC3_S0DCSEL_0_Msk             (1UL /*<< LM3S_ADC_SSDC3_S0DCSEL_0_Pos*/)

/* LM3S_ADC DCRIC Register Definitions */
#define LM3S_ADC_DCRIC_DCTRIG7_Pos               23
#define LM3S_ADC_DCRIC_DCTRIG7_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG7_Pos)

#define LM3S_ADC_DCRIC_DCTRIG6_Pos               22
#define LM3S_ADC_DCRIC_DCTRIG6_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG6_Pos)

#define LM3S_ADC_DCRIC_DCTRIG5_Pos               21
#define LM3S_ADC_DCRIC_DCTRIG5_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG5_Pos)

#define LM3S_ADC_DCRIC_DCTRIG4_Pos               20
#define LM3S_ADC_DCRIC_DCTRIG4_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG4_Pos)

#define LM3S_ADC_DCRIC_DCTRIG3_Pos               19
#define LM3S_ADC_DCRIC_DCTRIG3_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG3_Pos)

#define LM3S_ADC_DCRIC_DCTRIG2_Pos               18
#define LM3S_ADC_DCRIC_DCTRIG2_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG2_Pos)

#define LM3S_ADC_DCRIC_DCTRIG1_Pos               17
#define LM3S_ADC_DCRIC_DCTRIG1_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG1_Pos)

#define LM3S_ADC_DCRIC_DCTRIG0_Pos               16
#define LM3S_ADC_DCRIC_DCTRIG0_Msk               (1UL << LM3S_ADC_DCRIC_DCTRIG0_Pos)

#define LM3S_ADC_DCRIC_DCINT7_Pos                 7
#define LM3S_ADC_DCRIC_DCINT7_Msk                (1UL << LM3S_ADC_DCRIC_DCINT7_Pos)

#define LM3S_ADC_DCRIC_DCINT6_Pos                 6
#define LM3S_ADC_DCRIC_DCINT6_Msk                (1UL << LM3S_ADC_DCRIC_DCINT6_Pos)

#define LM3S_ADC_DCRIC_DCINT5_Pos                 5
#define LM3S_ADC_DCRIC_DCINT5_Msk                (1UL << LM3S_ADC_DCRIC_DCINT5_Pos)

#define LM3S_ADC_DCRIC_DCINT4_Pos                 4
#define LM3S_ADC_DCRIC_DCINT4_Msk                (1UL << LM3S_ADC_DCRIC_DCINT4_Pos)

#define LM3S_ADC_DCRIC_DCINT3_Pos                 3
#define LM3S_ADC_DCRIC_DCINT3_Msk                (1UL << LM3S_ADC_DCRIC_DCINT3_Pos)

#define LM3S_ADC_DCRIC_DCINT2_Pos                 2
#define LM3S_ADC_DCRIC_DCINT2_Msk                (1UL << LM3S_ADC_DCRIC_DCINT2_Pos)

#define LM3S_ADC_DCRIC_DCINT1_Pos                 1
#define LM3S_ADC_DCRIC_DCINT1_Msk                (1UL << LM3S_ADC_DCRIC_DCINT1_Pos)

#define LM3S_ADC_DCRIC_DCINT0_Pos                 0
#define LM3S_ADC_DCRIC_DCINT0_Msk                (1UL /*<< LM3S_ADC_DCRIC_DCINT0_Pos*/)

/* LM3S_ADC DCCTL Register Definitions */
#define LM3S_ADC_DCCTL_CTE_Pos                   12
#define LM3S_ADC_DCCTL_CTE_Msk                   (1UL << LM3S_ADC_DCCTL_CTE_Pos)

#define LM3S_ADC_DCCTL_CTC_Pos                   10
#define LM3S_ADC_DCCTL_CTC_Msk                   (0x00000003UL << LM3S_ADC_DCCTL_CTC_Pos)
#define LM3S_ADC_DCCTL_CTC_1_Pos                 11
#define LM3S_ADC_DCCTL_CTC_1_Msk                 (1 << LM3S_ADC_DCCTL_CTC_1_Pos)
#define LM3S_ADC_DCCTL_CTC_0_Pos                 10
#define LM3S_ADC_DCCTL_CTC_0_Msk                 (1 << LM3S_ADC_DCCTL_CTC_0_Pos)

#define LM3S_ADC_DCCTL_CTM_Pos                    8
#define LM3S_ADC_DCCTL_CTM_Msk                   (0x00000003UL << LM3S_ADC_DCCTL_CTM_Pos)
#define LM3S_ADC_DCCTL_CTM_1_Pos                  9
#define LM3S_ADC_DCCTL_CTM_1_Msk                 (1 << LM3S_ADC_DCCTL_CTM_1_Pos)
#define LM3S_ADC_DCCTL_CTM_0_Pos                  8
#define LM3S_ADC_DCCTL_CTM_0_Msk                 (1 << LM3S_ADC_DCCTL_CTM_0_Pos)

#define LM3S_ADC_DCCTL_CIE_Pos                    4
#define LM3S_ADC_DCCTL_CIE_Msk                   (1UL << LM3S_ADC_DCCTL_CIE_Pos)

#define LM3S_ADC_DCCTL_CIC_Pos                    2
#define LM3S_ADC_DCCTL_CIC_Msk                   (0x00000003UL << LM3S_ADC_DCCTL_CIC_Pos)
#define LM3S_ADC_DCCTL_CIC_1_Pos                  3
#define LM3S_ADC_DCCTL_CIC_1_Msk                 (1 << LM3S_ADC_DCCTL_CIC_1_Pos)
#define LM3S_ADC_DCCTL_CIC_0_Pos                  2
#define LM3S_ADC_DCCTL_CIC_0_Msk                 (1 << LM3S_ADC_DCCTL_CIC_0_Pos)

#define LM3S_ADC_DCCTL_CIM_Pos                    0
#define LM3S_ADC_DCCTL_CIM_Msk                   (0x00000003UL /*<< LM3S_ADC_DCCTL_CIM_Pos*/)
#define LM3S_ADC_DCCTL_CIM_1_Pos                  1
#define LM3S_ADC_DCCTL_CIM_1_Msk                 (1 << LM3S_ADC_DCCTL_CIM_1_Pos)
#define LM3S_ADC_DCCTL_CIM_0_Pos                  0
#define LM3S_ADC_DCCTL_CIM_0_Msk                 (1 /*<< LM3S_ADC_DCCTL_CIM_0_Pos*/)

/* LM3S_ADC DCCMP Register Definitions */
#define LM3S_ADC_DCCMP_COMP1_Pos                 16
#define LM3S_ADC_DCCMP_COMP1_Msk                 (0x000003FFUL << LM3S_ADC_DCCMP_COMP1_Pos)

#define LM3S_ADC_DCCMP_COMP0_Pos                  0
#define LM3S_ADC_DCCMP_COMP0_Msk                 (0x000003FFUL /*<< LM3S_ADC_DCCMP_COMP0_Pos*/)

/* ================================================================================ */
/* ================             Analog comparators (AC)            ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  MIS;                  /* Offset: 0x000 (R/W) Masked Interrupt Status Register */
  __IM  uint32_t  RIS;                  /* Offset: 0x004 (R/ ) Raw Interrupt Status Register */
  __IOM uint32_t  INTEN;                /* Offset: 0x008 (R/W) Interrupt Enable Register */
  __IOM uint32_t  REFCTL;               /* Offset: 0x010 (R/W) Reference Voltage Control Register */
  __IM  uint32_t  RESERVED0[3];
  __IM  uint32_t  STAT0;                /* Offset: 0x020 (R/ ) Status 2 Register */
  __IOM uint32_t  CTL0;                 /* Offset: 0x024 (R/W) Control 2 Register */
  __IM  uint32_t  RESERVED1[6];
  __IM  uint32_t  STAT1;                /* Offset: 0x040 (R/ ) Status 2 Register */
  __IOM uint32_t  CTL1;                 /* Offset: 0x044 (R/W) Control 2 Register */
  __IM  uint32_t  RESERVED2[6];
  __IM  uint32_t  STAT2;                /* Offset: 0x060 (R/ ) Status 2 Register */
  __IOM uint32_t  CTL2;                 /* Offset: 0x064 (R/W) Control 2 Register */
} LM3S_AC_TypeDef;

/* LM3S_AC MIS Register Definitions */
#define LM3S_AC_MIS_IN2_Pos                       2
#define LM3S_AC_MIS_IN2_Msk                      (1UL << LM3S_AC_MIS_IN2_Pos)

#define LM3S_AC_MIS_IN1_Pos                       1
#define LM3S_AC_MIS_IN1_Msk                      (1UL << LM3S_AC_MIS_IN1_Pos)

#define LM3S_AC_MIS_IN0_Pos                       0
#define LM3S_AC_MIS_IN0_Msk                      (1UL /*<< LM3S_AC_MIS_IN0_Pos*/)

/* LM3S_AC RIS Register Definitions */
#define LM3S_AC_RIS_IN2_Pos                       2
#define LM3S_AC_RIS_IN2_Msk                      (1UL << LM3S_AC_RIS_IN2_Pos)

#define LM3S_AC_RIS_IN1_Pos                       1
#define LM3S_AC_RIS_IN1_Msk                      (1UL << LM3S_AC_RIS_IN1_Pos)

#define LM3S_AC_RIS_IN0_Pos                       0
#define LM3S_AC_RIS_IN0_Msk                      (1UL /*<< LM3S_AC_RIS_IN0_Pos*/)

/* LM3S_AC EN Register Definitions */
#define LM3S_AC_EN_IN2_Pos                        2
#define LM3S_AC_EN_IN2_Msk                       (1UL << LM3S_AC_EN_IN2_Pos)

#define LM3S_AC_EN_IN1_Pos                        1
#define LM3S_AC_EN_IN1_Msk                       (1UL << LM3S_AC_EN_IN1_Pos)

#define LM3S_AC_EN_IN0_Pos                        0
#define LM3S_AC_EN_IN0_Msk                       (1UL /*<< LM3S_AC_EN_IN0_Pos*/)

/* LM3S_AC REFCTL Register Definitions */
#define LM3S_AC_REFCTL_EN_Pos                     9
#define LM3S_AC_REFCTL_EN_Msk                    (1UL << LM3S_AC_REFCTL_EN_Pos)

#define LM3S_AC_REFCTL_RNG_Pos                    8
#define LM3S_AC_REFCTL_RNG_Msk                   (1UL << LM3S_AC_REFCTL_RNG_Pos)

#define LM3S_AC_REFCTL_VREF_Pos                   0
#define LM3S_AC_REFCTL_VREF_Msk                  (0x0000000FUL /*<< LM3S_AC_REFCTL_VREF_Pos*/)

/* LM3S_AC STAT Register Definitions */
#define LM3S_AC_STAT_OVAL_Pos                     1
#define LM3S_AC_STAT_OVAL_Msk                    (1UL << LM3S_AC_STAT_OVAL_Pos)

/* LM3S_AC CTL Register Definitions */
#define LM3S_AC_CTL_TOEN_Pos                     11
#define LM3S_AC_CTL_TOEN_Msk                     (1UL << LM3S_AC_CTL_TOEN_Pos)

#define LM3S_AC_CTL_ASRCP_Pos                     9
#define LM3S_AC_CTL_ASRCP_Msk                    (0x00000003UL << LM3S_AC_CTL_ASRCP_Pos)
#define LM3S_AC_CTL_ASRCP_1_Pos                  10
#define LM3S_AC_CTL_ASRCP_1_Msk                  (1UL << LM3S_AC_CTL_ASRCP_1_Pos)
#define LM3S_AC_CTL_ASRCP_0_Pos                   9
#define LM3S_AC_CTL_ASRCP_0_Msk                  (1UL << LM3S_AC_CTL_ASRCP_0_Pos)

#define LM3S_AC_CTL_TSLVAL_Pos                    7
#define LM3S_AC_CTL_TSLVAL_Msk                   (1UL << LM3S_AC_CTL_TSLVAL_Pos)

#define LM3S_AC_CTL_TSEN_Pos                      5
#define LM3S_AC_CTL_TSEN_Msk                     (0x00000003UL << LM3S_AC_CTL_TSEN_Pos)
#define LM3S_AC_CTL_TSEN_1_Pos                    6
#define LM3S_AC_CTL_TSEN_1_Msk                   (1UL << LM3S_AC_CTL_TSEN_1_Pos)
#define LM3S_AC_CTL_TSEN_0_Pos                    5
#define LM3S_AC_CTL_TSEN_0_Msk                   (1UL << LM3S_AC_CTL_TSEN_0_Pos)

#define LM3S_AC_CTL_ISLVAL_Pos                    4
#define LM3S_AC_CTL_ISLVAL_Msk                   (1UL << LM3S_AC_CTL_ISLVAL_Pos)

#define LM3S_AC_CTL_ISEN_Pos                      2
#define LM3S_AC_CTL_ISEN_Msk                     (0x00000003UL << LM3S_AC_CTL_ISEN_Pos)
#define LM3S_AC_CTL_ISEN_1_Pos                    3
#define LM3S_AC_CTL_ISEN_1_Msk                   (1UL << LM3S_AC_CTL_ISEN_1_Pos)
#define LM3S_AC_CTL_ISEN_0_Pos                    2
#define LM3S_AC_CTL_ISEN_0_Msk                   (1UL << LM3S_AC_CTL_ISEN_0_Pos)

#define LM3S_AC_CTL_CINV_Pos                      1
#define LM3S_AC_CTL_CINV_Msk                     (1UL << LM3S_AC_CTL_CINV_Pos)

/* ================================================================================ */
/* ================                       CAN                      ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  CTL;                  /* Offset: 0x000 (R/W) Control Register */
  __IOM uint32_t  STS;                  /* Offset: 0x004 (R/W) Status Register */
  __IM  uint32_t  ERR;                  /* Offset: 0x008 (R/ ) Error Counter Register */
  __IOM uint32_t  BIT;                  /* Offset: 0x00C (R/W) Bit Timing Register */
  __IM  uint32_t  INT;                  /* Offset: 0x010 (R/ ) Interrupt Register */
  __IOM uint32_t  TST;                  /* Offset: 0x014 (R/W) Test Register */
  __IOM uint32_t  BRPE;                 /* Offset: 0x018 (R/W) Baud Rate Prescaler Extension Register */
  __IM  uint32_t  RESERVED0;
  __IOM uint32_t  IF1CRQ;               /* Offset: 0x020 (R/W) IF1 Command Request Register */
  __IOM uint32_t  IF1CMSK;              /* Offset: 0x024 (R/W) IF1 Command Mask Register */
  __IOM uint32_t  IF1MSK1;              /* Offset: 0x028 (R/W) IF1 Mask 1 Register */
  __IOM uint32_t  IF1MSK2;              /* Offset: 0x02C (R/W) IF1 Mask 2 Register */
  __IOM uint32_t  IF1ARB1;              /* Offset: 0x030 (R/W) IF1 Arbitration 1 Register */
  __IOM uint32_t  IF1ARB2;              /* Offset: 0x034 (R/W) IF1 Arbitration 2 Register */
  __IOM uint32_t  IF1MCTL;              /* Offset: 0x038 (R/W) IF1 Message Control Register */
  __IOM uint32_t  IF1DA1;               /* Offset: 0x03C (R/W) IF1 Data A1 Register */
  __IOM uint32_t  IF1DA2;               /* Offset: 0x040 (R/W) IF1 Data A2 Register */
  __IOM uint32_t  IF1DB1;               /* Offset: 0x044 (R/W) IF1 Data B1 Register */
  __IOM uint32_t  IF1DB2;               /* Offset: 0x048 (R/W) IF1 Data B2 Register */
  __IM  uint32_t  RESERVED1[13];
  __IOM uint32_t  IF2CRQ;               /* Offset: 0x080 (R/W) IF2 Command Request Register */
  __IOM uint32_t  IF2CMSK;              /* Offset: 0x084 (R/W) IF2 Command Mask Register */
  __IOM uint32_t  IF2MSK1;              /* Offset: 0x088 (R/W) IF2 Mask 1 Register */
  __IOM uint32_t  IF2MSK2;              /* Offset: 0x08C (R/W) IF2 Mask 2 Register */
  __IOM uint32_t  IF2ARB1;              /* Offset: 0x090 (R/W) IF2 Arbitration 1 Register */
  __IOM uint32_t  IF2ARB2;              /* Offset: 0x094 (R/W) IF2 Arbitration 2 Register */
  __IOM uint32_t  IF2MCTL;              /* Offset: 0x098 (R/W) IF2 Message Control Register */
  __IOM uint32_t  IF2DA1;               /* Offset: 0x09C (R/W) IF2 Data A1 Register */
  __IOM uint32_t  IF2DA2;               /* Offset: 0x0A0 (R/W) IF2 Data A2 Register */
  __IOM uint32_t  IF2DB1;               /* Offset: 0x0A4 (R/W) IF2 Data B1 Register */
  __IOM uint32_t  IF2DB2;               /* Offset: 0x0A8 (R/W) IF2 Data B2 Register */
  __IM  uint32_t  RESERVED2[21];
  __IM  uint32_t  TXRQ1;                /* Offset: 0x100 (R/ ) Transmission Request 1 Register */
  __IM  uint32_t  TXRQ2;                /* Offset: 0x104 (R/ ) Transmission Request 2 Register */
  __IM  uint32_t  RESERVED3[6];
  __IM  uint32_t  NWDA1;                /* Offset: 0x120 (R/ ) New Data 1 Register */
  __IM  uint32_t  NWDA2;                /* Offset: 0x124 (R/ ) New Data 2 Register */
  __IM  uint32_t  RESERVED4[6];
  __IM  uint32_t  MSG1INT;              /* Offset: 0x140 (R/ ) Message 1 Interrupt Pending Register */
  __IM  uint32_t  MSG2INT;              /* Offset: 0x144 (R/ ) Message 2 Interrupt Pending Register */
  __IM  uint32_t  RESERVED5[6];
  __IM  uint32_t  MSG1VAL;              /* Offset: 0x160 (R/ ) Message 1 Valid Register */
  __IM  uint32_t  MSG2VAL;              /* Offset: 0x164 (R/ ) Message 2 Valid Register */
} LM3S_CAN_TypeDef;

/* LM3S_CAN CTL Register Definitions */
#define LM3S_CAN_CTL_TEST_Pos                     7
#define LM3S_CAN_CTL_TEST_Msk                    (1UL << LM3S_CAN_CTL_TEST_Pos)

#define LM3S_CAN_CTL_CCE_Pos                      6
#define LM3S_CAN_CTL_CCE_Msk                     (1UL << LM3S_CAN_CTL_CCE_Pos)

#define LM3S_CAN_CTL_DAR_Pos                      5
#define LM3S_CAN_CTL_DAR_Msk                     (1UL << LM3S_CAN_CTL_DAR_Pos)

#define LM3S_CAN_CTL_EIE_Pos                      3
#define LM3S_CAN_CTL_EIE_Msk                     (1UL << LM3S_CAN_CTL_EIE_Pos)

#define LM3S_CAN_CTL_SIE_Pos                      2
#define LM3S_CAN_CTL_SIE_Msk                     (1UL << LM3S_CAN_CTL_SIE_Pos)

#define LM3S_CAN_CTL_IE_Pos                       1
#define LM3S_CAN_CTL_IE_Msk                      (1UL << LM3S_CAN_CTL_IE_Pos)

#define LM3S_CAN_CTL_INIT_Pos                     0
#define LM3S_CAN_CTL_INIT_Msk                    (1UL /*<< LM3S_CAN_CTL_INIT_Pos*/)

/* LM3S_CAN STS Register Definitions */
#define LM3S_CAN_STS_BOFF_Pos                     7
#define LM3S_CAN_STS_BOFF_Msk                    (1UL << LM3S_CAN_STS_BOFF_Pos)

#define LM3S_CAN_STS_EWARN_Pos                    6
#define LM3S_CAN_STS_EWARN_Msk                   (1UL << LM3S_CAN_STS_EWARN_Pos)

#define LM3S_CAN_STS_EPASS_Pos                    5
#define LM3S_CAN_STS_EPASS_Msk                   (1UL << LM3S_CAN_STS_EPASS_Pos)

#define LM3S_CAN_STS_RXOK_Pos                     4
#define LM3S_CAN_STS_RXOK_Msk                    (1UL << LM3S_CAN_STS_RXOK_Pos)

#define LM3S_CAN_STS_TXOK_Pos                     3
#define LM3S_CAN_STS_TXOK_Msk                    (1UL << LM3S_CAN_STS_TXOK_Pos)

#define LM3S_CAN_STS_LEC_Pos                      0
#define LM3S_CAN_STS_LEC_Msk                     (0x00000007UL /*<< LM3S_CAN_STS_LEC_Pos*/)
#define LM3S_CAN_STS_LEC_2_Pos                    2
#define LM3S_CAN_STS_LEC_2_Msk                   (1UL << LM3S_CAN_STS_LEC_2_Pos)
#define LM3S_CAN_STS_LEC_1_Pos                    1
#define LM3S_CAN_STS_LEC_1_Msk                   (1UL << LM3S_CAN_STS_LEC_1_Pos)
#define LM3S_CAN_STS_LEC_0_Pos                    0
#define LM3S_CAN_STS_LEC_0_Msk                   (1UL /*<< LM3S_CAN_STS_LEC_0_Pos*/)

/* LM3S_CAN ERR Register Definitions */
#define LM3S_CAN_ERR_RP_Pos                       7
#define LM3S_CAN_ERR_RP_Msk                      (1UL << LM3S_CAN_ERR_RP_Pos)

#define LM3S_CAN_ERR_REC_Pos                      8
#define LM3S_CAN_ERR_REC_Msk                     (0x0000007FUL << LM3S_CAN_ERR_REC_Pos)

#define LM3S_CAN_ERR_TEC_Pos                      0
#define LM3S_CAN_ERR_TEC_Msk                     (0x000000FFUL /*<< LM3S_CAN_ERR_TEC_Pos*/)

/* LM3S_CAN BIT Register Definitions */
#define LM3S_CAN_BIT_TSEG2_Pos                   12
#define LM3S_CAN_BIT_TSEG2_Msk                   (0x00000007UL << LM3S_CAN_BIT_TSEG2_Pos)

#define LM3S_CAN_BIT_TSEG1_Pos                    8
#define LM3S_CAN_BIT_TSEG1_Msk                   (0x0000000FUL << LM3S_CAN_BIT_TSEG1_Pos)

#define LM3S_CAN_BIT_SJW_Pos                      6
#define LM3S_CAN_BIT_SJW_Msk                     (0x00000003UL << LM3S_CAN_BIT_SJW_Pos)

#define LM3S_CAN_ERR_BRP_Pos                      0
#define LM3S_CAN_ERR_BRP_Msk                     (0x0000003FUL /*<< LM3S_CAN_ERR_BRP_Pos*/)

/* LM3S_CAN INT Register Definitions */
#define LM3S_CAN_INT_INTID_Pos                    0
#define LM3S_CAN_INT_INTID_Msk                   (0x0000FFFFUL /*<< LM3S_CAN_INT_INTID_Pos*/)

/* LM3S_CAN TST Register Definitions */
#define LM3S_CAN_TST_RX_Pos                       7
#define LM3S_CAN_TST_RX_Msk                      (1UL << LM3S_CAN_TST_RX_Pos)

#define LM3S_CAN_TST_TX_Pos                       5
#define LM3S_CAN_TST_TX_Msk                      (0x00000003UL << LM3S_CAN_INT_INTID_Pos)
#define LM3S_CAN_TST_TX_1_Pos                     6
#define LM3S_CAN_TST_TX_1_Msk                    (1UL << LM3S_CAN_TST_TX_1_Pos)
#define LM3S_CAN_TST_TX_0_Pos                     5
#define LM3S_CAN_TST_TX_0_Msk                    (1UL << LM3S_CAN_TST_TX_0_Pos)

#define LM3S_CAN_TST_LBACK_Pos                    4
#define LM3S_CAN_TST_LBACK_Msk                   (1UL << LM3S_CAN_TST_LBACK_Pos)

#define LM3S_CAN_TST_SILENT_Pos                   3
#define LM3S_CAN_TST_SILENT_Msk                  (1UL << LM3S_CAN_TST_SILENT_Pos)

#define LM3S_CAN_TST_BASIC_Pos                    2
#define LM3S_CAN_TST_BASIC_Msk                   (1UL << LM3S_CAN_TST_BASIC_Pos)

/* LM3S_CAN BRPE Register Definitions */
#define LM3S_CAN_BRPE_BRPE_Pos                    0
#define LM3S_CAN_BRPE_BRPE_Msk                   (0x0000000FUL /*<< LM3S_CAN_BRPE_BRPE_Pos*/)

/* LM3S_CAN IFNCRQ Register Definitions */
#define LM3S_CAN_IFNCRQ_BUSY_Pos                 15
#define LM3S_CAN_IFNCRQ_BUSY_Msk                 (1UL << LM3S_CAN_IFNCRQ_BUSY_Pos)

#define LM3S_CAN_IFNCRQ_MNUM_Pos                  0
#define LM3S_CAN_IFNCRQ_MNUM_Msk                 (0x0000003FUL /*<< LM3S_CAN_IFNCRQ_MNUM_Pos*/)

/* LM3S_CAN IFNCMSK Register Definitions */
#define LM3S_CAN_IFNCMSK_WRNRD_Pos                7
#define LM3S_CAN_IFNCMSK_WRNRD_Msk               (1UL << LM3S_CAN_IFNCMSK_WRNRD_Pos)

#define LM3S_CAN_IFNCMSK_MASK_Pos                 6
#define LM3S_CAN_IFNCMSK_MASK_Msk                (1UL << LM3S_CAN_IFNCMSK_MASK_Pos)

#define LM3S_CAN_IFNCMSK_ARB_Pos                  5
#define LM3S_CAN_IFNCMSK_ARB_Msk                 (1UL << LM3S_CAN_IFNCMSK_ARB_Pos)

#define LM3S_CAN_IFNCMSK_CONTROL_Pos              4
#define LM3S_CAN_IFNCMSK_CONTROL_Msk             (1UL << LM3S_CAN_IFNCMSK_CONTROL_Pos)

#define LM3S_CAN_IFNCMSK_CLRINTPND_Pos            3
#define LM3S_CAN_IFNCMSK_CLRINTPND_Msk           (1UL << LM3S_CAN_IFNCMSK_CLRINTPND_Pos)

#define LM3S_CAN_IFNCMSK_NEWDAT_TXRQST_Pos        2
#define LM3S_CAN_IFNCMSK_NEWDAT_TXRQST_Msk       (1UL << LM3S_CAN_IFNCMSK_NEWDAT_TXRQST_Pos)

#define LM3S_CAN_IFNCMSK_DATAA_Pos                1
#define LM3S_CAN_IFNCMSK_DATAA_Msk               (1UL << LM3S_CAN_IFNCMSK_DATAA_Pos)

#define LM3S_CAN_IFNCMSK_DATAB_Pos                0
#define LM3S_CAN_IFNCMSK_DATAB_Msk               (1UL /*<< LM3S_CAN_IFNCMSK_DATAB_Pos*/)

/* LM3S_CAN IFNMSK1 Register Definitions */
#define LM3S_CAN_IFNMSK1_MSK_Pos                  0
#define LM3S_CAN_IFNMSK1_MSK_Msk                 (0x0000FFFFUL /*<< LM3S_CAN_IFNMSK1_MSK_Pos*/)

/* LM3S_CAN IFNMSK2 Register Definitions */
#define LM3S_CAN_IFNMSK2_MXTD_Pos                15
#define LM3S_CAN_IFNMSK2_MXTD_Msk                (1UL << LM3S_CAN_IFNMSK2_MXTD_Pos)

#define LM3S_CAN_IFNMSK2_MDIR_Pos                14
#define LM3S_CAN_IFNMSK2_MDIR_Msk                (1UL << LM3S_CAN_IFNMSK2_MDIR_Pos)

#define LM3S_CAN_IFNMSK2_MSK_Pos                  0
#define LM3S_CAN_IFNMSK2_MSK_Msk                 (0x00001FFFUL /*<< LM3S_CAN_IFNMSK2_MSK_Pos*/)

/* LM3S_CAN IFNARB1 Register Definitions */
#define LM3S_CAN_IFNARB1_ID_Pos                   0
#define LM3S_CAN_IFNARB1_ID_Msk                  (0x0000FFFFUL /*<< LM3S_CAN_IFNARB1_ID_Pos*/)

/* LM3S_CAN IFNARB2 Register Definitions */
#define LM3S_CAN_IFNARB2_MSGVAL_Pos              15
#define LM3S_CAN_IFNARB2_MSGVAL_Msk              (1UL << LM3S_CAN_IFNARB2_MSGVAL_Pos)

#define LM3S_CAN_IFNARB2_XTD_Pos                 14
#define LM3S_CAN_IFNARB2_XTD_Msk                 (1UL << LM3S_CAN_IFNARB2_XTD_Pos)

#define LM3S_CAN_IFNARB2_DIR_Pos                 13
#define LM3S_CAN_IFNARB2_DIR_Msk                 (1UL << LM3S_CAN_IFNARB2_DIR_Pos)

#define LM3S_CAN_IFNARB2_MSK_Pos                  0
#define LM3S_CAN_IFNARB2_MSK_Msk                 (0x00001FFFUL /*<< LM3S_CAN_IFNARB2_MSK_Pos*/)

/* LM3S_CAN IFNMCTL Register Definitions */
#define LM3S_CAN_IFNMCTL_NEWDAT_Pos              15
#define LM3S_CAN_IFNMCTL_NEWDAT_Msk              (1UL << LM3S_CAN_IFNMCTL_NEWDAT_Pos)

#define LM3S_CAN_IFNMCTL_MSGLST_Pos              14
#define LM3S_CAN_IFNMCTL_MSGLST_Msk              (1UL << LM3S_CAN_IFNMCTL_MSGLST_Pos)

#define LM3S_CAN_IFNMCTL_INTPND_Pos              13
#define LM3S_CAN_IFNMCTL_INTPND_Msk              (1UL << LM3S_CAN_IFNMCTL_INTPND_Pos)

#define LM3S_CAN_IFNMCTL_UMASK_Pos               12
#define LM3S_CAN_IFNMCTL_UMASK_Msk               (1UL << LM3S_CAN_IFNMCTL_UMASK_Pos)

#define LM3S_CAN_IFNMCTL_TXIE_Pos                11
#define LM3S_CAN_IFNMCTL_TXIE_Msk                (1UL << LM3S_CAN_IFNMCTL_TXIE_Pos)

#define LM3S_CAN_IFNMCTL_RXIE_Pos                10
#define LM3S_CAN_IFNMCTL_RXIE_Msk                (1UL << LM3S_CAN_IFNMCTL_RXIE_Pos)

#define LM3S_CAN_IFNMCTL_RMTEN_Pos                9
#define LM3S_CAN_IFNMCTL_RMTEN_Msk               (1UL << LM3S_CAN_IFNMCTL_RMTEN_Pos)

#define LM3S_CAN_IFNMCTL_TXRQST_Pos               8
#define LM3S_CAN_IFNMCTL_TXRQST_Msk              (1UL << LM3S_CAN_IFNMCTL_TXRQST_Pos)

#define LM3S_CAN_IFNMCTL_EOB_Pos                  7
#define LM3S_CAN_IFNMCTL_EOB_Msk                 (1UL << LM3S_CAN_IFNMCTL_EOB_Pos)

#define LM3S_CAN_IFNMCTL_DLC_Pos                  0
#define LM3S_CAN_IFNMCTL_DLC_Msk                 (1UL /*<< LM3S_CAN_IFNMCTL_NEWDAT_Pos*/)

/* LM3S_CAN IFNDAN Register Definitions */
#define LM3S_CAN_IFNDAN_DATA_Pos                  0
#define LM3S_CAN_IFNDAN_DATA_Msk                 (0x0000FFFFUL /*<< LM3S_CAN_IFNDAN_DATA_Pos*/)

/* LM3S_CAN TXRQN Register Definitions */
#define LM3S_CAN_TXRQN_TXRQST_Pos                 0
#define LM3S_CAN_TXRQN_TXRQST_Msk                (0x0000FFFFUL /*<< LM3S_CAN_TXRQN_TXRQST_Pos*/)

/* LM3S_CAN NWDAN Register Definitions */
#define LM3S_CAN_NWDAN_NEWDAT_Pos                 0
#define LM3S_CAN_NWDAN_NEWDAT_Msk                (0x0000FFFFUL /*<< LM3S_CAN_NWDAN_NEWDAT_Pos*/)

/* LM3S_CAN MSGNINT Register Definitions */
#define LM3S_CAN_MSGNINT_INTPND_Pos               0
#define LM3S_CAN_MSGNINT_INTPND_Msk              (0x0000FFFFUL /*<< LM3S_CAN_MSGNINT_INTPND_Pos*/)

/* LM3S_CAN MSGNVAL Register Definitions */
#define LM3S_CAN_MSGNVAL_MSGVAL_Pos               0
#define LM3S_CAN_MSGNVAL_MSGVAL_Msk              (0x0000FFFFUL /*<< LM3S_CAN_MSGNVAL_MSGVAL_Pos*/)

/* ================================================================================ */
/* ================                    Ethernet                    ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  RISIASK;              /* Offset: 0x000 (R/W) Raw Interrupt Status/Acknowledge Register */
  __IOM uint32_t  IM;                   /* Offset: 0x004 (R/W) Interrupt Mask Register */
  __IOM uint32_t  RCTL;                 /* Offset: 0x008 (R/W) Receive Control Register */
  __IOM uint32_t  TCTL;                 /* Offset: 0x00C (R/W) Transmit Control Register */
  __IOM uint32_t  DATA;                 /* Offset: 0x010 (R/W) Data Register */
  __IOM uint32_t  IA0;                  /* Offset: 0x014 (R/W) Individual Address 0 Register */
  __IOM uint32_t  IA1;                  /* Offset: 0x018 (R/W) Individual Address 1 Register */
  __IOM uint32_t  THR;                  /* Offset: 0x01C (R/W) Threshold Register */
  __IOM uint32_t  MCTL;                 /* Offset: 0x020 (R/W) Management Control Register */
  __IOM uint32_t  MDV;                  /* Offset: 0x024 (R/W) Management Divider Register */
  __IM  uint32_t  RESERVED0;
  __IOM uint32_t  MTXD;                 /* Offset: 0x02C (R/W) Management Transmit Data Register */
  __IOM uint32_t  MRXD;                 /* Offset: 0x030 (R/W) Management Receive Data Register */
  __IM  uint32_t  NP;                   /* Offset: 0x034 (R/ ) Number of Packets Register */
  __IOM uint32_t  TR;                   /* Offset: 0x038 (R/W) Transmission Request Register */
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  LED;                  /* Offset: 0x040 (R/W) LED Encoding Register */
  __IOM uint32_t  MDIX;                 /* Offset: 0x044 (R/W) PHY MDIX Register */
} LM3S_ETHMAC_TypeDef;

/* LM3S_ETHMAC RISIASK Register Definitions */
#define LM3S_ETHMAC_RISIASK_PHYINT_Pos            6
#define LM3S_ETHMAC_RISIASK_PHYINT_Msk           (1UL << LM3S_ETHMAC_RISIASK_PHYINT_Pos)

#define LM3S_ETHMAC_RISIASK_MDINT_Pos             5
#define LM3S_ETHMAC_RISIASK_MDINT_Msk            (1UL << LM3S_ETHMAC_RISIASK_MDINT_Pos)

#define LM3S_ETHMAC_RISIASK_RXER_Pos              4
#define LM3S_ETHMAC_RISIASK_RXER_Msk             (1UL << LM3S_ETHMAC_RISIASK_RXER_Pos)

#define LM3S_ETHMAC_RISIASK_FOV_Pos               3
#define LM3S_ETHMAC_RISIASK_FOV_Msk              (1UL << LM3S_ETHMAC_RISIASK_FOV_Pos)

#define LM3S_ETHMAC_RISIASK_TXEMP_Pos             2
#define LM3S_ETHMAC_RISIASK_TXEMP_Msk            (1UL << LM3S_ETHMAC_RISIASK_TXEMP_Pos)

#define LM3S_ETHMAC_RISIASK_TXER_Pos              1
#define LM3S_ETHMAC_RISIASK_TXER_Msk             (1UL << LM3S_ETHMAC_RISIASK_TXER_Pos)

#define LM3S_ETHMAC_RISIASK_RXINT_Pos             0
#define LM3S_ETHMAC_RISIASK_RXINT_Msk            (1UL /*<< LM3S_ETHMAC_RISIASK_RXINT_Pos*/)

/* LM3S_ETHMAC IM Register Definitions */
#define LM3S_ETHMAC_IM_PHYINTM_Pos                6
#define LM3S_ETHMAC_IM_PHYINTM_Msk               (1UL << LM3S_ETHMAC_IM_PHYINTM_Pos)

#define LM3S_ETHMAC_IM_MDINTM_Pos                 5
#define LM3S_ETHMAC_IM_MDINTM_Msk                (1UL << LM3S_ETHMAC_IM_MDINTM_Pos)

#define LM3S_ETHMAC_IM_RXERM_Pos                  4
#define LM3S_ETHMAC_IM_RXERM_Msk                 (1UL << LM3S_ETHMAC_IM_RXERM_Pos)

#define LM3S_ETHMAC_IM_FOVM_Pos                   3
#define LM3S_ETHMAC_IM_FOVM_Msk                  (1UL << LM3S_ETHMAC_IM_FOVM_Pos)

#define LM3S_ETHMAC_IM_TXEMPM_Pos                 2
#define LM3S_ETHMAC_IM_TXEMPM_Msk                (1UL << LM3S_ETHMAC_IM_TXEMPM_Pos)

#define LM3S_ETHMAC_IM_TXERM_Pos                  1
#define LM3S_ETHMAC_IM_TXERM_Msk                 (1UL << LM3S_ETHMAC_IM_TXERM_Pos)

#define LM3S_ETHMAC_IM_RXINTM_Pos                 0
#define LM3S_ETHMAC_IM_RXINTM_Msk                (1UL /*<< LM3S_ETHMAC_IM_RXINTM_Pos*/)

/* LM3S_ETHMAC RCTL Register Definitions */
#define LM3S_ETHMAC_RCTL_RSTFIFO_Pos              4
#define LM3S_ETHMAC_RCTL_RSTFIFO_Msk             (1UL << LM3S_ETHMAC_RCTL_RSTFIFO_Pos)

#define LM3S_ETHMAC_RCTL_BADCRC_Pos               3
#define LM3S_ETHMAC_RCTL_BADCRC_Msk              (1UL << LM3S_ETHMAC_RCTL_BADCRC_Pos)

#define LM3S_ETHMAC_RCTL_PRMS_Pos                 2
#define LM3S_ETHMAC_RCTL_PRMS_Msk                (1UL << LM3S_ETHMAC_RCTL_PRMS_Pos)

#define LM3S_ETHMAC_RCTL_AMUL_Pos                 1
#define LM3S_ETHMAC_RCTL_AMUL_Msk                (1UL << LM3S_ETHMAC_RCTL_AMUL_Pos)

#define LM3S_ETHMAC_RCTL_RXEN_Pos                 0
#define LM3S_ETHMAC_RCTL_RXEN_Msk                (1UL /*<< LM3S_ETHMAC_RCTL_RXEN_Pos*/)

/* LM3S_ETHMAC TCTL Register Definitions */
#define LM3S_ETHMAC_TCTL_DUPLEX_Pos               4
#define LM3S_ETHMAC_TCTL_DUPLEX_Msk              (1UL << LM3S_ETHMAC_TCTL_DUPLEX_Pos)

#define LM3S_ETHMAC_TCTL_CRC_Pos                  2
#define LM3S_ETHMAC_TCTL_CRC_Msk                 (1UL << LM3S_ETHMAC_TCTL_CRC_Pos)

#define LM3S_ETHMAC_TCTL_PADEN_Pos                1
#define LM3S_ETHMAC_TCTL_PADEN_Msk               (1UL << LM3S_ETHMAC_TCTL_PADEN_Pos)

#define LM3S_ETHMAC_TCTL_TXEN_Pos                 0
#define LM3S_ETHMAC_TCTL_TXEN_Msk                (1UL /*<< LM3S_ETHMAC_TCTL_TXEN_Pos*/)

/* LM3S_ETHMAC DATA Register Definitions */
#define LM3S_ETHMAC_DATA_RXDATA_Pos               0
#define LM3S_ETHMAC_DATA_RXDATA_Msk              (0xFFFFFFFFUL /*<< LM3S_ETHMAC_DATA_TXDATA_Pos*/)

#define LM3S_ETHMAC_DATA_RXDATA_Pos               0
#define LM3S_ETHMAC_DATA_RXDATA_Msk              (0xFFFFFFFFUL /*<< LM3S_ETHMAC_DATA_RXDATA_Pos*/)

/* LM3S_ETHMAC IA0 Register Definitions */
#define LM3S_ETHMAC_IA0_MACOCT4_Pos              24
#define LM3S_ETHMAC_IA0_MACOCT4_Msk              (0x000000FFUL << LM3S_ETHMAC_IA0_MACOCT4_Pos)

#define LM3S_ETHMAC_IA0_MACOCT3_Pos              16
#define LM3S_ETHMAC_IA0_MACOCT3_Msk              (0x000000FFUL << LM3S_ETHMAC_IA0_MACOCT3_Pos)

#define LM3S_ETHMAC_IA0_MACOCT2_Pos               8
#define LM3S_ETHMAC_IA0_MACOCT2_Msk              (0x000000FFUL << LM3S_ETHMAC_IA0_MACOCT2_Pos)

#define LM3S_ETHMAC_IA0_MACOCT1_Pos               0
#define LM3S_ETHMAC_IA0_MACOCT1_Msk              (0x000000FFUL /*<< LM3S_ETHMAC_IA0_MACOCT1_Pos*/)

/* LM3S_ETHMAC IA1 Register Definitions */
#define LM3S_ETHMAC_IA1_MACOCT6_Pos               8
#define LM3S_ETHMAC_IA1_MACOCT6_Msk              (0x000000FFUL << LM3S_ETHMAC_IA1_MACOCT6_Pos)

#define LM3S_ETHMAC_IA1_MACOCT5_Pos               0
#define LM3S_ETHMAC_IA1_MACOCT5_Msk              (0x000000FFUL /*<< LM3S_ETHMAC_IA1_MACOCT5_Pos*/)

/* LM3S_ETHMAC THR Register Definitions */
#define LM3S_ETHMAC_THR_THRESH_Pos                0
#define LM3S_ETHMAC_THR_THRESH_Msk               (0x0000003FUL /*<< LM3S_ETHMAC_THR_THRESH_Pos*/)

/* LM3S_ETHMAC MCTL Register Definitions */
#define LM3S_ETHMAC_MCTL_REGADR_Pos               3
#define LM3S_ETHMAC_MCTL_REGADR_Msk              (0x0000001FUL << LM3S_ETHMAC_MCTL_REGADR_Pos)

#define LM3S_ETHMAC_MCTL_WRITE_Pos                2
#define LM3S_ETHMAC_MCTL_WRITE_Msk               (1UL << LM3S_ETHMAC_MCTL_WRITE_Pos)

#define LM3S_ETHMAC_MCTL_START_Pos                0
#define LM3S_ETHMAC_MCTL_START_Msk               (1UL /*<< LM3S_ETHMAC_MCTL_START_Pos*/)

/* LM3S_ETHMAC MTXD Register Definitions */
#define LM3S_ETHMAC_MTXD_MDTX_Pos                 0
#define LM3S_ETHMAC_MTXD_MDTX_Msk                (0x0000FFFFUL /*<< LM3S_ETHMAC_MTXD_MDTX_Pos*/)

/* LM3S_ETHMAC MRXD Register Definitions */
#define LM3S_ETHMAC_MRXD_MDRX_Pos                 0
#define LM3S_ETHMAC_MRXD_MDRX_Msk                (0x0000FFFFUL /*<< LM3S_ETHMAC_MRXD_MDRX_Pos*/)

/* LM3S_ETHMAC NP Register Definitions */
#define LM3S_ETHMAC_NP_NPR_Pos                    0
#define LM3S_ETHMAC_NP_NPR_Msk                   (0x0000003FUL /*<< LM3S_ETHMAC_NP_NPR_Pos*/)

/* LM3S_ETHMAC TR Register Definitions */
#define LM3S_ETHMAC_TR_NEWTX_Pos                  0
#define LM3S_ETHMAC_TR_NEWTX_Msk                 (1UL /*<< LM3S_ETHMAC_TR_NEWTX_Pos*/)

/* LM3S_ETHMAC LED Register Definitions */
#define LM3S_ETHMAC_LED_LED1_Pos                  8
#define LM3S_ETHMAC_LED_LED1_Msk                 (0x0000000FUL << LM3S_ETHMAC_LED_LED1_Pos)
#define LM3S_ETHMAC_LED_LED1_3_Pos               11
#define LM3S_ETHMAC_LED_LED1_3_Msk               (1UL << LM3S_ETHMAC_LED_LED1_3_Pos)
#define LM3S_ETHMAC_LED_LED1_2_Pos               10
#define LM3S_ETHMAC_LED_LED1_2_Msk               (1UL << LM3S_ETHMAC_LED_LED1_2_Pos)
#define LM3S_ETHMAC_LED_LED1_1_Pos                9
#define LM3S_ETHMAC_LED_LED1_1_Msk               (1UL << LM3S_ETHMAC_LED_LED1_1_Pos)
#define LM3S_ETHMAC_LED_LED1_0_Pos                8
#define LM3S_ETHMAC_LED_LED1_0_Msk               (1UL << LM3S_ETHMAC_LED_LED1_0_Pos)

#define LM3S_ETHMAC_LED_LED0_Pos                  0
#define LM3S_ETHMAC_LED_LED0_Msk                 (0x0000000FUL /*<< LM3S_ETHMAC_LED_LED0_Pos*/)
#define LM3S_ETHMAC_LED_LED0_3_Pos                3
#define LM3S_ETHMAC_LED_LED0_3_Msk               (1UL << LM3S_ETHMAC_LED_LED0_3_Pos)
#define LM3S_ETHMAC_LED_LED0_2_Pos                2
#define LM3S_ETHMAC_LED_LED0_2_Msk               (1UL << LM3S_ETHMAC_LED_LED0_2_Pos)
#define LM3S_ETHMAC_LED_LED0_1_Pos                1
#define LM3S_ETHMAC_LED_LED0_1_Msk               (1UL << LM3S_ETHMAC_LED_LED0_1_Pos)
#define LM3S_ETHMAC_LED_LED0_0_Pos                0
#define LM3S_ETHMAC_LED_LED0_0_Msk               (1UL /*<< LM3S_ETHMAC_LED_LED0_0_Pos*/)

/* LM3S_ETHMAC MDIX Register Definitions */
#define LM3S_ETHMAC_MDIX_EN_Pos                   0
#define LM3S_ETHMAC_MDIX_EN_Msk                  (1UL /*<< LM3S_ETHMAC_MDIX_EN_Pos*/)

/* LM3S_ETHMAC MR0 Register Definitions */
#define LM3S_ETHMAC_MR0_RESET_Pos                15
#define LM3S_ETHMAC_MR0_RESET_Msk                (1UL << LM3S_ETHMAC_MR0_RESET_Pos)

#define LM3S_ETHMAC_MR0_LOOPBK_Pos               14
#define LM3S_ETHMAC_MR0_LOOPBK_Msk               (1UL << LM3S_ETHMAC_MR0_LOOPBK_Pos)

#define LM3S_ETHMAC_MR0_SPEEDSL_Pos              13
#define LM3S_ETHMAC_MR0_SPEEDSL_Msk              (1UL << LM3S_ETHMAC_MR0_SPEEDSL_Pos)

#define LM3S_ETHMAC_MR0_ANEGEN_Pos               12
#define LM3S_ETHMAC_MR0_ANEGEN_Msk               (1UL << LM3S_ETHMAC_MR0_ANEGEN_Pos)

#define LM3S_ETHMAC_MR0_PWRDN_Pos                11
#define LM3S_ETHMAC_MR0_PWRDN_Msk                (1UL << LM3S_ETHMAC_MR0_PWRDN_Pos)

#define LM3S_ETHMAC_MR0_ISO_Pos                  10
#define LM3S_ETHMAC_MR0_ISO_Msk                  (1UL << LM3S_ETHMAC_MR0_ISO_Pos)

#define LM3S_ETHMAC_MR0_RANEG_Pos                 9
#define LM3S_ETHMAC_MR0_RANEG_Msk                (1UL << LM3S_ETHMAC_MR0_RANEG_Pos)

#define LM3S_ETHMAC_MR0_DUPLEX_Pos                8
#define LM3S_ETHMAC_MR0_DUPLEX_Msk               (1UL << LM3S_ETHMAC_MR0_DUPLEX_Pos)

#define LM3S_ETHMAC_MR0_COLT_Pos                  7
#define LM3S_ETHMAC_MR0_COLT_Msk                 (1UL << LM3S_ETHMAC_MR0_COLT_Pos)

/* LM3S_ETHMAC MR1 Register Definitions */
#define LM3S_ETHMAC_MR1_100X_F_Pos               14
#define LM3S_ETHMAC_MR1_100X_F_Msk               (1UL << LM3S_ETHMAC_MR1_100X_F_Pos)

#define LM3S_ETHMAC_MR1_100X_H_Pos               13
#define LM3S_ETHMAC_MR1_100X_H_Msk               (1UL << LM3S_ETHMAC_MR1_100X_H_Pos)

#define LM3S_ETHMAC_MR1_10T_F_Pos                12
#define LM3S_ETHMAC_MR1_10T_F_Msk                (1UL << LM3S_ETHMAC_MR1_10T_F_Pos)

#define LM3S_ETHMAC_MR1_10T_H_Pos                11
#define LM3S_ETHMAC_MR1_10T_H_Msk                (1UL << LM3S_ETHMAC_MR1_10T_H_Pos)

#define LM3S_ETHMAC_MR1_ANEGC_Pos                 5
#define LM3S_ETHMAC_MR1_ANEGC_Msk                (1UL << LM3S_ETHMAC_MR1_ANEGC_Pos)

#define LM3S_ETHMAC_MR1_RFAULT_Pos                4
#define LM3S_ETHMAC_MR1_RFAULT_Msk               (1UL << LM3S_ETHMAC_MR1_RFAULT_Pos)

#define LM3S_ETHMAC_MR1_ANEGA_Pos                 3
#define LM3S_ETHMAC_MR1_ANEGA_Msk                (1UL << LM3S_ETHMAC_MR1_ANEGA_Pos)

#define LM3S_ETHMAC_MR1_LINK_Pos                  2
#define LM3S_ETHMAC_MR1_LINK_Msk                 (1UL << LM3S_ETHMAC_MR1_LINK_Pos)

#define LM3S_ETHMAC_MR1_JAB_Pos                   1
#define LM3S_ETHMAC_MR1_JAB_Msk                  (1UL << LM3S_ETHMAC_MR1_JAB_Pos)

#define LM3S_ETHMAC_MR1_EXTD_Pos                  0
#define LM3S_ETHMAC_MR1_EXTD_Msk                 (1UL << LM3S_ETHMAC_MR1_EXTD_Pos)

/* LM3S_ETHMAC MR2 Register Definitions */
#define LM3S_ETHMAC_MR2_OUI21_6_Pos               0
#define LM3S_ETHMAC_MR2_OUI21_6_Msk              (0xFFFFFFFFUL /*<< LM3S_ETHMAC_MR2_OUI21_1_Pos*/)

/* LM3S_ETHMAC MR3 Register Definitions */
#define LM3S_ETHMAC_MR3_OUI5_0_Pos               10
#define LM3S_ETHMAC_MR3_OUI5_0_Msk               (0x0000003FUL << LM3S_ETHMAC_MR3_OUI5_0_Pos)

#define LM3S_ETHMAC_MR3_MN_Pos                    4
#define LM3S_ETHMAC_MR3_MN_Msk                   (0x0000003FUL << LM3S_ETHMAC_MR3_MN_Pos)

#define LM3S_ETHMAC_MR3_RN_Pos                    0
#define LM3S_ETHMAC_MR3_RN_Msk                   (0x0000000FUL /*<< LM3S_ETHMAC_MR3_RN_Pos*/)

/* LM3S_ETHMAC MR4 Register Definitions */
#define LM3S_ETHMAC_MR4_NP_Pos                   15
#define LM3S_ETHMAC_MR4_NP_Msk                   (1UL << LM3S_ETHMAC_MR4_NP_Pos)

#define LM3S_ETHMAC_MR4_RF_Pos                   13
#define LM3S_ETHMAC_MR4_RF_Msk                   (1UL << LM3S_ETHMAC_MR4_RF_Pos)

#define LM3S_ETHMAC_MR4_A3_Pos                    8
#define LM3S_ETHMAC_MR4_A3_Msk                   (1UL << LM3S_ETHMAC_MR4_A3_Pos)

#define LM3S_ETHMAC_MR4_A2_Pos                    7
#define LM3S_ETHMAC_MR4_A2_Msk                   (1UL << LM3S_ETHMAC_MR4_A2_Pos)

#define LM3S_ETHMAC_MR4_A1_Pos                    6
#define LM3S_ETHMAC_MR4_A1_Msk                   (1UL << LM3S_ETHMAC_MR4_A1_Pos)

#define LM3S_ETHMAC_MR4_A0_Pos                    5
#define LM3S_ETHMAC_MR4_A0_Msk                   (1UL << LM3S_ETHMAC_MR4_A0_Pos)

#define LM3S_ETHMAC_MR4_S_Pos                     0
#define LM3S_ETHMAC_MR4_S_Msk                    (0x0000001FUL /*<< LM3S_ETHMAC_MR4_S_Pos*/)

/* LM3S_ETHMAC MR5 Register Definitions */
#define LM3S_ETHMAC_MR5_NP_Pos                   15
#define LM3S_ETHMAC_MR5_NP_Msk                   (1UL << LM3S_ETHMAC_MR5_NP_Pos)

#define LM3S_ETHMAC_MR5_ACK_Pos                  14
#define LM3S_ETHMAC_MR5_ACK_Msk                  (1UL << LM3S_ETHMAC_MR5_ACK_Pos)

#define LM3S_ETHMAC_MR5_RF_Pos                   13
#define LM3S_ETHMAC_MR5_RF_Msk                   (1UL << LM3S_ETHMAC_MR5_RF_Pos)

#define LM3S_ETHMAC_MR5_A_Pos                     5
#define LM3S_ETHMAC_MR5_A_Msk                    (1UL << LM3S_ETHMAC_MR5_A_Pos)

#define LM3S_ETHMAC_MR5_S_Pos                     0
#define LM3S_ETHMAC_MR5_S_Msk                    (0x0000001FUL /*<< LM3S_ETHMAC_MR5_S_Pos*/)
#define LM3S_ETHMAC_MR5_S_4_Pos                   4
#define LM3S_ETHMAC_MR5_S_4_Msk                  (1UL << LM3S_ETHMAC_MR5_S_4_Pos)
#define LM3S_ETHMAC_MR5_S_3_Pos                   3
#define LM3S_ETHMAC_MR5_S_3_Msk                  (1UL << LM3S_ETHMAC_MR5_S_3_Pos)
#define LM3S_ETHMAC_MR5_S_2_Pos                   2
#define LM3S_ETHMAC_MR5_S_2_Msk                  (1UL << LM3S_ETHMAC_MR5_S_2_Pos)
#define LM3S_ETHMAC_MR5_S_1_Pos                   1
#define LM3S_ETHMAC_MR5_S_1_Msk                  (1UL << LM3S_ETHMAC_MR5_S_1_Pos)
#define LM3S_ETHMAC_MR5_S_0_Pos                   0
#define LM3S_ETHMAC_MR5_S_0_Msk                  (1UL /*<< LM3S_ETHMAC_MR5_S_0_Pos*/)

/* LM3S_ETHMAC MR6 Register Definitions */
#define LM3S_ETHMAC_MR6_PDF_Pos                   4
#define LM3S_ETHMAC_MR6_PDF_Msk                  (1UL << LM3S_ETHMAC_MR6_PDF_Pos)

#define LM3S_ETHMAC_MR6_LPNPA_Pos                 3
#define LM3S_ETHMAC_MR6_LPNPA_Msk                (1UL << LM3S_ETHMAC_MR6_LPNPA_Pos)

#define LM3S_ETHMAC_MR6_PRX_Pos                   1
#define LM3S_ETHMAC_MR6_PRX_Msk                  (1UL << LM3S_ETHMAC_MR6_PRX_Pos)

#define LM3S_ETHMAC_MR6_LPANEGA_Pos               0
#define LM3S_ETHMAC_MR6_LPANEGA_Msk              (1UL /*<< LM3S_ETHMAC_MR6_LPANEGA_Pos*/)

/* LM3S_ETHMAC MR16 Register Definitions */
#define LM3S_ETHMAC_MR16_SR_Pos                   6
#define LM3S_ETHMAC_MR16_SR_Msk                  (0x0000000FUL << LM3S_ETHMAC_MR16_SR_Pos)

/* LM3S_ETHMAC MR17 Register Definitions */
#define LM3S_ETHMAC_MR17_FASTRIP_Pos             14
#define LM3S_ETHMAC_MR17_FASTRIP_Msk             (1UL << LM3S_ETHMAC_MR17_FASTRIP_Pos)

#define LM3S_ETHMAC_MR17_EDPD_Pos                13
#define LM3S_ETHMAC_MR17_EDPD_Msk                (1UL << LM3S_ETHMAC_MR17_EDPD_Pos)

#define LM3S_ETHMAC_MR17_LSQE_Pos                11
#define LM3S_ETHMAC_MR17_LSQE_Msk                (1UL << LM3S_ETHMAC_MR17_LSQE_Pos)

#define LM3S_ETHMAC_MR17_FASTEST_Pos              8
#define LM3S_ETHMAC_MR17_FASTEST_Msk             (1UL << LM3S_ETHMAC_MR17_FASTEST_Pos)

#define LM3S_ETHMAC_MR17_FGLS_Pos                 2
#define LM3S_ETHMAC_MR17_FGLS_Msk                (1UL << LM3S_ETHMAC_MR17_FGLS_Pos)

#define LM3S_ETHMAC_MR17_ENON_Pos                 1
#define LM3S_ETHMAC_MR17_ENON_Msk                (1UL << LM3S_ETHMAC_MR17_ENON_Pos)

/* LM3S_ETHMAC MR27 Register Definitions */
#define LM3S_ETHMAC_MR27_XPOL_Pos                 4
#define LM3S_ETHMAC_MR27_XPOL_Msk                (1UL << LM3S_ETHMAC_MR27_XPOL_Pos)

/* LM3S_ETHMAC MR29 Register Definitions */
#define LM3S_ETHMAC_MR29_EONIS_Pos                7
#define LM3S_ETHMAC_MR29_EONIS_Msk               (1UL << LM3S_ETHMAC_MR29_EONIS_Pos)

#define LM3S_ETHMAC_MR29_ANCOMPIS_Pos             6
#define LM3S_ETHMAC_MR29_ANCOMPIS_Msk            (1UL << LM3S_ETHMAC_MR29_ANCOMPIS_Pos)

#define LM3S_ETHMAC_MR29_RFLTIS_Pos               5
#define LM3S_ETHMAC_MR29_RFLTIS_Msk              (1UL << LM3S_ETHMAC_MR29_RFLTIS_Pos)

#define LM3S_ETHMAC_MR29_LDIS_Pos                 4
#define LM3S_ETHMAC_MR29_LDIS_Msk                (1UL << LM3S_ETHMAC_MR29_LDIS_Pos)

#define LM3S_ETHMAC_MR29_LPACKIS_Pos              3
#define LM3S_ETHMAC_MR29_LPACKIS_Msk             (1UL << LM3S_ETHMAC_MR29_LPACKIS_Pos)

#define LM3S_ETHMAC_MR29_PDFIS_Pos                2
#define LM3S_ETHMAC_MR29_PDFIS_Msk               (1UL << LM3S_ETHMAC_MR29_PDFIS_Pos)

#define LM3S_ETHMAC_MR29_PRXIS_Pos                1
#define LM3S_ETHMAC_MR29_PRXIS_Msk               (1UL << LM3S_ETHMAC_MR29_PRXIS_Pos)

/* LM3S_ETHMAC MR30 Register Definitions */
#define LM3S_ETHMAC_MR30_EONIM_Pos                7
#define LM3S_ETHMAC_MR30_EONIM_Msk               (1UL << LM3S_ETHMAC_MR30_EONIM_Pos)

#define LM3S_ETHMAC_MR30_ANCOMPIM_Pos             6
#define LM3S_ETHMAC_MR30_ANCOMPIM_Msk            (1UL << LM3S_ETHMAC_MR30_ANCOMPIM_Pos)

#define LM3S_ETHMAC_MR30_RFLTIM_Pos               5
#define LM3S_ETHMAC_MR30_RFLTIM_Msk              (1UL << LM3S_ETHMAC_MR30_RFLTIM_Pos)

#define LM3S_ETHMAC_MR30_LDIM_Pos                 4
#define LM3S_ETHMAC_MR30_LDIM_Msk                (1UL << LM3S_ETHMAC_MR30_LDIM_Pos)

#define LM3S_ETHMAC_MR30_LPACKIM_Pos              3
#define LM3S_ETHMAC_MR30_LPACKIM_Msk             (1UL << LM3S_ETHMAC_MR30_LPACKIM_Pos)

#define LM3S_ETHMAC_MR30_PDFIM_Pos                2
#define LM3S_ETHMAC_MR30_PDFIM_Msk               (1UL << LM3S_ETHMAC_MR30_PDFIM_Pos)

#define LM3S_ETHMAC_MR30_PRXIM_Pos                1
#define LM3S_ETHMAC_MR30_PRXIM_Msk               (1UL << LM3S_ETHMAC_MR30_PRXIM_Pos)

/* LM3S_ETHMAC MR31 Register Definitions */
#define LM3S_ETHMAC_MR31_AUTODONE_Pos             7
#define LM3S_ETHMAC_MR31_AUTODONE_Msk            (1UL << LM3S_ETHMAC_MR31_AUTODONE_Pos)

#define LM3S_ETHMAC_MR31_SPEED_Pos                2
#define LM3S_ETHMAC_MR31_SPEED_Msk               (0x00000007UL << LM3S_ETHMAC_MR31_SPEED_Pos)
#define LM3S_ETHMAC_MR31_SPEED_2_Pos              4
#define LM3S_ETHMAC_MR31_SPEED_2_Msk             (1UL << LM3S_ETHMAC_MR31_SPEED_2_Pos)
#define LM3S_ETHMAC_MR31_SPEED_1_Pos              3
#define LM3S_ETHMAC_MR31_SPEED_1_Msk             (1UL << LM3S_ETHMAC_MR31_SPEED_1_Pos)
#define LM3S_ETHMAC_MR31_SPEED_0_Pos              2
#define LM3S_ETHMAC_MR31_SPEED_0_Msk             (1UL << LM3S_ETHMAC_MR31_SPEED_0_Pos)

#define LM3S_ETHMAC_MR31_SCRDIS_Pos               0
#define LM3S_ETHMAC_MR31_SCRDIS_Msk              (1UL /*<< LM3S_ETHMAC_MR31_SCRDIS_Pos*/)

/* ================================================================================ */
/* ================                       USB                      ================ */
/* ================================================================================ */

typedef __PACKED_STRUCT {
  __IOM uint8_t   FADDR;                /* Offset: 0x000 (R/W) Device Functional Address Register */
  __IOM uint8_t   POWER;                /* Offset: 0x001 (R/W) Power Register */
  __IM  uint16_t  TXIS;                 /* Offset: 0x002 (R/ ) Transmit Interrupt Status Register */
  __IM  uint16_t  RXIS;                 /* Offset: 0x004 (R/ ) Receive Interrupt Status Register */
  __IOM uint16_t  TXIE;                 /* Offset: 0x006 (R/W) Transmit Interrupt Enable Register */
  __IOM uint16_t  RXIE;                 /* Offset: 0x008 (R/W) Receive Interrupt Enable Register */
  __IM  uint8_t   IS;                   /* Offset: 0x00A (R/ ) General Interrupt Status Register */
  __IOM uint8_t   IE;                   /* Offset: 0x00B (R/W) Interrupt Enable Register */
  __IM  uint16_t  FRAME;                /* Offset: 0x00C (R/ ) Frame Value Register */
  __IOM uint8_t   EPIDX;                /* Offset: 0x00E (R/W) Endpoint Index Register */
  __IM  uint8_t   TEST;                 /* Offset: 0x00F (R/ ) Transmit Interrupt Status Register */
  __IM  uint32_t  RESERVED0[4];
  __IOM uint32_t  FIFO0;                /* Offset: 0x020 (R/W) FIFO Endpoint Register 0 */
  __IOM uint32_t  FIFO1;                /* Offset: 0x024 (R/W) FIFO Endpoint Register 1 */
  __IOM uint32_t  FIFO2;                /* Offset: 0x028 (R/W) FIFO Endpoint Register 2 */
  __IOM uint32_t  FIFO3;                /* Offset: 0x02C (R/W) FIFO Endpoint Register 3 */
  __IOM uint32_t  FIFO4;                /* Offset: 0x030 (R/W) FIFO Endpoint Register 4 */
  __IOM uint32_t  FIFO5;                /* Offset: 0x034 (R/W) FIFO Endpoint Register 5 */
  __IOM uint32_t  FIFO6;                /* Offset: 0x038 (R/W) FIFO Endpoint Register 6 */
  __IOM uint32_t  FIFO7;                /* Offset: 0x03C (R/W) FIFO Endpoint Register 7 */
  __IOM uint32_t  FIFO8;                /* Offset: 0x040 (R/W) FIFO Endpoint Register 8 */
  __IOM uint32_t  FIFO9;                /* Offset: 0x044 (R/W) FIFO Endpoint Register 9 */
  __IOM uint32_t  FIFO10;               /* Offset: 0x048 (R/W) FIFO Endpoint Register 10 */
  __IOM uint32_t  FIFO11;               /* Offset: 0x04C (R/W) FIFO Endpoint Register 11 */
  __IOM uint32_t  FIFO12;               /* Offset: 0x050 (R/W) FIFO Endpoint Register 12 */
  __IOM uint32_t  FIFO13;               /* Offset: 0x054 (R/W) FIFO Endpoint Register 13 */
  __IOM uint32_t  FIFO14;               /* Offset: 0x058 (R/W) FIFO Endpoint Register 14 */
  __IOM uint32_t  FIFO15;               /* Offset: 0x05C (R/W) FIFO Endpoint Register 15 */
  __IM  uint8_t   DEVCTL;               /* Offset: 0x060 (R/ ) USB Device Control Register */
  __IM  uint8_t   RESERVED1;
  __IOM uint8_t   TXFIFOSZ;             /* Offset: 0x062 (R/W) Transmit Dynamic FIFO Sizing Register */
  __IOM uint8_t   RXFIFOSZ;             /* Offset: 0x063 (R/W) Receive Dynamic FIFO Sizing Register */
  __IOM uint16_t  TXFIFOADD;            /* Offset: 0x064 (R/W) Transmit FIFO Start Address Register */
  __IOM uint16_t  RXFIFOADD;            /* Offset: 0x066 (R/W) Receive FIFO Start Address Register */
  __IM  uint8_t   RESERVED2[18];
  __IOM uint8_t   CONTIM;               /* Offset: 0x07A (R/W) Connect Timing Register */
  __IOM uint8_t   VPLEN;                /* Offset: 0x07B (R/W) OTG VBUS Pulse Timing Register */
  __IM  uint8_t   RESERVED3;
  __IOM uint8_t   FSEOF;                /* Offset: 0x07D (R/W) Full-Speed Last Transaction to End of Frame Timing Register */
  __IM  uint8_t   LSEOF;                /* Offset: 0x07E (R/W) Low-Speed Last Transaction to End of Frame Timing Register */
  __IM  uint8_t   RESERVED4;
  __IOM uint8_t   TXFUNCADDR0;          /* Offset: 0x080 (R/W) Transmit Functional Address Endpoint Register 0 */
  __IM  uint8_t   RESERVED5;
  __IOM uint8_t   TXHUBADDR0;           /* Offset: 0x082 (R/W) Transmit Hub Address Endpoint Register 0 */
  __IOM uint8_t   TXHUBPORT0;           /* Offset: 0x083 (R/W) Transmit Hub Port Endpoint Register 0 */
  __IM  uint8_t   RESERVED6[4];
  __IOM uint8_t   TXFUNCADDR1;          /* Offset: 0x088 (R/W) Transmit Functional Address Endpoint Register 1 */
  __IM  uint8_t   RESERVED7;
  __IOM uint8_t   TXHUBADDR1;           /* Offset: 0x08A (R/W) Transmit Hub Address Endpoint Register 1 */
  __IOM uint8_t   TXHUBPORT1;           /* Offset: 0x08B (R/W) Transmit Hub Port Endpoint Register 1 */
  __IOM uint8_t   RXFUNCADDR1;          /* Offset: 0x08C (R/W) Receive Functional Address Endpoint Register 1 */
  __IM  uint8_t   RESERVED8;
  __IOM uint8_t   RXHUBADDR1;           /* Offset: 0x08E (R/W) Receive Hub Address Endpoint Register 1 */
  __IOM uint8_t   RXHUBPORT1;           /* Offset: 0x08F (R/W) Receive Hub Port Endpoint Register 1 */
  __IOM uint8_t   TXFUNCADDR2;          /* Offset: 0x090 (R/W) Transmit Functional Address Endpoint Register 2 */
  __IM  uint8_t   RESERVED9;
  __IOM uint8_t   TXHUBADDR2;           /* Offset: 0x092 (R/W) Transmit Hub Address Endpoint Register 2 */
  __IOM uint8_t   TXHUBPORT2;           /* Offset: 0x093 (R/W) Transmit Hub Port Endpoint Register 2 */
  __IOM uint8_t   RXFUNCADDR2;          /* Offset: 0x094 (R/W) Receive Functional Address Endpoint Register 2 */
  __IM  uint8_t   RESERVED10;
  __IOM uint8_t   RXHUBADDR2;           /* Offset: 0x096 (R/W) Receive Hub Address Endpoint Register 2 */
  __IOM uint8_t   RXHUBPORT2;           /* Offset: 0x097 (R/W) Receive Hub Port Endpoint Register 2 */
  __IOM uint8_t   TXFUNCADDR3;          /* Offset: 0x098 (R/W) Transmit Functional Address Endpoint Register 3 */
  __IM  uint8_t   RESERVED11;
  __IOM uint8_t   TXHUBADDR3;           /* Offset: 0x09A (R/W) Transmit Hub Address Endpoint Register 3 */
  __IOM uint8_t   TXHUBPORT3;           /* Offset: 0x09B (R/W) Transmit Hub Port Endpoint Register 3 */
  __IOM uint8_t   RXFUNCADDR3;          /* Offset: 0x09C (R/W) Receive Functional Address Endpoint Register 3 */
  __IOM uint8_t   RXHUBADDR3;           /* Offset: 0x09E (R/W) Receive Hub Address Endpoint Register 3 */
  __IOM uint8_t   RXHUBPORT3;           /* Offset: 0x09F (R/W) Receive Hub Port Endpoint Register 3 */
  __IOM uint8_t   TXFUNCADDR4;          /* Offset: 0x0A0 (R/W) Transmit Functional Address Endpoint Register 4 */
  __IM  uint8_t   RESERVED12;
  __IOM uint8_t   TXHUBADDR4;           /* Offset: 0x0A2 (R/W) Transmit Hub Address Endpoint Register 4 */
  __IOM uint8_t   TXHUBPORT4;           /* Offset: 0x0A3 (R/W) Transmit Hub Port Endpoint Register 4 */
  __IOM uint8_t   RXFUNCADDR4;          /* Offset: 0x0A4 (R/W) Receive Functional Address Endpoint Register 4 */
  __IM  uint8_t   RESERVED13;
  __IOM uint8_t   RXHUBADDR4;           /* Offset: 0x0A6 (R/W) Receive Hub Address Endpoint Register 4 */
  __IOM uint8_t   RXHUBPORT4;           /* Offset: 0x0A7 (R/W) Receive Hub Port Endpoint Register 4 */
  __IOM uint8_t   TXFUNCADDR5;          /* Offset: 0x0A8 (R/W) Transmit Functional Address Endpoint Register 5 */
  __IM  uint8_t   RESERVED14;
  __IOM uint8_t   TXHUBADDR5;           /* Offset: 0x0AA (R/W)  Transmit Hub Address Endpoint Register 5 */
  __IOM uint8_t   TXHUBPORT5;           /* Offset: 0x0AB (R/W) Transmit Hub Port Endpoint Register 5 */
  __IOM uint8_t   RXFUNCADDR5;          /* Offset: 0x0AC (R/W) Receive Functional Address Endpoint Register 5 */
  __IOM uint8_t   RXHUBADDR5;           /* Offset: 0x0AE (R/W) Receive Hub Address Endpoint Register 5 */
  __IOM uint8_t   RXHUBPORT5;           /* Offset: 0x0AF (R/W) Receive Hub Port Endpoint Register 5 */
  __IOM uint8_t   TXFUNCADDR6;          /* Offset: 0x0B0 (R/W)  Transmit Functional Address Endpoint Register 6 */
  __IM  uint8_t   RESERVED15;
  __IOM uint8_t   TXHUBADDR6;           /* Offset: 0x0B2 (R/W) Transmit Hub Address Endpoint Register 6 */
  __IOM uint8_t   TXHUBPORT6;           /* Offset: 0x0B3 (R/W) Transmit Hub Port Endpoint Register 6 */
  __IOM uint8_t   RXFUNCADDR6;          /* Offset: 0x0B4 (R/W) Receive Functional Address Endpoint Register 6 */
  __IM  uint8_t   RESERVED16;
  __IOM uint8_t   RXHUBADDR6;           /* Offset: 0x0B6 (R/W)  Receive Hub Address Endpoint Register 6 */
  __IOM uint8_t   RXHUBPORT6;           /* Offset: 0x0B7 (R/W) Receive Hub Port Endpoint Register 6 */
  __IOM uint8_t   TXFUNCADDR7;          /* Offset: 0x0B8 (R/W)  Transmit Functional Address Endpoint Register 7 */
  __IM  uint8_t   RESERVED17;
  __IOM uint8_t   TXHUBADDR7;           /* Offset: 0x0BA (R/W) Transmit Hub Address Endpoint Register 7 */
  __IOM uint8_t   TXHUBPORT7;           /* Offset: 0x0BB (R/W) Transmit Hub Port Endpoint Register 7 */
  __IOM uint8_t   RXFUNCADDR7;          /* Offset: 0x0BC (R/W) Receive Functional Address Endpoint Register 7 */
  __IOM uint8_t   RXHUBADDR7;           /* Offset: 0x0BE (R/W) Receive Hub Address Endpoint Register 7 */
  __IOM uint8_t   RXHUBPORT7;           /* Offset: 0x0BF (R/W) Receive Hub Port Endpoint Register 7 */
  __IOM uint8_t   TXFUNCADDR8;          /* Offset: 0x0C0 (R/W) Transmit Functional Address Endpoint Register 8 */
  __IM  uint8_t   RESERVED18;
  __IOM uint8_t   TXHUBADDR8;           /* Offset: 0x0C2 (R/W) Transmit Hub Address Endpoint Register 8 */
  __IOM uint8_t   TXHUBPORT8;           /* Offset: 0x0C3 (R/W) Transmit Hub Port Endpoint Register 8 */
  __IOM uint8_t   RXFUNCADDR8;          /* Offset: 0x0C4 (R/W) Receive Functional Address Endpoint Register 8 */
  __IM  uint8_t   RESERVED19;
  __IOM uint8_t   RXHUBADDR8;           /* Offset: 0x0C6 (R/W) Receive Hub Address Endpoint Register 8 */
  __IOM uint8_t   RXHUBPORT8;           /* Offset: 0x0C7 (R/W) Receive Hub Port Endpoint Register 8 */
  __IOM uint8_t   TXFUNCADDR9;          /* Offset: 0x0C8 (R/W) Transmit Functional Address Endpoint Register 9 */
  __IM  uint8_t   RESERVED20;
  __IOM uint8_t   TXHUBADDR9;           /* Offset: 0x0CA (R/W) Transmit Hub Address Endpoint Register 9 */
  __IOM uint8_t   TXHUBPORT9;           /* Offset: 0x0CB (R/W) Transmit Hub Port Endpoint Register 9 */
  __IOM uint8_t   RXFUNCADDR9;          /* Offset: 0x0CC (R/W) Receive Functional Address Endpoint Register 9 */
  __IOM uint8_t   RXHUBADDR9;           /* Offset: 0x0CE (R/W) Receive Hub Address Endpoint Register 9 */
  __IOM uint8_t   RXHUBPORT9;           /* Offset: 0x0CF (R/W) Receive Hub Port Endpoint Register 9 */
  __IOM uint8_t   TXFUNCADDR10;         /* Offset: 0x0D0 (R/W) Transmit Functional Address Endpoint Register 10 */
  __IM  uint8_t   RESERVED21;
  __IOM uint8_t   TXHUBADDR10;          /* Offset: 0x0D2 (R/W) Transmit Hub Address Endpoint Register 10 */
  __IOM uint8_t   TXHUBPORT10;          /* Offset: 0x0D3 (R/W) Transmit Hub Port Endpoint Register 10 */
  __IOM uint8_t   RXFUNCADDR10;         /* Offset: 0x0D4 (R/W) Receive Functional Address Endpoint Register 10 */
  __IM  uint8_t   RESERVED22;
  __IOM uint8_t   RXHUBADDR10;          /* Offset: 0x0D6 (R/W) Receive Hub Address Endpoint Register 10 */
  __IOM uint8_t   RXHUBPORT10;          /* Offset: 0x0D7 (R/W) Receive Hub Port Endpoint Register 10 */
  __IOM uint8_t   TXFUNCADDR11;         /* Offset: 0x0D8 (R/W) Transmit Functional Address Endpoint Register 11 */
  __IM  uint8_t   RESERVED23;
  __IOM uint8_t   TXHUBADDR11;          /* Offset: 0x0DA (R/W) Transmit Hub Address Endpoint Register 11 */
  __IOM uint8_t   TXHUBPORT11;          /* Offset: 0x0DB (R/W) Transmit Hub Port Endpoint Register 11 */
  __IOM uint8_t   RXFUNCADDR11;         /* Offset: 0x0DC (R/W) Receive Functional Address Endpoint Register 11 */
  __IOM uint8_t   RXHUBADDR11;          /* Offset: 0x0DE (R/W) Receive Hub Address Endpoint Register 11 */
  __IOM uint8_t   RXHUBPORT11;          /* Offset: 0x0DF (R/W) Receive Hub Port Endpoint Register 11 */
  __IOM uint8_t   TXFUNCADDR12;         /* Offset: 0x0E0 (R/W) Transmit Functional Address Endpoint Register 12 */
  __IM  uint8_t   RESERVED124;
  __IOM uint8_t   TXHUBADDR12;          /* Offset: 0x0E2 (R/W) Transmit Hub Address Endpoint Register 12 */
  __IOM uint8_t   TXHUBPORT12;          /* Offset: 0x0E3 (R/W) Transmit Hub Port Endpoint Register 12 */
  __IOM uint8_t   RXFUNCADDR12;         /* Offset: 0x0E4 (R/W) Receive Functional Address Endpoint Register 12 */
  __IM  uint8_t   RESERVED25;
  __IOM uint8_t   RXHUBADDR12;          /* Offset: 0x0E6 (R/W) Receive Hub Address Endpoint Register 12 */
  __IOM uint8_t   RXHUBPORT12;          /* Offset: 0x0E7 (R/W) Receive Hub Port Endpoint Register 12 */
  __IOM uint8_t   TXFUNCADDR13;         /* Offset: 0x0E8 (R/W) Transmit Functional Address Endpoint Register 13 */
  __IM  uint8_t   RESERVED26;
  __IOM uint8_t   TXHUBADDR13;          /* Offset: 0x0EA (R/W) Transmit Hub Address Endpoint Register 13 */
  __IOM uint8_t   TXHUBPORT13;          /* Offset: 0x0EB (R/W) Transmit Hub Port Endpoint Register 13 */
  __IOM uint8_t   RXFUNCADDR13;         /* Offset: 0x0EC (R/W) Receive Functional Address Endpoint Register 13 */
  __IOM uint8_t   RXHUBADDR13;          /* Offset: 0x0EE (R/W) Receive Hub Address Endpoint Register 13 */
  __IOM uint8_t   RXHUBPORT13;          /* Offset: 0x0EF (R/W) Receive Hub Port Endpoint Register 13 */
  __IOM uint8_t   TXFUNCADDR14;         /* Offset: 0x0F0 (R/W) Transmit Functional Address Endpoint Register 14 */
  __IM  uint8_t   RESERVED127;
  __IOM uint8_t   TXHUBADDR14;          /* Offset: 0x0F2 (R/W) Transmit Hub Address Endpoint Register 14 */
  __IOM uint8_t   TXHUBPORT14;          /* Offset: 0x0F3 (R/W) Transmit Hub Port Endpoint Register 14 */
  __IOM uint8_t   RXFUNCADDR14;         /* Offset: 0x0F4 (R/W) Receive Functional Address Endpoint Register 14 */
  __IM  uint8_t   RESERVED28;
  __IOM uint8_t   RXHUBADDR14;          /* Offset: 0x0F6 (R/W) Receive Hub Address Endpoint Register 14 */
  __IOM uint8_t   RXHUBPORT14;          /* Offset: 0x0F7 (R/W) Receive Hub Port Endpoint Register 14 */
  __IOM uint8_t   TXFUNCADDR15;         /* Offset: 0x0F8 (R/W) Transmit Functional Address Endpoint Register 15 */
  __IM  uint8_t   RESERVED29;
  __IOM uint8_t   TXHUBADDR15;          /* Offset: 0x0FA (R/W) Transmit Hub Address Endpoint Register 15 */
  __IOM uint8_t   TXHUBPORT15;          /* Offset: 0x0FB (R/W) Transmit Hub Port Endpoint Register 15 */
  __IOM uint8_t   RXFUNCADDR15;         /* Offset: 0x0FC (R/W) Receive Functional Address Endpoint Register 15 */
  __IOM uint8_t   RXHUBADDR15;          /* Offset: 0x0FE (R/W) Receive Hub Address Endpoint Register 15 */
  __IOM uint8_t   RXHUBPORT15;          /* Offset: 0x0FF (R/W) Receive Hub Port Endpoint Register 15 */
  __IM  uint8_t   RESERVED30[2];
  __IOM uint8_t   CSRL0;                /* Offset: 0x102 (R/W) Control and Status Endpoint Low Register 0 */
  __IOM uint8_t   CSRH0;                /* Offset: 0x103 (R/W) Control and Status Endpoint High Register 0 */
  __IM  uint8_t   RESERVED31[4];
  __IM  uint8_t   COUNT0;               /* Offset: 0x108 (R/ ) Receive Byte Count Endpoint Register 0 */
  __IM  uint8_t   RESERVED32;
  __IOM uint8_t   TYPE0;                /* Offset: 0x10A (R/W) Type Endpoint Register 0 */
  __IOM uint8_t   NAKLMT;               /* Offset: 0x10B (R/W) NAK Limit Register */
  __IM  uint8_t   RESERVED33[4];
  __IOM uint16_t  TXMAXP1;              /* Offset: 0x110 (R/W) Maximum Transmit Data Endpoint Register 1 */
  __IOM uint8_t   TXCSRL1;              /* Offset: 0x112 (R/W) Transmit Control and Status Endpoint Low Register 1 */
  __IOM uint8_t   TXCSRH1;              /* Offset: 0x113 (R/W) Transmit Control and Status Endpoint High Register 1 */
  __IOM uint16_t  RXMAXP1;              /* Offset: 0x114 (R/W) Maximum Receive Data Endpoint Register 1 */
  __IOM uint8_t   RXCSRL1;              /* Offset: 0x116 (R/W) Receive Control and Status Endpoint Low Register 1 */
  __IOM uint8_t   RXCSRH1;              /* Offset: 0x117 (R/W) Receive Control and Status Endpoint High Register 1 */
  __IM  uint16_t  RXCOUNT1;             /* Offset: 0x118 (R/ ) Receive Byte Count Endpoint Register 1 */
  __IOM uint8_t   TXTYPE1;              /* Offset: 0x11A (R/W) Host Transmit Configure Type Endpoint Register 1 */
  __IOM uint8_t   TXINTERVAL1;          /* Offset: 0x11B (R/W) Host Transmit Interval Endpoint Register 1 */
  __IOM uint8_t   RXTYPE1;              /* Offset: 0x11C (R/W) Host Configure Receive Type Endpoint Register 1 */
  __IOM uint8_t   RXINTERVAL1;          /* Offset: 0x11D (R/W) Host Receive Interval Endpoint Register 1 */
  __IM  uint8_t   RESERVED34[2];
  __IOM uint16_t  TXMAXP2;              /* Offset: 0x120 (R/W) Maximum Transmit Data Endpoint Register 2 */
  __IOM uint8_t   TXCSRL2;              /* Offset: 0x122 (R/W) Transmit Control and Status Endpoint Low Register 2 */
  __IOM uint8_t   TXCSRH2;              /* Offset: 0x123 (R/W) Transmit Control and Status Endpoint High Register 2 */
  __IOM uint16_t  RXMAXP2;              /* Offset: 0x124 (R/W) Maximum Receive Data Endpoint Register 2 */
  __IOM uint8_t   RXCSRL2;              /* Offset: 0x126 (R/W) Receive Control and Status Endpoint Low Register 2 */
  __IOM uint8_t   RXCSRH2;              /* Offset: 0x127 (R/W) Receive Control and Status Endpoint High Register 2 */
  __IM  uint16_t  RXCOUNT2;             /* Offset: 0x128 (R/ ) Receive Byte Count Endpoint Register 2 */
  __IOM uint8_t   TXTYPE2;              /* Offset: 0x12A (R/W) Host Transmit Configure Type Endpoint Register 2 */
  __IOM uint8_t   TXINTERVAL2;          /* Offset: 0x12B (R/W) Host Transmit Interval Endpoint Register 2 */
  __IOM uint8_t   RXTYPE2;              /* Offset: 0x12C (R/W) Host Configure Receive Type Endpoint Register 2 */
  __IOM uint8_t   RXINTERVAL2;          /* Offset: 0x12D (R/W) Host Receive Interval Endpoint Register 2 */
  __IM  uint8_t   RESERVED35[2];
  __IOM uint16_t  TXMAXP3;              /* Offset: 0x130 (R/W) Maximum Transmit Data Endpoint Register 3 */
  __IOM uint8_t   TXCSRL3;              /* Offset: 0x132 (R/W) Transmit Control and Status Endpoint Low Register 3 */
  __IOM uint8_t   TXCSRH3;              /* Offset: 0x133 (R/W) Transmit Control and Status Endpoint High Register 3 */
  __IOM uint16_t  RXMAXP3;              /* Offset: 0x134 (R/W) Maximum Receive Data Endpoint Register 3 */
  __IOM uint8_t   RXCSRL3;              /* Offset: 0x136 (R/W) Receive Control and Status Endpoint Low Register 3 */
  __IOM uint8_t   RXCSRH3;              /* Offset: 0x137 (R/W) Receive Control and Status Endpoint High Register 3 */
  __IM  uint16_t  RXCOUNT3;             /* Offset: 0x138 (R/ ) Receive Byte Count Endpoint Register 3 */
  __IOM uint8_t   TXTYPE3;              /* Offset: 0x13A (R/W) Host Transmit Configure Type Endpoint Register 3 */
  __IOM uint8_t   TXINTERVAL3;          /* Offset: 0x13B (R/W) Host Transmit Interval Endpoint Register 3 */
  __IOM uint8_t   RXTYPE3;              /* Offset: 0x13C (R/W) Host Configure Receive Type Endpoint Register 3 */
  __IOM uint8_t   RXINTERVAL3;          /* Offset: 0x13D (R/W) Host Receive Interval Endpoint Register 3 */
  __IM  uint8_t   RESERVED36[2];
  __IOM uint16_t  TXMAXP4;              /* Offset: 0x140 (R/W) Maximum Transmit Data Endpoint Register 4 */
  __IOM uint8_t   TXCSRL4;              /* Offset: 0x142 (R/W) Transmit Control and Status Endpoint Low Register 4 */
  __IOM uint8_t   TXCSRH4;              /* Offset: 0x143 (R/W) Transmit Control and Status Endpoint High Register 4 */
  __IOM uint16_t  RXMAXP4;              /* Offset: 0x144 (R/W) Maximum Receive Data Endpoint Register 4 */
  __IOM uint8_t   RXCSRL4;              /* Offset: 0x146 (R/W) Receive Control and Status Endpoint Low Register 4 */
  __IOM uint8_t   RXCSRH4;              /* Offset: 0x147 (R/W) Receive Control and Status Endpoint High Register 4 */
  __IM  uint16_t  RXCOUNT4;             /* Offset: 0x148 (R/ ) Receive Byte Count Endpoint Register 4 */
  __IOM uint8_t   TXTYPE4;              /* Offset: 0x14A (R/W) Host Transmit Configure Type Endpoint Register 4 */
  __IOM uint8_t   TXINTERVAL4;          /* Offset: 0x14B (R/W) Host Transmit Interval Endpoint Register 4 */
  __IOM uint8_t   RXTYPE4;              /* Offset: 0x14C (R/W) Host Configure Receive Type Endpoint Register 4 */
  __IOM uint8_t   RXINTERVAL4;          /* Offset: 0x14D (R/W) Host Receive Interval Endpoint Register 4 */
  __IM  uint8_t   RESERVED37[2];
  __IOM uint16_t  TXMAXP5;              /* Offset: 0x150 (R/W) Maximum Transmit Data Endpoint Register 5 */
  __IOM uint8_t   TXCSRL5;              /* Offset: 0x152 (R/W) Transmit Control and Status Endpoint Low Register 5 */
  __IOM uint8_t   TXCSRH5;              /* Offset: 0x153 (R/W) Transmit Control and Status Endpoint High Register 5 */
  __IOM uint16_t  RXMAXP5;              /* Offset: 0x154 (R/W) Maximum Receive Data Endpoint Register 5 */
  __IOM uint8_t   RXCSRL5;              /* Offset: 0x156 (R/W) Receive Control and Status Endpoint Low Register 5 */
  __IOM uint8_t   RXCSRH5;              /* Offset: 0x157 (R/W) Receive Control and Status Endpoint High Register 5 */
  __IM  uint16_t  RXCOUNT5;             /* Offset: 0x158 (R/ ) Receive Byte Count Endpoint Register 5 */
  __IOM uint8_t   TXTYPE5;              /* Offset: 0x15A (R/W) Host Transmit Configure Type Endpoint Register 5 */
  __IOM uint8_t   TXINTERVAL5;          /* Offset: 0x15B (R/W) Host Transmit Interval Endpoint Register 5 */
  __IOM uint8_t   RXTYPE5;              /* Offset: 0x15C (R/W) Host Configure Receive Type Endpoint Register 5 */
  __IOM uint8_t   RXINTERVAL5;          /* Offset: 0x15D (R/W) Host Receive Interval Endpoint Register 5 */
  __IM  uint8_t   RESERVED38[2];
  __IOM uint16_t  TXMAXP6;              /* Offset: 0x160 (R/W) Maximum Transmit Data Endpoint Register 6 */
  __IOM uint8_t   TXCSRL6;              /* Offset: 0x162 (R/W) Transmit Control and Status Endpoint Low Register 6 */
  __IOM uint8_t   TXCSRH6;              /* Offset: 0x163 (R/W) Transmit Control and Status Endpoint High Register 6 */
  __IOM uint16_t  RXMAXP6;              /* Offset: 0x164 (R/W) Maximum Receive Data Endpoint Register 6 */
  __IOM uint8_t   RXCSRL6;              /* Offset: 0x166 (R/W) Receive Control and Status Endpoint Low Register 6 */
  __IOM uint8_t   RXCSRH6;              /* Offset: 0x167 (R/W) Receive Control and Status Endpoint High Register 6 */
  __IM  uint16_t  RXCOUNT6;             /* Offset: 0x168 (R/ ) Receive Byte Count Endpoint Register 6 */
  __IOM uint8_t   TXTYPE6;              /* Offset: 0x16A (R/W) Host Transmit Configure Type Endpoint Register 6 */
  __IOM uint8_t   TXINTERVAL6;          /* Offset: 0x16B (R/W) Host Transmit Interval Endpoint Register 6 */
  __IOM uint8_t   RXTYPE6;              /* Offset: 0x16C (R/W) Host Configure Receive Type Endpoint Register 6 */
  __IOM uint8_t   RXINTERVAL6;          /* Offset: 0x16D (R/W) Host Receive Interval Endpoint Register 6 */
  __IM  uint8_t   RESERVED39[2];
  __IOM uint16_t  TXMAXP7;              /* Offset: 0x170 (R/W) Maximum Transmit Data Endpoint Register 7 */
  __IOM uint8_t   TXCSRL7;              /* Offset: 0x172 (R/W) Transmit Control and Status Endpoint Low Register 7 */
  __IOM uint8_t   TXCSRH7;              /* Offset: 0x173 (R/W) Transmit Control and Status Endpoint High Register 7 */
  __IOM uint16_t  RXMAXP7;              /* Offset: 0x174 (R/W) Maximum Receive Data Endpoint Register 7 */
  __IOM uint8_t   RXCSRL7;              /* Offset: 0x176 (R/W) Receive Control and Status Endpoint Low Register 7 */
  __IOM uint8_t   RXCSRH7;              /* Offset: 0x177 (R/W) Receive Control and Status Endpoint High Register 7 */
  __IM  uint16_t  RXCOUNT7;             /* Offset: 0x178 (R/ ) Receive Byte Count Endpoint Register 7 */
  __IOM uint8_t   TXTYPE7;              /* Offset: 0x17A (R/W) Host Transmit Configure Type Endpoint Register 7 */
  __IOM uint8_t   TXINTERVAL7;          /* Offset: 0x17B (R/W) Host Transmit Interval Endpoint Register 7 */
  __IOM uint8_t   RXTYPE7;              /* Offset: 0x17C (R/W) Host Configure Receive Type Endpoint Register 7 */
  __IOM uint8_t   RXINTERVAL7;          /* Offset: 0x17D (R/W) Host Receive Interval Endpoint Register 7 */
  __IM  uint8_t   RESERVED40[2];
  __IOM uint16_t  TXMAXP8;              /* Offset: 0x180 (R/W) Maximum Transmit Data Endpoint Register 8 */
  __IOM uint8_t   TXCSRL8;              /* Offset: 0x182 (R/W) Transmit Control and Status Endpoint Low Register 8 */
  __IOM uint8_t   TXCSRH8;              /* Offset: 0x183 (R/W) Transmit Control and Status Endpoint High Register 8 */
  __IOM uint16_t  RXMAXP8;              /* Offset: 0x184 (R/W) Maximum Receive Data Endpoint Register 8 */
  __IOM uint8_t   RXCSRL8;              /* Offset: 0x186 (R/W) Receive Control and Status Endpoint Low Register 8 */
  __IOM uint8_t   RXCSRH8;              /* Offset: 0x187 (R/W) Receive Control and Status Endpoint High Register 8 */
  __IM  uint16_t  RXCOUNT8;             /* Offset: 0x188 (R/ ) Receive Byte Count Endpoint Register 8 */
  __IOM uint8_t   TXTYPE8;              /* Offset: 0x18A (R/W) Host Transmit Configure Type Endpoint Register 8 */
  __IOM uint8_t   TXINTERVAL8;          /* Offset: 0x18B (R/W) Host Transmit Interval Endpoint Register 8 */
  __IOM uint8_t   RXTYPE8;              /* Offset: 0x18C (R/W) Host Configure Receive Type Endpoint Register 8 */
  __IOM uint8_t   RXINTERVAL8;          /* Offset: 0x18D (R/W) Host Receive Interval Endpoint Register 8 */
  __IM  uint8_t   RESERVED41[2];
  __IOM uint16_t  TXMAXP9;              /* Offset: 0x190 (R/W) Maximum Transmit Data Endpoint Register 9 */
  __IOM uint8_t   TXCSRL9;              /* Offset: 0x192 (R/W) Transmit Control and Status Endpoint Low Register 9 */
  __IOM uint8_t   TXCSRH9;              /* Offset: 0x193 (R/W) Transmit Control and Status Endpoint High Register 9 */
  __IOM uint16_t  RXMAXP9;              /* Offset: 0x194 (R/W) Maximum Receive Data Endpoint Register 9 */
  __IOM uint8_t   RXCSRL9;              /* Offset: 0x196 (R/W) Receive Control and Status Endpoint Low Register 9 */
  __IOM uint8_t   RXCSRH9;              /* Offset: 0x197 (R/W) Receive Control and Status Endpoint High Register 9 */
  __IM  uint16_t  RXCOUNT9;             /* Offset: 0x198 (R/ ) Receive Byte Count Endpoint Register 9 */
  __IOM uint8_t   TXTYPE9;              /* Offset: 0x19A (R/W) Host Transmit Configure Type Endpoint Register 9 */
  __IOM uint8_t   TXINTERVAL9;          /* Offset: 0x19B (R/W) Host Transmit Interval Endpoint Register 9 */
  __IOM uint8_t   RXTYPE9;              /* Offset: 0x19C (R/W) Host Configure Receive Type Endpoint Register 9 */
  __IOM uint8_t   RXINTERVAL9;          /* Offset: 0x19D (R/W) Host Receive Interval Endpoint Register 9 */
  __IM  uint8_t   RESERVED42[2];
  __IOM uint16_t  TXMAXP10;             /* Offset: 0x1A0 (R/W) Maximum Transmit Data Endpoint Register 10 */
  __IOM uint8_t   TXCSRL10;             /* Offset: 0x1A2 (R/W) Transmit Control and Status Endpoint Low Register 10 */
  __IOM uint8_t   TXCSRH10;             /* Offset: 0x1A3 (R/W) Transmit Control and Status Endpoint High Register 10 */
  __IOM uint16_t  RXMAXP10;             /* Offset: 0x1A4 (R/W) Maximum Receive Data Endpoint Register 10 */
  __IOM uint8_t   RXCSRL10;             /* Offset: 0x1A6 (R/W) Receive Control and Status Endpoint Low Register 10 */
  __IOM uint8_t   RXCSRH10;             /* Offset: 0x1A7 (R/W) Receive Control and Status Endpoint High Register 10 */
  __IM  uint16_t  RXCOUNT10;            /* Offset: 0x1A8 (R/ ) Receive Byte Count Endpoint Register 10 */
  __IOM uint8_t   TXTYPE10;             /* Offset: 0x1AA (R/W) Host Transmit Configure Type Endpoint Register 10 */
  __IOM uint8_t   TXINTERVAL10;         /* Offset: 0x1AB (R/W) Host Transmit Interval Endpoint Register 10 */
  __IOM uint8_t   RXTYPE10;             /* Offset: 0x1AC (R/W) Host Configure Receive Type Endpoint Register 10 */
  __IOM uint8_t   RXINTERVAL10;         /* Offset: 0x1AD (R/W) Host Receive Interval Endpoint Register 10 */
  __IM  uint8_t   RESERVED43[2];
  __IOM uint16_t  TXMAXP11;             /* Offset: 0x1B0 (R/W) Maximum Transmit Data Endpoint Register 11 */
  __IOM uint8_t   TXCSRL11;             /* Offset: 0x1B2 (R/W) Transmit Control and Status Endpoint Low Register 11 */
  __IOM uint8_t   TXCSRH11;             /* Offset: 0x1B3 (R/W) Transmit Control and Status Endpoint High Register 11 */
  __IOM uint16_t  RXMAXP11;             /* Offset: 0x1B4 (R/W) Maximum Receive Data Endpoint Register 11 */
  __IOM uint8_t   RXCSRL11;             /* Offset: 0x1B6 (R/W) Receive Control and Status Endpoint Low Register 11 */
  __IOM uint8_t   RXCSRH11;             /* Offset: 0x1B7 (R/W) Receive Control and Status Endpoint High Register 11 */
  __IM  uint16_t  RXCOUNT11;            /* Offset: 0x1B8 (R/ ) Receive Byte Count Endpoint Register 11 */
  __IOM uint8_t   TXTYPE11;             /* Offset: 0x1BA (R/W) Host Transmit Configure Type Endpoint Register 11 */
  __IOM uint8_t   TXINTERVAL11;         /* Offset: 0x1BB (R/W) Host Transmit Interval Endpoint Register 11 */
  __IOM uint8_t   RXTYPE11;             /* Offset: 0x1BC (R/W) Host Configure Receive Type Endpoint Register 11 */
  __IOM uint8_t   RXINTERVAL11;         /* Offset: 0x1BD (R/W) Host Receive Interval Endpoint Register 11 */
  __IM  uint8_t   RESERVED44[2];
  __IOM uint16_t  TXMAXP12;             /* Offset: 0x1C0 (R/W) Maximum Transmit Data Endpoint Register 12 */
  __IOM uint8_t   TXCSRL12;             /* Offset: 0x1C2 (R/W) Transmit Control and Status Endpoint Low Register 12 */
  __IOM uint8_t   TXCSRH12;             /* Offset: 0x1C3 (R/W) Transmit Control and Status Endpoint High Register 12 */
  __IOM uint16_t  RXMAXP12;             /* Offset: 0x1C4 (R/W) Maximum Receive Data Endpoint Register 12 */
  __IOM uint8_t   RXCSRL12;             /* Offset: 0x1C6 (R/W) Receive Control and Status Endpoint Low Register 12 */
  __IOM uint8_t   RXCSRH12;             /* Offset: 0x1C7 (R/W) Receive Control and Status Endpoint High Register 12 */
  __IM  uint16_t  RXCOUNT12;            /* Offset: 0x1C8 (R/ ) Receive Byte Count Endpoint Register 12 */
  __IOM uint8_t   TXTYPE12;             /* Offset: 0x1CA (R/W) Host Transmit Configure Type Endpoint Register 12 */
  __IOM uint8_t   TXINTERVAL12;         /* Offset: 0x1CB (R/W) Host Transmit Interval Endpoint Register 12 */
  __IOM uint8_t   RXTYPE12;             /* Offset: 0x1CC (R/W) Host Configure Receive Type Endpoint Register 12 */
  __IOM uint8_t   RXINTERVAL12;         /* Offset: 0x1CD (R/W) Host Receive Interval Endpoint Register 12 */
  __IM  uint8_t   RESERVED45[2];
  __IOM uint16_t  TXMAXP13;             /* Offset: 0x1D0 (R/W) Maximum Transmit Data Endpoint Register 13 */
  __IOM uint8_t   TXCSRL13;             /* Offset: 0x1D2 (R/W) Transmit Control and Status Endpoint Low Register 13 */
  __IOM uint8_t   TXCSRH13;             /* Offset: 0x1D3 (R/W) Transmit Control and Status Endpoint High Register 13 */
  __IOM uint16_t  RXMAXP13;             /* Offset: 0x1D4 (R/W) Maximum Receive Data Endpoint Register 13 */
  __IOM uint8_t   RXCSRL13;             /* Offset: 0x1D6 (R/W) Receive Control and Status Endpoint Low Register 13 */
  __IOM uint8_t   RXCSRH13;             /* Offset: 0x1D7 (R/W) Receive Control and Status Endpoint High Register 13 */
  __IM  uint16_t  RXCOUNT13;            /* Offset: 0x1D8 (R/ ) Receive Byte Count Endpoint Register 13 */
  __IOM uint8_t   TXTYPE13;             /* Offset: 0x1DA (R/W) Host Transmit Configure Type Endpoint Register 13 */
  __IOM uint8_t   TXINTERVAL13;         /* Offset: 0x1DB (R/W) Host Transmit Interval Endpoint Register 13 */
  __IOM uint8_t   RXTYPE13;             /* Offset: 0x1DC (R/W) Host Configure Receive Type Endpoint Register 13 */
  __IOM uint8_t   RXINTERVAL13;         /* Offset: 0x1DD (R/W) Host Receive Interval Endpoint Register 13 */
  __IM  uint8_t   RESERVED46[2];
  __IOM uint16_t  TXMAXP14;             /* Offset: 0x1E0 (R/W) Maximum Transmit Data Endpoint Register 14 */
  __IOM uint8_t   TXCSRL14;             /* Offset: 0x1E2 (R/W) Transmit Control and Status Endpoint Low Register 14 */
  __IOM uint8_t   TXCSRH14;             /* Offset: 0x1E3 (R/W) Transmit Control and Status Endpoint High Register 14 */
  __IOM uint16_t  RXMAXP14;             /* Offset: 0x1E4 (R/W) Maximum Receive Data Endpoint Register 14 */
  __IOM uint8_t   RXCSRL14;             /* Offset: 0x1E6 (R/W) Receive Control and Status Endpoint Low Register 14 */
  __IOM uint8_t   RXCSRH14;             /* Offset: 0x1E7 (R/W) Receive Control and Status Endpoint High Register 14 */
  __IM  uint16_t  RXCOUNT14;            /* Offset: 0x1E8 (R/ ) Receive Byte Count Endpoint Register 14 */
  __IOM uint8_t   TXTYPE14;             /* Offset: 0x1EA (R/W) Host Transmit Configure Type Endpoint Register 14 */
  __IOM uint8_t   TXINTERVAL14;         /* Offset: 0x1EB (R/W) Host Transmit Interval Endpoint Register 14 */
  __IOM uint8_t   RXTYPE14;             /* Offset: 0x1EC (R/W) Host Configure Receive Type Endpoint Register 14 */
  __IOM uint8_t   RXINTERVAL14;         /* Offset: 0x1ED (R/W) Host Receive Interval Endpoint Register 14 */
  __IM  uint8_t   RESERVED47[2];
  __IOM uint16_t  TXMAXP15;             /* Offset: 0x1F0 (R/W) Maximum Transmit Data Endpoint Register 15 */
  __IOM uint8_t   TXCSRL15;             /* Offset: 0x1F2 (R/W) Transmit Control and Status Endpoint Low Register 15 */
  __IOM uint8_t   TXCSRH15;             /* Offset: 0x1F3 (R/W) Transmit Control and Status Endpoint High Register 15 */
  __IOM uint16_t  RXMAXP15;             /* Offset: 0x1F4 (R/W) Maximum Receive Data Endpoint Register 15 */
  __IOM uint8_t   RXCSRL15;             /* Offset: 0x1F6 (R/W) Receive Control and Status Endpoint Low Register 15 */
  __IOM uint8_t   RXCSRH15;             /* Offset: 0x1F7 (R/W) Receive Control and Status Endpoint High Register 15 */
  __IM  uint16_t  RXCOUNT15;            /* Offset: 0x1F8 (R/ ) Receive Byte Count Endpoint Register 15 */
  __IOM uint8_t   TXTYPE15;             /* Offset: 0x1FA (R/W) Host Transmit Configure Type Endpoint Register 15 */
  __IOM uint8_t   TXINTERVAL15;         /* Offset: 0x1FB (R/W) Host Transmit Interval Endpoint Register 15 */
  __IOM uint8_t   RXTYPE15;             /* Offset: 0x1FC (R/W) Host Configure Receive Type Endpoint Register 15 */
  __IOM uint8_t   RXINTERVAL15;         /* Offset: 0x1FD (R/W) Host Receive Interval Endpoint Register 15 */
  __IM  uint8_t   RESERVED48[262];
  __IOM uint16_t  RQPKTCOUNT1;          /* Offset: 0x304 (R/W) Request Packet Count in Block Transfer Endpoint Register 1 */
  __IM  uint8_t   RESERVED49[2];
  __IOM uint16_t  RQPKTCOUNT2;          /* Offset: 0x308 (R/W) Request Packet Count in Block Transfer Endpoint Register 2 */
  __IM  uint8_t   RESERVED50[2];
  __IOM uint16_t  RQPKTCOUNT3;          /* Offset: 0x30С (R/W) Request Packet Count in Block Transfer Endpoint Register 3 */
  __IM  uint8_t   RESERVED51[2];
  __IOM uint16_t  RQPKTCOUNT4;          /* Offset: 0x310 (R/W) Request Packet Count in Block Transfer Endpoint Register 4 */
  __IM  uint8_t   RESERVED52[2];
  __IOM uint16_t  RQPKTCOUNT5;          /* Offset: 0x314 (R/W) Request Packet Count in Block Transfer Endpoint Register 5 */
  __IM  uint8_t   RESERVED53[2];
  __IOM uint16_t  RQPKTCOUNT6;          /* Offset: 0x318 (R/W) Request Packet Count in Block Transfer Endpoint Register 6 */
  __IM  uint8_t   RESERVED54[2];
  __IOM uint16_t  RQPKTCOUNT7;          /* Offset: 0x31С (R/W) Request Packet Count in Block Transfer Endpoint Register 7 */
  __IM  uint8_t   RESERVED55[2];
  __IOM uint16_t  RQPKTCOUNT8;          /* Offset: 0x320 (R/W) Request Packet Count in Block Transfer Endpoint Register 8 */
  __IM  uint8_t   RESERVED56[2];
  __IOM uint16_t  RQPKTCOUNT9;          /* Offset: 0x324 (R/W) Request Packet Count in Block Transfer Endpoint Register 9 */
  __IM  uint8_t   RESERVED57[2];
  __IOM uint16_t  RQPKTCOUNT10;         /* Offset: 0x328 (R/W) Request Packet Count in Block Transfer Endpoint Register 10 */
  __IM  uint8_t   RESERVED58[2];
  __IOM uint16_t  RQPKTCOUNT11;         /* Offset: 0x32С (R/W) Request Packet Count in Block Transfer Endpoint Register 11 */
  __IM  uint8_t   RESERVED59[2];
  __IOM uint16_t  RQPKTCOUNT12;         /* Offset: 0x330 (R/W) Request Packet Count in Block Transfer Endpoint Register 12 */
  __IM  uint8_t   RESERVED60[2];
  __IOM uint16_t  RQPKTCOUNT13;         /* Offset: 0x334 (R/W) Request Packet Count in Block Transfer Endpoint Register 13 */
  __IM  uint8_t   RESERVED61[2];
  __IOM uint16_t  RQPKTCOUNT14;         /* Offset: 0x338 (R/W) Request Packet Count in Block Transfer Endpoint Register 14 */
  __IM  uint8_t   RESERVED62[2];
  __IOM uint16_t  RQPKTCOUNT15;         /* Offset: 0x33С (R/W) Request Packet Count in Block Transfer Endpoint Register 15 */
  __IM  uint8_t   RESERVED63[2];
  __IOM uint16_t  RXDPKTBUFDIS;         /* Offset: 0x340 (R/W) Receive Double Packet Buffer Disable Register */
  __IOM uint16_t  ЕXDPKTBUFDIS;         /* Offset: 0x342 (R/W) Transmit Double Packet Buffer Disable Register */
  __IM  uint8_t   RESERVED64[188];
  __IOM uint32_t  EPC;                  /* Offset: 0x400 (R/W) External Power Control Register */
  __IM  uint32_t  EPCRIS;               /* Offset: 0x404 (R/ ) External Power Control Raw Interrupt Status Register */
  __IOM uint32_t  EPCIM;                /* Offset: 0x408 (R/W) External Power Control Interrupt Mask Register */
  __IOM uint32_t  EPCISC;               /* Offset: 0x40C (R/W) External Power Control Interrupt Status and Clear Register */
  __IM  uint32_t  DRRIS;                /* Offset: 0x410 (R/ ) Device RESUME Raw Interrupt Status Register */
  __IOM uint32_t  DRIM;                 /* Offset: 0x414 (R/W) Device RESUME Interrupt Mask Register */
  __IOM uint32_t  DRISC;                /* Offset: 0x418 (R/W) Device RESUME Interrupt Status and Clear Register */
  __IOM uint32_t  GPCS;                 /* Offset: 0x41C (R/W) General-Purpose Control and Status Register */
  __IM  uint32_t  RESERVED65[4];
  __IOM uint32_t  VDC;                  /* Offset: 0x430 (R/W) VBUS Droop Control Register */
  __IM  uint32_t  VDCRIS;               /* Offset: 0x434 (R/ ) VBUS Droop Control Raw Interrupt Status Register */
  __IOM uint32_t  VDCIM;                /* Offset: 0x438 (R/W) VBUS Droop Control Interrupt Mask Register */
  __IOM uint32_t  VDCISC;               /* Offset: 0x43C (R/W) VBUS Droop Control Interrupt Status and Clear Register */
  __IM  uint32_t  RESERVED66;
  __IM  uint32_t  IDVRIS;               /* Offset: 0x444 (R/ ) ID Valid Detect Raw Interrupt Status Register */
  __IOM uint32_t  IDVIM;                /* Offset: 0x448 (R/W) ID Valid Detect Interrupt Mask Register */
  __IOM uint32_t  IDVISC;               /* Offset: 0x44C (R/W) ID Valid Detect Interrupt Status and Clear Register */
  __IOM uint32_t  DMASEL;               /* Offset: 0x450 (R/W) DMA Select Register */
} LM3S_USB_TypeDef;

/* LM3S USB FADDR Register Definitions */
#define LM3S_USB_FADDR_FUNCADDR_Pos               0
#define LM3S_USB_FADDR_FUNCADDR_Msk              (0x7FUL /*<< LM3S_USB_FADDR_FUNCADDR_Pos*/)

/* LM3S USB Host POWER Register Definitions */
#define LM3S_USB_POWER_RESET_Pos                  3
#define LM3S_USB_POWER_RESET_Msk                 (1UL << LM3S_USB_POWER_RESET_Pos)

#define LM3S_USB_POWER_RESUME_Pos                 2
#define LM3S_USB_POWER_RESUME_Msk                (1UL << LM3S_USB_POWER_RESUME_Pos)

#define LM3S_USB_POWER_SUSPEND_Pos                1
#define LM3S_USB_POWER_SUSPEND_Msk               (1UL << LM3S_USB_POWER_SUSPEND_Pos)

#define LM3S_USB_POWER_PWRDNPHY_Pos               0
#define LM3S_USB_POWER_PWRDNPHY_Msk              (1UL /*<< LM3S_USB_POWER_PWRDNPHY_Pos*/)

/* LM3S USB Device POWER Register Definitions */
#define LM3S_USB_POWER_ISOUP_Pos                  7
#define LM3S_USB_POWER_ISOUP_Msk                 (1UL << LM3S_USB_POWER_RESET_Pos)

#define LM3S_USB_POWER_SOFTCONN_Pos               6
#define LM3S_USB_POWER_SOFTCONN_Msk              (1UL << LM3S_USB_POWER_RESUME_Pos)

#define LM3S_USB_POWER_RESET_Pos                  3
#define LM3S_USB_POWER_RESET_Msk                 (1UL << LM3S_USB_POWER_RESET_Pos)

#define LM3S_USB_POWER_RESUME_Pos                 2
#define LM3S_USB_POWER_RESUME_Msk                (1UL << LM3S_USB_POWER_RESUME_Pos)

#define LM3S_USB_POWER_SUSPEND_Pos                1
#define LM3S_USB_POWER_SUSPEND_Msk               (1UL << LM3S_USB_POWER_SUSPEND_Pos)

#define LM3S_USB_POWER_PWRDNPHY_Pos               0
#define LM3S_USB_POWER_PWRDNPHY_Msk              (1UL /*<< LM3S_USB_POWER_PWRDNPHY_Pos*/)

/* LM3S USB TXIS Register Definitions */
#define LM3S_USB_TXIS_EP15_Pos                   15
#define LM3S_USB_TXIS_EP15_Msk                   (1UL << LM3S_USB_TXIS_EP15_Pos)

#define LM3S_USB_TXIS_EP14_Pos                   14
#define LM3S_USB_TXIS_EP14_Msk                   (1UL << LM3S_USB_TXIS_EP14_Pos)

#define LM3S_USB_TXIS_EP13_Pos                   13
#define LM3S_USB_TXIS_EP13_Msk                   (1UL << LM3S_USB_TXIS_EP13_Pos)

#define LM3S_USB_TXIS_EP12_Pos                   12
#define LM3S_USB_TXIS_EP12_Msk                   (1UL << LM3S_USB_TXIS_EP12_Pos)

#define LM3S_USB_TXIS_EP11_Pos                   11
#define LM3S_USB_TXIS_EP11_Msk                   (1UL << LM3S_USB_TXIS_EP11_Pos)

#define LM3S_USB_TXIS_EP10_Pos                   10
#define LM3S_USB_TXIS_EP10_Msk                   (1UL << LM3S_USB_TXIS_EP10_Pos)

#define LM3S_USB_TXIS_EP9_Pos                     9
#define LM3S_USB_TXIS_EP9_Msk                    (1UL << LM3S_USB_TXIS_EP9_Pos)

#define LM3S_USB_TXIS_EP8_Pos                     8
#define LM3S_USB_TXIS_EP8_Msk                    (1UL << LM3S_USB_TXIS_EP8_Pos)

#define LM3S_USB_TXIS_EP7_Pos                     7
#define LM3S_USB_TXIS_EP7_Msk                    (1UL << LM3S_USB_TXIS_EP7_Pos)

#define LM3S_USB_TXIS_EP6_Pos                     6
#define LM3S_USB_TXIS_EP6_Msk                    (1UL << LM3S_USB_TXIS_EP6_Pos)

#define LM3S_USB_TXIS_EP5_Pos                     5
#define LM3S_USB_TXIS_EP5_Msk                    (1UL << LM3S_USB_TXIS_EP5_Pos)

#define LM3S_USB_TXIS_EP4_Pos                     4
#define LM3S_USB_TXIS_EP4_Msk                    (1UL << LM3S_USB_TXIS_EP4_Pos)

#define LM3S_USB_TXIS_EP3_Pos                     3
#define LM3S_USB_TXIS_EP3_Msk                    (1UL << LM3S_USB_TXIS_EP3_Pos)

#define LM3S_USB_TXIS_EP2_Pos                     2
#define LM3S_USB_TXIS_EP2_Msk                    (1UL << LM3S_USB_TXIS_EP2_Pos)

#define LM3S_USB_TXIS_EP1_Pos                     1
#define LM3S_USB_TXIS_EP1_Msk                    (1UL << LM3S_USB_TXIS_EP1_Pos)

#define LM3S_USB_TXIS_EP0_Pos                     0
#define LM3S_USB_TXIS_EP0_Msk                    (1UL /*<< LM3S_USB_TXIS_EP0_Pos*/)

/* LM3S USB RXIS Register Definitions */
#define LM3S_USB_RXIS_EP15_Pos                   15
#define LM3S_USB_RXIS_EP15_Msk                   (1UL << LM3S_USB_RXIS_EP15_Pos)

#define LM3S_USB_RXIS_EP14_Pos                   14
#define LM3S_USB_RXIS_EP14_Msk                   (1UL << LM3S_USB_RXIS_EP14_Pos)

#define LM3S_USB_RXIS_EP13_Pos                   13
#define LM3S_USB_RXIS_EP13_Msk                   (1UL << LM3S_USB_RXIS_EP13_Pos)

#define LM3S_USB_RXIS_EP12_Pos                   12
#define LM3S_USB_RXIS_EP12_Msk                   (1UL << LM3S_USB_RXIS_EP12_Pos)

#define LM3S_USB_RXIS_EP11_Pos                   11
#define LM3S_USB_RXIS_EP11_Msk                   (1UL << LM3S_USB_RXIS_EP11_Pos)

#define LM3S_USB_RXIS_EP10_Pos                   10
#define LM3S_USB_RXIS_EP10_Msk                   (1UL << LM3S_USB_RXIS_EP10_Pos)

#define LM3S_USB_RXIS_EP9_Pos                     9
#define LM3S_USB_RXIS_EP9_Msk                    (1UL << LM3S_USB_RXIS_EP9_Pos)

#define LM3S_USB_RXIS_EP8_Pos                     8
#define LM3S_USB_RXIS_EP8_Msk                    (1UL << LM3S_USB_RXIS_EP8_Pos)

#define LM3S_USB_RXIS_EP7_Pos                     7
#define LM3S_USB_RXIS_EP7_Msk                    (1UL << LM3S_USB_RXIS_EP7_Pos)

#define LM3S_USB_RXIS_EP6_Pos                     6
#define LM3S_USB_RXIS_EP6_Msk                    (1UL << LM3S_USB_RXIS_EP6_Pos)

#define LM3S_USB_RXIS_EP5_Pos                     5
#define LM3S_USB_RXIS_EP5_Msk                    (1UL << LM3S_USB_RXIS_EP5_Pos)

#define LM3S_USB_RXIS_EP4_Pos                     4
#define LM3S_USB_RXIS_EP4_Msk                    (1UL << LM3S_USB_RXIS_EP4_Pos)

#define LM3S_USB_RXIS_EP3_Pos                     3
#define LM3S_USB_RXIS_EP3_Msk                    (1UL << LM3S_USB_RXIS_EP3_Pos)

#define LM3S_USB_RXIS_EP2_Pos                     2
#define LM3S_USB_RXIS_EP2_Msk                    (1UL << LM3S_USB_RXIS_EP2_Pos)

#define LM3S_USB_RXIS_EP1_Pos                     1
#define LM3S_USB_RXIS_EP1_Msk                    (1UL << LM3S_USB_RXIS_EP1_Pos)

/* LM3S USB TXIE Register Definitions */
#define LM3S_USB_TXIE_EP15_Pos                   15
#define LM3S_USB_TXIE_EP15_Msk                   (1UL << LM3S_USB_TXIE_EP15_Pos)

#define LM3S_USB_TXIE_EP14_Pos                   14
#define LM3S_USB_TXIE_EP14_Msk                   (1UL << LM3S_USB_TXIE_EP14_Pos)

#define LM3S_USB_TXIE_EP13_Pos                   13
#define LM3S_USB_TXIE_EP13_Msk                   (1UL << LM3S_USB_TXIE_EP13_Pos)

#define LM3S_USB_TXIE_EP12_Pos                   12
#define LM3S_USB_TXIE_EP12_Msk                   (1UL << LM3S_USB_TXIE_EP12_Pos)

#define LM3S_USB_TXIE_EP11_Pos                   11
#define LM3S_USB_TXIE_EP11_Msk                   (1UL << LM3S_USB_TXIE_EP11_Pos)

#define LM3S_USB_TXIE_EP10_Pos                   10
#define LM3S_USB_TXIE_EP10_Msk                   (1UL << LM3S_USB_TXIE_EP10_Pos)

#define LM3S_USB_TXIE_EP9_Pos                     9
#define LM3S_USB_TXIE_EP9_Msk                    (1UL << LM3S_USB_TXIE_EP9_Pos)

#define LM3S_USB_TXIE_EP8_Pos                     8
#define LM3S_USB_TXIE_EP8_Msk                    (1UL << LM3S_USB_TXIE_EP8_Pos)

#define LM3S_USB_TXIE_EP7_Pos                     7
#define LM3S_USB_TXIE_EP7_Msk                    (1UL << LM3S_USB_TXIE_EP7_Pos)

#define LM3S_USB_TXIE_EP6_Pos                     6
#define LM3S_USB_TXIE_EP6_Msk                    (1UL << LM3S_USB_TXIE_EP6_Pos)

#define LM3S_USB_TXIE_EP5_Pos                     5
#define LM3S_USB_TXIE_EP5_Msk                    (1UL << LM3S_USB_TXIE_EP5_Pos)

#define LM3S_USB_TXIE_EP4_Pos                     4
#define LM3S_USB_TXIE_EP4_Msk                    (1UL << LM3S_USB_TXIE_EP4_Pos)

#define LM3S_USB_TXIE_EP3_Pos                     3
#define LM3S_USB_TXIE_EP3_Msk                    (1UL << LM3S_USB_TXIE_EP3_Pos)

#define LM3S_USB_TXIE_EP2_Pos                     2
#define LM3S_USB_TXIE_EP2_Msk                    (1UL << LM3S_USB_TXIE_EP2_Pos)

#define LM3S_USB_TXIE_EP1_Pos                     1
#define LM3S_USB_TXIE_EP1_Msk                    (1UL << LM3S_USB_TXIE_EP1_Pos)

#define LM3S_USB_TXIE_EP0_Pos                     0
#define LM3S_USB_TXIE_EP0_Msk                    (1UL /*<< LM3S_USB_TXIE_EP0_Pos*/)

/* LM3S USB RXIE Register Definitions */
#define LM3S_USB_RXIE_EP15_Pos                   15
#define LM3S_USB_RXIE_EP15_Msk                   (1UL << LM3S_USB_RXIE_EP15_Pos)

#define LM3S_USB_RXIE_EP14_Pos                   14
#define LM3S_USB_RXIE_EP14_Msk                   (1UL << LM3S_USB_RXIE_EP14_Pos)

#define LM3S_USB_RXIE_EP13_Pos                   13
#define LM3S_USB_RXIE_EP13_Msk                   (1UL << LM3S_USB_RXIE_EP13_Pos)

#define LM3S_USB_RXIE_EP12_Pos                   12
#define LM3S_USB_RXIE_EP12_Msk                   (1UL << LM3S_USB_RXIE_EP12_Pos)

#define LM3S_USB_RXIE_EP11_Pos                   11
#define LM3S_USB_RXIE_EP11_Msk                   (1UL << LM3S_USB_RXIE_EP11_Pos)

#define LM3S_USB_RXIE_EP10_Pos                   10
#define LM3S_USB_RXIE_EP10_Msk                   (1UL << LM3S_USB_RXIE_EP10_Pos)

#define LM3S_USB_RXIE_EP9_Pos                     9
#define LM3S_USB_RXIE_EP9_Msk                    (1UL << LM3S_USB_RXIE_EP9_Pos)

#define LM3S_USB_RXIE_EP8_Pos                     8
#define LM3S_USB_RXIE_EP8_Msk                    (1UL << LM3S_USB_RXIE_EP8_Pos)

#define LM3S_USB_RXIE_EP7_Pos                     7
#define LM3S_USB_RXIE_EP7_Msk                    (1UL << LM3S_USB_RXIE_EP7_Pos)

#define LM3S_USB_RXIE_EP6_Pos                     6
#define LM3S_USB_RXIE_EP6_Msk                    (1UL << LM3S_USB_RXIE_EP6_Pos)

#define LM3S_USB_RXIE_EP5_Pos                     5
#define LM3S_USB_RXIE_EP5_Msk                    (1UL << LM3S_USB_RXIE_EP5_Pos)

#define LM3S_USB_RXIE_EP4_Pos                     4
#define LM3S_USB_RXIE_EP4_Msk                    (1UL << LM3S_USB_RXIE_EP4_Pos)

#define LM3S_USB_RXIE_EP3_Pos                     3
#define LM3S_USB_RXIE_EP3_Msk                    (1UL << LM3S_USB_RXIE_EP3_Pos)

#define LM3S_USB_RXIE_EP2_Pos                     2
#define LM3S_USB_RXIE_EP2_Msk                    (1UL << LM3S_USB_RXIE_EP2_Pos)

#define LM3S_USB_RXIE_EP1_Pos                     1
#define LM3S_USB_RXIE_EP1_Msk                    (1UL << LM3S_USB_RXIE_EP1_Pos)

/* LM3S USB Host IS Register Definitions */
#define LM3S_USB_IS_VBUSERR_Pos                   7
#define LM3S_USB_IS_VBUSERR_Msk                  (1UL << LM3S_USB_IS_VBUSERR_Pos)

#define LM3S_USB_IS_SESREQ_Pos                    6
#define LM3S_USB_IS_SESREQ_Msk                   (1UL << LM3S_USB_IS_SESREQ_Pos)

#define LM3S_USB_IS_DISCON_Pos                    5
#define LM3S_USB_IS_DISCON_Msk                   (1UL << LM3S_USB_IS_DISCON_Pos)

#define LM3S_USB_IS_CONN_Pos                      4
#define LM3S_USB_IS_CONN_Msk                     (1UL << LM3S_USB_IS_CONN_Pos)

#define LM3S_USB_IS_SOF_Pos                       3
#define LM3S_USB_IS_SOF_Msk                      (1UL << LM3S_USB_IS_SOF_Pos)

#define LM3S_USB_IS_BABBLE_Pos                    2
#define LM3S_USB_IS_BABBLE_Msk                   (1UL << LM3S_USB_IS_BABBLE_Pos)

#define LM3S_USB_IS_RESUME_Pos                    1
#define LM3S_USB_IS_RESUME_Msk                   (1UL << LM3S_USB_IS_RESUME_Pos)

/* LM3S USB Device IS Register Definitions */
#define LM3S_USB_IS_DISCON_Pos                    5
#define LM3S_USB_IS_DISCON_Msk                   (1UL << LM3S_USB_IS_DISCON_Pos)

#define LM3S_USB_IS_SOF_Pos                       3
#define LM3S_USB_IS_SOF_Msk                      (1UL << LM3S_USB_IS_SOF_Pos)

#define LM3S_USB_IS_BABBLE_Pos                    2
#define LM3S_USB_IS_BABBLE_Msk                   (1UL << LM3S_USB_IS_BABBLE_Pos)

#define LM3S_USB_IS_RESUME_Pos                    1
#define LM3S_USB_IS_RESUME_Msk                   (1UL << LM3S_USB_IS_RESUME_Pos)

#define LM3S_USB_IS_SUSPEND_Pos                   0
#define LM3S_USB_IS_SUSPEND_Msk                  (1UL /*<< LM3S_USB_IS_SUSPEND_Pos*/)

/* LM3S USB Host IE Register Definitions */
#define LM3S_USB_IE_VBUSERR_Pos                   7
#define LM3S_USB_IE_VBUSERR_Msk                  (1UL << LM3S_USB_IE_VBUSERR_Pos)

#define LM3S_USB_IE_SESREQ_Pos                    6
#define LM3S_USB_IE_SESREQ_Msk                   (1UL << LM3S_USB_IE_SESREQ_Pos)

#define LM3S_USB_IE_DIECON_Pos                    5
#define LM3S_USB_IE_DIECON_Msk                   (1UL << LM3S_USB_IE_DIECON_Pos)

#define LM3S_USB_IE_CONN_Pos                      4
#define LM3S_USB_IE_CONN_Msk                     (1UL << LM3S_USB_IE_CONN_Pos)

#define LM3S_USB_IE_SOF_Pos                       3
#define LM3S_USB_IE_SOF_Msk                      (1UL << LM3S_USB_IE_SOF_Pos)

#define LM3S_USB_IE_BABBLE_Pos                    2
#define LM3S_USB_IE_BABBLE_Msk                   (1UL << LM3S_USB_IE_BABBLE_Pos)

#define LM3S_USB_IE_RESUME_Pos                    1
#define LM3S_USB_IE_RESUME_Msk                   (1UL << LM3S_USB_IE_RESUME_Pos)

/* LM3S USB Device IE Register Definitions */
#define LM3S_USB_IE_DIECON_Pos                    5
#define LM3S_USB_IE_DIECON_Msk                   (1UL << LM3S_USB_IE_DIECON_Pos)

#define LM3S_USB_IE_SOF_Pos                       3
#define LM3S_USB_IE_SOF_Msk                      (1UL << LM3S_USB_IE_SOF_Pos)

#define LM3S_USB_IE_BABBLE_Pos                    2
#define LM3S_USB_IE_BABBLE_Msk                   (1UL << LM3S_USB_IE_BABBLE_Pos)

#define LM3S_USB_IE_RESUME_Pos                    1
#define LM3S_USB_IE_RESUME_Msk                   (1UL << LM3S_USB_IE_RESUME_Pos)

#define LM3S_USB_IE_SUSPEND_Pos                   0
#define LM3S_USB_IE_SUSPEND_Msk                  (1UL /*<< LM3S_USB_IE_SUSPEND_Pos*/)

/* LM3S USB FRAME Register Definitions */
#define LM3S_USB_FRAME_FRAME_Pos                  0
#define LM3S_USB_FRAME_FRAME_Msk                 (0x07FFUL /*<< LM3S_USB_FRAME_FRAME_Pos*/)

/* LM3S USB EPIDX Register Definitions */
#define LM3S_USB_EPIDX_EPIDX_Pos                  0
#define LM3S_USB_EPIDX_EPIDX_Msk                 (0x0FUL /*<< LM3S_USB_EPIDX_EPIDX_Pos*/)

/* LM3S USB Host TEST Register Definitions */
#define LM3S_USB_TEST_FORCEH_Pos                  7
#define LM3S_USB_TEST_FORCEH_Msk                 (1UL << LM3S_USB_TEST_FORCEH_Pos)

#define LM3S_USB_TEST_FIFOACC_Pos                 6
#define LM3S_USB_TEST_FIFOACC_Msk                (1UL << LM3S_USB_TEST_FIFOACC_Pos)

#define LM3S_USB_TEST_FORCEFS_Pos                 5
#define LM3S_USB_TEST_FORCEFS_Msk                (1UL << LM3S_USB_TEST_FORCEFS_Pos)

/* LM3S USB Device TEST Register Definitions */
#define LM3S_USB_TEST_FIFOACC_Pos                 6
#define LM3S_USB_TEST_FIFOACC_Msk                (1UL << LM3S_USB_TEST_FIFOACC_Pos)

#define LM3S_USB_TEST_FORCEFS_Pos                 5
#define LM3S_USB_TEST_FORCEFS_Msk                (1UL << LM3S_USB_TEST_FORCEFS_Pos)

/* LM3S USB FIFON Register Definitions */
#define LM3S_USB_FIFON_EPDATA_Pos                 0
#define LM3S_USB_FIFON_EPDATA_Msk                (0xFFFFFFFFUL /*<< LM3S_USB_FIFON_EPDATA_Pos*/)

/* LM3S USB DEVCTL Register Definitions */
#define LM3S_USB_DEVCTL_DEV_Pos                   7
#define LM3S_USB_DEVCTL_DEV_Msk                  (1UL << LM3S_USB_DEVCTL_DEV_Pos)

#define LM3S_USB_DEVCTL_FSDEV_Pos                 6
#define LM3S_USB_DEVCTL_FSDEV_Msk                (1UL << LM3S_USB_DEVCTL_FSDEV_Pos)

#define LM3S_USB_DEVCTL_LSDEV_Pos                 5
#define LM3S_USB_DEVCTL_LSDEV_Msk                (1UL << LM3S_USB_DEVCTL_LSDEV_Pos)

#define LM3S_USB_DEVCTL_VBUS_Pos                  3
#define LM3S_USB_DEVCTL_VBUS_Msk                 (0x03UL << LM3S_USB_DEVCTL_VBUS_Pos)
#define LM3S_USB_DEVCTL_VBUS_1_Pos                4
#define LM3S_USB_DEVCTL_VBUS_1_Msk               (1UL << LM3S_USB_DEVCTL_VBUS_1_Pos)
#define LM3S_USB_DEVCTL_VBUS_0_Pos                3
#define LM3S_USB_DEVCTL_VBUS_0_Msk               (1UL << LM3S_USB_DEVCTL_VBUS_0_Pos)

#define LM3S_USB_DEVCTL_HOST_Pos                  2
#define LM3S_USB_DEVCTL_HOST_Msk                 (1UL << LM3S_USB_DEVCTL_HOST_Pos)

#define LM3S_USB_DEVCTL_HOSTREQ_Pos               1
#define LM3S_USB_DEVCTL_HOSTREQ_Msk              (1UL << LM3S_USB_DEVCTL_HOSTREQ_Pos)

#define LM3S_USB_DEVCTL_SESSION_Pos               0
#define LM3S_USB_DEVCTL_SESSION_Msk              (1UL /*<< LM3S_USB_DEVCTL_SESSION_Pos*/)

/* LM3S USB TXFIFOS Register Definitions */
#define LM3S_USB_TXFIFOS_DPB_Pos                  4
#define LM3S_USB_TXFIFOS_DPB_Msk                 (1UL << LM3S_USB_TXFIFOS_DPB_Pos)

#define LM3S_USB_TXFIFOS_SIZE_Pos                 0
#define LM3S_USB_TXFIFOS_SIZE_Msk                (0x0FUL /*<< LM3S_USB_TXFIFOS_SIZE_Pos*/)
#define LM3S_USB_TXFIFOS_SIZE_3_Pos               4
#define LM3S_USB_TXFIFOS_SIZE_3_Msk              (1UL << LM3S_USB_TXFIFOS_SIZE_3_Pos)
#define LM3S_USB_TXFIFOS_SIZE_2_Pos               2
#define LM3S_USB_TXFIFOS_SIZE_2_Msk              (1UL << LM3S_USB_TXFIFOS_SIZE_2_Pos)
#define LM3S_USB_TXFIFOS_SIZE_1_Pos               1
#define LM3S_USB_TXFIFOS_SIZE_1_Msk              (1UL << LM3S_USB_TXFIFOS_SIZE_1_Pos)
#define LM3S_USB_TXFIFOS_SIZE_0_Pos               0
#define LM3S_USB_TXFIFOS_SIZE_0_Msk              (1UL /*<< LM3S_USB_TXFIFOS_SIZE_0_Pos*/)

/* LM3S USB RXFIFOS Register Definitions */
#define LM3S_USB_RXFIFOS_DPB_Pos                  4
#define LM3S_USB_RXFIFOS_DPB_Msk                 (1UL << LM3S_USB_RXFIFOS_DPB_Pos)

#define LM3S_USB_RXFIFOS_SIZE_Pos                 0
#define LM3S_USB_RXFIFOS_SIZE_Msk                (0x0FUL /*<< LM3S_USB_RXFIFOS_SIZE_Pos*/)
#define LM3S_USB_RXFIFOS_SIZE_3_Pos               4
#define LM3S_USB_RXFIFOS_SIZE_3_Msk              (1UL << LM3S_USB_RXFIFOS_SIZE_3_Pos)
#define LM3S_USB_RXFIFOS_SIZE_2_Pos               2
#define LM3S_USB_RXFIFOS_SIZE_2_Msk              (1UL << LM3S_USB_RXFIFOS_SIZE_2_Pos)
#define LM3S_USB_RXFIFOS_SIZE_1_Pos               1
#define LM3S_USB_RXFIFOS_SIZE_1_Msk              (1UL << LM3S_USB_RXFIFOS_SIZE_1_Pos)
#define LM3S_USB_RXFIFOS_SIZE_0_Pos               0
#define LM3S_USB_RXFIFOS_SIZE_0_Msk              (1UL /*<< LM3S_USB_RXFIFOS_SIZE_0_Pos*/)

/* LM3S USB TXFIFOADD Register Definitions */
#define LM3S_USB_TXFIFOADD_ADDR_Pos               0
#define LM3S_USB_TXFIFOADD_ADDR_Msk              (0x01FFUL /*<< LM3S_USB_TXFIFOADD_ADDR_Pos*/)

/* LM3S USB RXFIFOADD Register Definitions */
#define LM3S_USB_RXFIFOADD_ADDR_Pos               0
#define LM3S_USB_RXFIFOADD_ADDR_Msk              (0x01FFUL /*<< LM3S_USB_RXFIFOADD_ADDR_Pos*/)

/* LM3S USB CONTIM Register Definitions */
#define LM3S_USB_CONTIM_WTCON_Pos                 4
#define LM3S_USB_CONTIM_WTCON_Msk                (0x0FUL << LM3S_USB_CONTIM_WTCON_Pos)

#define LM3S_USB_CONTIM_WTID_Pos                  0
#define LM3S_USB_CONTIM_WTID_Msk                 (0x0FUL /*<< LM3S_USB_CONTIM_WTID_Pos*/)

/* LM3S USB VPLEN Register Definitions */
#define LM3S_USB_VPLEN_VPLEN_Pos                  0
#define LM3S_USB_VPLEN_VPLEN_Msk                 (0xFFUL /*<< LM3S_USB_VPLEN_VPLEN_Pos*/)

/* LM3S USB FSEOF Register Definitions */
#define LM3S_USB_FSEOF_FSEOF_Pos                  0
#define LM3S_USB_FSEOF_FSEOF_Msk                 (0xFFUL /*<< LM3S_USB_FSEOF_FSEOF_Pos*/)

/* LM3S USB LSEOF Register Definitions */
#define LM3S_USB_LSEOF_LSEOF_Pos                  0
#define LM3S_USB_LSEOF_LSEOF_Msk                 (0xFFUL /*<< LM3S_USB_LSEOF_LSEOF_Pos*/)

/* LM3S USB TXFUNCADDRN Register Definitions */
#define LM3S_USB_TXFUNCADDRN_ADDR_Pos             0
#define LM3S_USB_TXFUNCADDRN_ADDR_Msk            (0x7FUL /*<< LM3S_USB_TXFUNCADDRN_ADDR_Pos*/)

/* LM3S USB TXHUBADDRN Register Definitions */
#define LM3S_USB_TXHUBADDRN_MULTTRAN_Pos          7
#define LM3S_USB_TXHUBADDRN_MULTTRAN_Msk         (1UL << LM3S_USB_TXHUBADDRN_MULTTRAN_Pos)

#define LM3S_USB_TXHUBADDRN_ADDR_Pos              0
#define LM3S_USB_TXHUBADDRN_ADDR_Msk             (0x7FUL /*<< LM3S_USB_TXHUBADDRN_ADDR_Pos*/)

/* LM3S USB TXHUBPORTN Register Definitions */
#define LM3S_USB_TXHUBPORTN_PORT_Pos              0
#define LM3S_USB_TXHUBPORTN_PORT_Msk             (0x7FUL /*<< LM3S_USB_TXHUBPORTN_PORT_Pos*/)

/* LM3S USB RXFUNCADDRN Register Definitions */
#define LM3S_USB_RXFUNCADDRN_ADDR_Pos             0
#define LM3S_USB_RXFUNCADDRN_ADDR_Msk            (0x7FUL /*<< LM3S_USB_RXFUNCADDRN_ADDR_Pos*/)

/* LM3S USB RXHUBADDRN Register Definitions */
#define LM3S_USB_RXHUBADDRN_MULTTRAN_Pos          7
#define LM3S_USB_RXHUBADDRN_MULTTRAN_Msk         (1UL << LM3S_USB_RXHUBADDRN_MULTTRAN_Pos)

#define LM3S_USB_RXHUBADDRN_ADDR_Pos              0
#define LM3S_USB_RXHUBADDRN_ADDR_Msk             (0x7FUL /*<< LM3S_USB_RXHUBADDRN_ADDR_Pos*/)

/* LM3S USB RXHUBPORTN Register Definitions */
#define LM3S_USB_RXHUBPORTN_PORT_Pos              0
#define LM3S_USB_RXHUBPORTN_PORT_Msk             (0x7FUL /*<< LM3S_USB_RXHUBPORTN_PORT_Pos*/)

/* LM3S USB TXMAXPN Register Definitions */
#define LM3S_USB_TXMAXPN_MAXLOAD_Pos              0
#define LM3S_USB_TXMAXPN_MAXLOAD_Msk             (0x07FFUL /*<< LM3S_USB_TXMAXPN_MAXLOAD_Pos*/)

/* LM3S USB Host CSRL0 Register Definitions */
#define LM3S_USB_CSRL0_NAKTO_Pos                  7
#define LM3S_USB_CSRL0_NAKTO_Msk                 (1UL << LM3S_USB_CSRL0_NAKTO_Pos)

#define LM3S_USB_CSRL0_STATUS_Pos                 6
#define LM3S_USB_CSRL0_STATUS_Msk                (1UL << LM3S_USB_CSRL0_STATUS_Pos)

#define LM3S_USB_CSRL0_REQPKT_Pos                 5
#define LM3S_USB_CSRL0_REQPKT_Msk                (1UL << LM3S_USB_CSRL0_REQPKT_Pos)

#define LM3S_USB_CSRL0_ERROR_Pos                  4
#define LM3S_USB_CSRL0_ERROR_Msk                 (1UL << LM3S_USB_CSRL0_ERROR_Pos)

#define LM3S_USB_CSRL0_SETUP_Pos                  3
#define LM3S_USB_CSRL0_SETUP_Msk                 (1UL << LM3S_USB_CSRL0_SETUP_Pos)

#define LM3S_USB_CSRL0_STALLED_Pos                2
#define LM3S_USB_CSRL0_STALLED_Msk               (1UL << LM3S_USB_CSRL0_STALLED_Pos)

#define LM3S_USB_CSRL0_TXRDY_Pos                  1
#define LM3S_USB_CSRL0_TXRDY_Msk                 (1UL << LM3S_USB_CSRL0_TXRDY_Pos)

#define LM3S_USB_CSRL0_RXRDY_Pos                  0
#define LM3S_USB_CSRL0_RXRDY_Msk                 (1UL /*<< LM3S_USB_CSRL0_RXRDY_Pos*/)

/* LM3S USB Device CSRL0 Register Definitions */
#define LM3S_USB_CSRL0_SETENDC_Pos                7
#define LM3S_USB_CSRL0_SETENDC_Msk               (1UL << LM3S_USB_CSRL0_SETENDC_Pos)

#define LM3S_USB_CSRL0_RXRDYC_Pos                 6
#define LM3S_USB_CSRL0_RXRDYC_Msk                (1UL << LM3S_USB_CSRL0_RXRDYC_Pos)

#define LM3S_USB_CSRL0_STALL_Pos                  5
#define LM3S_USB_CSRL0_STALL_Msk                 (1UL << LM3S_USB_CSRL0_STALL_Pos)

#define LM3S_USB_CSRL0_SETEND_Pos                 4
#define LM3S_USB_CSRL0_SETEND_Msk                (1UL << LM3S_USB_CSRL0_SETEND_Pos)

#define LM3S_USB_CSRL0_DATAEND_Pos                3
#define LM3S_USB_CSRL0_DATAEND_Msk               (1UL << LM3S_USB_CSRL0_DATAEND_Pos)

#define LM3S_USB_CSRL0_STALLED_Pos                2
#define LM3S_USB_CSRL0_STALLED_Msk               (1UL << LM3S_USB_CSRL0_STALLED_Pos)

#define LM3S_USB_CSRL0_TXRDY_Pos                  1
#define LM3S_USB_CSRL0_TXRDY_Msk                 (1UL << LM3S_USB_CSRL0_TXRDY_Pos)

#define LM3S_USB_CSRL0_RXRDY_Pos                  0
#define LM3S_USB_CSRL0_RXRDY_Msk                 (1UL /*<< LM3S_USB_CSRL0_RXRDY_Pos*/)

/* LM3S USB Host CSRH0 Register Definitions */
#define LM3S_USB_CSRH0_DTWE_Pos                   2
#define LM3S_USB_CSRH0_DTWE_Msk                  (1UL << LM3S_USB_CSRH0_DTWE_Pos)

#define LM3S_USB_CSRH0_DT_Pos                     1
#define LM3S_USB_CSRH0_DT_Msk                    (1UL << LM3S_USB_CSRH0_DT_Pos)

#define LM3S_USB_CSRH0_FLUSH_Pos                  0
#define LM3S_USB_CSRH0_FLUSH_Msk                 (1UL /*<< LM3S_USB_CSRH0_FLUSH_Pos*/)

/* LM3S USB Device CSRH0 Register Definitions */
#define LM3S_USB_CSRH0_FLUSH_Pos                  0
#define LM3S_USB_CSRH0_FLUSH_Msk                 (1UL /*<< LM3S_USB_CSRH0_FLUSH_Pos*/)

/* LM3S USB COUNT0 Register Definitions */
#define LM3S_USB_COUNT0_COUNT_Pos                 0
#define LM3S_USB_COUNT0_COUNT_Msk                (0x7FUL /*<< LM3S_USB_COUNT0_COUNT_Pos*/)

/* LM3S USB Host TYPE0 Register Definitions */
#define LM3S_USB_TYPE0_SPEED_Pos                  6
#define LM3S_USB_TYPE0_SPEED_Msk                 (0x03UL << LM3S_USB_TYPE0_SPEED_Pos)
#define LM3S_USB_TYPE0_SPEED_1_Pos                7
#define LM3S_USB_TYPE0_SPEED_1_Msk               (1UL << LM3S_USB_TYPE0_SPEED_1_Pos)
#define LM3S_USB_TYPE0_SPEED_0_Pos                6
#define LM3S_USB_TYPE0_SPEED_0_Msk               (1UL << LM3S_USB_TYPE0_SPEED_0_Pos)

/* LM3S USB Host NAKLMT Register Definitions */
#define LM3S_USB_NAKLMT_NAKLMT_Pos                0
#define LM3S_USB_NAKLMT_NAKLMT_Msk               (0x1FUL /*<< LM3S_USB_NAKLMT_NAKLMT_Pos*/)

/* LM3S USB Host TXCSRLN Register Definitions */
#define LM3S_USB_TXCSRLN_NAKTO_Pos                7
#define LM3S_USB_TXCSRLN_NAKTO_Msk               (1UL << LM3S_USB_TXCSRLN_NAKTO_Pos)

#define LM3S_USB_TXCSRLN_CLRDT_Pos                6
#define LM3S_USB_TXCSRLN_CLRDT_Msk               (1UL << LM3S_USB_TXCSRLN_CLRDT_Pos)

#define LM3S_USB_TXCSRLN_STALLED_Pos              5
#define LM3S_USB_TXCSRLN_STALLED_Msk             (1UL << LM3S_USB_TXCSRLN_STALLED_Pos)

#define LM3S_USB_TXCSRLN_SETUP_Pos                4
#define LM3S_USB_TXCSRLN_SETUP_Msk               (1UL << LM3S_USB_TXCSRLN_SETUP_Pos)

#define LM3S_USB_TXCSRLN_FLUSH_Pos                3
#define LM3S_USB_TXCSRLN_FLUSH_Msk               (1UL << LM3S_USB_TXCSRLN_FLUSH_Pos)

#define LM3S_USB_TXCSRLN_ERROR_Pos                2
#define LM3S_USB_TXCSRLN_ERROR_Msk               (1UL << LM3S_USB_TXCSRLN_ERROR_Pos)

#define LM3S_USB_TXCSRLN_FIFONE_Pos               1
#define LM3S_USB_TXCSRLN_FIFONE_Msk              (1UL << LM3S_USB_TXCSRLN_FIFONE_Pos)

#define LM3S_USB_TXCSRLN_TXRDY_Pos                0
#define LM3S_USB_TXCSRLN_TXRDY_Msk               (1UL /*<< LM3S_USB_TXCSRLN_TXRDY_Pos*/)

/* LM3S USB Device TXCSRLN Register Definitions */
#define LM3S_USB_TXCSRLN_CLRDT_Pos                6
#define LM3S_USB_TXCSRLN_CLRDT_Msk               (1UL << LM3S_USB_TXCSRLN_CLRDT_Pos)

#define LM3S_USB_TXCSRLN_STALLED_Pos              5
#define LM3S_USB_TXCSRLN_STALLED_Msk             (1UL << LM3S_USB_TXCSRLN_STALLED_Pos)

#define LM3S_USB_TXCSRLN_STALL_Pos                4
#define LM3S_USB_TXCSRLN_STALL_Msk               (1UL << LM3S_USB_TXCSRLN_STALL_Pos)

#define LM3S_USB_TXCSRLN_FLUSH_Pos                3
#define LM3S_USB_TXCSRLN_FLUSH_Msk               (1UL << LM3S_USB_TXCSRLN_FLUSH_Pos)

#define LM3S_USB_TXCSRLN_UNDRN_Pos                2
#define LM3S_USB_TXCSRLN_UNDRN_Msk               (1UL << LM3S_USB_TXCSRLN_UNDRN_Pos)

#define LM3S_USB_TXCSRLN_FIFONE_Pos               1
#define LM3S_USB_TXCSRLN_FIFONE_Msk              (1UL << LM3S_USB_TXCSRLN_FIFONE_Pos)

#define LM3S_USB_TXCSRLN_TXRDY_Pos                0
#define LM3S_USB_TXCSRLN_TXRDY_Msk               (1UL /*<< LM3S_USB_TXCSRLN_TXRDY_Pos*/)

/* LM3S USB Host TXCSRHN Register Definitions */
#define LM3S_USB_TXCSRHN_AUTOSET_Pos              7
#define LM3S_USB_TXCSRHN_AUTOSET_Msk             (1UL << LM3S_USB_TXCSRHN_AUTOSET_Pos)

#define LM3S_USB_TXCSRHN_MODE_Pos                 5
#define LM3S_USB_TXCSRHN_MODE_Msk                (1UL << LM3S_USB_TXCSRHN_MODE_Pos)

#define LM3S_USB_TXCSRHN_DMAEN_Pos                4
#define LM3S_USB_TXCSRHN_DMAEN_Msk               (1UL << LM3S_USB_TXCSRHN_DMAEN_Pos)

#define LM3S_USB_TXCSRHN_FDT_Pos                  3
#define LM3S_USB_TXCSRHN_FDT_Msk                 (1UL << LM3S_USB_TXCSRHN_FDT_Pos)

#define LM3S_USB_TXCSRHN_DMAMOD_Pos               2
#define LM3S_USB_TXCSRHN_DMAMOD_Msk              (1UL << LM3S_USB_TXCSRHN_DMAMOD_Pos)

#define LM3S_USB_TXCSRHN_DTWE_Pos                 1
#define LM3S_USB_TXCSRHN_DTWE_Msk                (1UL << LM3S_USB_TXCSRHN_DTWE_Pos)

#define LM3S_USB_TXCSRHN_DT_Pos                   0
#define LM3S_USB_TXCSRHN_DT_Msk                  (1UL /*<< LM3S_USB_TXCSRHN_DT_Pos*/)

/* LM3S USB Device TXCSRLN Register Definitions */
#define LM3S_USB_TXCSRHN_AUTOSET_Pos              7
#define LM3S_USB_TXCSRHN_AUTOSET_Msk             (1UL << LM3S_USB_TXCSRHN_AUTOSET_Pos)

#define LM3S_USB_TXCSRHN_ISO_Pos                  6
#define LM3S_USB_TXCSRHN_ISO_Msk                 (1UL << LM3S_USB_TXCSRHN_ISO_Pos)

#define LM3S_USB_TXCSRHN_MODE_Pos                 5
#define LM3S_USB_TXCSRHN_MODE_Msk                (1UL << LM3S_USB_TXCSRHN_MODE_Pos)

#define LM3S_USB_TXCSRHN_DMAEN_Pos                4
#define LM3S_USB_TXCSRHN_DMAEN_Msk               (1UL << LM3S_USB_TXCSRHN_DMAEN_Pos)

#define LM3S_USB_TXCSRHN_FDT_Pos                  3
#define LM3S_USB_TXCSRHN_FDT_Msk                 (1UL << LM3S_USB_TXCSRHN_FDT_Pos)

#define LM3S_USB_TXCSRHN_DMAMOD_Pos               2
#define LM3S_USB_TXCSRHN_DMAMOD_Msk              (1UL << LM3S_USB_TXCSRHN_DMAMOD_Pos)

/* LM3S USB RXMAXPN Register Definitions */
#define LM3S_USB_RXMAXPN_MAXLOAD_Pos              0
#define LM3S_USB_RXMAXPN_MAXLOAD_Msk             (0x07FFUL /*<< LM3S_USB_RXMAXPN_MAXLOAD_Pos*/)

/* LM3S USB Host RXCSRLN Register Definitions */
#define LM3S_USB_RXCSRLN_CLRDT_Pos                7
#define LM3S_USB_RXCSRLN_CLRDT_Msk               (1UL << LM3S_USB_RXCSRLN_CLRDT_Pos)

#define LM3S_USB_RXCSRLN_STALLED_Pos              6
#define LM3S_USB_RXCSRLN_STALLED_Msk             (1UL << LM3S_USB_RXCSRLN_STALLED_Pos)

#define LM3S_USB_RXCSRLN_REQPKT_Pos               5
#define LM3S_USB_RXCSRLN_REQPKT_Msk              (1UL << LM3S_USB_RXCSRLN_REQPKT_Pos)

#define LM3S_USB_RXCSRLN_FLUSH_Pos                4
#define LM3S_USB_RXCSRLN_FLUSH_Msk               (1UL << LM3S_USB_RXCSRLN_FLUSH_Pos)

#define LM3S_USB_RXCSRLN_DATAERRNAKTO_Pos         3
#define LM3S_USB_RXCSRLN_DATAERRNAKTO_Msk        (1UL << LM3S_USB_RXCSRLN_DATAERRNAKTO_Pos)

#define LM3S_USB_RXCSRLN_ERROR_Pos                2
#define LM3S_USB_RXCSRLN_ERROR_Msk               (1UL << LM3S_USB_RXCSRLN_ERROR_Pos)

#define LM3S_USB_RXCSRLN_FULL_Pos                 1
#define LM3S_USB_RXCSRLN_FULL_Msk                (1UL << LM3S_USB_RXCSRLN_FULL_Pos)

#define LM3S_USB_RXCSRLN_RXRDY_Pos                0
#define LM3S_USB_RXCSRLN_RXRDY_Msk               (1UL /*<< LM3S_USB_RXCSRLN_RXRDY_Pos*/)

/* LM3S USB Device RXCSRLN Register Definitions */
#define LM3S_USB_RXCSRLN_CLRDT_Pos                7
#define LM3S_USB_RXCSRLN_CLRDT_Msk               (1UL << LM3S_USB_RXCSRLN_CLRDT_Pos)

#define LM3S_USB_RXCSRLN_STALLED_Pos              6
#define LM3S_USB_RXCSRLN_STALLED_Msk             (1UL << LM3S_USB_RXCSRLN_STALLED_Pos)

#define LM3S_USB_RXCSRLN_STALL_Pos                5
#define LM3S_USB_RXCSRLN_STALL_Msk               (1UL << LM3S_USB_RXCSRLN_STALL_Pos)

#define LM3S_USB_RXCSRLN_FLUSH_Pos                4
#define LM3S_USB_RXCSRLN_FLUSH_Msk               (1UL << LM3S_USB_RXCSRLN_FLUSH_Pos)

#define LM3S_USB_RXCSRLN_DATAERR_Pos              3
#define LM3S_USB_RXCSRLN_DATAERR_Msk             (1UL << LM3S_USB_RXCSRLN_DATAERR_Pos)

#define LM3S_USB_RXCSRLN_OVER_Pos                 2
#define LM3S_USB_RXCSRLN_OVER_Msk                (1UL << LM3S_USB_RXCSRLN_OVER_Pos)

#define LM3S_USB_RXCSRLN_FULL_Pos                 1
#define LM3S_USB_RXCSRLN_FULL_Msk                (1UL << LM3S_USB_RXCSRLN_FULL_Pos)

#define LM3S_USB_RXCSRLN_RXRDY_Pos                0
#define LM3S_USB_RXCSRLN_RXRDY_Msk               (1UL /*<< LM3S_USB_RXCSRLN_RXRDY_Pos*/)

/* LM3S USB Host RXCSRHN Register Definitions */
#define LM3S_USB_RXCSRHN_AUTOCL_Pos               7
#define LM3S_USB_RXCSRHN_AUTOCL_Msk              (1UL << LM3S_USB_RXCSRHN_AUTOCL_Pos)

#define LM3S_USB_RXCSRHN_AUTORQ_Pos               6
#define LM3S_USB_RXCSRHN_AUTORQ_Msk              (1UL << LM3S_USB_RXCSRHN_AUTORQ_Pos)

#define LM3S_USB_RXCSRHN_DMAEN_Pos                5
#define LM3S_USB_RXCSRHN_DMAEN_Msk               (1UL << LM3S_USB_RXCSRHN_DMAEN_Pos)

#define LM3S_USB_RXCSRHN_PIDERR_Pos               4
#define LM3S_USB_RXCSRHN_PIDERR_Msk              (1UL << LM3S_USB_RXCSRHN_PIDERR_Pos)

#define LM3S_USB_RXCSRHN_DMAMOD_Pos               3
#define LM3S_USB_RXCSRHN_DMAMOD_Msk              (1UL << LM3S_USB_RXCSRHN_DMAMOD_Pos)

#define LM3S_USB_RXCSRHN_DTWE_Pos                 2
#define LM3S_USB_RXCSRHN_DTWE_Msk                (1UL << LM3S_USB_RXCSRHN_DTWE_Pos)

#define LM3S_USB_RXCSRHN_DT_Pos                   1
#define LM3S_USB_RXCSRHN_DT_Msk                  (1UL << LM3S_USB_RXCSRHN_DT_Pos)

/* LM3S USB Device RXCSRHN Register Definitions */
#define LM3S_USB_RXCSRHN_AUTOCL_Pos               7
#define LM3S_USB_RXCSRHN_AUTOCL_Msk              (1UL << LM3S_USB_RXCSRHN_AUTOCL_Pos)

#define LM3S_USB_RXCSRHN_ISO_Pos                  6
#define LM3S_USB_RXCSRHN_ISO_Msk                 (1UL << LM3S_USB_RXCSRHN_ISO_Pos)

#define LM3S_USB_RXCSRHN_DMAEN_Pos                5
#define LM3S_USB_RXCSRHN_DMAEN_Msk               (1UL << LM3S_USB_RXCSRHN_DMAEN_Pos)

#define LM3S_USB_RXCSRHN_DISNYETPIDERR_Pos        4
#define LM3S_USB_RXCSRHN_DISNYETPIDERR_Msk       (1UL << LM3S_USB_RXCSRHN_DISNYETPIDERR_Pos)

#define LM3S_USB_RXCSRHN_DMAMOD_Pos               3
#define LM3S_USB_RXCSRHN_DMAMOD_Msk              (1UL << LM3S_USB_RXCSRHN_DMAMOD_Pos)

/* LM3S USB RXCOUNTN Register Definitions */
#define LM3S_USB_RXCOUNTN_COUNT_Pos               0
#define LM3S_USB_RXCOUNTN_COUNT_Msk              (0x1FFFUL /*<< LM3S_USB_RXCOUNTN_COUNT_Pos*/)

/* LM3S USB Host TXTYPEN Register Definitions */
#define LM3S_USB_TXTYPEN_SPEED_Pos                6
#define LM3S_USB_TXTYPEN_SPEED_Msk               (0x03UL << LM3S_USB_TXTYPEN_SPEED_Pos)
#define LM3S_USB_TXTYPEN_SPEED_1_Pos              7
#define LM3S_USB_TXTYPEN_SPEED_1_Msk             (1UL << LM3S_USB_TXTYPEN_SPEED_1_Pos)
#define LM3S_USB_TXTYPEN_SPEED_0_Pos              6
#define LM3S_USB_TXTYPEN_SPEED_0_Msk             (1UL << LM3S_USB_TXTYPEN_SPEED_0_Pos)

#define LM3S_USB_TXTYPEN_PROTO_Pos                4
#define LM3S_USB_TXTYPEN_PROTO_Msk               (0x03UL << LM3S_USB_TXTYPEN_PROTO_Pos)
#define LM3S_USB_TXTYPEN_PROTO_1_Pos              5
#define LM3S_USB_TXTYPEN_PROTO_1_Msk             (1UL << LM3S_USB_TXTYPEN_PROTO_1_Pos)
#define LM3S_USB_TXTYPEN_PROTO_0_Pos              4
#define LM3S_USB_TXTYPEN_PROTO_0_Msk             (1UL << LM3S_USB_TXTYPEN_PROTO_0_Pos)

#define LM3S_USB_TXTYPEN_TEP_Pos                  0
#define LM3S_USB_TXTYPEN_TEP_Msk                 (0x0FUL /*<< LM3S_USB_TXTYPEN_TEP_Pos*/)

/* LM3S USB Host TXINTERVALN Register Definitions */
#define LM3S_USB_TXINTERVALN_TXPOLLNAKLMT_Pos     0
#define LM3S_USB_TXINTERVALN_TXPOLLNAKLMT_Msk    (0xFFUL /*<< LM3S_USB_TXINTERVALN_TXPOLLNAKLMT_Pos*/)

/* LM3S USB Host RXTYPEN Register Definitions */
#define LM3S_USB_RXTYPEN_SPEED_Pos                6
#define LM3S_USB_RXTYPEN_SPEED_Msk               (0x03UL << LM3S_USB_RXTYPEN_SPEED_Pos)
#define LM3S_USB_RXTYPEN_SPEED_1_Pos              7
#define LM3S_USB_RXTYPEN_SPEED_1_Msk             (1UL << LM3S_USB_RXTYPEN_SPEED_1_Pos)
#define LM3S_USB_RXTYPEN_SPEED_0_Pos              6
#define LM3S_USB_RXTYPEN_SPEED_0_Msk             (1UL << LM3S_USB_RXTYPEN_SPEED_0_Pos)

#define LM3S_USB_RXTYPEN_PROTO_Pos                4
#define LM3S_USB_RXTYPEN_PROTO_Msk               (0x03UL << LM3S_USB_RXTYPEN_PROTO_Pos)
#define LM3S_USB_RXTYPEN_PROTO_1_Pos              5
#define LM3S_USB_RXTYPEN_PROTO_1_Msk             (1UL << LM3S_USB_RXTYPEN_PROTO_1_Pos)
#define LM3S_USB_RXTYPEN_PROTO_0_Pos              4
#define LM3S_USB_RXTYPEN_PROTO_0_Msk             (1UL << LM3S_USB_RXTYPEN_PROTO_0_Pos)

#define LM3S_USB_RXTYPEN_TEP_Pos                  0
#define LM3S_USB_RXTYPEN_TEP_Msk                 (0x0FUL /*<< LM3S_USB_RXTYPEN_TEP_Pos*/)

/* LM3S USB Host RXINTERVALN Register Definitions */
#define LM3S_USB_RXINTERVALN_RXPOLLNAKLMT_Pos     0
#define LM3S_USB_RXINTERVALN_RXPOLLNAKLMT_Msk    (0xFFUL /*<< LM3S_USB_RXINTERVALN_RXPOLLNAKLMT_Pos*/)

/* LM3S USB Host RQPKTCOUNTN Register Definitions */
#define LM3S_USB_RQPKTCOUNTN_COUNT_Pos            0
#define LM3S_USB_RQPKTCOUNTN_COUNT_Msk           (0xFFFFUL /*<< LM3S_USB_RQPKTCOUNTN_COUNT_Pos*/)

/* LM3S USB RXDPKTBUFDIS Register Definitions */
#define LM3S_USB_RXDPKTBUFDIS_EP15_Pos           15
#define LM3S_USB_RXDPKTBUFDIS_EP15_Msk           (1UL << LM3S_USB_RXDPKTBUFDIS_EP15_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP14_Pos           14
#define LM3S_USB_RXDPKTBUFDIS_EP14_Msk           (1UL << LM3S_USB_RXDPKTBUFDIS_EP14_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP13_Pos           13
#define LM3S_USB_RXDPKTBUFDIS_EP13_Msk           (1UL << LM3S_USB_RXDPKTBUFDIS_EP13_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP12_Pos           12
#define LM3S_USB_RXDPKTBUFDIS_EP12_Msk           (1UL << LM3S_USB_RXDPKTBUFDIS_EP12_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP11_Pos           11
#define LM3S_USB_RXDPKTBUFDIS_EP11_Msk           (1UL << LM3S_USB_RXDPKTBUFDIS_EP11_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP10_Pos           10
#define LM3S_USB_RXDPKTBUFDIS_EP10_Msk           (1UL << LM3S_USB_RXDPKTBUFDIS_EP10_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP9_Pos             9
#define LM3S_USB_RXDPKTBUFDIS_EP9_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP9_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP8_Pos             8
#define LM3S_USB_RXDPKTBUFDIS_EP8_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP8_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP7_Pos             7
#define LM3S_USB_RXDPKTBUFDIS_EP7_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP7_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP6_Pos             6
#define LM3S_USB_RXDPKTBUFDIS_EP6_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP6_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP5_Pos             5
#define LM3S_USB_RXDPKTBUFDIS_EP5_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP5_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP4_Pos             4
#define LM3S_USB_RXDPKTBUFDIS_EP4_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP4_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP3_Pos             3
#define LM3S_USB_RXDPKTBUFDIS_EP3_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP3_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP2_Pos             2
#define LM3S_USB_RXDPKTBUFDIS_EP2_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP2_Pos)

#define LM3S_USB_RXDPKTBUFDIS_EP1_Pos             1
#define LM3S_USB_RXDPKTBUFDIS_EP1_Msk            (1UL << LM3S_USB_RXDPKTBUFDIS_EP1_Pos)

/* LM3S USB TXDPKTBUFDIS Register Definitions */
#define LM3S_USB_TXDPKTBUFDIS_EP15_Pos           15
#define LM3S_USB_TXDPKTBUFDIS_EP15_Msk           (1UL << LM3S_USB_TXDPKTBUFDIS_EP15_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP14_Pos           14
#define LM3S_USB_TXDPKTBUFDIS_EP14_Msk           (1UL << LM3S_USB_TXDPKTBUFDIS_EP14_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP13_Pos           13
#define LM3S_USB_TXDPKTBUFDIS_EP13_Msk           (1UL << LM3S_USB_TXDPKTBUFDIS_EP13_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP12_Pos           12
#define LM3S_USB_TXDPKTBUFDIS_EP12_Msk           (1UL << LM3S_USB_TXDPKTBUFDIS_EP12_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP11_Pos           11
#define LM3S_USB_TXDPKTBUFDIS_EP11_Msk           (1UL << LM3S_USB_TXDPKTBUFDIS_EP11_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP10_Pos           10
#define LM3S_USB_TXDPKTBUFDIS_EP10_Msk           (1UL << LM3S_USB_TXDPKTBUFDIS_EP10_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP9_Pos             9
#define LM3S_USB_TXDPKTBUFDIS_EP9_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP9_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP8_Pos             8
#define LM3S_USB_TXDPKTBUFDIS_EP8_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP8_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP7_Pos             7
#define LM3S_USB_TXDPKTBUFDIS_EP7_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP7_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP6_Pos             6
#define LM3S_USB_TXDPKTBUFDIS_EP6_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP6_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP5_Pos             5
#define LM3S_USB_TXDPKTBUFDIS_EP5_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP5_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP4_Pos             4
#define LM3S_USB_TXDPKTBUFDIS_EP4_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP4_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP3_Pos             3
#define LM3S_USB_TXDPKTBUFDIS_EP3_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP3_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP2_Pos             2
#define LM3S_USB_TXDPKTBUFDIS_EP2_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP2_Pos)

#define LM3S_USB_TXDPKTBUFDIS_EP1_Pos             1
#define LM3S_USB_TXDPKTBUFDIS_EP1_Msk            (1UL << LM3S_USB_TXDPKTBUFDIS_EP1_Pos)

/* LM3S USB EPC Register Definitions */
#define LM3S_USB_EPC_PFLTACT_Pos                  8
#define LM3S_USB_EPC_PFLTACT_Msk                 (0x00000003UL << LM3S_USB_EPC_PFLTACT_Pos)
#define LM3S_USB_EPC_PFLTACT_1_Pos                9
#define LM3S_USB_EPC_PFLTACT_1_Msk               (1UL << LM3S_USB_EPC_PFLTACT_1_Pos)
#define LM3S_USB_EPC_PFLTACT_0_Pos                8
#define LM3S_USB_EPC_PFLTACT_0_Msk               (1UL << LM3S_USB_EPC_PFLTACT_0_Pos)

#define LM3S_USB_EPC_PFLTAEN_Pos                  6
#define LM3S_USB_EPC_PFLTAEN_Msk                 (1UL << LM3S_USB_EPC_PFLTAEN_Pos)

#define LM3S_USB_EPC_PFLTSEN_Pos                  5
#define LM3S_USB_EPC_PFLTSEN_Msk                 (1UL << LM3S_USB_EPC_PFLTSEN_Pos)

#define LM3S_USB_EPC_PFLTEN_Pos                   4
#define LM3S_USB_EPC_PFLTEN_Msk                  (1UL << LM3S_USB_EPC_PFLTEN_Pos)

#define LM3S_USB_EPC_EPENDE_Pos                   2
#define LM3S_USB_EPC_EPENDE_Msk                  (1UL << LM3S_USB_EPC_EPENDE_Pos)

#define LM3S_USB_EPC_EPEN_Pos                     0
#define LM3S_USB_EPC_EPEN_Msk                    (0x00000003UL /*<< LM3S_USB_EPC_EPEN_Pos*/)
#define LM3S_USB_EPC_EPEN_1_Pos                   1
#define LM3S_USB_EPC_EPEN_1_Msk                  (1UL << LM3S_USB_EPC_EPEN_1_Pos)
#define LM3S_USB_EPC_EPEN_0_Pos                   0
#define LM3S_USB_EPC_EPEN_0_Msk                  (1UL /*<< LM3S_USB_EPC_EPEN_0_Pos*/)

/* LM3S USB EPCRIS Register Definitions */
#define LM3S_USB_EPCRIS_PF_Pos                    0
#define LM3S_USB_EPCRIS_PF_Msk                   (1UL /*<< LM3S_USB_EPCRIS_PF_Pos*/)

/* LM3S USB EPCIM Register Definitions */
#define LM3S_USB_EPCIM_PF_Pos                     0
#define LM3S_USB_EPCIM_PF_Msk                    (1UL /*<< LM3S_USB_EPCIM_PF_Pos*/)

/* LM3S USB EPCISC Register Definitions */
#define LM3S_USB_EPCISC_PF_Pos                    0
#define LM3S_USB_EPCISC_PF_Msk                   (1UL /*<< LM3S_USB_EPCISC_PF_Pos*/)

/* LM3S USB DRRIS Register Definitions */
#define LM3S_USB_DRRIS_RESUME_Pos                 0
#define LM3S_USB_DRRIS_RESUME_Msk                (1UL /*<< LM3S_USB_DRRIS_RESUME_Pos*/)

/* LM3S USB DRIM Register Definitions */
#define LM3S_USB_DRIM_RESUME_Pos                  0
#define LM3S_USB_DRIM_RESUME_Msk                 (1UL /*<< LM3S_USB_DRIM_RESUME_Pos*/)

/* LM3S USB DRISC Register Definitions */
#define LM3S_USB_DRISC_RESUME_Pos                 0
#define LM3S_USB_DRISC_RESUME_Msk                (1UL /*<< LM3S_USB_DRISC_RESUME_Pos*/)

/* LM3S USB GPCS Register Definitions */
#define LM3S_USB_GPCS_DEVMODOTG_Pos               1
#define LM3S_USB_GPCS_DEVMODOTG_Msk              (1UL << LM3S_USB_GPCS_DEVMODOTG_Pos)

#define LM3S_USB_GPCS_DEVMOD_Pos                  0
#define LM3S_USB_GPCS_DEVMOD_Msk                 (1UL /*<< LM3S_USB_GPCS_DEVMOD_Pos*/)

/* LM3S USB VDC Register Definitions */
#define LM3S_USB_VDC_VBDEN_Pos                    0
#define LM3S_USB_VDC_VBDEN_Msk                   (1UL /*<< LM3S_USB_VDC_VBDEN_Pos*/)

/* LM3S USB VDCRIS Register Definitions */
#define LM3S_USB_VDCRIS_VD_Pos                    0
#define LM3S_USB_VDCRIS_VD_Msk                   (1UL /*<< LM3S_USB_VDCRIS_VD_Pos*/)

/* LM3S USB VDCIM Register Definitions */
#define LM3S_USB_VDCIM_VD_Pos                     0
#define LM3S_USB_VDCIM_VD_Msk                    (1UL /*<< LM3S_USB_VDCIM_VD_Pos*/)

/* LM3S USB VDCISC Register Definitions */
#define LM3S_USB_VDCISC_VD_Pos                    0
#define LM3S_USB_VDCISC_VD_Msk                   (1UL /*<< LM3S_USB_VDCISC_VD_Pos*/)

/* LM3S USB IDVRIS Register Definitions */
#define LM3S_USB_IDVRIS_ID_Pos                    0
#define LM3S_USB_IDVRIS_ID_Msk                   (1UL /*<< LM3S_USB_IDVRIS_ID_Pos*/)

/* LM3S USB IDVIM Register Definitions */
#define LM3S_USB_IDVIM_ID_Pos                     0
#define LM3S_USB_IDVIM_ID_Msk                    (1UL /*<< LM3S_USB_IDVIM_ID_Pos*/)

/* LM3S USB IDVVIM Register Definitions */
#define LM3S_USB_IDVISC_ID_Pos                    0
#define LM3S_USB_IDVISC_ID_Msk                   (1UL /*<< LM3S_USB_IDVISC_ID_Pos*/)

/* LM3S USB DMASEL Register Definitions */
#define LM3S_USB_DMASEL_DMACTX_Pos               20
#define LM3S_USB_DMASEL_DMACTX_Msk               (0x0000000FUL << LM3S_USB_DMASEL_DMACTX_Pos)

#define LM3S_USB_DMASEL_DMACRX_Pos               16
#define LM3S_USB_DMASEL_DMACRX_Msk               (0x0000000FUL << LM3S_USB_DMASEL_DMACRX_Pos)

#define LM3S_USB_DMASEL_DMABTX_Pos               12
#define LM3S_USB_DMASEL_DMABTX_Msk               (0x0000000FUL << LM3S_USB_DMASEL_DMABTX_Pos)

#define LM3S_USB_DMASEL_DMABRX_Pos                8
#define LM3S_USB_DMASEL_DMABRX_Msk               (0x0000000FUL << LM3S_USB_DMASEL_DMABRX_Pos)

#define LM3S_USB_DMASEL_DMAATX_Pos                4
#define LM3S_USB_DMASEL_DMAATX_Msk               (0x0000000FUL << LM3S_USB_DMASEL_DMAATX_Pos)

#define LM3S_USB_DMASEL_DMAARX_Pos                0
#define LM3S_USB_DMASEL_DMAARX_Msk               (0x0000000FUL /*<< LM3S_USB_DMASEL_DMAARX_Pos*/)

/* ================================================================================ */
/* ================                       I2S                      ================ */
/* ================================================================================ */

typedef struct {
  __OM  uint32_t  TXFIFO;               /* Offset: 0x000 ( /W) Transmit FIFO Data Register */
  __IOM uint32_t  TXFIFOCFG;            /* Offset: 0x004 (R/W) Transmit FIFO Configuration Register */
  __IOM uint32_t  TXCFG;                /* Offset: 0x008 (R/W) Transmit Module Configuration Register */
  __IOM uint32_t  TXLIMIT;              /* Offset: 0x00C (R/W) Transmit FIFO Limit Register */
  __IOM uint32_t  TXISM;                /* Offset: 0x010 (R/W) Transmit Interrupt Status and Mask Register */
  __IM  uint32_t  TXLEV;                /* Offset: 0x018 (R/ ) Transmit FIFO Level Register */
  __IM  uint32_t  RESERVED0[505];
  __IM  uint32_t  RXFIFO;               /* Offset: 0x800 (R/ ) Receive FIFO Data Register */
  __IOM uint32_t  RXFIFOCFG;            /* Offset: 0x804 (R/W) Receive FIFO Configuration Register */
  __IOM uint32_t  RXCFG;                /* Offset: 0x808 (R/W) Receive Module Configuration Register */
  __IOM uint32_t  RXLIMIT;              /* Offset: 0x80C (R/W) Receive FIFO Limit Register */
  __IOM uint32_t  RXISM;                /* Offset: 0x810 (R/W) Receive Interrupt Status and Mask Register */
  __IM  uint32_t  RXLEV;                /* Offset: 0x818 (R/ ) Receive FIFO Level Register */
  __IM  uint32_t  RESERVED1[249];
  __IOM uint32_t  CFG;                  /* Offset: 0xC00 (R/W) Module Configuration Register */
  __IM  uint32_t  RESERVED2[3];
  __IOM uint32_t  IM;                   /* Offset: 0xC10 (R/W) Interrupt Mask Register */
  __IM  uint32_t  RIS;                  /* Offset: 0xC14 (R/ ) Raw Interrupt Status Register */
  __IM  uint32_t  MIS;                  /* Offset: 0xC18 (R/ ) Masked Interrupt Status Register */
  __OM  uint32_t  IC;                   /* Offset: 0xC1C ( /W) Interrupt Clear Register */
} LM3S_I2S_TypeDef;

/* LM3S_I2S TXFIFO Register Definitions */
#define LM3S_I2S_TXFIFO_TXFIFO_Pos                0
#define LM3S_I2S_TXFIFO_TXFIFO_Msk               (0xFFFFFFFFUL /*<< LM3S_I2S_TXFIFO_TXFIFO_Pos*/)

/* LM3S_I2S TXFIFOCFG Register Definitions */
#define LM3S_I2S_TXFIFOCFG_CSS_Pos                1
#define LM3S_I2S_TXFIFOCFG_CSS_Msk               (1UL << LM3S_I2S_TXFIFOCFG_CSS_Pos)

#define LM3S_I2S_TXFIFOCFG_LRS_Pos                0
#define LM3S_I2S_TXFIFOCFG_LRS_Msk               (1UL /*<< LM3S_I2S_TXFIFOCFG_LRS_Pos*/)

/* LM3S_I2S TXCFG Register Definitions */
#define LM3S_I2S_TXCFG_JST_Pos                   29
#define LM3S_I2S_TXCFG_JST_Msk                   (1UL << LM3S_I2S_TXCFG_JST_Pos)

#define LM3S_I2S_TXCFG_DLY_Pos                   28
#define LM3S_I2S_TXCFG_DLY_Msk                   (1UL << LM3S_I2S_TXCFG_DLY_Pos)

#define LM3S_I2S_TXCFG_SCP_Pos                   27
#define LM3S_I2S_TXCFG_SCP_Msk                   (1UL << LM3S_I2S_TXCFG_SCP_Pos)

#define LM3S_I2S_TXCFG_LRP_Pos                   26
#define LM3S_I2S_TXCFG_LRP_Msk                   (1UL << LM3S_I2S_TXCFG_LRP_Pos)

#define LM3S_I2S_TXCFG_WM_Pos                    24
#define LM3S_I2S_TXCFG_WM_Msk                    (0x00000003UL << LM3S_I2S_TXCFG_WM_Pos)
#define LM3S_I2S_TXCFG_WM_1_Pos                  25
#define LM3S_I2S_TXCFG_WM_1_Msk                  (1UL << LM3S_I2S_TXCFG_WM_1_Pos)
#define LM3S_I2S_TXCFG_WM_0_Pos                  24
#define LM3S_I2S_TXCFG_WM_0_Msk                  (1UL << LM3S_I2S_TXCFG_WM_0_Pos)

#define LM3S_I2S_TXCFG_FMT_Pos                   23
#define LM3S_I2S_TXCFG_FMT_Msk                   (1UL << LM3S_I2S_TXCFG_FMT_Pos)

#define LM3S_I2S_TXCFG_MSL_Pos                   22
#define LM3S_I2S_TXCFG_MSL_Msk                   (1UL << LM3S_I2S_TXCFG_MSL_Pos)

#define LM3S_I2S_TXCFG_SSZ_Pos                   10
#define LM3S_I2S_TXCFG_SSZ_Msk                   (0x0000003FUL << LM3S_I2S_TXCFG_SSZ_Pos)

#define LM3S_I2S_TXCFG_SDSZ_Pos                   4
#define LM3S_I2S_TXCFG_SDSZ_Msk                  (0x0000003FUL /*<< LM3S_I2S_TXCFG_SDSZ_Pos*/)

/* LM3S_I2S TXLIMIT Register Definitions */
#define LM3S_I2S_TXLIMIT_LIMIT_Pos                0
#define LM3S_I2S_TXLIMIT_LIMIT_Msk               (0x0000001FUL /*<< LM3S_I2S_TXLIMIT_LIMIT_Pos*/)

/* LM3S_I2S TXISM Register Definitions */
#define LM3S_I2S_TXISM_FFI_Pos                   16
#define LM3S_I2S_TXISM_FFI_Msk                   (1UL << LM3S_I2S_TXISM_FFI_Pos)

#define LM3S_I2S_TXISM_FFM_Pos                    0
#define LM3S_I2S_TXISM_FFM_Msk                   (1UL /*<< LM3S_I2S_TXISM_FFM_Pos*/)

/* LM3S_I2S TXLEV Register Definitions */
#define LM3S_I2S_TXLEV_LEVEL_Pos                  0
#define LM3S_I2S_TXLEV_LEVEL_Msk                 (0x0000001FUL /*<< LM3S_I2S_TXLEV_LEVEL_Pos*/)

/* LM3S_I2S RXFIFO Register Definitions */
#define LM3S_I2S_RXFIFO_RXFIFO_Pos                0
#define LM3S_I2S_RXFIFO_RXFIFO_Msk               (0xFFFFFFFFUL /*<< LM3S_I2S_RXFIFO_RXFIFO_Pos*/)

/* LM3S_I2S RXFIFOCFG Register Definitions */
#define LM3S_I2S_RXFIFOCFG_FMM_Pos                2
#define LM3S_I2S_RXFIFOCFG_FMM_Msk               (1UL << LM3S_I2S_RXFIFOCFG_FMM_Pos)

#define LM3S_I2S_RXFIFOCFG_CSS_Pos                1
#define LM3S_I2S_RXFIFOCFG_CSS_Msk               (1UL << LM3S_I2S_RXFIFOCFG_CSS_Pos)

#define LM3S_I2S_RXFIFOCFG_LRS_Pos                0
#define LM3S_I2S_RXFIFOCFG_LRS_Msk               (1UL /*<< LM3S_I2S_RXFIFOCFG_LRS_Pos*/)

/* LM3S_I2S RXCFG Register Definitions */
#define LM3S_I2S_RXCFG_JST_Pos                   29
#define LM3S_I2S_RXCFG_JST_Msk                   (1UL << LM3S_I2S_RXCFG_JST_Pos)

#define LM3S_I2S_RXCFG_DLY_Pos                   28
#define LM3S_I2S_RXCFG_DLY_Msk                   (1UL << LM3S_I2S_RXCFG_DLY_Pos)

#define LM3S_I2S_RXCFG_SCP_Pos                   27
#define LM3S_I2S_RXCFG_SCP_Msk                   (1UL << LM3S_I2S_RXCFG_SCP_Pos)

#define LM3S_I2S_RXCFG_LRP_Pos                   26
#define LM3S_I2S_RXCFG_LRP_Msk                   (1UL << LM3S_I2S_RXCFG_LRP_Pos)

#define LM3S_I2S_RXCFG_RM_Pos                    24
#define LM3S_I2S_RXCFG_RM_Msk                    (1UL << LM3S_I2S_RXCFG_RM_Pos)

#define LM3S_I2S_RXCFG_MSL_Pos                   22
#define LM3S_I2S_RXCFG_MSL_Msk                   (1UL << LM3S_I2S_RXCFG_MSL_Pos)

#define LM3S_I2S_RXCFG_SSZ_Pos                   10
#define LM3S_I2S_RXCFG_SSZ_Msk                   (0x0000003FUL << LM3S_I2S_RXCFG_SSZ_Pos)

#define LM3S_I2S_RXCFG_SDSZ_Pos                   4
#define LM3S_I2S_RXCFG_SDSZ_Msk                  (0x0000003FUL /*<< LM3S_I2S_RXCFG_SDSZ_Pos*/)

/* LM3S_I2S RXLIMIT Register Definitions */
#define LM3S_I2S_RXLIMIT_LIMIT_Pos                0
#define LM3S_I2S_RXLIMIT_LIMIT_Msk               (0x0000001FUL /*<< LM3S_I2S_RXLIMIT_LIMIT_Pos*/)

/* LM3S_I2S RXISM Register Definitions */
#define LM3S_I2S_RXISM_FFI_Pos                   16
#define LM3S_I2S_RXISM_FFI_Msk                   (1UL << LM3S_I2S_RXISM_FFI_Pos)

#define LM3S_I2S_RXISM_FFM_Pos                    0
#define LM3S_I2S_RXISM_FFM_Msk                   (1UL /*<< LM3S_I2S_RXISM_FFM_Pos*/)

/* LM3S_I2S RXLEV Register Definitions */
#define LM3S_I2S_RXLEV_LEVEL_Pos                  0
#define LM3S_I2S_RXLEV_LEVEL_Msk                 (0x0000001FUL /*<< LM3S_I2S_RXLEV_LEVEL_Pos*/)

/* LM3S_I2S CFG Register Definitions */
#define LM3S_I2S_CFG_RXSLV_Pos                    5
#define LM3S_I2S_CFG_RXSLV_Msk                   (1UL << LM3S_I2S_CFG_RXSLV_Pos)

#define LM3S_I2S_CFG_TXSLV_Pos                    4
#define LM3S_I2S_CFG_TXSLV_Msk                   (1UL << LM3S_I2S_CFG_TXSLV_Pos)

#define LM3S_I2S_CFG_RXEN_Pos                     1
#define LM3S_I2S_CFG_RXEN_Msk                    (1UL << LM3S_I2S_CFG_RXEN_Pos)

#define LM3S_I2S_CFG_TXEN_Pos                     0
#define LM3S_I2S_CFG_TXEN_Msk                    (1UL /*<< LM3S_I2S_CFG_TXEN_Pos*/)

/* LM3S_I2S IM Register Definitions */
#define LM3S_I2S_IM_RXREIM_Pos                    5
#define LM3S_I2S_IM_RXREIM_Msk                   (1UL << LM3S_I2S_IM_RXREIM_Pos)

#define LM3S_I2S_IM_RXSRIM_Pos                    4
#define LM3S_I2S_IM_RXSRIM_Msk                   (1UL << LM3S_I2S_IM_RXSRIM_Pos)

#define LM3S_I2S_IM_TXWEIM_Pos                    1
#define LM3S_I2S_IM_TXWEIM_Msk                   (1UL << LM3S_I2S_IM_TXWEIM_Pos)

#define LM3S_I2S_IM_TXSRIM_Pos                    0
#define LM3S_I2S_IM_TXSRIM_Msk                   (1UL /*<< LM3S_I2S_IM_TXSRIM_Pos*/)

/* LM3S_I2S RIS Register Definitions */
#define LM3S_I2S_RIS_RXRERIS_Pos                  5
#define LM3S_I2S_RIS_RXRERIS_Msk                 (1UL << LM3S_I2S_RIS_RXRERIS_Pos)

#define LM3S_I2S_RIS_RXSRRIS_Pos                  4
#define LM3S_I2S_RIS_RXSRRIS_Msk                 (1UL << LM3S_I2S_RIS_RXSRRIS_Pos)

#define LM3S_I2S_RIS_TXWERIS_Pos                  1
#define LM3S_I2S_RIS_TXWERIS_Msk                 (1UL << LM3S_I2S_RIS_TXWERIS_Pos)

#define LM3S_I2S_RIS_TXSRRIS_Pos                  0
#define LM3S_I2S_RIS_TXSRRIS_Msk                 (1UL /*<< LM3S_I2S_RIS_TXSRRIS_Pos*/)

/* LM3S_I2S MIS Register Definitions */
#define LM3S_I2S_MIS_RXREMIS_Pos                  5
#define LM3S_I2S_MIS_RXREMIS_Msk                 (1UL << LM3S_I2S_MIS_RXREMIS_Pos)

#define LM3S_I2S_MIS_RXSRMIS_Pos                  4
#define LM3S_I2S_MIS_RXSRMIS_Msk                 (1UL << LM3S_I2S_MIS_RXSRMIS_Pos)

#define LM3S_I2S_MIS_TXWEMIS_Pos                  1
#define LM3S_I2S_MIS_TXWEMIS_Msk                 (1UL << LM3S_I2S_MIS_TXWEMIS_Pos)

#define LM3S_I2S_MIS_TXSRMIS_Pos                  0
#define LM3S_I2S_MIS_TXSRMIS_Msk                 (1UL /*<< LM3S_I2S_MIS_TXSRMIS_Pos*/)

/* LM3S_I2S IC Register Definitions */
#define LM3S_I2S_IC_RXREIC_Pos                    5
#define LM3S_I2S_IC_RXREIC_Msk                   (1UL << LM3S_I2S_IC_RXREIC_Pos)

#define LM3S_I2S_IC_TXWEIC_Pos                    1
#define LM3S_I2S_IC_TXWEIC_Msk                   (1UL << LM3S_I2S_IC_TXWEIC_Pos)

/* ================================================================================ */
/* ================                       EPI                      ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  CFG;                  /* Offset: 0x000 (R/W) Configuration Register */
  __IOM uint32_t  BAUD;                 /* Offset: 0x004 (R/W) Main Baud Rate Register */
  __IM  uint32_t  RESERVED0[2];
  union {
    __IOM uint32_t  SDRAMCFG;           /* Offset: 0x010 (R/W) SDRAM Configuration Register */
    __IOM uint32_t  HB8CFG;             /* Offset: 0x010 (R/W) Host-Bus 8 Configuration Register */
    __IOM uint32_t  HB16CFG;            /* Offset: 0x010 (R/W) Host-Bus 16 Configuration Register */
    __IOM uint32_t  GPCFG;              /* Offset: 0x010 (R/W) General-Purpose Configuration Register */
  };
  union {
    __IOM uint32_t  HB8CFG2;            /* Offset: 0x014 (R/W) Host-Bus 8 Configuration Register 2 */
    __IOM uint32_t  HB16CFG2;           /* Offset: 0x014 (R/W) Host-Bus 16 Configuration Register 2 */
    __IOM uint32_t  GPCFG2;             /* Offset: 0x014 (R/W) General-Purpose Configuration Register 2 */
  };
  __IM  uint32_t  RESERVED1;
  __IOM uint32_t  ADDRMAP;              /* Offset: 0x01C (R/W) Address Map Register */
  __IOM uint32_t  RSIZE0;               /* Offset: 0x020 (R/W) Read Size Register 0 */
  __IOM uint32_t  RADDR0;               /* Offset: 0x024 (R/W) Read Address Register 0 */
  __IOM uint32_t  RPSTD0;               /* Offset: 0x028 (R/W) Non-Blocking Read Data Register 0 */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  RSIZE1;               /* Offset: 0x030 (R/W) Read Size Register 1 */
  __IOM uint32_t  RADDR1;               /* Offset: 0x034 (R/W) Read Address Register 1 */
  __IOM uint32_t  RPSTD1;               /* Offset: 0x038 (R/W) Non-Blocking Read Data Register 1 */
  __IM  uint32_t  RESERVED3[9];
  __IM  uint32_t  STAT;                 /* Offset: 0x060 (R/ ) Status Register */
  __IM  uint32_t  RESERVED4[2];
  __IM  uint32_t  RFIFOCNT;             /* Offset: 0x06C (R/ ) Read FIFO Count Register */
  __IM  uint32_t  READFIFO;             /* Offset: 0x070 (R/ ) Read FIFO Register */
  __IM  uint32_t  READFIFO1;            /* Offset: 0x074 (R/ ) Read FIFO Alias 1 Register */
  __IM  uint32_t  READFIFO2;            /* Offset: 0x078 (R/ ) Read FIFO Alias 2 Register */
  __IM  uint32_t  READFIFO3;            /* Offset: 0x07C (R/ ) Read FIFO Alias 3 Register */
  __IM  uint32_t  READFIFO4;            /* Offset: 0x080 (R/ ) Read FIFO Alias 4 Register */
  __IM  uint32_t  READFIFO5;            /* Offset: 0x084 (R/ ) Read FIFO Alias 5 Register */
  __IM  uint32_t  READFIFO6;            /* Offset: 0x088 (R/ ) Read FIFO Alias 6 Register */
  __IM  uint32_t  READFIFO7;            /* Offset: 0x08C (R/ ) Read FIFO Alias 7 Register */
  __IM  uint32_t  RESERVED5[92];
  __IOM uint32_t  FIFOLVL;              /* Offset: 0x200 (R/W) FIFO Level Selects Register */
  __IM  uint32_t  WFIFOCNT;             /* Offset: 0x204 (R/ ) Write FIFO Count Register */
  __IM  uint32_t  RESERVED6;
  __IOM uint32_t  IM;                   /* Offset: 0x210 (R/W) Interrupt Mask Register */
  __IOM uint32_t  RIS;                  /* Offset: 0x214 (R/ ) Raw Interrupt Status Register */
  __IOM uint32_t  MIS;                  /* Offset: 0x218 (R/ ) Masked Interrupt Status Register */
  __IOM uint32_t  EISC;                 /* Offset: 0x21C (R/W) Error Interrupt Status and Clear Register */
} LM3S_EPI_TypeDef;

/* LM3S_EPI CFG Register Definitions */
#define LM3S_EPI_CFG_BLKEN_Pos                    4
#define LM3S_EPI_CFG_BLKEN_Msk                   (1UL << LM3S_EPI_CFG_BLKEN_Pos)

#define LM3S_EPI_CFG_MODE_Pos                     0
#define LM3S_EPI_CFG_MODE_Msk                    (0x0000000FUL /*<< LM3S_EPI_CFG_MODE_Pos*/)
#define LM3S_EPI_CFG_MODE_3_Pos                   3
#define LM3S_EPI_CFG_MODE_3_Msk                  (1UL << LM3S_EPI_CFG_MODE_3_Pos)
#define LM3S_EPI_CFG_MODE_2_Pos                   2
#define LM3S_EPI_CFG_MODE_2_Msk                  (1UL << LM3S_EPI_CFG_MODE_2_Pos)
#define LM3S_EPI_CFG_MODE_1_Pos                   1
#define LM3S_EPI_CFG_MODE_1_Msk                  (1UL << LM3S_EPI_CFG_MODE_1_Pos)
#define LM3S_EPI_CFG_MODE_0_Pos                   0
#define LM3S_EPI_CFG_MODE_0_Msk                  (1UL /*<< LM3S_EPI_CFG_MODE_0_Pos*/)

/* LM3S_EPI BAUD Register Definitions */
#define LM3S_EPI_BAUD_COUNT1_Pos                 16
#define LM3S_EPI_BAUD_COUNT1_Msk                 (0x0000FFFFUL << LM3S_EPI_BAUD_COUNT1_Pos)

#define LM3S_EPI_BAUD_COUNT0_Pos                  0
#define LM3S_EPI_BAUD_COUNT0_Msk                 (0x0000FFFFUL /*<< LM3S_EPI_BAUD_COUNT0_Pos*/)

/* LM3S_EPI SDRAMCFG Register Definitions */
#define LM3S_EPI_SDRAMCFG_FREQ_Pos               30
#define LM3S_EPI_SDRAMCFG_FREQ_Msk               (0x00000003UL << LM3S_EPI_SDRAMCFG_FREQ_Pos)
#define LM3S_EPI_SDRAMCFG_FREQ_1_Pos             31
#define LM3S_EPI_SDRAMCFG_FREQ_1_Msk             (1UL << LM3S_EPI_SDRAMCFG_FREQ_1_Pos)
#define LM3S_EPI_SDRAMCFG_FREQ_0_Pos             30
#define LM3S_EPI_SDRAMCFG_FREQ_0_Msk             (1UL << LM3S_EPI_SDRAMCFG_FREQ_0_Pos)

#define LM3S_EPI_SDRAMCFG_RFSH_Pos               16
#define LM3S_EPI_SDRAMCFG_RFSH_Msk               (0x000007FFUL << LM3S_EPI_SDRAMCFG_RFSH_Pos)

#define LM3S_EPI_SDRAMCFG_SLEEP_Pos               9
#define LM3S_EPI_SDRAMCFG_SLEEP_Msk              (1UL << LM3S_EPI_SDRAMCFG_SLEEP_Pos)

#define LM3S_EPI_SDRAMCFG_SIZE_Pos                0
#define LM3S_EPI_SDRAMCFG_SIZE_Msk               (0x00000003UL /*<< LM3S_EPI_SDRAMCFG_SIZE_Pos*/)
#define LM3S_EPI_SDRAMCFG_SIZE_1_Pos              1
#define LM3S_EPI_SDRAMCFG_SIZE_1_Msk             (1UL << LM3S_EPI_SDRAMCFG_SIZE_1_Pos)
#define LM3S_EPI_SDRAMCFG_SIZE_0_Pos              0
#define LM3S_EPI_SDRAMCFG_SIZE_0_Msk             (1UL /*<< LM3S_EPI_SDRAMCFG_SIZE_0_Pos*/)

/* LM3S_EPI HB8CFG Register Definitions */
#define LM3S_EPI_HB8CFG_XFFEN_Pos                23
#define LM3S_EPI_HB8CFG_XFFEN_Msk                (1UL << LM3S_EPI_HB8CFG_XFFEN_Pos)

#define LM3S_EPI_HB8CFG_XFEEN_Pos                22
#define LM3S_EPI_HB8CFG_XFEEN_Msk                (1UL << LM3S_EPI_HB8CFG_XFEEN_Pos)

#define LM3S_EPI_HB8CFG_WRHIGH_Pos               21
#define LM3S_EPI_HB8CFG_WRHIGH_Msk               (1UL << LM3S_EPI_HB8CFG_WRHIGH_Pos)

#define LM3S_EPI_HB8CFG_RDHIGH_Pos               20
#define LM3S_EPI_HB8CFG_RDHIGH_Msk               (1UL << LM3S_EPI_HB8CFG_RDHIGH_Pos)

#define LM3S_EPI_HB8CFG_MAXWAIT_Pos               8
#define LM3S_EPI_HB8CFG_MAXWAIT_Msk              (0x000000FFUL << LM3S_EPI_HB8CFG_MAXWAIT_Pos)

#define LM3S_EPI_HB8CFG_WRWS_Pos                  6
#define LM3S_EPI_HB8CFG_WRWS_Msk                 (0x00000003UL << LM3S_EPI_HB8CFG_WRWS_Pos)
#define LM3S_EPI_HB8CFG_WRWS_1_Pos                7
#define LM3S_EPI_HB8CFG_WRWS_1_Msk               (1UL << LM3S_EPI_HB8CFG_WRWS_1_Pos)
#define LM3S_EPI_HB8CFG_WRWS_0_Pos                6
#define LM3S_EPI_HB8CFG_WRWS_0_Msk               (1UL << LM3S_EPI_HB8CFG_WRWS_0_Pos)

#define LM3S_EPI_HB8CFG_RDWS_Pos                  4
#define LM3S_EPI_HB8CFG_RDWS_Msk                 (0x00000003UL << LM3S_EPI_HB8CFG_RDWS_Pos)
#define LM3S_EPI_HB8CFG_RDWS_1_Pos                5
#define LM3S_EPI_HB8CFG_RDWS_1_Msk               (1UL << LM3S_EPI_HB8CFG_RDWS_1_Pos)
#define LM3S_EPI_HB8CFG_RDWS_0_Pos                4
#define LM3S_EPI_HB8CFG_RDWS_0_Msk               (1UL << LM3S_EPI_HB8CFG_RDWS_0_Pos)

#define LM3S_EPI_HB8CFG_MODE_Pos                  0
#define LM3S_EPI_HB8CFG_MODE_Msk                 (0x00000003UL /*<< LM3S_EPI_HB8CFG_MODE_Pos*/)
#define LM3S_EPI_HB8CFG_MODE_1_Pos                1
#define LM3S_EPI_HB8CFG_MODE_1_Msk               (1UL << LM3S_EPI_HB8CFG_MODE_1_Pos)
#define LM3S_EPI_HB8CFG_MODE_0_Pos                0
#define LM3S_EPI_HB8CFG_MODE_0_Msk               (1UL /*<< LM3S_EPI_HB8CFG_MODE_0_Pos*/)

/* LM3S_EPI HB16CFG Register Definitions */
#define LM3S_EPI_HB16CFG_XFFEN_Pos               23
#define LM3S_EPI_HB16CFG_XFFEN_Msk               (1UL << LM3S_EPI_HB16CFG_XFFEN_Pos)

#define LM3S_EPI_HB16CFG_XFEEN_Pos               22
#define LM3S_EPI_HB16CFG_XFEEN_Msk               (1UL << LM3S_EPI_HB16CFG_XFEEN_Pos)

#define LM3S_EPI_HB16CFG_WRHIGH_Pos              21
#define LM3S_EPI_HB16CFG_WRHIGH_Msk              (1UL << LM3S_EPI_HB16CFG_WRHIGH_Pos)

#define LM3S_EPI_HB16CFG_RDHIGH_Pos              20
#define LM3S_EPI_HB16CFG_RDHIGH_Msk              (1UL << LM3S_EPI_HB16CFG_RDHIGH_Pos)

#define LM3S_EPI_HB16CFG_MAXWAIT_Pos              8
#define LM3S_EPI_HB16CFG_MAXWAIT_Msk             (0x000000FFUL << LM3S_EPI_HB16CFG_MAXWAIT_Pos)

#define LM3S_EPI_HB16CFG_WRWS_Pos                 6
#define LM3S_EPI_HB16CFG_WRWS_Msk                (0x00000003UL << LM3S_EPI_HB16CFG_WRWS_Pos)
#define LM3S_EPI_HB16CFG_WRWS_1_Pos               7
#define LM3S_EPI_HB16CFG_WRWS_1_Msk              (1UL << LM3S_EPI_HB16CFG_WRWS_1_Pos)
#define LM3S_EPI_HB16CFG_WRWS_0_Pos               6
#define LM3S_EPI_HB16CFG_WRWS_0_Msk              (1UL << LM3S_EPI_HB16CFG_WRWS_0_Pos)

#define LM3S_EPI_HB16CFG_RDWS_Pos                 4
#define LM3S_EPI_HB16CFG_RDWS_Msk                (0x00000003UL << LM3S_EPI_HB16CFG_RDWS_Pos)
#define LM3S_EPI_HB16CFG_RDWS_1_Pos               5
#define LM3S_EPI_HB16CFG_RDWS_1_Msk              (1UL << LM3S_EPI_HB16CFG_RDWS_1_Pos)
#define LM3S_EPI_HB16CFG_RDWS_0_Pos               4
#define LM3S_EPI_HB16CFG_RDWS_0_Msk              (1UL << LM3S_EPI_HB16CFG_RDWS_0_Pos)

#define LM3S_EPI_HB16CFG_BSEL_Pos                 2
#define LM3S_EPI_HB16CFG_BSEL_Msk                (1UL << LM3S_EPI_HB16CFG_BSEL_Pos)

#define LM3S_EPI_HB16CFG_MODE_Pos                 0
#define LM3S_EPI_HB16CFG_MODE_Msk                (0x00000003UL /*<< LM3S_EPI_HB16CFG_MODE_Pos*/)
#define LM3S_EPI_HB16CFG_MODE_1_Pos               1
#define LM3S_EPI_HB16CFG_MODE_1_Msk              (1UL << LM3S_EPI_HB16CFG_MODE_1_Pos)
#define LM3S_EPI_HB16CFG_MODE_0_Pos               0
#define LM3S_EPI_HB16CFG_MODE_0_Msk              (1UL /*<< LM3S_EPI_HB16CFG_MODE_0_Pos*/)

/* LM3S_EPI GPCFG Register Definitions */
#define LM3S_EPI_GPCFG_CLKPIN_Pos                31
#define LM3S_EPI_GPCFG_CLKPIN_Msk                (1UL << LM3S_EPI_GPCFG_CLKPIN_Pos)

#define LM3S_EPI_GPCFG_CLKGATE_Pos               30
#define LM3S_EPI_GPCFG_CLKGATE_Msk               (1UL << LM3S_EPI_GPCFG_CLKGATE_Pos)

#define LM3S_EPI_GPCFG_RDYEN_Pos                 28
#define LM3S_EPI_GPCFG_RDYEN_Msk                 (1UL << LM3S_EPI_GPCFG_RDYEN_Pos)

#define LM3S_EPI_GPCFG_FRMPIN_Pos                27
#define LM3S_EPI_GPCFG_FRMPIN_Msk                (1UL << LM3S_EPI_GPCFG_FRMPIN_Pos)

#define LM3S_EPI_GPCFG_FRM50_Pos                 26
#define LM3S_EPI_GPCFG_FRM50_Msk                 (1UL << LM3S_EPI_GPCFG_FRM50_Pos)

#define LM3S_EPI_GPCFG_FRMCNT_Pos                22
#define LM3S_EPI_GPCFG_FRMCNT_Msk                (0x0000000FUL << LM3S_EPI_GPCFG_FRMCNT_Pos)

#define LM3S_EPI_GPCFG_RW_Pos                    21
#define LM3S_EPI_GPCFG_RW_Msk                    (1UL << LM3S_EPI_GPCFG_RW_Pos)

#define LM3S_EPI_GPCFG_WR2CYC_Pos                19
#define LM3S_EPI_GPCFG_WR2CYC_Msk                (1UL << LM3S_EPI_GPCFG_WR2CYC_Pos)

#define LM3S_EPI_GPCFG_RD2CYC_Pos                18
#define LM3S_EPI_GPCFG_RD2CYC_Msk                (1UL << LM3S_EPI_GPCFG_RD2CYC_Pos)

#define LM3S_EPI_GPCFG_MAXWAIT_Pos                8
#define LM3S_EPI_GPCFG_MAXWAIT_Msk               (0x000000FFUL << LM3S_EPI_GPCFG_MAXWAIT_Pos)

#define LM3S_EPI_GPCFG_ASIZE_Pos                  4
#define LM3S_EPI_GPCFG_ASIZE_Msk                 (0x00000003UL << LM3S_EPI_GPCFG_ASIZE_Pos)
#define LM3S_EPI_GPCFG_ASIZE_1_Pos                5
#define LM3S_EPI_GPCFG_ASIZE_1_Msk               (1UL << LM3S_EPI_GPCFG_ASIZE_1_Pos)
#define LM3S_EPI_GPCFG_ASIZE_0_Pos                4
#define LM3S_EPI_GPCFG_ASIZE_0_Msk               (1UL << LM3S_EPI_GPCFG_ASIZE_0_Pos)

#define LM3S_EPI_GPCFG_DSIZE_Pos                  0
#define LM3S_EPI_GPCFG_DSIZE_Msk                 (0x00000003UL /*<< LM3S_EPI_GPCFG_DSIZE_Pos*/)
#define LM3S_EPI_GPCFG_DSIZE_1_Pos                1
#define LM3S_EPI_GPCFG_DSIZE_1_Msk               (1UL << LM3S_EPI_GPCFG_DSIZE_1_Pos)
#define LM3S_EPI_GPCFG_DSIZE_0_Pos                0
#define LM3S_EPI_GPCFG_DSIZE_0_Msk               (1UL /*<< LM3S_EPI_GPCFG_DSIZE_0_Pos*/)

/* LM3S_EPI HB8CFG2 Register Definitions */
#define LM3S_EPI_HB8CFG2_WORD_Pos                31
#define LM3S_EPI_HB8CFG2_WORD_Msk                (1UL << LM3S_EPI_HB8CFG2_WORD_Pos)

#define LM3S_EPI_HB8CFG2_CSBAUD_Pos              26
#define LM3S_EPI_HB8CFG2_CSBAUD_Msk              (1UL << LM3S_EPI_HB8CFG2_CSBAUD_Pos)

#define LM3S_EPI_HB8CFG2_CSCFG_Pos               24
#define LM3S_EPI_HB8CFG2_CSCFG_Msk               (1UL << LM3S_EPI_HB8CFG2_CSCFG_Pos)
#define LM3S_EPI_HB8CFG2_CSCFG_1_Pos             25
#define LM3S_EPI_HB8CFG2_CSCFG_1_Msk             (1UL << LM3S_EPI_HB8CFG2_CSCFG_1_Pos)
#define LM3S_EPI_HB8CFG2_CSCFG_0_Pos             24
#define LM3S_EPI_HB8CFG2_CSCFG_0_Msk             (1UL << LM3S_EPI_HB8CFG2_CSCFG_0_Pos)

/* LM3S_EPI HB16CFG2 Register Definitions */
#define LM3S_EPI_HB16CFG2_WORD_Pos               31
#define LM3S_EPI_HB16CFG2_WORD_Msk               (1UL << LM3S_EPI_HB16CFG2_WORD_Pos)

#define LM3S_EPI_HB16CFG2_CSBAUD_Pos             26
#define LM3S_EPI_HB16CFG2_CSBAUD_Msk             (1UL << LM3S_EPI_HB16CFG2_CSBAUD_Pos)

#define LM3S_EPI_HB16CFG2_CSCFG_Pos              24
#define LM3S_EPI_HB16CFG2_CSCFG_Msk              (1UL << LM3S_EPI_HB16CFG2_CSCFG_Pos)
#define LM3S_EPI_HB16CFG2_CSCFG_1_Pos            25
#define LM3S_EPI_HB16CFG2_CSCFG_1_Msk            (1UL << LM3S_EPI_HB16CFG2_CSCFG_1_Pos)
#define LM3S_EPI_HB16CFG2_CSCFG_0_Pos            24
#define LM3S_EPI_HB16CFG2_CSCFG_0_Msk            (1UL << LM3S_EPI_HB16CFG2_CSCFG_0_Pos)

/* LM3S_EPI GPCFG2 Register Definitions */
#define LM3S_EPI_GPCFG2_WORD_Pos                 31
#define LM3S_EPI_GPCFG2_WORD_Msk                 (1UL << LM3S_EPI_GPCFG2_WORD_Pos)

/* LM3S_EPI ADDRMAP Register Definitions */
#define LM3S_EPI_ADDRMAP_EPSZ_Pos                 6
#define LM3S_EPI_ADDRMAP_EPSZ_Msk                (0x00000003UL << LM3S_EPI_ADDRMAP_EPSZ_Pos)
#define LM3S_EPI_ADDRMAP_EPSZ_1_Pos               7
#define LM3S_EPI_ADDRMAP_EPSZ_1_Msk              (1UL << LM3S_EPI_ADDRMAP_EPSZ_1_Pos)
#define LM3S_EPI_ADDRMAP_EPSZ_0_Pos               6
#define LM3S_EPI_ADDRMAP_EPSZ_0_Msk              (1UL << LM3S_EPI_ADDRMAP_EPSZ_0_Pos)

#define LM3S_EPI_ADDRMAP_EPADR_Pos                4
#define LM3S_EPI_ADDRMAP_EPADR_Msk               (0x00000003UL << LM3S_EPI_ADDRMAP_EPADR_Pos)
#define LM3S_EPI_ADDRMAP_EPADR_1_Pos              5
#define LM3S_EPI_ADDRMAP_EPADR_1_Msk             (1UL << LM3S_EPI_ADDRMAP_EPADR_1_Pos)
#define LM3S_EPI_ADDRMAP_EPADR_0_Pos              4
#define LM3S_EPI_ADDRMAP_EPADR_0_Msk             (1UL << LM3S_EPI_ADDRMAP_EPADR_0_Pos)

#define LM3S_EPI_ADDRMAP_ERSZ_Pos                 2
#define LM3S_EPI_ADDRMAP_ERSZ_Msk                (0x00000003UL << LM3S_EPI_ADDRMAP_ERSZ_Pos)
#define LM3S_EPI_ADDRMAP_ERSZ_1_Pos               3
#define LM3S_EPI_ADDRMAP_ERSZ_1_Msk              (1UL << LM3S_EPI_ADDRMAP_ERSZ_1_Pos)
#define LM3S_EPI_ADDRMAP_ERSZ_0_Pos               2
#define LM3S_EPI_ADDRMAP_ERSZ_0_Msk              (1UL << LM3S_EPI_ADDRMAP_ERSZ_0_Pos)

#define LM3S_EPI_ADDRMAP_ERADR_Pos                0
#define LM3S_EPI_ADDRMAP_ERADR_Msk               (0x00000003UL /*<< LM3S_EPI_ADDRMAP_ERADR_Pos*/)
#define LM3S_EPI_ADDRMAP_ERADR_1_Pos              1
#define LM3S_EPI_ADDRMAP_ERADR_1_Msk             (1UL << LM3S_EPI_ADDRMAP_ERADR_1_Pos)
#define LM3S_EPI_ADDRMAP_ERADR_0_Pos              0
#define LM3S_EPI_ADDRMAP_ERADR_0_Msk             (1UL /*<< LM3S_EPI_ADDRMAP_ERADR_0_Pos*/)

/* LM3S_EPI RSIZEN Register Definitions */
#define LM3S_EPI_RSIZEN_SIZE_Pos                  0
#define LM3S_EPI_RSIZEN_SIZE_Msk                 (0x00000003UL /*<< LM3S_EPI_RSIZEN_SIZE_Pos*/)
#define LM3S_EPI_RSIZEN_SIZE_1_Pos                1
#define LM3S_EPI_RSIZEN_SIZE_1_Msk               (1UL << LM3S_EPI_RSIZEN_SIZE_1_Pos)
#define LM3S_EPI_RSIZEN_SIZE_0_Pos                0
#define LM3S_EPI_RSIZEN_SIZE_0_Msk               (1UL /*<< LM3S_EPI_RSIZEN_SIZE_0_Pos*/)

/* LM3S_EPI RADDRN Register Definitions */
#define LM3S_EPI_RADDRN_ADDR_Pos                  0
#define LM3S_EPI_RADDRN_ADDR_Msk                 (0x1FFFFFFFUL /*<< LM3S_EPI_RADDRN_ADDR_Pos*/)

/* LM3S_EPI RPSTDN Register Definitions */
#define LM3S_EPI_RPSTDN_POSTCNT_Pos               0
#define LM3S_EPI_RPSTDN_POSTCNT_Msk              (0x00001FFFUL /*<< LM3S_EPI_RPSTDN_POSTCNT_Pos*/)

/* LM3S_EPI STAT Register Definitions */
#define LM3S_EPI_STAT_CELOW_Pos                   9
#define LM3S_EPI_STAT_CELOW_Msk                  (1UL << LM3S_EPI_STAT_CELOW_Pos)

#define LM3S_EPI_STAT_XFFULL_Pos                  8
#define LM3S_EPI_STAT_XFFULL_Msk                 (1UL << LM3S_EPI_STAT_XFFULL_Pos)

#define LM3S_EPI_STAT_XFEMPTY_Pos                 7
#define LM3S_EPI_STAT_XFEMPTY_Msk                (1UL << LM3S_EPI_STAT_XFEMPTY_Pos)

#define LM3S_EPI_STAT_INITSEQ_Pos                 6
#define LM3S_EPI_STAT_INITSEQ_Msk                (1UL << LM3S_EPI_STAT_INITSEQ_Pos)

#define LM3S_EPI_STAT_WBUSY_Pos                   5
#define LM3S_EPI_STAT_WBUSY_Msk                  (1UL << LM3S_EPI_STAT_WBUSY_Pos)

#define LM3S_EPI_STAT_NBRBUSY_Pos                 4
#define LM3S_EPI_STAT_NBRBUSY_Msk                (1UL << LM3S_EPI_STAT_NBRBUSY_Pos)

#define LM3S_EPI_STAT_ACTIVE_Pos                  0
#define LM3S_EPI_STAT_ACTIVE_Msk                 (1UL /*<< LM3S_EPI_STAT_ACTIVE_Pos*/)

/* LM3S_EPI RFIFOCNT Register Definitions */
#define LM3S_EPI_RFIFOCNT_COUNT_Pos               0
#define LM3S_EPI_RFIFOCNT_COUNT_Msk              (0x00000007UL /*<< LM3S_EPI_RFIFOCNT_COUNT_Pos*/)

/* LM3S_EPI READFIFO Register Definitions */
#define LM3S_EPI_READFIFO_DATA_Pos                0
#define LM3S_EPI_READFIFO_DATA_Msk               (0xFFFFFFFFUL /*<< LM3S_EPI_READFIFO_DATA_Pos*/)

/* LM3S_EPI FIFOLVL Register Definitions */
#define LM3S_EPI_FIFOLVL_WFERR_Pos               17
#define LM3S_EPI_FIFOLVL_WFERR_Msk               (1UL << LM3S_EPI_FIFOLVL_WFERR_Pos)

#define LM3S_EPI_FIFOLVL_RSERR_Pos               16
#define LM3S_EPI_FIFOLVL_RSERR_Msk               (1UL << LM3S_EPI_FIFOLVL_RSERR_Pos)

#define LM3S_EPI_FIFOLVL_WRFIFO_Pos               4
#define LM3S_EPI_FIFOLVL_WRFIFO_Msk              (0x00000007UL << LM3S_EPI_FIFOLVL_WRFIFO_Pos)
#define LM3S_EPI_FIFOLVL_WRFIFO_2_Pos             6
#define LM3S_EPI_FIFOLVL_WRFIFO_2_Msk            (1UL << LM3S_EPI_FIFOLVL_WRFIFO_2_Pos)
#define LM3S_EPI_FIFOLVL_WRFIFO_1_Pos             5
#define LM3S_EPI_FIFOLVL_WRFIFO_1_Msk            (1UL << LM3S_EPI_FIFOLVL_WRFIFO_1_Pos)
#define LM3S_EPI_FIFOLVL_WRFIFO_0_Pos             4
#define LM3S_EPI_FIFOLVL_WRFIFO_0_Msk            (1UL << LM3S_EPI_FIFOLVL_WRFIFO_0_Pos)

#define LM3S_EPI_FIFOLVL_RDFIFO_Pos               0
#define LM3S_EPI_FIFOLVL_RDFIFO_Msk              (0x00000007UL /*<< LM3S_EPI_FIFOLVL_RDFIFO_Pos*/)
#define LM3S_EPI_FIFOLVL_RDFIFO_2_Pos             2
#define LM3S_EPI_FIFOLVL_RDFIFO_2_Msk            (1UL << LM3S_EPI_FIFOLVL_RDFIFO_2_Pos)
#define LM3S_EPI_FIFOLVL_RDFIFO_1_Pos             1
#define LM3S_EPI_FIFOLVL_RDFIFO_1_Msk            (1UL << LM3S_EPI_FIFOLVL_RDFIFO_1_Pos)
#define LM3S_EPI_FIFOLVL_RDFIFO_0_Pos             0
#define LM3S_EPI_FIFOLVL_RDFIFO_0_Msk            (1UL /*<< LM3S_EPI_FIFOLVL_RDFIFO_0_Pos*/)

/* LM3S_EPI WFIFOCNT Register Definitions */
#define LM3S_EPI_WFIFOCNT_WTAV_Pos                0
#define LM3S_EPI_WFIFOCNT_WTAV_Msk               (0x00000007UL /*<< LM3S_EPI_WFIFOCNT_WTAV_Pos*/)

/* LM3S_EPI IM Register Definitions */
#define LM3S_EPI_IM_WRIM_Pos                      2
#define LM3S_EPI_IM_WRIM_Msk                     (1UL << LM3S_EPI_IM_WRIM_Pos)

#define LM3S_EPI_IM_RDIM_Pos                      1
#define LM3S_EPI_IM_RDIM_Msk                     (1UL << LM3S_EPI_IM_RDIM_Pos)

#define LM3S_EPI_IM_ERRIM_Pos                     0
#define LM3S_EPI_IM_ERRIM_Msk                    (1UL /*<< LM3S_EPI_IM_ERRIM_Pos*/)

/* LM3S_EPI RIS Register Definitions */
#define LM3S_EPI_RIS_WRRIS_Pos                    2
#define LM3S_EPI_RIS_WRRIS_Msk                   (1UL << LM3S_EPI_RIS_WRRIS_Pos)

#define LM3S_EPI_RIS_RDRIS_Pos                    1
#define LM3S_EPI_RIS_RDRIS_Msk                   (1UL << LM3S_EPI_RIS_RDRIS_Pos)

#define LM3S_EPI_RIS_ERRRIS_Pos                   0
#define LM3S_EPI_RIS_ERRRIS_Msk                  (1UL /*<< LM3S_EPI_RIS_ERRRIS_Pos*/)

/* LM3S_EPI MIS Register Definitions */
#define LM3S_EPI_MIS_WRMIS_Pos                    2
#define LM3S_EPI_MIS_WRMIS_Msk                   (1UL << LM3S_EPI_MIS_WRMIS_Pos)

#define LM3S_EPI_MIS_RDMIS_Pos                    1
#define LM3S_EPI_MIS_RDMIS_Msk                   (1UL << LM3S_EPI_MIS_RDMIS_Pos)

#define LM3S_EPI_MIS_ERRMIS_Pos                   0
#define LM3S_EPI_MIS_ERRMIS_Msk                  (1UL /*<< LM3S_EPI_MIS_ERRMIS_Pos*/)

/* LM3S_EPI EISC Register Definitions */
#define LM3S_EPI_EISC_WTFULL_Pos                  2
#define LM3S_EPI_EISC_WTFULL_Msk                 (1UL << LM3S_EPI_EISC_WTFULL_Pos)

#define LM3S_EPI_EISC_RSTALL_Pos                  1
#define LM3S_EPI_EISC_RSTALL_Msk                 (1UL << LM3S_EPI_EISC_RSTALL_Pos)

#define LM3S_EPI_EISC_TOUT_Pos                    0
#define LM3S_EPI_EISC_TOUT_Msk                   (1UL /*<< LM3S_EPI_EISC_TOUT_Pos*/)

/* ================================================================================ */
/* ================                     SYSCTL                     ================ */
/* ================================================================================ */

typedef struct {
  __IM  uint32_t  DID0;                 /* Offset: 0x000 (R/ ) Device Identification Register 0 */
  __IM  uint32_t  DID1;                 /* Offset: 0x004 (R/ ) Device Identification Register 1 */
  __IM  uint32_t  DC0;                  /* Offset: 0x008 (R/ ) Device Capabilities Register 0 */
  __IM  uint32_t  RESERVED0;
  __IM  uint32_t  DC1;                  /* Offset: 0x010 (R/ ) Device Capabilities Register 1 */
  __IM  uint32_t  DC2;                  /* Offset: 0x014 (R/ ) Device Capabilities Register 2 */
  __IM  uint32_t  DC3;                  /* Offset: 0x018 (R/ ) Device Capabilities Register 3 */
  __IM  uint32_t  DC4;                  /* Offset: 0x01C (R/ ) Device Capabilities Register 4 */
  __IM  uint32_t  DC5;                  /* Offset: 0x020 (R/ ) Device Capabilities Register 5 */
  __IM  uint32_t  DC6;                  /* Offset: 0x024 (R/ ) Device Capabilities Register 6 */
  __IM  uint32_t  DC7;                  /* Offset: 0x028 (R/ ) Device Capabilities Register 7 */
  __IM  uint32_t  DC8;                  /* Offset: 0x02C (R/ ) Device Capabilities Register 8 ADC Channels */
  __IOM uint32_t  PBORCTL;              /* Offset: 0x030 (R/W) Power Brown-Out Reset Control Register */
  __IM  uint32_t  RESERVED1[3];
  __IOM uint32_t  SRCR0;                /* Offset: 0x040 (R/W) Software Reset Control Register 0 */
  __IOM uint32_t  SRCR1;                /* Offset: 0x044 (R/W) Software Reset Control Register 1 */
  __IOM uint32_t  SRCR2;                /* Offset: 0x048 (R/W) Software Reset Control Register 2 */
  __IM  uint32_t  RESERVED2;
  __IOM uint32_t  RIS;                  /* Offset: 0x050 (R/ ) Raw Interrupt Status Register */
  __IOM uint32_t  IMC;                  /* Offset: 0x054 (R/ ) Interrupt Mask Control Register */
  __IOM uint32_t  MISC;                 /* Offset: 0x058 (R/ ) Masked Interrupt Status and Clear Register */
  __IOM uint32_t  RESC;                 /* Offset: 0x05C (R/ ) Reset Cause Register */
  __IOM uint32_t  RCC;                  /* Offset: 0x060 (R/ ) Run-Mode Clock Configuration Register */
  __IM  uint32_t  PLLCFG;               /* Offset: 0x064 (R/ ) XTAL to PLL Translation Register */
  __IM  uint32_t  RESERVED3;
  __IOM uint32_t  GPIOHBCTL;            /* Offset: 0x06C (R/ ) GPIO High-Performance Bus Control Register */
  __IOM uint32_t  RCC2;                 /* Offset: 0x070 (R/ ) Run-Mode Clock Configuration Register 2 */
  __IM  uint32_t  RESERVED4[2];
  __IOM uint32_t  MOSCCTL;              /* Offset: 0x07C (R/ ) Main Oscillator Control Register */
  __IM  uint32_t  RESERVED5[32];
  __IOM uint32_t  RCGC0;                /* Offset: 0x100 (R/ ) Run Mode Clock Gating Control Register 0 */
  __IOM uint32_t  RCGC1;                /* Offset: 0x104 (R/ ) Run Mode Clock Gating Control Register 1 */
  __IOM uint32_t  RCGC2;                /* Offset: 0x108 (R/ ) Run Mode Clock Gating Control Register 2 */
  __IM  uint32_t  RESERVED6;
  __IOM uint32_t  SCGC0;                /* Offset: 0x110 (R/ ) Sleep Mode Clock Gating Control Register 0 */
  __IOM uint32_t  SCGC1;                /* Offset: 0x114 (R/ ) Sleep Mode Clock Gating Control Register 1 */
  __IOM uint32_t  SCGC2;                /* Offset: 0x118 (R/ ) Sleep Mode Clock Gating Control Register 2 */
  __IM  uint32_t  RESERVED7;
  __IOM uint32_t  DCGC0;                /* Offset: 0x120 (R/ ) Deep Sleep Mode Clock Gating Control Register 0 */
  __IOM uint32_t  DCGC1;                /* Offset: 0x124 (R/ ) Deep-Sleep Mode Clock Gating Control Register 1 */
  __IOM uint32_t  DCGC2;                /* Offset: 0x128 (R/ ) Deep Sleep Mode Clock Gating Control Register 2 */
  __IM  uint32_t  RESERVED8[6];
  __IOM uint32_t  DSLPCLKCFG;           /* Offset: 0x144 (R/ ) Deep Sleep Clock Configuration Register */
  __IM  uint32_t  RESERVED9[2];
  __IOM uint32_t  PIOSCCAL;             /* Offset: 0x150 (R/ ) Precision Internal Oscillator Calibration Register */
  __IM  uint32_t  RESERVED10[7];
  __IOM uint32_t  I2SMCLKCFG;           /* Offset: 0x170 (R/ ) I2S MCLK Configuration Register */
  __IM  uint32_t  RESERVED11[7];
  __IM  uint32_t  DC9;                  /* Offset: 0x190 (R/ ) Device Capabilities Register 9 ADC Digital Comparators */
  __IM  uint32_t  RESERVED12[3];
  __IM  uint32_t  NVMSTAT;              /* Offset: 0x1A0 (R/ ) Non-Volatile Memory Information Register */
} LM3S_SYSCTL_TypeDef;

/* LM3S_SYSCTL DID0 Register Definitions */
#define LM3S_SYSCTL_DID0_VER_Pos                 28
#define LM3S_SYSCTL_DID0_VER_Msk                 (0x00000003UL << LM3S_SYSCTL_DID0_VER_Pos)

#define LM3S_SYSCTL_DID0_VER2_Pos                30
#define LM3S_SYSCTL_DID0_VER2_Msk                (1UL << LM3S_SYSCTL_DID0_VER2_Pos)

#define LM3S_SYSCTL_DID0_VER1_Pos                29
#define LM3S_SYSCTL_DID0_VER1_Msk                (1UL << LM3S_SYSCTL_DID0_VER1_Pos)

#define LM3S_SYSCTL_DID0_VER0_Pos                28
#define LM3S_SYSCTL_DID0_VER0_Msk                (1UL << LM3S_SYSCTL_DID0_VER0_Pos)

#define LM3S_SYSCTL_DID0_CLASS_Pos               16
#define LM3S_SYSCTL_DID0_CLASS_Msk               (0x0000FFFFUL << LM3S_SYSCTL_DID0_CLASS_Pos)

#define LM3S_SYSCTL_DID0_MAJOR_Pos                8
#define LM3S_SYSCTL_DID0_MAJOR_Msk               (0x0000FFFFUL << LM3S_SYSCTL_DID0_MAJOR_Pos)

#define LM3S_SYSCTL_DID0_MINOR_Pos                0
#define LM3S_SYSCTL_DID0_MINOR_Msk               (0x0000FFFFUL /*<< LM3S_SYSCTL_DID0_MINOR_Pos*/)

/* LM3S_SYSCTL PBOCTL Register Definitions */
#define LM3S_SYSCTL_PBOCTL_BORIOR_Pos             1
#define LM3S_SYSCTL_PBOCTL_BORIOR_Msk            (1UL << LM3S_SYSCTL_PBOCTL_BORIOR_Pos)

/* LM3S_SYSCTL RIS Register Definitions */
#define LM3S_SYSCTL_RIS_MOSCPUPRIS_Pos            8
#define LM3S_SYSCTL_RIS_MOSCPUPRIS_Msk           (1UL << LM3S_SYSCTL_RIS_MOSCPUPRIS_Pos)

#define LM3S_SYSCTL_RIS_USBPLLLRIS_Pos            7
#define LM3S_SYSCTL_RIS_USBPLLLRIS_Msk           (1UL << LM3S_SYSCTL_RIS_USBPLLLRIS_Pos)

#define LM3S_SYSCTL_RIS_PLLLRIS_Pos               6
#define LM3S_SYSCTL_RIS_PLLLRIS_Msk              (1UL << LM3S_SYSCTL_RIS_PLLLRIS_Pos)

#define LM3S_SYSCTL_RIS_BORRIS_Pos                1
#define LM3S_SYSCTL_RIS_BORRIS_Msk               (1UL << LM3S_SYSCTL_RIS_BORRIS_Pos)

/* LM3S_SYSCTL IMC Register Definitions */
#define LM3S_SYSCTL_IMC_MOSCPUPIM_Pos             8
#define LM3S_SYSCTL_IMC_MOSCPUPIM_Msk            (1UL << LM3S_SYSCTL_IMC_MOSCPUPIM_Pos)

#define LM3S_SYSCTL_IMC_USBPLLLIM_Pos             7
#define LM3S_SYSCTL_IMC_USBPLLLIM_Msk            (1UL << LM3S_SYSCTL_IMC_USBPLLLIM_Pos)

#define LM3S_SYSCTL_IMC_PLLLIM_Pos                6
#define LM3S_SYSCTL_IMC_PLLLIM_Msk               (1UL << LM3S_SYSCTL_IMC_PLLLIM_Pos)

#define LM3S_SYSCTL_IMC_BORIM_Pos                 1
#define LM3S_SYSCTL_IMC_BORIM_Msk                (1UL << LM3S_SYSCTL_IMC_BORIM_Pos)

/* LM3S_SYSCTL MISC Register Definitions */
#define LM3S_SYSCTL_MISC_MOSCPUPMIS_Pos           8
#define LM3S_SYSCTL_MISC_MOSCPUPMIS_Msk          (1UL << LM3S_SYSCTL_MISC_MOSCPUPMIS_Pos)

#define LM3S_SYSCTL_MISC_USBPLLLMIS_Pos           7
#define LM3S_SYSCTL_MISC_USBPLLLMIS_Msk          (1UL << LM3S_SYSCTL_MISC_USBPLLLMIS_Pos)

#define LM3S_SYSCTL_MISC_PLLLMIS_Pos              6
#define LM3S_SYSCTL_MISC_PLLLMIS_Msk             (1UL << LM3S_SYSCTL_MISC_PLLLMIS_Pos)

#define LM3S_SYSCTL_MISC_BORMIS_Pos               1
#define LM3S_SYSCTL_MISC_BORMIS_Msk              (1UL << LM3S_SYSCTL_MISC_BORMIS_Pos)

/* LM3S_SYSCTL RESC Register Definitions */
#define LM3S_SYSCTL_RESC_MOSCFAIL_Pos            16
#define LM3S_SYSCTL_RESC_MOSCFAIL_Msk            (1UL << LM3S_SYSCTL_RESC_MOSCFAIL_Pos)

#define LM3S_SYSCTL_RESC_WDT1_Pos                 5
#define LM3S_SYSCTL_RESC_WDT1_Msk                (1UL << LM3S_SYSCTL_RESC_WDT1_Pos)

#define LM3S_SYSCTL_RESC_SW_Pos                   4
#define LM3S_SYSCTL_RESC_SW_Msk                  (1UL << LM3S_SYSCTL_RESC_SW_Pos)

#define LM3S_SYSCTL_RESC_WDT0_Pos                 3
#define LM3S_SYSCTL_RESC_WDT0_Msk                (1UL << LM3S_SYSCTL_RESC_WDT0_Pos)

#define LM3S_SYSCTL_RESC_BOR_Pos                  2
#define LM3S_SYSCTL_RESC_BOR_Msk                 (1UL << LM3S_SYSCTL_RESC_BOR_Pos)

#define LM3S_SYSCTL_RESC_POR_Pos                  1
#define LM3S_SYSCTL_RESC_POR_Msk                 (1UL << LM3S_SYSCTL_RESC_POR_Pos)

#define LM3S_SYSCTL_RESC_EXT_Pos                  0
#define LM3S_SYSCTL_RESC_EXT_Msk                 (1UL /*<< LM3S_SYSCTL_RESC_EXT_Pos*/)

/* LM3S_SYSCTL RCC Register Definitions */
#define LM3S_SYSCTL_RCC_ACG_Pos                  27
#define LM3S_SYSCTL_RCC_ACG_Msk                  (1UL << LM3S_SYSCTL_RCC_ACG_Pos)

#define LM3S_SYSCTL_RCC_SYSDIV_Pos               23
#define LM3S_SYSCTL_RCC_SYSDIV_Msk               (0x0000000FUL << LM3S_SYSCTL_RCC_SYSDIV_Pos)
#define LM3S_SYSCTL_RCC_SYSDIV_3_Pos             26
#define LM3S_SYSCTL_RCC_SYSDIV_3_Msk             (1UL << LM3S_SYSCTL_RCC_SYSDIV_3_Pos)
#define LM3S_SYSCTL_RCC_SYSDIV_2_Pos             25
#define LM3S_SYSCTL_RCC_SYSDIV_2_Msk             (1UL << LM3S_SYSCTL_RCC_SYSDIV_2_Pos)
#define LM3S_SYSCTL_RCC_SYSDIV_1_Pos             24
#define LM3S_SYSCTL_RCC_SYSDIV_1_Msk             (1UL << LM3S_SYSCTL_RCC_SYSDIV_1_Pos)
#define LM3S_SYSCTL_RCC_SYSDIV_0_Pos             23
#define LM3S_SYSCTL_RCC_SYSDIV_0_Msk             (1UL << LM3S_SYSCTL_RCC_SYSDIV_0_Pos)

#define LM3S_SYSCTL_RCC_USESYSDIV_Pos            22
#define LM3S_SYSCTL_RCC_USESYSDIV_Msk            (1UL << LM3S_SYSCTL_RCC_USESYSDIV_Pos)

#define LM3S_SYSCTL_RCC_USEPWMDIV_Pos            21
#define LM3S_SYSCTL_RCC_USEPWMDIV_Msk            (1UL << LM3S_SYSCTL_RCC_USEPWMDIV_Pos)

#define LM3S_SYSCTL_RCC_PWMDIV_Pos               17
#define LM3S_SYSCTL_RCC_PWMDIV_Msk               (0x00000003UL << LM3S_SYSCTL_RCC_PWMDIV_Pos)
#define LM3S_SYSCTL_RCC_PWMDIV_2_Pos             19
#define LM3S_SYSCTL_RCC_PWMDIV_2_Msk             (1UL << LM3S_SYSCTL_RCC_PWMDIV_2_Pos)
#define LM3S_SYSCTL_RCC_PWMDIV_1_Pos             18
#define LM3S_SYSCTL_RCC_PWMDIV_1_Msk             (1UL << LM3S_SYSCTL_RCC_PWMDIV_1_Pos)
#define LM3S_SYSCTL_RCC_PWMDIV_0_Pos             17
#define LM3S_SYSCTL_RCC_PWMDIV_0_Msk             (1UL << LM3S_SYSCTL_RCC_PWMDIV_0_Pos)

#define LM3S_SYSCTL_RCC_PWRDN_Pos                13
#define LM3S_SYSCTL_RCC_PWRDN_Msk                (1UL << LM3S_SYSCTL_RCC_PWRDN_Pos)

#define LM3S_SYSCTL_RCC_BYPASS_Pos               11
#define LM3S_SYSCTL_RCC_BYPASS_Msk               (1UL << LM3S_SYSCTL_RCC_BYPASS_Pos)

#define LM3S_SYSCTL_RCC_XTAL_Pos                  6
#define LM3S_SYSCTL_RCC_XTAL_Msk                 (0x0000001FUL << LM3S_SYSCTL_RCC_XTAL_Pos)
#define LM3S_SYSCTL_RCC_XTAL_4_Pos               10
#define LM3S_SYSCTL_RCC_XTAL_4_Msk               (1UL << LM3S_SYSCTL_RCC_XTAL_4_Pos)
#define LM3S_SYSCTL_RCC_XTAL_3_Pos                9
#define LM3S_SYSCTL_RCC_XTAL_3_Msk               (1UL << LM3S_SYSCTL_RCC_XTAL_3_Pos)
#define LM3S_SYSCTL_RCC_XTAL_2_Pos                8
#define LM3S_SYSCTL_RCC_XTAL_2_Msk               (1UL << LM3S_SYSCTL_RCC_XTAL_2_Pos)
#define LM3S_SYSCTL_RCC_XTAL_1_Pos                7
#define LM3S_SYSCTL_RCC_XTAL_1_Msk               (1UL << LM3S_SYSCTL_RCC_XTAL_1_Pos)
#define LM3S_SYSCTL_RCC_XTAL_0_Pos                6
#define LM3S_SYSCTL_RCC_XTAL_0_Msk               (1UL << LM3S_SYSCTL_RCC_XTAL_0_Pos)

#define LM3S_SYSCTL_RCC_OSCSRC_Pos                4
#define LM3S_SYSCTL_RCC_OSCSRC_Msk               (0x00000003UL << LM3S_SYSCTL_RCC_OSCSRC_Pos)
#define LM3S_SYSCTL_RCC_OSCSRC_1_Pos              5
#define LM3S_SYSCTL_RCC_OSCSRC_1_Msk             (1UL << LM3S_SYSCTL_RCC_OSCSRC_1_Pos)
#define LM3S_SYSCTL_RCC_OSCSRC_0_Pos              4
#define LM3S_SYSCTL_RCC_OSCSRC_0_Msk             (1UL << LM3S_SYSCTL_RCC_OSCSRC_0_Pos)

#define LM3S_SYSCTL_RCC_IOSCDIS_Pos               1
#define LM3S_SYSCTL_RCC_IOSCDIS_Msk              (1UL << LM3S_SYSCTL_RCC_IOSCDIS_Pos)

#define LM3S_SYSCTL_RCC_MOSCDIS_Pos               0
#define LM3S_SYSCTL_RCC_MOSCDIS_Msk              (1UL /*<< LM3S_SYSCTL_RCC_MOSCDIS_Pos*/)

/* LM3S_SYSCTL PLLCFG Register Definitions */
#define LM3S_SYSCTL_PLLCFG_F_Pos                  5
#define LM3S_SYSCTL_PLLCFG_F_Msk                 (0x000001FFUL << LM3S_SYSCTL_PLLCFG_F_Pos)

#define LM3S_SYSCTL_PLLCFG_R_Pos                  0
#define LM3S_SYSCTL_PLLCFG_R_Msk                 (0x000000FFUL /*<< LM3S_SYSCTL_PLLCFG_R_Pos*/)

/* LM3S_SYSCTL GPIOHBCTL Register Definitions */
#define LM3S_SYSCTL_GPIOHBCTL_PORTJ_Pos           8
#define LM3S_SYSCTL_GPIOHBCTL_PORTJ_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTJ_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTH_Pos           7
#define LM3S_SYSCTL_GPIOHBCTL_PORTH_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTH_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTG_Pos           6
#define LM3S_SYSCTL_GPIOHBCTL_PORTG_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTG_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTF_Pos           5
#define LM3S_SYSCTL_GPIOHBCTL_PORTF_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTF_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTE_Pos           4
#define LM3S_SYSCTL_GPIOHBCTL_PORTE_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTE_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTD_Pos           3
#define LM3S_SYSCTL_GPIOHBCTL_PORTD_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTD_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTC_Pos           2
#define LM3S_SYSCTL_GPIOHBCTL_PORTC_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTC_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTB_Pos           1
#define LM3S_SYSCTL_GPIOHBCTL_PORTB_Msk          (1UL << LM3S_SYSCTL_GPIOHBCTL_PORTB_Pos)

#define LM3S_SYSCTL_GPIOHBCTL_PORTA_Pos           0
#define LM3S_SYSCTL_GPIOHBCTL_PORTA_Msk          (0xFFFFFFFFUL /*<< LM3S_SYSCTL_GPIOHBCTL_PORTA_Pos*/)

/* LM3S_SYSCTL RCC2 Register Definitions */
#define LM3S_SYSCTL_RCC2_USERCC2_Pos             31
#define LM3S_SYSCTL_RCC2_USERCC2_Msk             (1UL << LM3S_SYSCTL_RCC2_USERCC2_Pos)

#define LM3S_SYSCTL_RCC2_DIV400_Pos              30
#define LM3S_SYSCTL_RCC2_DIV400_Msk              (1UL << LM3S_SYSCTL_RCC2_DIV400_Pos)

#define LM3S_SYSCTL_RCC2_SYSDIV2_Pos             23
#define LM3S_SYSCTL_RCC2_SYSDIV2_Msk             (0x0000003FUL << LM3S_SYSCTL_RCC2_SYSDIV2_Pos)
#define LM3S_SYSCTL_RCC2_SYSDIV2_5_Pos           28
#define LM3S_SYSCTL_RCC2_SYSDIV2_5_Msk           (1UL << LM3S_SYSCTL_RCC2_SYSDIV2_5_Pos)
#define LM3S_SYSCTL_RCC2_SYSDIV2_4_Pos           27
#define LM3S_SYSCTL_RCC2_SYSDIV2_4_Msk           (1UL << LM3S_SYSCTL_RCC2_SYSDIV2_4_Pos)
#define LM3S_SYSCTL_RCC2_SYSDIV2_3_Pos           26
#define LM3S_SYSCTL_RCC2_SYSDIV2_3_Msk           (1UL << LM3S_SYSCTL_RCC2_SYSDIV2_3_Pos)
#define LM3S_SYSCTL_RCC2_SYSDIV2_2_Pos           25
#define LM3S_SYSCTL_RCC2_SYSDIV2_2_Msk           (1UL << LM3S_SYSCTL_RCC2_SYSDIV2_2_Pos)
#define LM3S_SYSCTL_RCC2_SYSDIV2_1_Pos           24
#define LM3S_SYSCTL_RCC2_SYSDIV2_1_Msk           (1UL << LM3S_SYSCTL_RCC2_SYSDIV2_1_Pos)
#define LM3S_SYSCTL_RCC2_SYSDIV2_0_Pos           23
#define LM3S_SYSCTL_RCC2_SYSDIV2_0_Msk           (1UL << LM3S_SYSCTL_RCC2_SYSDIV2_0_Pos)

#define LM3S_SYSCTL_RCC2_SYSDIV2LSB_Pos          22
#define LM3S_SYSCTL_RCC2_SYSDIV2LSB_Msk          (1UL << LM3S_SYSCTL_RCC2_SYSDIV2LSB_Pos)

#define LM3S_SYSCTL_RCC2_USBPWRDN_Pos            14
#define LM3S_SYSCTL_RCC2_USBPWRDN_Msk            (1UL << LM3S_SYSCTL_RCC2_USBPWRDN_Pos)

#define LM3S_SYSCTL_RCC2_PWRDN2_Pos              13
#define LM3S_SYSCTL_RCC2_PWRDN2_Msk              (1UL << LM3S_SYSCTL_RCC2_PWRDN2_Pos)

#define LM3S_SYSCTL_RCC2_BYPASS2_Pos             11
#define LM3S_SYSCTL_RCC2_BYPASS2_Msk             (1UL << LM3S_SYSCTL_RCC2_BYPASS2_Pos)

#define LM3S_SYSCTL_RCC2_OSCSRC2_Pos              4
#define LM3S_SYSCTL_RCC2_OSCSRC2_Msk             (0x00000003UL << LM3S_SYSCTL_RCC2_OSCSRC2_Pos)
#define LM3S_SYSCTL_RCC2_OSCSRC2_1_Pos            5
#define LM3S_SYSCTL_RCC2_OSCSRC2_1_Msk           (1UL << LM3S_SYSCTL_RCC2_OSCSRC2_1_Pos)
#define LM3S_SYSCTL_RCC2_OSCSRC2_0_Pos            4
#define LM3S_SYSCTL_RCC2_OSCSRC2_0_Msk           (1UL << LM3S_SYSCTL_RCC2_OSCSRC2_0_Pos)

/* LM3S_SYSCTL MOSCCTL Register Definitions */
#define LM3S_SYSCTL_MOSCCTL_CVAL_Pos              0
#define LM3S_SYSCTL_MOSCCTL_CVAL_Msk             (1UL << /*LM3S_SYSCTL_MOSCCTL_CVAL_Pos*/)

/* LM3S_SYSCTL DSLPCLKCFG Register Definitions */
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_Pos    23
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_Msk    (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_5_Pos  28
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_5_Msk  (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_5_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_4_Pos  27
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_4_Msk  (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_4_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_3_Pos  26
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_3_Msk  (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_3_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_2_Pos  25
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_2_Msk  (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_2_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_1_Pos  24
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_1_Msk  (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_1_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_0_Pos  23
#define LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_0_Msk  (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSDIVORIDE_0_Pos)

#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_Pos       4
#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_Msk      (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_2_Pos     6
#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_2_Msk    (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_2_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_1_Pos     7
#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_1_Msk    (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_1_Pos)
#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_0_Pos     4
#define LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_0_Msk    (1UL << LM3S_SYSCTL_DSLPCLKCFG_DSOSCSRC_0__Pos)

/* LM3S_SYSCTL PIOSCCAL Register Definitions */
#define LM3S_SYSCTL_PIOSCCAL_UTEN_Pos            31
#define LM3S_SYSCTL_PIOSCCAL_UTEN_Msk            (1UL << LM3S_SYSCTL_PIOSCCAL_UTEN_Pos)

#define LM3S_SYSCTL_PIOSCCAL_UPDATE_Pos           8
#define LM3S_SYSCTL_PIOSCCAL_UPDATE_Msk          (1UL << LM3S_SYSCTL_PIOSCCAL_UPDATE_Pos)

#define LM3S_SYSCTL_PIOSCCAL_UT_Pos               0
#define LM3S_SYSCTL_PIOSCCAL_UT_Msk              (0x0000003FUL /*<< LM3S_SYSCTL_PIOSCCAL_UT_Pos*/)

/* LM3S_SYSCTL I2SMCLKCFG Register Definitions */
#define LM3S_SYSCTL_I2SMCLKCFG_RXEN_Pos          31
#define LM3S_SYSCTL_I2SMCLKCFG_RXEN_Msk          (1UL << LM3S_SYSCTL_I2SMCLKCFG_RXEN_Pos)

#define LM3S_SYSCTL_I2SMCLKCFG_RXI_Pos           20
#define LM3S_SYSCTL_I2SMCLKCFG_RXI_Msk           (0x000001FFUL << LM3S_SYSCTL_I2SMCLKCFG_RXI_Pos)

#define LM3S_SYSCTL_I2SMCLKCFG_RXF_Pos           16
#define LM3S_SYSCTL_I2SMCLKCFG_RXF_Msk           (0x000001FFUL << LM3S_SYSCTL_I2SMCLKCFG_RXF_Pos)

#define LM3S_SYSCTL_I2SMCLKCFG_TXEN_Pos          15
#define LM3S_SYSCTL_I2SMCLKCFG_TXEN_Msk          (1UL << LM3S_SYSCTL_I2SMCLKCFG_TXEN_Pos)

#define LM3S_SYSCTL_I2SMCLKCFG_TXI_Pos            4
#define LM3S_SYSCTL_I2SMCLKCFG_TXI_Msk           (0x000001FFUL << LM3S_SYSCTL_I2SMCLKCFG_TXI_Pos)

#define LM3S_SYSCTL_I2SMCLKCFG_TXF_Pos            0
#define LM3S_SYSCTL_I2SMCLKCFG_TXF_Msk           (0x000001FFUL /*<< LM3S_SYSCTL_I2SMCLKCFG_TXF_Pos*/)

/* LM3S_SYSCTL DID1 Register Definitions */
#define LM3S_SYSCTL_DID1_VER_Pos                 28
#define LM3S_SYSCTL_DID1_VER_Msk                 (0x0000000FUL << LM3S_SYSCTL_DID1_VER_Pos)

#define LM3S_SYSCTL_DID1_FAM_Pos                 24
#define LM3S_SYSCTL_DID1_FAM_Msk                 (0x0000000FUL << LM3S_SYSCTL_DID1_FAM_Pos)

#define LM3S_SYSCTL_DID1_PARTNO_Pos              16
#define LM3S_SYSCTL_DID1_PARTNO_Msk              (0x000000FFUL << LM3S_SYSCTL_DID1_PARTNO_Pos)

#define LM3S_SYSCTL_DID1_PINCOUNT_Pos            13
#define LM3S_SYSCTL_DID1_PINCOUNT_Msk            (0x00000007UL << LM3S_SYSCTL_DID1_PINCOUNT_Pos)

#define LM3S_SYSCTL_DID1_TEMP_Pos                 5
#define LM3S_SYSCTL_DID1_TEMP_Msk                (0x00000007UL << LM3S_SYSCTL_DID1_TEMP_Pos)

#define LM3S_SYSCTL_DID1_PKG_Pos                  3
#define LM3S_SYSCTL_DID1_PKG_Msk                 (0x00000003UL << LM3S_SYSCTL_DID1_PKG_Pos)

#define LM3S_SYSCTL_I2SMCLKCFG_ROHS_Pos           2
#define LM3S_SYSCTL_I2SMCLKCFG_ROHS_Msk          (1UL << LM3S_SYSCTL_I2SMCLKCFG_ROHS_Pos)

#define LM3S_SYSCTL_DID1_QUAL_Pos                 0
#define LM3S_SYSCTL_DID1_QUAL_Msk                (0x00000003UL /*<< LM3S_SYSCTL_DID1_QUAL_Pos*/)

/* LM3S_SYSCTL DC0 Register Definitions */
#define LM3S_SYSCTL_DC0_SRAMSZ_Pos               16
#define LM3S_SYSCTL_DC0_SRAMSZ_Msk               (0x000000FFUL << LM3S_SYSCTL_DC0_SRAMSZ_Pos)

#define LM3S_SYSCTL_DC0_FLASHSZ_Pos               0
#define LM3S_SYSCTL_DC0_FLASHSZ_Msk              (0x000000FFUL /*<< LM3S_SYSCTL_DC0_FLASHSZ_Pos*/)

/* LM3S_SYSCTL DC1 Register Definitions */
#define LM3S_SYSCTL_DC1_WDT1_Pos                 28
#define LM3S_SYSCTL_DC1_WDT1_Msk                 (1UL << LM3S_SYSCTL_DC1_WDT1_Pos)

#define LM3S_SYSCTL_DC1_CAN1_Pos                 25
#define LM3S_SYSCTL_DC1_CAN1_Msk                 (1UL << LM3S_SYSCTL_DC1_CAN1_Pos)

#define LM3S_SYSCTL_DC1_CAN0_Pos                 24
#define LM3S_SYSCTL_DC1_CAN0_Msk                 (1UL << LM3S_SYSCTL_DC1_CAN0_Pos)

#define LM3S_SYSCTL_DC1_PWM_Pos                  20
#define LM3S_SYSCTL_DC1_PWM_Msk                  (1UL << LM3S_SYSCTL_DC1_PWM_Pos)

#define LM3S_SYSCTL_DC1_ADC1_Pos                 17
#define LM3S_SYSCTL_DC1_ADC1_Msk                 (1UL << LM3S_SYSCTL_DC1_ADC1_Pos)

#define LM3S_SYSCTL_DC1_ADC0_Pos                 16
#define LM3S_SYSCTL_DC1_ADC0_Msk                 (1UL << LM3S_SYSCTL_DC1_ADC0_Pos)

#define LM3S_SYSCTL_DC1_MINSYSDIV_Pos            12
#define LM3S_SYSCTL_DC1_MINSYSDIV_Msk            (0x0000000FUL << LM3S_SYSCTL_DC1_MINSYSDIV_Pos)

#define LM3S_SYSCTL_DC1_MAXADC1SPD_Pos           10
#define LM3S_SYSCTL_DC1_MAXADC1SPD_Msk           (0x00000003UL << LM3S_SYSCTL_DC1_MAXADC1SPD_Pos)

#define LM3S_SYSCTL_DC1_MAXADC0SPD_Pos            8
#define LM3S_SYSCTL_DC1_MAXADC0SPD_Msk           (0x00000003UL << LM3S_SYSCTL_DC1_MAXADC0SPD_Pos)

#define LM3S_SYSCTL_DC1_MPU_Pos                   7
#define LM3S_SYSCTL_DC1_MPU_Msk                  (1UL << LM3S_SYSCTL_DC1_MPU_Pos)

#define LM3S_SYSCTL_DC1_TEMPSNS_Pos               5
#define LM3S_SYSCTL_DC1_TEMPSNS_Msk              (1UL << LM3S_SYSCTL_DC1_TEMPSNS_Pos)

#define LM3S_SYSCTL_DC1_PLL_Pos                   4
#define LM3S_SYSCTL_DC1_PLL_Msk                  (1UL << LM3S_SYSCTL_DC1_PLL_Pos)

#define LM3S_SYSCTL_DC1_WDT0_Pos                  3
#define LM3S_SYSCTL_DC1_WDT0_Msk                 (1UL << LM3S_SYSCTL_DC1_WDT0_Pos)

#define LM3S_SYSCTL_DC1_SWO_Pos                   2
#define LM3S_SYSCTL_DC1_SWO_Msk                  (1UL << LM3S_SYSCTL_DC1_SWO_Pos)

#define LM3S_SYSCTL_DC1_SWD_Pos                   1
#define LM3S_SYSCTL_DC1_SWD_Msk                  (1UL << LM3S_SYSCTL_DC1_SWD_Pos)

#define LM3S_SYSCTL_DC1_JTAG_Pos                  0
#define LM3S_SYSCTL_DC1_JTAG_Msk                 (1UL /*<< LM3S_SYSCTL_DC1_JTAG_Pos*/)

/* LM3S_SYSCTL DC2 Register Definitions */
#define LM3S_SYSCTL_DC2_EPI0_Pos                 30
#define LM3S_SYSCTL_DC2_EPI0_Msk                 (1UL << LM3S_SYSCTL_DC2_EPI0_Pos)

#define LM3S_SYSCTL_DC2_I2S0_Pos                 28
#define LM3S_SYSCTL_DC2_I2S0_Msk                 (1UL << LM3S_SYSCTL_DC2_I2S0_Pos)

#define LM3S_SYSCTL_DC2_COMP2_Pos                26
#define LM3S_SYSCTL_DC2_COMP2_Msk                (1UL << LM3S_SYSCTL_DC2_COMP2_Pos)

#define LM3S_SYSCTL_DC2_COMP1_Pos                25
#define LM3S_SYSCTL_DC2_COMP1_Msk                (1UL << LM3S_SYSCTL_DC2_COMP1_Pos)

#define LM3S_SYSCTL_DC2_COMP0_Pos                24
#define LM3S_SYSCTL_DC2_COMP0_Msk                (1UL << LM3S_SYSCTL_DC2_COMP0_Pos)

#define LM3S_SYSCTL_DC2_TIMER3_Pos               19
#define LM3S_SYSCTL_DC2_TIMER3_Msk               (1UL << LM3S_SYSCTL_DC2_TIMER3_Pos)

#define LM3S_SYSCTL_DC2_TIMER2_Pos               18
#define LM3S_SYSCTL_DC2_TIMER2_Msk               (1UL << LM3S_SYSCTL_DC2_TIMER2_Pos)

#define LM3S_SYSCTL_DC2_TIMER1_Pos               17
#define LM3S_SYSCTL_DC2_TIMER1_Msk               (1UL << LM3S_SYSCTL_DC2_TIMER1_Pos)

#define LM3S_SYSCTL_DC2_TIMER0_Pos               16
#define LM3S_SYSCTL_DC2_TIMER0_Msk               (1UL << LM3S_SYSCTL_DC2_TIMER0_Pos)

#define LM3S_SYSCTL_DC2_I2C1_Pos                 14
#define LM3S_SYSCTL_DC2_I2C1_Msk                 (1UL << LM3S_SYSCTL_DC2_I2C1_Pos)

#define LM3S_SYSCTL_DC2_I2C0_Pos                 12
#define LM3S_SYSCTL_DC2_I2C0_Msk                 (1UL << LM3S_SYSCTL_DC2_I2C0_Pos)

#define LM3S_SYSCTL_DC2_QEI1_Pos                  9
#define LM3S_SYSCTL_DC2_QEI1_Msk                 (1UL << LM3S_SYSCTL_DC2_QEI1_Pos)

#define LM3S_SYSCTL_DC2_QEI0_Pos                  8
#define LM3S_SYSCTL_DC2_QEI0_Msk                 (1UL << LM3S_SYSCTL_DC2_QEI0_Pos)

#define LM3S_SYSCTL_DC2_SSI1_Pos                  5
#define LM3S_SYSCTL_DC2_SSI1_Msk                 (1UL << LM3S_SYSCTL_DC2_SSI1_Pos)

#define LM3S_SYSCTL_DC2_SSI0_Pos                  4
#define LM3S_SYSCTL_DC2_SSI0_Msk                 (1UL << LM3S_SYSCTL_DC2_SSI0_Pos)

#define LM3S_SYSCTL_DC2_UART2_Pos                 2
#define LM3S_SYSCTL_DC2_UART2_Msk                (1UL << LM3S_SYSCTL_DC2_UART2_Pos)

#define LM3S_SYSCTL_DC2_UART1_Pos                 1
#define LM3S_SYSCTL_DC2_UART1_Msk                (1UL << LM3S_SYSCTL_DC2_UART1_Pos)

#define LM3S_SYSCTL_DC2_UART0_Pos                 0
#define LM3S_SYSCTL_DC2_UART0_Msk                (1UL /*<< LM3S_SYSCTL_DC2_UART0_Pos*/)

/* LM3S_SYSCTL DC3 Register Definitions */
#define LM3S_SYSCTL_DC3_32KHZ_Pos                31
#define LM3S_SYSCTL_DC3_32KHZ_Msk                (1UL << LM3S_SYSCTL_DC3_32KHZ_Pos)

#define LM3S_SYSCTL_DC3_CCP5_Pos                 29
#define LM3S_SYSCTL_DC3_CCP5_Msk                 (1UL << LM3S_SYSCTL_DC3_CCP5_Pos)

#define LM3S_SYSCTL_DC3_CCP4_Pos                 28
#define LM3S_SYSCTL_DC3_CCP4_Msk                 (1UL << LM3S_SYSCTL_DC3_CCP4_Pos)

#define LM3S_SYSCTL_DC3_CCP3_Pos                 27
#define LM3S_SYSCTL_DC3_CCP3_Msk                 (1UL << LM3S_SYSCTL_DC3_CCP3_Pos)

#define LM3S_SYSCTL_DC3_CCP2_Pos                 26
#define LM3S_SYSCTL_DC3_CCP2_Msk                 (1UL << LM3S_SYSCTL_DC3_CCP2_Pos)

#define LM3S_SYSCTL_DC3_CCP1_Pos                 25
#define LM3S_SYSCTL_DC3_CCP1_Msk                 (1UL << LM3S_SYSCTL_DC3_CCP1_Pos)

#define LM3S_SYSCTL_DC3_CCP0_Pos                 24
#define LM3S_SYSCTL_DC3_CCP0_Msk                 (1UL << LM3S_SYSCTL_DC3_CCP0_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN7_Pos             23
#define LM3S_SYSCTL_DC3_ADC0AIN7_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN7_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN6_Pos             22
#define LM3S_SYSCTL_DC3_ADC0AIN6_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN6_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN5_Pos             21
#define LM3S_SYSCTL_DC3_ADC0AIN5_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN5_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN4_Pos             20
#define LM3S_SYSCTL_DC3_ADC0AIN4_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN4_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN3_Pos             19
#define LM3S_SYSCTL_DC3_ADC0AIN3_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN3_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN2_Pos             18
#define LM3S_SYSCTL_DC3_ADC0AIN2_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN2_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN1_Pos             17
#define LM3S_SYSCTL_DC3_ADC0AIN1_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN1_Pos)

#define LM3S_SYSCTL_DC3_ADC0AIN0_Pos             16
#define LM3S_SYSCTL_DC3_ADC0AIN0_Msk             (1UL << LM3S_SYSCTL_DC3_ADC0AIN0_Pos)

#define LM3S_SYSCTL_DC3_PWMFAULT_Pos             15
#define LM3S_SYSCTL_DC3_PWMFAULT_Msk             (1UL << LM3S_SYSCTL_DC3_PWMFAULT_Pos)

#define LM3S_SYSCTL_DC3_C2O_Pos                  14
#define LM3S_SYSCTL_DC3_C2O_Msk                  (1UL << LM3S_SYSCTL_DC3_C2O_Pos)

#define LM3S_SYSCTL_DC3_C2PLUS_Pos               13
#define LM3S_SYSCTL_DC3_C2PLUS_Msk               (1UL << LM3S_SYSCTL_DC3_C2PLUS_Pos)

#define LM3S_SYSCTL_DC3_C2MINUS_Pos              12
#define LM3S_SYSCTL_DC3_C2MINUS_Msk              (1UL << LM3S_SYSCTL_DC3_C2MINUS_Pos)

#define LM3S_SYSCTL_DC3_C1O_Pos                  11
#define LM3S_SYSCTL_DC3_C1O_Msk                  (1UL << LM3S_SYSCTL_DC3_C1O_Pos)

#define LM3S_SYSCTL_DC3_C1PLUS_Pos               10
#define LM3S_SYSCTL_DC3_C1PLUS_Msk               (1UL << LM3S_SYSCTL_DC3_C1PLUS_Pos)

#define LM3S_SYSCTL_DC3_C1MINUS_Pos               9
#define LM3S_SYSCTL_DC3_C1MINUS_Msk              (1UL << LM3S_SYSCTL_DC3_C1MINUS_Pos)

#define LM3S_SYSCTL_DC3_C0O_Pos                   8
#define LM3S_SYSCTL_DC3_C0O_Msk                  (1UL << LM3S_SYSCTL_DC3_C0O_Pos)

#define LM3S_SYSCTL_DC3_C0PLUS_Pos                7
#define LM3S_SYSCTL_DC3_C0PLUS_Msk               (1UL << LM3S_SYSCTL_DC3_C0PLUS_Pos)

#define LM3S_SYSCTL_DC3_C0MINUS_Pos               6
#define LM3S_SYSCTL_DC3_C0MINUS_Msk              (1UL << LM3S_SYSCTL_DC3_C0MINUS_Pos)

#define LM3S_SYSCTL_DC3_PWM5_Pos                  5
#define LM3S_SYSCTL_DC3_PWM5_Msk                 (1UL << LM3S_SYSCTL_DC3_PWM5_Pos)

#define LM3S_SYSCTL_DC3_PWM4_Pos                  4
#define LM3S_SYSCTL_DC3_PWM4_Msk                 (1UL << LM3S_SYSCTL_DC3_PWM4_Pos)

#define LM3S_SYSCTL_DC3_PWM3_Pos                  3
#define LM3S_SYSCTL_DC3_PWM3_Msk                 (1UL << LM3S_SYSCTL_DC3_PWM3_Pos)

#define LM3S_SYSCTL_DC3_PWM2_Pos                  2
#define LM3S_SYSCTL_DC3_PWM2_Msk                 (1UL << LM3S_SYSCTL_DC3_PWM2_Pos)

#define LM3S_SYSCTL_DC3_PWM1_Pos                  1
#define LM3S_SYSCTL_DC3_PWM1_Msk                 (1UL << LM3S_SYSCTL_DC3_PWM1_Pos)

#define LM3S_SYSCTL_DC3_PWM0_Pos                  0
#define LM3S_SYSCTL_DC3_PWM0_Msk                 (1UL /*<< LM3S_SYSCTL_DC3_PWM0_Pos*/)

/* LM3S_SYSCTL DC4 Register Definitions */
#define LM3S_SYSCTL_DC4_EPHY0_Pos                30
#define LM3S_SYSCTL_DC4_EPHY0_Msk                (1UL << LM3S_SYSCTL_DC4_EPHY0_Pos)

#define LM3S_SYSCTL_DC4_EMAC0_Pos                28
#define LM3S_SYSCTL_DC4_EMAC0_Msk                (1UL << LM3S_SYSCTL_DC4_EMAC0_Pos)

#define LM3S_SYSCTL_DC4_CCP7_Pos                 15
#define LM3S_SYSCTL_DC4_CCP7_Msk                 (1UL << LM3S_SYSCTL_DC4_CCP7_Pos)

#define LM3S_SYSCTL_DC4_CCP6_Pos                  14
#define LM3S_SYSCTL_DC4_CCP6_Msk                 (1UL << LM3S_SYSCTL_DC4_CCP6_Pos)

#define LM3S_SYSCTL_DC4_UDMA_Pos                 13
#define LM3S_SYSCTL_DC4_UDMA_Msk                 (1UL << LM3S_SYSCTL_DC4_UDMA_Pos)

#define LM3S_SYSCTL_DC4_ROM_Pos                  12
#define LM3S_SYSCTL_DC4_ROM_Msk                  (1UL << LM3S_SYSCTL_DC4_ROM_Pos)

#define LM3S_SYSCTL_DC4_GPIOJ_Pos                 8
#define LM3S_SYSCTL_DC4_GPIOJ_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOJ_Pos)

#define LM3S_SYSCTL_DC4_GPIOH_Pos                 7
#define LM3S_SYSCTL_DC4_GPIOH_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOH_Pos)

#define LM3S_SYSCTL_DC4_GPIOG_Pos                 6
#define LM3S_SYSCTL_DC4_GPIOG_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOG_Pos)

#define LM3S_SYSCTL_DC4_GPIOF_Pos                 5
#define LM3S_SYSCTL_DC4_GPIOF_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOF_Pos)

#define LM3S_SYSCTL_DC4_GPIOE_Pos                 4
#define LM3S_SYSCTL_DC4_GPIOE_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOE_Pos)

#define LM3S_SYSCTL_DC4_GPIOD_Pos                 3
#define LM3S_SYSCTL_DC4_GPIOD_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOD_Pos)

#define LM3S_SYSCTL_DC4_GPIOC_Pos                 2
#define LM3S_SYSCTL_DC4_GPIOC_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOC_Pos)

#define LM3S_SYSCTL_DC4_GPIOB_Pos                 1
#define LM3S_SYSCTL_DC4_GPIOB_Msk                (1UL << LM3S_SYSCTL_DC4_GPIOB_Pos)

#define LM3S_SYSCTL_DC4_GPIOA_Pos                 0
#define LM3S_SYSCTL_DC4_GPIOA_Msk                (1UL /*<< LM3S_SYSCTL_DC4_GPIOA_Pos*/)

/* LM3S_SYSCTL DC5 Register Definitions */
#define LM3S_SYSCTL_DC5_PWMFAULT3_Pos            27
#define LM3S_SYSCTL_DC5_PWMFAULT3_Msk            (1UL << LM3S_SYSCTL_DC5_PWMFAULT3_Pos)

#define LM3S_SYSCTL_DC5_PWMFAULT2_Pos            26
#define LM3S_SYSCTL_DC5_PWMFAULT2_Msk            (1UL << LM3S_SYSCTL_DC5_PWMFAULT2_Pos)

#define LM3S_SYSCTL_DC5_PWMFAULT1_Pos            25
#define LM3S_SYSCTL_DC5_PWMFAULT1_Msk            (1UL << LM3S_SYSCTL_DC5_PWMFAULT1_Pos)

#define LM3S_SYSCTL_DC5_PWMFAULT0_Pos            24
#define LM3S_SYSCTL_DC5_PWMFAULT0_Msk            (1UL << LM3S_SYSCTL_DC5_PWMFAULT0_Pos)

#define LM3S_SYSCTL_DC5_PWMEFLT_Pos              21
#define LM3S_SYSCTL_DC5_PWMEFLT_Msk              (1UL << LM3S_SYSCTL_DC5_PWMEFLT_Pos)

#define LM3S_SYSCTL_DC5_PWMESYNC_Pos             20
#define LM3S_SYSCTL_DC5_PWMESYNC_Msk             (1UL << LM3S_SYSCTL_DC5_PWMESYNC_Pos)

#define LM3S_SYSCTL_DC5_PWM7_Pos                  7
#define LM3S_SYSCTL_DC5_PWM7_Msk                 (1UL << LM3S_SYSCTL_DC5_PWM7_Pos)

#define LM3S_SYSCTL_DC5_PWM6_Pos                  6
#define LM3S_SYSCTL_DC5_PWM6_Msk                 (1UL << LM3S_SYSCTL_DC5_PWM6_Pos)

#define LM3S_SYSCTL_DC5_PWM5_Pos                  5
#define LM3S_SYSCTL_DC5_PWM5_Msk                 (1UL << LM3S_SYSCTL_DC5_PWM5_Pos)

#define LM3S_SYSCTL_DC5_PWM4_Pos                  4
#define LM3S_SYSCTL_DC5_PWM4_Msk                 (1UL << LM3S_SYSCTL_DC5_PWM4_Pos)

#define LM3S_SYSCTL_DC5_PWM3_Pos                  3
#define LM3S_SYSCTL_DC5_PWM3_Msk                 (1UL << LM3S_SYSCTL_DC5_PWM3_Pos)

#define LM3S_SYSCTL_DC5_PWM2_Pos                  2
#define LM3S_SYSCTL_DC5_PWM2_Msk                 (1UL << LM3S_SYSCTL_DC5_PWM2_Pos)

#define LM3S_SYSCTL_DC5_PWM1_Pos                  1
#define LM3S_SYSCTL_DC5_PWM1_Msk                 (1UL << LM3S_SYSCTL_DC5_PWM1_Pos)

#define LM3S_SYSCTL_DC5_PWM0_Pos                  0
#define LM3S_SYSCTL_DC5_PWM0_Msk                 (1UL /*<< LM3S_SYSCTL_DC5_PWM0_Pos*/)

/* LM3S_SYSCTL DC6 Register Definitions */
#define LM3S_SYSCTL_DC6_USB0PHY_Pos               4
#define LM3S_SYSCTL_DC6_USB0PHY_Msk              (1UL << LM3S_SYSCTL_DC6_USB0PHY_Pos)

#define LM3S_SYSCTL_DC6_USB0_Pos                  0
#define LM3S_SYSCTL_DC6_USB0_Msk                 (0x00000003UL /*<< LM3S_SYSCTL_DC6_USB0_Pos*/)

/* LM3S_SYSCTL DC7 Register Definitions */
#define LM3S_SYSCTL_DC7_DMACH30_Pos              30
#define LM3S_SYSCTL_DC7_DMACH30_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH30_Pos)

#define LM3S_SYSCTL_DC7_DMACH29_Pos              29
#define LM3S_SYSCTL_DC7_DMACH29_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH29_Pos)

#define LM3S_SYSCTL_DC7_DMACH28_Pos              28
#define LM3S_SYSCTL_DC7_DMACH28_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH28_Pos)

#define LM3S_SYSCTL_DC7_DMACH27_Pos              27
#define LM3S_SYSCTL_DC7_DMACH27_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH27_Pos)

#define LM3S_SYSCTL_DC7_DMACH26_Pos              26
#define LM3S_SYSCTL_DC7_DMACH26_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH26_Pos)

#define LM3S_SYSCTL_DC7_DMACH25_Pos              25
#define LM3S_SYSCTL_DC7_DMACH25_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH25_Pos)

#define LM3S_SYSCTL_DC7_DMACH24_Pos              24
#define LM3S_SYSCTL_DC7_DMACH24_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH24_Pos)

#define LM3S_SYSCTL_DC7_DMACH23_Pos              23
#define LM3S_SYSCTL_DC7_DMACH23_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH23_Pos)

#define LM3S_SYSCTL_DC7_DMACH22_Pos              22
#define LM3S_SYSCTL_DC7_DMACH22_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH22_Pos)

#define LM3S_SYSCTL_DC7_DMACH21_Pos              21
#define LM3S_SYSCTL_DC7_DMACH21_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH21_Pos)

#define LM3S_SYSCTL_DC7_DMACH20_Pos              20
#define LM3S_SYSCTL_DC7_DMACH20_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH20_Pos)

#define LM3S_SYSCTL_DC7_DMACH19_Pos              19
#define LM3S_SYSCTL_DC7_DMACH19_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH19_Pos)

#define LM3S_SYSCTL_DC7_DMACH18_Pos              18
#define LM3S_SYSCTL_DC7_DMACH18_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH18_Pos)

#define LM3S_SYSCTL_DC7_DMACH17_Pos              17
#define LM3S_SYSCTL_DC7_DMACH17_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH17_Pos)

#define LM3S_SYSCTL_DC7_DMACH16_Pos              16
#define LM3S_SYSCTL_DC7_DMACH16_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH16_Pos)

#define LM3S_SYSCTL_DC7_DMACH15_Pos              15
#define LM3S_SYSCTL_DC7_DMACH15_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH15_Pos)

#define LM3S_SYSCTL_DC7_DMACH14_Pos              14
#define LM3S_SYSCTL_DC7_DMACH14_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH14_Pos)

#define LM3S_SYSCTL_DC7_DMACH13_Pos              13
#define LM3S_SYSCTL_DC7_DMACH13_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH13_Pos)

#define LM3S_SYSCTL_DC7_DMACH12_Pos              12
#define LM3S_SYSCTL_DC7_DMACH12_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH12_Pos)

#define LM3S_SYSCTL_DC7_DMACH11_Pos              11
#define LM3S_SYSCTL_DC7_DMACH11_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH11_Pos)

#define LM3S_SYSCTL_DC7_DMACH10_Pos              10
#define LM3S_SYSCTL_DC7_DMACH10_Msk              (1UL << LM3S_SYSCTL_DC7_DMACH10_Pos)

#define LM3S_SYSCTL_DC7_DMACH9_Pos                9
#define LM3S_SYSCTL_DC7_DMACH9_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH9_Pos)

#define LM3S_SYSCTL_DC7_DMACH8_Pos                8
#define LM3S_SYSCTL_DC7_DMACH8_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH8_Pos)

#define LM3S_SYSCTL_DC7_DMACH7_Pos                7
#define LM3S_SYSCTL_DC7_DMACH7_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH7_Pos)

#define LM3S_SYSCTL_DC7_DMACH6_Pos                6
#define LM3S_SYSCTL_DC7_DMACH6_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH6_Pos)

#define LM3S_SYSCTL_DC7_DMACH5_Pos                5
#define LM3S_SYSCTL_DC7_DMACH5_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH5_Pos)

#define LM3S_SYSCTL_DC7_DMACH4_Pos                4
#define LM3S_SYSCTL_DC7_DMACH4_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH4_Pos)

#define LM3S_SYSCTL_DC7_DMACH3_Pos                3
#define LM3S_SYSCTL_DC7_DMACH3_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH3_Pos)

#define LM3S_SYSCTL_DC7_DMACH2_Pos                2
#define LM3S_SYSCTL_DC7_DMACH2_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH2_Pos)

#define LM3S_SYSCTL_DC7_DMACH1_Pos                1
#define LM3S_SYSCTL_DC7_DMACH1_Msk               (1UL << LM3S_SYSCTL_DC7_DMACH1_Pos)

#define LM3S_SYSCTL_DC7_DMACH0_Pos                0
#define LM3S_SYSCTL_DC7_DMACH0_Msk               (1UL /*<< LM3S_SYSCTL_DC7_DMACH0_Pos*/)

/* LM3S_SYSCTL DC8 Register Definitions */
#define LM3S_SYSCTL_DC8_ADC1AIN15_Pos             31
#define LM3S_SYSCTL_DC8_ADC1AIN15_Msk            (1UL << LM3S_SYSCTL_DC8_ADC1AIN15_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN14_Pos            30
#define LM3S_SYSCTL_DC8_ADC1AIN14Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN14_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN13_Pos            29
#define LM3S_SYSCTL_DC8_ADC1AIN13_Msk            (1UL << LM3S_SYSCTL_DC8_ADC1AIN13_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN12_Pos            28
#define LM3S_SYSCTL_DC8_ADC1AIN12_Msk            (1UL << LM3S_SYSCTL_DC8_ADC1AIN12_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN11_Pos            27
#define LM3S_SYSCTL_DC8_ADC1AIN11_Msk            (1UL << LM3S_SYSCTL_DC8_ADC1AIN11_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN10_Pos            26
#define LM3S_SYSCTL_DC8_ADC1AIN10_Msk            (1UL << LM3S_SYSCTL_DC8_ADC1AIN10_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN9_Pos             25
#define LM3S_SYSCTL_DC8_ADC1AIN9_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN9_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN8_Pos             24
#define LM3S_SYSCTL_DC8_ADC1AIN8_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN8_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN7_Pos             23
#define LM3S_SYSCTL_DC8_ADC1AIN7_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN7_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN6_Pos             22
#define LM3S_SYSCTL_DC8_ADC1AIN6_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN6_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN5_Pos             21
#define LM3S_SYSCTL_DC8_ADC1AIN5_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN5_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN4_Pos             20
#define LM3S_SYSCTL_DC8_ADC1AIN4_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN4_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN3_Pos             19
#define LM3S_SYSCTL_DC8_ADC1AIN3_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN3_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN2_Pos             18
#define LM3S_SYSCTL_DC8_ADC1AIN2_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN2_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN1_Pos             17
#define LM3S_SYSCTL_DC8_ADC1AIN1_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN1_Pos)

#define LM3S_SYSCTL_DC8_ADC1AIN0_Pos             16
#define LM3S_SYSCTL_DC8_ADC1AIN0_Msk             (1UL << LM3S_SYSCTL_DC8_ADC1AIN0_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN15_Pos            15
#define LM3S_SYSCTL_DC8_ADC0AIN15_Msk            (1UL << LM3S_SYSCTL_DC8_ADC0AIN15_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN14_Pos            14
#define LM3S_SYSCTL_DC8_ADC0AIN14_Msk            (1UL << LM3S_SYSCTL_DC8_ADC0AIN14_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN13_Pos            13
#define LM3S_SYSCTL_DC8_ADC0AIN13_Msk            (1UL << LM3S_SYSCTL_DC8_ADC0AIN13_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN12_Pos            12
#define LM3S_SYSCTL_DC8_ADC0AIN12_Msk            (1UL << LM3S_SYSCTL_DC8_ADC0AIN12_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN11_Pos            11
#define LM3S_SYSCTL_DC8_ADC0AIN11_Msk            (1UL << LM3S_SYSCTL_DC8_ADC0AIN11_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN10_Pos            10
#define LM3S_SYSCTL_DC8_ADC0AIN10_Msk            (1UL << LM3S_SYSCTL_DC8_ADC0AIN10_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN9_Pos              9
#define LM3S_SYSCTL_DC8_ADC0AIN9_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN9_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN8_Pos              8
#define LM3S_SYSCTL_DC8_ADC0AIN8_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN8_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN7_Pos              7
#define LM3S_SYSCTL_DC8_ADC0AIN7_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN7_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN6_Pos              6
#define LM3S_SYSCTL_DC8_ADC0AIN6_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN6_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN5_Pos              5
#define LM3S_SYSCTL_DC8_ADC0AIN5_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN5_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN4_Pos              4
#define LM3S_SYSCTL_DC8_ADC0AIN4_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN4_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN3_Pos              3
#define LM3S_SYSCTL_DC8_ADC0AIN3_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN3_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN2_Pos              2
#define LM3S_SYSCTL_DC8_ADC0AIN2_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN2_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN1_Pos              1
#define LM3S_SYSCTL_DC8_ADC0AIN1_Msk             (1UL << LM3S_SYSCTL_DC8_ADC0AIN1_Pos)

#define LM3S_SYSCTL_DC8_ADC0AIN0_Pos              0
#define LM3S_SYSCTL_DC8_ADC0AIN0_Msk             (1UL /*<< LM3S_SYSCTL_DC8_ADC0AIN0_Pos*/)

/* LM3S_SYSCTL DC9 Register Definitions */
#define LM3S_SYSCTL_DC9_ADC1DC7_Pos              23
#define LM3S_SYSCTL_DC9_ADC1DC7_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC7_Pos)

#define LM3S_SYSCTL_DC9_ADC1DC6_Pos              22
#define LM3S_SYSCTL_DC9_ADC1DC6_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC6_Pos)

#define LM3S_SYSCTL_DC9_ADC1DC5_Pos              21
#define LM3S_SYSCTL_DC9_ADC1DC5_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC5_Pos)

#define LM3S_SYSCTL_DC9_ADC1DC4_Pos              20
#define LM3S_SYSCTL_DC9_ADC1DC4_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC4_Pos)

#define LM3S_SYSCTL_DC9_ADC1DC3_Pos              19
#define LM3S_SYSCTL_DC9_ADC1DC3_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC3_Pos)

#define LM3S_SYSCTL_DC9_ADC1DC2_Pos              18
#define LM3S_SYSCTL_DC9_ADC1DC2_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC2_Pos)

#define LM3S_SYSCTL_DC9_ADC1DC1_Pos              17
#define LM3S_SYSCTL_DC9_ADC1DC1_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC1_Pos)

#define LM3S_SYSCTL_DC9_ADC1DC0_Pos              16
#define LM3S_SYSCTL_DC9_ADC1DC0_Msk              (1UL << LM3S_SYSCTL_DC9_ADC1DC0_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC7_Pos               7
#define LM3S_SYSCTL_DC9_ADC0DC7_Msk              (1UL << LM3S_SYSCTL_DC9_ADC0DC7_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC6_Pos               6
#define LM3S_SYSCTL_DC9_ADC0DC6_Msk              (1UL << LM3S_SYSCTL_DC9_ADC0DC6_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC5_Pos               5
#define LM3S_SYSCTL_DC9_ADC0DC5_Msk              (1UL << LM3S_SYSCTL_DC9_ADC0DC5_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC4_Pos               4
#define LM3S_SYSCTL_DC9_ADC0DC4_Msk              (1UL << LM3S_SYSCTL_DC9_ADC0DC4_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC3_Pos               3
#define LM3S_SYSCTL_DC9_ADC0DC3_Msk              (1UL << LM3S_SYSCTL_DC9_ADC0DC3_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC2_Pos               2
#define LM3S_SYSCTL_DC9_ADC0DC2_Msk              (1UL << LM3S_SYSCTL_DC9_ADC0DC2_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC1_Pos               1
#define LM3S_SYSCTL_DC9_ADC0DC1_Msk              (1UL << LM3S_SYSCTL_DC9_ADC0DC1_Pos)

#define LM3S_SYSCTL_DC9_ADC0DC0_Pos               0
#define LM3S_SYSCTL_DC9_ADC0DC0_Msk              (1UL /*<< LM3S_SYSCTL_DC9_ADC0DC0_Pos*/)

/* LM3S_SYSCTL NVMSTAT Register Definitions */
#define LM3S_SYSCTL_NVMSTAT_FWB_Pos               0
#define LM3S_SYSCTL_NVMSTAT_FWB_Msk              (1UL /*<< LM3S_SYSCTL_NVMSTAT_FWB_Pos*/)

/* LM3S_SYSCTL RCGC0 Register Definitions */
#define LM3S_SYSCTL_RCGC0_WDT1_Pos               28
#define LM3S_SYSCTL_RCGC0_WDT1_Msk               (1UL << LM3S_SYSCTL_RCGC0_WDT1_Pos)

#define LM3S_SYSCTL_RCGC0_CAN1_Pos               25
#define LM3S_SYSCTL_RCGC0_CAN1_Msk               (1UL << LM3S_SYSCTL_RCGC0_CAN1_Pos)

#define LM3S_SYSCTL_RCGC0_CAN0_Pos               25
#define LM3S_SYSCTL_RCGC0_CAN0_Msk               (1UL << LM3S_SYSCTL_RCGC0_CAN0_Pos)

#define LM3S_SYSCTL_RCGC0_PWM_Pos                20
#define LM3S_SYSCTL_RCGC0_PWM_Msk                (1UL << LM3S_SYSCTL_RCGC0_PWM_Pos)

#define LM3S_SYSCTL_RCGC0_ADC1_Pos               17
#define LM3S_SYSCTL_RCGC0_ADC1_Msk               (1UL << LM3S_SYSCTL_RCGC0_ADC1_Pos)

#define LM3S_SYSCTL_RCGC0_ADC0_Pos               16
#define LM3S_SYSCTL_RCGC0_ADC0_Msk               (1UL << LM3S_SYSCTL_RCGC0_ADC0_Pos)

#define LM3S_SYSCTL_RCGC0_MAXADC1SPD_Pos         10
#define LM3S_SYSCTL_RCGC0_MAXADC1SPD_Msk         (0x00000003UL << LM3S_SYSCTL_RCGC0_MAXADC1SPD_Pos)
#define LM3S_SYSCTL_RCGC0_MAXADC1SPD_1_Pos       11
#define LM3S_SYSCTL_RCGC0_MAXADC1SPD_1_Msk       (1UL << LM3S_SYSCTL_RCGC0_MAXADC1SPD_1_Pos)
#define LM3S_SYSCTL_RCGC0_MAXADC1SPD_0_Pos       10
#define LM3S_SYSCTL_RCGC0_MAXADC1SPD_0_Msk       (1UL << LM3S_SYSCTL_RCGC0_MAXADC1SPD_0_Pos)

#define LM3S_SYSCTL_RCGC0_MAXADC0SPD_Pos          8
#define LM3S_SYSCTL_RCGC0_MAXADC0SPD_Msk         (0x00000003UL << LM3S_SYSCTL_RCGC0_MAXADC0SPD_Pos)
#define LM3S_SYSCTL_RCGC0_MAXADC0SPD_1_Pos        9
#define LM3S_SYSCTL_RCGC0_MAXADC0SPD_1_Msk       (1UL << LM3S_SYSCTL_RCGC0_MAXADC0SPD_1_Pos)
#define LM3S_SYSCTL_RCGC0_MAXADC0SPD_0_Pos        8
#define LM3S_SYSCTL_RCGC0_MAXADC0SPD_0_Msk       (1UL << LM3S_SYSCTL_RCGC0_MAXADC0SPD_0_Pos)

#define LM3S_SYSCTL_RCGC0_WDT0_Pos                2
#define LM3S_SYSCTL_RCGC0_WDT0_Msk               (1UL << LM3S_SYSCTL_RCGC0_WDT0_Pos)

/* LM3S_SYSCTL SCGC0 Register Definitions */
#define LM3S_SYSCTL_SCGC0_WDT1_Pos               28
#define LM3S_SYSCTL_SCGC0_WDT1_Msk               (1UL << LM3S_SYSCTL_SCGC0_WDT1_Pos)

#define LM3S_SYSCTL_SCGC0_CAN1_Pos               25
#define LM3S_SYSCTL_SCGC0_CAN1_Msk               (1UL << LM3S_SYSCTL_SCGC0_CAN1_Pos)

#define LM3S_SYSCTL_SCGC0_CAN0_Pos               25
#define LM3S_SYSCTL_SCGC0_CAN0_Msk               (1UL << LM3S_SYSCTL_SCGC0_CAN0_Pos)

#define LM3S_SYSCTL_SCGC0_PWM_Pos                20
#define LM3S_SYSCTL_SCGC0_PWM_Msk                (1UL << LM3S_SYSCTL_SCGC0_PWM_Pos)

#define LM3S_SYSCTL_SCGC0_ADC1_Pos               17
#define LM3S_SYSCTL_SCGC0_ADC1_Msk               (1UL << LM3S_SYSCTL_SCGC0_ADC1_Pos)

#define LM3S_SYSCTL_SCGC0_ADC0_Pos               16
#define LM3S_SYSCTL_SCGC0_ADC0_Msk               (1UL << LM3S_SYSCTL_SCGC0_ADC0_Pos)

#define LM3S_SYSCTL_SCGC0_MAXADC1SPD_Pos         10
#define LM3S_SYSCTL_SCGC0_MAXADC1SPD_Msk         (0x00000003UL << LM3S_SYSCTL_SCGC0_MAXADC1SPD_Pos)
#define LM3S_SYSCTL_SCGC0_MAXADC1SPD_1_Pos       11
#define LM3S_SYSCTL_SCGC0_MAXADC1SPD_1_Msk       (1UL << LM3S_SYSCTL_SCGC0_MAXADC1SPD_1_Pos)
#define LM3S_SYSCTL_SCGC0_MAXADC1SPD_0_Pos       10
#define LM3S_SYSCTL_SCGC0_MAXADC1SPD_0_Msk       (1UL << LM3S_SYSCTL_SCGC0_MAXADC1SPD_0_Pos)

#define LM3S_SYSCTL_SCGC0_MAXADC0SPD_Pos          8
#define LM3S_SYSCTL_SCGC0_MAXADC0SPD_Msk         (0x00000003UL << LM3S_SYSCTL_SCGC0_MAXADC0SPD_Pos)
#define LM3S_SYSCTL_SCGC0_MAXADC0SPD_1_Pos        9
#define LM3S_SYSCTL_SCGC0_MAXADC0SPD_1_Msk       (1UL << LM3S_SYSCTL_SCGC0_MAXADC0SPD_1_Pos)
#define LM3S_SYSCTL_SCGC0_MAXADC0SPD_0_Pos        8
#define LM3S_SYSCTL_SCGC0_MAXADC0SPD_0_Msk       (1UL << LM3S_SYSCTL_SCGC0_MAXADC0SPD_0_Pos)

#define LM3S_SYSCTL_SCGC0_WDT0_Pos                2
#define LM3S_SYSCTL_SCGC0_WDT0_Msk               (1UL << LM3S_SYSCTL_SCGC0_WDT0_Pos)

/* LM3S_SYSCTL DCGC0 Register Definitions */
#define LM3S_SYSCTL_DCGC0_WDT1_Pos               28
#define LM3S_SYSCTL_DCGC0_WDT1_Msk               (1UL << LM3S_SYSCTL_DCGC0_WDT1_Pos)

#define LM3S_SYSCTL_DCGC0_CAN1_Pos               25
#define LM3S_SYSCTL_DCGC0_CAN1_Msk               (1UL << LM3S_SYSCTL_DCGC0_CAN1_Pos)

#define LM3S_SYSCTL_DCGC0_CAN0_Pos               24
#define LM3S_SYSCTL_DCGC0_CAN0_Msk               (1UL << LM3S_SYSCTL_DCGC0_CAN0_Pos)

#define LM3S_SYSCTL_DCGC0_PWM_Pos                20
#define LM3S_SYSCTL_DCGC0_PWM_Msk                (1UL << LM3S_SYSCTL_DCGC0_PWM_Pos)

#define LM3S_SYSCTL_DCGC0_ADC1_Pos               17
#define LM3S_SYSCTL_DCGC0_ADC1_Msk               (1UL << LM3S_SYSCTL_DCGC0_ADC1_Pos)

#define LM3S_SYSCTL_DCGC0_ADC0_Pos               16
#define LM3S_SYSCTL_DCGC0_ADC0_Msk               (1UL << LM3S_SYSCTL_DCGC0_ADC0_Pos)

#define LM3S_SYSCTL_DCGC0_WDT0_Pos                2
#define LM3S_SYSCTL_DCGC0_WDT0_Msk               (1UL << LM3S_SYSCTL_DCGC0_WDT0_Pos)

/* LM3S_SYSCTL RCGC1 Register Definitions */
#define LM3S_SYSCTL_RCGC1_EPI0_Pos               30
#define LM3S_SYSCTL_RCGC1_EPI0_Msk               (1UL << LM3S_SYSCTL_RCGC1_EPI0_Pos)

#define LM3S_SYSCTL_RCGC1_I2S0_Pos               28
#define LM3S_SYSCTL_RCGC1_I2S0_Msk               (1UL << LM3S_SYSCTL_RCGC1_I2S0_Pos)

#define LM3S_SYSCTL_RCGC1_COMP2_Pos              26
#define LM3S_SYSCTL_RCGC1_COMP2_Msk              (1UL << LM3S_SYSCTL_RCGC1_COMP2_Pos)

#define LM3S_SYSCTL_RCGC1_COMP1_Pos              25
#define LM3S_SYSCTL_RCGC1_COMP1_Msk              (1UL << LM3S_SYSCTL_RCGC1_COMP1_Pos)

#define LM3S_SYSCTL_RCGC1_COMP0_Pos              24
#define LM3S_SYSCTL_RCGC1_COMP0_Msk              (1UL << LM3S_SYSCTL_RCGC1_COMP0_Pos)

#define LM3S_SYSCTL_RCGC1_TIMER3_Pos             19
#define LM3S_SYSCTL_RCGC1_TIMER3_Msk             (1UL << LM3S_SYSCTL_RCGC1_TIMER3_Pos)

#define LM3S_SYSCTL_RCGC1_TIMER2_Pos             18
#define LM3S_SYSCTL_RCGC1_TIMER2_Msk             (1UL << LM3S_SYSCTL_RCGC1_TIMER2_Pos)

#define LM3S_SYSCTL_RCGC1_TIMER1_Pos             17
#define LM3S_SYSCTL_RCGC1_TIMER1_Msk             (1UL << LM3S_SYSCTL_RCGC1_TIMER1_Pos)

#define LM3S_SYSCTL_RCGC1_TIMER0_Pos             16
#define LM3S_SYSCTL_RCGC1_TIMER0_Msk             (1UL << LM3S_SYSCTL_RCGC1_TIMER0_Pos)

#define LM3S_SYSCTL_RCGC1_I2C1_Pos               14
#define LM3S_SYSCTL_RCGC1_I2C1_Msk               (1UL << LM3S_SYSCTL_RCGC1_I2C1_Pos)

#define LM3S_SYSCTL_RCGC1_I2C0_Pos               12
#define LM3S_SYSCTL_RCGC1_I2C0_Msk               (1UL << LM3S_SYSCTL_RCGC1_I2C0_Pos)

#define LM3S_SYSCTL_RCGC1_QEI1_Pos                9
#define LM3S_SYSCTL_RCGC1_QEI1_Msk               (1UL << LM3S_SYSCTL_RCGC1_QEI1_Pos)

#define LM3S_SYSCTL_RCGC1_QEI0_Pos                8
#define LM3S_SYSCTL_RCGC1_QEI0_Msk               (1UL << LM3S_SYSCTL_RCGC1_QEI0_Pos)

#define LM3S_SYSCTL_RCGC1_SSI1_Pos                5
#define LM3S_SYSCTL_RCGC1_SSI1_Msk               (1UL << LM3S_SYSCTL_RCGC1_SSI1_Pos)

#define LM3S_SYSCTL_RCGC1_SSI0_Pos                4
#define LM3S_SYSCTL_RCGC1_SSI0_Msk               (1UL << LM3S_SYSCTL_RCGC1_SSI0_Pos)

#define LM3S_SYSCTL_RCGC1_UART2_Pos               2
#define LM3S_SYSCTL_RCGC1_UART2_Msk              (1UL << LM3S_SYSCTL_RCGC1_UART2_Pos)

#define LM3S_SYSCTL_RCGC1_UART1_Pos               1
#define LM3S_SYSCTL_RCGC1_UART1_Msk              (1UL << LM3S_SYSCTL_RCGC1_UART1_Pos)

#define LM3S_SYSCTL_RCGC1_UART0_Pos               0
#define LM3S_SYSCTL_RCGC1_UART0_Msk              (1UL /*<< LM3S_SYSCTL_RCGC1_UART0_Pos*/)

/* LM3S_SYSCTL SCGC1 Register Definitions */
#define LM3S_SYSCTL_SCGC1_EPI0_Pos               30
#define LM3S_SYSCTL_SCGC1_EPI0_Msk               (1UL << LM3S_SYSCTL_SCGC1_EPI0_Pos)

#define LM3S_SYSCTL_SCGC1_I2S0_Pos               28
#define LM3S_SYSCTL_SCGC1_I2S0_Msk               (1UL << LM3S_SYSCTL_SCGC1_I2S0_Pos)

#define LM3S_SYSCTL_SCGC1_COMP2_Pos              26
#define LM3S_SYSCTL_SCGC1_COMP2_Msk              (1UL << LM3S_SYSCTL_SCGC1_COMP2_Pos)

#define LM3S_SYSCTL_SCGC1_COMP1_Pos              25
#define LM3S_SYSCTL_SCGC1_COMP1_Msk              (1UL << LM3S_SYSCTL_SCGC1_COMP1_Pos)

#define LM3S_SYSCTL_SCGC1_COMP0_Pos              24
#define LM3S_SYSCTL_SCGC1_COMP0_Msk              (1UL << LM3S_SYSCTL_SCGC1_COMP0_Pos)

#define LM3S_SYSCTL_SCGC1_TIMER3_Pos             19
#define LM3S_SYSCTL_SCGC1_TIMER3_Msk             (1UL << LM3S_SYSCTL_SCGC1_TIMER3_Pos)

#define LM3S_SYSCTL_SCGC1_TIMER2_Pos             18
#define LM3S_SYSCTL_SCGC1_TIMER2_Msk             (1UL << LM3S_SYSCTL_SCGC1_TIMER2_Pos)

#define LM3S_SYSCTL_SCGC1_TIMER1_Pos             17
#define LM3S_SYSCTL_SCGC1_TIMER1_Msk             (1UL << LM3S_SYSCTL_SCGC1_TIMER1_Pos)

#define LM3S_SYSCTL_SCGC1_TIMER0_Pos             16
#define LM3S_SYSCTL_SCGC1_TIMER0_Msk             (1UL << LM3S_SYSCTL_SCGC1_TIMER0_Pos)

#define LM3S_SYSCTL_SCGC1_I2C1_Pos               14
#define LM3S_SYSCTL_SCGC1_I2C1_Msk               (1UL << LM3S_SYSCTL_SCGC1_I2C1_Pos)

#define LM3S_SYSCTL_SCGC1_I2C0_Pos               12
#define LM3S_SYSCTL_SCGC1_I2C0_Msk               (1UL << LM3S_SYSCTL_SCGC1_I2C0_Pos)

#define LM3S_SYSCTL_SCGC1_QEI1_Pos                9
#define LM3S_SYSCTL_SCGC1_QEI1_Msk               (1UL << LM3S_SYSCTL_SCGC1_QEI1_Pos)

#define LM3S_SYSCTL_SCGC1_QEI0_Pos                8
#define LM3S_SYSCTL_SCGC1_QEI0_Msk               (1UL << LM3S_SYSCTL_SCGC1_QEI0_Pos)

#define LM3S_SYSCTL_SCGC1_SSI1_Pos                5
#define LM3S_SYSCTL_SCGC1_SSI1_Msk               (1UL << LM3S_SYSCTL_SCGC1_SSI1_Pos)

#define LM3S_SYSCTL_SCGC1_SSI0_Pos                4
#define LM3S_SYSCTL_SCGC1_SSI0_Msk               (1UL << LM3S_SYSCTL_SCGC1_SSI0_Pos)

#define LM3S_SYSCTL_SCGC1_UART2_Pos               2
#define LM3S_SYSCTL_SCGC1_UART2_Msk              (1UL << LM3S_SYSCTL_SCGC1_UART2_Pos)

#define LM3S_SYSCTL_SCGC1_UART1_Pos               1
#define LM3S_SYSCTL_SCGC1_UART1_Msk              (1UL << LM3S_SYSCTL_SCGC1_UART1_Pos)

#define LM3S_SYSCTL_SCGC1_UART0_Pos               0
#define LM3S_SYSCTL_SCGC1_UART0_Msk              (1UL /*<< LM3S_SYSCTL_SCGC1_UART0_Pos*/)

/* LM3S_SYSCTL DCGC1 Register Definitions */
#define LM3S_SYSCTL_DCGC1_EPI0_Pos               30
#define LM3S_SYSCTL_DCGC1_EPI0_Msk               (1UL << LM3S_SYSCTL_DCGC1_EPI0_Pos)

#define LM3S_SYSCTL_DCGC1_I2S0_Pos               28
#define LM3S_SYSCTL_DCGC1_I2S0_Msk               (1UL << LM3S_SYSCTL_DCGC1_I2S0_Pos)

#define LM3S_SYSCTL_DCGC1_COMP2_Pos              26
#define LM3S_SYSCTL_DCGC1_COMP2_Msk              (1UL << LM3S_SYSCTL_DCGC1_COMP2_Pos)

#define LM3S_SYSCTL_DCGC1_COMP1_Pos              25
#define LM3S_SYSCTL_DCGC1_COMP1_Msk              (1UL << LM3S_SYSCTL_DCGC1_COMP1_Pos)

#define LM3S_SYSCTL_DCGC1_COMP0_Pos              24
#define LM3S_SYSCTL_DCGC1_COMP0_Msk              (1UL << LM3S_SYSCTL_DCGC1_COMP0_Pos)

#define LM3S_SYSCTL_DCGC1_TIMER3_Pos             19
#define LM3S_SYSCTL_DCGC1_TIMER3_Msk             (1UL << LM3S_SYSCTL_DCGC1_TIMER3_Pos)

#define LM3S_SYSCTL_DCGC1_TIMER2_Pos             18
#define LM3S_SYSCTL_DCGC1_TIMER2_Msk             (1UL << LM3S_SYSCTL_DCGC1_TIMER2_Pos)

#define LM3S_SYSCTL_DCGC1_TIMER1_Pos             17
#define LM3S_SYSCTL_DCGC1_TIMER1_Msk             (1UL << LM3S_SYSCTL_DCGC1_TIMER1_Pos)

#define LM3S_SYSCTL_DCGC1_TIMER0_Pos             16
#define LM3S_SYSCTL_DCGC1_TIMER0_Msk             (1UL << LM3S_SYSCTL_DCGC1_TIMER0_Pos)

#define LM3S_SYSCTL_DCGC1_I2C1_Pos               14
#define LM3S_SYSCTL_DCGC1_I2C1_Msk               (1UL << LM3S_SYSCTL_DCGC1_I2C1_Pos)

#define LM3S_SYSCTL_DCGC1_I2C0_Pos               12
#define LM3S_SYSCTL_DCGC1_I2C0_Msk               (1UL << LM3S_SYSCTL_DCGC1_I2C0_Pos)

#define LM3S_SYSCTL_DCGC1_QEI1_Pos                9
#define LM3S_SYSCTL_DCGC1_QEI1_Msk               (1UL << LM3S_SYSCTL_DCGC1_QEI1_Pos)

#define LM3S_SYSCTL_DCGC1_QEI0_Pos                8
#define LM3S_SYSCTL_DCGC1_QEI0_Msk               (1UL << LM3S_SYSCTL_DCGC1_QEI0_Pos)

#define LM3S_SYSCTL_DCGC1_SSI1_Pos                5
#define LM3S_SYSCTL_DCGC1_SSI1_Msk               (1UL << LM3S_SYSCTL_DCGC1_SSI1_Pos)

#define LM3S_SYSCTL_DCGC1_SSI0_Pos                4
#define LM3S_SYSCTL_DCGC1_SSI0_Msk               (1UL << LM3S_SYSCTL_DCGC1_SSI0_Pos)

#define LM3S_SYSCTL_DCGC1_UART2_Pos               2
#define LM3S_SYSCTL_DCGC1_UART2_Msk              (1UL << LM3S_SYSCTL_DCGC1_UART2_Pos)

#define LM3S_SYSCTL_DCGC1_UART1_Pos               1
#define LM3S_SYSCTL_DCGC1_UART1_Msk              (1UL << LM3S_SYSCTL_DCGC1_UART1_Pos)

#define LM3S_SYSCTL_DCGC1_UART0_Pos               0
#define LM3S_SYSCTL_DCGC1_UART0_Msk              (1UL /*<< LM3S_SYSCTL_DCGC1_UART0_Pos*/)

/* LM3S_SYSCTL RCGC2 Register Definitions */
#define LM3S_SYSCTL_RCGC2_EPHY0_Pos              30
#define LM3S_SYSCTL_RCGC2_EPHY0_Msk              (1UL << LM3S_SYSCTL_RCGC2_EPHY0_Pos)

#define LM3S_SYSCTL_RCGC2_EMAC0_Pos              28
#define LM3S_SYSCTL_RCGC2_EMAC0_Msk              (1UL << LM3S_SYSCTL_RCGC2_EMAC0_Pos)

#define LM3S_SYSCTL_RCGC2_USB0_Pos               16
#define LM3S_SYSCTL_RCGC2_USB0_Msk               (1UL << LM3S_SYSCTL_RCGC2_USB0_Pos)

#define LM3S_SYSCTL_RCGC2_UDMA_Pos               13
#define LM3S_SYSCTL_RCGC2_UDMA_Msk               (1UL << LM3S_SYSCTL_RCGC2_UDMA_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOJ_Pos               8
#define LM3S_SYSCTL_RCGC2_GPIOJ_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOJ_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOH_Pos               7
#define LM3S_SYSCTL_RCGC2_GPIOH_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOH_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOG_Pos               6
#define LM3S_SYSCTL_RCGC2_GPIOG_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOG_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOF_Pos               5
#define LM3S_SYSCTL_RCGC2_GPIOF_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOF_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOE_Pos               4
#define LM3S_SYSCTL_RCGC2_GPIOE_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOE_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOD_Pos               3
#define LM3S_SYSCTL_RCGC2_GPIOD_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOD_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOC_Pos               2
#define LM3S_SYSCTL_RCGC2_GPIOC_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOC_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOB_Pos               1
#define LM3S_SYSCTL_RCGC2_GPIOB_Msk              (1UL << LM3S_SYSCTL_RCGC2_GPIOB_Pos)

#define LM3S_SYSCTL_RCGC2_GPIOA_Pos               0
#define LM3S_SYSCTL_RCGC2_GPIOA_Msk              (1UL /*<< LM3S_SYSCTL_RCGC2_GPIOA_Pos*/)

/* LM3S_SYSCTL SCGC2 Register Definitions */
#define LM3S_SYSCTL_SCGC2_EPHY0_Pos              30
#define LM3S_SYSCTL_SCGC2_EPHY0_Msk              (1UL << LM3S_SYSCTL_SCGC2_EPHY0_Pos)

#define LM3S_SYSCTL_SCGC2_EMAC0_Pos              28
#define LM3S_SYSCTL_SCGC2_EMAC0_Msk              (1UL << LM3S_SYSCTL_SCGC2_EMAC0_Pos)

#define LM3S_SYSCTL_SCGC2_USB0_Pos               16
#define LM3S_SYSCTL_SCGC2_USB0_Msk               (1UL << LM3S_SYSCTL_SCGC2_USB0_Pos)

#define LM3S_SYSCTL_SCGC2_UDMA_Pos               13
#define LM3S_SYSCTL_SCGC2_UDMA_Msk               (1UL << LM3S_SYSCTL_SCGC2_UDMA_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOJ_Pos               8
#define LM3S_SYSCTL_SCGC2_GPIOJ_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOJ_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOH_Pos               7
#define LM3S_SYSCTL_SCGC2_GPIOH_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOH_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOG_Pos               6
#define LM3S_SYSCTL_SCGC2_GPIOG_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOG_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOF_Pos               5
#define LM3S_SYSCTL_SCGC2_GPIOF_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOF_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOE_Pos               4
#define LM3S_SYSCTL_SCGC2_GPIOE_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOE_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOD_Pos               3
#define LM3S_SYSCTL_SCGC2_GPIOD_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOD_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOC_Pos               2
#define LM3S_SYSCTL_SCGC2_GPIOC_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOC_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOB_Pos               1
#define LM3S_SYSCTL_SCGC2_GPIOB_Msk              (1UL << LM3S_SYSCTL_SCGC2_GPIOB_Pos)

#define LM3S_SYSCTL_SCGC2_GPIOA_Pos               0
#define LM3S_SYSCTL_SCGC2_GPIOA_Msk              (1UL /*<< LM3S_SYSCTL_SCGC2_GPIOA_Pos*/)

/* LM3S_SYSCTL DCGC2 Register Definitions */
#define LM3S_SYSCTL_DCGC2_EPHY0_Pos              30
#define LM3S_SYSCTL_DCGC2_EPHY0_Msk              (1UL << LM3S_SYSCTL_DCGC2_EPHY0_Pos)

#define LM3S_SYSCTL_DCGC2_EMAC0_Pos              28
#define LM3S_SYSCTL_DCGC2_EMAC0_Msk              (1UL << LM3S_SYSCTL_DCGC2_EMAC0_Pos)

#define LM3S_SYSCTL_DCGC2_USB0_Pos               16
#define LM3S_SYSCTL_DCGC2_USB0_Msk               (1UL << LM3S_SYSCTL_DCGC2_USB0_Pos)

#define LM3S_SYSCTL_DCGC2_UDMA_Pos               13
#define LM3S_SYSCTL_DCGC2_UDMA_Msk               (1UL << LM3S_SYSCTL_DCGC2_UDMA_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOJ_Pos               8
#define LM3S_SYSCTL_DCGC2_GPIOJ_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOJ_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOH_Pos               7
#define LM3S_SYSCTL_DCGC2_GPIOH_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOH_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOG_Pos               6
#define LM3S_SYSCTL_DCGC2_GPIOG_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOG_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOF_Pos               5
#define LM3S_SYSCTL_DCGC2_GPIOF_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOF_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOE_Pos               4
#define LM3S_SYSCTL_DCGC2_GPIOE_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOE_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOD_Pos               3
#define LM3S_SYSCTL_DCGC2_GPIOD_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOD_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOC_Pos               2
#define LM3S_SYSCTL_DCGC2_GPIOC_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOC_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOB_Pos               1
#define LM3S_SYSCTL_DCGC2_GPIOB_Msk              (1UL << LM3S_SYSCTL_DCGC2_GPIOB_Pos)

#define LM3S_SYSCTL_DCGC2_GPIOA_Pos               0
#define LM3S_SYSCTL_DCGC2_GPIOA_Msk              (1UL /*<< LM3S_SYSCTL_DCGC2_GPIOA_Pos*/)

/* LM3S_SYSCTL SRCR0 Register Definitions */
#define LM3S_SYSCTL_SRCR0_WDT1_Pos               28
#define LM3S_SYSCTL_SRCR0_WDT1_Msk               (1UL << LM3S_SYSCTL_SRCR0_WDT1_Pos)

#define LM3S_SYSCTL_SRCR0_CAN1_Pos               25
#define LM3S_SYSCTL_SRCR0_CAN1_Msk               (1UL << LM3S_SYSCTL_SRCR0_CAN1_Pos)

#define LM3S_SYSCTL_SRCR0_CAN0_Pos               24
#define LM3S_SYSCTL_SRCR0_CAN0_Msk               (1UL << LM3S_SYSCTL_SRCR0_CAN0_Pos)

#define LM3S_SYSCTL_SRCR0_PWM_Pos                20
#define LM3S_SYSCTL_SRCR0_PWM_Msk                (1UL << LM3S_SYSCTL_SRCR0_PWM_Pos)

#define LM3S_SYSCTL_SRCR0_ADC1_Pos               17
#define LM3S_SYSCTL_SRCR0_ADC1_Msk               (1UL << LM3S_SYSCTL_SRCR0_ADC1_Pos)

#define LM3S_SYSCTL_SRCR0_ADC0_Pos               16
#define LM3S_SYSCTL_SRCR0_ADC0_Msk               (1UL << LM3S_SYSCTL_SRCR0_ADC0_Pos)

#define LM3S_SYSCTL_SRCR0_WDT0_Pos                3
#define LM3S_SYSCTL_SRCR0_WDT0_Msk               (1UL << LM3S_SYSCTL_SRCR0_WDT0_Pos)

/* LM3S_SYSCTL SRCR1 Register Definitions */
#define LM3S_SYSCTL_SRCR1_EPI0_Pos               30
#define LM3S_SYSCTL_SRCR1_EPI0_Msk               (1UL << LM3S_SYSCTL_SRCR1_EPI0_Pos)

#define LM3S_SYSCTL_SRCR1_I2S0_Pos               28
#define LM3S_SYSCTL_SRCR1_I2S0_Msk               (1UL << LM3S_SYSCTL_SRCR1_I2S0_Pos)

#define LM3S_SYSCTL_SRCR1_COMP2_Pos              26
#define LM3S_SYSCTL_SRCR1_COMP2_Msk              (1UL << LM3S_SYSCTL_SRCR1_COMP2_Pos)

#define LM3S_SYSCTL_SRCR1_COMP1_Pos              25
#define LM3S_SYSCTL_SRCR1_COMP1_Msk              (1UL << LM3S_SYSCTL_SRCR1_COMP1_Pos)

#define LM3S_SYSCTL_SRCR1_COMP0_Pos              24
#define LM3S_SYSCTL_SRCR1_COMP0_Msk              (1UL << LM3S_SYSCTL_SRCR1_COMP0_Pos)

#define LM3S_SYSCTL_SRCR1_TIMER3_Pos             19
#define LM3S_SYSCTL_SRCR1_TIMER3_Msk             (1UL << LM3S_SYSCTL_SRCR1_TIMER3_Pos)

#define LM3S_SYSCTL_SRCR1_TIMER2_Pos             18
#define LM3S_SYSCTL_SRCR1_TIMER2_Msk             (1UL << LM3S_SYSCTL_SRCR1_TIMER2_Pos)

#define LM3S_SYSCTL_SRCR1_TIMER1_Pos             17
#define LM3S_SYSCTL_SRCR1_TIMER1_Msk             (1UL << LM3S_SYSCTL_SRCR1_TIMER1_Pos)

#define LM3S_SYSCTL_SRCR1_TIMER0_Pos             16
#define LM3S_SYSCTL_SRCR1_TIMER0_Msk             (1UL << LM3S_SYSCTL_SRCR1_TIMER0_Pos)

#define LM3S_SYSCTL_SRCR1_I2C1_Pos               14
#define LM3S_SYSCTL_SRCR1_I2C1_Msk               (1UL << LM3S_SYSCTL_SRCR1_I2C1_Pos)

#define LM3S_SYSCTL_SRCR1_I2C0_Pos               12
#define LM3S_SYSCTL_SRCR1_I2C0_Msk               (1UL << LM3S_SYSCTL_SRCR1_I2C0_Pos)

#define LM3S_SYSCTL_SRCR1_QEI1_Pos                9
#define LM3S_SYSCTL_SRCR1_QEI1_Msk               (1UL << LM3S_SYSCTL_SRCR1_QEI1_Pos)

#define LM3S_SYSCTL_SRCR1_QEI0_Pos                8
#define LM3S_SYSCTL_SRCR1_QEI0_Msk               (1UL << LM3S_SYSCTL_SRCR1_QEI0_Pos)

#define LM3S_SYSCTL_SRCR1_SSI1_Pos                5
#define LM3S_SYSCTL_SRCR1_SSI1_Msk               (1UL << LM3S_SYSCTL_SRCR1_SSI1_Pos)

#define LM3S_SYSCTL_SRCR1_SSI0_Pos                4
#define LM3S_SYSCTL_SRCR1_SSI0_Msk               (1UL << LM3S_SYSCTL_SRCR1_SSI0_Pos)

#define LM3S_SYSCTL_SRCR1_UART2_Pos               2
#define LM3S_SYSCTL_SRCR1_UART2_Msk              (1UL << LM3S_SYSCTL_SRCR1_UART2_Pos)

#define LM3S_SYSCTL_SRCR1_UART1_Pos               1
#define LM3S_SYSCTL_SRCR1_UART1_Msk              (1UL << LM3S_SYSCTL_SRCR1_UART1_Pos)

#define LM3S_SYSCTL_SRCR1_UART0_Pos               0
#define LM3S_SYSCTL_SRCR1_UART0_Msk              (1UL /*<< LM3S_SYSCTL_SRCR1_UART0_Pos*/)

/* LM3S_SYSCTL SRCR2 Register Definitions */
#define LM3S_SYSCTL_SRCR2_EPHY0_Pos              30
#define LM3S_SYSCTL_SRCR2_EPHY0_Msk              (1UL << LM3S_SYSCTL_SRCR2_EPHY0_Pos)

#define LM3S_SYSCTL_SRCR2_EMAC0_Pos              28
#define LM3S_SYSCTL_SRCR2_EMAC0_Msk              (1UL << LM3S_SYSCTL_SRCR2_EMAC0_Pos)

#define LM3S_SYSCTL_SRCR2_USB0_Pos               16
#define LM3S_SYSCTL_SRCR2_USB0_Msk               (1UL << LM3S_SYSCTL_SRCR2_USB0_Pos)

#define LM3S_SYSCTL_SRCR2_UDMA_Pos               13
#define LM3S_SYSCTL_SRCR2_UDMA_Msk               (1UL << LM3S_SYSCTL_SRCR2_UDMA_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOJ_Pos               8
#define LM3S_SYSCTL_SRCR2_GPIOJ_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOJ_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOH_Pos               7
#define LM3S_SYSCTL_SRCR2_GPIOH_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOH_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOG_Pos               6
#define LM3S_SYSCTL_SRCR2_GPIOG_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOG_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOF_Pos               5
#define LM3S_SYSCTL_SRCR2_GPIOF_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOF_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOE_Pos               4
#define LM3S_SYSCTL_SRCR2_GPIOE_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOE_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOD_Pos               3
#define LM3S_SYSCTL_SRCR2_GPIOD_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOD_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOC_Pos               2
#define LM3S_SYSCTL_SRCR2_GPIOC_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOC_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOB_Pos               1
#define LM3S_SYSCTL_SRCR2_GPIOB_Msk              (1UL << LM3S_SYSCTL_SRCR2_GPIOB_Pos)

#define LM3S_SYSCTL_SRCR2_GPIOA_Pos               0
#define LM3S_SYSCTL_SRCR2_GPIOA_Msk              (1UL /*<< LM3S_SYSCTL_SRCR2_GPIOA_Pos*/)

/* ================================================================================ */
/* ================                      UDMA                      ================ */
/* ================================================================================ */

typedef struct {
  __IOM uint32_t  SRCENDP;              /* Offset: 0x000 (R/W) Source Address End Pointer Register */
  __IOM uint32_t  DSTENDP;              /* Offset: 0x004 (R/W) Destination Address End Pointer Register */
  __IOM uint32_t  CHCTL;                /* Offset: 0x008 (R/W) Destination Address End Pointer Register */
} LM3S_UDMA_Channel_TypeDef;

/* LM3S_UDMA Channel SRCENDP Register Definitions */
#define LM3S_UDMA_SRCENDP_ADDR_Pos                0
#define LM3S_UDMA_SRCENDP_ADDR_Msk               (0xFFFFFFFFUL /*<< LM3S_UDMA_SRCENDP_ADDR_Pos*/)

/* LM3S_UDMA Channel DSTENDP Register Definitions */
#define LM3S_UDMA_DSTENDP_ADDR_Pos                0
#define LM3S_UDMA_DSTENDP_ADDR_Msk               (0xFFFFFFFFUL /*<< LM3S_UDMA_DSTENDP_ADDR_Pos*/)

/* LM3S_UDMA Channel CHCTL Register Definitions */
#define LM3S_UDMA_CHCTL_DSTINC_Pos               31
#define LM3S_UDMA_CHCTL_DSTINC_Msk               (0x00000003UL << LM3S_UDMA_CHCTL_DSTINC_Pos)
#define LM3S_UDMA_CHCTL_DSTINC_1_Pos             31
#define LM3S_UDMA_CHCTL_DSTINC_1_Msk             (1UL << LM3S_UDMA_CHCTL_DSTINC_1_Pos)
#define LM3S_UDMA_CHCTL_DSTINC_0_Pos             30
#define LM3S_UDMA_CHCTL_DSTINC_0_Msk             (1UL << LM3S_UDMA_CHCTL_DSTINC_0_Pos)

#define LM3S_UDMA_CHCTL_DSTSIZE_Pos              28
#define LM3S_UDMA_CHCTL_DSTSIZE_Msk              (0x00000003UL << LM3S_UDMA_CHCTL_DSTSIZE_Pos)
#define LM3S_UDMA_CHCTL_DSTSIZE_1_Pos            29
#define LM3S_UDMA_CHCTL_DSTSIZE_1_Msk            (1UL << LM3S_UDMA_CHCTL_DSTSIZE_1_Pos)
#define LM3S_UDMA_CHCTL_DSTSIZE_0_Pos            28
#define LM3S_UDMA_CHCTL_DSTSIZE_0_Msk            (1UL << LM3S_UDMA_CHCTL_DSTSIZE_0_Pos)

#define LM3S_UDMA_CHCTL_SRCINC_Pos               26
#define LM3S_UDMA_CHCTL_SRCINC_Msk               (0x00000003UL << LM3S_UDMA_CHCTL_SRCINC_Pos)
#define LM3S_UDMA_CHCTL_SRCINC_1_Pos             27
#define LM3S_UDMA_CHCTL_SRCINC_1_Msk             (1UL << LM3S_UDMA_CHCTL_SRCINC_1_Pos)
#define LM3S_UDMA_CHCTL_SRCINC_0_Pos             26
#define LM3S_UDMA_CHCTL_SRCINC_0_Msk             (1UL << LM3S_UDMA_CHCTL_SRCINC_0_Pos)

#define LM3S_UDMA_CHCTL_SRCSIZE_Pos              24
#define LM3S_UDMA_CHCTL_SRCSIZE_Msk              (0x00000003UL << LM3S_UDMA_CHCTL_SRCSIZE_Pos)
#define LM3S_UDMA_CHCTL_SRCSIZE_1_Pos            25
#define LM3S_UDMA_CHCTL_SRCSIZE_1_Msk            (1UL << LM3S_UDMA_CHCTL_SRCSIZE_1_Pos)
#define LM3S_UDMA_CHCTL_SRCSIZE_0_Pos            24
#define LM3S_UDMA_CHCTL_SRCSIZE_0_Msk            (1UL << LM3S_UDMA_CHCTL_SRCSIZE_0_Pos)

#define LM3S_UDMA_CHCTL_ARBSIZE_Pos              14
#define LM3S_UDMA_CHCTL_ARBSIZE_Msk              (0x0000000FUL << LM3S_UDMA_CHCTL_ARBSIZE_Pos)
#define LM3S_UDMA_CHCTL_ARBSIZE_3_Pos            17
#define LM3S_UDMA_CHCTL_ARBSIZE_3_Msk            (1UL << LM3S_UDMA_CHCTL_ARBSIZE_3_Pos)
#define LM3S_UDMA_CHCTL_ARBSIZE_2_Pos            16
#define LM3S_UDMA_CHCTL_ARBSIZE_2_Msk            (1UL << LM3S_UDMA_CHCTL_ARBSIZE_2_Pos)
#define LM3S_UDMA_CHCTL_ARBSIZE_1_Pos            15
#define LM3S_UDMA_CHCTL_ARBSIZE_1_Msk            (1UL << LM3S_UDMA_CHCTL_ARBSIZE_1_Pos)
#define LM3S_UDMA_CHCTL_ARBSIZE_0_Pos            14
#define LM3S_UDMA_CHCTL_ARBSIZE_0_Msk            (1UL << LM3S_UDMA_CHCTL_ARBSIZE_0_Pos)

#define LM3S_UDMA_CHCTL_XFERSIZE_Pos              4
#define LM3S_UDMA_CHCTL_XFERSIZE_Msk             (0x000003FFUL << LM3S_UDMA_CHCTL_XFERSIZE_Pos)

#define LM3S_UDMA_CHCTL_NXTUSEBURST_Pos           3
#define LM3S_UDMA_CHCTL_NXTUSEBURST_Msk          (1UL << LM3S_UDMA_CHCTL_NXTUSEBURST_Pos)

#define LM3S_UDMA_CHCTL_XFERMODE_Pos              0
#define LM3S_UDMA_CHCTL_XFERMODE_Msk             (0x00000007UL /*<< LM3S_UDMA_CHCTL_XFERMODE_Pos*/)
#define LM3S_UDMA_CHCTL_XFERMODE_2_Pos            2
#define LM3S_UDMA_CHCTL_XFERMODE_2_Msk           (1UL << LM3S_UDMA_CHCTL_XFERMODE_2_Pos)
#define LM3S_UDMA_CHCTL_XFERMODE_1_Pos            1
#define LM3S_UDMA_CHCTL_XFERMODE_1_Msk           (1UL << LM3S_UDMA_CHCTL_XFERMODE_1_Pos)
#define LM3S_UDMA_CHCTL_XFERMODE_0_Pos            0
#define LM3S_UDMA_CHCTL_XFERMODE_0_Msk           (1UL /*<< LM3S_UDMA_CHCTL_XFERMODE_0_Pos*/)

typedef struct {
  __IM  uint32_t  STAT;                 /* Offset: 0x000 (R/ ) Status Register */
  __OM  uint32_t  CFG;                  /* Offset: 0x004 ( /W) Configuration Register */
  __IOM uint32_t  CTLBASE;              /* Offset: 0x008 (R/W) Channel Control Base Pointer Register */
  __IM  uint32_t  ALTBASE;              /* Offset: 0x00C (R/ ) Alternate Channel Control Base Pointer Register */
  __IM  uint32_t  WAITSTAT;             /* Offset: 0x010 (R/ ) Channel Wait-on-Request Status Register */
  __OM  uint32_t  SWREQ;                /* Offset: 0x014 ( /W) Channel Software Request Register */
  __IOM uint32_t  USEBURSTSET;          /* Offset: 0x018 (R/W) Channel Useburst Set Register */
  __OM  uint32_t  SEBURSTCLR;           /* Offset: 0x01C ( /W) Channel Useburst Clear Register */
  __IOM uint32_t  REQMASKSET;           /* Offset: 0x020 (R/W) Channel Request Mask Set Register */
  __OM  uint32_t  REQMASKCLR;           /* Offset: 0x024 ( /W) Channel Request Mask Clear Register */
  __IOM uint32_t  ENASET;               /* Offset: 0x028 (R/W) Channel Enable Set Register */
  __OM  uint32_t  ENACLR;               /* Offset: 0x02C ( /W) Channel Enable Clear Register */
  __IOM uint32_t  ALTSET;               /* Offset: 0x030 (R/W) Channel Primary Alternate Set Register */
  __OM  uint32_t  ALTCLR;               /* Offset: 0x034 ( /W) Channel Primary Alternate Clear Register */
  __IOM uint32_t  PRIOSET;              /* Offset: 0x038 (R/W) Channel Priority Set Register */
  __OM  uint32_t  PRIOCLR;              /* Offset: 0x03C ( /W) Channel Priority Clear Register */
  __IM  uint32_t  RESERVED0[3];
  __IOM uint32_t  ERRCLR;               /* Offset: 0x04C (R/W) Bus Error Clear Register */
  __IM  uint32_t  RESERVED1[300];
  __IOM uint32_t  CHASGN;               /* Offset: 0x500 (R/W) Channel Assignment Register */
  __IM  uint32_t  RESERVED2[695];
  __IM  uint32_t  PID4;                 /* Offset: 0xFD0 (R/ ) Peripheral Identification 4 Register */
  __IM  uint32_t  RESERVED3[3];
  __IM  uint32_t  PID0;                 /* Offset: 0xFE0 (R/ ) Peripheral Identification 0 Register */
  __IM  uint32_t  PID1;                 /* Offset: 0xFE4 (R/ ) Peripheral Identification 1 Register */
  __IM  uint32_t  PID2;                 /* Offset: 0xFE8 (R/ ) Peripheral Identification 2 Register */
  __IM  uint32_t  PID3;                 /* Offset: 0xFEC (R/ ) Peripheral Identification 3 Register */
  __IM  uint32_t  PCID0;                /* Offset: 0xFF0 (R/ ) PrimeCell Identification 0 Register */
  __IM  uint32_t  PCID1;                /* Offset: 0xFF4 (R/ ) PrimeCell Identification 1 Register */
  __IM  uint32_t  PCID2;                /* Offset: 0xFF8 (R/ ) PrimeCell Identification 2 Register */
  __IM  uint32_t  PCID3;                /* Offset: 0xFFC (R/ ) PrimeCell Identification 3 Register */
} LM3S_UDMA_TypeDef;

/* LM3S_UDMA STAT Register Definitions */
#define LM3S_UDMA_STAT_DMACHANS_Pos              16
#define LM3S_UDMA_STAT_DMACHANS_Msk              (0x0000000FUL << LM3S_UDMA_STAT_DMACHANS_Pos)

#define LM3S_UDMA_STAT_STATE_Pos                  4
#define LM3S_UDMA_STAT_STATE_Msk                 (0x0000000FUL << LM3S_UDMA_STAT_STATE_Pos)
#define LM3S_UDMA_STAT_STATE_3_Pos                7
#define LM3S_UDMA_STAT_STATE_3_Msk               (1UL << LM3S_UDMA_STAT_STATE_3_Pos)
#define LM3S_UDMA_STAT_STATE_2_Pos                6
#define LM3S_UDMA_STAT_STATE_2_Msk               (1UL << LM3S_UDMA_STAT_STATE_2_Pos)
#define LM3S_UDMA_STAT_STATE_1_Pos                5
#define LM3S_UDMA_STAT_STATE_1_Msk               (1UL << LM3S_UDMA_STAT_STATE_1_Pos)
#define LM3S_UDMA_STAT_STATE_0_Pos                4
#define LM3S_UDMA_STAT_STATE_0_Msk               (1UL << LM3S_UDMA_STAT_STATE_0_Pos)

#define LM3S_UDMA_STAT_MASTEN_Pos                 0
#define LM3S_UDMA_STAT_MASTEN_Msk                (1UL /*<< LM3S_UDMA_STAT_MASTEN_Pos*/)

/* LM3S_UDMA CFG Register Definitions */
#define LM3S_UDMA_CFG_MASTEN_Pos                  0
#define LM3S_UDMA_CFG_MASTEN_Msk                 (1UL /*<< LM3S_UDMA_CFG_MASTEN_Pos*/)

/* LM3S_UDMA CTLBASE Register Definitions */
#define LM3S_UDMA_CTLBASE_ADDR_Pos               10
#define LM3S_UDMA_CTLBASE_ADDR_Msk               (0x003FFFFFUL << LM3S_UDMA_CTLBASE_ADDR_Pos)

/* LM3S_UDMA ALTBASE Register Definitions */
#define LM3S_UDMA_ALTBASE_ADDR_Pos                0
#define LM3S_UDMA_ALTBASE_ADDR_Msk               (0xFFFFFFFFUL /*<< LM3S_UDMA_ALTBASE_ADDR_Pos*/)

/* LM3S_UDMA WAITSTAT Register Definitions */
#define LM3S_UDMA_WAITSTAT_WAITREQN_Pos           0
#define LM3S_UDMA_WAITSTAT_WAITREQN_Msk          (0xFFFFFFFFUL /*<< LM3S_UDMA_WAITSTAT_WAITREQN_Pos*/)

/* LM3S_UDMA SWREQ Register Definitions */
#define LM3S_UDMA_SWREQ_SWREQN_Pos                0
#define LM3S_UDMA_SWREQ_SWREQN_Msk               (0xFFFFFFFFUL /*<< LM3S_UDMA_SWREQ_SWREQN_Pos*/)

/* LM3S_UDMA USEBURSTSET Register Definitions */
#define LM3S_UDMA_USEBURSTSET_SETN_Pos            0
#define LM3S_UDMA_USEBURSTSET_SETN_Msk           (0xFFFFFFFFUL /*<< LM3S_UDMA_USEBURSTSET_SETN_Pos*/)

/* LM3S_UDMA USEBURSTCLR Register Definitions */
#define LM3S_UDMA_USEBURSTCLR_CLRN_Pos            0
#define LM3S_UDMA_USEBURSTCLR_CLRN_Msk           (0xFFFFFFFFUL /*<< LM3S_UDMA_USEBURSTCLR_CLRN_Pos*/)

/* LM3S_UDMA REQMASKSET Register Definitions */
#define LM3S_UDMA_REQMASKSET_SETN_Pos             0
#define LM3S_UDMA_REQMASKSET_SETN_Msk            (0xFFFFFFFFUL /*<< LM3S_UDMA_REQMASKSET_SETN_Pos*/)

/* LM3S_UDMA REQMASKCLR Register Definitions */
#define LM3S_UDMA_REQMASKCLR_CLRN_Pos             0
#define LM3S_UDMA_REQMASKCLR_CLRN_Msk            (0xFFFFFFFFUL /*<< LM3S_UDMA_REQMASKCLR_CLRN_Pos*/)

/* LM3S_UDMA ENASET Register Definitions */
#define LM3S_UDMA_ENASET_SETN_Pos                 0
#define LM3S_UDMA_ENASET_SETN_Msk                (0xFFFFFFFFUL /*<< LM3S_UDMA_ENASET_SETN_Pos*/)

/* LM3S_UDMA ENACLR Register Definitions */
#define LM3S_UDMA_ENACLR_CLRN_Pos                 0
#define LM3S_UDMA_ENACLR_CLRN_Msk                (0xFFFFFFFFUL /*<< LM3S_UDMA_ENACLR_CLRN_Pos*/)

/* LM3S_UDMA ALTSET Register Definitions */
#define LM3S_UDMA_ALTSET_SETN_Pos                 0
#define LM3S_UDMA_ALTSET_SETN_Msk                (0xFFFFFFFFUL /*<< LM3S_UDMA_ALTSET_SETN_Pos*/)

/* LM3S_UDMA ALTCLR Register Definitions */
#define LM3S_UDMA_ALTCLR_CLRN_Pos                 0
#define LM3S_UDMA_ALTCLR_CLRN_Msk                (0xFFFFFFFFUL /*<< LM3S_UDMA_ALTCLR_CLRN_Pos*/)

/* LM3S_UDMA PRIOSET Register Definitions */
#define LM3S_UDMA_PRIOSET_SETN_Pos                0
#define LM3S_UDMA_PRIOSET_SETN_Msk               (0xFFFFFFFFUL /*<< LM3S_UDMA_PRIOSET_SETN_Pos*/)

/* LM3S_UDMA PRIOCLR Register Definitions */
#define LM3S_UDMA_PRIOCLR_CLRN_Pos                0
#define LM3S_UDMA_PRIOCLR_CLRN_Msk               (0xFFFFFFFFUL /*<< LM3S_UDMA_PRIOCLR_CLRN_Pos*/)

/* LM3S_UDMA ERRCLR Register Definitions */
#define LM3S_UDMA_ERRCLR_ERRCLR_Pos               0
#define LM3S_UDMA_ERRCLR_ERRCLR_Msk              (1UL /*<< LM3S_UDMA_ERRCLR_CLRN_Pos*/)

/* LM3S_UDMA CHASGN Register Definitions */
#define LM3S_UDMA_CHASGN_CHASGNN_Pos              0
#define LM3S_UDMA_CHASGN_CHASGNN_Msk             (0xFFFFFFFFUL /*<< LM3S_UDMA_CHASGN_CHASGNN_Pos*/)

/* LM3S_UDMA PID4 Register Definitions */
#define LM3S_UDMA_PID4_PID4_Pos                   0
#define LM3S_UDMA_PID4_PID4_Msk                  (0x000000FFUL /*<< LM3S_UDMA_PID4_PID4_Pos*/)

/* LM3S_UDMA PID0 Register Definitions */
#define LM3S_UDMA_PID0_PID0_Pos                   0
#define LM3S_UDMA_PID0_PID0_Msk                  (0x000000FFUL /*<< LM3S_UDMA_PID0_PID0_Pos*/)

/* LM3S_UDMA PID1 Register Definitions */
#define LM3S_UDMA_PID1_PID1_Pos                   0
#define LM3S_UDMA_PID1_PID1_Msk                  (0x000000FFUL /*<< LM3S_UDMA_PID1_PID1_Pos*/)

/* LM3S_UDMA PID2 Register Definitions */
#define LM3S_UDMA_PID2_PID2_Pos                   0
#define LM3S_UDMA_PID2_PID2_Msk                  (0x000000FFUL /*<< LM3S_UDMA_PID2_PID2_Pos*/)

/* LM3S_UDMA PID3 Register Definitions */
#define LM3S_UDMA_PID3_PID3_Pos                   0
#define LM3S_UDMA_PID3_PID3_Msk                  (0x000000FFUL /*<< LM3S_UDMA_PID3_PID3_Pos*/)

/* LM3S_UDMA PCID0 Register Definitions */
#define LM3S_UDMA_PCID0_PCID0_Pos                 0
#define LM3S_UDMA_PCID0_PCID0_Msk                (0x000000FFUL /*<< LM3S_UDMA_PCID0_PCID0_Pos*/)

/* LM3S_UDMA PCID1 Register Definitions */
#define LM3S_UDMA_PCID1_PCID1_Pos                 0
#define LM3S_UDMA_PCID1_PCID1_Msk                (0x000000FFUL /*<< LM3S_UDMA_PCID1_PCID1_Pos*/)

/* LM3S_UDMA PID2 Register Definitions */
#define LM3S_UDMA_PCID2_PCID2_Pos                 0
#define LM3S_UDMA_PCID2_PCID2_Msk                (0x000000FFUL /*<< LM3S_UDMA_PCID2_PCID2_Pos*/)

/* LM3S_UDMA PCID3 Register Definitions */
#define LM3S_UDMA_PCID3_PCID3_Pos                 0
#define LM3S_UDMA_PCID3_PCID3_Msk                (0x000000FFUL /*<< LM3S_UDMAI_PCID3_PCID3_Pos*/)

///* ========================================================================= */
///* ============                      FLASH                      ============ */
///* ========================================================================= */

typedef struct
{
  __IOM uint32_t  FMA;                  /* Offset: 0x000 (R/W) Flash Memory Address Register */
  __IM  uint32_t  FMD;                  /* Offset: 0x004 (R/ ) Flash Memory Data Register */
  __IOM uint32_t  FMC;                  /* Offset: 0x008 (R/W) Flash Memory Control Register */
  __OM  uint32_t  FCRIS;                /* Offset: 0x00C ( /W) Flash Controller Raw Interrupt Status Register */
  __IM  uint32_t  FCIM;                 /* Offset: 0x010 (R/ ) Flash Controller Interrupt Mask Register */
  __IM  uint32_t  FCMISC;               /* Offset: 0x014 (R/ ) Flash Controller Masked Interrupt Status and Clear Register */
  __IM  uint32_t  RESERVED0[2];
  __IOM uint32_t  FMC2;                 /* Offset: 0x020 (R/W) Flash Memory Control Register 2 */
  __IM  uint32_t  RESERVED1[3];
  __IOM uint32_t  FWBVAL;               /* Offset: 0x030 (R/W) Flash Write Buffer Valid Register */
  __IM  uint32_t  RESERVED2[49];
  __IOM uint32_t  FCTL;                 /* Offset: 0x0F8 (R/W) Flash Control Register */
  __IM  uint32_t  RESERVED3;
  __IO  uint32_t  FWB[32];              /* Offset: 0x100-0x17C (R/W) Flash Write Buffer n Register */
} LM3S_FLASH_TypeDef;

/* LM3S_FLASH FMA Register Definitions */
#define LM3S_FLASH_FMA_OFFSET_Pos                 0
#define LM3S_FLASH_FMA_OFFSET_Msk                (0x000003FFUL /*<< LM3S_FLASH_FMA_OFFSET_Pos*/)

/* LM3S_FLASH FMD Register Definitions */
#define LM3S_FLASH_FMD_DATA_Pos                   0
#define LM3S_FLASH_FMD_DATA_Msk                  (0xFFFFFFFFUL /*<< LM3S_FLASH_FMD_DATA_Pos*/)

/* LM3S_FLASH FMC Register Definitions */
#define LM3S_FLASH_FMC_WRKEY_Pos                 16
#define LM3S_FLASH_FMC_WRKEY_Msk                 (0x0000FFFFUL << LM3S_FLASH_FMC_WRKEY_Pos)

#define LM3S_FLASH_FMC_COMT_Pos                   3
#define LM3S_FLASH_FMC_COMT_Msk                  (1UL << LM3S_FLASH_FMC_COMT_Pos)

#define LM3S_FLASH_FMC_MERASE_Pos                 2
#define LM3S_FLASH_FMC_MERASE_Msk                (1UL << LM3S_FLASH_FMC_MERASE_Pos)

#define LM3S_FLASH_FMC_ERASE_Pos                  1
#define LM3S_FLASH_FMC_ERASE_Msk                 (1UL << LM3S_FLASH_FMC_ERASE_Pos)

#define LM3S_FLASH_FMC_WRITE_Pos                  0
#define LM3S_FLASH_FMC_WRITE_Msk                 (1UL /*<< LM3S_FLASH_FMC_WRITE_Pos*/)

/* LM3S_FLASH FCRIS Register Definitions */
#define LM3S_FLASH_FCRIS_PRIS_Pos                 1
#define LM3S_FLASH_FCRIS_PRIS_Msk                (1UL << LM3S_FLASH_FCRIS_PRIS_Pos)

#define LM3S_FLASH_FCRIS_ARIS_Pos                 0
#define LM3S_FLASH_FCRIS_ARIS_Msk                (1UL /*<< LM3S_FLASH_FCRIS_ARIS_Pos*/)

/* LM3S_FLASH FCIM Register Definitions */
#define LM3S_FLASH_FCIM_PMASK_Pos                 1
#define LM3S_FLASH_FCIM_PMASK_Msk                (1UL << LM3S_FLASH_FCIM_PMASK_Pos)

#define LM3S_FLASH_FCIM_AMASK_Pos                 0
#define LM3S_FLASH_FCIM_AMASK_Msk                (1UL /*<< LM3S_FLASH_FCIM_AMASK_Pos*/)

/* LM3S_FLASH FCMISC Register Definitions */
#define LM3S_FLASH_FCMISC_PMISC_Pos               1
#define LM3S_FLASH_FCMISC_PMISC_Msk              (1UL << LM3S_FLASH_FCMISC_PMISC_Pos)

#define LM3S_FLASH_FCMISC_AMISC_Pos               0
#define LM3S_FLASH_FCMISC_AMISC_Msk              (1UL /*<< LM3S_FLASH_FCMISC_AMISC_Pos*/)

/* LM3S_FLASH FMC2 Register Definitions */
#define LM3S_FLASH_FMC2_WRKEY_Pos                16
#define LM3S_FLASH_FMC2_WRKEY_Msk                (0x0000FFFFUL << LM3S_FLASH_FMC2_WRKEY_Pos)

#define LM3S_FLASH_FMC2_WRBUF_Pos                 0
#define LM3S_FLASH_FMC2_WRBUF_Msk                (1UL /*<< LM3S_FLASH_FMC2_WRBUF_Pos*/)

/* LM3S_FLASH FWBVAL Register Definitions */
#define LM3S_FLASH_FWBVAL_FWB_Pos                 0
#define LM3S_FLASH_FWBVAL_FWB_Msk                (0xFFFFFFFFUL /*<< LM3S_FLASH_FWBVAL_FWB_Pos*/)

/* LM3S_FLASH FWBn Register Definitions */
#define LM3S_FLASH_FWB_DATA_Pos                   0
#define LM3S_FLASH_FWB_DATA_Msk                  (0xFFFFFFFFUL /*<< LM3S_FLASH_FWB_DATA_Pos*/)

/* LM3S_FLASH FCTL Register Definitions */
#define LM3S_FLASH_FCTL_USDACK_Pos                1
#define LM3S_FLASH_FCTL_USDACK_Msk               (1UL << LM3S_FLASH_FCTL_USDACK_Pos)

#define LM3S_FLASH_FCTL_USDREQ_Pos                0
#define LM3S_FLASH_FCTL_USDREQ_Msk               (1UL /*<< LM3S_FLASH_FCTL_USDREQ_Pos*/)

typedef struct {
  __IM  uint32_t RESERVED0[60];
  __IOM uint32_t RMCTL;                 /* Offset: 0x0F0 (R/W) ROM Control Register */
  __IM  uint32_t RMVER;                 /* Offset: 0x0F4 (R/ ) ROM Version Register */
  __IM  uint32_t RESERVED1[14];
  __IOM uint32_t FMPRE0_0;              /* Offset: 0x130 (R/W) Flash Memory Address Register (Backwards compatibility)*/ 
  __IOM uint32_t FMPPE0_0;              /* Offset: 0x134 (R/W) Flash Memory Address Register (Backwards compatibility)*/
  __IM  uint32_t RESERVED2[38];
  __IOM uint32_t BOOTCFG;               /* Offset: 0x1D0 (R/W) Flash Memory Address Register */
  __IM  uint32_t RESERVED3[3];
  __IOM uint32_t USER_REG0;             /* Offset: 0x1E0 (R/W) Flash Memory Address Register */
  __IOM uint32_t USER_REG1;             /* Offset: 0x1E4 (R/W) Flash Memory Address Register */
  __IOM uint32_t USER_REG2;             /* Offset: 0x1E8 (R/W) Flash Memory Address Register */
  __IOM uint32_t USER_REG3;             /* Offset: 0x1EC (R/W) Flash Memory Address Register */
  __IM  uint32_t RESERVED4[4];
  __IOM uint32_t FMPRE0;                /* Offset: 0x200 (R/W) Flash Memory Address Register */
  __IOM uint32_t FMPRE1;                /* Offset: 0x204 (R/W) Flash Memory Address Register */
  __IOM uint32_t FMPRE2;                /* Offset: 0x208 (R/W) Flash Memory Address Register */
  __IOM uint32_t FMPRE3;                /* Offset: 0x20C (R/W) Flash Memory Address Register */
  __IM  uint32_t RESERVED5[124];
  __IOM uint32_t FMPPE0;                /* Offset: 0x400 (R/W) Flash Memory Address Register */
  __IOM uint32_t FMPPE1;                /* Offset: 0x404 (R/W) Flash Memory Address Register */
  __IOM uint32_t FMPPE2;                /* Offset: 0x408 (R/W) Flash Memory Address Register */
  __IOM uint32_t FMPPE3;                /* Offset: 0x40C (R/W) Flash Memory Address Register */
} LM3S_MEMORY_TypeDef;

/* LM3S_MEMORY RMCTL Register Definitions */
#define LM3S_MEMORY_RMCTL_BA_Pos                  0
#define LM3S_MEMORY_RMCTL_BA_Msk                 (1UL /*<< LM3S_MEMORY_RMCTL_BA_Pos*/)

/* LM3S_MEMORY RMVER Register Definitions */
#define LM3S_MEMORY_RMVER_CONT_Pos               24
#define LM3S_MEMORY_RMVER_CONT_Msk               (0x0000000FUL << LM3S_MEMORY_RMVER_CONT_Pos)

#define LM3S_MEMORY_RMVER_SIZE_Pos               16
#define LM3S_MEMORY_RMVER_SIZE_Msk               (0x0000000FUL << LM3S_MEMORY_RMVER_SIZE_Pos)

#define LM3S_MEMORY_RMVER_VER_Pos                 8
#define LM3S_MEMORY_RMVER_VER_Msk                (0x0000000FUL << LM3S_MEMORY_RMVER_VER_Pos)

#define LM3S_MEMORY_RMVER_REV_Pos                 0
#define LM3S_MEMORY_RMVER_REV_Msk                (0x0000000FUL /*<< LM3S_MEMORY_RMVER_REV_Pos*/)

/* LM3S_MEMORY FMPRE0 Register Definitions */
#define LM3S_MEMORY_FMPRE0_READ_ENABLE_Pos        0
#define LM3S_MEMORY_FMPRE0_READ_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPRE0_READ_ENABLE_Pos*/)

/* LM3S_MEMORY FMPRE1 Register Definitions */
#define LM3S_MEMORY_FMPRE1_READ_ENABLE_Pos        0
#define LM3S_MEMORY_FMPRE1_READ_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPRE1_READ_ENABLE_Pos*/)

/* LM3S_MEMORY FMPRE2 Register Definitions */
#define LM3S_MEMORY_FMPRE2_READ_ENABLE_Pos        0
#define LM3S_MEMORY_FMPRE2_READ_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPRE2_READ_ENABLE_Pos*/)

/* LM3S_MEMORY FMPRE3 Register Definitions */
#define LM3S_MEMORY_FMPRE3_READ_ENABLE_Pos        0
#define LM3S_MEMORY_FMPRE3_READ_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPRE3_READ_ENABLE_Pos*/)

/* LM3S_MEMORY FMPPE0 Register Definitions */
#define LM3S_MEMORY_FMPPE0_PROG_ENABLE_Pos        0
#define LM3S_MEMORY_FMPPE0_PROG_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPPE0_PROG_ENABLE_Pos*/)

/* LM3S_MEMORY FMPPE1 Register Definitions */
#define LM3S_MEMORY_FMPPE1_PROG_ENABLE_Pos        0
#define LM3S_MEMORY_FMPPE1_PROG_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPPE1_PROG_ENABLE_Pos*/)

/* LM3S_MEMORY FMPPE2 Register Definitions */
#define LM3S_MEMORY_FMPPE2_PROG_ENABLE_Pos        0
#define LM3S_MEMORY_FMPPE2_PROG_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPPE2_PROG_ENABLE_Pos*/)

/* LM3S_MEMORY FMPPE3 Register Definitions */
#define LM3S_MEMORY_FMPPE3_PROG_ENABLE_Pos        0
#define LM3S_MEMORY_FMPPE3_PROG_ENABLE_Msk       (0xFFFFFFFFUL /*<< LM3S_MEMORY_FMPPE3_PROG_ENABLE_Pos*/)

/* LM3S_MEMORY BOOTCFG Register Definitions */
#define LM3S_MEMORY_BOOTCFG_NW_Pos               31
#define LM3S_MEMORY_BOOTCFG_NW_Msk               (1UL << LM3S_MEMORY_BOOTCFG_NW_Pos)

#define LM3S_MEMORY_BOOTCFG_PORT_Pos             13
#define LM3S_MEMORY_BOOTCFG_PORT_Msk             (0x00000007UL << LM3S_MEMORY_BOOTCFG_PORT_Pos)

#define LM3S_MEMORY_BOOTCFG_PIN_Pos              10
#define LM3S_MEMORY_BOOTCFG_PIN_Msk              (0x00000007UL << LM3S_MEMORY_BOOTCFG_PIN_Pos)

#define LM3S_MEMORY_BOOTCFG_POL_Pos               9
#define LM3S_MEMORY_BOOTCFG_POL_Msk              (1UL << LM3S_MEMORY_BOOTCFG_POL_Pos)

#define LM3S_MEMORY_BOOTCFG_EN_Pos                8
#define LM3S_MEMORY_BOOTCFG_EN_Msk               (1UL << LM3S_MEMORY_BOOTCFG_EN_Pos)

#define LM3S_MEMORY_BOOTCFG_DBG1_Pos              1
#define LM3S_MEMORY_BOOTCFG_DBG1_Msk             (1UL << LM3S_MEMORY_BOOTCFG_DBG1_Pos)

#define LM3S_MEMORY_BOOTCFG_DBG0_Pos              0
#define LM3S_MEMORY_BOOTCFG_DBG0_Msk             (1UL /*<< LM3S_MEMORY_BOOTCFG_DBG0_Pos*/)

/* LM3S_MEMORY USER REG0 Register Definitions */
#define LM3S_MEMORY_USER_REG0_DATA_Pos            0
#define LM3S_MEMORY_USER_REG0_DATA_Msk           (0x7FFFFFFFUL /*<< LM3S_MEMORY_USER_REG0_DATA_Pos*/)

/* LM3S_MEMORY USER REG1 Register Definitions */
#define LM3S_MEMORY_USER_REG1_DATA_Pos            0
#define LM3S_MEMORY_USER_REG1_DATA_Msk           (0x7FFFFFFFUL /*<< LM3S_MEMORY_USER_REG1_DATA_Pos*/)

/* LM3S_MEMORY USER REG2 Register Definitions */
#define LM3S_MEMORY_USER_REG2_DATA_Pos            0
#define LM3S_MEMORY_USER_REG2_DATA_Msk           (0x7FFFFFFFUL /*<< LM3S_MEMORY_USER_REG2_DATA_Pos*/)

/* LM3S_MEMORY USER REG3 Register Definitions */
#define LM3S_MEMORY_USER_REG3_DATA_Pos            0
#define LM3S_MEMORY_USER_REG3_DATA_Msk           (0x7FFFFFFFUL /*<< LM3S_MEMORY_USER_REG3_DATA_Pos*/)

/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* ========================================================================= */
/* ============     Device Specific Peripheral Address Map      ============ */
/* ========================================================================= */

/* Peripheral and SRAM base address */
#define LM3S_FLASH_BASE       (0x00000000UL)               /* (FLASH           ) Base Address */
#define LM3S_SRAM_BASE        (0x20000000UL)               /* (SRAM            ) Base Address */
#define LM3S_PERIPH_BASE      (0x40000000UL)               /* (Peripheral      ) Base Address */

/* Peripheral memory map */
#define LM3S_WDT0_BASE        (LM3S_PERIPH_BASE)           /* (Watchdog Timer 0) Base Address */
#define LM3S_WDT1_BASE        (LM3S_PERIPH_BASE + 0x1000)  /* (Watchdog Timer 1) Base Address */

#define LM3S_GPIOA_BASE       (LM3S_PERIPH_BASE + 0x4000)  /* (GPIO A          ) Base Address */
#define LM3S_GPIOB_BASE       (LM3S_PERIPH_BASE + 0x5000)  /* (GPIO B          ) Base Address */
#define LM3S_GPIOC_BASE       (LM3S_PERIPH_BASE + 0x6000)  /* (GPIO C          ) Base Address */
#define LM3S_GPIOD_BASE       (LM3S_PERIPH_BASE + 0x7000)  /* (GPIO D          ) Base Address */

#define LM3S_SSI0_BASE        (LM3S_PERIPH_BASE + 0x8000)  /* (SSI 0           ) Base Address */
#define LM3S_SSI1_BASE        (LM3S_PERIPH_BASE + 0x9000)  /* (SSI 1           ) Base Address */

#define LM3S_UART0_BASE       (LM3S_PERIPH_BASE + 0xC000)  /* (UART 0          ) Base Address */
#define LM3S_UART1_BASE       (LM3S_PERIPH_BASE + 0xD000)  /* (UART 1          ) Base Address */
#define LM3S_UART2_BASE       (LM3S_PERIPH_BASE + 0xE000)  /* (UART 1          ) Base Address */

#define LM3S_I2C0_BASE        (LM3S_PERIPH_BASE + 0x20000) /* (I2C 0           ) Base Address */
#define LM3S_I2C1_BASE        (LM3S_PERIPH_BASE + 0x21000) /* (I2C 1           ) Base Address */

#define LM3S_GPIOE_BASE       (LM3S_PERIPH_BASE + 0x24000) /* (GPIO E          ) Base Address */
#define LM3S_GPIOF_BASE       (LM3S_PERIPH_BASE + 0x25000) /* (GPIO F          ) Base Address */
#define LM3S_GPIOG_BASE       (LM3S_PERIPH_BASE + 0x26000) /* (GPIO G          ) Base Address */
#define LM3S_GPIOH_BASE       (LM3S_PERIPH_BASE + 0x27000) /* (GPIO H          ) Base Address */

#define LM3S_PWM_BASE         (LM3S_PERIPH_BASE + 0x28000) /* (PWM             ) Base Address */

#define LM3S_QEI0_BASE        (LM3S_PERIPH_BASE + 0x2C000) /* (QEI 0           ) Base Address */
#define LM3S_QEI1_BASE        (LM3S_PERIPH_BASE + 0x2D000) /* (QEI 1           ) Base Address */

#define LM3S_GPTM0_BASE       (LM3S_PERIPH_BASE + 0x30000) /* (G-P Timer 0     ) Base Address */
#define LM3S_GPTM1_BASE       (LM3S_PERIPH_BASE + 0x31000) /* (G-P Timer 1     ) Base Address */
#define LM3S_GPTM2_BASE       (LM3S_PERIPH_BASE + 0x32000) /* (G-P Timer 2     ) Base Address */
#define LM3S_GPTM3_BASE       (LM3S_PERIPH_BASE + 0x33000) /* (G-P Timer 3     ) Base Address */

#define LM3S_ADC0_BASE        (LM3S_PERIPH_BASE + 0x38000) /* (ADC 0           ) Base Address */
#define LM3S_ADC1_BASE        (LM3S_PERIPH_BASE + 0x39000) /* (ADC 1           ) Base Address */

#define LM3S_AC_BASE          (LM3S_PERIPH_BASE + 0x3C000) /* (Analog Comps    ) Base Address */

#define LM3S_GPIOJ_BASE       (LM3S_PERIPH_BASE + 0x3D000) /* (GPIO J          ) Base Address */

#define LM3S_CAN0_BASE        (LM3S_PERIPH_BASE + 0x40000) /* (CAN 0           ) Base Address */
#define LM3S_CAN1_BASE        (LM3S_PERIPH_BASE + 0x41000) /* (CAN 1           ) Base Address */

#define LM3S_ETH_BASE         (LM3S_PERIPH_BASE + 0x48000) /* (Ethernet        ) Base Address */

#define LM3S_USB_BASE         (LM3S_PERIPH_BASE + 0x50000) /* (USB             ) Base Address */

#define LM3S_I2S_BASE         (LM3S_PERIPH_BASE + 0x54000) /* (I2S             ) Base Address */

#define LM3S_GPIOA_AHB_BASE   (LM3S_PERIPH_BASE + 0x58000) /* (GPIO A AHB      ) Base Address */
#define LM3S_GPIOB_AHB_BASE   (LM3S_PERIPH_BASE + 0x59000) /* (GPIO B AHB      ) Base Address */
#define LM3S_GPIOC_AHB_BASE   (LM3S_PERIPH_BASE + 0x5A000) /* (GPIO C AHB      ) Base Address */
#define LM3S_GPIOD_AHB_BASE   (LM3S_PERIPH_BASE + 0x5B000) /* (GPIO D AHB      ) Base Address */
#define LM3S_GPIOE_AHB_BASE   (LM3S_PERIPH_BASE + 0x5C000) /* (GPIO E AHB      ) Base Address */
#define LM3S_GPIOF_AHB_BASE   (LM3S_PERIPH_BASE + 0x5D000) /* (GPIO F AHB      ) Base Address */
#define LM3S_GPIOG_AHB_BASE   (LM3S_PERIPH_BASE + 0x5E000) /* (GPIO G AHB      ) Base Address */
#define LM3S_GPIOH_AHB_BASE   (LM3S_PERIPH_BASE + 0x5F000) /* (GPIO H AHB      ) Base Address */
#define LM3S_GPIOJ_AHB_BASE   (LM3S_PERIPH_BASE + 0x60000) /* (GPIO J AHB      ) Base Address */

#define LM3S_EPI_BASE         (LM3S_PERIPH_BASE + 0xD0000) /* (EPI 0           ) Base Address */

#define LM3S_FLASHCTL_BASE    (LM3S_PERIPH_BASE + 0xFD000) /* (FLASH Control   ) Base Address */
#define LM3S_MEMORY_BASE      (LM3S_PERIPH_BASE + 0xFE000) /* (MEMORY Control  ) Base Address */
#define LM3S_SYSCTL_BASE      (LM3S_PERIPH_BASE + 0xFE000) /* (System Control  ) Base Address */
#define LM3S_UDMA_BASE        (LM3S_PERIPH_BASE + 0xFF000) /* (uDMA            ) Base Address */

/* ========================================================================= */
/* ============             Peripheral declaration              ============ */
/* ========================================================================= */

#define LM3S_WDT0        ((LM3S_WDT_TypeDef    *) LM3S_WDT0_BASE      )
#define LM3S_WDT1        ((LM3S_WDT_TypeDef    *) LM3S_WDT1_BASE      )
#define LM3S_GPIOA       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOA_BASE     )
#define LM3S_GPIOB       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOB_BASE     )
#define LM3S_GPIOC       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOC_BASE     )
#define LM3S_GPIOD       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOD_BASE     )
#define LM3S_SSI0        ((LM3S_SSI_TypeDef    *) LM3S_SSI0_BASE      )
#define LM3S_SSI1        ((LM3S_SSI_TypeDef    *) LM3S_SSI1_BASE      )
#define LM3S_UART0       ((LM3S_UART_TypeDef   *) LM3S_UART0_BASE     )
#define LM3S_UART1       ((LM3S_UART_TypeDef   *) LM3S_UART1_BASE     )
#define LM3S_UART2       ((LM3S_UART_TypeDef   *) LM3S_UART2_BASE     )
#define LM3S_I2C0        ((LM3S_I2C_TypeDef    *) LM3S_I2C0_BASE      )
#define LM3S_I2C1        ((LM3S_I2C_TypeDef    *) LM3S_I2C1_BASE      )
#define LM3S_GPIOE       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOE_BASE     )
#define LM3S_GPIOF       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOF_BASE     )
#define LM3S_GPIOG       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOG_BASE     )
#define LM3S_GPIOH       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOH_BASE     )
#define LM3S_PWM         ((LM3S_PWM_TypeDef    *) LM3S_PWM_BASE       )
#define LM3S_QEI0        ((LM3S_QEI_TypeDef    *) LM3S_QEI0_BASE      )
#define LM3S_QEI1        ((LM3S_QEI_TypeDef    *) LM3S_QEI1_BASE      )
#define LM3S_GPTM0       ((LM3S_GPTM_TypeDef   *) LM3S_GPTM0_BASE     )
#define LM3S_GPTM1       ((LM3S_GPTM_TypeDef   *) LM3S_GPTM1_BASE     )
#define LM3S_GPTM2       ((LM3S_GPTM_TypeDef   *) LM3S_GPTM2_BASE     )
#define LM3S_GPTM3       ((LM3S_GPTM_TypeDef   *) LM3S_GPTM3_BASE     )
#define LM3S_ADC0        ((LM3S_ADC_TypeDef    *) LM3S_ADC0_BASE      )
#define LM3S_ADC1        ((LM3S_ADC_TypeDef    *) LM3S_ADC1_BASE      )
#define LM3S_AC          ((LM3S_AC_TypeDef     *) LM3S_AC_BASE        )
#define LM3S_GPIOJ       ((LM3S_GPIO_TypeDef   *) LM3S_GPIOJ_BASE     )
#define LM3S_CAN0        ((LM3S_CAN_TypeDef    *) LM3S_CAN0_BASE      )
#define LM3S_CAN1        ((LM3S_CAN_TypeDef    *) LM3S_CAN1_BASE      )
#define LM3S_ETH         ((LM3S_ETHMAC_TypeDef *) LM3S_ETH_BASE       )
#define LM3S_USB         ((LM3S_USB_TypeDef    *) LM3S_USB_BASE       )
#define LM3S_I2S         ((LM3S_I2S_TypeDef    *) LM3S_I2S_BASE       )
#define LM3S_GPIOA_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOA_AHB_BASE )
#define LM3S_GPIOB_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOB_AHB_BASE )
#define LM3S_GPIOC_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOC_AHB_BASE )
#define LM3S_GPIOD_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOD_AHB_BASE )
#define LM3S_GPIOE_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOE_AHB_BASE )
#define LM3S_GPIOF_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOF_AHB_BASE )
#define LM3S_GPIOG_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOG_AHB_BASE )
#define LM3S_GPIOH_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOH_AHB_BASE )
#define LM3S_GPIOJ_AHB   ((LM3S_GPIO_TypeDef   *) LM3S_GPIOJ_AHB_BASE )
#define LM3S_EPI0        ((LM3S_EPI_TypeDef    *) LM3S_EPI_BASE       )
#define LM3S_FLASHCTL    ((LM3S_FLASH_TypeDef  *) LM3S_FLASHCTL_BASE  )
#define LM3S_MEMORY      ((LM3S_MEMORY_TypeDef *) LM3S_MEMORY_BASE    )
#define LM3S_SYSCTL      ((LM3S_SYSCTL_TypeDef *) LM3S_SYSCTL_BASE    )
#define LM3S_UDMA        ((LM3S_UDMA_TypeDef   *) LM3S_UDMA_BASE      )

#ifdef __cplusplus
}
#endif

#endif  /* LM3S9B92_H */
