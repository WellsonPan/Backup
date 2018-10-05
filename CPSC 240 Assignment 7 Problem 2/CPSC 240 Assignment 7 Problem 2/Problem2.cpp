#include <iostream>
#include <iomanip>
using namespace std;

float a, b, c, d, x1, x2, four = 4.0, two = 2.0, zero = 0.0;

void ask()
{
	cout << "To see the two real roots of aX^2 + bX + c = 0, enter the values for a, b, and c: ";
	cin >> a >> b >> c;
}

void print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\tX1 = " << x1 << "\tX2 = " << x2 << endl;
}

int main()
{
	_asm {
		call ask;
		fld b;
		fld b;
		fmul;
		fld four;
		fld a;
		fld c;
		fmul;
		fmul;
		fsub;
		fsqrt;
		fstp d;

		fld d;
		fld b;
		fsub;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x1;

		fld zero;
		fld d;
		fsub;
		fld b;
		fsub;
		fld two;
		fld a;
		fmul;
		fdiv;
		fstp x2;

		call print;
	}

	system("pause");
	return 0;
}