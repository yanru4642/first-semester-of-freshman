#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 64

int palindrome(char str[],int cnt,int n,int status);

int main(void) {
	char str[MAX];
	char temp[MAX];

	memset(str, '\n', MAX);

	printf("Enter a phase> ");
	fgets(str, sizeof(str), stdin);


	for (int i = 0; i < strlen(str); i++){
		if (isupper(str[i])) {
			str[i] += 32;
		}
	}
	for (int i = 0; i < strlen(str); i++) {
		if(str[i]=='\n') {
			str[i] = '\0';
		}else if (isalpha(str[i]) == false) {
			memset(temp, '\0', MAX);
			//strcpy
			for (int j = i+1; j < strlen(str); j++){
				temp[j-i-1] = str[j];
			}
			//clear
			for (int k = i; k < strlen(str); k++){
				str[k] = '\0';
			}
			//strcat
			strcat(str, temp);
		}
	}

	int status = 1;
	int start = 0;
	int len;
	len = strlen(str) / 2;
	status = palindrome(str,start,len,status);
	if (status==1){
		printf("Is palindrome\n");
	}
	else {
		printf("Not palindrome\n");
	}

	system("pause");
	return 0;
}

int palindrome(char str[],int cnt,int n,int status) {
	if (cnt==n){
		return status;
	}else {
		if (str[cnt]!=str[strlen(str)-cnt-1]){
			status = 0;
			return status;
		}
		cnt++;
		status=palindrome(str,cnt,n,status);
	}
}