/*
 * STM32_F103x6.h
 *
 *  Created on: Mar 15, 2022
 *      Author: reham
 */

#ifndef INCLUDES_STM32_F103X6_H_
#define INCLUDES_STM32_F103X6_H_

//--------------------------------
//Includes
//--------------------------------
#include <stdlib.h>
#include <stdint.h>

//--------------------------------
//Base addresees for memory
//--------------------------------
#define FLASH_Memory_BASE						0x08000000UL
#define System_Memory_BASE						0x1FFFF000UL
#define SRAM_Memory_BASE						0x20000000UL


#define Peripherals_BASE						0x40000000UL
#define cortex_M3_internal_Peripherals_BASE		0xE0000000UL

//--------------------------------
//Base addresees for AHB peripheral
//--------------------------------
//1-RCC
#define RCC_Base								0x40021000UL

//--------------------------------
//Base addresees for APB2 peripheral
//--------------------------------
//1-GPIOA
//A,B fully included in LQF48 Package
#define GPIOA_Base								0x40010800UL
#define GPIOB_Base								0x40010C00UL

//C,D partial included in LQF48 Package
#define GPIOC_Base								0x40011000UL
#define GPIOD_Base								0x40011400UL

//E not included in LQF48 Package
#define GPIOE_Base								0x40011800UL

//2-EXTERNAL INTERRUPT
#define EXTI_Base								0x40010400UL

//3-AFIO
#define AFIO_Base								0x40010000UL

//--------------------------------
//Base addresees for APB1 peripheral
//--------------------------------

//=================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//-*-*-*-*-*-*-*-*-*-*
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Typedef;
//-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*-*
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

}RCC_Typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RSTR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*-*

typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4; //0X14
	uint32_t 		  RESERVED0;
	volatile uint32_t MAPR2;   //0X1C

}AFIO_Typedef;


//=================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral instants
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA               ((GPIO_Typedef *)GPIOA_Base)
#define GPIOB               ((GPIO_Typedef *)GPIOB_Base)
#define GPIOC               ((GPIO_Typedef *)GPIOC_Base)
#define GPIOD               ((GPIO_Typedef *)GPIOD_Base)
#define GPIOE               ((GPIO_Typedef *)GPIOE_Base)

#define RCC                 ((RCC_Typedef *)RCC_Base)

#define EXTI                ((EXTI_Typedef *)EXTI_Base)

#define AFIO                ((AFIO_Typedef *)AFIO_Base)

//=================================================

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Clock enable macros
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()  (RCC->APB2ENR |=1<<2)
#define RCC_GPIOB_CLK_EN()  (RCC->APB2ENR |=1<<3)
#define RCC_GPIOC_CLK_EN()  (RCC->APB2ENR |=1<<4)
#define RCC_GPIOD_CLK_EN()  (RCC->APB2ENR |=1<<5)
#define RCC_GPIOE_CLK_EN()  (RCC->APB2ENR |=1<<6)

#define RCC_AFIO_CLK_EN()  (RCC->APB2ENR |=1<<0)
#endif /* INCLUDES_STM32_F103X6_H_ */
