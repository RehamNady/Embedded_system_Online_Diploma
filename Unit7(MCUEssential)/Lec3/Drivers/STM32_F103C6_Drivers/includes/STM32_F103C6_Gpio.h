/*
 * STM32_F103C6_Gpio.h
 *
 *  Created on: Mar 15, 2022
 *      Author: reham
 */

#ifndef INCLUDES_STM32_F103C6_GPIO_H_
#define INCLUDES_STM32_F103C6_GPIO_H_

//Includes
#include "STM32_F103x6.h"
//---------------------------------
//config struct
typedef struct
{
	uint16_t GPIO_PinNumber; 		 //specifies the GPIO pins to be configured
	                         	 	 // this parameter must be set based on @ref GPIO_PINS_define
	uint8_t GPIO_MODE  	   ;		 //specifies the GPIO pins to be configured
                            		 // this parameter must be set based on @ref GPIO_PINS_define
	uint8_t GPIO_Output_speed; 		 //specifies the speed for the selected pins
									 // this parameter must be set based on @ref GPIO_SPEED_define

}GPIO_PinConfig_t;

//@ref GPIO_PIN_state
#define GPIO_PIN_SET	1
#define GPIO_PIN_RESET	0

//@ref GPIO_RETURN_LOCK
#define GPIO_RETURN_LOCK_Enabled	1
#define GPIO_RETURN_LOCK_ERROR		0
//==================================
//Macros Configuration References
//==================================
//@ref GPIO_PINS_define
#define GPIO_PIN_0 						((uint16_t)0x0001) /*pin 0 selected*/
#define GPIO_PIN_1 						((uint16_t)0x0002) /*pin 1 selected*/
#define GPIO_PIN_2 						((uint16_t)0x0004) /*pin 2 selected*/
#define GPIO_PIN_3 						((uint16_t)0x0008) /*pin 3 selected*/
#define GPIO_PIN_4 						((uint16_t)0x0010) /*pin 4 selected*/
#define GPIO_PIN_5 						((uint16_t)0x0020) /*pin 5 selected*/
#define GPIO_PIN_6 						((uint16_t)0x0040) /*pin 6 selected*/
#define GPIO_PIN_7 						((uint16_t)0x0080) /*pin 7 selected*/
#define GPIO_PIN_8 						((uint16_t)0x0100) /*pin 8 selected*/
#define GPIO_PIN_9 						((uint16_t)0x0200) /*pin 9 selected*/
#define GPIO_PIN_10 					((uint16_t)0x0400) /*pin 10 selected*/
#define GPIO_PIN_11 					((uint16_t)0x0800) /*pin 11 selected*/
#define GPIO_PIN_12						((uint16_t)0x1000) /*pin 12 selected*/
#define GPIO_PIN_13 					((uint16_t)0x2000) /*pin 13 selected*/
#define GPIO_PIN_14 					((uint16_t)0x4000) /*pin 14 selected*/
#define GPIO_PIN_15						((uint16_t)0x8000) /*pin 15 selected*/

#define GPIO_PIN_MASK					0x0000FFFFU /*PIN mask for assert test*/

//==================================
//@ref GPIO_MODE_define
//0:Analog mode
//1: floating input (reset state)
//2: input with pull_up
//3:pull-down
//4:General purpose output push-pull
//5: General purpose output open-drain
//6:Alternate function o/p push-pull
//7:Alternate function o/p open-drain
//8://6:Alternate function input
#define GPIO_MODE_Analog			0x00000000u // Analog mode
#define GPIO_MODE_INPUT_FLO			0x00000001u // floating input
#define GPIO_MODE_INPUT_PU			0x00000002u // input with pull_up
#define GPIO_MODE_INPUT_PD			0x00000003u // input with pull_down
#define GPIO_MODE_OUTPUT_PP			0x00000004u // General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD			0x00000005u // General purpose output open-drain
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006u // Alternate function output push-pull
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007u // Alternate function output open drain
#define GPIO_MODE_AF_INPUT			0x00000008u // Alternate function input

//==================================
//@ref GPIO_SPEED_define
//0:Analog mode
//1: output mode,max speed 10MHZ
//2: output mode,max speed 2MHZ
//3:output mode,max speed 50MHZ

#define GPIO_SPEED_10M			0x00000001u //output mode, max speed 10MHZ.
#define GPIO_SPEED_2M			0x00000002u //output mode, max speed 2MHZ.
#define GPIO_SPEED_50M			0x00000003u //output mode, max speed 50MHZ.


/*
 * =================================================================================================
 * 					APIs Supported by "MCAL GPIO DRIVER"
 * =================================================================================================
 */
void MCAL_GPIO_Init(GPIO_Typedef* GPIOx,GPIO_PinConfig_t* PinConfig);
void MCAL_GPIO_DEInit(GPIO_Typedef* GPIOx);

uint8_t MCAL_GPIO_ReadPin (GPIO_Typedef* GPIOx, uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort (GPIO_Typedef* GPIOx);

void MCAL_GPIO_WritePin (GPIO_Typedef* GPIOx, uint16_t PinNumber,uint8_t value);
void MCAL_GPIO_WritePort (GPIO_Typedef* GPIOx,uint16_t value);

void MCAL_GPIO_TogglePin (GPIO_Typedef* GPIOx, uint16_t PinNumber);

uint8_t MCAL_GPIO_lOCKPin (GPIO_Typedef* GPIOx, uint16_t PinNumber);
#endif /* INCLUDES_STM32_F103C6_GPIO_H_ */
