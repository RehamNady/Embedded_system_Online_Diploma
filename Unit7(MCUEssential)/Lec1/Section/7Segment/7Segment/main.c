/*
 * 7Segment.c
 *
 * Created: 2/22/2022 12:55:29 AM
 * Author : reham
 */ 


#include "BitMath.h"
#include "DIO_HW.h"

#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	int i,j,x;
	// portc 2:7 output
	DDRC_Reg = 0xFC;

    while (1) 
    {
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{
				for(x=0;x<100;x++)
				{
					PORTC_Reg = ((PORTC_Reg & 0x0F)|(i<<4));
					PORTC_Reg |=1<<3; //enable 2nd segment
					_delay_ms(1);
					PORTC_Reg &=~(1<<3); //disable 2nd segment
					
					PORTC_Reg = ((PORTC_Reg & 0x0F)|(j<<4));
					PORTC_Reg |=1<<2; //enable 1st segment
					_delay_ms(2);
					PORTC_Reg &=~(1<<2); // disable 1st segment
				}
			}
		}
    }
}

