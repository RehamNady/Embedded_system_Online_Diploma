/*
 * main.c
 *
 *  Created on: Dec 10, 2021
 *      Author: reham
 *      show a pointer to an array which contents are pointer to structure
 *      struct *(*a)[]
 */
#include<stdio.h>
struct Semployee{
	char Name[20];
	int ID;
};
int main(){
	int i=0;
	struct Semployee data[5]={
			{"reham nady",1000},
			{"hossam eldeen",1001},
			{"Alex",1002},
			{"waly eldeen",1003},
			{"john",1004}
	};
	struct Semployee** pa;
	struct Semployee* a[5];
	for(i=0;i<5;i++){
		a[i]=&data[i];
	}

	pa=a;
	for(i=0;i<5;i++){
		printf("Employee Name:%s\n",(*pa)->Name);
		printf("Employee ID: %d\n\n",(*pa)->ID);
		pa++;
	}
	return 0;
}
