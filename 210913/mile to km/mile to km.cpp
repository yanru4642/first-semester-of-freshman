/*
 * Convert distance in miles to kilometers.
 */

#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h> /* system definition             */
#include<stdio.h>  /* printf, scanf definitions     */

#define KMS_PER_MILE 1.609  /* conversion contant     */

int main() {
	double miles, /* input - distance in miles.       */
		kms;      /* output - distance in kilometers  */

		/* Get the distance in miles.                     */
	printf("Enter the distance in miles> ");
	scanf("%lf", &miles);

	/* Convert the distance to kilometers.            */
	kms = KMS_PER_MILE * miles;

	/* Display the distance in kilometers.            */
	printf("That equals %f kilometers.\n", kms);


	system("PAUSE");
	return 0;
}
