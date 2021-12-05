/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: reham
 *      Difference between struc & union
 */
#include<stdio.h>
union job{
	char name[32];
	float salary;
	int worker_no;
}U;
struct job1{
	char name[32];
	float salary;
	int worker_no;
}S;
int main(){
	printf("size of union= %d\n",sizeof(U));
	printf("size of struct= %d",sizeof(S));
	return 0;
}
