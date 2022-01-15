/*
 * ca.h
 *
 *  Created on: Jan 11, 2022
 *      Author: reham
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"
#include<stdio.h>
#include<stdlib.h>
#define Dprintf(...) {fflush(stdin);\
				 fflush(stdout);\
				 printf(__VA_ARGS__);\
				 fflush(stdin);\
				 fflush(stdout);}

typedef enum{
	CA_waiting,
	CA_driving
}CA_state_id;
extern void(*CA_state)();

STATE_define(CA_waiting);
STATE_define(CA_driving);


#endif /* CA_H_ */
