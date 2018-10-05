#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = " ";
	string whole = "";
	int count = 0;
	
	while (true)
	{
		getline(cin, input);
		count = 1;
		if (input == "Quit" || input == "quit" || input == "q")
		{
			break;
		}
		input = "\n" + input;
		whole = whole + input;
	}

	for (int index = (whole.length() - 1); index > 0; index--)
	{
		cout << whole[index];
	}
	cout << endl;

	system("pause");
	return 0;
}