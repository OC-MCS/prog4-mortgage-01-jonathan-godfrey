// main goes here. Code that *uses* the Mortgage class
// goes in this file

#include <iostream>
#include <string>
#include <iomanip>
#include "Mortgage.h"
using namespace std;

bool parseInt(string sval, int& val);
bool parseFloat(string sval, float& val);

int main()
{
	float loan, rate, monthlyPayment, totalPayment;
	int years;
	string input;

	do
	{
		cout << "Enter loan amount: " << endl;
		getline(cin, input);
	} while (!parseFloat(input, loan) && loan < 0);

	do
	{
		cout << "Enter interest rate: " << endl;
		getline(cin, input);
	} while (!parseFloat(input, rate) && rate < 0);

	do
	{
		cout << "Enter number of years of the loan: " << endl;
		getline(cin, input);
	} while (!parseInt(input, years) && years < 0);

	Mortgage mortgage(loan, rate, years);

	monthlyPayment = mortgage.calculatePayment();
	totalPayment = mortgage.calculateTotalPayment();

	cout << "Monthly payment is: $" << fixed << setprecision(2) << monthlyPayment << endl;
	cout << "Total payment will be: $" << totalPayment << endl;

	return 0;
}

//=============================================================
// parseInt: checks if string input from user is an int
// parameters: 
//   sval: string input from user
//   val: int value from string
// returns: bool of whether string is an int
//=============================================================
bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

//=============================================================
// parsefloat: checks if string input from user is a float
// parameters: 
//   sval: string input from user
//   val: float value from string
// returns: bool of whether string is a float
//=============================================================
bool parseFloat(string sval, float& val)
{
	float num;
	bool success = true;
	try
	{
		num = stof(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}