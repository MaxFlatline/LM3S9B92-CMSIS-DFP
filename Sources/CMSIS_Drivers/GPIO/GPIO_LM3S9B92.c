/**
 * \file GPIO_LM3S9Bxx.c
 * \brief CMSIS-Driver GPIO realisation for LM3S
 * \author Max Flatline
 * \version 
 * \date 07.09.2025
 *
 * First sketch
 *
 */

#include "RTE_Components.h"             // Component selection
#include CMSIS_device_header

#include "Driver_GPIO.h"                // CMSIS Driver:GPIO

// Pin mapping
#define GPIO_MAX_PINS           65U
#define PIN_IS_AVAILABLE(n)     ((n) < GPIO_MAX_PINS)
#define PORT_IS_AVAILABLE(n)    (((n) <= GPIO_PORT_J) && ((n) >= GPIO_PORT_A))
/**
 * \defgroup Service inline functions
 * @{
 */

__STATIC_FORCEINLINE void SET_BIT (uint32_t * RegPtr, uint32_t BitPos){
    if(BitPos < 32){
        *RegPtr |= (1 << BitPos);
    }
}

/**@}*/

typedef ARM_GPIO_SignalEvent_t GPIO_CallbackArray_t;

typedef enum GPIO_Instance_e {
    GPIO_PORT_A = 0x00U,
    GPIO_PORT_B = 0x01U,
    GPIO_PORT_C = 0x02U,
    GPIO_PORT_D = 0x03U,
    GPIO_PORT_E = 0x04U,
    GPIO_PORT_F = 0x05U,
    GPIO_PORT_G = 0x06U,
    GPIO_PORT_H = 0x07U,
    GPIO_PORT_J = 0x08U
} GPIO_Instance_t;

static GPIO_CallbackArray_t GPIOA_CallbackArray [8];
static GPIO_CallbackArray_t GPIOB_CallbackArray [8];
static GPIO_CallbackArray_t GPIOC_CallbackArray [8];
static GPIO_CallbackArray_t GPIOD_CallbackArray [8];
static GPIO_CallbackArray_t GPIOE_CallbackArray [8];
static GPIO_CallbackArray_t GPIOF_CallbackArray [8];
static GPIO_CallbackArray_t GPIOG_CallbackArray [8];
static GPIO_CallbackArray_t GPIOH_CallbackArray [8];
static GPIO_CallbackArray_t GPIOJ_CallbackArray [8];

static GPIO_Type    *const GPIO_InstArray[9]   = {GPIOA,GPIOB,GPIOC,\
                                                          GPIOD,GPIOE,GPIOF,\
                                                          GPIOG,GPIOH,GPIOJ};
static GPIO_CallbackArray_t *const GPIO_InstCBArray[9] = {GPIOA_CallbackArray,GPIOB_CallbackArray,GPIOC_CallbackArray,\
                                                          GPIOD_CallbackArray,GPIOE_CallbackArray,GPIOF_CallbackArray,\
                                                          GPIOG_CallbackArray,GPIOH_CallbackArray,GPIOJ_CallbackArray};

static IRQn_Type const GPIO_IrqNumArray[9] = {GPIOA_IRQn, GPIOB_IRQn, GPIOC_IRQn, GPIOD_IRQn, GPIOE_IRQn,\
                                              GPIOF_IRQn, GPIOG_IRQn, GPIOH_IRQn, GPIOJ_IRQn};

// Setup GPIO Interface
static int32_t GPIO_Setup (GPIO_Instance_t Inst, ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    
    GPIO_Type * SelectedInst;
    GPIO_CallbackArray_t * SelectedInstCBarray;
    if (PIN_IS_AVAILABLE(pin) && PORT_IS_AVAILABLE(Inst)) {
        SelectedInst = GPIO_InstArray[Inst];
        SelectedInstCBarray = GPIO_InstCBArray[Inst];
        // Direction and Mode
        SelectedInst->DIR   &= (~(1<<pin));
        SelectedInst->AFSEL &= (~(1<<pin));
        // Output Drive Strength
        SelectedInst->DR2R  &= ~((1<<pin));
        SelectedInst->DR4R  |=   (1<<pin) ;
        SelectedInst->DR8R  &= ~((1<<pin));
        SelectedInst->SLR   &= ~((1<<pin));
        // Pin Type
        SelectedInst->ODR   &= ~((1<<pin));
        SelectedInst->PUR   &= ~((1<<pin));
        SelectedInst->PDR   &= ~((1<<pin));
        SelectedInst->DEN   |=   (1<<pin) ;
        // Analog Mode disabled
        if((SelectedInst == GPIOD) || (SelectedInst == GPIOE)){
            SelectedInst->AMSEL &= ~((1<<pin));
        }
        // Set CallBack event
        SelectedInstCBarray[pin] = cb_event;
    }
    else {
        result = ARM_GPIO_ERROR_PIN;
    }

    return result;
}

