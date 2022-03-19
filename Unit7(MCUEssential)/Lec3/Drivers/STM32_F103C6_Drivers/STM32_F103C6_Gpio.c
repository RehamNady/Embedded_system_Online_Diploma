/*
 * STM32_F103C6_Gpio.c
 *
 *  Created on: Mar 15, 2022
 *      Author: reham
 */

#include "STM32_F103C6_Gpio.h"

uint8_t Get_CRLH_position(uint16_t pinNumber)
{
	switch(pinNumber)
	{
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28;
		break;

	}
	return 0;
}
/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_Init
 * @BRIEF		-initialize the GPIOX PINY according to the specified parameters in the PinConfig
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @param [in]	-PinConfig pointer to GPIO_PinConfig_t structure that contains the configuration information
 * 				for the specified GPIO pin.
 * @returnval	-None
 * Note			-Stm32F103c6 MCU has GPIO A,B,C,D,E Modules
 * 				 but LQFP48 Package has only GPIO A,B,PART OF C/D exported as external pins from the MCU
 *
 */


void MCAL_GPIO_Init(GPIO_Typedef* GPIOx,GPIO_PinConfig_t* PinConfig)
{
	//Port configuration register low (GPIOx_CRL) from 0 to 7
	//Port configuration register high (GPIOx_CRH) from 8 to 15
	volatile uint32_t* Configergister =NULL;
	uint8_t pin_config=0;
	Configergister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8)?&GPIOx->CRL :&GPIOx->CRH;
	// clear CNF[1:0] Mode[1:0]
	(*Configergister) &=~(0xf <<(Get_CRLH_position(PinConfig->GPIO_PinNumber)));

	//if pin is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD)|| (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD)|| (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP))
	{
		pin_config=((((PinConfig->GPIO_MODE -4)<<2)|(PinConfig->GPIO_Output_speed))& 0x0f);

	}
	//if pin is input
	else //Mode=00 :input mode
	{
		if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO)|| (PinConfig->GPIO_MODE == GPIO_MODE_Analog))
		{
			//set: CNF8[1:0] MODE8[1:0]00
			pin_config= (((PinConfig->GPIO_MODE)<<2)&0x0f);

		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT)//consider it as input floating
		{
			//set: CNF8[1:0] MODE8[1:0]00
			pin_config= (((GPIO_MODE_INPUT_FLO)<<2)&0x0f);
		}
		else //PU or PD
		{
			//set: CNF8[1:0] MODE8[1:0]00
			pin_config= (((GPIO_MODE_INPUT_PU)<<2)&0x0f);

			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				//pxODR =1 input pull_up: Table 20 port bit configuration table
				GPIOx->ODR |=(PinConfig->GPIO_PinNumber);

			}
			else//PD
			{
				//pxODR =0 input pull_down: Table 20 port bit configuration table
				GPIOx->ODR &=~(PinConfig->GPIO_PinNumber);
			}
		}
	}
	//write on CRL or CRH
	(*Configergister) |= ((pin_config)<<Get_CRLH_position(PinConfig->GPIO_PinNumber));

}

/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_DEInit
 * @BRIEF		-reset all the GPIOX PINY according to the specified parameters in the PinConfig
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @returnval	-None
 * Note			-None
 *
 */

void MCAL_GPIO_DEInit(GPIO_Typedef* GPIOx)
{
	/*GPIOx->CRL=0x44444444	;
	GPIOx->CRH=0x44444444	;
	GPIOx->BRR=0x00000000	;
	GPIOx->BSRR=0x00000000	;
	//GPIOx->IDR (Read only)
	GPIOx->LCKR=0x00000000	;
	GPIOx->ODR=0x00000000	;*/

	//2nd method by reset controller
	//set and reset bit
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |=(1<<2);
		RCC->APB2RSTR &=~(1<<2);
	}
	if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR |=(1<<3);
		RCC->APB2RSTR &=~(1<<3);
	}
	if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR |=(1<<4);
		RCC->APB2RSTR &=~(1<<4);
	}
	if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR |=(1<<5);
		RCC->APB2RSTR &=~(1<<5);
	}
	if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR |=(1<<6);
		RCC->APB2RSTR &=~(1<<6);
	}

}

