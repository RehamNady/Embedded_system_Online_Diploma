/*
 * US.h
 *
 *  Created on: Jan 11, 2022
 *      Author: reham
 */

#ifndef US_H_
#define US_H_

#include "state.h"
#include<stdio.h>
#include<stdlib.h>
#define Dprintf(...) {fflush(stdin);\
				 fflush(stdout);\
				 printf(__VA_ARGS__);\
				 fflush(stdin);\
				 fflush(stdout);}

typedef enum{
	US_Reading

}US_state_id;
extern void(*US_state)();

STATE_define(US_Reading);
void US_init();


#endif /* US_H_ */
