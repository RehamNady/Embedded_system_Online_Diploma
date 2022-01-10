/*
 * main.c
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */

#include "fifo.h"
element_type buffer1[5];
int main(){
	int i;
	element_type temp=0;
	FIFO_BUF_t FIFO_UART,FIFO_I2C;
	element_type* buffer2=(element_type*)malloc(5*sizeof(element_type));
	FIFO_init(&FIFO_UART, sizeof(buffer1)/sizeof(element_type), buffer1);
	FIFO_init(&FIFO_I2C, 5, buffer2);
	printf("\n=============ADD UART FIFO ITEMs=============\n");
	for(i=0;i<7;i++){
		if(FIFO_enqueue(&FIFO_UART, i)== FIFO_no_error)
			printf("UART_FIFO enqueue : %d\n",i);
		else if(FIFO_enqueue(&FIFO_UART, i)== FIFO_full)
			printf("fifo enqueue ------failed \n");
		else
			printf("Uart_fifo is not initialize \n");

	}
	printf("\n=============ADD I2C FIFO ITEMs=============\n");
	for(i=10;i<17;i++){
		if(FIFO_enqueue(&FIFO_I2C, i)== FIFO_no_error)
			printf("UART_FIFO enqueue : %d\n",i);
		else if(FIFO_enqueue(&FIFO_I2C, i)== FIFO_full)
			printf("fifo enqueue ------failed \n");
		else
			printf("Uart_fifo is not initialize \n");

	}
	printf("\n=============UART FIFO ITEMs=============\n");
	FIFO_print(&FIFO_UART);
	printf("\n=============I2C FIFO ITEMs=============\n");
	FIFO_print(&FIFO_I2C);


	printf("\n=============GET UART FIFO ITEMs=============\n");
	for(i=0;i<7;i++){
		if(FIFO_dequeue(&FIFO_UART, &temp)== FIFO_no_error)
			printf("UART_FIFO Enqueue : %d\n",temp);
		else if(FIFO_dequeue(&FIFO_UART, &temp)== FIFO_empty)
			printf("fifo dequeue  ------failed \n");
		else
			printf("Uart_fifo is not initialize \n");
	}

	printf("\n=============GET I2C FIFO ITEMs=============\n");
	for(i=0;i<7;i++){
		if(FIFO_dequeue(&FIFO_I2C, &temp)== FIFO_no_error)
			printf("UART_FIFO Enqueue : %d\n",temp);
		else if(FIFO_dequeue(&FIFO_I2C, &temp)== FIFO_empty)
			printf("fifo dequeue  ------failed \n");
		else
			printf("Uart_fifo is not initialize \n");
	}
	return 0;
}
