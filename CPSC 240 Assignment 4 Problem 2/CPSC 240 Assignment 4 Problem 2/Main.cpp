#include <iostream>
using namespace std;

char c;
int first = 0, second = 0;

void ask()
{
	cout << "Enter a sentence: ";
}

void read()
{
	cin.get(c);
}

void printC()
{
	cout << c;
}

void printCap()
{
	cout << char(c - 32);
}

void newline()
{
	cout << endl;
}

void output()
{
	cout << "\tOutput: ";
}

int main()
{
	_asm {
		call ask;
	whileLoop:
		call read;
		cmp c, '\n';
		Je done;
		cmp c, 'a';
		Je printUp;
		cmp c, 'e';
		Je printUp;
		cmp c, 'i';
		Je printUp;
		cmp c, 'o';
		Je printUp;
		cmp c, 'u';
		Je printUp;
		cmp first, 0;
		Je printOut;
	print:
		call printC;
		Jmp whileLoop;
	printUp:
		cmp second, 0;
		Je printOut2;
		call printCap;
		Jmp whileLoop;
	printOut:
		call output;
		call printC;
		inc first;
		inc second;
		Jmp whileLoop;
	printOut2:
		call output;
		call printCap;
		inc second;
		inc first;
		Jmp whileLoop;
	done:
		call newline;
	}

	system("pause");
	return 0;
}