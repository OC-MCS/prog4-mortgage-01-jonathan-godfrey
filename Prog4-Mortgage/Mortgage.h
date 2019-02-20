#pragma once
// header file for Mortgage class

#ifndef MORTGAGE_H
#define MORTGAGE_H

class Mortgage
{
private:
	float loan;
	float rate;
	int years;
	float term;
	float payment;
	float monthlyPayment;
	float totalPayment;
public:
	Mortgage();
	Mortgage(float loan, float rate, int years);
	float calculateTerm(float rate, int years);
	float calculatePayment();
	float calculateTotalPayment();
};

#endif