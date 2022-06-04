#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n1 = 0;	//分子
	int d1 = 0;	//分母
	int flag = 0;
	int i = 0;
	int smallnum = 0;

	printf("Enter a fraction(format: n/d )> ");
	scanf("%d/%d", &n1, &d1);

	if (n1 < d1) {
		smallnum = abs(n1);
	}else{
		smallnum = abs(d1);
	}

	do{
		flag = 1;
		for (i = smallnum; i > 0; i--){
			if (n1 % i == 0 && d1 % i == 0) {
				n1 /= i;
				d1 /= i;
				break;
			}
		}
		if (i<=1) {
			flag = 0;
		}
	} while (flag);

	printf("\nRESULT: %d/%d\n", n1, d1);

	system("pause");
	return 0;
}