/*
 * main.c
 *
 *  Created on: Dec 5, 2021
 *      Author: reham
 *      Store information of 10 Students
 */
#include<stdio.h>
typedef struct {
	char name[50];
	int roll;
	float marks;
}Sstudent;

int main(){
	Sstudent students[10];
	int count=0;
	printf("Enter information of students:\n");
	do {
		printf("for roll number:");
		fflush(stdin);fflush(stdout);
		scanf("%d",&students[count].roll);
		printf("Enter name:");
		fflush(stdin);fflush(stdout);
		fgets(students[count].name,50,stdin);
		printf("Enter marks:");
		fflush(stdin);fflush(stdout);
		scanf("%f",&students[count].marks);
		count++;

	}while(count<10);
	printf("Displaying information of students:\n");
	count=0;
	do {
		printf("information for roll number %d:\n",students[count].roll);
		printf("Name:%s",students[count].name);
		printf("Marks: %f\n",students[count].marks);
		count++;
	}while(count<10);
		return 0;
	}
