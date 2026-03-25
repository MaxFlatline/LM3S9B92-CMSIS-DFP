/**
 * \file bsp_evalbot.c
 * \brief Common pre-os-init and post-os-init fucntions
 * \author Max "Flatline"
 * \version 0.0.1
 * \date 13.09.2025
 *
 * Initial version
 * BSP_PreInit - configures clocks, can be coinfigured manually or using pre-defined frequencies
 *
 */

#include "lm3s9b92.h"                   // Device header

/**
 * \fn
 * \brief 
 *
 * \param
 * \param 
 * \return 
 */
void BSP_PreInit(void)
{
    
}

/**
 * \fn
 * \brief 
 *
 * \param
 * \param 
 * \return  
 */
//static void BSP_SystemClockSet(void)
//{
//    unsigned long ulDelay, ulRCC, ulRCC2;
//    //
//    // Get the current value of the RCC and RCC2 registers.  If using a
//    // Sandstorm-class device, the RCC2 register reads back as zero and the
//    // writes to it from within this function are ignored.
//    //
//    ulRCC = SYSCTL->RCC;
//    ulRCC2 = SYSCTL->RCC2;
//    
//    //
//    // Bypass the PLL and system clock dividers for now.
//    //
//    ulRCC |= ;
//    ulRCC &= ~(SYSCTL_RCC_USESYSDIV);
//    ulRCC2 |= SYSCTL_RCC2_BYPASS2;
//    
//}

///**
// * \fn
// * \brief 
// *
// * \param
// * \param 
// * \return  
// */
//static void BSP_SystemClockGet(void)
//{
//    
//}

