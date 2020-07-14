/*
 * stm32f4_gpio_lib.c
 *
 *  Created on: Jul 4, 2020
 *      Author: Mehmet
 */

#include "stm32f4_gpio_lib.h"

#define ME_GPIO_NUMBER 				16U
#define ME_GPIO_MODER_MODE0			0x3U<<0
#define ME_GPIO_MODE				0x03U
#define	ME_GPIO_PUPDR_PUPDR0		0x3U<<0
#define	ME_GPIO_OSPEEDER_OSPEEDR0	0x3U<<0
#define	ME_GPIO_OTYPER_OT0			0x1U<<0
#define ME_GPIO_OUTPUT_TYPE			0X00010U


void LIB_GPIO_Init(ME_GPIO_Typedef  *GPIOx, ME_GPIO_InitTypeDef *GPIO_Init){

  uint32_t position;
  uint32_t ioposition = 0x00U;
  uint32_t iocurrent = 0x00U;
  uint32_t temp = 0x00U;

	  /* Configure the port pins */
  for(position = 0U; position < ME_GPIO_NUMBER; position++)
  {
    /* Get the IO position */
    ioposition = 0x01U << position;
    /* Get the current IO position */
    iocurrent = (uint32_t)(GPIO_Init->Pin) & ioposition;

    if(iocurrent == ioposition)
    {

    	/*
    	 * Alternate function selection
    	 */
     if((GPIO_Init->Mode == ME_GPIO_MODE_AF_PP) || (GPIO_Init->Mode == ME_GPIO_MODE_AF_OD))
    		 {
    	 	 	 temp  = GPIOx->AFR[position>>3U];
    	 	 	 temp &= (0xFU<<((uint32_t) (position & 0x07U) * 4U));
    	 	 	 temp |= ((uint32_t)(GPIO_Init->Alternate) << (((uint32_t) position & 0x07U)*4U));
    	 	 	 GPIOx->AFR[position >>3U] = temp;
    		 }

     /*
      * Direction Mode
      */
      /* Configure IO Direction mode (Input, Output) */
      temp = GPIOx->MODER;
      temp &= ~(ME_GPIO_MODER_MODE0 << (position * 2U));
      temp |= ((GPIO_Init->Mode & ME_GPIO_MODE) << (position * 2U));
      GPIOx->MODER = temp;


      /*
       * Alternate function selection
       */
      /* Activate the Pull-up or Pull down resistor for the current IO */
      if((GPIO_Init->Mode == ME_GPIO_MODE_OUT_PP) || (GPIO_Init->Mode == ME_GPIO_MODE_OUT_OD) ||
    	 (GPIO_Init->Mode == ME_GPIO_MODE_AF_PP) || (GPIO_Init->Mode == ME_GPIO_MODE_AF_OD))
      {
    	  	temp  = GPIOx->OSPEEDR;
    	  	temp &= ~(ME_GPIO_OSPEEDER_OSPEEDR0 << (position *2U));
    	  	temp |= (GPIO_Init->Speed << (position *2U));
    	  	GPIOx->OSPEEDR = temp;


    	  	/*
    	  	 * Output Type
    	  	 */
    	  	temp  = GPIOx->OTYPER;
    	  	temp &= ~(ME_GPIO_OTYPER_OT0 << (position *2U));
    	  	temp |= (((GPIO_Init->Mode & ME_GPIO_OUTPUT_TYPE ) >> 4U) << (position *2U));
    	  	GPIOx->OTYPER = temp;

      }
      temp = GPIOx->PUPDR;
      temp &= ~(ME_GPIO_PUPDR_PUPDR0 << (position * 2U));
      temp |= ((GPIO_Init->Pull) << (position * 2U));
      GPIOx->PUPDR = temp;
		}

		}
}

ME_GPIO_Pin_State	LIB_GPIO_Read_Pin(ME_GPIO_Typedef *GPIOx, uint16_t GPIO_Pin)
{
	ME_GPIO_Pin_State bitstatus;
	if((GPIOx->IDR & GPIO_Pin) != (uint32_t)ME_GPIO_PIN_RESET)
	{
		bitstatus = ME_GPIO_PIN_SET;
	}
	else
	{
		bitstatus = ME_GPIO_PIN_RESET;
	}

	return bitstatus;
}

void	LIB_GPIO_Write_Pin(ME_GPIO_Typedef *GPIOx,uint32_t GPIO_Pin, ME_GPIO_Pin_State PinState)
{
	if(PinState != ME_GPIO_PIN_RESET)
	{
		GPIOx->BSRR = GPIO_Pin;
	}
	else
	{
		GPIOx->BSRR = (uint32_t) GPIO_Pin <<16;
	}
}



void 	LIB_GPIO_Toogle_Pin(ME_GPIO_Typedef *GPIOx,uint32_t GPIO_Pin)
{
		GPIOx->ODR ^= GPIO_Pin;
}

void __LIB_RCC_GPIOA_Clock_Enable(void) {ME_RCC->AHBENR = GPIOA_EN;}
void __LIB_RCC_GPIOB_Clock_Enable(void)	{ME_RCC->AHBENR = GPIOB_EN;}
void __LIB_RCC_GPIOC_Clock_Enable(void) {ME_RCC->AHBENR = GPIOC_EN;}
void __LIB_RCC_GPIOD_Clock_Enable(void) {ME_RCC->AHBENR = GPIOD_EN;}
void __LIB_RCC_GPIOE_Clock_Enable(void) {ME_RCC->AHBENR = GPIOE_EN;}
void __LIB_RCC_GPIOF_Clock_Enable(void) {ME_RCC->AHBENR = GPIOF_EN;}



