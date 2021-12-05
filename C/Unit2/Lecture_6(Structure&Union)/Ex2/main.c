/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: reham
 *      Add 2 distance in (inch-feet)
 */
#include<stdio.h>
struct Sunits{
	float inch;
	int feet;
};
struct Sunits Enter_info(int n);
struct Sunits Add(struct Sunits x,struct Sunits y);
int main(){
	struct Sunits x,y,z;
	x=Enter_info(1);
	y=Enter_info(2);
	z= Add(x,y);
	printf("\n Sum of distances= %d\'-%.1f\"",z.feet,z.inch);
}
struct Sunits Enter_info(int n){
	struct Sunits x;
	printf("Enter information for %d distance\n",n);
	printf("Enter feet:");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x.feet);
	printf("Enter inch:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&x.inch);
	return x;
}
struct Sunits Add(struct Sunits x,struct Sunits y){
	struct Sunits z;
	z.feet=x.feet+y.feet;
	z.inch=x.inch+y.inch;
	if(z.inch>12.0){
		z.inch-=12;
		z.feet++;
	}
	return z;
}
