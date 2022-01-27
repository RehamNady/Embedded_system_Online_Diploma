#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include"state.h"

extern void(*Alarm_state)();
enum {
  Alarm_Waiting,
  Alarm_Start,
  Alarm_Stop
}Alarm_id;

void Alarm_init();
State_define(Alarm_Waiting);
State_define(Alarm_Start);
State_define(Alarm_Stop);

#endif
