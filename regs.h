/*
********************************************************************************
*                                                                              *
* Copyright (c) 2017 Andrea Loi                                                *
*                                                                              *
* Permission is hereby granted, free of charge, to any person obtaining a      *
* copy of this software and associated documentation files (the "Software"),   *
* to deal in the Software without restriction, including without limitation    *
* the rights to use, copy, modify, merge, publish, distribute, sublicense,     *
* and/or sell copies of the Software, and to permit persons to whom the        *
* Software is furnished to do so, subject to the following conditions:         *
*                                                                              *
* The above copyright notice and this permission notice shall be included      *
* in all copies or substantial portions of the Software.                       *
*                                                                              *
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR   *
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,     *
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL      *
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER   *
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      *
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER          *
* DEALINGS IN THE SOFTWARE.                                                    *
*                                                                              *
********************************************************************************
* This file defines all the registers.                                         *
********************************************************************************
*/

#ifndef REGS_H
#define REGS_H

#include "common.h"



// *****************************************************************************
// *          DON'T EDIT THIS FILE UNLESS YOU KNOW WHAT YOU'RE DOING!          *
// *****************************************************************************



// *****************************************************************************
// *                          < Register structures >                          *
// *****************************************************************************

typedef struct {
  volatile uint16_t F_SIZE;
  volatile uint16_t RESERVED_1[3];
  volatile uint16_t U_ID_15_0;
  volatile uint16_t U_ID_31_16;
  volatile uint16_t U_ID_63_48;
  volatile uint16_t U_ID_47_32;
  volatile uint16_t U_ID_95_80;
  volatile uint16_t U_ID_79_64;
} SIG_Type;

typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RESERVED_1;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t RESERVED_2;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
} TIM2_Type;

typedef struct {
  volatile uint32_t CRH;
  volatile uint32_t CRL;
  volatile uint32_t PRLH;
  volatile uint32_t PRLL;
  volatile uint32_t DIVH;
  volatile uint32_t DIVL;
  volatile uint32_t CNTH;
  volatile uint32_t CNTL;
  volatile uint32_t ALRH;
  volatile uint32_t ALRL;
} RTC_Type;

typedef struct {
  volatile uint32_t CR;
  volatile uint32_t CFR;
  volatile uint32_t SR;
} WWDG_Type;

typedef struct {
  volatile uint32_t KR;
  volatile uint32_t PR;
  volatile uint32_t RLR;
  volatile uint32_t SR;
} IWDG_Type;

typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t CRCPR;
  volatile uint32_t RXCRCR;
  volatile uint32_t TXCRCR;
  volatile uint32_t I2SCFGR;
  volatile uint32_t I2SPR;
} SPI1_Type;

typedef struct {
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t BRR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t CR3;
  volatile uint32_t GTPR;
} USART1_Type;

typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t DR;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t CCR;
  volatile uint32_t TRISE;
} I2C1_Type;

typedef struct {
  volatile uint32_t EP0R;
  volatile uint32_t EP1R;
  volatile uint32_t EP2R;
  volatile uint32_t EP3R;
  volatile uint32_t EP4R;
  volatile uint32_t EP5R;
  volatile uint32_t EP6R;
  volatile uint32_t EP7R;
  volatile uint32_t RESERVED_1[8];
  volatile uint32_t CNTR;
  volatile uint32_t ISTR;
  volatile uint32_t FNR;
  volatile uint32_t DADDR;
  volatile uint32_t BTABLE;
} USB_Type;

