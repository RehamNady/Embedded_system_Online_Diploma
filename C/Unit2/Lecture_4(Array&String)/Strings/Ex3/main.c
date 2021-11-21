/*
 * main.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      Reverse string
 */

#include<stdio.h>
#include<string.h>
int main(){
	int i;
	char str[15];
	printf("Enter the string : ");
	fflush(stdin);fflush(stdout);
	gets(str);
	printf("Reverse string is : ");
	for(i=strlen(str);i>0;i--){
		printf("%c",str[i-1]);
	}
	return 0;
}