static int32_t GPIOA_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOA_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOA_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_A, pin, cb_event);
    return result;
}

static int32_t GPIOB_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOB_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOB_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_B, pin, cb_event);
    return result;
}

static int32_t GPIOC_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOC_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOC_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_C, pin, cb_event);
    return result;
}

static int32_t GPIOD_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOD_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOD_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_D, pin, cb_event);
    return result;
}

static int32_t GPIOE_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOE_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOE_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_E, pin, cb_event);
    return result;
}

static int32_t GPIOF_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOF_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOF_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_F, pin, cb_event);
    return result;
}

static int32_t GPIOG_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOG_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOG_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_G, pin, cb_event);
    return result;
}

static int32_t GPIOH_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOH_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOH_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_H, pin, cb_event);
    return result;
}

static int32_t GPIOJ_Setup (ARM_GPIO_Pin_t pin, ARM_GPIO_SignalEvent_t cb_event) {
    int32_t result = ARM_DRIVER_OK;
    // TODO: Get current mode and set clocking. Currently - only RUN MODE
    if(!(SYSCTL->RCGC2 & SYSCTL_RCGC2_GPIOJ_Msk)){
        SYSCTL->RCGC2 |= SYSCTL_RCGC2_GPIOJ_Msk;
    }
    result = GPIO_Setup(GPIO_PORT_J, pin, cb_event);
    return result;
}

// Set GPIO Direction
static int32_t GPIO_SetDirection (GPIO_Instance_t Inst, ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    GPIO_Type * SelectedInst;
    
    if (PIN_IS_AVAILABLE(pin) && PORT_IS_AVAILABLE(Inst)) {
        SelectedInst = GPIO_InstArray[Inst];
        switch (direction) {
            case ARM_GPIO_INPUT:
                // Direction and Mode
                SelectedInst->DIR   &= (~(1 << pin));
                SelectedInst->AFSEL &= (~(1 << pin));
                // Output Drive Strength
                SelectedInst->DR2R  &= ~((1 << pin));
                SelectedInst->DR4R  &= ~((1 << pin));
                SelectedInst->DR8R  &= ~((1 << pin));
                SelectedInst->SLR   &= ~((1 << pin));
                // Pin Type
                SelectedInst->ODR   &= ~((1 << pin));
                SelectedInst->PUR   &= ~((1 << pin));
                SelectedInst->PDR   &= ~((1 << pin));
                SelectedInst->DEN   |=   (1 << pin) ;
                // Analog Mode disabled
                if((SelectedInst == GPIOD) || (SelectedInst == GPIOE)){
                    SelectedInst->AMSEL &= ~((1 << pin));
                }
                break;
            case ARM_GPIO_OUTPUT:
                // Direction and Mode
                SelectedInst->DIR   |=   (1 << pin) ;
                SelectedInst->AFSEL &= (~(1 << pin));
                // Output Drive Strength
                SelectedInst->DR2R  &= ~((1 << pin));
                SelectedInst->DR4R  |=   (1 << pin) ;
                SelectedInst->DR8R  &= ~((1 << pin));
                SelectedInst->SLR   &= ~((1 << pin));
                // Pin Type
                SelectedInst->ODR   &= ~((1 << pin));
                SelectedInst->PUR   &= ~((1 << pin));
                SelectedInst->PDR   &= ~((1 << pin));
                SelectedInst->DEN   |=   (1 << pin) ;
                // Analog Mode disabled
                if((SelectedInst == GPIOD) || (SelectedInst == GPIOE)){
                    SelectedInst->AMSEL &= ~((1 << pin));
                }
                break;
            default:
                result = ARM_DRIVER_ERROR_PARAMETER;
                break;
        }
    }
    else {
        result = ARM_GPIO_ERROR_PIN;
    }
    __NOP();
    __NOP();
    return result;
}

