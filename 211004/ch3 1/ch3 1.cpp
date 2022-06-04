#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double get_payment(double, double, double);

int main(void) {
	double purchasePrice = 0;		//input- purchase price
	double downPayment = 0;			//input- down payment
	double annualInterestRate = 0;	//input- annual interest rate
	double numberOfPayments = 0;	//input- total number of payments
	double principal = 0;			//the amount borrowed
	double monthlyInterestRate = 0;	//monthly interest rate
	double monthlyPayment = 0;		//monthly payment

	//display instructions and input 4 variables
	printf("Enter the purchase price>  ");
	scanf("%lf", &purchasePrice);
	printf("Enter the down payment>  ");
	scanf(" %lf", &downPayment);
	printf("Enter the annual interest rate>  ");
	scanf(" %lf", &annualInterestRate);
	printf("Enter the total number of payments>  ");
	scanf(" %lf", &numberOfPayments);

	//calculate the amount borrowed
	principal = purchasePrice - downPayment;

	//claculate monthly interest rate from annual interest rate
	monthlyInterestRate = annualInterestRate / 12;

	//calculate monthly payment
	monthlyPayment = get_payment(principal, monthlyInterestRate, numberOfPayments);

	//display the amount borrowed and monthly payment
	printf("\n\nThe amount borrowed:  %lf\nMonthly payment:  %.2lf$", principal, monthlyPayment);

	return(0);
}

double get_payment(double P, double i, double n) {
	double ans = 0;
	ans = (i * P) / (1 - pow((1 + i), -n));
	return(ans);
}