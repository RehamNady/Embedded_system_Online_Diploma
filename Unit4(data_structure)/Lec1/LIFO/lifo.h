/*
 * lifo.h
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>

#define element_type unsigned int

typedef struct {
	unsigned count ;
	unsigned int length ;
	element_type * Base;
	element_type *Head;
}LIFO_BUF_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_Status;

LIFO_Status LIFO_init(LIFO_BUF_t* lifo_buffer,unsigned int length,element_type* buffer);
LIFO_Status LIFO_ADD_item(LIFO_BUF_t* lifo_buffer,element_type item);
LIFO_Status LIFO_GET_item(LIFO_BUF_t* lifo_buffer,element_type* item);
void LIFO_print(LIFO_BUF_t *lifo_buffer);

int LIFO_is_exist(LIFO_BUF_t* lifo_buffer);
LIFO_Status LIFO_is_full(LIFO_BUF_t* lifo_buffer);
LIFO_Status LIFO_is_empty(LIFO_BUF_t* lifo_buffer);

#endif /* LIFO_H_ */
