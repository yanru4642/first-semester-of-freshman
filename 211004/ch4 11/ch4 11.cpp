#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int within_x_percent(double ref, double data, double x_percent) {
	x_percent = x_percent / 100;
	if ((ref - ref * x_percent) <= data && data <= (ref + ref * x_percent)) {
		return(1);
	}
	else {
		return(0);
	}
}

int main(void) {
	double temp, percent;	//input - temperature
	//show instructions and input data
	printf("Enter the temperature observed in celsius> ");
	scanf("%lf", &temp);
	printf("Enter precent> ");
	scanf("%lf", &percent);
	//display the result
	if (within_x_percent(100.0, temp, percent)) {
		printf("Water");
	}
	else if (within_x_percent(357.0, temp, percent)) {
		printf("Mercury");
	}
	else if (within_x_percent(1187.0, temp, percent)) {
		printf("Copper");
	}
	else if (within_x_percent(2193.0, temp, percent)) {
		printf("Silver");
	}
	else if (within_x_percent(2660.0, temp, percent)) {
		printf("Gold");
	}
	else {
		printf("Substance unknown");
	}
	return(0);
}