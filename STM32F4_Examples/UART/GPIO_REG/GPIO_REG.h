/*
 * GPIO_REG.h
 *
 *  Created on: May 6, 2022
 *      Author: Admin
 */

#ifndef GPIO_REG_H_
#define GPIO_REG_H_

#include <stdint.h>

/*
 * peripheral register definition structure for GPIO
 */
typedef struct
{
	volatile uint32_t MODER;                        /*!< GPIO port mode register,                    	Address offset: 0x00      */
	volatile uint32_t OTYPER;                       /*!< TODO,     										Address offset: 0x04      */
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t LCKR;
	volatile uint32_t AFR[2];					 /*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
} GPIO_Types;


/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 * TODO : Complete for all other peripherals
 */
#define GPIOC_BASEADDR                   (0x40020800UL)
#define GPIOC  							((GPIO_Types*)GPIOC_BASEADDR)


void GPIOC_UART6_Setup(void);

#endif /* GPIO_REG_H_ */
