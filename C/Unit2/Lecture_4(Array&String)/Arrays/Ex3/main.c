/*
 * main.c
 *
 *  Created on: Nov 21, 2021
 *      Author: reham
 *      Transpose of matrix
 */

#include<stdio.h>
int main(){
	float mat[10][10];
	int n,k,i,j;
	printf("Enter rows and columns of matrix:");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&n,&k);
	printf("Enter elements of matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			printf("Enter elements a%d%d: ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%f",&mat[i][j]);
		}
	}
	printf("Entered Matrix\n");
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			printf("%f ",mat[i][j]);
		}
		printf("\n");
	}
	printf("Transpose of Matrix\n");
		for(i=0;i<k;i++){
			for(j=0;j<n;j++){
				printf("%f ",mat[j][i]);
			}
			printf("\n");
		}
	return 0;
}

