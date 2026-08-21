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

/*------------------------------------------------------------------------------
 *  DEFINES
 *----------------------------------------------------------------------------*/
//------------- <<< Use Configuration Wizard in Context Menu >>> ---------------
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

//      <q> ACG: Auto Clock Gating
//          <i> Check this box to use the Sleep-Mode Clock
//          <i> Gating Control (SCGCn) registers and Deep-Sleep-Mode Clock
//          <i> Gating Control (DCGCn) registers if the microcontroller enters a
//          <i> Sleep or Deep-Sleep mode (respectively).
//
// The following controls whether the SCGCn and DCGCn are used.  If the
// value is 1, the SCGCn and DCGCn registers allow unused
// peripherals to consume less power when the microcontroller is
// in a sleep mode.  If the value is 0, then RCGCn are used in all modes.
//
#define CFG_RCC_ACG 0

//      <o> SYSDIV: System Clock Divisor <0-15>
//          <i> Specifies the divisor used to generate the system clock from
//          <i> either the PLL output of 200 MHz, or the chosen oscillator.
//
// The following value is the system clock divisor.  This will be applied if
// USESYSDIV (see below) is enabled.  The valid range of dividers is 0-15.
//
#define CFG_RCC_SYSDIV 2

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
#define CFG_RCC_PWMDIV 2

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
//              <1=> 1: PIOSC Internal oscillator (default)
//              <2=> 2: PIOSC/4 Internal oscillator / 4 (this is necessary if used as input to PLL)
//              <3=> 3: 30kHz 30-KHz internal oscillator
//          <i> Chooses the oscillator that is used for the system clock,
//          <i> or the PLL input.
//
// The following value chooses the oscillator source according to the table in
// the comments above.
//
#define CFG_RCC_OSCSRC 0

//      <q> PIOSCDIS: Precision Internal Oscillator Disable
//          <i> Check this box to turn off the internal oscillator
//
// Set the following value to 1 to turn off the internal oscillator.  This
// value can be set to 1 if you are not using the internal oscillator.
//
#define CFG_RCC_PIOSCDIS 1

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

//      <q> DIV400: Divide PLL as 400 MHz vs. 200 MHz
//          <i> This bit, along with the SYSDIV2LSB bit, allows additional
//          <i> frequency choices.
//
// Set the following value to 1 to use the 400MHz PLL value and an additional
//  bit for SYSDIV2.
//
#define CFG_RCC2_DIV400 1

//      <o> SYSDIV2: System Clock Divisor <0-63>
//          <i> Specifies the divisor used to generate the system clock from
//          <i> either the PLL output of 200 MHz, or the oscillator.
//
// The following value is the system clock divisor.  This will be applied if
// USESYSDIV in RCC is enabled.  The valid range of dividers is 0-63.
//
#define CFG_RCC2_SYSDIV2 2

//      <q> SYSDIV2LSB: Additional LSB for SYSDIV2
//          <i> When DIV400 is set, this bit becomes the LSB of SYSDIV2.
//          <i> If DIV400 is clear, this bit is not used. 
//
// This bit can only be set or cleared when DIV400 is set.
//
#define CFG_RCC2_SYSDIV2LSB 0

//      <q> USBPWRDN: Power-Down USB PLL
//          <i> Check this box to disable the USB PLL.
//
// If the following value is 1, then the USB PLL is powered down.  Keep this
// value as 1 if you do not need to use the PLL. If you are using the USB PLL,
// then this value must be set to 0.
//
#define CFG_RCC2_USBPWRDN 1

//      <q> PWRDN2: Power Down PLL
//          <i> Check this box to disable the PLL.  You must also choose
//          <i> PLL Bypass.
//
// If the following value is 1, then the PLL is powered down.  Keep this value
// as 1 if you do not need to use the PLL.  In this case, BYPASS2 (see below)
// must also be set to 1.  If you are using the PLL, then this value must be
// set to 0.
//
#define CFG_RCC2_PWRDN2 0

//      <q> BYPASS2: Bypass PLL
//          <i> Check this box to not use the PLL for the System Clock
//
// Set the following value to 1 to bypass the PLL and not use it for the
// system clock.  You must set this to 1 if PWRDN2 (above) is set to 1.  Set
// this to 0 if you are using the PLL.
//
#define CFG_RCC2_BYPASS2 0

//      <o> OSCSRC2: Oscillator Source
//              <0=> 0: MOSC Main oscillator
//              <1=> 1: PIOSC Precision Internal oscillator (default)
//              <2=> 2: PIOSC/4 Precision Internal oscillator / 4 (this is necessary if used as input to PLL)
//              <3=> 3: 30kHz 30-kHz internal oscillator
//          <i> The oscillator that is used for the system clock, or the PLL input.
//
// The following value chooses the oscillator source according to the table in
// the comments above.
//
#define CFG_RCC2_OSCSRC2 0

//  </h>
//
//  </e>

//------------------ <<< end of configuration section >>> ----------------------

/*------------------------------------------------------------------------------
 *  Define clocks
 *----------------------------------------------------------------------------*/
