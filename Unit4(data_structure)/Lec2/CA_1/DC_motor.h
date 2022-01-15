/*
 * DC.h
 *
 *  Created on: Jan 11, 2022
 *      Author: reham
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
#include<stdio.h>
#include<stdlib.h>
#define Dprintf(...) {fflush(stdin);\
				 fflush(stdout);\
				 printf(__VA_ARGS__);\
				 fflush(stdin);\
				 fflush(stdout);}

typedef enum{
	DC_Idle,
	DC_Busy
}DC_state_id;
extern void(*DC_state)();

STATE_define(DC_Idle);
STATE_define(DC_Busy);
void DC_init();


#endif /* DC_H_ */
