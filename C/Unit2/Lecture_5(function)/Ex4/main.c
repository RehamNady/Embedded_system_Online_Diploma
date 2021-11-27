/*
 * main.c
 *
 *  Created on: Nov 27, 2021
 *      Author: reham
 *      Power of number using recursion
 */

#include<stdio.h>
float power(float a,int b);
float power_neg(float a,int b);
int main(){
	float a,result;
	int pow;
	printf("Enter base number: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&a);
	printf("Enter power number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&pow);
	if(pow>0){
		result=power(a,pow);

	}
	else{
		result=power_neg(a,pow);
	}
	printf("%f^%d=%f",a,pow,result);
	return 0;
}
float power(float a,int b){
	if(b!=0){
		return a*power(a,b-1);
	}
	else
		return 1;
}
float power_neg(float a,int b){
	if(b!=0){
		return (1/a)*power_neg(a,b+1);
	}
	else
		return 1;
}
