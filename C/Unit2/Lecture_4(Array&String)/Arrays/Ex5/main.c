/*
 * main.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      search an element in array
 */

#include<stdio.h>
int main(){
	int n,numb,arr[10];
	int i;
	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		arr[i]=(i+1)*10+(i+1);
		printf("%d ",arr[i]);
	}
	printf("\nEnter the elements to be searched : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&numb);
	for(i=0;i<n;i++){
		if(numb==arr[i]){
			printf("Number found at the location = %d\n",i+1);
			break;
		}
	}
	if(i==n){
		printf("sorry, number doesn't find in array\n");
	}
	return 0;
}
