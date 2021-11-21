/*
 * main.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      Frequency of characters in a string
 */
#include<stdio.h>
#include<conio.h>
int main(){
	char str[50],ch;
	int i,sum=0;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
    gets(str);
    printf("Enter a character to find frequency: ");
    fflush(stdin);fflush(stdout);
    scanf("%c",&ch);
        for(i=0;(i<sizeof(str))&&(str[i]!=0);i++){
    	if(ch==str[i]){
    		sum++;
    	}
    }
    printf("frequency of %c = %d",ch,sum);
	return 0;
}

