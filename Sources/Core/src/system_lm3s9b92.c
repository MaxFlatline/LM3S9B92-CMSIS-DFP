/*************************************************************************//**
 * @file     system_lm3s9b92.c
 * @brief    CMSIS-Core(M) Device Peripheral Access Layer Source File for
 *           Device LM3S9B92
 * @version  V1.0.0
 * @date     20. September 2025
 *****************************************************************************/
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
 
#include <stdint.h>
#include "lm3s9b92.h"


/*----------------------------------------------------------------------------
  DEFINES
 *----------------------------------------------------------------------------*/
//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
//
// This file can be used by the Keil uVision configuration wizard to set
// the following system clock configuration values.  Or the value of the
// macros can be directly edited below if not using the uVision configuration
// wizard.
//
//--------------------- Clock Configuration ----------------------------------
//
//  <e> Clock Configuration
//          <i> Uncheck this box to skip the clock configuration.
//
// The following controls whether the system clock is configured in the
// SystemInit() function.  If it is defined to be 1 then the system clock
// will be configured according to the macros in the rest of this file.
// If it is defined to be 0, then the system clock configuration is bypassed.
//
#define CLOCK_SETUP 1

//********************************* RCC ***************************************
//
//  <h> Run-Mode Clock Configuration (RCC)

//      <o> SYSDIV: System Clock Divisor <2-16>
//          <i> Specifies the divisor used to generate the system clock from
//          <i> either the PLL output of 200 MHz, or the chosen oscillator.
//
// The following value is the system clock divisor.  This will be applied if
// USESYSDIV (see below) is enabled.  The valid range of dividers is 2-16.
//
#define CFG_RCC_SYSDIV 4

//      <q> USESYSDIV: Enable System Clock Divider
//          <i> Check this box to use the System Clock Divider
//
// The following controls whether the system clock divider is used.  If the
// value is 1, then the system clock divider is used, and the value of the
// system divider is defined by SYSDIV (see above).  If the value is 0, then
// the system clock divider is not used.
//
#define CFG_RCC_USESYSDIV 1

//      <q> USEPWMDIV: Enable PWM Clock Divider
//          <i> Check this box to use the PWM Clock Divider
//
// The following controls whether the PWM clock divider is used.  If the
// value is 1, then the PWM clock divider is used, and the value of the
// PWM divider is defined by PWMDIV (see below).  If the value is 0, then
// the PWM clock divider is not used.
//
#define CFG_RCC_USEPWMDIV 0

//      <o> PWMDIV: PWM Unit Clock Divisor
//              <0=> 0: SysClk / 2
//              <1=> 1: SysClk / 4
//              <2=> 2: SysClk / 8
//              <3=> 3: SysClk / 16
//              <4=> 4: SysClk / 32
//              <5=> 5: SysClk / 64
//              <6=> 6: SysClk / 64
//              <7=> 7: SysClk / 64 (default)
//          <i> Specifies the divisor used to generate the PWM time base,
//          <i> from the System Clock
//
// The following value determines the PWM clock divider.  It is used if
// USEPWMDIV is enabled (see above).  Otherwise the PWM clock is the same as
// the system clock.  The value of the divider is determined by the table
// above.
//
#define CFG_RCC_PWMDIV 0

//      <q> PWRDN: PLL Power Down
//          <i> Check this box to disable the PLL.  You must also choose
//          <i> PLL Bypass.
//
// If the following value is 1, then the PLL is powered down.  Keep this value
// as 1 if you do not need to use the PLL.  In this case, BYPASS (see below)
// must also be set to 1.  If you are using the PLL, then this value must be
// set to 0.
//
#define CFG_RCC_PWRDN 0

//      <q> BYPASS: PLL Bypass
//          <i> Check this box to not use the PLL for the System Clock
//
// Set the following value to 1 to bypass the PLL and not use it for the
// system clock.  You must set this to 1 if PWRDN (above) is set to 1.  Set
// this to 0 if you are using the PLL.
//
#define CFG_RCC_BYPASS 0

