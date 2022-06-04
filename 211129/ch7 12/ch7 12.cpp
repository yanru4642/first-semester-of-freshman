#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binary_srch(int arr[],int search);

int main(void) {
	int arr[10] = { -333,-33,-1,0,5,5,11,47,101,789 };
	int index = 0;
	int search = 0;

	//input the search target
	printf("Enter the number you want to search> ");
	scanf("%d", &search);

	index = binary_srch(arr, search);

	//output the result
	if (index == -1) {
		printf("Error. %d not found.\n", search);
	}
	else {
		printf("found %d.  Index: %d\n", search, index);
	}

	system("pause");
	return (0);
}

int binary_srch(int arr[],int search) {
	int found = 0;
	int bottom = 0;
	int top = 9;
	int middle;

	while (bottom<=top && !found){
		middle = (bottom + top) / 2;
		if (arr[middle]==search) {
			return(middle);
		}else if(arr[middle]>search) {
			top = middle - 1;
		}else{
			bottom = middle + 1;
		}
	}

	return -1;
}