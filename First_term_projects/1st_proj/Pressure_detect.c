#include"Pressure_detect.h"

void(*Pdetect_state)();
int pressure_val;
int threshold = 20;
int alarm_period=60;
void send_pressure(int pressure){
  pressure_val=pressure;
  Pdetect_state=State(High_P_detect);
}
State_define(Busy){
  Pressure_detect_id=Busy;
}
State_define(High_P_detect){
  Pressure_detect_id=High_P_detect;
  if(pressure_val>=threshold){
    set_alarm(alarm_period);
  }
  Pdetect_state=State(Busy);


}
