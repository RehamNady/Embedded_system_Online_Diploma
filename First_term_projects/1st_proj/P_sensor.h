#ifndef P_SENSOR_H_
#define P_SENSOR_H_
#include"state.h"
extern void(*PSensor_state)();
enum {
  Reading,
  PSensor_Waiting
}PSensor_id;

void PSensor_init();
State_define(PSensor_Waiting);
State_define(Reading);


#endif
