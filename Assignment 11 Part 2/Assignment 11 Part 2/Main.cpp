#include <iostream>
#include <string>
using namespace std;

int main()
{
	const int SIZE = 5;
	string salsa[SIZE] = {"Mild", "Medium", "Sweet", "Hot", "Zesty"};
	int amountSold[SIZE] = {10, 20, 5, 15, 25};
	int totalSales, totalAmount = 0;

	cout << "Name\t\tJars Sold" << endl;
	cout << "_________________________" << endl;
	for (int index = 0; index < SIZE; index++)
	{
		cout << salsa[index] << "\t\t" << amountSold[index] << endl;
		totalAmount += amountSold[index];
	}

	int highestSold, highest = amountSold[0];
	for (int index = 0; index < SIZE; index++)
	{
		if (amountSold[index] > highest)
		{
			highest = amountSold[index];
			highestSold = index;
		}
	}

	int lowestSold, lowest = amountSold[0];
	for (int index = 0; index < SIZE; index++)
	{
		if (amountSold[index] < lowest)
		{
			lowest = amountSold[index];
			lowestSold = index;
		}
	}
	totalSales = totalAmount * 4; 

	cout << endl;
	cout << "Total Sales: $" << totalSales << endl;
	cout << "High Seller: " << salsa[highestSold] << endl;
	cout << "Low Seller: " << salsa[lowestSold] << endl;

	system("pause");
	return 0;
}