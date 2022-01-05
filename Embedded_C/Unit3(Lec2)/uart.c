
#include"uart.h"

void uart_send(unsigned char*p_tx_str){
  while(*p_tx_str ){
    UART0DR = (unsigned int )*p_tx_str;
    p_tx_str++;
  }
}
