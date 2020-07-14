/*
 * my_stm32_systick.h
 *
 *  Created on: 6 Tem 2020
 *      Author: Mehmet
 */

#ifndef INC_MY_STM32_SYSTICK_H_
#define INC_MY_STM32_SYSTICK_H_

#include <stdint.h>

#define __IOM	volatile  /* Read/Write structure member permission*/
#define __OM	volatile  /* Write only structure member permission*/
#define __IM	volatile  /* Read only structure member permission*/

#define SCB_BASE		(0xE000E000UL) 	// System Control Base Adress

#define	SysTick_Offset	(0x01UL)
#define	SysTick_BASE	(SCB_BASE + SysTick_Offset)

typedef struct
{
	__IOM	uint32_t CTRL;
	__IOM	uint32_t LOAD;
	__IOM	uint32_t VAL;
	__IM	uint32_t CALIB;
}SysTick_Type;

#define SysTick 	((SysTick_Type*) SysTick_BASE)	//


#endif /* INC_MY_STM32_SYSTICK_H_ */
