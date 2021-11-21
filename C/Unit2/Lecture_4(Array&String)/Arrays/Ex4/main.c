/*
 * main.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      Insert an element in an array
 */

#include<stdio.h>
int main(){
	int n,arr[10],i,temp,temp2,numb,loc;
	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		arr[i]=i+1;
		printf("%d ",arr[i]);
	}
	printf("\nEnter the element to be inserted : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&numb);
	printf("Enter the location : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&loc);
	temp=arr[loc-1];
	for(i=loc;i<=n;i++){
		temp2=arr[i];
		arr[i]=temp;
		temp=temp2;
	}
	arr[loc-1]=numb;
	for(i=0;i<=n;i++){
		printf("%d ",arr[i]);
	}


	return 0;
}
