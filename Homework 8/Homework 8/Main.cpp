#include <iostream>
using namespace std;

int main()
{
	int counter = 0;
	while (counter <= 100)
	{
		if ((counter % 2) == 0)
		{
			cout << counter << "\t";
		}
		counter++;
	}


	system("pause");
	return 0;
}