/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: reham
 *      Find area of circle using macros
 */
#include<stdio.h>

#define pi 3.1415
#define area_of_circle(r) (pi*r*r)
int main(){
	int r;
	float area;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&r);
	area=area_of_circle(r);
	printf("Area= %.2f",area);
	return 0;
}
