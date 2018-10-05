#include <iostream>
#include <iomanip>
using namespace std;

float a, b, c, h, rectWidth, rectLength, triArea, triPerim, rectArea, rectPerim, two = 2.0;

void printMenu()
{
	cout << "       /|\\        ________________ " << endl;
	cout << "      / | \\      |                |" << endl;
	cout << "  a  /  |  \\ b   |                | width" << endl;
	cout << "    /  h|   \\    |                |" << endl;
	cout << "   /    |    \\   |                |" << endl;
	cout << "   ___________   __________________ " << endl;
	cout << "        C              length      " << endl;
}

void askTri()
{
	cout << "Enter the values of a, b, c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
}

void askRect()
{
	cout << "Enter the length and the width of the rectangle: ";
	cin >> rectLength >> rectWidth;
}

void print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\tTriangle" << endl;
	cout << "\t\tArea...................." << triArea << endl;
	cout << "\t\tPerimeter..............." << triPerim << endl;
	cout << "\tRectangle" << endl;
	cout << "\t\tArea...................." << rectArea << endl;
	cout << "\t\tPerimeter..............." << rectPerim << endl;
}

int main()
{
	_asm {
		call printMenu;
		call askTri;
		call askRect;

		fld c;
		fld h;
		fmul;
		fld two;
		fdiv;
		fstp triArea;

		fld a;
		fld b;
		fadd;
		fld c;
		fadd;
		fstp triPerim;

		fld rectWidth;
		fld rectLength;
		fmul;
		fstp rectArea;

		fld rectWidth;
		fld two;
		fmul;
		fld rectLength;
		fld two;
		fmul;
		fadd;
		fstp rectPerim;

		call print;
	}

	system("pause");
	return 0;
}