#define MOSC_VALUE_1MHZ_PLLOFF                                       (1000000UL)
#define MOSC_VALUE_1_8432MHZ_PLLOFF                                  (1843200UL)
#define MOSC_VALUE_2MHZ_PLLOFF                                       (2000000UL)
#define MOSC_VALUE_2_4576MHZ_PLLOFF                                  (2457600UL)
#define MOSC_VALUE_3_579545MHZ                                       (3579545UL)
#define MOSC_VALUE_3_6864MHZ                                         (3686400UL)
#define MOSC_VALUE_4MHZ                                              (4000000UL)
#define MOSC_VALUE_4_096MHZ                                          (4096000UL)
#define MOSC_VALUE_4_9152MHZ                                         (4915200UL)
#define MOSC_VALUE_5MHZ                                              (5000000UL)
#define MOSC_VALUE_5_12MHZ                                           (5120000UL)
#define MOSC_VALUE_6MHZ_USB                                          (6000000UL)
#define MOSC_VALUE_6_144MHZ                                          (6144000UL)
#define MOSC_VALUE_7_3728MHZ                                         (7372800UL)
#define MOSC_VALUE_8MHZ_USB                                          (8000000UL)
#define MOSC_VALUE_8_192MHZ                                          (8192000UL)
#define MOSC_VALUE_10MHZ_USB                                        (10000000UL)
#define MOSC_VALUE_12MHZ_USB                                        (12000000UL)
#define MOSC_VALUE_12_288MHZ                                        (12288000UL)
#define MOSC_VALUE_13_56MHZ                                         (13560000UL)
#define MOSC_VALUE_14_31818MHZ                                      (14318180UL)
#define MOSC_VALUE_16MHZ_USB                                        (16000000UL)
#define MOSC_VALUE_16_384MHZ                                        (16384000UL)

#define PIOSC_VALUE_16MHZ                                           (16000000UL)

#define IOSC_VALUE_30KHZ                                               (30000UL)

#define HOSC_VALUE_32768HZ                                             (32768UL)

#define VCO_VALUE_400MHZ                                           (400000000UL)
#define VCO_PREDDIV2_VALUE_200MHZ                                  (200000000UL)

#define SYS_CLK_MAX                                                 (80000000UL)

/*------------------------------------------------------------------------------
 *  Clock Sources Macros
 *----------------------------------------------------------------------------*/
#define OSCSRC_MOSC                                               (0x00000000UL)
#define OSCSRC_PIOSC                                              (0x00000001UL)
#define OSCSRC_PIOSC_DIV4                                         (0x00000002UL)
#define OSCSRC_30KHZ                                              (0x00000003UL)

/*------------------------------------------------------------------------------
 *  Divisor Constraint Macros
 *----------------------------------------------------------------------------*/
#define MINSYSDIV_VCO400_DIV_5                                    (0x00000001UL)
#define MINSYSDIV_VCO400_DIV_6                                    (0x00000002UL)
#define MINSYSDIV_50MHZ_DIV4                                      (0x00000003UL)
#define MINSYSDIV_25MHZ_DIV8                                      (0x00000007UL)
#define MINSYSDIV_20MHZ_DIV10                                     (0x00000009UL)

/*------------------------------------------------------------------------------
 *  XTAL Types Macros
 *----------------------------------------------------------------------------*/
#define XTAL_NOPLL_1MHZ                                           (0x00000000UL)
#define XTAL_NOPLL_1_8432MHZ                                      (0x00000001UL)
#define XTAL_NOPLL_2MHZ                                           (0x00000002UL)
#define XTAL_NOPLL_2_4576MHZ                                      (0x00000003UL)
#define XTAL_3_579545MHZ                                          (0x00000004UL)
#define XTAL_3_6864MHZ                                            (0x00000005UL)
#define XTAL_4MHZ_USB                                             (0x00000006UL)
#define XTAL_4_096MHZ                                             (0x00000007UL)
#define XTAL_4_9152MHZ                                            (0x00000008UL)
#define XTAL_5MHZ_USB                                             (0x00000009UL)
#define XTAL_5_12MHZ                                              (0x0000000AUL)
#define XTAL_6MHZ_USB_DEFAULT                                     (0x0000000BUL)
#define XTAL_6_144MHZ                                             (0x0000000CUL)
#define XTAL_7_3728MHZ                                            (0x0000000DUL)
#define XTAL_8MHZ_USB                                             (0x0000000EUL)
#define XTAL_8_192MHZ                                             (0x0000000FUL)
#define XTAL_10MHZ_USB                                            (0x00000010UL)
#define XTAL_12MHZ_USB                                            (0x00000011UL)
#define XTAL_12_288MHZ                                            (0x00000012UL)
#define XTAL_13_56MHZ                                             (0x00000013UL)
#define XTAL_14_31818MHZ                                          (0x00000014UL)
#define XTAL_16MHZ_USB                                            (0x00000015UL)
#define XTAL_16_384MHZ                                            (0x00000016UL)

/*------------------------------------------------------------------------------
 *  Service macros
 *----------------------------------------------------------------------------*/
#define PLL_LOCK_TIMEOUT                                              (100000UL)
#define MOSC_ENABLE_TIMEOUT                                           (100000UL)
#define PLL_LOCK_DELAY                                                 (10000UL)
#define SYS_CLOCK_STABILIZE_DELAY                                        (100UL)
#define MOSC_SWITCH_DELAY                                                 (50UL)
#define MOSC_SHUTDOWN_DELAY                                               (10UL)
/*------------------------------------------------------------------------------
 *  Clock calculator
 *----------------------------------------------------------------------------*/
