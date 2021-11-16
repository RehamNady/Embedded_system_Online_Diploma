/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Check whether a number is positive or negative
 */

#include <stdio.h>
int main(){
	float num;
	printf("Enter a number:");
	fflush(stdout); fflush(stdin);
	scanf("%f",&num);
	if (num>0){
		printf("%f is positive\n",num);
	}
	else if(num <0){
		printf("%f is negative\n",num);
	}
	else
	{
		printf("%f you entered zero\n",num);
	}
	return 0;
}
