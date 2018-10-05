#include <iostream>
using namespace std;

int main()
{
	const int SIZE = 5;
	char letter[SIZE] = {'A', 'B', 'C', 'D', 'E'};

	for (int index = 0; index < SIZE; index++)
	{
		for (int counter = 0; counter < 3; counter++)
		{
			cout << letter[index] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}