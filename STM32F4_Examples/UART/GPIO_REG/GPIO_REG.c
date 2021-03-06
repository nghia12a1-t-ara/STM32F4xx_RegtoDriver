#include "GPIO_REG.h"
#include "CLOCK_REG.h"

void GPIOC_UART6_Setup(void)
{
	GPIOC_PCLK_EN();

	/* PC6 as AF mode - USART6 TX */
	GPIOC->MODER |= (0x2 << 12);
	GPIOC->OTYPER &= ~(1 << 6);
	GPIOC->OSPEEDR |= (0x2 << 12);
	GPIOC->PUPDR |= (0x1 << 12);

	/* PC7 as AF mode - USART6 RX */
	GPIOC->MODER |= (0x2 << 14);
	GPIOC->OTYPER &= ~(1 << 7);
	GPIOC->OSPEEDR |= (0x2 << 14);
	GPIOC->PUPDR |= (0x1 << 14);

	/* Alternate Function Settings */
	GPIOC->AFR[0] |= (0x8 << 24);
	GPIOC->AFR[0] |= (0x8 << 28);
}
