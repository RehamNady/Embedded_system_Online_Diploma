/*
 * ca.c
 *
 *  Created on: Jan 11, 2022
 *      Author: reham
 */
#include "ca.h"
//variables
int CA_speed =0;
int CA_distance=0;
int CA_threshold=50;

// state pointer to func
void(*CA_state)();

void US_set_distance(int d){
	CA_distance=d;
	(CA_distance <= CA_threshold)?(CA_state=STATE(CA_waiting)):(CA_state=STATE(CA_driving));
	Dprintf("US--------distance=%d------>CA\n",CA_distance);
}


STATE_define(CA_waiting){
	//state name
	CA_state_id state_id = CA_waiting;
	//state action

	Dprintf("CA_waiting state:distance =%d speed=%d\n",CA_distance,CA_speed);
	CA_speed=0;
	DC_motor(CA_speed);
	//DC_motor(ca_speed)

}

STATE_define(CA_driving){
	//state name
	CA_state_id state_id= CA_driving;
	//state action
	Dprintf("CA_driving state:distance =%d speed=%d\n",CA_distance,CA_speed);
	CA_speed=30;
	DC_motor(CA_speed);
	//DC_motor(ca_speed)
	//event check
	//US_get_distance(CA_distance)


}