static int32_t GPIOA_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_A, pin, direction);
    return result;
}

static int32_t GPIOB_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_B, pin, direction);
    return result;
}

static int32_t GPIOC_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_C, pin, direction);
    return result;
}

static int32_t GPIOD_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_D, pin, direction);
    return result;
}

static int32_t GPIOE_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_E, pin, direction);
    return result;
}

static int32_t GPIOF_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_F, pin, direction);
    return result;
}

static int32_t GPIOG_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_G, pin, direction);
    return result;
}

static int32_t GPIOH_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_H, pin, direction);
    return result;
}

static int32_t GPIOJ_SetDirection (ARM_GPIO_Pin_t pin, ARM_GPIO_DIRECTION direction) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetDirection(GPIO_PORT_J, pin, direction);
    return result;
}

// Set GPIO Output Mode
static int32_t GPIO_SetOutputMode (GPIO_Instance_t Inst, ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    GPIO_Type * SelectedInst;
    if(PIN_IS_AVAILABLE(pin) && PORT_IS_AVAILABLE(Inst)){
        SelectedInst = GPIO_InstArray[Inst];
        switch (mode) {
            case ARM_GPIO_OPEN_DRAIN:
                SelectedInst->ODR   |=   (1 << pin) ;
                break;
            case ARM_GPIO_PUSH_PULL:
                SelectedInst->ODR   &= ~((1 << pin));
                break;
            default:
                result = ARM_DRIVER_ERROR_PARAMETER;
                break;
        }
    }
    else {
        result = ARM_GPIO_ERROR_PIN;
    }
    return result;
}

static int32_t GPIOA_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_A, pin, mode);
    return result;
}

static int32_t GPIOB_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_B, pin, mode);
    return result;
}

static int32_t GPIOC_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_C, pin, mode);
    return result;
}

static int32_t GPIOD_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_D, pin, mode);
    return result;
}

static int32_t GPIOE_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_E, pin, mode);
    return result;
}

static int32_t GPIOF_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_F, pin, mode);
    return result;
}

static int32_t GPIOG_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_G, pin, mode);
    return result;
}

static int32_t GPIOH_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_H, pin, mode);
    return result;
}

static int32_t GPIOJ_SetOutputMode (ARM_GPIO_Pin_t pin, ARM_GPIO_OUTPUT_MODE mode) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetOutputMode(GPIO_PORT_J, pin, mode);
    return result;
}

// Set GPIO Pull Resistor
static int32_t GPIO_SetPullResistor (GPIO_Instance_t Inst, ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    GPIO_Type * SelectedInst;
    if(PIN_IS_AVAILABLE(pin) && PORT_IS_AVAILABLE(Inst)){
        SelectedInst = GPIO_InstArray[Inst];
        switch (resistor) {
            case ARM_GPIO_PULL_NONE:
                SelectedInst->PUR &= ~(1<<pin);
                SelectedInst->PDR &= ~(1<<pin);
                break;
            case ARM_GPIO_PULL_UP:
                SelectedInst->PUR |=  (1<<pin);
                break;
            case ARM_GPIO_PULL_DOWN:
                SelectedInst->PDR |=  (1<<pin);
                break;
            default:
                result = ARM_DRIVER_ERROR_PARAMETER;
                break;
        }
    }
    else {
        result = ARM_GPIO_ERROR_PIN;
    }
    return result;
}

static int32_t GPIOA_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_A, pin, resistor);
    return result;
}

static int32_t GPIOB_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_B, pin, resistor);
    return result;
}

static int32_t GPIOC_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_C, pin, resistor);
    return result;
}

static int32_t GPIOD_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_D, pin, resistor);
    return result;
}

static int32_t GPIOE_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_E, pin, resistor);
    return result;
}

static int32_t GPIOF_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_F, pin, resistor);
    return result;
}

static int32_t GPIOG_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_G, pin, resistor);
    return result;
}

static int32_t GPIOH_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_H, pin, resistor);
    return result;
}

