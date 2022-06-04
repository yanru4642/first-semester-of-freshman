#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void charges(double hour, double* ptr1, double* ptr2);
void round_money(double* ptr1, double* ptr2);

int main(void) {
	int month = 0;
	int year = 0;
	int status = 0;
	FILE* inp, * outp;
	inp = fopen("usage.txt", "r");
	outp = fopen("charges.txt", "w");

	fscanf(inp, "%d %d", &month, &year);
	fprintf(outp, "Charges  for  %d/%d\n\n", month, year);
	fprintf(outp, "\nCustomer        Hours used        Charge        Average cost per hour");

	do {
		int CUST = 0;			//customer number
		double hour = 0;		//hours used
		double chrg = 0;		//charge
		double avgCostPerHr = 0;//read and write customer number
		status = fscanf(inp, "%d", &CUST);
		if (status == EOF) {
			break;
		}
		fprintf(outp, "\n    %5d	", CUST);

		//read and write used hour
		fscanf(inp, "%lf", &hour);
		fprintf(outp, "	%3.1lf	", hour);

		//calculate charge and average cost per hour
		charges(hour, &chrg, &avgCostPerHr);

		//round the number
		round_money(&chrg, &avgCostPerHr);

		fprintf(outp, "%.2lf		%.2lf", chrg, avgCostPerHr);

	} while (status != EOF);



	fclose(inp);
	fclose(outp);
	system("pause");
	return(0);
}

void charges(double hour, double* ptr1, double* ptr2) {

	//calculate charge
	if (hour < 10) {
		*ptr1 = 7.99;
	}
	else {
		*ptr1 = 7.99 + 1.99 * ceil(hour - 10);
	}

	//calculate average cost per hour
	*ptr2 = *ptr1 / hour;
}

void round_money(double* ptr1, double* ptr2) {
	*ptr1 = round(*ptr1 * 100) / 100;
	*ptr2 = round(*ptr2 * 100) / 100;
}