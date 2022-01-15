/*
 * US.c
 *
 *  Created on: Jan 11, 2022
 *      Author: reham
 */
#include "US.h"
//variables
int US_distance=0;

// state pointer to func
int US_Get_distance_random(int l,int r,int count);
void(*US_state)();

void US_init(){
	Dprintf("US_init\n");
}
STATE_define(US_Reading){
	volatile int i;
	//state name
	US_state_id state_id = US_Reading;
	//state action
	US_distance=US_Get_distance_random(45, 55, 1);

	//US_Set_distance(US_distance)
	Dprintf("US_Reading state:distance =%d \n",US_distance);
	US_set_distance(US_distance);
    for(i=0;i<100;i++);
	US_state=STATE(US_Reading);
}

int US_Get_distance_random(int l,int r,int count){
	int i;
	for(i=0;i<count;i++){
		int rand_num=(rand()%(r - l +1))+l;
		return rand_num;
	}
}