static int32_t GPIOJ_SetPullResistor (ARM_GPIO_Pin_t pin, ARM_GPIO_PULL_RESISTOR resistor) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetPullResistor(GPIO_PORT_J, pin, resistor);
    return result;
}


// Set GPIO Event Trigger
static int32_t GPIO_SetEventTrigger (GPIO_Instance_t Inst, ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    GPIO_Type * SelectedInst;
    GPIO_CallbackArray_t * SelectedInstCBarray;
    IRQn_Type SelectedInstIrqNum;
    if(PIN_IS_AVAILABLE(pin) && PORT_IS_AVAILABLE(Inst)){
        SelectedInst = GPIO_InstArray[Inst];
        SelectedInstCBarray = GPIO_InstCBArray[Inst];
        SelectedInstIrqNum = GPIO_IrqNumArray[Inst];
        // Set interrupt sence to edge detection
        SelectedInst->IS &= ~(1<<pin);
        SelectedInst->IC  = (1<<pin);
        switch (trigger) {
            case ARM_GPIO_TRIGGER_NONE:
                SelectedInst->IBE |=  (1<<pin);
                SelectedInst->IM  &= ~(1<<pin);
                __NVIC_DisableIRQ(SelectedInstIrqNum);
                break;
            case ARM_GPIO_TRIGGER_RISING_EDGE:
                SelectedInst->IBE &= ~(1<<pin);
                SelectedInst->IEV |=  (1<<pin);
                SelectedInst->IM  |=  (1<<pin);
                __NVIC_EnableIRQ(SelectedInstIrqNum);
                break;
            case ARM_GPIO_TRIGGER_FALLING_EDGE:
                SelectedInst->IBE &= ~(1<<pin);
                SelectedInst->IEV &= ~(1<<pin);
                SelectedInst->IM  |=  (1<<pin);
                __NVIC_EnableIRQ(SelectedInstIrqNum);
                break;
            case ARM_GPIO_TRIGGER_EITHER_EDGE:
                SelectedInst->IBE |=  (1<<pin);
                SelectedInst->IM  |=  (1<<pin);
                __NVIC_EnableIRQ(SelectedInstIrqNum);
                break;
            default:
                result = ARM_DRIVER_ERROR_PARAMETER;
                break;
        }
    }
    else {
        result = ARM_GPIO_ERROR_PIN;
    }
    return result;
}

static int32_t GPIOA_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_A, pin, trigger);
    return result;
}

static int32_t GPIOB_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_B, pin, trigger);
    return result;
}

static int32_t GPIOC_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_C, pin, trigger);
    return result;
}

static int32_t GPIOD_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_D, pin, trigger);
    return result;
}

static int32_t GPIOE_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_E, pin, trigger);
    return result;
}

static int32_t GPIOF_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_F, pin, trigger);
    return result;
}

static int32_t GPIOG_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_G, pin, trigger);
    return result;
}

static int32_t GPIOH_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_H, pin, trigger);
    return result;
}

static int32_t GPIOJ_SetEventTrigger (ARM_GPIO_Pin_t pin, ARM_GPIO_EVENT_TRIGGER trigger) {
    int32_t result = ARM_DRIVER_OK;
    result = GPIO_SetEventTrigger(GPIO_PORT_J, pin, trigger);
    return result;
}

// Set GPIO Output Level
static void GPIO_SetOutput (GPIO_Instance_t Inst, ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_Type * SelectedInst;
    if (PIN_IS_AVAILABLE(pin) && PORT_IS_AVAILABLE(Inst)) {
        SelectedInst = GPIO_InstArray[Inst];
        SelectedInst->DATA[1<<pin] = (val) ? (1 << pin) : (0);
    }
}

static void GPIOA_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_A, pin, val);
}
static void GPIOB_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_B, pin, val);
}
static void GPIOC_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_C, pin, val);
}
static void GPIOD_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_D, pin, val);
}
static void GPIOE_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_E, pin, val);
}
static void GPIOF_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_F, pin, val);
}
static void GPIOG_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_J, pin, val);
}
static void GPIOH_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_H, pin, val);
}
static void GPIOJ_SetOutput (ARM_GPIO_Pin_t pin, uint32_t val) {
    GPIO_SetOutput(GPIO_PORT_J, pin, val);
}

