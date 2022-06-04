/*pumps*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(void) {
	int VTBI = 0; //input - Volume to be infused
	int mins = 0; //input - Minutes over which to infuse
	float rate = 0; // infuse rate

	//Display instructions and input.
	printf("Volume to be infused (ml)> ");
	scanf("%d", &VTBI);
	printf("Minutes over which to infuse> ");
	scanf("%d", &mins);

	//Calculate the rate.
	rate = ((float)VTBI / mins) * 60;

	//Display the result
	printf("VTBI: %d ml\nRate: %f ml/hr", VTBI, rate);

	return(0);
}