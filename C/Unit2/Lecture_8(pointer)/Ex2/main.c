/*
 * main.c
 *
 *  Created on: Dec 10, 2021
 *      Author: reham
 *      print all the alphabets using a pointer
 */
#include<stdio.h>
int main(){
	char c='A';
	char *ps=&c;
	int i;
	printf("The Alphabets are : \n");
	for(i=0;i<26;i++){
		printf("%c ",*ps+i);
	}
	return 0;
}


