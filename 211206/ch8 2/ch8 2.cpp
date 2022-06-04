#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int determine_colors(char COLOR_CODES[][7], char buffer[], int count);

int main(void){
	char COLOR_CODES[10][7] = {"black","brown","red","orange","yellow","green","blue","violet","gray","white"};
	char buffer[64];
	int band[3];
	int count;	//which number the band color is
	double result;
	char again;

	do{
		//show instruction and input
		memset(buffer, '\0', 64);
		memset(band, 0, 3);
		result = 0;
		printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end.\n");
		printf("Type the colors in lowercase letters only, NO CAPS.\n");
		for (count = 0; count < 3; count++) {
			do {
				printf("Band %d => ", count + 1);
				memset(buffer, '\0', 64);
				scanf("%s", buffer);
				band[count] = determine_colors(COLOR_CODES, buffer, count);
				if (band[count] == -1) {
					printf("Invalid color:  %s\nPlease enter again.\n", buffer);
				}
			} while (band[count] == -1);
		}

		//calculate
		for (count = 0; count < 3; count++) {
			if (count != 2) {
				result += band[count] * pow(10, (1 - count));
			}
			else {
				result *= pow(10, band[count]);
			}
		}
		result /= 1000.0;

		//show the result
		printf("\nResistance value: %4.1lf kilo-ohms", result);

		//ask whether decode another resistor or not
		printf("\nDo you want to decode another resistor? (y/n)");
		scanf(" %c", &again);
		printf("----------------------------------------\n\n");
	} while (again=='Y'||again=='y');


	system("pause");
	return 0;
}

int determine_colors(char COLOR_CODES[][7], char buffer[], int count) {
	int index = 0;
	int temp = 0;
	for (index = 0; index < 10; index++) {
		int temp = 0;
		do{
			if (COLOR_CODES[index][temp]!=buffer[temp]) {
				break;
			}
		} while (buffer[temp++] != '\0');
		if (temp==7){
			temp--;
		}
		if (COLOR_CODES[index][temp] == buffer[temp]) {
			return index;
		}
	}
	return -1;
}