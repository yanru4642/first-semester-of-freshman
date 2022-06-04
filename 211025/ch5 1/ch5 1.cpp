#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int number = 0;
	int temp = 0;

	//show instruction and input
	printf("Enter a number> ");
	scanf("%d", &number);

	temp = number;
	while (number != 0) {
		printf("\n%d", number % 10);
		number = number / 10;
	}
	if (temp % 9 == 0) {
		printf("\n%d is divisible by 9.", temp);
	}
	else {
		printf("\n%d is indivisible by 9.", temp);
	}
}