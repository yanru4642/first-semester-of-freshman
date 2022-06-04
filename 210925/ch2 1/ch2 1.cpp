/*Taxi Fare Calculator*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	float rate = 1.5; //Define the rate of taxi fare at 1.5$ per mile.
	float startOdometerReading = 0, endOdometerReading = 0; //input - Odometer reading
	double distance; //The distance that taxi travels.
	double fare; //The fare that a customer should pay.

	//Displaying instruction and input odometer reading.
	printf("TAXI FARE CALCULATOR\nEnter beginning odometer reading> ");
	scanf("%f", &startOdometerReading);
	printf("Enter ending odometer reading> ");
	scanf("%f", &endOdometerReading);

	//Calculate.
	distance = endOdometerReading - startOdometerReading;
	fare = distance * rate;

	//Display the result.
	printf("You traveled a distance of %f mile(s).\nAt %f per mile, your fare is %f.", distance, rate, fare);

	return(0);
}
