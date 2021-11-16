/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Simple Calculator to Add,subtract,multiply or divide two operands
 *
 */

#include <stdio.h>

int main(){
	float num1,num2;
	char op;
	printf("Enter operator either + or - or * or / :");
	fflush(stdin);fflush(stdout);
	scanf("%c",&op);
	printf("Enter two operands: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&num1,&num2);
	switch(op){
	case'+':
	{
		printf("%f + %f =%f",num1,num2,num1+num2);
	}
	break;
	case'-':
	{
		printf("%f - %f =%f",num1,num2,num1-num2);
	}
	break;
	case'*':
	{
		printf("%f * %f =%f",num1,num2,num1*num2);
	}
	break;
	case'/':
	{
		printf("%f / %f =%f",num1,num2,num1/num2);
	}
	break;
	default:
	{
		printf("\n Check your sign");
	}
	break;
	}

	return 0;
}


