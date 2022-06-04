#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void DoRevNumber(int* ptr1, char* ptr2, char* ptr3, int* ptr4);
int CheckIsPrime(int* ptr1);
int CheckIsPalindrome(int* ptr1, int* ptr2);

int main(void) {
	int number = 0;			//input- integer number
	int revnumber = 0;		//reverse number
	int tempNumber = 0;		//temporary
	char arrNumber[16];		//number array
	char arrRevNumber[16];	//reverse number array
	char lineBuf[1024];		//line buffer array
	int lineBufCnt = 0;		//line buffer count
	char wordBuf[16];		//word buffer array
	int wordBufCnt = 0;		//word buffer count
	int wordBufDigitNum = 0;	//word buffer digit number


	//Show instructions and input a list of positive integers
	printf("Enter a list of positive integers>");
	//將一整行暫存
	do {
		scanf("%c", &lineBuf[lineBufCnt]);
		lineBufCnt++;
	} while (lineBuf[lineBufCnt - 1] != '\n');
	lineBufCnt--;
	lineBuf[lineBufCnt] = '\0';

	do {
		//切片數字陣列
		memset(arrNumber, 0, 16);
		memset(arrRevNumber, 0, 16);
		memset(wordBuf, 0, 16);
		number = 0;
		revnumber = 0;
		wordBufDigitNum = 0;
		do {
			wordBuf[wordBufDigitNum] = lineBuf[wordBufCnt];
			if (wordBuf[wordBufDigitNum] == ' ') {
				wordBufCnt++;
				break;
			}
			else if (wordBuf[wordBufDigitNum] == '\0') {
				wordBufCnt++;
				break;
			}
			wordBufDigitNum++;
			wordBufCnt++;
		} while (true);
		wordBuf[wordBufDigitNum] = '\0';

		//數字陣列轉10進制數字
		number = 0;
		for (int i = 0; i < wordBufDigitNum; i++) {
			number += (wordBuf[i] - '0') * (int)pow(10.0, wordBufDigitNum - i - 1);
		}

		tempNumber = number;

		//output number
		printf("\nInput	number: %d", number);

		//reverse the number and output
		DoRevNumber(&tempNumber, arrRevNumber, arrNumber, &revnumber);
		printf("\nReverse number: %s", arrRevNumber);

		//check the number is prime or not and output
		if (CheckIsPrime(&number) == 0) {
			printf("\n%d is NOT a prime number.", number);
		}
		else if (CheckIsPrime(&number) == 1) {
			printf("\n%d is a prime number.", number);
		}
		else {
			printf("Check prime Error");
		}

		//check the number is palindrome or not and output
		if (CheckIsPalindrome(&number, &revnumber) == 0) {
			printf("\n%d is NOT a palindrome number.", number);
		}
		else if (CheckIsPalindrome(&number, &revnumber) == 1) {
			printf("\n%d is a palindrome number.", number);
		}
		else {
			printf("Check palindrome Error");
		}
		printf("\n------------------------\n");
		system("pause");

	} while (wordBufCnt <= lineBufCnt);

	system("pause");
	return(0);
}

void DoRevNumber(int* ptr1, char* ptr2, char* ptr3, int* ptr4) {

	//反轉數陣列
	int digit;
	for (digit = 0; *ptr1 != 0; digit++) {
		*(ptr2 + digit) = *ptr1 % 10 + '0';
		*ptr1 /= 10;
	}
	*(ptr2 + digit) = '\0';

	//數字陣列
	for (int i = 0; i < digit; i++) {
		*(ptr3 + i) = *(ptr2 + digit - i - 1);
	}
	*(ptr3 + digit) = '\0';

	//反轉數
	for (int j = 0; j < digit; j++) {
		*ptr4 += (*(ptr3 + j) - '0') * (int)pow(10.0, (double)j);
	}
}

int CheckIsPrime(int* ptr1) {
	if (*ptr1 <= 0) {
		return(0);
	}
	else if (*ptr1 == 1) {
		return(0);
	}
	for (int i = 2; i <= *ptr1 / 2; i++) {
		if (*ptr1 % i == 0) {
			return(0);
		}
	}
	return(1);
}

int CheckIsPalindrome(int* ptr1, int* ptr2) {
	if (*ptr1 == *ptr2) {
		return(1);
	}
	else {
		return(0);
	}
}