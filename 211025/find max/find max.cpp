#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int FindMax(int a, int b);

int main(void) {
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int n4 = 0;
	int n5 = 0;
	int tempMax = 0;

	printf("Enter numbers(format:n1 n2 n3 n4 n5)> ");
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	tempMax = FindMax(n1, n2);
	tempMax = FindMax(tempMax, n3);
	tempMax = FindMax(tempMax, n4);
	tempMax = FindMax(tempMax, n5);
	printf("\nThe Maximum number is %d", tempMax);

}
int FindMax(int a, int b) {
	if (a > b) {
		return(a);
	}
	else {
		return(b);
	}
}