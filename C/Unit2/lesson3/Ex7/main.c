/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Swap Two Numbers without temp variable.
 */

#include <stdio.h>
int main(){
	float a,b;
	printf("Enter value of a:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swapping, value of a = %f \nAfter swapping, value of b = %f",a,b);
	return 0;
}

