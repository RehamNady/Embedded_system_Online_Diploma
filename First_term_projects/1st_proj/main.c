#include"Alarm_actuator.h"
#include"Alarm_monitor.h"
#include"driver.h"
#include"P_sensor.h"
#include"Pressure_detect.h"

void setup(){
  GPIO_INITIALIZATION ();
  Alarm_init();
  PSensor_init();
  PSensor_state=State(Reading);
  Pdetect_state=State(Busy);
  MONITOR_alarm_state=State(Check);
  Alarm_state=State(Alarm_Waiting);

}
int main(){
  setup();
  while(1){
    PSensor_state();
    Pdetect_state();
    MONITOR_alarm_state();
    Alarm_state();
    Delay(100);
  }
}