////*****************************************************************************
////
////! Sets the clocking of the device.
////!
////! \param ulConfig is the required configuration of the device clocking.
////!
////! This function configures the clocking of the device.  The input crystal
////! frequency, oscillator to be used, use of the PLL, and the system clock
////! divider are all configured with this function.
////!
////! The \e ulConfig parameter is the logical OR of several different values,
////! many of which are grouped into sets where only one can be chosen.
////!
////! The system clock divider is chosen with one of the following values:
////! \b SYSCTL_SYSDIV_1, \b SYSCTL_SYSDIV_2, \b SYSCTL_SYSDIV_3, ...
////! \b SYSCTL_SYSDIV_64.  Only \b SYSCTL_SYSDIV_1 through \b SYSCTL_SYSDIV_16
////! are valid on Sandstorm-class devices. Half-dividers, such as
////! \b SYSCTL_SYSDIV_2_5 and \b SYSCTL_SYSDIV_3_5. are available on Tempest-,
////! Firestorm-, and Blizzard-class devices.
////!
////! The use of the PLL is chosen with either \b SYSCTL_USE_PLL or
////! \b SYSCTL_USE_OSC.
////!
////! The external crystal frequency is chosen with one of the following values:
////! \b SYSCTL_XTAL_1MHZ, \b SYSCTL_XTAL_1_84MHZ, \b SYSCTL_XTAL_2MHZ,
////! \b SYSCTL_XTAL_2_45MHZ, \b SYSCTL_XTAL_3_57MHZ, \b SYSCTL_XTAL_3_68MHZ,
////! \b SYSCTL_XTAL_4MHZ, \b SYSCTL_XTAL_4_09MHZ, \b SYSCTL_XTAL_4_91MHZ,
////! \b SYSCTL_XTAL_5MHZ, \b SYSCTL_XTAL_5_12MHZ, \b SYSCTL_XTAL_6MHZ,
////! \b SYSCTL_XTAL_6_14MHZ, \b SYSCTL_XTAL_7_37MHZ, \b SYSCTL_XTAL_8MHZ,
////! \b SYSCTL_XTAL_8_19MHZ, \b SYSCTL_XTAL_10MHZ, \b SYSCTL_XTAL_12MHZ,
////! \b SYSCTL_XTAL_12_2MHZ, \b SYSCTL_XTAL_13_5MHZ, \b SYSCTL_XTAL_14_3MHZ,
////! \b SYSCTL_XTAL_16MHZ, \b SYSCTL_XTAL_16_3MHZ, \b SYSCTL_XTAL_18MHZ,
////! \b SYSCTL_XTAL_20MHZ, \b SYSCTL_XTAL_24MHZ, or \b SYSCTL_XTAL_25MHz.
////! Values below \b SYSCTL_XTAL_3_57MHZ are not valid when the PLL is in
////! operation on Sandstorm-, Fury-, Dustdevil-, Tempest-, and Firestorm-class.
////! devices. Values below \b SYSCTL_XTAL_5MHZ are not valid when the PLL is in
////! operation on Blizzard-class devices.  Values below \b SYSCTL_XTAL_4MHZ
////! are never valid on Blizzard-class devices. On  Sandstorm- and Fury-class
////! devices, values above \b SYSCTL_XTAL_8_19MHZ are not valid. On Dustdevil-,
////! Tempest-, and Firestorm-class devices, values above \b SYSCTL_XTAL_16_3MHZ
////! are not valid.
////!
////! The oscillator source is chosen with one of the following values:
////! \b SYSCTL_OSC_MAIN, \b SYSCTL_OSC_INT, \b SYSCTL_OSC_INT4,
////! \b SYSCTL_OSC_INT30, or \b SYSCTL_OSC_EXT32.  On Sandstorm-class devices,
////! \b SYSCTL_OSC_INT30 and \b SYSCTL_OSC_EXT32 are not valid.
////! \b SYSCTL_OSC_EXT32 is only available on devices with the hibernate module,
////! and then only when the hibernate module has been enabled.
////!
////! The internal and main oscillators are disabled with the
////! \b SYSCTL_INT_OSC_DIS and \b SYSCTL_MAIN_OSC_DIS flags, respectively.
////! The external oscillator must be enabled in order to use an external clock
////! source.  Note that attempts to disable the oscillator used to clock the
////! device is prevented by the hardware.
////!
////! To clock the system from an external source (such as an external crystal
////! oscillator), use \b SYSCTL_USE_OSC \b | \b SYSCTL_OSC_MAIN.  To clock the
////! system from the main oscillator, use \b SYSCTL_USE_OSC \b |
////! \b SYSCTL_OSC_MAIN.  To clock the system from the PLL, use
////! \b SYSCTL_USE_PLL \b | \b SYSCTL_OSC_MAIN, and select the appropriate
////! crystal with one of the \b SYSCTL_XTAL_xxx values.
////!
////! \note If selecting the PLL as the system clock source (that is, via
////! \b SYSCTL_USE_PLL), this function polls the PLL lock interrupt to
////! determine when the PLL has locked.  If an interrupt handler for the
////! system control interrupt is in place, and it responds to and clears the
////! PLL lock interrupt, this function delays until its timeout has occurred
////! instead of completing as soon as PLL lock is achieved.
////!
////! \return None.
////
////*****************************************************************************
//void
//SysCtlClockSet(unsigned long ulConfig)
//{
//    unsigned long ulDelay, ulRCC, ulRCC2;

//    //
//    // See if this is a Sandstorm-class device and clocking features from newer
//    // devices were requested.
//    //
//    if(CLASS_IS_SANDSTORM && (ulConfig & SYSCTL_RCC2_USERCC2))
//    {
//        //
//        // Return without changing the clocking because the requested
//        // configuration can not be achieved.
//        //
//        return;
//    }

//    //
//    // Get the current value of the RCC and RCC2 registers.  If using a
//    // Sandstorm-class device, the RCC2 register reads back as zero and the
//    // writes to it from within this function are ignored.
//    //
//    ulRCC = HWREG(SYSCTL_RCC);
//    ulRCC2 = HWREG(SYSCTL_RCC2);

