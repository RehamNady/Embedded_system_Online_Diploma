/*
 * task3.c
 *
 * Created: 2/22/2022 12:46:33 AM
 * Author : reham
 */ 


#include "BitMath.h"
#include "DIO_HW.h"

#define F_CPU 8000000UL
#include <util/delay.h>



int main(void)
{
    // port d0 input 
	ClearBit(DDRD_Reg,0);
	ClearBit(PORTD_Reg,0); // disable internal pullup
	// d4 output
	SetBit(DDRD_Reg,4); 

    while (1) 
    {
		if(GetBit(PIND_Reg,0)==1)
		{
			SetBit(PORTD_Reg,4);
			_delay_ms(1000);
			ClearBit(PORTD_Reg,4);
		}
		while(GetBit(PIND_Reg,0)==1);
    }
}

