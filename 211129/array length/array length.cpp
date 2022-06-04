#include <stdio.h>
#include <stdlib.h>


int main(void){
	int arr[10];
	for (int i = 0; i < 5; i++){
		arr[i] = i+11;
	}


	printf("\nsizeof(arr): %d", sizeof(arr));
	printf("\nsizeof(arr[0]): %d", sizeof(arr[0]));
	printf("\nnumber of elements: %d", sizeof(arr)/sizeof(arr[0]));

	system("pause");
	return 0;
}
