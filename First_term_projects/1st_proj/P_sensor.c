#include"P_sensor.h"

int pressure;
void(*PSensor_state)();
void PSensor_init(){

}
State_define(PSensor_Waiting){
  PSensor_id=PSensor_Waiting;
  Delay(100);
  PSensor_state=State(Reading);
}
State_define(Reading){
  PSensor_id=Reading;
  pressure=getPressureVal();
  send_pressure(pressure);
  PSensor_state=State(PSensor_Waiting);
}
