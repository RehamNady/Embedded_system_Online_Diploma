/*
 * main.c
 *
 *  Created on: Jan 11, 2022
 *      Author: reham
 */


#include "ca.h"
#include"US.h"
#include "DC_motor.h"
void setup()
{
	//init all the drivers
	//init IRQ
	//init HAL us_driver
	//init block
	//set states pointers for each block
	DC_init();
	US_init();
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_Reading);
	DC_state = STATE(DC_Idle);

}
int main()
{ volatile int d=0;
setup();
while(1){
	//call state for each block
	US_state();
	CA_state();
	DC_state();
	//delay
	for(d=0;d<=1000;d++);
}
return 0;
}
