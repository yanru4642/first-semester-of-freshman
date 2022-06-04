#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*Function prototpyes*/
double get_BMI(double, double);
double rounded(double);

int main(void) {
	double wt_lb = 0;	//input - weight in lb
	double ht_in = 0;	//input - height in in
	double BMI = 0;		//output - BMI

	//Show instruction and input
	printf("Enter your height in inches>> ");
	scanf("%lf", &ht_in);
	printf("Enter your weight in pounds>> ");
	scanf("%lf", &wt_lb);

	//calculate BMI
	BMI = get_BMI(ht_in, wt_lb);

	//rounded the BMI
	BMI = rounded(BMI);

	//determine weight status and display the result
	if (BMI < 18.5) {
		printf("\n----------------------------------");
		printf("\nYour BMI: % .2lf", BMI);
		printf("\nYour weight status: Underweight");
		printf("\n----------------------------------\n");
	}
	else if (BMI >= 18.5 && BMI <= 24.9) {
		printf("\n----------------------------------");
		printf("\nYour BMI: % .2lf", BMI);
		printf("\nYour weight status: Normal");
		printf("\n----------------------------------\n");
	}
	else if (BMI >= 25 && BMI <= 29.9) {
		printf("\n----------------------------------");
		printf("\nYour BMI: % .2lf", BMI);
		printf("\nYour weight status: Overweight");
		printf("\n----------------------------------\n");
	}
	else {
		printf("\n----------------------------------");
		printf("\nYour BMI: % .2lf", BMI);
		printf("\nYour weight status: Obese");
		printf("\n----------------------------------\n");
	}
	return(0);
}

double get_BMI(double h, double w) {
	return((703 * w) / (h * h));
}

double rounded(double BMI) {
	double round = BMI * 100;
	round = round + 0.5;
	return(round / 100);
}