//      <o> XTAL: Crystal Value
//              < 0=>  0: 1.0000 MHz  (can not be used with PLL)
//              < 1=>  1: 1.8432 MHz  (can not be used with PLL)
//              < 2=>  2: 2.0000 MHz  (can not be used with PLL)
//              < 3=>  3: 2.4576 MHz  (can not be used with PLL)
//              < 4=>  4: 3.579545 MHz
//              < 5=>  5: 3.6864 MHz
//              < 6=>  6: 4.0000 MHz
//              < 7=>  7: 4.096 MHz
//              < 8=>  8: 4.9152 MHz
//              < 9=>  9: 5.0000 MHz
//              <10=> 10: 5.12 MHz
//              <11=> 11: 6.0000 MHz (default)
//              <12=> 12: 6.144 MHz
//              <13=> 13: 7.3728 MHz
//              <14=> 14: 8.0000 MHz
//              <15=> 15: 8.192 MHz
//              <16=> 16: 10.0 MHz
//              <17=> 17: 12.0 MHz
//              <18=> 18: 12.288 MHz
//              <19=> 19: 13.56 MHz
//              <20=> 20: 14.31818 MHz
//              <21=> 21: 16.0 MHz
//              <22=> 22: 16.384 MHz
//          <i> This is the crystal frequency used for the main oscillator
//
// This value defines the crystal frequency for the main oscillator, according
// to the table in the comments above.  If an external crystal is used, then
// this value must be set to match the value of the crystal.
//
#define CFG_RCC_XTAL 21

//      <o> OSCSRC: Oscillator Source
//              <0=> 0: MOSC Main oscillator
//              <1=> 1: IOSC Internal oscillator (default)
//              <2=> 2: IOSC/4 Internal oscillator / 4 (this is necessary if used as input to PLL)
//              <3=> 3: 30kHz 30-KHz internal oscillator
//          <i> Chooses the oscillator that is used for the system clock,
//          <i> or the PLL input.
//
// The following value chooses the oscillator source according to the table in
// the comments above.
//
#define CFG_RCC_OSCSRC 0

//      <q> IOSCDIS: Internal Oscillator Disable
//          <i> Check this box to turn off the internal oscillator
//
// Set the following value to 1 to turn off the internal oscillator.  This
// value can be set to 1 if you are not using the internal oscillator.
//
#define CFG_RCC_IOSCDIS 1

//      <q> MOSCDIS: Main Oscillator Disable
//          <i> Check this box to turn off the main oscillator
//
// Set the following value to 1 to turn off the main oscillator.  This
// value can be set to 1 if you are not using the main oscillator.
//
#define CFG_RCC_MOSCDIS 0

//  </h>

//********************************* RCC2 **************************************
//
//   <h> Run-Mode Clock Configuration 2 (RCC2)

//      <q> USERCC2: Use RCC2
//          <i> Check this box to override some fields in RCC.  RCC2 provides
//          <i> more bits for the system clock divider, and provides an
//          <i> additional oscillator source.  If you do not need these
//          <i> additional features, then leave this box unchecked.
//
// Set the following value to 1 to use the RCC2 register.  The RCC2 register
// overrides some of the fields in the RCC register if it is used.
//
#define CFG_RCC2_USERCC2 1

//      <o> SYSDIV2: System Clock Divisor <2-64>
//          <i> Specifies the divisor used to generate the system clock from
//          <i> either the PLL output of 200 MHz, or the oscillator.
//
// The following value is the system clock divisor.  This will be applied if
// USESYSDIV in RCC is enabled.  The valid range of dividers is 2-64.
//
#define CFG_RCC_SYSDIV2 4

//      <q> PWRDN2: Power Down PLL
//          <i> Check this box to disable the PLL.  You must also choose
//          <i> PLL Bypass.
//
// If the following value is 1, then the PLL is powered down.  Keep this value
// as 1 if you do not need to use the PLL.  In this case, BYPASS2 (see below)
// must also be set to 1.  If you are using the PLL, then this value must be
// set to 0.
//
#define CFG_RCC_PWRDN2 0

//      <q> BYPASS2: Bypass PLL
//          <i> Check this box to not use the PLL for the System Clock
//
// Set the following value to 1 to bypass the PLL and not use it for the
// system clock.  You must set this to 1 if PWRDN2 (above) is set to 1.  Set
// this to 0 if you are using the PLL.
//
#define CFG_RCC_BYPASS2 0

