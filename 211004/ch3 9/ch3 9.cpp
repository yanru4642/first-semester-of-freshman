#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void predict_cases(int);

int main(void) {
	int day = 0;	//input - day number
	int cases = 0;	//predicted cases

	printf("Enter day number>> ");
	scanf("%d", &day);
	predict_cases(day);

	printf("Enter day number>> ");
	scanf("%d", &day);
	predict_cases(day);

	printf("Enter day number>> ");
	scanf("%d", &day);
	predict_cases(day);

	return(0);
}

void predict_cases(int day) {
	int cases = 0;	//predicted cases
	cases = pow(1.28, day);
	printf("By day %d, model predicts %d cases totaal.\n\n", day, cases);
}