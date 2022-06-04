#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	double n = 0;	//f(x)= x^n - c
	double c = 0;
	double x0 = 0;
	double x1 = 0;
	double Fx0 = 0;	//方程式
	double fx0 = 0;	//方程式一次微分
	double delta = 0;	//x0與x1的差

	printf("求方程式 x^n - c = 0 的根\nEnter n = ");
	scanf("%lf", &n);
	printf("Enter c = ");
	scanf("%lf", &c);
	printf("---------------");

	x0 = c / 2.0;
	int i = 0;
	while (1) {
		Fx0 = pow(x0, n) - c;
		fx0 = n * pow(x0, (n - 1));
		x1 = x0 - Fx0 / fx0;

		system("break");

		printf("\nX%d = % lf", i, x0);
		delta = x0 - x1;
		if (fabs(delta) < 0.000001) {
			break;
		}
		x0 = x1;
		i++;
	}

	return(0);
}