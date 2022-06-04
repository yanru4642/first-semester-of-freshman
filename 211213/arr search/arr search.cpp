#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

int search(int const arr[], int const num);

int main(void) {
	char digit = '0';
	int arr[MAX] = { 0 };
	int num = 0;
	int index = 0;

	printf("Enter 10 numbers> ");
	for (int i = 0; digit != '\n'; i++) {
		do {
			scanf("%c", &digit);
			if (digit == ' ' || digit == '\n') {
				break;
			}
			arr[i] *= 10;
			arr[i] += digit - '0';
		} while (digit != ' ' && digit != '\n');
	}

	//search
	printf("Enter the target number> ");
	scanf(" %d", &num);
	index =  search(arr, num);

	//result
	if (index == -1) {
		printf("\nError. Number not found.\n");
	}
	else {
		printf("\nnumber %d is found. Index: %d\n", num, index);
	}

	system("pause");
	return 0;
}

int search(int const arr[], int const num) {

	for (int i = 0; i < MAX; i++){
		if (arr[i]==num){
			return i;
		}
	}
	return -1;
}