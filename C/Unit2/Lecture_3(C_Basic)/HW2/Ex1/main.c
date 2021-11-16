/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Check whether a number is odd or even
 */
#include <stdio.h>
int main(){
	int numb_chk;
	printf("Enter an integer you want to check: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&numb_chk);
	if(!(numb_chk % 2)){
		printf("%d is Even",numb_chk);
	}
	else{
		printf("%d is Odd",numb_chk);
	}
	return 0;
}

