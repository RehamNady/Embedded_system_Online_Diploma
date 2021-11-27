/*
 * main.c
 *
 *  Created on: Nov 24, 2021
 *      Author: reham
 *      factorial using recursion
 */

#include <stdio.h>
int factorial(int a);
int main (){
	int n,fact;
	printf("Enter a positive number:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	if(n>0){
	fact=factorial(n);
	printf("Factorial of %d = %d",n,fact);
	}
	else
	{
		printf("please enter a positive number");
	}
	return 0;
}
int factorial(int a){
	if (a!=1)
		return a*factorial(a-1);
	else
		return 1;
}
