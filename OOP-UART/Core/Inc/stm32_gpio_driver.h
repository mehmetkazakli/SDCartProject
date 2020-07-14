/*
 * stm32_gpio_driver.h
 *
 *  Created on: Jul 4, 2020
 *      Author: Mehmet
 */

#ifndef INC_STM32_GPIO_DRIVER_H_
#define INC_STM32_GPIO_DRIVER_H_

#include "stdint.h"

// 1. İlk önce BASE adresleri yazın
#define ME_PERIPH_BASE		0x40000000U							// 0x4000 0000
#define ME_AHB1PERIPH_BASE (ME_PERIPH_BASE + 0x00020000U)		// 0x4002 0000
#define ME_AHP2PERIPH_BASE	(ME_PERIPH_BASE + 0x08000000U) 		// 0x4800 0000
#define ME_RCC_BASE		(ME_AHB1PERIPH_BASE+ 0x00003000U)		// 0x4002 3000
#define ME_GPIOA_BASE	(ME_AHP2PERIPH_BASE + 0x00000000U)		// 0x4800 0000
#define ME_GPIOB_BASE	(ME_AHP2PERIPH_BASE + 0x00004000U)		// 0x4800 0400
#define ME_GPIOC_BASE	(ME_AHP2PERIPH_BASE + 0x00008000U)		// 0x4800 0800
#define ME_GPIOD_BASE	(ME_AHP2PERIPH_BASE + 0x0000C000U)		// 0x4800 0C00
#define ME_GPIOE_BASE	(ME_AHP2PERIPH_BASE + 0x00001000U)		// 0x4800 1000
#define ME_GPIOF_BASE	(ME_AHP2PERIPH_BASE + 0x00001400U)		// 0x4800 1400


// 2. Daha sonra BASE adreslere eklenecek olan offset'leri register halinede aşağıdaki gibi struct oluştururak yazın.
#define __IO		volatile

typedef struct
{
	__IO uint32_t	MODER;		// 00
	__IO uint32_t	OTYPER;		// 04
	__IO uint32_t	OSPEEDR;	// 08
	__IO uint32_t	PUPDR;		// 0C
	__IO uint32_t	IDR;		// 10
	__IO uint32_t	ODR;		// 14
	__IO uint32_t	BSRR;		// 18
	__IO uint32_t	LCKR;		// 1C
	__IO uint32_t	AFR[2];		// 20
	__IO uint32_t	BRR;		// 28
}ME_GPIO_Typedef;


typedef struct
{
	__IO uint32_t	CR;
	__IO uint32_t	CFGR;
	__IO uint32_t	CIR;
	__IO uint32_t	APB2RSTR;
	__IO uint32_t	APB1RSTR;
// 		 uint32_t 	RESERVED;	 EGER ADRESS 1 BYTLIK KAYAR ISE BOYLE BIR BOSLUK/RESERVED OLUSTURABILIRSIN
	__IO uint32_t	AHBENR;
	__IO uint32_t	APB2ENR;
	__IO uint32_t	APB1ENR;
//       uint32_t 	RESERVED;	 EGER ADRESS 1 BYTLIK KAYAR ISE BOYLE BIR BOSLUK/RESERVED OLUSTURABILIRSIN
	__IO uint32_t	BDCR;
	__IO uint32_t	CSR;
	__IO uint32_t	AHBRSTR;
	__IO uint32_t	CFGR2;
// 		 uint32_t 	RESERVED[2];  EGER ADRESS 2 BYTLIK KAYAR ISE BOYLE BIR BOSLUK/RESERVED OLUSTURABILIRSIN
	__IO uint32_t	CFGR3;
}ME_RCC_Typedef;

// 3. Simdi sırada RCC, GPIOA vs base adreslerine ofset ekleyip registerlara ulaşabilme özelliğini eklemeye geldi.
#define	ME_RCC			((ME_RCC_Typedef *) ME_RCC_BASE)  // Burada RCC Base Adresini pointer olarak kullanıp RCC Typedef ofsetlerini RCC_BASE adresine ekliyoruz.
#define	ME_GPIOA		((ME_GPIO_Typedef *) ME_GPIOA_BASE)
#define	ME_GPIOB		((ME_GPIO_Typedef *) ME_GPIOB_BASE)
#define	ME_GPIOC		((ME_GPIO_Typedef *) ME_GPIOC_BASE)
#define	ME_GPIOD		((ME_GPIO_Typedef *) ME_GPIOD_BASE)
#define	ME_GPIOE		((ME_GPIO_Typedef *) ME_GPIOE_BASE)
#define	ME_GPIOF		((ME_GPIO_Typedef *) ME_GPIOF_BASE)

#define	GPIOA_EN	1<<17
#define	GPIOB_EN	1<<18
#define	GPIOC_EN	1<<19
#define	GPIOD_EN	1<<20
#define	GPIOE_EN	1<<21
#define	GPIOF_EN	1<<22


#define	MODER_5_OUT	1<<10
#define	LED_PIN		1<<5

#endif /* INC_STM32_GPIO_DRIVER_H_ */