//      <o> OSCSRC2: Oscillator Source
//              <0=> 0: MOSC Main oscillator
//              <1=> 1: IOSC Internal oscillator (default)
//              <2=> 2: IOSC/4 Internal oscillator / 4 (this is necessary if used as input to PLL)
//              <3=> 3: 30kHz 30-kHz internal oscillator
//              <7=> 7: 32kHz 32.768-kHz external oscillator
//          <i> The oscillator that is used for the system clock, or the PLL input.
//
// The following value chooses the oscillator source according to the table in
// the comments above.
//
#define CFG_RCC_OSCSRC2 0

//  </h>
//
//  </e>

//-------- <<< end of configuration section >>> ------------------------------

//
// The following macros are used to program the RCC and RCC2 registers in
// the SystemInit() function.  Edit the macros above to change these values.
//
#define RCC_Val                                                               \
(                                                                             \
    ((CFG_RCC_SYSDIV - 1)   << 23) |                                          \
    (CFG_RCC_USESYSDIV      << 22) |                                          \
    (CFG_RCC_USEPWMDIV      << 20) |                                          \
    (CFG_RCC_PWMDIV         << 17) |                                          \
    (CFG_RCC_PWRDN          << 13) |                                          \
    (CFG_RCC_BYPASS         << 11) |                                          \
    (CFG_RCC_XTAL           << 6)  |                                          \
    (CFG_RCC_OSCSRC         << 4)  |                                          \
    (CFG_RCC_IOSCDIS        << 1)  |                                          \
    (CFG_RCC_MOSCDIS        << 1)\
)

#define RCC2_Val                                                              \
(                                                                             \
    (CFG_RCC2_USERCC2      << 31) |                                           \
    ((CFG_RCC_SYSDIV2 - 1)  << 23) |                                          \
    (CFG_RCC_PWRDN2         << 13) |                                          \
    (CFG_RCC_BYPASS2        << 11) |                                          \
    (CFG_RCC_OSCSRC2        << 4)\
)


/*----------------------------------------------------------------------------
  Define clocks
 *----------------------------------------------------------------------------*/
#define XTAL_PIOSC_16MHZ           (16000000UL)
#define XTAL_INT30KHZ                 (30000UL)

#define XTAL_EXT_1MHZ_PLLOFF        (1000000UL)
#define XTAL_EXT_1_8432MHZ_PLLOFF   (1843200UL)
#define XTAL_EXT_2MHZ_PLLOFF        (2000000UL)
#define XTAL_EXT_2_4576MHZ_PLLOFF   (2457600UL)
#define XTAL_EXT_3_579545MHZ        (3579545UL)
#define XTAL_EXT_3_6864MHZ          (3686400UL)
#define XTAL_EXT_4MHZ               (4000000UL)
#define XTAL_EXT_4_096MHZ           (4096000UL)
#define XTAL_EXT_4_9152MHZ          (4915200UL)
#define XTAL_EXT_5MHZ               (5000000UL)
#define XTAL_EXT_5_12MHZ            (5120000UL)
#define XTAL_EXT_6MHZ_USB           (6000000UL)
#define XTAL_EXT_6_144MHZ           (6144000UL)
#define XTAL_EXT_7_3728MHZ          (7372800UL)
#define XTAL_EXT_8MHZ_USB           (8000000UL)
#define XTAL_EXT_8_192MHZ           (8192000UL)
#define XTAL_EXT_10MHZ_USB         (10000000UL)
#define XTAL_EXT_12MHZ_USB         (12000000UL)
#define XTAL_EXT_12_288MHZ         (12288000UL)
#define XTAL_EXT_13_56MHZ          (13560000UL)
#define XTAL_EXT_14_31818MHZ       (14318180UL)
#define XTAL_EXT_16MHZ_USB         (16000000UL)
#define XTAL_EXT_16_384MHZ         (16384000UL)

#define XTAL_EXT_32768HZ              (32768UL)



#define VCO_CLK                   (400000000UL)
#define VCO_PREDDIV2_CLK          (200000000UL)

#define ADC_CLK                    (VCO_CLK/25)