//    //
//    // Bypass the PLL and system clock dividers for now.
//    //
//    ulRCC |= SYSCTL_RCC_BYPASS;
//    ulRCC &= ~(SYSCTL_RCC_USESYSDIV);
//    ulRCC2 |= SYSCTL_RCC2_BYPASS2;

//    //
//    // Write the new RCC value.
//    //
//    HWREG(SYSCTL_RCC) = ulRCC;
//    HWREG(SYSCTL_RCC2) = ulRCC2;

//    //
//    // See if either oscillator needs to be enabled.
//    //
//    if(((ulRCC & SYSCTL_RCC_IOSCDIS) && !(ulConfig & SYSCTL_RCC_IOSCDIS)) ||
//       ((ulRCC & SYSCTL_RCC_MOSCDIS) && !(ulConfig & SYSCTL_RCC_MOSCDIS)))
//    {
//        //
//        // Make sure that the required oscillators are enabled.  For now, the
//        // previously enabled oscillators must be enabled along with the newly
//        // requested oscillators.
//        //
//        ulRCC &= (~(SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS) |
//                  (ulConfig & (SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS)));

//        //
//        // Write the new RCC value.
//        //
//        HWREG(SYSCTL_RCC) = ulRCC;

//        //
//        // Wait for a bit, giving the oscillator time to stabilize.  The number
//        // of iterations is adjusted based on the current clock source; a
//        // smaller number of iterations is required for slower clock rates.
//        //
//        if(((ulRCC2 & SYSCTL_RCC2_USERCC2) &&
//            (((ulRCC2 & SYSCTL_RCC2_OSCSRC2_M) == SYSCTL_RCC2_OSCSRC2_30) ||
//             ((ulRCC2 & SYSCTL_RCC2_OSCSRC2_M) == SYSCTL_RCC2_OSCSRC2_32))) ||
//           (!(ulRCC2 & SYSCTL_RCC2_USERCC2) &&
//            ((ulRCC & SYSCTL_RCC_OSCSRC_M) == SYSCTL_RCC_OSCSRC_30)))
//        {
//            //
//            // Delay for 4096 iterations.
//            //
//            SysCtlDelay(4096);
//        }
//        else
//        {
//            //
//            // Delay for 524,288 iterations.
//            //
//            SysCtlDelay(524288);
//        }
//    }

//    //
//    // Set the new crystal value and oscillator source.  Because the OSCSRC2
//    // field in RCC2 overlaps the XTAL field in RCC, the OSCSRC field has a
//    // special encoding within ulConfig to avoid the overlap.
//    //
//    ulRCC &= ~(SYSCTL_RCC_XTAL_M | SYSCTL_RCC_OSCSRC_M);
//    ulRCC |= ulConfig & (SYSCTL_RCC_XTAL_M | SYSCTL_RCC_OSCSRC_M);
//    ulRCC2 &= ~(SYSCTL_RCC2_USERCC2 | SYSCTL_RCC2_OSCSRC2_M);
//    ulRCC2 |= ulConfig & (SYSCTL_RCC2_USERCC2 | SYSCTL_RCC_OSCSRC_M);
//    ulRCC2 |= (ulConfig & 0x00000008) << 3;

//    //
//    // Write the new RCC value.
//    //
//    HWREG(SYSCTL_RCC) = ulRCC;
//    HWREG(SYSCTL_RCC2) = ulRCC2;

//    //
//    // Wait for a bit so that new crystal value and oscillator source can take
//    // effect.
//    //
//    SysCtlDelay(16);

//    //
//    // Set the PLL configuration.
//    //
//    ulRCC &= ~(SYSCTL_RCC_PWRDN | SYSCTL_RCC_OEN);
//    ulRCC |= ulConfig & (SYSCTL_RCC_PWRDN | SYSCTL_RCC_OEN);
//    ulRCC2 &= ~(SYSCTL_RCC2_PWRDN2);
//    ulRCC2 |= ulConfig & SYSCTL_RCC2_PWRDN2;

