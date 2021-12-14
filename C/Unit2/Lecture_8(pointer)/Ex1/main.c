/*
 * main.c
 *
 *  Created on: Dec 9, 2021
 *      Author: reham
 *      handle the pointers
 */
#include<stdio.h>
int main(){
	int m,*pm;
	m=29;
	printf("address of m : 0x%x \nvalue of m : %d\n\n",(unsigned int)&m,m);
	pm=&m;
	printf("ab is assigned with the address of m\n");
	printf("address of pointer ab : 0x%x \ncontent of pointer ab : %d\n\n",(unsigned int)pm,*pm);
	m=34;
	printf("the value of m assigned to 34 now\n");
	printf("address of pointer ab : 0x%x \ncontent of pointer ab : %d\n\n",(unsigned int)pm,*pm);
	*pm=7;
	printf("the pointer variable ab is assigned with value 7 now\n");
	printf("address of m : 0x%x \nvalue of m : %d\n\n",(unsigned int)&m,m);

	return 0;
}
