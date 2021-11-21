/*
 * man.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      Find the length of string
 */
#include<stdio.h>
int main(){
	int len=0,i;
	char arr[20];
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(arr);
	for(i=0;(i<sizeof(arr))&&(arr[i]!=0);i++){
		len++;
	}
	printf("Length of string: %d",len);
	return 0;
}

