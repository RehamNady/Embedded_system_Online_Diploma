/*
 * Interrupt Controller On Atmega32.c
 *
 * Created: 2/18/2022 3:11:24 PM
 * Author : reham
 */ 

#include <avr/interrupt.h>
#define F_CPU 1000000ul
#include "util/delay.h"

#define PIND_REG (*((volatile unsigned int*)0x30))
#define DDRD_REG (*((volatile unsigned int*)0x31))
#define PORTD_REG (*((volatile unsigned int*)0x32))
#define PINB_REG (*((volatile unsigned int*)0x36))
#define DDRB_REG (*((volatile unsigned int*)0x37))
#define PORTB_REG (*((volatile unsigned int*)0x38))
#define MCUCSR_REG (*((volatile unsigned int*)0x54))
#define MCUCR_REG (*((volatile unsigned int*)0x55))
#define GICR_REG (*((volatile unsigned int*)0x5B))

volatile int i;


void GPIO_init()
{
	DDRB_REG &=~(1<<2); // set B2 input
	DDRD_REG &=~((1<<2)|(1<<3)); // set D2&3 input
	DDRD_REG |=(1<<5)|(1<<6)|(1<<7);//set D5,6,7 as output
	PORTB_REG &=~(1<<2); // pull-up resistor off
	PORTD_REG &=~((1<<2)|(1<<3)); //pull-up resistor off
}

int main(void)
{
    GPIO_init();
	MCUCR_REG |=((1<<3)|(1<<2)); // rising edge interrupt 1;
	// Any logical change on INT0 generates an interrupt request.
	MCUCR_REG |=(1<<0);
	MCUCR_REG &=~(1<<1);
	MCUCSR_REG &=~(1<<6); //falling edge on INT2 activates
	GICR_REG |=((1<<5)|(1<<6)|(1<<7));//External Interrupt Request 0&1&2 Enable
	//Global Interrupt Enable
	sei();
    while (1) 
    {
		PORTD_REG &=~(1<<5);
		PORTD_REG &=~(1<<6);
		PORTD_REG &=~(1<<7);
		_delay_ms(1000);
    }
	return 0;
}

ISR(INT0_vect)
{
	PORTD_REG |=1<<5;
	_delay_ms(1000);
		
}

ISR(INT1_vect)
{
	PORTD_REG |=1<<6;
	_delay_ms(1000);

}
ISR(INT2_vect)
{
	PORTD_REG |=1<<7;
	_delay_ms(1000);
}

