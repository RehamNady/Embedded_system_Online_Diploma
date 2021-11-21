/*
 * main.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      Multidimensional Array
 *      sum of 2 matrix of order 2*2
 */
#include <stdio.h>
int main(){
	int i,j;
	float a[2][2],sum[2][2];
	float b[2][2];
	for(i=0;i<4;i++){
		for(j=0;j<2;j++){
			if(i<2){
				if((i==0)&&(j==0)){
					printf("Enter the elements of 1st matrix \n");
				}
				printf("Enter a%d%d",i+1,j+1);
				fflush(stdin);fflush(stdout);
				scanf("%f",&a[i][j]);
			}
			else{
				if((i==2)&&(j==0)){
					printf("Enter the elements of 2nd matrix \n");
				}
				printf("Enter b%d%d",i-1,j+1);
				fflush(stdin);fflush(stdout);
				scanf("%f",&b[i-2][j]);
			}
		}
	}
	printf("Sum of Matrix:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			sum[i][j]=a[i][j]+b[i][j];
			printf("%.1f\t",sum[i][j]);

		}
		printf("\n");
	}

	return 0;
}


