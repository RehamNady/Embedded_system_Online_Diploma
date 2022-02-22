/*
 * GPIO_HW.h
 *
 *  Created on: Feb 22, 2022
 *      Author: reham
 */

#ifndef GPIO_HW_H_
#define GPIO_HW_H_

#define RCC_Base 0x40021000
#define GPIOA_Base 0x40010800
#define GPIOB_Base 0x40010C00

#define RCC_APB2ENR *((volatile unsigned int *)(RCC_Base+0x18))

#define GPIOA_CRL *((volatile unsigned int *)(GPIOA_Base+0x00))
#define GPIOA_CRH *((volatile unsigned int *)(GPIOA_Base+0x04))
#define GPIOA_IDR *((volatile unsigned int*)(GPIOA_Base+0x08))
#define GPIOA_ODR *((volatile unsigned int*)(GPIOA_Base+0x0C))

#define GPIOB_CRL *((volatile unsigned int *)(GPIOB_Base+0x00))
#define GPIOB_CRH *((volatile unsigned int *)(GPIOB_Base+0x04))
#define GPIOB_IDR *((volatile unsigned int*)(GPIOB_Base+0x08))
#define GPIOB_ODR *((volatile unsigned int*)(GPIOB_Base+0x0C))





#endif /* GPIO_HW_H_ */
