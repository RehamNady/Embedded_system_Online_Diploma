#ifndef _UART_H_
#define _UART_H_

#define UART0DR (*((volatile unsigned int*)0x101f1000))

void uart_send(unsigned char*p_tx_str);

#endif
