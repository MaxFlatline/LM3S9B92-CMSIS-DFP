/**************************************************************************//**
 * @file     startup_lm3s9b92_ac6.S
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device LM3S9B92 (using Arm Compiler 6 with scatter file)
 * @version  V1.0.0
 * @date     10. October 2025
 ******************************************************************************/
/*
 * Copyright (c) Add copyright
 */

                .syntax  unified
                .arch    armv7-m


//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------


//<h> Stack Configuration
//  <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
//</h>

                #define Stack_Size 0x00000100
                //.pushsection .section ARM_LIB_HEAP, "awx", , Stack_Size
//                AREA     STACK, NOINIT, READWRITE, ALIGN=3
                .globl   __stack_limit
                .globl   __initial_sp

                .section .stack
                .align      3

__stack_limit:
                .space      Stack_Size
                .size       __stack_limit, . - __stack_limit
__initial_sp:
                .size       __initial_sp, . - __initial_sp



//<h> Heap Configuration
//  <o> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
//</h>

                #define Heap_Size 0x00000100
                
                .section    .heap
                .align      3
                #if Heap_Size > 0
    .globl      __heap_base
    .globl      __heap_limit
__heap_base:
                .size       __heap_base, . - __heap_base
__heap_limit:
                .size       __heap_limit, . - __heap_limit
                #endif
                    
                    
                    
                    
                #define __INITIAL_SP     __initial_sp
                #define __STACK_LIMIT    __stack_limit

                .section RESET
                .align   2
                .globl   __Vectors
                .globl   __Vectors_End
                .globl   __Vectors_Size

