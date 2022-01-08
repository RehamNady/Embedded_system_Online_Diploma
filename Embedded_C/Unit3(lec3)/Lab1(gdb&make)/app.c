#include "uart.h"
unsigned char string_buff[100]="learn-in-depth:Reham Nady";
unsigned char string_buff2[100]="learn-in-depth:Reham Nady";

int const g[25]={1,2,100,5};
int main(void){

  uart_send_string(string_buff);/*uart_send_string(&string_buff[0])*/
  return 0;
}
