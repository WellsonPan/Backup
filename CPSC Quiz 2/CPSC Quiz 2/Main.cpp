#include <iostream>
using namespace std;

int main()
{
	//Problem 1
	/*int n, totalDigits, thousand = 1000, hundred = 100, ten = 10;
	cout << "Enter a four digit number: ";
	cin >> n;

	_asm {
		mov eax, n;
		cdq;
		idiv thousand;
		mov totalDigits, eax;
		mov eax, edx;
		cdq;
		idiv hundred;
		add totalDigits, eax;
		mov eax, edx;
		cdq;
		idiv ten;
		add totalDigits, eax;
		add totalDigits, edx;
	}

	cout << "The total of digits in n is " << totalDigits << endl;
	*/

	//Problem 2
	short a = 5, b = 7, c = 2, r, twenty = 20;

	_asm {
		mov ax, a;
		mov bx, a;
		add ax, b;
		sub bx, b;
		imul bx;
		imul twenty;
		mov r, ax;
		mov ax, a;
		imul a;
		imul a;
		imul c;
		mov bx, ax;
		mov ax, r;
		cwd;
		idiv bx;
		mov r, ax;
	}

	cout << "r: " << r << endl;

	system("pause");
	return 0;
}