#if (CFG_RCC2_USERCC2)
    #if (CFG_RCC2_BYPASS2)
        #if (CFG_RCC2_OSCSRC2 == OSCSRC_MOSC)
            #if (CFG_RCC_XTAL == XTAL_NOPLL_1MHZ)
                #define __SYS_CLK_PRE XTAL_1MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_NOPLL_1_8432MHZ)
                #define __SYS_CLK_PRE XTAL_1_8432MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_NOPLL_2MHZ)
                #define __SYS_CLK_PRE XTAL_2MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_NOPLL_2_4576MHZ)
                #define __SYS_CLK_PRE XTAL_2_4576MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_3_579545MHZ)
              #define __SYS_CLK_PRE XTAL_3_579545MHZ
            #elif (CFG_RCC_XTAL == XTAL_3_6864MHZ)
                #define __SYS_CLK_PRE XTAL_3_6864MHZ
            #elif (CFG_RCC_XTAL == XTAL_4MHZ_USB)
                #define __SYS_CLK_PRE XTAL_4MHZ
            #elif (CFG_RCC_XTAL == XTAL_4_096MHZ)
                #define __SYS_CLK_PRE XTAL_4_096MHZ
            #elif (CFG_RCC_XTAL == XTAL_4_9152MHZ)
                #define __SYS_CLK_PRE XTAL_4_9152MHZ
            #elif (CFG_RCC_XTAL == XTAL_5MHZ_USB)
                #define __SYS_CLK_PRE XTAL_5MHZ
            #elif (CFG_RCC_XTAL == XTAL_5_12MHZ)
                #define __SYS_CLK_PRE XTAL_5_12MHZ
            #elif (CFG_RCC_XTAL == XTAL_6MHZ_USB_DEFAULT)
                #define __SYS_CLK_PRE XTAL_6MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_6_144MHZ)
                #define __SYS_CLK_PRE XTAL_6_144MHZ
            #elif (CFG_RCC_XTAL == XTAL_7_3728MHZ)
                #define __SYS_CLK_PRE XTAL_7_3728MHZ
            #elif (CFG_RCC_XTAL == XTAL_8MHZ_USB)
                #define __SYS_CLK_PRE XTAL_8MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_8_192MHZ)
                #define __SYS_CLK_PRE XTAL_8_192MHZ
            #elif (CFG_RCC_XTAL == XTAL_10MHZ_USB)
                #define __SYS_CLK_PRE  XTAL_10MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_12MHZ_USB)
                #define __SYS_CLK_PRE XTAL_12MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_12_288MHZ)
                #define __SYS_CLK_PRE XTAL_12_288MHZ
            #elif (CFG_RCC_XTAL == XTAL_13_56MHZ)
                #define __SYS_CLK_PRE XTAL_13_56MHZ
            #elif (CFG_RCC_XTAL == XTAL_14_31818MHZ)
                #define __SYS_CLK_PRE XTAL_14_31818MHZ
            #elif (CFG_RCC_XTAL == XTAL_16MHZ_USB)
                #define __SYS_CLK_PRE XTAL_16MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_16_384MHZ)
                #define __SYS_CLK_PRE XTAL_16_384MHZ
            #else
                #error "Incorrect XTAL setting!"
            #endif
        #elif (CFG_RCC2_OSCSRC2 == OSCSRC_PIOSC)
            #define __SYS_CLK_PRE PIOSC_VALUE_16MHZ
        #elif (CFG_RCC2_OSCSRC2 == OSCSRC_PIOSC_DIV4)
            #define __SYS_CLK_PRE (PIOSC_VALUE_16MHZ/4)
        #elif (CFG_RCC2_OSCSRC2 == OSCSRC_30KHZ)
            #define __SYS_CLK_PRE XTAL_INT30KHZ
        #else
            #error "Incorrect Clock setting!"
        #endif
        #if(CFG_RCC_USESYSDIV)
            #define __SYS_CLK (__SYS_CLK_PRE / (CFG_RCC2_SYSDIV2 + 1))
        #else
            #define __SYS_CLK (__SYS_CLK_PRE)
        #endif
    #elif (CFG_RCC2_PWRDN2 == 0)
        #if (CFG_RCC2_OSCSRC2 != OSCSRC_MOSC) && (CFG_RCC2_OSCSRC2 != OSCSRC_PIOSC)
            #error "PLL can ONLY be driven by MOSC or PIOSC!"
        #endif
        #if ((CFG_RCC2_OSCSRC2 == OSCSRC_MOSC)&&(CFG_RCC_XTAL <= XTAL_NOPLL_2_4576MHZ))
            #error "Incorrect XTAL selected!"
        #endif
        #if (CFG_RCC_USESYSDIV != 1)
            #error "Hardware forces USESYSDIV to 1 when PLL is enabled! Please check USESYSDIV box in Wizard."
        #endif
        #if(CFG_RCC2_DIV400)
            #define __SYS_CLK (VCO_VALUE_400MHZ / ((CFG_RCC2_SYSDIV2 << 1) + CFG_RCC2_SYSDIV2LSB + 1))
        #else
            #define __SYS_CLK (VCO_PREDDIV2_VALUE_200MHZ / (CFG_RCC2_SYSDIV2 + 1)) 
        #endif
    #else
        #error "PLL is powered down (CFG_RCC2_PWRDN2 is 1)! Cannot use PLL when BYPASS2=0."
    #endif
    #if (CFG_RCC2_OSCSRC2 == OSCSRC_PIOSC) || (CFG_RCC2_OSCSRC2 == OSCSRC_PIOSC_DIV4)
        #if (CFG_RCC_PIOSCDIS == 1)
            #error "Conflict in Wizard: PIOSC is selected as clock source, but CFG_RCC_PIOSCDIS is enabled!"
        #endif
    #endif

    #if (CFG_RCC2_OSCSRC2 == OSCSRC_MOSC)
        #if (CFG_RCC_MOSCDIS == 1)
            #error "Conflict in Wizard: MOSC (Crystal) is selected as clock source, but CFG_RCC_MOSCDIS is enabled!"
        #endif
    #endif
