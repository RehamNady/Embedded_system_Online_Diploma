#include"Alarm_monitor.h"
void(*MONITOR_alarm_state)();
int period_alarm=0;

void set_alarm(int period){
  period_alarm=period;
  MONITOR_alarm_state=State(Alarm_ON);
}

State_define(Check){
  MONITOR_alarm_id=Check;
}

State_define(Alarm_Monitor_Waiting){
  MONITOR_alarm_id=Alarm_Monitor_Waiting;
  Delay(period_alarm);
  MONITOR_alarm_state=State(Alarm_OFF);
}
State_define(Alarm_ON){
  MONITOR_alarm_id=Alarm_ON;
  start_alarm();
  MONITOR_alarm_state=State(Alarm_Monitor_Waiting);
}
State_define(Alarm_OFF){
  MONITOR_alarm_id=Alarm_OFF;
  stop_alarm();
  MONITOR_alarm_state=State(Check);
}
