/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Find the Largest number among three Numbers
 */

#include <stdio.h>
int main(){
	float num1,num2,num3;
	printf("Enter three numbers:");
	fflush(stdin);fflush(stdout);
	scanf("%f %f %f",&num1,&num2,&num3);
	if(num1 > num2){
		if(num1>num3){
			printf("Largest number =%f",num1);
		}
		else{
			printf("Largest number =%f",num3);
		}
	}
	else{
		if(num2>num3){
			printf("Largest number =%f",num2);
		}
		else{
			printf("Largest number =%f",num3);
		}

	}

	return 0;
}