#define MINSYSDIV_VCO400_DIV_5   (0x00000001UL)
#define MINSYSDIV_VCO400_DIV_6   (0x00000002UL)
#define MINSYSDIV_50MHZ_DIV4     (0x00000003UL)
#define MINSYSDIV_25MHZ_DIV8     (0x00000007UL)
#define MINSYSDIV_20MHZ_DIV10    (0x00000009UL)

 /* Determine clock frequency according to clock register values */
  #if (RCC2_Val & (1UL<<31))                              /* is rcc2 used ? */
    #if (RCC2_Val & (1UL<<11))                           /* check BYPASS */
              #if   (((RCC2_Val>>4) & 0x07) == 0x0)
                #if   (((RCC_Val>>6) & 0x1F) == 0x0)
                      #define __CORE_CLK_PRE  XTAL_1MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x1)
                      #define __CORE_CLK_PRE  XTAL_1_8432MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x2)
                      #define __CORE_CLK_PRE  XTAL_2MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x3)
                      #define __CORE_CLK_PRE  XTAL_2_4576MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x4)
                      #define __CORE_CLK_PRE  XTAL_3_579545MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x5)
                      #define __CORE_CLK_PRE  XTAL_3_6864MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x6)
                      #define __CORE_CLK_PRE  XTAL_4MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x7)
                      #define __CORE_CLK_PRE  XTAL_4_096MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x8)
                      #define __CORE_CLK_PRE  XTAL_4_9152MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x9)
                      #define __CORE_CLK_PRE  XTAL_5MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xA)
                      #define __CORE_CLK_PRE  XTAL_5_12MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xB)
                      #define __CORE_CLK_PRE  XTAL_6MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0xC)
                      #define __CORE_CLK_PRE  XTAL_6_144MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xD)
                      #define __CORE_CLK_PRE  XTAL_7_3728MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xE)
                      #define __CORE_CLK_PRE  XTAL_8MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0xF)
                      #define __CORE_CLK_PRE  XTAL_8_192MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x10)
                      #define __CORE_CLK_PRE  XTAL_10MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0x11)
                      #define __CORE_CLK_PRE  XTAL_12MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0x12)
                      #define __CORE_CLK_PRE  XTAL_12_288MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x13)
                      #define __CORE_CLK_PRE  XTAL_13_56MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x14)
                      #define __CORE_CLK_PRE  XTAL_14_31818MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x15)
                      #define __CORE_CLK_PRE  XTAL_16MHZ_USB
                #else
                      #define __CORE_CLK_PRE  XTAL_16_384MHZ
                #endif
              #elif (((RCC2_Val>>4) & 0x07) == 0x1)
                  #define __CORE_CLK_PRE  XTALI
              #elif (((RCC2_Val>>4) & 0x07) == 0x2)
                  #define __CORE_CLK_PRE  (XTALI/4)
              #else
                  #define __CORE_CLK_PRE  XTAL30K
              #endif
    #else
      #define __CORE_CLK_PRE   PLL_CLK
    #endif
    #if (RCC_Val & (1UL<<22))                            /* check USESYSDIV */
      #if (RCC2_Val & (1UL<<11))
        #define __CORE_CLK  (__CORE_CLK_PRE / (((RCC2_Val>>23) & (0x3F)) + 1))
      #else
        #define __CORE_CLK  (__CORE_CLK_PRE / (((RCC2_Val>>23) & (0x3F)) + 1) / 2)
      #endif
    #else
      #define __CORE_CLK  __CORE_CLK_PRE
    #endif
  #else
    #if (RCC_Val & (1UL<<11))                           /* check BYPASS */
              #if   (((RCC_Val>>4) & 0x03) == 0x0)
                #if   (((RCC_Val>>6) & 0x1F) == 0x0)
                      #define __CORE_CLK_PRE  XTAL_1MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x1)
                      #define __CORE_CLK_PRE  XTAL_1_8432MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x2)
                      #define __CORE_CLK_PRE  XTAL_2MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x3)
                      #define __CORE_CLK_PRE  XTAL_2_4576MHZ_PLLOFF
                #elif (((RCC_Val>>6) & 0x1F) == 0x4)
                      #define __CORE_CLK_PRE  XTAL_3_579545MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x5)
                      #define __CORE_CLK_PRE  XTAL_3_6864MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x6)
                      #define __CORE_CLK_PRE  XTAL_4MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x7)
                      #define __CORE_CLK_PRE  XTAL_4_096MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x8)
                      #define __CORE_CLK_PRE  XTAL_4_9152MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x9)
                      #define __CORE_CLK_PRE  XTAL_5MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xA)
                      #define __CORE_CLK_PRE  XTAL_5_12MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xB)
                      #define __CORE_CLK_PRE  XTAL_6MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0xC)
                      #define __CORE_CLK_PRE  XTAL_6_144MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xD)
                      #define __CORE_CLK_PRE  XTAL_7_3728MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0xE)
                      #define __CORE_CLK_PRE  XTAL_8MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0xF)
                      #define __CORE_CLK_PRE  XTAL_8_192MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x10)
                      #define __CORE_CLK_PRE  XTAL_10MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0x11)
                      #define __CORE_CLK_PRE  XTAL_12MHZ_USB
                #elif (((RCC_Val>>6) & 0x1F) == 0x12)
                      #define __CORE_CLK_PRE  XTAL_12_288MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x13)
                      #define __CORE_CLK_PRE  XTAL_13_56MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x14)
                      #define __CORE_CLK_PRE  XTAL_14_31818MHZ
                #elif (((RCC_Val>>6) & 0x1F) == 0x15)
                      #define __CORE_CLK_PRE  XTAL_16MHZ_USB
                #else
                      #define __CORE_CLK_PRE  XTAL_16_384MHZ
                #endif
              #elif (((RCC_Val>>4) & 0x03) == 0x1)
                  #define __CORE_CLK_PRE  XTALI
              #elif (((RCC_Val>>4) & 0x03) == 0x2)
                  #define __CORE_CLK_PRE  (XTALI/4)
              #else
                  #define __CORE_CLK_PRE  XTAL30K
              #endif
    #else
      #define __CORE_CLK_PRE   PLL_CLK
    #endif
    #if (RCC_Val & (1UL<<22))                            /* check USESYSDIV */
      #if (RCC_Val & (1UL<<11))                          /* check BYPASS */
        #define __CORE_CLK  (__CORE_CLK_PRE / (((RCC_Val>>23) & (0x0F)) + 1))
      #else
        #define __CORE_CLK  (__CORE_CLK_PRE / (((RCC_Val>>23) & (0x0F)) + 1) / 2)
      #endif
    #else
      #define __CORE_CLK  __CORE_CLK_PRE
    #endif
  #endif

