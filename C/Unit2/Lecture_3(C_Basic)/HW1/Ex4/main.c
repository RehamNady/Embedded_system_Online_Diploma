/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Multiply two Floating Point Numbers
 */
#include <stdio.h>
int main (){
	float num1,num2;
	printf("Enter two numbers:");
	fflush(stdout);
	fflush(stdin);
	scanf("%f %f",&num1,&num2);
	printf("Sum: %f",num1*num2);
	return 0;

}

