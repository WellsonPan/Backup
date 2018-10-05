#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input;
	bool accept = false;
	cout << "Input: ";
	cin >> input;

	//cout << input[input.length() - 1] << endl;

	if (input[0] == 'a')
	{
		if (input[input.length() - 1] == 'b')
		{
			if (input.length() > 2)
			{
				for (int index = 1; index < (input.length() - 2); index++)
				{
					if (input[index] != 'a')
					{
						accept = false;
						break;
					}
					else
					{
						accept = true;
					}
				}
			}
			else
			{
				accept = true;
			}
		}
	}
	else if (input[0] == 'b')
	{
		if (input.length() > 1)
		{
			for (int index = 1; index < input.length(); index++)
			{
				if (input[index] != 'b')
				{
					accept = false;
					break;
				}
				else
				{
					accept = true;
				}
			}
		}
		else
		{
			accept = true;
		}
	}
	else
	{
		accept = false;
	}

	if (accept)
	{
		cout << input << " is in the language" << endl;
	}
	else
	{
		cout << input << " is not in the language" << endl;
	}
	
	system("pause");
	return 0;
}