/******************************************************************************
 * @file     startup_lm3s9b92.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device LM3S9B92
 * @version  V1.0.0
 * @date     20. September 2025
 ******************************************************************************/
/*
 * Copyright (c) TODO: set copyright
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

#include "lm3s9b92.h"

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);

/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SecureFault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void GPIOA_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOB_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOC_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOD_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOE_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART0_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART1_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM0Fault_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM0_0_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM0_1_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM0_2_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC0SS0_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC0SS1_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC0SS2_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC0SS3_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void WDT0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM0A_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM0B_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1A_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM1B_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2A_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM2B_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP0_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP1_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void COMP2_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void SYSCTL_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void FLASH_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOF_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOG_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOH_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void UART2_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void SSI1_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3A_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void TIM3B_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));
void I2C1_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void QEI1_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN1_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void CAN2_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void ETH0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void HIB_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void USB0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void PWM0_3_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void UDMA_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void UDMAError_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1SS0_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1SS1_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1SS2_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void ADC1SS3_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));
void I2S0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void EPI0_Handler           (void) __attribute__ ((weak, alias("Default_Handler")));
void GPIOJ_Handler          (void) __attribute__ ((weak, alias("Default_Handler")));

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[72];
       const VECTOR_TABLE_Type __VECTOR_TABLE[72] __VECTOR_TABLE_ATTRIBUTE = {
  (VECTOR_TABLE_Type)(&__INITIAL_SP),  /*     Initial Stack Pointer */
  Reset_Handler,                       /*     Reset Handler */
  NMI_Handler,                         /* -14 NMI Handler */
  HardFault_Handler,                   /* -13 Hard Fault Handler */
  MemManage_Handler,                   /* -12 MPU Fault Handler */
  BusFault_Handler,                    /* -11 Bus Fault Handler */
  UsageFault_Handler,                  /* -10 Usage Fault Handler */
  SecureFault_Handler,                 /*  -9 Secure Fault Handler */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  SVC_Handler,                         /*  -5 SVCall Handler */
  DebugMon_Handler,                    /*  -4 Debug Monitor Handler */
  0,                                   /*     Reserved */
  PendSV_Handler,                      /*  -2 PendSV Handler */
  SysTick_Handler,                     /*  -1 SysTick Handler */

  GPIOA_Handler,                       /*   0 GPIOA Handler */
  GPIOB_Handler,                       /*   1 GPIOB Handler */
  GPIOC_Handler,                       /*   2 GPIOC Handler */
  GPIOD_Handler,                       /*   3 GPIOD Handler */
  GPIOE_Handler,                       /*   4 GPIOE Handler */
  UART0_Handler,                       /*   5 UART0 Handler */
  UART1_Handler,                       /*   6 UART1 Handler */
  SSI0_Handler,                        /*   7 SSI0 Handler */
  I2C0_Handler,                        /*   8 I2C0 Handler */
  PWM0Fault_Handler,                   /*   9 PWM0 Fault Handler */
  PWM0_0_Handler,                      /*  10 PWM0 Generator 0 Handler */
  PWM0_1_Handler,                      /*  11 PWM0 Generator 1 Handler */
  PWM0_2_Handler,                      /*  12 PWM0 Generator 2 Handler */
  QEI0_Handler,                        /*  13 Quadrature Encoder 0 Handler */
  ADC0SS0_Handler,                     /*  14 ADC0 Sequence 0 Handler */
  ADC0SS1_Handler,                     /*  15 ADC0 Sequence 1 Handler */
  ADC0SS2_Handler,                     /*  16 ADC0 Sequence 2 Handler */
  ADC0SS3_Handler,                     /*  17 ADC0 Sequence 3 Handler */
  WDT0_Handler,                        /*  18 Watchdog Timer 0 Handler */
  TIM0A_Handler,                       /*  19 Timer 0 Subtimer A Handler */
  TIM0B_Handler,                       /*  20 Timer 0 Subtimer B Handler */
  TIM1A_Handler,                       /*  21 Timer 1 Subtimer A Handler */
  TIM1B_Handler,                       /*  22 Timer 1 Subtimer B Handler */
  TIM2A_Handler,                       /*  23 Timer 2 Subtimer A Handler */
  TIM2B_Handler,                       /*  24 Timer 2 Subtimer B Handler */
  COMP0_Handler,                       /*  25 Analog Comparator 0 Handler */
  COMP1_Handler,                       /*  26 Analog Comparator 1 Handler */
  COMP2_Handler,                       /*  27 Analog Comparator 2 Handler */
  SYSCTL_Handler,                      /*  28 System Cortrol Handler */
  FLASH_Handler,                       /*  29 FLASH Handler */
  GPIOF_Handler,                       /*  30 GPIOF Handler */
  GPIOG_Handler,                       /*  31 GPIOG Handler */
  GPIOH_Handler,                       /*  32 GPIOH Handler */
  UART2_Handler,                       /*  33 UART2 Handler */
  SSI1_Handler,                        /*  34 SSI1 Handler */
  TIM3A_Handler,                       /*  35 Timer 3 Subtimer A Handler */
  TIM3B_Handler,                       /*  36 Timer 3 Subtimer B Handler */
  I2C1_Handler,                        /*  37 I2C1 Handler */
  QEI1_Handler,                        /*  38 Quadrature Encoder 1 Handler */
  CAN0_Handler,                        /*  39 CAN0 Handler */
  CAN1_Handler,                        /*  40 CAN1 Handler */
  CAN2_Handler,                        /*  41 CAN2 Handler */
  ETH0_Handler,                        /*  42 Ethernet 0 Handler */
  HIB_Handler,                         /*  43 Hibernation module Handler */
  USB0_Handler,                        /*  44 USB0 Handler */
  PWM0_3_Handler,                      /*  45 PWM0 Generator 3 Handler */
  UDMA_Handler,                        /*  46 uDMA Handler */
  UDMAError_Handler,                   /*  47 uDMA Error Handler */
  ADC1SS0_Handler,                     /*  48 ADC1 Sequence 0 Handler */
  ADC1SS1_Handler,                     /*  49 ADC1 Sequence 1 Handler */
  ADC1SS2_Handler,                     /*  50 ADC1 Sequence 2 Handler */
  ADC1SS3_Handler,                     /*  51 ADC1 Sequence 3 Handler */
  I2S0_Handler,                        /*  52 I2S0 Handler */
  EPI0_Handler,                        /*  53 External Peripheral Interface Handler */
  GPIOJ_Handler,                       /*  54 GPIOJ Handler */
  0                                    /*     Reserved */ 
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
  __set_PSP((uint32_t)(&__INITIAL_SP));

  SystemInit();                    /* CMSIS System Initialization */
  __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif
