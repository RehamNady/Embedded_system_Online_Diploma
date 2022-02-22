/*
 * 1st_task.c
 *
 * Created: 2/21/2022 11:17:19 PM
 * Author : reham
 */ 
//turn on led on port d5,6,7 and then turnoff it in reverse order

#include "BitMath.h"
#include "DIO_HW.h"

#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
    // d5,6,7 output
	DDRD_Reg |=(0b111<<5);
    while (1) 
    {
		SetBit(PORTD_Reg,5);
		_delay_ms(100);
		SetBit(PORTD_Reg,6);
		_delay_ms(100);
		SetBit(PORTD_Reg,7);
		_delay_ms(300);
		ClearBit(PORTD_Reg,7);
		_delay_ms(100);
		ClearBit(PORTD_Reg,6);
		_delay_ms(100);
		ClearBit(PORTD_Reg,5);
		_delay_ms(100);
		
		
    }
}