#else
    #if (CFG_RCC_BYPASS)
        #if (CFG_RCC_OSCSRC == OSCSRC_MOSC)
            #if (CFG_RCC_XTAL == XTAL_NOPLL_1MHZ)
                #define __SYS_CLK_PRE XTAL_1MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_NOPLL_1_8432MHZ)
                #define __SYS_CLK_PRE XTAL_1_8432MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_NOPLL_2MHZ)
                #define __SYS_CLK_PRE XTAL_2MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_NOPLL_2_4576MHZ)
                #define __SYS_CLK_PRE XTAL_2_4576MHZ_PLLOFF
            #elif (CFG_RCC_XTAL == XTAL_3_579545MHZ)
                #define __SYS_CLK_PRE XTAL_3_579545MHZ
            #elif (CFG_RCC_XTAL == XTAL_3_6864MHZ)
                #define __SYS_CLK_PRE XTAL_3_6864MHZ
            #elif (CFG_RCC_XTAL == XTAL_4MHZ_USB)
                #define __SYS_CLK_PRE XTAL_4MHZ
            #elif (CFG_RCC_XTAL == XTAL_4_096MHZ)
                #define __SYS_CLK_PRE XTAL_4_096MHZ
            #elif (CFG_RCC_XTAL == XTAL_4_9152MHZ)
                #define __SYS_CLK_PRE XTAL_4_9152MHZ
            #elif (CFG_RCC_XTAL == XTAL_5MHZ_USB)
                #define __SYS_CLK_PRE XTAL_5MHZ
            #elif (CFG_RCC_XTAL == XTAL_5_12MHZ)
                #define __SYS_CLK_PRE XTAL_5_12MHZ
            #elif (CFG_RCC_XTAL == XTAL_6MHZ_USB_DEFAULT)
                #define __SYS_CLK_PRE XTAL_6MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_6_144MHZ)
                #define __SYS_CLK_PRE XTAL_6_144MHZ
            #elif (CFG_RCC_XTAL == XTAL_7_3728MHZ)
                #define __SYS_CLK_PRE XTAL_7_3728MHZ
            #elif (CFG_RCC_XTAL == XTAL_8MHZ_USB)
                #define __SYS_CLK_PRE XTAL_8MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_8_192MHZ)
                #define __SYS_CLK_PRE XTAL_8_192MHZ
            #elif (CFG_RCC_XTAL == XTAL_10MHZ_USB)
                #define __SYS_CLK_PRE XTAL_10MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_12MHZ_USB)
                #define __SYS_CLK_PRE XTAL_12MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_12_288MHZ)
                #define __SYS_CLK_PRE XTAL_12_288MHZ
            #elif (CFG_RCC_XTAL == XTAL_13_56MHZ)
                #define __SYS_CLK_PRE XTAL_13_56MHZ
            #elif (CFG_RCC_XTAL == XTAL_14_31818MHZ)
                #define __SYS_CLK_PRE XTAL_14_31818MHZ
            #elif (CFG_RCC_XTAL == XTAL_16MHZ_USB)
                #define __SYS_CLK_PRE XTAL_16MHZ_USB
            #elif (CFG_RCC_XTAL == XTAL_16_384MHZ)
                #define __SYS_CLK_PRE XTAL_16_384MHZ
            #else
                #error "Incorrect XTAL setting!"
            #endif
        #elif (CFG_RCC_OSCSRC == OSCSRC_PIOSC)
            #define __SYS_CLK_PRE PIOSC_VALUE_16MHZ
        #elif (CFG_RCC_OSCSRC == OSCSRC_PIOSC_DIV4)
            #define __SYS_CLK_PRE (PIOSC_VALUE_16MHZ / 4)
        #elif (CFG_RCC_OSCSRC == OSCSRC_30KHZ)
            #define __SYS_CLK_PRE XTAL_INT30KHZ
        #else
            #error "Incorrect Clock setting!"
        #endif
        #if (CFG_RCC_USESYSDIV)
            #define __SYS_CLK  (__SYS_CLK_PRE / (CFG_RCC_SYSDIV + 1))
        #else
            #define __SYS_CLK  (__SYS_CLK_PRE)
        #endif
    #elif (CFG_RCC_PWRDN == 0)
        #if (CFG_RCC_OSCSRC != OSCSRC_MOSC) && (CFG_RCC_OSCSRC != OSCSRC_PIOSC)
            #error "PLL can ONLY be driven by MOSC or PIOSC!"
        #endif
        #if ((CFG_RCC_OSCSRC == OSCSRC_MOSC)&&(CFG_RCC_XTAL <= XTAL_NOPLL_2_4576MHZ))
            #error "Incorrect XTAL selected!"
        #endif
        #if (CFG_RCC_USESYSDIV != 1)
            #error "Hardware forces USESYSDIV to 1 when PLL is enabled! Please check USESYSDIV box in Wizard."
        #endif
        #define __SYS_CLK  (VCO_PREDDIV2_VALUE_200MHZ / (CFG_RCC_SYSDIV + 1))
    #else
        #error "Incorrect XTAL selected!"
    #endif
     #if (CFG_RCC_OSCSRC == OSCSRC_PIOSC) || (CFG_RCC_OSCSRC == OSCSRC_PIOSC_DIV4)
        #if (CFG_RCC_PIOSCDIS == 1)
            #error "Conflict in Wizard: PIOSC is selected as clock source, but CFG_RCC_IOSCDIS is enabled (1)!"
        #endif
    #endif

    #if (CFG_RCC_OSCSRC == OSCSRC_MOSC)
        #if (CFG_RCC_MOSCDIS == 1)
            #error "Conflict in Wizard: MOSC (Crystal) is selected as clock source, but CFG_RCC_MOSCDIS is enabled (1)!"
        #endif
    #endif
#endif

#if (__SYS_CLK  > SYS_CLK_MAX)
    #error "System Clock frequency exceeds the maximum allowed limit of 80 MHz for LM3S9B92!"
#endif

/*------------------------------------------------------------------------------
 *  System Core Clock Variable
 *----------------------------------------------------------------------------*/
