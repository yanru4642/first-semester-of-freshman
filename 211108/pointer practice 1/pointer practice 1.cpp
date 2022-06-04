#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void find_sq_sum(double a, double b, double c, double* ptr1);
void find_avg(double a, double b, double c, double* ptr2);

int main(void) {
	double a = 0, b = 0, c = 0;
	double sq_sum = 0;
	double avg = 0;

	printf("Enter a b c> ");
	scanf("%lf %lf %lf", &a, &b, &c);

	find_sq_sum(a, b, c, &sq_sum);
	find_avg(a, b, c, &avg);


	printf("\nsquare sum:	%.3lf", sq_sum);
	printf("\naverage:	%.3lf\n", avg);

	system("pause");
	return(0);
}

void find_sq_sum(double a, double b, double c, double* ptr1) {
	a = pow(a, 2);
	b = pow(b, 2);
	c = pow(c, 2);
	*ptr1 = a + b + c;
}
void find_avg(double a, double b, double c, double* ptr2) {
	*ptr2 = (a + b + c) / 3;
}