typedef struct {
  volatile uint32_t CAN_MCR;
  volatile uint32_t CAN_MSR;
  volatile uint32_t CAN_TSR;
  volatile uint32_t CAN_RF0R;
  volatile uint32_t CAN_RF1R;
  volatile uint32_t CAN_IER;
  volatile uint32_t CAN_ESR;
  volatile uint32_t CAN_BTR;
  volatile uint32_t RESERVED_1[88];
  volatile uint32_t CAN_TI0R;
  volatile uint32_t CAN_TDT0R;
  volatile uint32_t CAN_TDL0R;
  volatile uint32_t CAN_TDH0R;
  volatile uint32_t CAN_TI1R;
  volatile uint32_t CAN_TDT1R;
  volatile uint32_t CAN_TDL1R;
  volatile uint32_t CAN_TDH1R;
  volatile uint32_t CAN_TI2R;
  volatile uint32_t CAN_TDT2R;
  volatile uint32_t CAN_TDL2R;
  volatile uint32_t CAN_TDH2R;
  volatile uint32_t CAN_RI0R;
  volatile uint32_t CAN_RDT0R;
  volatile uint32_t CAN_RDL0R;
  volatile uint32_t CAN_RDH0R;
  volatile uint32_t CAN_RI1R;
  volatile uint32_t CAN_RDT1R;
  volatile uint32_t CAN_RDL1R;
  volatile uint32_t CAN_RDH1R;
  volatile uint32_t RESERVED_2[12];
  volatile uint32_t CAN_FMR;
  volatile uint32_t CAN_FM1R;
  volatile uint32_t RESERVED_3;
  volatile uint32_t CAN_FS1R;
  volatile uint32_t RESERVED_4;
  volatile uint32_t CAN_FFA1R;
  volatile uint32_t RESERVED_5;
  volatile uint32_t CAN_FA1R;
  volatile uint32_t RESERVED_6[8];
  volatile uint32_t F0R1;
  volatile uint32_t F0R2;
  volatile uint32_t F1R1;
  volatile uint32_t F1R2;
  volatile uint32_t F2R1;
  volatile uint32_t F2R2;
  volatile uint32_t F3R1;
  volatile uint32_t F3R2;
  volatile uint32_t F4R1;
  volatile uint32_t F4R2;
  volatile uint32_t F5R1;
  volatile uint32_t F5R2;
  volatile uint32_t F6R1;
  volatile uint32_t F6R2;
  volatile uint32_t F7R1;
  volatile uint32_t F7R2;
  volatile uint32_t F8R1;
  volatile uint32_t F8R2;
  volatile uint32_t F9R1;
  volatile uint32_t F9R2;
  volatile uint32_t F10R1;
  volatile uint32_t F10R2;
  volatile uint32_t F11R1;
  volatile uint32_t F11R2;
  volatile uint32_t F12R1;
  volatile uint32_t F12R2;
  volatile uint32_t F13R1;
  volatile uint32_t F13R2;
} CAN1_Type;

typedef struct {
  volatile uint32_t DR1;
  volatile uint32_t DR2;
  volatile uint32_t DR3;
  volatile uint32_t DR4;
  volatile uint32_t DR5;
  volatile uint32_t DR6;
  volatile uint32_t DR7;
  volatile uint32_t DR8;
  volatile uint32_t DR9;
  volatile uint32_t DR10;
  volatile uint32_t RTCCR;
  volatile uint32_t CR;
  volatile uint32_t CSR;
  volatile uint32_t RESERVED_1[2];
  volatile uint32_t DR11;
  volatile uint32_t DR12;
  volatile uint32_t DR13;
  volatile uint32_t DR14;
  volatile uint32_t DR15;
  volatile uint32_t DR16;
  volatile uint32_t DR17;
  volatile uint32_t DR18;
  volatile uint32_t DR19;
  volatile uint32_t DR20;
  volatile uint32_t DR21;
  volatile uint32_t DR22;
  volatile uint32_t DR23;
  volatile uint32_t DR24;
  volatile uint32_t DR25;
  volatile uint32_t DR26;
  volatile uint32_t DR27;
  volatile uint32_t DR28;
  volatile uint32_t DR29;
  volatile uint32_t DR30;
  volatile uint32_t DR31;
  volatile uint32_t DR32;
  volatile uint32_t DR33;
  volatile uint32_t DR34;
  volatile uint32_t DR35;
  volatile uint32_t DR36;
  volatile uint32_t DR37;
  volatile uint32_t DR38;
  volatile uint32_t DR39;
  volatile uint32_t DR40;
  volatile uint32_t DR41;
  volatile uint32_t DR42;
} BKP_Type;

