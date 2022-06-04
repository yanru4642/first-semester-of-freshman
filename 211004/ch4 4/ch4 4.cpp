#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char color = 0; //input - the letter that representing observed color

	//Show instructions and input
	printf("Enter the character representing the color> \n");
	scanf("%c", &color);

	//display the result
	switch (color) {
	case'O':
	case'o':
		printf("\norange    ammodia\n");
		break;

	case'B':
	case'b':
		printf("\nbrown    carbon monoxide\n");
		break;

	case'Y':
	case'y':
		printf("\nyellow     hydrogen\n");
		break;

	case'G':
	case'g':
		printf("\ngreen     oxygen\n");
		break;

	default:
		printf("\nError: Contents unknow\n");
	}

	return(0);
}
