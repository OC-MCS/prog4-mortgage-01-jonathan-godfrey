// implementation file for Mortgage class
#include <iostream>
#include <cmath>
#include "Mortgage.h"

Mortgage::Mortgage()
{
	loan = 0;
	rate = 0;
	years = 0;
	term = 0;
	payment = 0;
	monthlyPayment = 0;
	totalPayment = 0;
}

Mortgage::Mortgage(float ln, float irate, int yrs)
{
	loan = ln;
	rate = irate / 100;
	years = yrs;
}

//=============================================================
// calculateTerm: Calculates term of payment
// parameters: 
//   rate: interest rate on loan
//   years: years of the loan
// returns: term of payment
//=============================================================
float Mortgage::calculateTerm(float rate, int years)
{
	term = pow((1 + (rate / 12.0)), (12.0 * years));
	return term;
}

//=============================================================
// calculatePayment: Calculates monthly payment on loan
// parameters: none
// returns: monthlyPayment
//=============================================================
float Mortgage::calculatePayment()
{
	calculateTerm(rate, years);
	monthlyPayment = (loan * (rate / 12) * term) / (term - 1);
	return monthlyPayment;
}

//=============================================================
// calculatePayment: Calculates total payment on loan
// parameters: none
// returns: totalPayment
//=============================================================
float Mortgage::calculateTotalPayment()
{

	totalPayment = monthlyPayment * 12 * years;
	return totalPayment;
}
