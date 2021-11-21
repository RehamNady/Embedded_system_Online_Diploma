/*
 * main.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      calculate average using array
 *
 */
#include <stdio.h>
int main(){
	float numbers[10],average=0;
	int n,i;
	printf("Enter the numbers of data: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("%d. Enter number: ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&numbers[i]);
		average+=numbers[i];
	}
	average/=n;
	printf("Average = %.2f",average);

	return 0;
}

