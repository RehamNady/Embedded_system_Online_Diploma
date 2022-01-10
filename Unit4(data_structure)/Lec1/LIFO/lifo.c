/*
 * lifo.c
 *
 *  Created on: Jan 9, 2022
 *      Author: reham
 */


#include "lifo.h"


LIFO_Status LIFO_init(LIFO_BUF_t* lifo_buffer,unsigned int length,element_type* buffer){

	if(buffer == NULL)
		return LIFO_Null;

	lifo_buffer->Base = buffer;
	lifo_buffer->Head = buffer;
	lifo_buffer->length = length;
	lifo_buffer->count = 0;

	return LIFO_no_error;
}

LIFO_Status LIFO_ADD_item(LIFO_BUF_t* lifo_buffer,element_type item){

	if(!LIFO_is_exist(lifo_buffer))
		return LIFO_Null;

	if(LIFO_is_full(lifo_buffer)== LIFO_full)
		return LIFO_full;

	*(lifo_buffer->Head)=item;
	lifo_buffer->Head++;
	lifo_buffer->count++;
	return LIFO_no_error;


}
LIFO_Status LIFO_GET_item(LIFO_BUF_t* lifo_buffer,element_type* item){
	if(!LIFO_is_exist(lifo_buffer))
		return LIFO_Null;

	if(LIFO_is_empty(lifo_buffer)==LIFO_empty)
		return LIFO_empty;

	lifo_buffer->Head--;
	*item=*(lifo_buffer->Head);
	lifo_buffer->count--;
	return LIFO_no_error;

}
void LIFO_print(LIFO_BUF_t *lifo_buffer){
	element_type*temp;
	int i;
	if(!LIFO_is_exist(lifo_buffer))
			printf("lifo is not initialize \n");
	else if(LIFO_is_empty(lifo_buffer)==LIFO_empty)
			printf("LIFO is empty\n");
	else{
		temp=lifo_buffer->Head;
		temp--;
		for(i=0;i<lifo_buffer->count;i++){
			printf("%d- %d\n",i+1,*temp);
			temp--;
		}
	}

}

LIFO_Status LIFO_is_full(LIFO_BUF_t* lifo_buffer){
	if(!LIFO_is_exist(lifo_buffer))
		return LIFO_Null;
	/*if(lifo_buffer->Head >= lifo_buffer->Base+lifo_buffer->length) */
	if(lifo_buffer->count == lifo_buffer->length)
		return LIFO_full;
	return LIFO_no_error;
}
LIFO_Status LIFO_is_empty(LIFO_BUF_t* lifo_buffer){
	if(!LIFO_is_exist(lifo_buffer))
			return LIFO_Null;
	/*if(lifo_buffer->Head == lifo_buffer->Base) */
	if(lifo_buffer->count ==0)
		return LIFO_empty;
	return LIFO_no_error;
}
int LIFO_is_exist(LIFO_BUF_t* lifo_buffer){
	if(!lifo_buffer->Base || !lifo_buffer->Head)
		return 0;
	return 1;
}
