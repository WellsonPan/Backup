#include <iostream>
using namespace std;

int main()
{
	int zipcodeList[] = {1, 2, 3, 4, 5};
	int nZips = 5;
	bool duplicates = false;

	for (int j = 0; j < nZips; j++)
	{
		for (int k = j + 1; k < nZips; k++)
		{
			if (zipcodeList[j] == zipcodeList[k])
			{
				duplicates = true;
				break;
			}
			//else
			//{
				//duplicates = false;
			//}
		}
	}

	if (duplicates)
	{

		cout << "True";
	}
	else
	{
		cout << "False";
	}

	system("pause");
	return 0;
}