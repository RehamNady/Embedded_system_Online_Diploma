/*
 * main.c
 *
 *  Created on: Dec 10, 2021
 *      Author: reham
 *      print a string in reverse using pointer
 */
#include<stdio.h>
#include<string.h>
int main(){
	char arr[50];
	char *ps=arr;
	int i=0;
	printf("Input a string : ");
	fflush(stdin);fflush(stdout);
	gets(arr);
	for(i=strlen(arr)-1;i>=0;i--){
		printf("%c",*(ps+i));

	}
	return 0;
}

