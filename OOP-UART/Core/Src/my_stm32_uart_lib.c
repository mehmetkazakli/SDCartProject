/*
 * my_stm32_uart_lib.c
 *
 *  Created on: 6 Tem 2020
 *      Author: Mehmet
 */

#include "my_stm32_uart_lib.h"

#define CR1_CNF1_RX		0X0004		// 0000 0000 0000 0100V
#define BRR_CNF1_115200 0x008b		// 115200 boud rate
#define BRR_CNF1_96500	0X0683		// 9600 baud rate
#define CR1_CNF1_TX		0x0008		// Enable Tx, 8 bit data
#define CR2_CNF1 		0x0000		// 1 stop bit
#define CR3_CNF1		0x0000		// no flow control
#define USART1_CR1_EN	0x2000
#define USART1_CR1_DIS	0x0000



void LIB_UART1_Init(UART_ComType comtype, UART_BoudrateType baudratetype)
{
	ME_RCC->AHBENR |= 1; // Enable GPIO clock
	ME_RCC->APB1ENR|= 0x20000; // Enable USART1 clock

	ME_USART1->CR1 = USART1_CR1_DIS;

	switch (comtype)
	{
	case TX_ONLY:
		ME_GPIOA->MODER  |= 0X0020;	// Enable alternate function
		ME_GPIOA->AFR[0] |= 0x0700;	// alt5 for usart1
		ME_USART1->CR1 = CR1_CNF1_TX;
		break;


	case RX_ONLY:
		ME_GPIOA->MODER |= 0X0080;
		ME_GPIOA->AFR[0] |= 0x7000;	// alt7 for usart1
		ME_USART1->CR1 = CR1_CNF1_RX;
		break;

	case RX_AND_TX:
		ME_GPIOA->MODER |= 0x00200 | 0x0080;
		ME_GPIOA->AFR[0] |= 0x00700 | 0x7000;
		ME_USART1->CR1 |= CR1_CNF1_TX | CR1_CNF1_RX ;
		break;

	default :
		break;
	}

	/*
	 * above code with IF STATEMENT
	 */
	/*
	if(comtype == TX_ONLY)
	{
		ME_GPIOA->MODER  |= 0X0020;	// Enable alternate function
		ME_GPIOA->AFR[0] |= 0x0700;	// alt5 for usart1

		ME_USART1->CR1 = CR1_CNF1_TX;
	}

	else if (comtype == RX_ONLY)
	{
		// PA5
		ME_GPIOA->MODER |= 0X0080;
		ME_GPIOA->AFR[0] |= 0x7000;	// alt7 for usart1

		ME_USART1->CR1 = CR1_CNF1_RX;
	}

	else if (comtype == RX_AND_TX)
	{
		GPIOA->MODER |= 0x00200 | 0x0080;
		GPIOA->AFR[0] |= 0x00700 | 0x7000;

		ME_USART1->CR1 |= CR1_CNF1_TX | CR1_CNF1_RX ;

	}
	*/

	switch(baudratetype)
	{
	case _115200:
		ME_USART1-> BRR = BRR_CNF1_115200;
		break;

	case _96500:
		ME_USART1->BRR = BRR_CNF1_96500;
		break;

	default :
		break;

	}


	ME_USART1->CR2 = CR2_CNF1;
	ME_USART1->CR3 = CR3_CNF1;
	ME_USART1->CR1 |= USART1_CR1_EN;
}




char LIB_UART1_Read(void)
{
	while(!(ME_USART1->ISR & 0x0020)){} // wait until character arrives
	return ME_USART1->RDR;

}

void LIB_UART1_Write(int ch)
{
	while (!(ME_USART1->ISR & 0x0080)){} // wait until Tx buffer is empty
	ME_USART1->TDR =  (ch&0xFF);
}
