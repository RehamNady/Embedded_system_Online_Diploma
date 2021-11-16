/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Calculate sum of natural number displsay the value of 1+2+3....+n
 *
 */
#include <stdio.h>
int main(){
	unsigned int n,i=0,sum=0;

	printf("Enter an integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=1;i<=100;i++){
		sum +=i;
	}
	printf("Sum = %d",sum);
	return 0;
}

