#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display_result(double, double);

int main(void) {
	double p1min = 0, p1sec = 0;	//input - player 1 score
	double p2min = 0, p2sec = 0;	//input - player 2 score
	double p3min = 0, p3sec = 0;	//input - player 3 score
	double p4min = 0, p4sec = 0;	//input - player 4 score

	//input player1 score and display the result
	printf("Enter the Player1 score(format:min sec)> ");
	scanf("%lf %lf", &p1min, &p1sec);
	display_result(p1min, p1sec);

	//input player2 score and display the result
	printf("Enter the Player2 score(format:min sec)> ");
	scanf("%lf %lf", &p2min, &p2sec);
	display_result(p2min, p2sec);

	//input player3 score and display the result
	printf("Enter the Player3 score(format:min sec)> ");
	scanf("%lf %lf", &p3min, &p3sec);
	display_result(p3min, p3sec);

	//input player4 score and display the result
	printf("Enter the Player4 score(format:min sec)> ");
	scanf("%lf %lf", &p4min, &p4sec);
	display_result(p4min, p4sec);

	return(0);
}

void display_result(double min, double sec) {
	double totalTime = min * 60 + sec;			//caculate total time in second
	double fps = 5280 / totalTime;				//1 mile = 5280 feet
	double mps = (1000 * 5280 / 3282) / totalTime;	//3282 feet = 1 kilometer
	printf("Minutes: %.2lf    Seconds: %.2lf\nfeet per second(fps): %lf\nmeters per second(mps): %lf", min, sec, fps, mps);
	printf("\n------------------------------------------------\n\n");
}