/*
 * fifo.c
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */

#include "fifo.h"

FIFO_Status FIFO_init(FIFO_BUF_t* fifo_buffer,unsigned int length,element_type* buffer){
	if(!FIFO_is_exist(fifo_buffer))
		return FIFO_Null;

	fifo_buffer->Base=buffer;
	fifo_buffer->Head=buffer;
	fifo_buffer->tail=buffer;
	fifo_buffer->length=length;
	fifo_buffer->count=0;
	return FIFO_no_error;
}
FIFO_Status FIFO_enqueue(FIFO_BUF_t* fifo_buffer,element_type item){

	if(FIFO_is_exist(fifo_buffer)== FIFO_Null)
		return FIFO_Null;
	if(FIFO_is_full(fifo_buffer))
		return  FIFO_full;
	*(fifo_buffer->Head)=item;
	fifo_buffer->count++;
	if(fifo_buffer->Head==fifo_buffer->Base+fifo_buffer->length)
		fifo_buffer->Head=fifo_buffer->Base;
	else
		fifo_buffer->Head++;
	return FIFO_no_error;

}
FIFO_Status FIFO_dequeue(FIFO_BUF_t* fifo_buffer,element_type* item){
	if(FIFO_is_exist(fifo_buffer)== FIFO_Null)
		return FIFO_Null;
	if(FIFO_is_empty(fifo_buffer))
		return  FIFO_empty;
	*item=*(fifo_buffer->tail);
	fifo_buffer->count--;
	if(fifo_buffer->tail==fifo_buffer->Base+fifo_buffer->length)
		fifo_buffer->tail=fifo_buffer->Base;
	else
		fifo_buffer->tail++;
	return FIFO_no_error;

}

void FIFO_print(FIFO_BUF_t *fifo_buffer){
	if(!FIFO_is_exist(fifo_buffer))
		printf("fifo is not initialize \n");
	else if(FIFO_is_empty(fifo_buffer))
		printf("FIFO is empty\n");
	else{
		int i;
		element_type* temp;
		temp = fifo_buffer->tail;
		for(i=0;i<fifo_buffer->count;i++){
			printf("%d- %d\n",i+1,*temp);
			if(temp==fifo_buffer->Base+fifo_buffer->length)
				temp=fifo_buffer->Base;
			else
				temp++;
		}
	}
}

int FIFO_is_exist(FIFO_BUF_t* fifo_buffer){
	if(!fifo_buffer->Base || !fifo_buffer->Head || !fifo_buffer->tail)
		return 0;
	return 1;
}
FIFO_Status FIFO_is_full(FIFO_BUF_t* fifo_buffer){
	if(!FIFO_is_exist(fifo_buffer))
		return FIFO_Null;
	if(fifo_buffer->count >= fifo_buffer->length)
		return FIFO_full;
	return FIFO_no_error;
}
FIFO_Status FIFO_is_empty(FIFO_BUF_t* fifo_buffer){
	if(!FIFO_is_exist(fifo_buffer))
		return FIFO_Null;
	if(fifo_buffer->count == 0)
		return FIFO_empty;
	return FIFO_no_error;
}