// Get GPIO Input Level
static uint32_t GPIO_GetInput (GPIO_Instance_t Inst, ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    GPIO_Type * SelectedInst;
    if (PIN_IS_AVAILABLE(pin) && PORT_IS_AVAILABLE(Inst)) {
        SelectedInst = GPIO_InstArray[Inst];
        val = ((SelectedInst->DATA[(1<<pin)]) == (1<<pin));
    }
    return val;
}

static uint32_t GPIOA_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_A, pin);
    return val;
}
static uint32_t GPIOB_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_B, pin);
    return val;
}
static uint32_t GPIOC_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_C, pin);
    return val;
}
static uint32_t GPIOD_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_D, pin);
    return val;
}
static uint32_t GPIOE_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_E, pin);
    return val;
}
static uint32_t GPIOF_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_F, pin);
    return val;
}
static uint32_t GPIOG_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_G, pin);
    return val;
}
static uint32_t GPIOH_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_H, pin);
    return val;
}
static uint32_t GPIOJ_GetInput (ARM_GPIO_Pin_t pin) {
    uint32_t val = 0U;
    val = GPIO_GetInput(GPIO_PORT_J, pin);
    return val;
}

// Interrupt Handlers (redefinition of WEAK Irq Handlers)
void GPIO_IrqHandler (GPIO_Instance_t Inst){
    uint8_t InterruptsPendingMasked;
    GPIO_Type * SelectedInst;
    GPIO_CallbackArray_t * SelectedInstCBarray;
    
    uint8_t Event;
    
    
    if (PORT_IS_AVAILABLE(Inst)) {
        SelectedInst = GPIO_InstArray[Inst];
        SelectedInstCBarray = GPIO_InstCBArray[Inst];
        // Get all pending external interrupts of a port
        InterruptsPendingMasked = (uint8_t)(SelectedInst->MIS);
        // Clear triggered interrupts
        SelectedInst->IC = InterruptsPendingMasked;
        if(InterruptsPendingMasked & GPIO_MIS_MIS0_Msk) {
            if(SelectedInstCBarray[0] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE0_Msk) == GPIO_IBE_IBE0_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV0_Msk) == GPIO_IEV_IEV0_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[0](0, Event);
            }
        }
        if(InterruptsPendingMasked & GPIO_MIS_MIS1_Msk) {
            if(SelectedInstCBarray[1] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE1_Msk) == GPIO_IBE_IBE1_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV1_Msk) == GPIO_IEV_IEV1_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[1](1, Event);
            }
        }
        if(InterruptsPendingMasked & GPIO_MIS_MIS2_Msk) {
            if(SelectedInstCBarray[2] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE2_Msk) == GPIO_IBE_IBE2_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV2_Msk) == GPIO_IEV_IEV2_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[2](2, Event);
            }
        }
        if(InterruptsPendingMasked & GPIO_MIS_MIS3_Msk) {
            if(SelectedInstCBarray[3] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE3_Msk) == GPIO_IBE_IBE3_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV3_Msk) == GPIO_IEV_IEV3_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[3](3, Event);
            }
        }
        if(InterruptsPendingMasked & GPIO_MIS_MIS4_Msk) {
            if(SelectedInstCBarray[4] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE4_Msk) == GPIO_IBE_IBE4_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV4_Msk) == GPIO_IEV_IEV4_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[4](4, Event);
            }
        }
        if(InterruptsPendingMasked & GPIO_MIS_MIS5_Msk) {
            if(SelectedInstCBarray[5] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE5_Msk) == GPIO_IBE_IBE5_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV5_Msk) == GPIO_IEV_IEV5_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[5](5, Event);
            }
        }
        if(InterruptsPendingMasked & GPIO_MIS_MIS6_Msk) {
            if(SelectedInstCBarray[6] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE6_Msk) == GPIO_IBE_IBE6_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV6_Msk) == GPIO_IEV_IEV6_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[6](6, Event);
            }
        }
        if(InterruptsPendingMasked & GPIO_MIS_MIS7_Msk) {
            if(SelectedInstCBarray[7] != NULL){
                if ((SelectedInst->IBE & GPIO_IBE_IBE7_Msk) == GPIO_IBE_IBE7_Msk) {
                    // Sensitivity to both edges - hardware can't distinguish between rising and falling edge
                    Event = ARM_GPIO_EVENT_EITHER_EDGE;
                }
                else if ((SelectedInst->IEV & GPIO_IEV_IEV7_Msk) == GPIO_IEV_IEV7_Msk) {
                    // Rising edge enabled
                    Event = ARM_GPIO_EVENT_RISING_EDGE;
                }
                else {
                    // Falling edge enabled
                    Event = ARM_GPIO_EVENT_FALLING_EDGE;
                }
                SelectedInstCBarray[7](7, Event);
            }
        }
    }
}

