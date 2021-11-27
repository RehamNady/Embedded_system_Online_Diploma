/*
 * main.c
 *
 *  Created on: Nov 27, 2021
 *      Author: reham
 *      Reverse sentence using recursion
 */
#include<stdio.h>
#include<string.h>
void rev_sen(char arr[],int n);

int main(){
	char arr[100];
	printf("Enter a sentence: ");
	fflush(stdin);fflush(stdout);
	gets(arr);
	rev_sen(arr,strlen(arr)-1);
	return 0;
}
void rev_sen(char arr[],int n){
	printf("%c",arr[n]);
	if(n>0){
		rev_sen(arr,n-1);
	}


}
