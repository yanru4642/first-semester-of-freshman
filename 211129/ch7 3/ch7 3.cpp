#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 32

int fget_point_mass(int n, double arr[][3], double* ptr2);
void center_grav(double loc[][3], double mass[], int n, double center[]);
void fwrite_point_mass(double loc[][3], double mass[], int n, double center[]);

int main(void) {
	//declare variables
	int n = 0;	//number of points
	double loc[MAX][3];
	double mass[MAX]={0};
	double center[MAX]={0};

	//file I/O
	int status = 0;
	FILE* inp, *outp;
	inp = fopen("input.txt", "r");
	outp = fopen("output.txt", "w");



	//fget_point_mass
	n = fget_point_mass(10, loc, mass);

	//center_grav
	center_grav(loc, mass, n, center);

	//fwrite_point_mass
	fwrite_point_mass(loc, mass, n, center);
	

	fclose(inp);
	fclose(outp);
	system("pause");
	return (0);
}

int fget_point_mass(int n, double arr[][3], double* ptr2) {
	int temp_n;

	//file I/O
	int status = 0;
	FILE* inp, * outp;
	inp = fopen("input.txt", "r");
	outp = fopen("output.txt", "w");

	//scan number of points
	fscanf(inp, "%d", &temp_n);
	if (temp_n<3||temp_n>10){
		printf("Error. n should be between 3 to 10.\n");
		exit(1);
	}

	//store the location
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			status = fscanf(inp, "%lf", &arr[i][j]);
			if (status == EOF) {
				n = i;
				break;
			}
		}
		fscanf(inp, "%lf", &ptr2[i]);
		if (*(ptr2+i) < 0.0){
			printf("Error. Mass should be positive.\n");
			exit(1);
		}
	}

	return n;
}

void center_grav(double loc[][3], double mass[], int n, double center[]) {
	double totalMass = 0;
	//calculate total mass
	for (int i = 0; i < n; i++){
		totalMass += mass[i];
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < n; j++){
			center[i] += mass[j] * loc[j][i] / totalMass;
		}
	}

}

void fwrite_point_mass(double loc[][3], double mass[], int n, double center[]) {
	//file I/O
	int status = 0;
	FILE * outp;
	outp = fopen("output.txt", "w");

	//print the result
	fprintf(outp, "Location:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			fprintf(outp, "%.0lf  ", loc[i][j]);
		}
		fprintf(outp, "\n");
	}

	fprintf(outp, "\nmass:\n");
	for (int i = 0; i < n; i++) {
		fprintf(outp, "%.0lf\n", mass[i]);
	}

	fprintf(outp, "\nn: %d\n", n);

	fprintf(outp, "\ncenter gravity:\n");
	for (int i = 0; i < 3; i++) {
		fprintf(outp, "%.2lf  ", center[i]);
	}
}