#include <iostream>
#include <string>
using namespace std;

void Big()
{
	cout << "B I G\a" << endl;
}

int main()
{
	string answer;
	cout << "True? (y/n)" << endl;
	cin >> answer;

	if (answer == "y" || answer == "Y" || answer == "non't")
	{
		Big();
	}
	else if (answer == "69" || answer == "420")
	{
		cout << "nice" << endl;
	}
	else if (answer == "heaven" || answer == "Heaven")
	{
		cout << "West Virginia" << endl;
	}
	else if (answer == "Nice")
	{
		cout << "\u2193" << endl;
	}
	else
	{
		cout << "me to thanks" << endl;
	}

	system("pause");
	return 0;
}