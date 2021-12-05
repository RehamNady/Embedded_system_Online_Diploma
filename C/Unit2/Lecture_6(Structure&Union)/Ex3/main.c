/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: reham
 *      add two complex number
 */
#include<stdio.h>
struct Scomplex{
	float real;
	float imag;
};
struct Scomplex Enter_num(int n,char s[]);
struct Scomplex Add(struct Scomplex x ,struct Scomplex y);
int main(){
	struct Scomplex x,y,z;
	x=Enter_num(1,"st");
	y=Enter_num(2,"nd");
	z=Add(x,y);
	printf("sum=%.1f+%.1fi",z.real,z.imag);
	return 0;
}
struct Scomplex Enter_num(int n,char s[]){
	struct Scomplex x;
	printf("for %d%s complex number\n",n,s);
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&x.real,&x.imag);
	return x;
}
struct Scomplex Add(struct Scomplex x ,struct Scomplex y){
	struct Scomplex z;
	z.real=x.real+y.real;
	z.imag=x.imag+y.imag;
	return z;
}
