/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Find Factorial of a number
 */

#include <stdio.h>

int main(){
	int n,i=0,fact;
	printf("Enter an integer :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	fact=n;
	if (n>0){
		for(i=n-1;i>0;i--){
			fact*=i;
		}
		printf("Factorial = %d",fact);
	}
	else if(n==0){
		printf("Factorial = 1");
	}
	else{
		printf("Error!!! Factorial of negative number doesn't exist.");
	}
	return 0;
}

