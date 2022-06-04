#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trap(double a, double b, double n, char ch);

int main(void) {
	char ch;
	double a = 0,
		b = 0;
	int n = 2;

	printf("選擇要估計的方程式面積\n");
	printf("g(x) = x^2 * sin(x)\n");
	printf("h(x) = √(4 - x^2)\n");
	printf("輸入g或h來代表要選擇的函式>\n");
	scanf("%c", &ch);
	printf("輸入估計的閉區間[a,b](format:a b)>\n");
	scanf("%lf %lf", &a, &b);

	for (n = 2; n <= 128; n *= 2) {
		double area = trap(a, b, n, ch);
		if (area == -1) {
			break;
		}
		printf("n=%3d 時，估計面積為 %lf\n", n, area);
		system("break");
	}
	return(0);
}

double trap(double a, double b, double n, char ch) {
	double sigma = 0;
	double area = 0;
	double h = (b - a) / n;

	switch (ch) {
	case'G':
	case 'g': {
		for (int i = 0; i < n; i++) {
			sigma += pow(a + i * h, 2) * sin(a + i * h);
		}
		area = h / 2 * (pow(a, 2) * sin(a) + pow(b, 2) * sin(b) + 2 * sigma);
		return(fabs(area));
		break;
	}
	case'H':
	case'h': {
		for (int i = 0; i < n; i++) {
			sigma += pow(4 - pow(a + i * h, 2), 0.5);
		}
		area = h / 2 * (pow(4 - pow(a, 2), 0.5) + pow(4 - pow(b, 2), 0.5) + 2 * sigma);
		return(fabs(area));
		break;
	}
	default: {
		printf("Error function name!");
		return(-1);
		break;
	}
	}
}