#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double usuage = 0;	//input - data usuage

	//Show instruction and input
	printf("Enter your date usuage(Gbs)>> ");
	scanf("%lf", &usuage);

	//determine charges and display the result
	if (usuage <= 0) {
		printf("\nError: Bad data\n");
	}
	else if (0 < usuage && usuage <= 1) {
		printf("\nData Usuage: %.2lf\n", usuage);
		printf("Charges: 250$\n");
	}
	else if (1 < usuage && usuage <= 2) {
		printf("\nData Usuage: %.2lf\n", usuage);
		printf("Charges: 500$\n");
	}
	else if (2 < usuage && usuage <= 5) {
		printf("\nData Usuage: %.2lf\n", usuage);
		printf("Charges: 1000$\n");
	}
	else if (5 < usuage && usuage <= 10) {
		printf("\nData Usuage: %.2lf\n", usuage);
		printf("Charges: 1500$\n");
	}
	else {
		printf("\nData Usuage: %.2lf\n", usuage);
		printf("Charges: 2000$\n");
	}

	return(0);
}