__Vectors:
                .long    __INITIAL_SP                       /*     Initial Stack Pointer */
                .long    Reset_Handler                      /*     Reset Handler */
                .long    NMI_Handler                        /* -14 NMI Handler */
                .long    HardFault_Handler                  /* -13 Hard Fault Handler */
                .long    MemManage_Handler                  /* -12 MPU Fault Handler */
                .long    BusFault_Handler                   /* -11 Bus Fault Handler */
                .long    UsageFault_Handler                 /* -10 Usage Fault Handler */
                .long    SecureFault_Handler                /*  -9 Secure Fault Handler */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    SVC_Handler                        /*  -5 SVCall Handler */
                .long    DebugMon_Handler                   /*  -4 Debug Monitor Handler */
                .long    0                                  /*     Reserved */
                .long    PendSV_Handler                     /*  -2 PendSV Handler */
                .long    SysTick_Handler                    /*  -1 SysTick Handler */

                /* Interrupts */
                .long    GPIOA_Handler                      /*   0 GPIOA Handler */
                .long    GPIOB_Handler                      /*   1 GPIOB Handler */
                .long    GPIOC_Handler                      /*   2 GPIOC Handler */
                .long    GPIOD_Handler                      /*   3 GPIOD Handler */
                .long    GPIOE_Handler                      /*   4 GPIOE Handler */
                .long    UART0_Handler                      /*   5 UART0 Handler */
                .long    UART1_Handler                      /*   6 UART1 Handler */
                .long    SSI0_Handler                       /*   7 SSI Handler */
                .long    I2C0_Handler                       /*   8 I2C0 Handler */
                .long    PWM0Fault_Handler                  /*   9 PWM0 Fault Handler */
                .long    PWM0_0_Handler                     /*  10 PWM0 Generator 0 Handler */
                .long    PWM0_1_Handler                     /*  11 PWM0 Generator 1 Handler */
                .long    PWM0_2_Handler                     /*  12 PWM0 Generator 2 Handler */
                .long    QEI0_Handler                       /*  13 Quadrature Encoder 0 Handler */
                .long    ADC0SS0_Handler                    /*  14 ADC0 Sequence 0 Handler */
                .long    ADC0SS1_Handler                    /*  15 ADC0 Sequence 1 Handler */
                .long    ADC0SS2_Handler                    /*  16 ADC0 Sequence 2 Handler */
                .long    ADC0SS3_Handler                    /*  17 ADC0 Sequence 3 Handler */
                .long    WDT0_Handler                       /*  18 Watchdog Timer 0 Handler */
                .long    TIM0A_Handler                      /*  19 Timer 0 Subtimer A Handler */
                .long    TIM0B_Handler                      /*  20 Timer 0 Subtimer B Handler */
                .long    TIM1A_Handler                      /*  21 Timer 1 Subtimer A Handler */
                .long    TIM1B_Handler                      /*  22 Timer 1 Subtimer B Handler */
                .long    TIM2A_Handler                      /*  23 Timer 2 Subtimer A Handler */
                .long    TIM2B_Handler                      /*  24 Timer 2 Subtimer B Handler */
                .long    COMP0_Handler                      /*  25 Analog Comparator 0 Handler */
                .long    COMP1_Handler                      /*  26 Analog Comparator 1 Handler */
                .long    COMP2_Handler                      /*  27 Analog Comparator 2 Handler */
                .long    SYSCTL_Handler                     /*  28 System Cortrol Handler */
                .long    FLASH_Handler                      /*  29 FLASH Handler */
                .long    GPIOF_Handler                      /*  30 GPIOF Handler */
                .long    GPIOG_Handler                      /*  31 GPIOG Handler */
                .long    GPIOH_Handler                      /*  32 GPIOH Handler */
                .long    UART2_Handler                      /*  33 UART2 Handler */
                .long    SSI1_Handler                       /*  34 SSI1 Handler */
                .long    TIM3A_Handler                      /*  35 Timer 3 Subtimer A Handler */
                .long    TIM3B_Handler                      /*  36 Timer 3 Subtimer B Handler */
                .long    I2C1_Handler                       /*  37 I2C1 Handler */
                .long    QEI1_Handler                       /*  38 Quadrature Encoder 1 Handler */
                .long    CAN0_Handler                       /*  39 CAN0 Handler */
                .long    CAN1_Handler                       /*  40 CAN1 Handler */
                .long    CAN2_Handler                       /*  41 CAN2 Handler */
                .long    ETH0_Handler                       /*  42 Ethernet 0 Handler */ 
                .long    HIB_Handler                        /*  43 Hibernation module Handler */
                .long    USB0_Handler                       /*  44 USB0 Handler */
                .long    PWM0_3_Handler                     /*  45 PWM0 Generator 3 Handler */
                .long    UDMA_Handler                       /*  46 uDMA Handler */
                .long    UDMAError_Handler                  /*  47 uDMA Error Handler */
                .long    ADC1SS0_Handler                    /*  48 ADC1 Sequence 0 Handler */
                .long    ADC1SS1_Handler                    /*  49 ADC1 Sequence 1 Handler */
                .long    ADC1SS2_Handler                    /*  50 ADC1 Sequence 2 Handler */
                .long    ADC1SS3_Handler                    /*  51 ADC1 Sequence 3 Handler */
                .long    I2S0_Handler                       /*  52 I2S0 Handler */
                .long    EPI0_Handler                       /*  53 External Peripheral Interface Handler */
                .long    GPIOJ_Handler                      /*  54 GPIOJ Handler */

                .space   (70 * 4)                           /* Interrupts 71 .. 480 are left out */
__Vectors_End:
                .equ     __Vectors_Size, __Vectors_End - __Vectors
                .size    __Vectors, . - __Vectors


                .thumb
                .section .text
                .align   2

                .thumb_func
                .type    Reset_Handler, %function
                .globl   Reset_Handler
                .fnstart
Reset_Handler:
                ldr      r0, =__INITIAL_SP
                msr      psp, r0

                ldr      r0, =__STACK_LIMIT
                msr      msplim, r0
                msr      psplim, r0

                bl       SystemInit

                bl       __main

                .fnend
                .size    Reset_Handler, . - Reset_Handler


/* The default macro is not used for HardFault_Handler
 * because this results in a poor debug illusion.
 */
                .thumb_func
                .type    HardFault_Handler, %function
                .weak    HardFault_Handler
                .fnstart
