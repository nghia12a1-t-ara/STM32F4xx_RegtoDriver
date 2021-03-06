/*
 * UART_REG.h
 *
 *  Created on: May 6, 2022
 *      Author: Admin
 */

#ifndef UART_REG_H_
#define UART_REG_H_

#include <stdint.h>

#define UART_MODE_MASTER			(1 << 3)
#define UART_MODE_SLAVE				(1 << 2)

/*
 * peripheral register definition structure for USART
 */
typedef struct
{
	volatile uint32_t SR;         /*!< Address offset: 0x00 */
	volatile uint32_t DR;         /*!< Address offset: 0x04 */
	volatile uint32_t BRR;        /*!< Address offset: 0x08 */
	volatile uint32_t CR1;        /*!< Address offset: 0x0C */
	volatile uint32_t CR2;        /*!< Address offset: 0x10 */
	volatile uint32_t CR3;        /*!< Address offset: 0x14 */
	volatile uint32_t GTPR;       /*!< Address offset: 0x18 */
} USART_Types;


/*
 * Base addresses of peripherals which are hanging on APB1 bus
 * TODO : Complete for all other peripherals
 */
#define UART6_BASEADDR				(0x40011400UL)
#define UART6  						((USART_Types*)UART6_BASEADDR)

/**
 * Function Prototypes
 * */
void GPIOA_UART1_Setup(void);
void UART_Init(uint8_t MODE);
void UART_SendData(uint8_t *pTxBuffer, uint32_t Len);
void  UART_ReceiveData(uint8_t *pRxBuffer, uint32_t Len);
void UART6_ReceiveINT_Setup(void);

#endif /* UART_REG_H_ */
