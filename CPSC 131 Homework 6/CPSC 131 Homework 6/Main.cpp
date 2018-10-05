#include <iostream>

using namespace std;

double chlorineAmount(double week)
{
	if (week == 1)
	{
		return 32;
	}
	else
	{
		return 14 + ((chlorineAmount(week - 1))* .6);
	}
}

int main()
{
	double n;

	cout << "How many weeks has it been?" << endl;
	cin >> n;

	cout << "The amount of chlorine in your pool is " << chlorineAmount(n) << " ounces"<< endl;

	system("pause");
	return 0;
}