/*
 * task2.c
 *
 * Created: 2/21/2022 11:50:42 PM
 * Author : reham
 */ 
//toggle led on portd5 then portd6 then portd7 by button on portd0 

#include "BitMath.h"
#include "DIO_HW.h"

#define F_CPU 8000000UL
#include <util/delay.h>


int main(void)
{
	unsigned char flag =0;
	// d5,6,7 output
	DDRD_Reg |=(0b111<<5);
	//d0 input
	DDRD_Reg &=~(1<<0);
    
    while (1) 
    {
		if(GetBit(PIND_Reg,0)==1)
		{
			/*
			if(flag==0)
			{
				ToggleBit(PORTD_Reg,5);
				flag++;
			}
			else if(flag==1)
			{
				ToggleBit(PORTD_Reg,6);
				flag++;
			}
			else 
			{
				ToggleBit(PORTD_Reg,7);
				flag=0;
				
			}
			*/
			switch (flag)
			{
				case 0:
				ToggleBit(PORTD_Reg,5);
				flag++;
				break;
				case 1:
				ToggleBit(PORTD_Reg,6);
				flag++;
				break;
				case 2:
				ToggleBit(PORTD_Reg,7);
				flag=0;
				break;
				
			}
			
		}
		while(GetBit(PIND_Reg,0)==1);
		
    }
}

