#include<stdio.h>

void fill_arr(int* arr, int *ptr);

int main(void) {
	int square[11], i;
	fill_arr(square, &i);

	printf("\nlast i %d", i);

}

void fill_arr(int* arr, int *ptr){
	for (*ptr = 0; *ptr < 11; (* ptr)++)
	{
		arr[*ptr] = *ptr * *ptr;
		printf("\n[%d] %d", *ptr, arr[*ptr]);
	}
}

