/*************************************************************************//**
 * @file     system_lm3s9b92.h
 * @brief    CMSIS-Core(M) Device Peripheral Access Layer Header File for
 *           Device LM3S9B92
 * @version  V1.0.1
 * @date     20. September 2025
 *****************************************************************************/
/*
 * Copyright (c) TODO: set copyright
 */

#ifndef SYSTEM_LM3S9B92_H
#define SYSTEM_LM3S9B92_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/**
  \brief Exception / Interrupt Handler Function Prototype
*/
typedef void(*VECTOR_TABLE_Type)(void);

/**
  \brief System Clock Frequency (Core Clock)
*/
extern uint32_t SystemCoreClock;

/**
  \brief Setup the microcontroller system.

   Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit (void);


/**
  \brief  Update SystemCoreClock variable.

   Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate (void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_LM3S9B92_H */