void GPIOA_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_A);
}

void GPIOB_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_B);
}

void GPIOC_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_C);
}

void GPIOD_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_D);
}

void GPIOE_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_E);
}

void GPIOF_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_F);
}

void GPIOG_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_G);
}

void GPIOH_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_H);
}

void GPIOJ_Handler (void){
    GPIO_IrqHandler(GPIO_PORT_J);
}

// GPIO Driver access structure A
ARM_DRIVER_GPIO Driver_GPIO0 = {
  GPIOA_Setup,
  GPIOA_SetDirection,
  GPIOA_SetOutputMode,
  GPIOA_SetPullResistor,
  GPIOA_SetEventTrigger,
  GPIOA_SetOutput,
  GPIOA_GetInput
};

// GPIO Driver access structure B
ARM_DRIVER_GPIO Driver_GPIO1 = {
  GPIOB_Setup,
  GPIOB_SetDirection,
  GPIOB_SetOutputMode,
  GPIOB_SetPullResistor,
  GPIOB_SetEventTrigger,
  GPIOB_SetOutput,
  GPIOB_GetInput
};
// GPIO Driver access structure C
ARM_DRIVER_GPIO Driver_GPIO2 = {
  GPIOC_Setup,
  GPIOC_SetDirection,
  GPIOC_SetOutputMode,
  GPIOC_SetPullResistor,
  GPIOC_SetEventTrigger,
  GPIOC_SetOutput,
  GPIOC_GetInput
};
// GPIO Driver access structure D
ARM_DRIVER_GPIO Driver_GPIO3 = {
  GPIOD_Setup,
  GPIOD_SetDirection,
  GPIOD_SetOutputMode,
  GPIOD_SetPullResistor,
  GPIOD_SetEventTrigger,
  GPIOD_SetOutput,
  GPIOD_GetInput
};
// GPIO Driver access structure E
ARM_DRIVER_GPIO Driver_GPIO4 = {
  GPIOE_Setup,
  GPIOE_SetDirection,
  GPIOE_SetOutputMode,
  GPIOE_SetPullResistor,
  GPIOE_SetEventTrigger,
  GPIOE_SetOutput,
  GPIOE_GetInput
};
// GPIO Driver access structure F
ARM_DRIVER_GPIO Driver_GPIO5 = {
  GPIOF_Setup,
  GPIOF_SetDirection,
  GPIOF_SetOutputMode,
  GPIOF_SetPullResistor,
  GPIOF_SetEventTrigger,
  GPIOF_SetOutput,
  GPIOF_GetInput
};
// GPIO Driver access structure G
ARM_DRIVER_GPIO Driver_GPIO6 = {
  GPIOG_Setup,
  GPIOG_SetDirection,
  GPIOG_SetOutputMode,
  GPIOG_SetPullResistor,
  GPIOG_SetEventTrigger,
  GPIOG_SetOutput,
  GPIOG_GetInput
};
// GPIO Driver access structure H
ARM_DRIVER_GPIO Driver_GPIO7 = {
  GPIOH_Setup,
  GPIOH_SetDirection,
  GPIOH_SetOutputMode,
  GPIOH_SetPullResistor,
  GPIOH_SetEventTrigger,
  GPIOH_SetOutput,
  GPIOH_GetInput
};
// GPIO Driver access structure J
ARM_DRIVER_GPIO Driver_GPIO8 = {
  GPIOJ_Setup,
  GPIOJ_SetDirection,
  GPIOJ_SetOutputMode,
  GPIOJ_SetPullResistor,
  GPIOJ_SetEventTrigger,
  GPIOJ_SetOutput,
  GPIOJ_GetInput
};