//    //
//    // Clear the PLL lock interrupt.
//    //
//    HWREG(SYSCTL_MISC) = SYSCTL_INT_PLL_LOCK;

//    //
//    // Write the new RCC value.
//    //
//    if(ulRCC2 & SYSCTL_RCC2_USERCC2)
//    {
//        HWREG(SYSCTL_RCC2) = ulRCC2;
//        HWREG(SYSCTL_RCC) = ulRCC;
//    }
//    else
//    {
//        HWREG(SYSCTL_RCC) = ulRCC;
//        HWREG(SYSCTL_RCC2) = ulRCC2;
//    }

//    //
//    // Set the requested system divider and disable the appropriate
//    // oscillators.  This value is not written immediately.
//    //
//    ulRCC &= ~(SYSCTL_RCC_SYSDIV_M | SYSCTL_RCC_USESYSDIV |
//               SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS);
//    ulRCC |= ulConfig & (SYSCTL_RCC_SYSDIV_M | SYSCTL_RCC_USESYSDIV |
//                         SYSCTL_RCC_IOSCDIS | SYSCTL_RCC_MOSCDIS);
//    ulRCC2 &= ~(SYSCTL_RCC2_SYSDIV2_M);
//    ulRCC2 |= ulConfig & SYSCTL_RCC2_SYSDIV2_M;
//    if(ulConfig & SYSCTL_RCC2_DIV400)
//    {
//        ulRCC |= SYSCTL_RCC_USESYSDIV;
//        ulRCC2 &= ~(SYSCTL_RCC_USESYSDIV);
//        ulRCC2 |= ulConfig & (SYSCTL_RCC2_DIV400 | SYSCTL_RCC2_SYSDIV2LSB);
//    }
//    else
//    {
//        ulRCC2 &= ~(SYSCTL_RCC2_DIV400);
//    }

//    //
//    // See if the PLL output is being used to clock the system.
//    //
//    if(!(ulConfig & SYSCTL_RCC_BYPASS))
//    {
//        //
//        // Wait until the PLL has locked.
//        //
//        for(ulDelay = 32768; ulDelay > 0; ulDelay--)
//        {
//            if(HWREG(SYSCTL_RIS) & SYSCTL_INT_PLL_LOCK)
//            {
//                break;
//            }
//        }

//        //
//        // Enable use of the PLL.
//        //
//        ulRCC &= ~(SYSCTL_RCC_BYPASS);
//        ulRCC2 &= ~(SYSCTL_RCC2_BYPASS2);
//    }

//    //
//    // Write the final RCC value.
//    //
//    HWREG(SYSCTL_RCC) = ulRCC;
//    HWREG(SYSCTL_RCC2) = ulRCC2;

//    //
//    // Delay for a little bit so that the system divider takes effect.
//    //
//    SysCtlDelay(16);
//}

////*****************************************************************************
////
////! Gets the processor clock rate.
////!
////! This function determines the clock rate of the processor clock, which is
////! also the clock rate of the peripheral modules (with the exception of
////! PWM, which has its own clock divider; other peripherals may have different
////! clocking, see the device data sheet for details).
////!
////! \note This cannot return accurate results if SysCtlClockSet() has not
////! been called to configure the clocking of the device, or if the device is
////! directly clocked from a crystal (or a clock source) that is not one of the
////! supported crystal frequencies.  In the latter case, this function should be
////! modified to directly return the correct system clock rate.
////!
////! \return The processor clock rate.
////
////*****************************************************************************
//unsigned long
//SysCtlClockGet(void)
//{
//    unsigned long ulRCC, ulRCC2, ulPLL, ulClk;

