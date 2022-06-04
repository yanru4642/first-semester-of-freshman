#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAX 64

int main(void) {
	FILE* outp;
	outp = fopen("RESULT.txt", "w");
	int scale = 0;
	int matrix[MAX][MAX] = { 0 };
	int x = 0;	//row(¦C)
	int y = 0;	//column(¦æ)
	int fillnum = 1;	//
	int lyr = 0;	//layer
	int dir = 1;	//direction

	//input the scale of the matrix
	printf("Enter the scale of the matrix> ");
	scanf("%d", &scale);
	if (scale >= MAX) {
		printf("½d³ò¹L¤j");
		return (1);
	}

	//the first row
	for (int i = 0; i < scale; i++) {
		matrix[y][i] = fillnum;
		x = i;
		fillnum++;
	}

	//produce the matrix
	for (lyr = scale - 1; lyr >= 1; lyr--) {
		//y
		for (int j = 1; j <= lyr; j++) {
			y += dir;
			matrix[y][x] = fillnum;
			fillnum++;
		}
		//x
		for (int k = 0; k < lyr; k++) {
			x -= dir;
			matrix[y][x] = fillnum;
			fillnum++;
		}
		//change the direction
		dir *= -1;
	}

	//print the matrix
	printf("\n\n");
	for (int i = 0; i < scale; i++) {
		for (int j = 0; j < scale; j++) {
			printf("%3d ", matrix[i][j]);
			fprintf(outp, "%04d ", matrix[i][j]);
		}
		printf("\n");
		fprintf(outp, "\n");
	}

	fclose(outp);
	system("pause");
	return (0);
}


