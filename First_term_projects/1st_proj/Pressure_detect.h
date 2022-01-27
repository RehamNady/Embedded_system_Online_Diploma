#ifndef PRESSURE_DETECT_H_
#define PRESSURE_DETECT_H_
#include"state.h"
extern void(*Pdetect_state)();
enum {
  Busy,
  High_P_detect
}Pressure_detect_id;

State_define(Busy);
State_define(High_P_detect);


#endif
