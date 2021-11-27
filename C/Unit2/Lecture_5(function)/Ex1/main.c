/*
 * main.c
 *
 *  Created on: Nov 24, 2021
 *      Author: reham
 *      prime numbers between two intervals
 */
int prime (int a);

#include <stdio.h>
int main ()
{ int a,b,i,f;
printf("Enter two numbers(intervals):");
fflush(stdin);fflush(stdout);
scanf("%d %d",&a,&b);
printf("prime Numbers between %d and %d are: ",a,b);
for (i=a;i<=b;i++){
	f=prime(i);
	if(f==0)
	{
		printf("%d ",i);
	}
}
return 0;
}
int prime (int a)
{
	int i,j=0;
	for(i=2;i<=(a/2);i++)
	{
		if(a%i==0)
		{
			j=1;
			break;
		}
	}
	return j;
}