//    //
//    // Read RCC and RCC2.  For Sandstorm-class devices (which do not have
//    // RCC2), the RCC2 read returns 0, indicating that RCC2 is
//    // disabled (because the SYSCTL_RCC2_USERCC2 bit is clear).
//    //
//    ulRCC = HWREG(SYSCTL_RCC);
//    ulRCC2 = HWREG(SYSCTL_RCC2);

//    //
//    // Get the base clock rate.
//    //
//    switch((ulRCC2 & SYSCTL_RCC2_USERCC2) ?
//           (ulRCC2 & SYSCTL_RCC2_OSCSRC2_M) :
//           (ulRCC & SYSCTL_RCC_OSCSRC_M))
//    {
//        //
//        // The main oscillator is the clock source.  Determine its rate from
//        // the crystal setting field.
//        //
//        case SYSCTL_RCC_OSCSRC_MAIN:
//        {
//            ulClk = g_pulXtals[(ulRCC & SYSCTL_RCC_XTAL_M) >>
//                               SYSCTL_RCC_XTAL_S];
//            break;
//        }

//        //
//        // The internal oscillator is the source clock.
//        //
//        case SYSCTL_RCC_OSCSRC_INT:
//        {
//            //
//            // See if this is a Sandstorm-class or Fury-class device.
//            //
//            if(CLASS_IS_SANDSTORM)
//            {
//                //
//                // The internal oscillator on a Sandstorm-class device is
//                // 15 MHz +/- 50%.
//                //
//                ulClk = 15000000;
//            }
//            else if((CLASS_IS_FURY && REVISION_IS_A2) ||
//                    (CLASS_IS_DUSTDEVIL && REVISION_IS_A0))
//            {
//                //
//                // The internal oscillator on a rev A2 Fury-class device and a
//                // Dustdevil-class device is 12 MHz +/- 30%.
//                //
//                ulClk = 12000000;
//            }
//            else
//            {
//                //
//                // The internal oscillator on all other devices is 16 MHz.
//                //
//                ulClk = 16000000;
//            }
//            break;
//        }

//        //
//        // The internal oscillator divided by four is the source clock.
//        //
//        case SYSCTL_RCC_OSCSRC_INT4:
//        {
//            //
//            // See if this is a Sandstorm-class or Fury-class device.
//            //
//            if(CLASS_IS_SANDSTORM)
//            {
//                //
//                // The internal oscillator on a Sandstorm-class device is
//                // 15 MHz +/- 50%.
//                //
//                ulClk = 15000000 / 4;
//            }
//            else if((CLASS_IS_FURY && REVISION_IS_A2) ||
//                    (CLASS_IS_DUSTDEVIL && REVISION_IS_A0))
//            {
//                //
//                // The internal oscillator on a rev A2 Fury-class device and a
//                // Dustdevil-class device is 12 MHz +/- 30%.
//                //
//                ulClk = 12000000 / 4;
//            }
//            else
//            {
//                //
//                // The internal oscillator on a Tempest-class device is 16 MHz.
//                //
//                ulClk = 16000000 / 4;
//            }
//            break;
//        }

//        //
//        // The internal 30-KHz oscillator is the source clock.
//        //
//        case SYSCTL_RCC_OSCSRC_30:
//        {
//            //
//            // The internal 30-KHz oscillator has an accuracy of +/- 30%.
//            //
//            ulClk = 30000;
//            break;
//        }

//        //
//        // The 4.194304-MHz clock from the hibernate module is the clock
//        // source.
//        //
//        case SYSCTL_RCC2_OSCSRC2_419:
//        {
//            ulClk = 4194304;
//            break;
//        }

//        //
//        // The 32.768-KHz clock from the hibernate module is the source clock.
//        //
//        case SYSCTL_RCC2_OSCSRC2_32:
//        {
//            ulClk = 32768;
//            break;
//        }

//        //
//        // An unknown setting, so return a zero clock (that is, an unknown
//        // clock rate).
//        //
//        default:
//        {
//            return(0);
//        }
//    }