/*---------------------------------------------------------------------------
  System Core Clock Variable
 *---------------------------------------------------------------------------*/
uint32_t SystemCoreClock;  /* System Clock Frequency (Core Clock)*/

/*---------------------------------------------------------------------------
  Static Core Clock functions
 *---------------------------------------------------------------------------*/
__INLINE static uint32_t getOscClk (uint32_t xtal, uint32_t oscSrc);

/*---------------------------------------------------------------------------
  System Core Clock function
 *---------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void)
{
/* ToDo: Add code to calculate the system frequency based upon the current
         register settings.
         This function can be used to retrieve the system core clock frequeny
         after user changed register sittings. */


    uint32_t rcc, rcc2;
    uint32_t sysdiv, minsysdiv;
    
    /* Determine clock frequency according to clock register values */
    rcc  = LM3S_SYSCTL->RCC;
    rcc2 = LM3S_SYSCTL->RCC2;
    
    
    
    if ((rcc2 & LM3S_SYSCTL_RCC2_USERCC2_Msk) == LM3S_SYSCTL_RCC2_USERCC2_Msk) {
        /* RCC2 is used */
        if((rcc2 & LM3S_SYSCTL_RCC2_BYPASS2_Msk) == LM3S_SYSCTL_RCC2_BYPASS2_Msk) {
            /* PLL is bypassed */
            SystemCoreClock = getOscClk (((rcc & LM3S_SYSCTL_RCC_XTAL_Msk)>>LM3S_SYSCTL_RCC_XTAL_Pos),((rcc2 & LM3S_SYSCTL_RCC2_OSCSRC2_Msk)>>LM3S_SYSCTL_RCC2_OSCSRC2_Pos));
            if((rcc & LM3S_SYSCTL_RCC_USESYSDIV_Msk) == LM3S_SYSCTL_RCC_USESYSDIV_Msk) {
                sysdiv = (rcc & LM3S_SYSCTL_RCC2_SYSDIV2_Msk)>>LM3S_SYSCTL_RCC2_SYSDIV2_Pos;
                /* SYSDIV2 is used */
                if(sysdiv > 0) {
                    /* SYSDIV2 is greater than /2 */
                    SystemCoreClock = VCO_PREDDIV2_CLK / (sysdiv + 1);
                }
                else {
                    /* SYSDIV is 0 - Reserved*/
                    SystemCoreClock = 0;
                }
            }
        }
        else {
            /* PLL is used */
            /* SYSDIV is forced to be used when PLL is selected as the source */
            sysdiv = (rcc & LM3S_SYSCTL_RCC2_SYSDIV2_Msk)>>LM3S_SYSCTL_RCC2_SYSDIV2_Pos;
            /* SYSDIV2 is used */
            if(sysdiv > 1) {
                /* SYSDIV2 is greater than /2 */
                SystemCoreClock = VCO_PREDDIV2_CLK / (sysdiv + 1);
            }
            else {
                /* SYSDIV2 is less than 2 - Reserved*/
                SystemCoreClock = 0;
            }
        }
    }
    else {
        /* RCC2 is unused */
        if((rcc & LM3S_SYSCTL_RCC_BYPASS_Msk) == LM3S_SYSCTL_RCC_BYPASS_Msk) {
            /* PLL is bypassed */
            SystemCoreClock = getOscClk (((rcc & LM3S_SYSCTL_RCC_XTAL_Msk)>>LM3S_SYSCTL_RCC_XTAL_Pos),((rcc & LM3S_SYSCTL_RCC_OSCSRC_Msk)>>LM3S_SYSCTL_RCC_OSCSRC_Pos));
            if((rcc & LM3S_SYSCTL_RCC_USESYSDIV_Msk) == LM3S_SYSCTL_RCC_USESYSDIV_Msk) {
                sysdiv = (rcc & LM3S_SYSCTL_RCC_SYSDIV_Msk)>>LM3S_SYSCTL_RCC_SYSDIV_Pos;
                /* SYSDIV is used */
                if(sysdiv > 0) {
                    /* SYSDIV is greater than /2 */
                    SystemCoreClock = VCO_PREDDIV2_CLK / (sysdiv + 1);
                }
                else {
                    /* SYSDIV is 0 - Reserved*/
                    SystemCoreClock = 0;
                }
            }
        }
        else {
            /* PLL is used */
            /* SYSDIV is forced to be used when PLL is selected as the source */
            sysdiv = (rcc & LM3S_SYSCTL_RCC_SYSDIV_Msk)>>LM3S_SYSCTL_RCC_SYSDIV_Pos;
            /* SYSDIV is used */
            if(sysdiv > 1) {
                /* SYSDIV is greater than /2 */
                SystemCoreClock = VCO_PREDDIV2_CLK / (sysdiv + 1);
            }
            else {
                /* SYSDIV is less than 2 - Reserved*/
                SystemCoreClock = 0;
            }
            
        }
    }
}


