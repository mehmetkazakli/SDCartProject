/*
 * my_stm32_systick_lib.c
 *
 *  Created on: 6 Tem 2020
 *      Author: Mehmet
 */

#include "my_stm32_systick_lib.h"



void LIB_SYSTICK_Delay(uint32_t sec)
{
	/*
	 * 	Configure Systick
	 */

	SysTick->LOAD = 16000000-1;		//
	SysTick->VAL = 0;				// clear currnet  value register
	SysTick->CTRL = 5;				// Enable systick , no interrupt

	int i;
	for (i=0;i<sec;i++)
	{
		/*
		 * Wait until the CONTFLAG is set
		 */
		while((SysTick->CTRL & 0x10000) == 0) {}
	}
	SysTick->CTRL = 0; /* Stop the TIMER (EN = 0) */
}


void LIB_SYSTICK_DelayMs(uint32_t mili)
{
	/*
	 * 	Configure Systick
	 */

	SysTick->LOAD = 16000-1;		//
	SysTick->VAL = 0;				// clear currnet  value register
	SysTick->CTRL = 5;				// Enable systick , no interrupt

	int i;
	for (i=0;i<mili;i++)
	{
		/*
		 * Wait until the CONTFLAG is set
		 */
		while((SysTick->CTRL & 0x10000) == 0) {}
	}
	SysTick->CTRL = 0; /* Stop the TIMER (EN = 0) */


}


