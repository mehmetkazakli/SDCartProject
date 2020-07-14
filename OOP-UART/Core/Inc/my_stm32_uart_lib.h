/*
 * my_stm32_uart_lib.h
 *
 *  Created on: 6 Tem 2020
 *      Author: Mehmet
 */

#ifndef INC_MY_STM32_UART_LIB_H_
#define INC_MY_STM32_UART_LIB_H_

#include "uart.h"

#include "stm32_gpio_driver.h"



typedef enum
{
	RX_ONLY = 0,
	TX_ONLY,
	RX_AND_TX

}UART_ComType;

typedef enum
{
	_115200 = 0,
	_96500
}UART_BoudrateType;


void LIB_UART1_Init(UART_ComType comtype, UART_BoudrateType baudratetype);



char LIB_UART1_Read(void);
void LIB_UART1_Write(int ch);

#endif /* INC_MY_STM32_UART_LIB_H_ */
