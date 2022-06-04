#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* inp;
	char ch;
	int player;
	int hit = 0;
	int out = 0;
	double bat_avg;
	int status = 0;
	char line[32];
	int i = 0;

	inp = fopen("file.txt", "r");

	do {
		i = 0;
		player = 0;
		hit = 0;
		out = 0;

		status = fscanf(inp, "%d", &player);
		if (status == EOF) {
			break;
		}
		else if (status == 1) {
			printf("Player %d's record:", player);
		}

		fgets(line, 32, inp);
		for (i = 0; i < 32; i++) {
			if (line[i] == 'H') {
				hit++;
			}
			else if (line[i] == 'O') {
				out++;
			}
			else if (line[i] == '\n') {
				line[i] = '\0';
				break;
			}
		}

		printf("%s", line);

		bat_avg = (double)hit / (hit + out);

		printf("\nPlayer %d's batting average: %.3lf\n\n", player, bat_avg);

	} while (status != EOF);

	fclose(inp);
	system("pause");
	return(0);
}