#ifndef MONITOR_alarm_MONITOR_H_
#define MONITOR_alarm_MONITOR_H_
#include"state.h"
extern void(*MONITOR_alarm_state)();
enum {
  Check,
  Alarm_ON,
  Alarm_Monitor_Waiting,
  Alarm_OFF
}MONITOR_alarm_id;

State_define(Check);
State_define(Alarm_Monitor_Waiting);
State_define(Alarm_ON);
State_define(Alarm_OFF);

#endif
