#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void in_val(void);
double avg(double a, double b, double c);
double a = 0,
b = 0,
c = 0;

int main(void) {
	in_val();
	printf("\nAvg: %lf", avg(a, b, c));

	return(0);
}

void in_val() {
	int error = 0;
	char skip;
	int status;
	do {
		error = 0;
		printf("\nEnter a b c> ");
		status = scanf("%lf %lf %lf", &a, &b, &c);
		if (status != 3) {
			error = 1;
			printf("Bad data!");
		}
		else if (a < 0 || a>100 || b < 0 || b>100 || c < 0 || c>100) {
			error = 1;
			printf("Error number!");
		}
		do {
			scanf("%c", &skip);
		} while (skip != '\n');

	} while (error);
}

double avg(double a, double b, double c) {
	return((a + b + c) / 3);
}