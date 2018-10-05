#include <iostream>
#include <string>
using namespace std;

bool valid(string temp)
{
	bool result = false;
	if (isdigit(temp[0]))
	{
		result = false;
	}
	else if(isalpha(temp[0]) || temp[0] == '_')
	{
		result = true;
	}
	else
	{
		result = false;
	}
	return result;
}

bool alphaNum(string c)
{
	bool result = true;
	for (int i = 0; i < c.length(); i++)
	{
		if (isspace(c[i]))
		{
			result = false;
			break;
		}
		else if (isalpha(c[i]) || c[i] == '_'  || isdigit(c[i]))
		{
			result = true;
		}
		else
		{
			result = false;
			break;

		}
	}
	return result;
}

int main()
{
	string cont = "y";
	string identifier;
	int first = 0;
	while (cont == "y" || cont == "Y")
	{
		cout << "\tEnter a string: ";
		if (first > 0)
		{
			cin.ignore();
		}
		getline(cin, identifier);
		first++;
		if (valid(identifier))
		{
			if (alphaNum(identifier))
			{
				cout << "\t" << identifier << " is an identifier" << endl;
			}
			else
			{
				cout << "\t" << identifier << " is not an identifier" << endl;
			}
		}
		else
		{
			cout << "\t" << identifier << " is not an identifier" << endl;
		}
		cout << "CONTINUE(y/n)? ";
		cin >> cont;
	}
	cout << endl;
	system("pause");
	return 0;
}