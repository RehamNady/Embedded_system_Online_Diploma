/*
 * fifo.h
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include <stdlib.h>

#define element_type unsigned int

typedef struct {
	unsigned count ;
	unsigned int length ;
	element_type * Base;
	element_type *Head;
	element_type *tail;
}FIFO_BUF_t;

typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null
}FIFO_Status;

FIFO_Status FIFO_init(FIFO_BUF_t* fifo_buffer,unsigned int length,element_type* buffer);
FIFO_Status FIFO_enqueue(FIFO_BUF_t* fifo_buffer,element_type item);
FIFO_Status FIFO_dequeue(FIFO_BUF_t* fifo_buffer,element_type* item);
void FIFO_print(FIFO_BUF_t *fifo_buffer);

int FIFO_is_exist(FIFO_BUF_t* fifo_buffer);
FIFO_Status FIFO_is_full(FIFO_BUF_t* fifo_buffer);
FIFO_Status FIFO_is_empty(FIFO_BUF_t* fifo_buffer);


#endif /* FIFO_H_ */
