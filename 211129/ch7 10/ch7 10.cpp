#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



int main(void) {
	char name[4] = { 'A','B', 'C', 'D' };
	int data[5][4] = { {192,48,206,37},{147,90,312,21},{186,12,121,38},{114,21,408,39},{267,13,382,29} };
	for (int i = 0; i < 2; i++){
		int vote[4] = { 0,0,0,0 };
		double percentge[4] = { 0,0,0,0 };
		int total_vote = 0;
		double temp = 0;
		double tempMax = 0;
		int first_candidate = 0;
		int second_candidate = 0;

		//a.
		printf("Precinct    Candidate A    Candidate B    Candidate C    Candidate D");
		printf("\n--------------------------------------------------------------------\n");
		for (int i = 0; i < 5; i++) {
			printf("    %d    ", i + 1);
			for (int j = 0; j < 4; j++) {
				printf("        %d    ", data[i][j]);
			}
			printf("\n");
		}

		//b.
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 5; j++) {
				vote[i] += data[j][i];
				total_vote += data[j][i];
			}
		}

		for (int i = 0; i < 4; i++) {
			percentge[i] = vote[i] / (double)total_vote * 100;
			printf("\nCandidate %c: %4d", name[i], vote[i]);
			printf("    Percentage: %2.2lf%%", percentge[i]);
		}

		//c.
		for (int i = 0; i < 4; i++) {
			if (percentge[i] > 50) {
				printf("\nCandidate %c is the winner, percentge %.2lf\n\n", name[i], percentge[i]);
			}

		}

		//d.
		if (percentge[0] < 50 && percentge[1] < 50 && percentge[2] < 50 && percentge[3] < 50) {
			//first
			for (int i = 0; i < 4; i++) {
				if (percentge[i] > temp) {
					temp = percentge[i];
					first_candidate = i;
				}
			}
			tempMax = temp;
			temp = 0;
			//second
			for (int j = 0; j < 4; j++) {
				if (percentge[j] < tempMax && percentge[j]>temp) {
					temp = percentge[j];
					second_candidate = j;
				}
			}
			printf("\n\nRunoff between two candidates");
			printf("\nCandidate %c, percentge %.2lf%%", name[first_candidate], tempMax);
			printf("\nCandidate %c, percentge %.2lf%%\n\n", name[second_candidate], temp);
		}

		//e.
		data[3][2] = 108;
	}
	system("pause");
	return (0);
}