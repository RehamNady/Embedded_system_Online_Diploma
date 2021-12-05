/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: reham
 *      store information of a student usong structure
 */

#include<stdio.h>

struct Sstudent{
	char name[50];
	int roll;
	float marks;
};
int main(){
	struct Sstudent S;
	printf("Enter information of students:\n");
	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	fgets(S.name,50,stdin);
	printf("Enter roll number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&S.roll);
	printf("Enter marks: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&S.marks);
	printf("\nDisplaying information\n");
	printf("name: %s",S.name);
	printf("Roll: %d",S.roll);
	printf("Marks: %.2f",S.marks);


	return 0;

}