HardFault_Handler:
                b        .
                .fnend
                .size    HardFault_Handler, . - HardFault_Handler

                .thumb_func
                .type    Default_Handler, %function
                .weak    Default_Handler
                .fnstart
Default_Handler:
                b        .
                .fnend
                .size    Default_Handler, . - Default_Handler

/* Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols with an endless loop.
 * They can be overwritten by real handlers.
 */
                .macro   Set_Default_Handler  Handler_Name
                .weak    \Handler_Name
                .set     \Handler_Name, Default_Handler
                .endm

/* Default exception/interrupt handler */
                Set_Default_Handler  NMI_Handler
                Set_Default_Handler  MemManage_Handler
                Set_Default_Handler  BusFault_Handler
                Set_Default_Handler  UsageFault_Handler
                Set_Default_Handler  SecureFault_Handler
                Set_Default_Handler  SVC_Handler
                Set_Default_Handler  DebugMon_Handler
                Set_Default_Handler  PendSV_Handler
                Set_Default_Handler  SysTick_Handler

                Set_Default_Handler  GPIOA_Handler          
                Set_Default_Handler  GPIOB_Handler          
                Set_Default_Handler  GPIOC_Handler          
                Set_Default_Handler  GPIOD_Handler          
                Set_Default_Handler  GPIOE_Handler          
                Set_Default_Handler  UART0_Handler          
                Set_Default_Handler  UART1_Handler          
                Set_Default_Handler  SSI0_Handler           
                Set_Default_Handler  I2C0_Handler           
                Set_Default_Handler  PWM0Fault_Handler      
                Set_Default_Handler  PWM0_0_Handler         
                Set_Default_Handler  PWM0_1_Handler         
                Set_Default_Handler  PWM0_2_Handler         
                Set_Default_Handler  QEI0_Handler           
                Set_Default_Handler  ADC0SS0_Handler        
                Set_Default_Handler  ADC0SS1_Handler        
                Set_Default_Handler  ADC0SS2_Handler        
                Set_Default_Handler  ADC0SS3_Handler        
                Set_Default_Handler  WDT0_Handler           
                Set_Default_Handler  TIM0A_Handler          
                Set_Default_Handler  TIM0B_Handler          
                Set_Default_Handler  TIM1A_Handler          
                Set_Default_Handler  TIM1B_Handler          
                Set_Default_Handler  TIM2A_Handler          
                Set_Default_Handler  TIM2B_Handler          
                Set_Default_Handler  COMP0_Handler          
                Set_Default_Handler  COMP1_Handler          
                Set_Default_Handler  COMP2_Handler          
                Set_Default_Handler  SYSCTL_Handler         
                Set_Default_Handler  FLASH_Handler          
                Set_Default_Handler  GPIOF_Handler          
                Set_Default_Handler  GPIOG_Handler          
                Set_Default_Handler  GPIOH_Handler          
                Set_Default_Handler  UART2_Handler          
                Set_Default_Handler  SSI1_Handler           
                Set_Default_Handler  TIM3A_Handler          
                Set_Default_Handler  TIM3B_Handler          
                Set_Default_Handler  I2C1_Handler           
                Set_Default_Handler  QEI1_Handler           
                Set_Default_Handler  CAN0_Handler           
                Set_Default_Handler  CAN1_Handler           
                Set_Default_Handler  CAN2_Handler           
                Set_Default_Handler  ETH0_Handler           
                Set_Default_Handler  HIB_Handler            
                Set_Default_Handler  USB0_Handler           
                Set_Default_Handler  PWM0_3_Handler         
                Set_Default_Handler  UDMA_Handler           
                Set_Default_Handler  UDMAError_Handler      
                Set_Default_Handler  ADC1SS0_Handler        
                Set_Default_Handler  ADC1SS1_Handler        
                Set_Default_Handler  ADC1SS2_Handler        
                Set_Default_Handler  ADC1SS3_Handler        
                Set_Default_Handler  I2S0_Handler           
                Set_Default_Handler  EPI0_Handler           
                Set_Default_Handler  GPIOJ_Handler  

                .end
