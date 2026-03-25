; ;*********************************************************************** ;*
; * @file     startup_lm3s9b92_noSct.s
; * @brief    CMSIS-Core(M) Device Startup File for
; *           Device LM3S9B92 (using Arm Compiler 5 without scatter file)
; * @version  V1.0.0
; * @date     20. January 2021
; ***************************************************************************
; ;
; * Copyright (c) ToDo: Set copyright
; 

;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------


;<h> Stack Configuration
;  <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
;</h>

Stack_Size      EQU      0x00000400

                AREA     STACK, NOINIT, READWRITE, ALIGN=3
__stack_limit
Stack_Mem       SPACE    Stack_Size
__initial_sp


;<h> Heap Configuration
;  <o> Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
;</h>

Heap_Size       EQU      0x00000C00

                IF       Heap_Size != 0                      ; Heap is provided
                AREA     HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE    Heap_Size
__heap_limit
                ENDIF


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA     RESET, DATA, READONLY
                EXPORT   __Vectors
                EXPORT   __Vectors_End
                EXPORT   __Vectors_Size

__Vectors       DCD      __initial_sp                        ;     Top of Stack
                DCD      Reset_Handler                       ;     Reset Handler
                DCD      NMI_Handler                         ; -14 NMI Handler
                DCD      HardFault_Handler                   ; -13 Hard Fault Handler
                DCD      MemManage_Handler                   ; -12 MPU Fault Handler
                DCD      BusFault_Handler                    ; -11 Bus Fault Handler
                DCD      UsageFault_Handler                  ; -10 Usage Fault Handler
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      0                                   ;     Reserved
                DCD      SVC_Handler                         ;  -5 SVCall Handler
                DCD      DebugMon_Handler                    ;  -4 Debug Monitor Handler
                DCD      0                                   ;     Reserved
                DCD      PendSV_Handler                      ;  -2 PendSV Handler
                DCD      SysTick_Handler                     ;  -1 SysTick Handler

                ; Interrupts
                DCD      GPIOA_Handler                       ;   0 GPIOA Handler
                DCD      GPIOB_Handler                       ;   1 GPIOB Handler
                DCD      GPIOC_Handler                       ;   2 GPIOC Handler
                DCD      GPIOD_Handler                       ;   3 GPIOD Handler
                DCD      GPIOE_Handler                       ;   4 GPIOE Handler
                DCD      UART0_Handler                       ;   5 UART0 Handler
                DCD      UART1_Handler                       ;   6 UART1 Handler
                DCD      SSI0_Handler                        ;   7 SSI Handler
                DCD      I2C0_Handler                        ;   8 I2C0 Handler
                DCD      PWM0Fault_Handler                   ;   9 PWM0 Fault Handler
                DCD      PWM0_0_Handler                      ;  10 PWM0 Generator 0 Handler
                DCD      PWM0_1_Handler                      ;  11 PWM0 Generator 1 Handler
                DCD      PWM0_2_Handler                      ;  12 PWM0 Generator 2 Handler
                DCD      QEI0_Handler                        ;  13 Quadrature Encoder 0 Handler
                DCD      ADC0SS0_Handler                     ;  14 ADC0 Sequence 0 Handler
                DCD      ADC0SS1_Handler                     ;  15 ADC0 Sequence 1 Handler
                DCD      ADC0SS2_Handler                     ;  16 ADC0 Sequence 2 Handler
                DCD      ADC0SS3_Handler                     ;  17 ADC0 Sequence 3 Handler
                DCD      WDT0_Handler                        ;  18 Watchdog Timer 0 Handler
                DCD      TIM0A_Handler                       ;  19 Timer 0 Subtimer A Handler
                DCD      TIM0B_Handler                       ;  20 Timer 0 Subtimer B Handler
                DCD      TIM1A_Handler                       ;  21 Timer 1 Subtimer A Handler
                DCD      TIM1B_Handler                       ;  22 Timer 1 Subtimer B Handler
                DCD      TIM2A_Handler                       ;  23 Timer 2 Subtimer A Handler
                DCD      TIM2B_Handler                       ;  24 Timer 2 Subtimer B Handler
                DCD      COMP0_Handler                       ;  25 Analog Comparator 0 Handler
                DCD      COMP1_Handler                       ;  26 Analog Comparator 1 Handler
                DCD      COMP2_Handler                       ;  27 Analog Comparator 2 Handler
                DCD      SYSCTL_Handler                      ;  28 System Cortrol Handler
                DCD      FLASH_Handler                       ;  29 FLASH Handler
                DCD      GPIOF_Handler                       ;  30 GPIOF Handler
                DCD      GPIOG_Handler                       ;  31 GPIOG Handler
                DCD      GPIOH_Handler                       ;  32 GPIOH Handler
                DCD      UART2_Handler                       ;  33 UART2 Handler
                DCD      SSI1_Handler                        ;  34 SSI1 Handler
                DCD      TIM3A_Handler                       ;  35 Timer 3 Subtimer A Handler
                DCD      TIM3B_Handler                       ;  36 Timer 3 Subtimer B Handler
                DCD      I2C1_Handler                        ;  37 I2C1 Handler
                DCD      QEI1_Handler                        ;  38 Quadrature Encoder 1 Handler
                DCD      CAN0_Handler                        ;  39 CAN0 Handler
                DCD      CAN1_Handler                        ;  40 CAN1 Handler
                DCD      CAN2_Handler                        ;  41 CAN2 Handler
                DCD      ETH0_Handler                        ;  42 Ethernet 0 Handler
                DCD      HIB_Handler                         ;  43 Hibernation module Handler
                DCD      USB0_Handler                        ;  44 USB0 Handler
                DCD      PWM0_3_Handler                      ;  45 PWM0 Generator 3 Handler
                DCD      UDMA_Handler                        ;  46 uDMA Handler
                DCD      UDMAError_Handler                   ;  47 uDMA Error Handler
                DCD      ADC1SS0_Handler                     ;  48 ADC1 Sequence 0 Handler
                DCD      ADC1SS1_Handler                     ;  49 ADC1 Sequence 1 Handler
                DCD      ADC1SS2_Handler                     ;  50 ADC1 Sequence 2 Handler
                DCD      ADC1SS3_Handler                     ;  51 ADC1 Sequence 3 Handler
                DCD      I2S0_Handler                        ;  52 I2S0 Handler
                DCD      EPI0_Handler                        ;  53 External Peripheral Interface Handler
                DCD      GPIOJ_Handler                       ;  54 GPIOJ Handler

                SPACE    (70 * 4)                           ; Interrupts 71 .. 224 are left out
