#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

void sort(int arr[]);

int main(void){
	char digit = '0';
	int arr[MAX] = { 0 };

	 for (int i = 0; digit!='\n'; i++){
		do{
			scanf("%c", &digit);
			if (digit==' '|| digit=='\n'){
				break;
			}
			arr[i] *= 10;
			arr[i] += digit - '0';
		} while (digit!=' ' && digit!='\n');
	}

	//before sort
	printf("before sort:\n");
	for (int i = 0; i < MAX; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	//sort
	sort(arr);

	//after sort
	printf("after sort:\n");
	for (int i = 0; i < MAX; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}

void sort(int arr[]) {
	int index = 0;
	int temp = 0;
	for (int index = 0; index < MAX; index++){
		for (int i = index; i < MAX; i++) {
			if (arr[i]<arr[index]) {
				temp = arr[index];
				arr[index] = arr[i];
				arr[i] = temp;
			}
		}
	}
}