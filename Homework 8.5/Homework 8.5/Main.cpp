#include <iostream>
using namespace std;

int main()
{
	double beginBalance, interestRate, paymentAmount, totalAmountPayed = 0;
	int monthCounter = 0;
	cout << "Please input the balance, interest rate, and the payment amount: " << endl;
	cin >> beginBalance >> interestRate >> paymentAmount;
	while (beginBalance > 0)
	{
		beginBalance = (beginBalance + (beginBalance*interestRate))-paymentAmount;
		monthCounter++;
		totalAmountPayed += paymentAmount;
	}
	cout << "Months: " << monthCounter << endl;
	cout << "Total Amount Payed: " << totalAmountPayed << endl;

	system("pause");
	return 0;
}