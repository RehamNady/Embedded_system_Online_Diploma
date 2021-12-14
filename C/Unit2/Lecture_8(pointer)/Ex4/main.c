/*
 * main.c
 *
 *  Created on: Dec 10, 2021
 *      Author: reham
 *      print the elements of an array in reverse order
 */
#include<stdio.h>
void Enter_arr(int *a,int n);
void rev_arr(int *pa,int *pr,int n);
int main(){
	int a[15],n;
	int *pa=a,*prv=(int*)0;
	printf("number of elements to store in array(max 15):");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	Enter_arr(pa,n);
    rev_arr(pa,prv,n);
}

void Enter_arr(int* a,int n){
	int i;
	printf("input %d number of elemnts in the array:\n",n);
	for(i=0;i<n;i++){
		printf("element -%d :",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",a+i);

	}
}
void rev_arr(int *pa,int *pr,int n){
	int i;
	pr=pa+n-1;
	for(i=n-1;i>=0;i--){
		printf("element -%d : %d\n",i+1,*pr);
		pr--;
	}
}
