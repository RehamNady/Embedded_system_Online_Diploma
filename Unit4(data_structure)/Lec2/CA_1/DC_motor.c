/*
 * DC.c
 *
 *  Created on: Jan 11, 2022
 *      Author: reham
 */
#include "DC_motor.h"
//variables
int DC_speed =0;

// state pointer to func
void(*DC_state)();
void DC_init(){
	// init pwm
	Dprintf("DC_init \n");
}
void DC_motor(int s){
	DC_speed=s;
	DC_state=STATE(DC_Busy);
	Dprintf("CA--------speed=%d------>DC\n",DC_speed);
}
STATE_define(DC_Idle){
	//state name
	DC_state_id state_id = DC_Idle;
	//state action
	//call pwm to make speed = dc_speed

	Dprintf("DC_idle state: speed=%d\n",DC_speed);

}

STATE_define(DC_Busy){
	//state name
	DC_state_id state_id= DC_Busy;
	//state action
	//call pwm to make speed = dc_speed

	Dprintf("DC_Busy state: speed=%d\n",DC_speed);
	DC_state=STATE(DC_Idle);

}
