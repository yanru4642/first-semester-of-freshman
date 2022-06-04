#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void){
	char arr[2][50];
	char *ptr[2];
	char input[64];
	for (int i = 0; i < 2; i++)
	{
		scanf("%s", input);
		strcpy(arr[i], input);
		ptr[i] = arr[i];
	}
	strcat(*(ptr), *(ptr+1));
	printf("%s", *ptr);
}


