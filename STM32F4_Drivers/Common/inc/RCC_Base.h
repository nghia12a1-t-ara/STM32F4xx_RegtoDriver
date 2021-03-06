#ifndef __RCC_BASE_H_
#define __RCC_BASE_H_

#include "stm32f4xx.h"

/*
 * peripheral register definition structure for RCC
 */
typedef struct
{
  __vo uint32 CR;            /*!< TODO,     										Address offset: 0x00 */
  __vo uint32 PLLCFGR;       /*!< TODO,     										Address offset: 0x04 */
  __vo uint32 CFGR;          /*!< TODO,     										Address offset: 0x08 */
  __vo uint32 CIR;           /*!< TODO,     										Address offset: 0x0C */
  __vo uint32 AHB1RSTR;      /*!< TODO,     										Address offset: 0x10 */
  __vo uint32 AHB2RSTR;      /*!< TODO,     										Address offset: 0x14 */
  __vo uint32 AHB3RSTR;      /*!< TODO,     										Address offset: 0x18 */
  uint32      RESERVED0;     /*!< Reserved, 0x1C                                                       */
  __vo uint32 APB1RSTR;      /*!< TODO,     										Address offset: 0x20 */
  __vo uint32 APB2RSTR;      /*!< TODO,     										Address offset: 0x24 */
  uint32      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                  */
  __vo uint32 AHB1ENR;       /*!< TODO,     										Address offset: 0x30 */
  __vo uint32 AHB2ENR;       /*!< TODO,     										Address offset: 0x34 */
  __vo uint32 AHB3ENR;       /*!< TODO,     										Address offset: 0x38 */
  uint32      RESERVED2;     /*!< Reserved, 0x3C                                                       */
  __vo uint32 APB1ENR;       /*!< TODO,     										Address offset: 0x40 */
  __vo uint32 APB2ENR;       /*!< TODO,     										Address offset: 0x44 */
  uint32      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                  */
  __vo uint32 AHB1LPENR;     /*!< TODO,     										Address offset: 0x50 */
  __vo uint32 AHB2LPENR;     /*!< TODO,     										Address offset: 0x54 */
  __vo uint32 AHB3LPENR;     /*!< TODO,     										Address offset: 0x58 */
  uint32      RESERVED4;     /*!< Reserved, 0x5C                                                       */
  __vo uint32 APB1LPENR;     /*!< TODO,     										Address offset: 0x60 */
  __vo uint32 APB2LPENR;     /*!< RTODO,     										Address offset: 0x64 */
  uint32      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                  */
  __vo uint32 BDCR;          /*!< TODO,     										Address offset: 0x70 */
  __vo uint32 CSR;           /*!< TODO,     										Address offset: 0x74 */
  uint32      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                  */
  __vo uint32 SSCGR;         /*!< TODO,     										Address offset: 0x80 */
  __vo uint32 PLLI2SCFGR;    /*!< TODO,     										Address offset: 0x84 */
  __vo uint32 PLLSAICFGR;    /*!< TODO,     										Address offset: 0x88 */
  __vo uint32 DCKCFGR;       /*!< TODO,     										Address offset: 0x8C */
  __vo uint32 CKGATENR;      /*!< TODO,     										Address offset: 0x90 */
  __vo uint32 DCKCFGR2;      /*!< TODO,     										Address offset: 0x94 */
} RCC_Types;


/**
 * RCC Base Address & Pointer
 */
#define RCC_BASEADDR			(AHB1PERIPH_BASEADDR + 0x3800)
#define RCC						((RCC_Types*)RCC_BASEADDR)


/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()    	(RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()		(RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()		(RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()		(RCC->AHB1ENR |= (1 << 7))
#define GPIOI_PCLK_EN()		(RCC->AHB1ENR |= (1 << 8))


/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN() 		(RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN() 		(RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN() 		(RCC->APB1ENR |= (1 << 23))


/*
 * Clock Enable Macros for SPIx peripheralsbu
 */
#define SPI1_PCLK_EN() 		(RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN() 		(RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN() 		(RCC->APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN() 		(RCC->APB2ENR |= (1 << 13))


/*
 * Clock Enable Macros for USARTx peripherals
 */
#define USART1_PCLK_EN() 	(RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN() 	(RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN() 	(RCC->APB1ENR |= (1 << 18))
#define USART4_PCLK_EN()  	(RCC->APB1ENR |= (1 << 19))
#define USART5_PCLK_EN()  	(RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN() 	(RCC->APB1ENR |= (1 << 5))

/*
 * Clock Enable Macros for DMAx peripherals
 */
#define DMA1_CLOCK_MASK		(21) 
#define DMA2_CLOCK_MASK		(22) 
#define DMA1_PCLK_EN() 		(RCC->AHB1ENR |= (1 << DMA1_CLOCK_MASK))
#define DMA2_PCLK_EN() 		(RCC->AHB1ENR |= (1 << DMA2_CLOCK_MASK))

/*
 * Clock Enable Macros for SYSCFG peripheral
 */
#define SYSCFG_PCLK_EN() (RCC->APB2ENR |= (1 << 14))


#endif	/* !(__RCC_BASE_H_) */
