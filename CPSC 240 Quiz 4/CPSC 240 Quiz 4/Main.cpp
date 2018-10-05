#include <iostream>
using namespace std;

char c;
int counter = 0, two = 2, first = 0;

void ask()
{
	cout << "Enter a sentence: ";
}

void read()
{
	cin.get(c);
}

void print()
{
	cout << c;
}

void printUp()
{
	cout << char(c - 32);
}

void cont()
{
	cout << "Continue(y/n)? ";
}

void newline()
{
	cout << endl;
}

void output()
{
	cout << "  Output: ";
}

void blank()
{
	cout << ' ';
}

int main()
{
	_asm {
		call ask;
		Jmp whileLoop;
	buffer:
		dec first;
		call read;
		call ask;
	whileLoop:
		call read;
		cmp c, '\n';
		Je cnt;
		cmp c, ' ';
		Je space;
		mov eax, counter;
		cdq;
		idiv two;
		cmp edx, 0;
		Je up;
		call print;
		inc counter;
		Jmp whileLoop;
	up:
		cmp first, 0;
		Je printOut;
		call printUp;
		inc counter;
		Jmp whileLoop;
	cnt:
		call newline;
		call cont;
		call read;
		cmp c, 'y';
		Je buffer;
		cmp c, 'Y';
		Je buffer;
		cmp c, 'n';
		Je done;
		cmp c, 'N';
		Je done;
	printOut:
		call output;
		call printUp;
		inc counter;
		inc first;
		Jmp whileLoop;
	space:
		call blank;
		Jmp whileLoop;
	done:
	}

	system("pause");
	return 0;
}