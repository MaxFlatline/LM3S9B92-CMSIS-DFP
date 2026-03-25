// Header: Main source file
// File Name: main.c
// Author: Max Flatline
// Date: 07.07.2025

#include "RTE_Components.h"             // Component selection
#include CMSIS_device_header
#include "cmsis_os2.h"                  // CMSIS:RTOS2
#include "cmsis_dv.h"
#include "unity_fixture.h"
#include <stdio.h>
#include "EventRecorder.h"              // CMSIS-View:Event Recorder&&DAP

#include "Driver_I2C.h"                 // CMSIS Driver:I2C
#include "Driver_GPIO.h"                // CMSIS Driver:GPIO

#include <math.h>

static void RunAllTests (void);


/* GPIO driver instance */
extern ARM_DRIVER_GPIO             Driver_GPIO5;
static ARM_DRIVER_GPIO *LEDdrv =  &Driver_GPIO5;
 
/* Pin mapping */
#define GPIO_PIN0       0U
#define GPIO_PIN1       1U
#define GPIO_PIN2       2U
#define GPIO_PIN3       3U
#define GPIO_PIN4       4U
#define GPIO_PIN5       5U
#define GPIO_PIN6       6U
#define GPIO_PIN7       7U
// 
///* GPIO Signal Event callback */
//static void GPIO_SignalEvent (ARM_GPIO_Pin_t pin, uint32_t event) {
// 
//  switch (pin) {
//    case GPIO_PIN1:
//      /* Events on pin GPIO_PIN1 */
//      if (event & ARM_GPIO_EVENT_RISING_EDGE) {
//        /* Rising-edge detected */
//      }
//      if (event & ARM_GPIO_EVENT_FALLING_EDGE) {
//        /* Falling-edge detected */
//      }
//      break;
//  }
//}
// 
///* Get GPIO Input 0 */
//uint32_t GPIO_GetInput0 (void) {
//  return (GPIOdrv->GetInput(GPIO_PIN0));
//}
// 
///* Get GPIO Input 1 */
//uint32_t GPIO_GetInput1 (void) {
//  return (GPIOdrv->GetInput(GPIO_PIN1));
//}
// 
///* Set GPIO Output Pin 2 */
//void GPIO_SetOutput2 (uint32_t val) {
//  GPIOdrv->SetOutput(GPIO_PIN2, val);
//}
// 
///* Set GPIO Output Pin 3 */
//void GPIO_SetOutput3 (uint32_t val) {
//  GPIOdrv->SetOutput(GPIO_PIN3, val);
//}
// 
///* Setup GPIO pins */
//void GPIO_Setup (void) {
// 
//  /* Pin GPIO_PIN0: Input */
//  GPIOdrv->Setup          (GPIO_PIN0, NULL);
//  GPIOdrv->SetDirection   (GPIO_PIN0, ARM_GPIO_INPUT);
// 
//  /* Pin GPIO_PIN1: Input with trigger on rising and falling edge */
//  GPIOdrv->Setup          (GPIO_PIN1, GPIO_SignalEvent);
//  GPIOdrv->SetDirection   (GPIO_PIN1, ARM_GPIO_INPUT);
//  GPIOdrv->SetEventTrigger(GPIO_PIN1, ARM_GPIO_TRIGGER_EITHER_EDGE);
// 
//  /* Pin GPIO_PIN2: Output push-pull (initial level 0) */
//  GPIOdrv->Setup          (GPIO_PIN2, NULL);
//  GPIOdrv->SetOutput      (GPIO_PIN2, 0U);
//  GPIOdrv->SetDirection   (GPIO_PIN2, ARM_GPIO_OUTPUT);
// 
//  /* Pin GPIO_PIN3: Output open-drain with pull-up resistor (initial level 1) */
//  GPIOdrv->Setup          (GPIO_PIN3, NULL);
//  GPIOdrv->SetPullResistor(GPIO_PIN3, ARM_GPIO_PULL_UP);
//  GPIOdrv->SetOutputMode  (GPIO_PIN3, ARM_GPIO_OPEN_DRAIN);
//  GPIOdrv->SetOutput      (GPIO_PIN3, 1U);
//  GPIOdrv->SetDirection   (GPIO_PIN3, ARM_GPIO_OUTPUT);
//}


/*----------------------------------------------------------------------------
 * Application main thread
 *---------------------------------------------------------------------------*/
void app_main (void *argument) {
    
    // LED1
    LEDdrv->Setup          (GPIO_PIN4, NULL);
    LEDdrv->SetOutput      (GPIO_PIN4, 0U);
    LEDdrv->SetDirection   (GPIO_PIN4, ARM_GPIO_OUTPUT);
    // LED2
    LEDdrv->Setup          (GPIO_PIN5, NULL);
    LEDdrv->SetOutput      (GPIO_PIN5, 1U);
    LEDdrv->SetDirection   (GPIO_PIN5, ARM_GPIO_OUTPUT);
    osThreadNew(cmsis_dv, NULL, NULL);
    
    for (;;) {
        LEDdrv->SetOutput      (GPIO_PIN4, 1U);
        LEDdrv->SetOutput      (GPIO_PIN5, 0U);
        osDelay(500);
        LEDdrv->SetOutput      (GPIO_PIN4, 0U);
        LEDdrv->SetOutput      (GPIO_PIN5, 1U);
        osDelay(500);
    }
}

int main (void) {
    
    osStatus_t OS_Result;
    uint32_t EVr_Result;
    osThreadId_t AppMainID;
    
    
    SystemCoreClockUpdate();
    OS_Result = osKernelInitialize();                 // Initialize CMSIS-RTOS
    
    EVr_Result = EventRecorderInitialize (EventRecordAll, 1);    // initialize and start Event Recorder
    
    AppMainID = osThreadNew(app_main, NULL, NULL);    // Create application main thread
    OS_Result = osKernelStart();                      // Start thread execution
    
    while (1) {

    }
    
    return 0;
}

static void RunAllTests (void) {
    
    
    
}
