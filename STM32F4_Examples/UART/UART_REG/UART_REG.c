/*
 * UART_REG.c
 *
 *  Created on: May 6, 2022
 *      Author: Admin
 */

#include "UART_REG.h"
#include "CLOCK_REG.h"
#include "GPIO_REG.h"
#include "NVIC_REG.h"

extern uint8_t pRxBuffer;

void UART_Init(uint8_t MODE)
{
	uint32_t usartdiv;
	uint32_t M_part, F_part;

	GPIOC_UART6_Setup();

	/* Enable Clock for UART6 */
	USART6_PCLK_EN();

	/* Enable TX-Master or RX-Slave */
	UART6->CR1 |= MODE;

	/* bit M - 8 bits Data */
	UART6->CR1 &= ~(1 << 12);

	/* Implement the code to enable the parity control */
	UART6->CR1 &= ~( 1 << 10);

	/* Setup Baudrate - 9600, CLK = 16MHz
	 * Mantissa =
	 * Fraction = */
	/* OVER8 = 0 -> Oversampling by 16 */
	UART6->CR1 &= ~(1 << 15);

	usartdiv = ((25 * 16000000) / (4 * 9600));
	M_part = usartdiv / 100;
	F_part = (usartdiv - (M_part * 100));
	F_part = ((( F_part * 16)+ 50) / 100) & ((uint8_t)0x0F);

	UART6->BRR |= F_part;
	UART6->BRR |= (M_part << 4);

	/* Enable RX Interrupt */
	UART6->CR1 |= (1 << 5);

	/* bit UE - Enable UART */
	UART6->CR1 |= (1 << 13);
}

void UART_SendData(uint8_t *pTxBuffer, uint32_t Len)
{
	for(uint32_t i = 0 ; i < Len; i++)
	{
		/* Wait until TXE flag is set in the SR */
		while ( (UART6->SR & (1 << 7) ) == 0 );

		/* 8bit data transfer */
		UART6->DR |= (uint8_t)(*pTxBuffer  & (uint8_t)0xFF);

		/* Increment the buffer address */
		pTxBuffer++;
	}

	/* Wait till TC flag is set in the SR */
	while ( (UART6->SR & (1 << 6) ) == 0 );
}

void UART_ReceiveData(uint8_t *pRxBuffer, uint32_t Len)
{
	for(uint32_t i = 0 ; i < Len; i++)
	{
		/* Wait until RXNE flag is set in the SR */
		while ( (UART6->SR & (1 << 5) ) == 0 );

		/* Read 8bit data receive from Data Register */
		*pRxBuffer = (uint8_t)(UART6->DR & (uint8_t)0xFF);

		/* Increment the buffer address */
		pRxBuffer++;
	}
}

void UART6_ReceiveINT_Setup(void)
{
	/* Enable USART Interrupt, IRQ_Number = 71 */
	*NVIC_ISER2 |= (1 << 8);

	*NVIC_ICPR2 |= (1 << 8);

	__asm volatile("cpsie i");
}

void USART6_IRQHandler(void)
{
	if ( (UART6->SR & (1 << 5) ) == 0 )
	{
		pRxBuffer = (uint8_t)(UART6->DR & (uint8_t)0xFF);
	}

	UART6->SR &= ~(1 << 5);
	*NVIC_ICPR2 |= (1 << 8);
}





