#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	char cont = 'y';

	while (cont == 'y')
	{
		string postfix;
		int correspondance[10];
		stack<int> hold;
		int varCount = 0;
		int count = 0;

		cout << "Enter a postfix expression: ";
		cin >> postfix;

		for (int index = 0; index < postfix.length(); index++)
		{
			if (postfix[index] >= 97 && postfix[index] <= 122)
			{
				int var;
				cout << "Enter the value of " << postfix[index] << ": ";
				cin >> var;
				correspondance[varCount] = var;
				varCount++;
			}
		}

		for (int index = 0; index < postfix.length(); index++)
		{
			if (postfix[index] > 96 && postfix[index] < 123)
			{
				hold.push(correspondance[count]);
				count++;
			}
			else
			{
				int op1 = hold.top();
				hold.pop();
				int op2 = hold.top();
				hold.pop();

				if (postfix[index] == '+')
				{
					hold.push(op1 + op2);
				}
				else if (postfix[index] == '-')
				{
					hold.push(op2 - op1);
				}
				else if (postfix[index] == '*')
				{
					hold.push(op1 * op2);
				}
				else if (postfix[index] == '/')
				{
					hold.push(op2/op1);
				}
				else
				{
					cout << "Input is not a number or arithmetic operator" << endl;
				}
			}
		}

		cout << "Final value: " << hold.top() << endl;

		cout << "Continue(y/n)? ";
		cin >> cont;
	}
	system("pause");
	return 0;
}