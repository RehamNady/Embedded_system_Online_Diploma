/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Find ASCII Value of a Character
 *
 */


#include <stdio.h>
int main(){
	char ch;
	printf("Enter a character:");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&ch);
	printf("ASCII value of G = %d",ch);
	return 0;
}
