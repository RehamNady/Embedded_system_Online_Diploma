/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Code to Swap Two Numbers using temp variable
 */

#include <stdio.h>
int main(){
	float a,b;
	float temp;
	printf("Enter value of a:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	temp = a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %f \nAfter swapping, value of b = %f",a,b);
	return 0;
}