/*---------------------------------------------------------------------------
  System initialization function
 *---------------------------------------------------------------------------*/
void SystemInit (void)
{
/* ToDo: Add code to initialize the system.
         Do not use global variables because this function is called before
         reaching pre-main. RW section maybe overwritten afterwards. */

#if(CLOCK_SETUP)
    uint32_t i;

    LM3S_SYSCTL->RCC2 = 0x07802810;    /* set default value */
    LM3S_SYSCTL->RCC  = 0x078E3AD1;    /* set default value */

    LM3S_SYSCTL->RCC  = (RCC_Val  | (1UL<<11) | (1UL<<13)) & ~(1UL<<22); /* set value with BYPASS, PWRDN set, USESYSDIV reset */
    LM3S_SYSCTL->RCC2 = (RCC2_Val | (1UL<<11) | (1UL<<13));              /* set value with BYPASS, PWRDN set */
    for (i = 0; i < 1000; i++);   /* wait a while */

    LM3S_SYSCTL->RCC  = (RCC_Val  | (1UL<<11)) & ~(1UL<<22);             /* set value with BYPASS, USESYSDIV reset */
    LM3S_SYSCTL->RCC2 = (RCC2_Val | (1UL<<11));                          /* set value with BYPASS */
    for (i = 0; i < 1000; i++);   /* wait a while */

    LM3S_SYSCTL->RCC  = (RCC_Val  | (1<<11));                            /* set value with BYPASS */

    if ( (((RCC_Val  & (1UL<<13)) == 0) && ((RCC2_Val & (1UL<<31)) == 0)) ||
         (((RCC2_Val & (1UL<<13)) == 0) && ((RCC2_Val & (1UL<<31)) != 0))   ) {
      while ((LM3S_SYSCTL->RIS & (1UL<<6)) != (1UL<<6));                 /* wait until PLL is locked */
    }

    LM3S_SYSCTL->RCC  = (RCC_Val);                                       /* set value */
    LM3S_SYSCTL->RCC2 = (RCC2_Val);                                      /* set value */
    for (i = 0; i < 10000; i++);   /* wait a while */

#endif
    SystemCoreClockUpdate();
}

