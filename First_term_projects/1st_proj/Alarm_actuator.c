#include"Alarm_actuator.h"
void(*Alarm_state)() ;
void stop_alarm(){
  Alarm_state=State(Alarm_Stop);
}
void start_alarm(){
  Alarm_state=State(Alarm_Start);
}
void Alarm_init(){
  Set_Alarm_actuator(1);
}
State_define(Alarm_Waiting){
  Alarm_id = Alarm_Waiting;
}
State_define(Alarm_Start){
  Alarm_id = Alarm_Start;
  Set_Alarm_actuator(0);
  Alarm_state=State(Alarm_Waiting);
}
State_define(Alarm_Stop){
  Alarm_id = Alarm_Stop;
  Set_Alarm_actuator(1);
  Alarm_state=State(Alarm_Waiting);
}
