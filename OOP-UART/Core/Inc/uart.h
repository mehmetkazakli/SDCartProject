/*
 * uart.h
 *
 *  Created on: Jul 5, 2020
 *      Author: Mehmet
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "stm32_gpio_driver.h"

#define __IO		volatile

// #define ME_PERIPH_BASE		0x40000000U							// 0x4000 0000
#define AP2PERIPH_BASE		(ME_PERIPH_BASE + 0x00010000U)		// 0x4001 0000
#define ME_UART1_BASE		(AP2PERIPH_BASE + 0x00003800U)		// 0x4001 3800


typedef struct
{
	__IO	uint32_t	CR1;
	__IO	uint32_t	CR2;
	__IO	uint32_t	CR3;
	__IO	uint32_t	BRR;
	__IO	uint32_t	GTPR;
	__IO	uint32_t	RTOR;
	__IO	uint32_t	RQR;
	__IO	uint32_t	ISR;
	__IO	uint32_t	ICR;
	__IO	uint32_t	RDR;
	__IO	uint32_t	TDR;
}ME_USART_Typedef;

#define	ME_USART1			((ME_USART_Typedef *) ME_UART1_BASE)





#endif /* INC_UART_H_ */