/*----------------------------------------------------------------------------
  Get the OSC clock
 *----------------------------------------------------------------------------*/
__INLINE static uint32_t getOscClk (uint32_t xtal, uint32_t oscSrc) {
    uint32_t oscClk = XTAL_INT30KHZ;
    switch (oscSrc) {                        /* switch OSCSRC */
        case 0:                              /* MOSC Main oscillator */
        switch (xtal) {                      /* switch XTAL */
            case 0x0:
                oscClk = XTAL_EXT_1MHZ_PLLOFF;
                break;
            case 0x1:
                oscClk = XTAL_EXT_1_8432MHZ_PLLOFF;
                break;
            case 0x2:
                oscClk = XTAL_EXT_2MHZ_PLLOFF;
                break;
            case 0x3:
                oscClk = XTAL_EXT_2_4576MHZ_PLLOFF;
                break;
            case 0x4:
                oscClk = XTAL_EXT_3_579545MHZ;
                break;
            case 0x5:
                oscClk = XTAL_EXT_3_6864MHZ;
                break;
            case 0x6:
                oscClk = XTAL_EXT_4MHZ;
                break;
            case 0x7:
                oscClk = XTAL_EXT_4_096MHZ;
                break;
            case 0x8:
                oscClk = XTAL_EXT_4_9152MHZ;
                break;
            case 0x9:
                oscClk = XTAL_EXT_5MHZ;
                break;
            case 0xA:
                oscClk = XTAL_EXT_5_12MHZ;
                break;
            case 0xB:
                oscClk = XTAL_EXT_6MHZ_USB;
                break;
            case 0xC:
                oscClk = XTAL_EXT_6_144MHZ;
                break;
            case 0xD:
                oscClk = XTAL_EXT_7_3728MHZ;
                break;
            case 0xE:
                oscClk = XTAL_EXT_8MHZ_USB;
                break;
            case 0xF:
                oscClk = XTAL_EXT_8_192MHZ;
                break;
            case 0x10:
                oscClk = XTAL_EXT_10MHZ_USB;
                break;
            case 0x11:
                oscClk = XTAL_EXT_12MHZ_USB;
                break;
            case 0x12:
                oscClk = XTAL_EXT_12_288MHZ;
                break;
            case 0x13:
                oscClk = XTAL_EXT_13_56MHZ;
                break;
            case 0x14:
                oscClk = XTAL_EXT_14_31818MHZ;
                break;
            case 0x15:
                oscClk = XTAL_EXT_16MHZ_USB;
                break;
            case 0x16:
                oscClk = XTAL_EXT_16_384MHZ;
                break;
            default:
                oscClk = 0;
                break;
        }
        break;
            case 1:                         /* PIOSC Internal oscillator */
            oscClk = XTAL_PIOSC_16MHZ;
        break;
        case 2:                         /* PIOSC/4 Internal oscillator/4 */
            oscClk = XTAL_PIOSC_16MHZ/4;
            break;
        case 3:                         /* 30kHz internal oscillator  */
            oscClk = XTAL_INT30KHZ;
            break;
        default:
            oscClk = 0;
            break;
    }
    return oscClk;
}