uint32_t SystemCoreClock;  /* System Clock Frequency (Core Clock)*/

/*------------------------------------------------------------------------------
 *  Static Core Clock functions
 *----------------------------------------------------------------------------*/
__STATIC_INLINE uint32_t getOscClk (uint32_t xtal, uint32_t oscSrc);
__STATIC_INLINE uint32_t GetMinSysDiv(uint32_t minsysdiv);

/*------------------------------------------------------------------------------
 *  System Core Clock function
 *----------------------------------------------------------------------------*/
void SystemCoreClockUpdate (void) {
    uint32_t rcc, rcc2;
    uint32_t sysdiv, minsysdiv;
    uint32_t TempClock;
    
    rcc  = SYSCTL->RCC;
    rcc2 = SYSCTL->RCC2;
    minsysdiv = ((SYSCTL->DC1 & SYSCTL_DC1_MINSYSDIV_Msk) >> SYSCTL_DC1_MINSYSDIV_Pos);
    
    
    if ((rcc2 & SYSCTL_RCC2_USERCC2_Msk) == SYSCTL_RCC2_USERCC2_Msk) {
        if((rcc2 & SYSCTL_RCC2_BYPASS2_Msk) == SYSCTL_RCC2_BYPASS2_Msk) {
            TempClock = getOscClk(((rcc & SYSCTL_RCC_XTAL_Msk) >> SYSCTL_RCC_XTAL_Pos), ((rcc2 & SYSCTL_RCC2_OSCSRC2_Msk) >> SYSCTL_RCC2_OSCSRC2_Pos));
            if((rcc & SYSCTL_RCC_USESYSDIV_Msk) == SYSCTL_RCC_USESYSDIV_Msk) {
                sysdiv = (rcc2 & SYSCTL_RCC2_SYSDIV2_Msk) >> SYSCTL_RCC2_SYSDIV2_Pos;
                SystemCoreClock = TempClock / (sysdiv + 1);
            }
            else {
                SystemCoreClock = TempClock;
            }
        }
        else {
            if((rcc2 & SYSCTL_RCC2_DIV400_Msk) == SYSCTL_RCC2_DIV400_Msk){
                sysdiv = ((rcc2 & SYSCTL_RCC2_SYSDIV2_Msk) >> SYSCTL_RCC2_SYSDIV2_Pos);
                sysdiv = (sysdiv << 1) + ((rcc2 & SYSCTL_RCC2_SYSDIV2LSB_Msk) >> SYSCTL_RCC2_SYSDIV2LSB_Pos) + 1;
                if ((rcc & SYSCTL_RCC_USESYSDIV_Msk) == SYSCTL_RCC_USESYSDIV_Msk) {
                    minsysdiv = GetMinSysDiv((SYSCTL->DID1 & SYSCTL_DC1_MINSYSDIV_Msk) >> SYSCTL_DC1_MINSYSDIV_Pos);
                    if (sysdiv < minsysdiv) {
                        sysdiv = minsysdiv;
                    }
                }
                SystemCoreClock = VCO_VALUE_400MHZ / sysdiv;
            }
            else {
                sysdiv = ((rcc2 & SYSCTL_RCC2_SYSDIV2_Msk) >> (SYSCTL_RCC2_SYSDIV2_Pos + 1)) + 1;
                sysdiv = sysdiv << 1;
                if ((rcc & SYSCTL_RCC_USESYSDIV_Msk) == SYSCTL_RCC_USESYSDIV_Msk) {
                    minsysdiv = GetMinSysDiv((SYSCTL->DID1 & SYSCTL_DC1_MINSYSDIV_Msk) >> SYSCTL_DC1_MINSYSDIV_Pos);
                    if (sysdiv < minsysdiv) {
                        sysdiv = minsysdiv;
                    }
                }
                SystemCoreClock = VCO_VALUE_400MHZ / sysdiv;
            }
        }
    }
    else {
        if((rcc & SYSCTL_RCC_BYPASS_Msk) == SYSCTL_RCC_BYPASS_Msk) {
            TempClock = getOscClk(((rcc & SYSCTL_RCC_XTAL_Msk) >> SYSCTL_RCC_XTAL_Pos),((rcc & SYSCTL_RCC_OSCSRC_Msk) >> SYSCTL_RCC_OSCSRC_Pos));
            if((rcc & SYSCTL_RCC_USESYSDIV_Msk) == SYSCTL_RCC_USESYSDIV_Msk) {
                sysdiv = (rcc & SYSCTL_RCC_SYSDIV_Msk) >> SYSCTL_RCC_SYSDIV_Pos;
                SystemCoreClock = TempClock / (sysdiv + 1);
            } else {
                SystemCoreClock = TempClock;
            }
        }
        else {
            sysdiv = ((rcc & SYSCTL_RCC_SYSDIV_Msk) >> SYSCTL_RCC_SYSDIV_Pos) + 1;
            sysdiv = sysdiv << 1;
            if ((rcc & SYSCTL_RCC_USESYSDIV_Msk) == SYSCTL_RCC_USESYSDIV_Msk) {
                minsysdiv = GetMinSysDiv((SYSCTL->DID1 & SYSCTL_DC1_MINSYSDIV_Msk) >> SYSCTL_DC1_MINSYSDIV_Pos);
                if (sysdiv < minsysdiv) {
                    sysdiv = minsysdiv;
                }
            }
            SystemCoreClock = VCO_PREDDIV2_VALUE_200MHZ / sysdiv;
        }
    }
}

/*---------------------------------------------------------------------------
    System initialization function
 *---------------------------------------------------------------------------*/