__Vectors_End
__Vectors_Size  EQU      __Vectors_End - __Vectors


                AREA     |.text|, CODE, READONLY

; Reset Handler

Reset_Handler   PROC
                EXPORT   Reset_Handler             [WEAK]
                IMPORT   SystemInit
                IMPORT   __main

                LDR      R0, =SystemInit
                BLX      R0
                LDR      R0, =__main
                BX       R0
                ENDP


; The default macro is not used for HardFault_Handler
; because this results in a poor debug illusion.
HardFault_Handler PROC
                EXPORT   HardFault_Handler         [WEAK]
                B        .
                ENDP

; Macro to define default exception/interrupt handlers.
; Default handler are weak symbols with an endless loop.
; They can be overwritten by real handlers.
                MACRO
                Set_Default_Handler  $Handler_Name
$Handler_Name   PROC
                EXPORT   $Handler_Name             [WEAK]
                B        .
                ENDP
                MEND


; Default exception/interrupt handler
                Set_Default_Handler  NMI_Handler
;               Set_Default_Handler  HardFault_Handler
                Set_Default_Handler  MemManage_Handler
                Set_Default_Handler  BusFault_Handler
                Set_Default_Handler  UsageFault_Handler
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

                ALIGN


; User setup Stack & Heap

                IF       :LNOT::DEF:__MICROLIB
                IMPORT   __use_two_region_memory
                ENDIF

                EXPORT   __stack_limit
                EXPORT   __initial_sp
                IF       Heap_Size != 0                      ; Heap is provided
                EXPORT   __heap_base
                EXPORT   __heap_limit
                ENDIF

                END
