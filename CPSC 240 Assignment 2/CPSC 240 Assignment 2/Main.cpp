#include <iostream>
using namespace std;

int main()
{
	//Problem 1
	/*short drinks, sandwiches, total, drinkPrice = 2, sandPrice = 4;
	cout << "----------MENU----------" << endl;
	cout << " Drinks..............$2" << endl;
	cout << " Sandwiches..........$4" << endl;
	cout << "\tHow many drinks?";
	cin >> drinks;
	cout << "\tHow many sandwiches:";
	cin >> sandwiches;

	_asm {
		mov ax, drinks;
		imul drinkPrice;
		mov total, ax;
		mov ax, sandwiches;
		imul sandPrice;
		add total, ax;
	}

	cout << "\t\tYour total bill $" << total << endl;*/

	//Problem 2
	/*int a, b, c, h, l, width, triArea, triPerim, recArea, recPerim, d = 2;
	cout <<"        /|\\           -------------------------"<< endl;
	cout <<"       / | \\          |                       |" << endl;
	cout <<"    a /  |  \\ b       |                       | width" << endl;
	cout <<"     /  h|   \\        |                       |" << endl;
	cout <<"    /    |    \\       |                       |" << endl;
	cout <<"   -------------      ------------------------- " << endl;
	cout <<"          c                       length  "<<endl;
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	cin >> l;
	cin >> width;

	_asm {
		mov eax, c;
		imul h;
		idiv d;
		mov triArea, eax;
		mov eax, a;
		add eax, b;
		add eax, c;
		mov triPerim, eax;
		mov eax, l;
		imul width;
		mov recArea, eax;
		mov eax, l;
		imul d;
		mov recPerim, eax;
		mov eax, width;
		imul d;
		add recPerim, eax;
	}

	cout << "Triangle" << endl;
	cout << "\tArea........................." << triArea << endl;
	cout << "\tPerimeter...................." << triPerim << endl;
	cout << "Rectangle" << endl;
	cout << "\tArea........................." << recArea << endl;
	cout << "\tPerimeter...................." << recPerim << endl;
	*/

	//Problem 3
	/*short cel, fahr;
	short f = 5, n = 9, c = 32;

	cout << "Enter temperature in Fahrenheit: ";
	cin >> fahr;

	_asm {
		mov ax, fahr;
		sub ax, c;
		imul f;
		cwd;
		idiv n;
		mov cel, ax;
	}

	cout << fahr << " F\370 is " << cel << " C\370" << endl;
	*/

	//Problem 4
	int n, x, y, z, total;
	int hun = 100;
	int ten = 10;
	cout << "Enter a 3 digit int number: ";
	cin >> n;
	_asm {
		mov eax, n;
		cdq;
		idiv hun;
		mov x, eax;
		mov eax, edx;
		cdq;
		idiv ten;
		mov y, eax;
		mov z, edx;
		mov total, edx;
		add edx, y;
		add edx, x;
		mov total, edx;
	}

	cout << "The total of digits in " << n << " is " << total << endl;

	system("pause");
	return 0;
}