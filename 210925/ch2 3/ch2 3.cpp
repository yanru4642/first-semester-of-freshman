/*Temperature Estimation*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int inputHour = 0, inputMin = 0; //input - hour and minute
	float convertedTime = 0; //converted time
	float temp = 0; //estimated temperature

	//Display instruction and input.
	printf("Freezer Temperature Estimation\n Please enter the time.(format:hh mm)> ");
	scanf("%2d%2d", &inputHour, &inputMin);

	//Convert time's format.
	convertedTime = ((float)inputHour * 60 + (float)inputMin) / 60;

	//Estimate the temp.
	temp = (4 * convertedTime * convertedTime) / (convertedTime + 2) - 20;

	//Display the result.
	printf("Estimated temperature is %f °C.", temp);

	return(0);
}