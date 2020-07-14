/*
 * my_stm32_systick_lib.h
 *
 *  Created on: 6 Tem 2020
 *      Author: Mehmet
 */

#ifndef INC_MY_STM32_SYSTICK_LIB_H_
#define INC_MY_STM32_SYSTICK_LIB_H_


#include "my_stm32_systick.h"

void LIB_SYSTICK_Delay(uint32_t sec);
void LIB_SYSTICK_DelayMs(uint32_t mili);

#endif /* INC_MY_STM32_SYSTICK_LIB_H_ */
