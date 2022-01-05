#include"uart.h"

unsigned char buffer[100]="learn-in-depth:Reham Nady";
 int main() {
  uart_send(buffer);
  return 0;
}
