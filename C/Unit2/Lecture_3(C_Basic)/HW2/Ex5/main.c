/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      check whether a character is alphabet or not
 */
#include <stdio.h>
int main(){
	char ch;
	int i;
	printf("Enter a character : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	i=(int)ch;
	if(((i>64) &&(i<91))||((i>96) &&(i<123))){
		printf("%c is an alphabet\n",ch);
	}
	else{
		printf("%c is not an alphabet\n",ch);
	}

	return 0;
}