void SystemInit (void) {
#if(CLOCK_SETUP)
    uint32_t rcc, rcc2, timeout;

    rcc = SYSCTL->RCC;
    rcc |= SYSCTL_RCC_BYPASS_Msk;
    rcc &= ~SYSCTL_RCC_OSCSRC_Msk;
    rcc |= (OSCSRC_PIOSC << SYSCTL_RCC_OSCSRC_Pos); 
    SYSCTL->RCC = rcc;
    
    rcc2 = SYSCTL->RCC2;
    rcc2 |= SYSCTL_RCC2_USBPWRDN_Msk;
    SYSCTL->RCC2 = rcc2;

    SYSCTL->RCGC0 &= ~(SYSCTL_RCGC0_CAN0_Msk | SYSCTL_RCGC0_CAN1_Msk);
    SYSCTL->SCGC0 &= ~(SYSCTL_SCGC0_CAN0_Msk | SYSCTL_SCGC0_CAN1_Msk);
    SYSCTL->DCGC0 &= ~(SYSCTL_DCGC0_CAN0_Msk | SYSCTL_DCGC0_CAN1_Msk);

    SYSCTL->RCGC2 &= ~(SYSCTL_RCGC2_EMAC0_Msk | SYSCTL_RCGC2_EPHY0_Msk);
    SYSCTL->SCGC2 &= ~(SYSCTL_SCGC2_EMAC0_Msk | SYSCTL_SCGC2_EPHY0_Msk);
    SYSCTL->DCGC2 &= ~(SYSCTL_DCGC2_EMAC0_Msk | SYSCTL_DCGC2_EPHY0_Msk);

    for (volatile uint32_t delay = 0; delay < SYS_CLOCK_STABILIZE_DELAY; delay++) {}

    SYSCTL->MISC = SYSCTL_MISC_MOSCPUPMIS_Msk | SYSCTL_MISC_USBPLLLMIS_Msk | \
                   SYSCTL_MISC_PLLLMIS_Msk | SYSCTL_MISC_BORMIS_Msk;

    if(CFG_RCC2_USERCC2) {
        rcc2 = SYSCTL->RCC2;
        rcc2 |= SYSCTL_RCC2_USERCC2_Msk;
        rcc2 &= ~SYSCTL_RCC2_OSCSRC2_Msk;
        rcc2 |= (OSCSRC_PIOSC << SYSCTL_RCC2_OSCSRC2_Pos);
        rcc2 |= SYSCTL_RCC2_BYPASS2_Msk;
        SYSCTL->RCC2 = rcc2;
        
        for (volatile uint32_t delay = 0; delay < MOSC_SWITCH_DELAY; delay++) {}

#if (CFG_RCC2_OSCSRC2 == OSCSRC_MOSC)
        SYSCTL->RCC |= SYSCTL_RCC_MOSCDIS_Msk;
        for (volatile uint32_t delay = 0; delay < MOSC_SHUTDOWN_DELAY; delay++) {}
        SYSCTL->RCC &= ~SYSCTL_RCC_MOSCDIS_Msk;

        timeout = MOSC_ENABLE_TIMEOUT;
        while (((SYSCTL->RIS & SYSCTL_RIS_MOSCPUPRIS_Msk) == 0) && (timeout > 0)) {
            timeout--;
        }
        if (timeout == 0) {
            SYSCTL->RCC |= SYSCTL_RCC_MOSCDIS_Msk;
            SYSCTL->RCC2 &= ~SYSCTL_RCC2_USERCC2_Msk;
            SystemCoreClockUpdate();
            return;
        }
#endif

        rcc = SYSCTL->RCC;
        rcc &= ~(SYSCTL_RCC_XTAL_Msk      | SYSCTL_RCC_MOSCDIS_Msk | 
                 SYSCTL_RCC_USEPWMDIV_Msk | SYSCTL_RCC_PWMDIV_Msk  | 
                 SYSCTL_RCC_ACG_Msk);
                 
        rcc |= (CFG_RCC_XTAL       << SYSCTL_RCC_XTAL_Pos)       |
               (CFG_RCC_USEPWMDIV  << SYSCTL_RCC_USEPWMDIV_Pos)  |
               (CFG_RCC_PWMDIV     << SYSCTL_RCC_PWMDIV_Pos)     |
               (CFG_RCC_ACG        << SYSCTL_RCC_ACG_Pos);
        SYSCTL->RCC = rcc;

        rcc2 = SYSCTL->RCC2;
        rcc2 &= ~(SYSCTL_RCC2_OSCSRC2_Msk | SYSCTL_RCC2_SYSDIV2_Msk  | 
                  SYSCTL_RCC2_DIV400_Msk  | SYSCTL_RCC2_PWRDN2_Msk   | 
                  SYSCTL_RCC2_USBPWRDN_Msk);
              
        rcc2 |=  (CFG_RCC2_OSCSRC2  << SYSCTL_RCC2_OSCSRC2_Pos)  |
                 (CFG_RCC2_SYSDIV2  << SYSCTL_RCC2_SYSDIV2_Pos)  |
                 (CFG_RCC2_USBPWRDN << SYSCTL_RCC2_USBPWRDN_Pos) |
                  SYSCTL_RCC2_PWRDN2_Msk   | 
                  SYSCTL_RCC2_USERCC2_Msk;

#if (CFG_RCC2_DIV400)
        rcc2 |= SYSCTL_RCC2_DIV400_Msk;
        rcc2 &= ~SYSCTL_RCC2_SYSDIV2LSB_Msk;
        rcc2 |= (CFG_RCC2_SYSDIV2LSB << SYSCTL_RCC2_SYSDIV2LSB_Pos);
#endif
        SYSCTL->RCC2 = rcc2; 
        
        for (volatile uint32_t delay = 0; delay < SYS_CLOCK_STABILIZE_DELAY; delay++) {}

#if (CFG_RCC2_BYPASS2 == 0)
        rcc2 &= ~SYSCTL_RCC2_PWRDN2_Msk;
        SYSCTL->RCC2 = rcc2;

        timeout = PLL_LOCK_TIMEOUT;
        while (((SYSCTL->RIS & SYSCTL_RIS_PLLLRIS_Msk) == 0) && (timeout > 0)) {
            timeout--;
        }

        if (timeout == 0) {
            rcc2 = SYSCTL->RCC2;
            rcc2 &= ~SYSCTL_RCC2_OSCSRC2_Msk;
            rcc2 |= (OSCSRC_PIOSC << SYSCTL_RCC2_OSCSRC2_Pos);
            rcc2 |= SYSCTL_RCC2_BYPASS2_Msk;
            SYSCTL->RCC2 = rcc2;
        } else {
            rcc2 = SYSCTL->RCC2;
            rcc2 &= ~(SYSCTL_RCC2_OSCSRC2_Msk | SYSCTL_RCC2_BYPASS2_Msk);
            rcc2 |= (CFG_RCC2_OSCSRC2 << SYSCTL_RCC2_OSCSRC2_Pos);
            SYSCTL->RCC2 = rcc2;
            
            for (volatile uint32_t delay = 0; delay < PLL_LOCK_DELAY; delay++){}

#if (CFG_RCC_PIOSCDIS == 1)
            if (CFG_RCC2_OSCSRC2 == OSCSRC_MOSC) {
                SYSCTL->RCC |= SYSCTL_RCC_IOSCDIS_Msk;
            }
#endif
#if (CFG_RCC_MOSCDIS == 1)
            if ((CFG_RCC2_OSCSRC2 == OSCSRC_PIOSC) || (CFG_RCC2_OSCSRC2 == OSCSRC_PIOSC_DIV4)) {
                SYSCTL->RCC |= SYSCTL_RCC_MOSCDIS_Msk;
            }
#endif
        }
#else
        rcc2 = SYSCTL->RCC2;
        rcc2 &= ~SYSCTL_RCC2_OSCSRC2_Msk;
        rcc2 |= (CFG_RCC2_OSCSRC2 << SYSCTL_RCC2_OSCSRC2_Pos);
        SYSCTL->RCC2 = rcc2;
#endif
    }
    else {
#if (CFG_RCC_OSCSRC == OSCSRC_MOSC)
        SYSCTL->RCC |= SYSCTL_RCC_MOSCDIS_Msk;
        for (volatile uint32_t delay = 0; delay < MOSC_SHUTDOWN_DELAY; delay++) {}
        SYSCTL->RCC &= ~SYSCTL_RCC_MOSCDIS_Msk;

        timeout = MOSC_ENABLE_TIMEOUT;
        while (((SYSCTL->RIS & SYSCTL_RIS_MOSCPUPRIS_Msk) == 0) && (timeout > 0)) {
            timeout--;
        }

        if (timeout == 0) {
            SYSCTL->RCC |= SYSCTL_RCC_MOSCDIS_Msk;
            SystemCoreClockUpdate();
            return;
        }
#endif

        rcc = SYSCTL->RCC;
        rcc &= ~(SYSCTL_RCC_XTAL_Msk      | SYSCTL_RCC_OSCSRC_Msk     |
                 SYSCTL_RCC_SYSDIV_Msk    | SYSCTL_RCC_PWRDN_Msk      |
                 SYSCTL_RCC_USESYSDIV_Msk | SYSCTL_RCC_IOSCDIS_Msk    | 
                 SYSCTL_RCC_MOSCDIS_Msk   | SYSCTL_RCC_USEPWMDIV_Msk  | 
                 SYSCTL_RCC_PWMDIV_Msk    | SYSCTL_RCC_ACG_Msk);

        rcc |=  (CFG_RCC_XTAL            << SYSCTL_RCC_XTAL_Pos)      |
                (CFG_RCC_SYSDIV          << SYSCTL_RCC_SYSDIV_Pos)    |
                (CFG_RCC_USESYSDIV       << SYSCTL_RCC_USESYSDIV_Pos) |
                (CFG_RCC_USEPWMDIV       << SYSCTL_RCC_USEPWMDIV_Pos) |
                (CFG_RCC_PWMDIV          << SYSCTL_RCC_PWMDIV_Pos)    |
                (CFG_RCC_ACG             << SYSCTL_RCC_ACG_Pos)       |
                (OSCSRC_PIOSC            << SYSCTL_RCC_OSCSRC_Pos)    | 
                SYSCTL_RCC_PWRDN_Msk     | 
                SYSCTL_RCC_BYPASS_Msk;     
        SYSCTL->RCC = rcc;

        for (volatile uint32_t delay = 0; delay < SYS_CLOCK_STABILIZE_DELAY; delay++) {}

#if (CFG_RCC_BYPASS == 0)
        rcc &= ~SYSCTL_RCC_PWRDN_Msk;
        SYSCTL->RCC = rcc;

        timeout = PLL_LOCK_TIMEOUT;
        while (((SYSCTL->RIS & SYSCTL_RIS_PLLLRIS_Msk) == 0) && (timeout > 0)) {
            timeout--;
        }

        if (timeout == 0) {
            rcc = SYSCTL->RCC;
            rcc &= ~SYSCTL_RCC_OSCSRC_Msk;
            rcc |= (OSCSRC_PIOSC << SYSCTL_RCC_OSCSRC_Pos);
            rcc |= SYSCTL_RCC_BYPASS_Msk;
            rcc |= SYSCTL_RCC_MOSCDIS_Msk;
            SYSCTL->RCC = rcc;
            SystemCoreClockUpdate();
            return;
        } else {
            rcc = SYSCTL->RCC;
            rcc &= ~(SYSCTL_RCC_OSCSRC_Msk | SYSCTL_RCC_BYPASS_Msk);
            rcc |= (CFG_RCC_OSCSRC << SYSCTL_RCC_OSCSRC_Pos); 
            SYSCTL->RCC = rcc;
            
            for (volatile uint32_t delay = 0; delay < PLL_LOCK_DELAY; delay++){}

#if (CFG_RCC_PIOSCDIS == 1)
            if (CFG_RCC_OSCSRC == OSCSRC_MOSC) {
                SYSCTL->RCC |= SYSCTL_RCC_IOSCDIS_Msk;
            }
#endif
#if (CFG_RCC_MOSCDIS == 1)
            if ((CFG_RCC_OSCSRC == OSCSRC_PIOSC) || (CFG_RCC_OSCSRC == OSCSRC_PIOSC_DIV4)) {
                SYSCTL->RCC |= SYSCTL_RCC_MOSCDIS_Msk;
            }
#endif
        }
#else
        rcc = SYSCTL->RCC;
        rcc &= ~SYSCTL_RCC_OSCSRC_Msk;
        rcc |= (CFG_RCC_OSCSRC << SYSCTL_RCC_OSCSRC_Pos); 
        SYSCTL->RCC = rcc;
#endif
    }
#endif

    SystemCoreClockUpdate();
}