typedef struct {
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_Type;

typedef struct {
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR1;
  volatile uint32_t EXTICR2;
  volatile uint32_t EXTICR3;
  volatile uint32_t EXTICR4;
  volatile uint32_t RESERVED_1;
  volatile uint32_t MAPR2;
} AFIO_Type;

typedef struct {
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_Type;

typedef struct {
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIOA_Type;

typedef struct {
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC1_Type;

typedef struct {
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC2_Type;

typedef struct {
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t BDTR;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
} TIM1_Type;

typedef struct {
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
  volatile uint32_t CCR1;
  volatile uint32_t CNDTR1;
  volatile uint32_t CPAR1;
  volatile uint32_t CMAR1;
  volatile uint32_t RESERVED_1;
  volatile uint32_t CCR2;
  volatile uint32_t CNDTR2;
  volatile uint32_t CPAR2;
  volatile uint32_t CMAR2;
  volatile uint32_t RESERVED_2;
  volatile uint32_t CCR3;
  volatile uint32_t CNDTR3;
  volatile uint32_t CPAR3;
  volatile uint32_t CMAR3;
  volatile uint32_t RESERVED_3;
  volatile uint32_t CCR4;
  volatile uint32_t CNDTR4;
  volatile uint32_t CPAR4;
  volatile uint32_t CMAR4;
  volatile uint32_t RESERVED_4;
  volatile uint32_t CCR5;
  volatile uint32_t CNDTR5;
  volatile uint32_t CPAR5;
  volatile uint32_t CMAR5;
  volatile uint32_t RESERVED_5;
  volatile uint32_t CCR6;
  volatile uint32_t CNDTR6;
  volatile uint32_t CPAR6;
  volatile uint32_t CMAR6;
  volatile uint32_t RESERVED_6;
  volatile uint32_t CCR7;
  volatile uint32_t CNDTR7;
  volatile uint32_t CPAR7;
  volatile uint32_t CMAR7;
} DMA1_Type;

typedef struct {
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
} RCC_Type;

typedef struct {
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED_1;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
} FLASH_Type;

typedef struct {
  volatile uint32_t DR;
  volatile uint32_t IDR;
  volatile uint32_t CR;
} CRC_Type;

typedef struct {
  volatile uint32_t RESERVED_1;
  volatile uint32_t ICTR;
  volatile uint32_t RESERVED_2[62];
  volatile uint32_t ISER0;
  volatile uint32_t ISER1;
  volatile uint32_t RESERVED_3[30];
  volatile uint32_t ICER0;
  volatile uint32_t ICER1;
  volatile uint32_t RESERVED_4[30];
  volatile uint32_t ISPR0;
  volatile uint32_t ISPR1;
  volatile uint32_t RESERVED_5[30];
  volatile uint32_t ICPR0;
  volatile uint32_t ICPR1;
  volatile uint32_t RESERVED_6[30];
  volatile uint32_t IABR0;
  volatile uint32_t IABR1;
  volatile uint32_t RESERVED_7[62];
  volatile uint32_t IPR0;
  volatile uint32_t IPR1;
  volatile uint32_t IPR2;
  volatile uint32_t IPR3;
  volatile uint32_t IPR4;
  volatile uint32_t IPR5;
  volatile uint32_t IPR6;
  volatile uint32_t IPR7;
  volatile uint32_t IPR8;
  volatile uint32_t IPR9;
  volatile uint32_t IPR10;
  volatile uint32_t IPR11;
  volatile uint32_t IPR12;
  volatile uint32_t IPR13;
  volatile uint32_t IPR14;
  volatile uint32_t RESERVED_8[689];
  volatile uint32_t STIR;
} NVIC_Type;

typedef struct {
  volatile uint32_t CTRL;
  volatile uint32_t LOAD;
  volatile uint32_t VAL;
  volatile uint32_t CALIB;
} STK_Type;

typedef struct {
  volatile uint32_t CPUID;
  volatile uint32_t ICSR;
  volatile uint32_t VTOR;
  volatile uint32_t AIRCR;
  volatile uint32_t SCR;
  volatile uint32_t CCR;
  volatile uint32_t SHPR1;
  volatile uint32_t SHPR2;
  volatile uint32_t SHPR3;
  volatile uint32_t SHCRS;
  volatile uint32_t CFSR;
  volatile uint32_t HFSR;
  volatile uint32_t RESERVED_1;
  volatile uint32_t MMAR;
  volatile uint32_t BFAR;
} SCB_Type;

typedef struct {
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
} DBG_Type;



// *****************************************************************************
// *                        < Register base addresses >                        *
// *****************************************************************************

#define SIG_BASE           ((uint32_t) 0x1FFFF7E0)
#define TIM2_BASE          ((uint32_t) 0x40000000)
#define TIM3_BASE          ((uint32_t) 0x40000400)
#define TIM4_BASE          ((uint32_t) 0x40000800)
#define RTC_BASE           ((uint32_t) 0x40002800)
#define WWDG_BASE          ((uint32_t) 0x40002C00)
#define IWDG_BASE          ((uint32_t) 0x40003000)
#define SPI2_BASE          ((uint32_t) 0x40003800)
#define USART2_BASE        ((uint32_t) 0x40004400)
#define USART3_BASE        ((uint32_t) 0x40004800)
#define I2C1_BASE          ((uint32_t) 0x40005400)
#define I2C2_BASE          ((uint32_t) 0x40005800)
#define USB_BASE           ((uint32_t) 0x40005C00)
#define CAN1_BASE          ((uint32_t) 0x40006400)
#define BKP_BASE           ((uint32_t) 0x40006C00)
#define PWR_BASE           ((uint32_t) 0x40007000)
#define AFIO_BASE          ((uint32_t) 0x40010000)
#define EXTI_BASE          ((uint32_t) 0x40010400)
#define GPIOA_BASE         ((uint32_t) 0x40010800)
#define GPIOB_BASE         ((uint32_t) 0x40010C00)
#define GPIOC_BASE         ((uint32_t) 0x40011000)
#define GPIOD_BASE         ((uint32_t) 0x40011400)
#define ADC1_BASE          ((uint32_t) 0x40012400)
#define ADC2_BASE          ((uint32_t) 0x40012800)
#define TIM1_BASE          ((uint32_t) 0x40012C00)
#define SPI1_BASE          ((uint32_t) 0x40013000)
#define USART1_BASE        ((uint32_t) 0x40013800)
#define DMA1_BASE          ((uint32_t) 0x40020000)
#define RCC_BASE           ((uint32_t) 0x40021000)
#define FLASH_BASE         ((uint32_t) 0x40022000)
#define CRC_BASE           ((uint32_t) 0x40023000)
#define NVIC_BASE          ((uint32_t) 0xE000E000)
#define STK_BASE           ((uint32_t) 0xE000E010)
#define SCB_BASE           ((uint32_t) 0xE000ED00)
#define DBG_BASE           ((uint32_t) 0xE0042000)



// *****************************************************************************
// *                     < Register locations assignment >                     *
// *****************************************************************************

#define SIG           ( (SIG_Type*)       SIG_BASE    )
#define TIM2          ( (TIM2_Type*)      TIM2_BASE   )
#define TIM3          ( (TIM2_Type*)      TIM3_BASE   )
#define TIM4          ( (TIM2_Type*)      TIM4_BASE   )
#define RTC           ( (RTC_Type*)       RTC_BASE    )
#define WWDG          ( (WWDG_Type*)      WWDG_BASE   )
#define IWDG          ( (IWDG_Type*)      IWDG_BASE   )
#define SPI2          ( (SPI1_Type*)      SPI2_BASE   )
#define USART2        ( (USART1_Type*)    USART2_BASE )
#define USART3        ( (USART1_Type*)    USART3_BASE )
#define I2C1          ( (I2C1_Type*)      I2C1_BASE   )
#define I2C2          ( (I2C1_Type*)      I2C2_BASE   )
#define USB           ( (USB_Type*)       USB_BASE    )
#define CAN1          ( (CAN1_Type*)      CAN1_BASE   )
#define BKP           ( (BKP_Type*)       BKP_BASE    )
#define PWR           ( (PWR_Type*)       PWR_BASE    )
#define AFIO          ( (AFIO_Type*)      AFIO_BASE   )
#define EXTI          ( (EXTI_Type*)      EXTI_BASE   )
#define GPIOA         ( (GPIOA_Type*)     GPIOA_BASE  )
#define GPIOB         ( (GPIOA_Type*)     GPIOB_BASE  )
#define GPIOC         ( (GPIOA_Type*)     GPIOC_BASE  )
#define GPIOD         ( (GPIOA_Type*)     GPIOD_BASE  )
#define ADC1          ( (ADC1_Type*)      ADC1_BASE   )
#define ADC2          ( (ADC2_Type*)      ADC2_BASE   )
#define TIM1          ( (TIM1_Type*)      TIM1_BASE   )
#define SPI1          ( (SPI1_Type*)      SPI1_BASE   )
#define USART1        ( (USART1_Type*)    USART1_BASE )
#define DMA1          ( (DMA1_Type*)      DMA1_BASE   )
#define RCC           ( (RCC_Type*)       RCC_BASE    )
#define FLASH         ( (FLASH_Type*)     FLASH_BASE  )
#define CRC           ( (CRC_Type*)       CRC_BASE    )
#define NVIC          ( (NVIC_Type*)      NVIC_BASE   )
#define STK           ( (STK_Type*)       STK_BASE    )
#define SCB           ( (SCB_Type*)       SCB_BASE    )
#define DBG           ( (DBG_Type*)       DBG_BASE    )



// *****************************************************************************
// *                    < Bit-banding register structures >                    *
// *****************************************************************************

typedef struct {
  volatile uint32_t CR1[32];
  volatile uint32_t CR2[32];
  volatile uint32_t SMCR[32];
  volatile uint32_t DIER[32];
  volatile uint32_t SR[32];
  volatile uint32_t EGR[32];
  volatile uint32_t CCMR1[32];
  volatile uint32_t CCMR2[32];
  volatile uint32_t CCER[32];
  volatile uint32_t CNT[32];
  volatile uint32_t PSC[32];
  volatile uint32_t ARR[32];
  volatile uint32_t RESERVED_1[32];
  volatile uint32_t CCR1[32];
  volatile uint32_t CCR2[32];
  volatile uint32_t CCR3[32];
  volatile uint32_t CCR4[32];
  volatile uint32_t RESERVED_2[32];
  volatile uint32_t DCR[32];
  volatile uint32_t DMAR[32];
} TIM2_BB_Type;

typedef struct {
  volatile uint32_t CRH[32];
  volatile uint32_t CRL[32];
  volatile uint32_t PRLH[32];
  volatile uint32_t PRLL[32];
  volatile uint32_t DIVH[32];
  volatile uint32_t DIVL[32];
  volatile uint32_t CNTH[32];
  volatile uint32_t CNTL[32];
  volatile uint32_t ALRH[32];
  volatile uint32_t ALRL[32];
} RTC_BB_Type;

typedef struct {
  volatile uint32_t CR[32];
  volatile uint32_t CFR[32];
  volatile uint32_t SR[32];
} WWDG_BB_Type;

typedef struct {
  volatile uint32_t KR[32];
  volatile uint32_t PR[32];
  volatile uint32_t RLR[32];
  volatile uint32_t SR[32];
} IWDG_BB_Type;

typedef struct {
  volatile uint32_t CR1[32];
  volatile uint32_t CR2[32];
  volatile uint32_t SR[32];
  volatile uint32_t DR[32];
  volatile uint32_t CRCPR[32];
  volatile uint32_t RXCRCR[32];
  volatile uint32_t TXCRCR[32];
  volatile uint32_t I2SCFGR[32];
  volatile uint32_t I2SPR[32];
} SPI1_BB_Type;

typedef struct {
  volatile uint32_t SR[32];
  volatile uint32_t DR[32];
  volatile uint32_t BRR[32];
  volatile uint32_t CR1[32];
  volatile uint32_t CR2[32];
  volatile uint32_t CR3[32];
  volatile uint32_t GTPR[32];
} USART1_BB_Type;

typedef struct {
  volatile uint32_t CR1[32];
  volatile uint32_t CR2[32];
  volatile uint32_t OAR1[32];
  volatile uint32_t OAR2[32];
  volatile uint32_t DR[32];
  volatile uint32_t SR1[32];
  volatile uint32_t SR2[32];
  volatile uint32_t CCR[32];
  volatile uint32_t TRISE[32];
} I2C1_BB_Type;

typedef struct {
  volatile uint32_t EP0R[32];
  volatile uint32_t EP1R[32];
  volatile uint32_t EP2R[32];
  volatile uint32_t EP3R[32];
  volatile uint32_t EP4R[32];
  volatile uint32_t EP5R[32];
  volatile uint32_t EP6R[32];
  volatile uint32_t EP7R[32];
  volatile uint32_t RESERVED_1[8][32];
  volatile uint32_t CNTR[32];
  volatile uint32_t ISTR[32];
  volatile uint32_t FNR[32];
  volatile uint32_t DADDR[32];
  volatile uint32_t BTABLE[32];
} USB_BB_Type;

typedef struct {
  volatile uint32_t CAN_MCR[32];
  volatile uint32_t CAN_MSR[32];
  volatile uint32_t CAN_TSR[32];
  volatile uint32_t CAN_RF0R[32];
  volatile uint32_t CAN_RF1R[32];
  volatile uint32_t CAN_IER[32];
  volatile uint32_t CAN_ESR[32];
  volatile uint32_t CAN_BTR[32];
  volatile uint32_t RESERVED_1[88][32];
  volatile uint32_t CAN_TI0R[32];
  volatile uint32_t CAN_TDT0R[32];
  volatile uint32_t CAN_TDL0R[32];
  volatile uint32_t CAN_TDH0R[32];
  volatile uint32_t CAN_TI1R[32];
  volatile uint32_t CAN_TDT1R[32];
  volatile uint32_t CAN_TDL1R[32];
  volatile uint32_t CAN_TDH1R[32];
  volatile uint32_t CAN_TI2R[32];
  volatile uint32_t CAN_TDT2R[32];
  volatile uint32_t CAN_TDL2R[32];
  volatile uint32_t CAN_TDH2R[32];
  volatile uint32_t CAN_RI0R[32];
  volatile uint32_t CAN_RDT0R[32];
  volatile uint32_t CAN_RDL0R[32];
  volatile uint32_t CAN_RDH0R[32];
  volatile uint32_t CAN_RI1R[32];
  volatile uint32_t CAN_RDT1R[32];
  volatile uint32_t CAN_RDL1R[32];
  volatile uint32_t CAN_RDH1R[32];
  volatile uint32_t RESERVED_2[12][32];
  volatile uint32_t CAN_FMR[32];
  volatile uint32_t CAN_FM1R[32];
  volatile uint32_t RESERVED_3[32];
  volatile uint32_t CAN_FS1R[32];
  volatile uint32_t RESERVED_4[32];
  volatile uint32_t CAN_FFA1R[32];
  volatile uint32_t RESERVED_5[32];
  volatile uint32_t CAN_FA1R[32];
  volatile uint32_t RESERVED_6[8][32];
  volatile uint32_t F0R1[32];
  volatile uint32_t F0R2[32];
  volatile uint32_t F1R1[32];
  volatile uint32_t F1R2[32];
  volatile uint32_t F2R1[32];
  volatile uint32_t F2R2[32];
  volatile uint32_t F3R1[32];
  volatile uint32_t F3R2[32];
  volatile uint32_t F4R1[32];
  volatile uint32_t F4R2[32];
  volatile uint32_t F5R1[32];
  volatile uint32_t F5R2[32];
  volatile uint32_t F6R1[32];
  volatile uint32_t F6R2[32];
  volatile uint32_t F7R1[32];
  volatile uint32_t F7R2[32];
  volatile uint32_t F8R1[32];
  volatile uint32_t F8R2[32];
  volatile uint32_t F9R1[32];
  volatile uint32_t F9R2[32];
  volatile uint32_t F10R1[32];
  volatile uint32_t F10R2[32];
  volatile uint32_t F11R1[32];
  volatile uint32_t F11R2[32];
  volatile uint32_t F12R1[32];
  volatile uint32_t F12R2[32];
  volatile uint32_t F13R1[32];
  volatile uint32_t F13R2[32];
} CAN1_BB_Type;

typedef struct {
  volatile uint32_t DR1[32];
  volatile uint32_t DR2[32];
  volatile uint32_t DR3[32];
  volatile uint32_t DR4[32];
  volatile uint32_t DR5[32];
  volatile uint32_t DR6[32];
  volatile uint32_t DR7[32];
  volatile uint32_t DR8[32];
  volatile uint32_t DR9[32];
  volatile uint32_t DR10[32];
  volatile uint32_t RTCCR[32];
  volatile uint32_t CR[32];
  volatile uint32_t CSR[32];
  volatile uint32_t RESERVED_1[2][32];
  volatile uint32_t DR11[32];
  volatile uint32_t DR12[32];
  volatile uint32_t DR13[32];
  volatile uint32_t DR14[32];
  volatile uint32_t DR15[32];
  volatile uint32_t DR16[32];
  volatile uint32_t DR17[32];
  volatile uint32_t DR18[32];
  volatile uint32_t DR19[32];
  volatile uint32_t DR20[32];
  volatile uint32_t DR21[32];
  volatile uint32_t DR22[32];
  volatile uint32_t DR23[32];
  volatile uint32_t DR24[32];
  volatile uint32_t DR25[32];
  volatile uint32_t DR26[32];
  volatile uint32_t DR27[32];
  volatile uint32_t DR28[32];
  volatile uint32_t DR29[32];
  volatile uint32_t DR30[32];
  volatile uint32_t DR31[32];
  volatile uint32_t DR32[32];
  volatile uint32_t DR33[32];
  volatile uint32_t DR34[32];
  volatile uint32_t DR35[32];
  volatile uint32_t DR36[32];
  volatile uint32_t DR37[32];
  volatile uint32_t DR38[32];
  volatile uint32_t DR39[32];
  volatile uint32_t DR40[32];
  volatile uint32_t DR41[32];
  volatile uint32_t DR42[32];
} BKP_BB_Type;

typedef struct {
  volatile uint32_t CR[32];
  volatile uint32_t CSR[32];
} PWR_BB_Type;

typedef struct {
  volatile uint32_t EVCR[32];
  volatile uint32_t MAPR[32];
  volatile uint32_t EXTICR1[32];
  volatile uint32_t EXTICR2[32];
  volatile uint32_t EXTICR3[32];
  volatile uint32_t EXTICR4[32];
  volatile uint32_t RESERVED_1[32];
  volatile uint32_t MAPR2[32];
} AFIO_BB_Type;

typedef struct {
  volatile uint32_t IMR[32];
  volatile uint32_t EMR[32];
  volatile uint32_t RTSR[32];
  volatile uint32_t FTSR[32];
  volatile uint32_t SWIER[32];
  volatile uint32_t PR[32];
} EXTI_BB_Type;

typedef struct {
  volatile uint32_t CRL[32];
  volatile uint32_t CRH[32];
  volatile uint32_t IDR[32];
  volatile uint32_t ODR[32];
  volatile uint32_t BSRR[32];
  volatile uint32_t BRR[32];
  volatile uint32_t LCKR[32];
} GPIOA_BB_Type;

typedef struct {
  volatile uint32_t SR[32];
  volatile uint32_t CR1[32];
  volatile uint32_t CR2[32];
  volatile uint32_t SMPR1[32];
  volatile uint32_t SMPR2[32];
  volatile uint32_t JOFR1[32];
  volatile uint32_t JOFR2[32];
  volatile uint32_t JOFR3[32];
  volatile uint32_t JOFR4[32];
  volatile uint32_t HTR[32];
  volatile uint32_t LTR[32];
  volatile uint32_t SQR1[32];
  volatile uint32_t SQR2[32];
  volatile uint32_t SQR3[32];
  volatile uint32_t JSQR[32];
  volatile uint32_t JDR1[32];
  volatile uint32_t JDR2[32];
  volatile uint32_t JDR3[32];
  volatile uint32_t JDR4[32];
  volatile uint32_t DR[32];
} ADC1_BB_Type;

typedef struct {
  volatile uint32_t SR[32];
  volatile uint32_t CR1[32];
  volatile uint32_t CR2[32];
  volatile uint32_t SMPR1[32];
  volatile uint32_t SMPR2[32];
  volatile uint32_t JOFR1[32];
  volatile uint32_t JOFR2[32];
  volatile uint32_t JOFR3[32];
  volatile uint32_t JOFR4[32];
  volatile uint32_t HTR[32];
  volatile uint32_t LTR[32];
  volatile uint32_t SQR1[32];
  volatile uint32_t SQR2[32];
  volatile uint32_t SQR3[32];
  volatile uint32_t JSQR[32];
  volatile uint32_t JDR1[32];
  volatile uint32_t JDR2[32];
  volatile uint32_t JDR3[32];
  volatile uint32_t JDR4[32];
  volatile uint32_t DR[32];
} ADC2_BB_Type;

typedef struct {
  volatile uint32_t CR1[32];
  volatile uint32_t CR2[32];
  volatile uint32_t SMCR[32];
  volatile uint32_t DIER[32];
  volatile uint32_t SR[32];
  volatile uint32_t EGR[32];
  volatile uint32_t CCMR1[32];
  volatile uint32_t CCMR2[32];
  volatile uint32_t CCER[32];
  volatile uint32_t CNT[32];
  volatile uint32_t PSC[32];
  volatile uint32_t ARR[32];
  volatile uint32_t RCR[32];
  volatile uint32_t CCR1[32];
  volatile uint32_t CCR2[32];
  volatile uint32_t CCR3[32];
  volatile uint32_t CCR4[32];
  volatile uint32_t BDTR[32];
  volatile uint32_t DCR[32];
  volatile uint32_t DMAR[32];
} TIM1_BB_Type;

typedef struct {
  volatile uint32_t ISR[32];
  volatile uint32_t IFCR[32];
  volatile uint32_t CCR1[32];
  volatile uint32_t CNDTR1[32];
  volatile uint32_t CPAR1[32];
  volatile uint32_t CMAR1[32];
  volatile uint32_t RESERVED_1[32];
  volatile uint32_t CCR2[32];
  volatile uint32_t CNDTR2[32];
  volatile uint32_t CPAR2[32];
  volatile uint32_t CMAR2[32];
  volatile uint32_t RESERVED_2[32];
  volatile uint32_t CCR3[32];
  volatile uint32_t CNDTR3[32];
  volatile uint32_t CPAR3[32];
  volatile uint32_t CMAR3[32];
  volatile uint32_t RESERVED_3[32];
  volatile uint32_t CCR4[32];
  volatile uint32_t CNDTR4[32];
  volatile uint32_t CPAR4[32];
  volatile uint32_t CMAR4[32];
  volatile uint32_t RESERVED_4[32];
  volatile uint32_t CCR5[32];
  volatile uint32_t CNDTR5[32];
  volatile uint32_t CPAR5[32];
  volatile uint32_t CMAR5[32];
  volatile uint32_t RESERVED_5[32];
  volatile uint32_t CCR6[32];
  volatile uint32_t CNDTR6[32];
  volatile uint32_t CPAR6[32];
  volatile uint32_t CMAR6[32];
  volatile uint32_t RESERVED_6[32];
  volatile uint32_t CCR7[32];
  volatile uint32_t CNDTR7[32];
  volatile uint32_t CPAR7[32];
  volatile uint32_t CMAR7[32];
} DMA1_BB_Type;

typedef struct {
  volatile uint32_t CR[32];
  volatile uint32_t CFGR[32];
  volatile uint32_t CIR[32];
  volatile uint32_t APB2RSTR[32];
  volatile uint32_t APB1RSTR[32];
  volatile uint32_t AHBENR[32];
  volatile uint32_t APB2ENR[32];
  volatile uint32_t APB1ENR[32];
  volatile uint32_t BDCR[32];
  volatile uint32_t CSR[32];
} RCC_BB_Type;

typedef struct {
  volatile uint32_t ACR[32];
  volatile uint32_t KEYR[32];
  volatile uint32_t OPTKEYR[32];
  volatile uint32_t SR[32];
  volatile uint32_t CR[32];
  volatile uint32_t AR[32];
  volatile uint32_t RESERVED_1[32];
  volatile uint32_t OBR[32];
  volatile uint32_t WRPR[32];
} FLASH_BB_Type;

typedef struct {
  volatile uint32_t DR[32];
  volatile uint32_t IDR[32];
  volatile uint32_t CR[32];
} CRC_BB_Type;



// *****************************************************************************
// *                      < Bit-banding base addresses >                       *
// *****************************************************************************

#define TIM2_BB_BASE          ((uint32_t) 0x42000000)
#define TIM3_BB_BASE          ((uint32_t) 0x42008000)
#define TIM4_BB_BASE          ((uint32_t) 0x42010000)
#define RTC_BB_BASE           ((uint32_t) 0x42050000)
#define WWDG_BB_BASE          ((uint32_t) 0x42058000)
#define IWDG_BB_BASE          ((uint32_t) 0x42060000)
#define SPI2_BB_BASE          ((uint32_t) 0x42070000)
#define USART2_BB_BASE        ((uint32_t) 0x42088000)
#define USART3_BB_BASE        ((uint32_t) 0x42090000)
#define I2C1_BB_BASE          ((uint32_t) 0x420A8000)
#define I2C2_BB_BASE          ((uint32_t) 0x420B0000)
#define USB_BB_BASE           ((uint32_t) 0x420B8000)
#define CAN1_BB_BASE          ((uint32_t) 0x420C8000)
#define BKP_BB_BASE           ((uint32_t) 0x420D8000)
#define PWR_BB_BASE           ((uint32_t) 0x420E0000)
#define AFIO_BB_BASE          ((uint32_t) 0x42200000)
#define EXTI_BB_BASE          ((uint32_t) 0x42208000)
#define GPIOA_BB_BASE         ((uint32_t) 0x42210000)
#define GPIOB_BB_BASE         ((uint32_t) 0x42218000)
#define GPIOC_BB_BASE         ((uint32_t) 0x42220000)
#define GPIOD_BB_BASE         ((uint32_t) 0x42228000)
#define ADC1_BB_BASE          ((uint32_t) 0x42248000)
#define ADC2_BB_BASE          ((uint32_t) 0x42250000)
#define TIM1_BB_BASE          ((uint32_t) 0x42258000)
#define SPI1_BB_BASE          ((uint32_t) 0x42260000)
#define USART1_BB_BASE        ((uint32_t) 0x42270000)
#define DMA1_BB_BASE          ((uint32_t) 0x42400000)
#define RCC_BB_BASE           ((uint32_t) 0x42420000)
#define FLASH_BB_BASE         ((uint32_t) 0x42440000)
#define CRC_BB_BASE           ((uint32_t) 0x42460000)



// *****************************************************************************
// *                   < Bit-banding locations assignment >                    *
// *****************************************************************************

#define BB_TIM2          ( (TIM2_BB_Type*)      TIM2_BB_BASE   )
#define BB_TIM3          ( (TIM2_BB_Type*)      TIM3_BB_BASE   )
#define BB_TIM4          ( (TIM2_BB_Type*)      TIM4_BB_BASE   )
#define BB_RTC           ( (RTC_BB_Type*)       RTC_BB_BASE    )
#define BB_WWDG          ( (WWDG_BB_Type*)      WWDG_BB_BASE   )
#define BB_IWDG          ( (IWDG_BB_Type*)      IWDG_BB_BASE   )
#define BB_SPI2          ( (SPI1_BB_Type*)      SPI2_BB_BASE   )
#define BB_USART2        ( (USART1_BB_Type*)    USART2_BB_BASE )
#define BB_USART3        ( (USART1_BB_Type*)    USART3_BB_BASE )
#define BB_I2C1          ( (I2C1_BB_Type*)      I2C1_BB_BASE   )
#define BB_I2C2          ( (I2C1_BB_Type*)      I2C2_BB_BASE   )
#define BB_USB           ( (USB_BB_Type*)       USB_BB_BASE    )
#define BB_CAN1          ( (CAN1_BB_Type*)      CAN1_BB_BASE   )
#define BB_BKP           ( (BKP_BB_Type*)       BKP_BB_BASE    )
#define BB_PWR           ( (PWR_BB_Type*)       PWR_BB_BASE    )
#define BB_AFIO          ( (AFIO_BB_Type*)      AFIO_BB_BASE   )
#define BB_EXTI          ( (EXTI_BB_Type*)      EXTI_BB_BASE   )
#define BB_GPIOA         ( (GPIOA_BB_Type*)     GPIOA_BB_BASE  )
#define BB_GPIOB         ( (GPIOA_BB_Type*)     GPIOB_BB_BASE  )
#define BB_GPIOC         ( (GPIOA_BB_Type*)     GPIOC_BB_BASE  )
#define BB_GPIOD         ( (GPIOA_BB_Type*)     GPIOD_BB_BASE  )
#define BB_ADC1          ( (ADC1_BB_Type*)      ADC1_BB_BASE   )
#define BB_ADC2          ( (ADC2_BB_Type*)      ADC2_BB_BASE   )
#define BB_TIM1          ( (TIM1_BB_Type*)      TIM1_BB_BASE   )
#define BB_SPI1          ( (SPI1_BB_Type*)      SPI1_BB_BASE   )
#define BB_USART1        ( (USART1_BB_Type*)    USART1_BB_BASE )
#define BB_DMA1          ( (DMA1_BB_Type*)      DMA1_BB_BASE   )
#define BB_RCC           ( (RCC_BB_Type*)       RCC_BB_BASE    )
#define BB_FLASH         ( (FLASH_BB_Type*)     FLASH_BB_BASE  )
#define BB_CRC           ( (CRC_BB_Type*)       CRC_BB_BASE    )



#endif


