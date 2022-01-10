/*
 * main.c
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */

#include "lifo.h"

element_type buffer1[5];

int main(){
	int i;
	unsigned int temp=0;
	LIFO_BUF_t uart_lifo,I2C_lifo;
	LIFO_init(&uart_lifo, sizeof(buffer1)/sizeof(element_type), buffer1);

	element_type *buffer2=(element_type *)malloc(5*sizeof(element_type));

	LIFO_init(&I2C_lifo, 5, buffer2);
	printf("\n=============ADD UART LIFO ITEMs=============\n");
	for(i=0;i<7;i++){
		if(LIFO_ADD_item(&uart_lifo, i)== LIFO_no_error)
			printf("UART_LIFO add : %d\n",i);
		else if(LIFO_ADD_item(&uart_lifo, i)== LIFO_full)
			printf("Uart_LIFO is FULL \n");
		else
			printf("Uart_lifo is not initialize \n");

	}
	printf("\n=============ADD I2C LIFO ITEMs=============\n");
	for(i=10;i<17;i++){
		if(LIFO_ADD_item(&I2C_lifo, i)== LIFO_no_error)
			printf("I2C_LIFO add : %d\n",i);
		else if(LIFO_ADD_item(&I2C_lifo, i)== LIFO_full)
			printf("I2C_LIFO is FULL \n");
		else
			printf("I2C_lifo is not initialize \n");

	}
	printf("\n=============UART LIFO ITEMs=============\n");
	LIFO_print(&uart_lifo);
	printf("\n=============I2C LIFO ITEMs=============\n");
	LIFO_print(&I2C_lifo);
	printf("\n=============PULL UART LIFO ITEMs=============\n");

	for(i=0;i<7;i++){
		if(LIFO_GET_item(&uart_lifo, &temp)== LIFO_no_error)
			printf("UART_LIFO get : %d\n",temp);
		else if(LIFO_GET_item(&uart_lifo, &temp)== LIFO_empty)
			printf("Uart_LIFO is EMPTY \n");
		else
			printf("Uart_lifo is not initialize \n");

	}
	printf("\n=============PULL I2C LIFO ITEMs=============\n");
	for(i=0;i<7;i++){
		if(LIFO_GET_item(&I2C_lifo, &temp)== LIFO_no_error)
			printf("I2C_LIFO get : %d\n",temp);
		else if(LIFO_GET_item(&I2C_lifo, &temp)== LIFO_empty)
			printf("I2C_LIFO is EMPTY \n");
		else
			printf("I2C_lifo is not initialize \n");

	}
	return 0;
}