//    //
//    // See if the PLL is being used.
//    //
//    if(((ulRCC2 & SYSCTL_RCC2_USERCC2) && !(ulRCC2 & SYSCTL_RCC2_BYPASS2)) ||
//       (!(ulRCC2 & SYSCTL_RCC2_USERCC2) && !(ulRCC & SYSCTL_RCC_BYPASS)))
//    {
//        //
//        // Get the PLL configuration.
//        //
//        ulPLL = HWREG(SYSCTL_PLLCFG);

//        //
//        // See if this is a Sandstorm-class or Fury-class device.
//        //
//        if(CLASS_IS_SANDSTORM)
//        {
//            //
//            // Compute the PLL output frequency based on its input frequency.
//            // The formula for a Sandstorm-class devices is
//            // "(xtal * (f + 2)) / (r + 2)".
//            //
//            ulClk = ((ulClk * (((ulPLL & SYSCTL_PLLCFG_F_M) >>
//                                SYSCTL_PLLCFG_F_S) + 2)) /
//                     (((ulPLL & SYSCTL_PLLCFG_R_M) >> SYSCTL_PLLCFG_R_S) + 2));
//        }
//        else
//        {
//            //
//            // Compute the PLL output frequency based on its input
//            // frequency.  The formula for a Fury-class device is
//            // "(xtal * f) / ((r + 1) * 2)".
//            //
//            ulClk = ((ulClk * ((ulPLL & SYSCTL_PLLCFG_F_M) >>
//                               SYSCTL_PLLCFG_F_S)) /
//                     ((((ulPLL & SYSCTL_PLLCFG_R_M) >>
//                        SYSCTL_PLLCFG_R_S) + 1) * 2));
//        }

//        //
//        // See if the optional output divide by 2 is being used.
//        //
//        if(ulPLL & SYSCTL_PLLCFG_OD_2)
//        {
//            ulClk /= 2;
//        }

//        //
//        // See if the optional output divide by 4 is being used.
//        //
//        if(ulPLL & SYSCTL_PLLCFG_OD_4)
//        {
//            ulClk /= 4;
//        }

//        //
//        // Force the system divider to be enabled.  It is always used when
//        // using the PLL, but in some cases it does not read as being enabled.
//        //
//        ulRCC |= SYSCTL_RCC_USESYSDIV;
//    }

//    //
//    // See if the system divider is being used.
//    //
//    if(ulRCC & SYSCTL_RCC_USESYSDIV)
//    {
//        //
//        // Adjust the clock rate by the system clock divider.
//        //
//        if(ulRCC2 & SYSCTL_RCC2_USERCC2)
//        {
//            if((ulRCC2 & SYSCTL_RCC2_DIV400) &&
//               (((ulRCC2 & SYSCTL_RCC2_USERCC2) &&
//                 !(ulRCC2 & SYSCTL_RCC2_BYPASS2)) ||
//                (!(ulRCC2 & SYSCTL_RCC2_USERCC2) &&
//                 !(ulRCC & SYSCTL_RCC_BYPASS))))

//            {
//                ulClk = ((ulClk * 2) / (((ulRCC2 & (SYSCTL_RCC2_SYSDIV2_M |
//                                                    SYSCTL_RCC2_SYSDIV2LSB)) >>
//                                         (SYSCTL_RCC2_SYSDIV2_S - 1)) + 1));
//            }
//            else
//            {
//                ulClk /= (((ulRCC2 & SYSCTL_RCC2_SYSDIV2_M) >>
//                           SYSCTL_RCC2_SYSDIV2_S) + 1);
//            }
//        }
//        else
//        {
//            ulClk /= (((ulRCC & SYSCTL_RCC_SYSDIV_M) >> SYSCTL_RCC_SYSDIV_S) +
//                      1);
//        }
//    }

//    //
//    // Return the computed clock rate.
//    //
//    return(ulClk);
//}