#ifndef STATE_H_
#define STATE_H_
#include"driver.h"

#define State_define(_State_Fun) void ST_##_State_Fun()
#define State(_State_Fun) ST_##_State_Fun

void stop_alarm();
void start_alarm();
void set_alarm(int period);
void send_pressure(int pressure);
#endif