/*------------------------------------------------------------------------------
 * Get the OSC clock
 *----------------------------------------------------------------------------*/
__STATIC_INLINE uint32_t getOscClk (uint32_t xtal, uint32_t oscSrc) {
    uint32_t oscClk = IOSC_VALUE_30KHZ;
    switch (oscSrc) {
        case OSCSRC_MOSC:
        switch (xtal) {
            case XTAL_NOPLL_1MHZ:
                oscClk = MOSC_VALUE_1MHZ_PLLOFF;
                break;
            case XTAL_NOPLL_1_8432MHZ:
                oscClk = MOSC_VALUE_1_8432MHZ_PLLOFF;
                break;
            case XTAL_NOPLL_2MHZ:
                oscClk = MOSC_VALUE_2MHZ_PLLOFF;
                break;
            case XTAL_NOPLL_2_4576MHZ:
                oscClk = MOSC_VALUE_2_4576MHZ_PLLOFF;
                break;
            case XTAL_3_579545MHZ:
                oscClk = MOSC_VALUE_3_579545MHZ;
                break;
            case XTAL_3_6864MHZ:
                oscClk = MOSC_VALUE_3_6864MHZ;
                break;
            case XTAL_4MHZ_USB:
                oscClk = MOSC_VALUE_4MHZ;
                break;
            case XTAL_4_096MHZ:
                oscClk = MOSC_VALUE_4_096MHZ;
                break;
            case XTAL_4_9152MHZ:
                oscClk = MOSC_VALUE_4_9152MHZ;
                break;
            case XTAL_5MHZ_USB:
                oscClk = MOSC_VALUE_5MHZ;
                break;
            case XTAL_5_12MHZ:
                oscClk = MOSC_VALUE_5_12MHZ;
                break;
            case XTAL_6MHZ_USB_DEFAULT:
                oscClk = MOSC_VALUE_6MHZ_USB;
                break;
            case XTAL_6_144MHZ:
                oscClk = MOSC_VALUE_6_144MHZ;
                break;
            case XTAL_7_3728MHZ:
                oscClk = MOSC_VALUE_7_3728MHZ;
                break;
            case XTAL_8MHZ_USB:
                oscClk = MOSC_VALUE_8MHZ_USB;
                break;
            case XTAL_8_192MHZ:
                oscClk = MOSC_VALUE_8_192MHZ;
                break;
            case XTAL_10MHZ_USB:
                oscClk = MOSC_VALUE_10MHZ_USB;
                break;
            case XTAL_12MHZ_USB:
                oscClk = MOSC_VALUE_12MHZ_USB;
                break;
            case XTAL_12_288MHZ:
                oscClk = MOSC_VALUE_12_288MHZ;
                break;
            case XTAL_13_56MHZ:
                oscClk = MOSC_VALUE_13_56MHZ;
                break;
            case XTAL_14_31818MHZ:
                oscClk = MOSC_VALUE_14_31818MHZ;
                break;
            case XTAL_16MHZ_USB:
                oscClk = MOSC_VALUE_16MHZ_USB;
                break;
            case XTAL_16_384MHZ:
                oscClk = MOSC_VALUE_16_384MHZ;
                break;
            default:
                oscClk = -1;
                break;
        }
        break;
            case OSCSRC_PIOSC:
            oscClk = PIOSC_VALUE_16MHZ;
        break;
        case OSCSRC_PIOSC_DIV4:
            oscClk = PIOSC_VALUE_16MHZ/4;
            break;
        case OSCSRC_30KHZ:
            oscClk = IOSC_VALUE_30KHZ;
            break;
        default:
            oscClk = -1;
            break;
    }
    return oscClk;
}

/*------------------------------------------------------------------------------
 * Get the min PLL400 divisor
 *----------------------------------------------------------------------------*/
__STATIC_INLINE uint32_t GetMinSysDiv(uint32_t minsysdiv) {
    switch (minsysdiv) {
        case MINSYSDIV_VCO400_DIV_5:
            return 5;
        case MINSYSDIV_VCO400_DIV_6:
            return 6;
        case MINSYSDIV_50MHZ_DIV4:
            return 8;
        case MINSYSDIV_25MHZ_DIV8:
            return 16;
        case MINSYSDIV_20MHZ_DIV10:
            return 20;
        default:
            return 5;
    }
}