/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_ReadPin
 * @BRIEF		-Read Specific PIN
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @Param [in]	-PinNumber:set pinNumber according @ref GPIO_PINS_define
 * @returnval	-the input pin value (two values based on @ref GPIO_PIN_state)
 * Note			-None
 *
 */


uint8_t MCAL_GPIO_ReadPin (GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	uint8_t bitstatus;
	if(((GPIOx->IDR) & PinNumber) != (uint32_t)GPIO_PIN_RESET)
	{
		bitstatus = GPIO_PIN_SET;
	}
	else
	{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}

/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_ReadPort
 * @BRIEF		-Read the input port value
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @returnval	-the input port value
 * Note			-None
 *
 */

uint16_t MCAL_GPIO_ReadPort (GPIO_Typedef* GPIOx)
{
	uint16_t port_value;
	port_value = (uint16_t)(GPIOx->IDR);
	return port_value;

}

/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_WritePin
 * @BRIEF		-write on Specific input PIN
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @Param [in]	-PinNumber:specifies the port bit to read.set by @ref GPIO_PINS_define
 * @Param [in]	-Value:pin value
 * @returnval	-none
 * Note			-None
 *
 */

void MCAL_GPIO_WritePin (GPIO_Typedef* GPIOx, uint16_t PinNumber,uint8_t value)
{
	if(value != (uint8_t)GPIO_PIN_RESET)
	{
		GPIOx->ODR |=PinNumber;
		/*
		// or by using BSRR
		GPIOx->BSRR=(uint32_t)PinNumber;*/
	}
	else
	{
		GPIOx->ODR &=~(PinNumber);
		//GPIOx->BRR =(uint32_t)PinNumber;

	}


}

/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_WritePort
 * @BRIEF		-write on output port
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @Param [in]	-Value:port value
 * @returnval	-none
 * Note			-None
 *
 */


void MCAL_GPIO_WritePort (GPIO_Typedef* GPIOx,uint16_t value)
{
	GPIOx->ODR=(uint32_t)value;

}

/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_TogglePin
 * @BRIEF		-toggles the Specified GPIO PIN
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @Param [in]	-PinNumber:specifies the port bit to read.set by @ref GPIO_PINS_define
 * @returnval	-none
 * Note			-None
 *
 */
void MCAL_GPIO_TogglePin (GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber;

}

/*
 * ================================================================================
 * @FUNC		-MCAL_GPIO_lockPin
 * @BRIEF		-The locking mechanism allows the IO configuration to be frozen
 * @Param [in]	-GPIOX: where x can be (A..E depending on device used)to select the GPIO peripheral
 * @Param [in]	-PinNumber:specifies the port bit to read.set by @ref GPIO_PINS_define
 * @returnval	-Ok is pin config is locked or ERROR if pin not locked(OK and ERROR are defined @ref GPIO_RETURN_LOCK
 * Note			-None
 *
 */
uint8_t MCAL_GPIO_lOCKPin (GPIO_Typedef* GPIOx, uint16_t PinNumber)
{
	//set lck[16]
	volatile uint32_t tmp = 1<<16;
	//set the lcky
	tmp |= PinNumber;
	//sequence
	//write 1
	GPIOx->LCKR = tmp;
	//write 0
	GPIOx->LCKR = PinNumber;
	//write 1
	GPIOx->LCKR = tmp;
	//Read 0
	tmp = GPIOx->LCKR;
	//Read 1(this read is optional but confirms that the lock is active)
	if((uint32_t)(((GPIOx->LCKR)>>16)&1))
	{
		return GPIO_RETURN_LOCK_Enabled;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR;
	}

}
