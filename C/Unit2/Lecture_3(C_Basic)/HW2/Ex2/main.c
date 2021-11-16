/*
 * main.c
 *
 *  Created on: Nov 16, 2021
 *      Author: reham
 *      Check alphabets is vowel or constant
 */


#include <stdio.h>
int main(){
	char ch;
	printf("Enter an alphabet: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	switch (ch){
	case'a':
	case'A':
	case'e':
	case'E':
	case'i':
	case'I':
	case'o':
	case'O':
	case'u':
	case'U':
	{
		printf("%c is Vowel.\n",ch);
	}
	break;
	default:
	{
		printf("%c is Constant.\n",ch);
	}
	break;
	}

	return 0;
}
