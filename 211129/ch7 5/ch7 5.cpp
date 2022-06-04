#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32

void get_check_digit(const int* ptr1, int* ptr2);

int main(void) {
	char buffer[MAX];
	char temp;
	int barcode[MAX];
	int check_number = 0;
	int check_digit = 0;

	//Show instructions and input
	printf("Enter a barcode> ");
	for (int i = 0; i < 12; i++) {
		scanf(" %c", &buffer[i]);
	}
	for (int i = 0; i < 12; i++) {
		barcode[i] = buffer[i] - 48;
	}

	//Calculate the check number
	get_check_digit(barcode, &check_number);

	//Get the check digit
	check_digit = check_number % 10;
	if (check_digit != 0) {
		check_digit = 10 - check_digit;
	}

	//output the result
	printf("\nInput barcode: ");
	for (int i = 0; i < 12; i++){
		printf("%d", barcode[i]);
	}
	if (check_digit == barcode[11]) {
		printf("\nValidated");
	}else{
		printf("\nError in barcode");
		printf("\nThe result from step 2: %d", check_number);
	}


	system("pause");
	return (0);
}

void get_check_digit(const int* ptr1, int* ptr2) {
	//Step 1
	for (int i = 0; i < 11; i+=2){
		*ptr2 += *(ptr1 + i) * 3;
	}

	//Step 2
	for (int i = 1; i < 11; i += 2) {
		*ptr2 += *(ptr1 + i);
	}
}