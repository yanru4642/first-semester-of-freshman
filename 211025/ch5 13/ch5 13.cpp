#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* inp;
	char ch;
	int player;
	int hit;
	int out;
	double bat_avg;
	int status = 0;
	int i = 0;

	inp = fopen("file.txt", "r");
	do {
		player = 0;
		hit = 0;
		out = 0;

		status = fscanf(inp, "%d", &player);
		printf("Player %d's record:", player);
		do {
			status = fscanf(inp, "%c", &ch);
			if (status == 1) {
				printf("%c", ch);
				switch (ch) {
				case 'H':
					hit++;
					break;
				case 'O':
					out++;
					break;
				default:
					break;
				}
			}
			else if (status == EOF) {
				printf("\n");
				break;
			}
		} while (ch != '\n');

		bat_avg = (double)hit / (hit + out);

		printf("Player %d's batting average: %.3lf\n\n", player, bat_avg);
		if (status == EOF) {
			break;
		}
	} while (status != EOF);

	fclose(inp);
	return(0);
}