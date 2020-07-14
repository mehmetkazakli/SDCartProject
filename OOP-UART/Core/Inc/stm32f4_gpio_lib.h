/*
 * stm32f4_gpio_lib.h
 *
 *  Created on: Jul 4, 2020
 *      Author: Mehmet
 */

#ifndef INC_STM32F4_GPIO_LIB_H_
#define INC_STM32F4_GPIO_LIB_H_

#include "stm32_gpio_driver.h"

#define ME_GPIO_PIN_0		(uint16_t)0x0001U
#define ME_GPIO_PIN_1		(uint16_t)0x0002U
#define ME_GPIO_PIN_2		(uint16_t)0x0004U
#define ME_GPIO_PIN_3		(uint16_t)0x0008U
#define ME_GPIO_PIN_4		(uint16_t)0x0010U
#define ME_GPIO_PIN_5		(uint16_t)0x0020U
#define ME_GPIO_PIN_6		(uint16_t)0x0040U
#define ME_GPIO_PIN_8		(uint16_t)0x0080U
#define ME_GPIO_PIN_9		(uint16_t)0x0100U
#define ME_GPIO_PIN_10		(uint16_t)0x0200U
#define ME_GPIO_PIN_11		(uint16_t)0x0400U
#define ME_GPIO_PIN_12		(uint16_t)0x0800U
#define ME_GPIO_PIN_13		(uint16_t)0x1000U
#define ME_GPIO_PIN_14		(uint16_t)0x2000U
#define ME_GPIO_PIN_15		(uint16_t)0x4000U
#define ME_GPIO_PIN_ALL	(uint16_t)0xFFFFU

// Sadece Mode Registerı ile ilgili GPIO'yu INPUT yapar
#define ME_GPIO_MODE_INPUT	0x00U


/*
 * Hem Mode regiser, Hem type register'i ayarlayarak Output Push-Pull, Output Open-Drain, Alternate Function Push-Pull, Alternate Function Open-Drain
 * gibi birden fazla register'i tek bir #define tanımlayarak ayarlamak için kullanılabilir.
 */
#define ME_GPIO_MODE_OUT_PP	0x11U
#define ME_GPIO_MODE_OUT_OD	0x01U
#define ME_GPIO_MODE_AF_PP	0x02U
#define	ME_GPIO_MODE_AF_OD	0x12U

#define ME_GPIO_NOPULL		0x00U
#define ME_GPIO_PULL_UP	0x01U
#define ME_GPIO_NO_PULL	0x02U

typedef struct
{
	uint32_t Pin;
	uint32_t Mode;
	uint32_t Pull;
	uint32_t Speed;
	uint32_t Alternate;
}ME_GPIO_InitTypeDef;


typedef enum
{
	ME_GPIO_PIN_RESET = 0,
	ME_GPIO_PIN_SET
}ME_GPIO_Pin_State;

void LIB_GPIO_Init(ME_GPIO_Typedef * GPIOx, ME_GPIO_InitTypeDef *GPIO_Init);
ME_GPIO_Pin_State	LIB_GPIO_Read_Pin(ME_GPIO_Typedef *GPIOx, uint16_t GPIO_Pin);
void	LIB_GPIO_Write_Pin(ME_GPIO_Typedef *GPIOx,uint32_t GPIO_Pin, ME_GPIO_Pin_State PinState);
void 	LIB_GPIO_Toogle_Pin(ME_GPIO_Typedef *GPIOx,uint32_t GPIO_Pin);

void __LIB_RCC_GPIOA_Clock_Enable(void);
void __LIB_RCC_GPIOB_Clock_Enable(void);
void __LIB_RCC_GPIOC_Clock_Enable(void);
void __LIB_RCC_GPIOD_Clock_Enable(void);
void __LIB_RCC_GPIOE_Clock_Enable(void);
void __LIB_RCC_GPIOF_Clock_Enable(void);

#endif /* INC_STM32F4_GPIO_LIB_H_ */
