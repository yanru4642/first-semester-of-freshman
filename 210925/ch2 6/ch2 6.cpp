/*Predict the score needed on a final exam.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char desiredGrade; //input - desired grade
	float minAvg = 0; //input - minimum average required
	float avgInCourse = 0; //input - current average in course
	float pctOfFinalExam = 0; //input - the percentage of final exam in course
	float scoreRequired = 0;  //output - the score to achieve the goal

	//Display instructions and input variables
	printf("Enter desired grade> ");
	scanf("%c", &desiredGrade);
	printf("Enter minimum average required> ");
	scanf("%f", &minAvg);
	printf("Enter current average in course> ");
	scanf("%f", &avgInCourse);
	printf("Enter how much the final counts as a percentage of the course grade(%%)> ");
	scanf("%f", &pctOfFinalExam);

	//強制將分數轉換成大寫(題目沒要求，自己想寫的)
	if (desiredGrade >= 'a' && desiredGrade <= 'z') {
		desiredGrade = desiredGrade - 32;
	}

	//Calculate the score required
	pctOfFinalExam = pctOfFinalExam / 100;
	scoreRequired = (minAvg - (1 - pctOfFinalExam) * avgInCourse) / (pctOfFinalExam);

	//Display the results
	printf("\nYou need a score of %f on the final to get a %c.\n", scoreRequired, desiredGrade);

	return(0);
}
