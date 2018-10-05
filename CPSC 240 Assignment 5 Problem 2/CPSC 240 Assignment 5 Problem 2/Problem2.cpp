#include <iostream>
using namespace std;

char c;
int total = 0, two = 2;

void valid()
{
	cout << " is a valid ID for the family" << endl;
}

void notValid()
{
	cout << " is not a valid ID for the family" << endl;
}

void read()
{
	cin.get(c);
}

int main()
{
	_asm {
	whileLoop:
		call read;
		cmp c, '\n';
		Je checkValid;
		cmp c, 'A';
		Je addTen;
		cmp c, 'B';
		Je addEleven;
		cmp c, 'C';
		Je addTwelve;
		cmp c, 'D';
		Je addThirteen;
		cmp c, 'E';
		Je addFourteen;
		cmp c, 'F';
		Je addFifteen;
	addTen:
		add total, 10;
		Jmp whileLoop;
	addEleven:
		add total, 11;
		Jmp whileLoop;
	addTwelve:
		add total, 12;
		Jmp whileLoop;
	addThirteen:
		add total, 13;
		Jmp whileLoop;
	addFourteen:
		add total, 14;
		Jmp whileLoop;
	addFifteen:
		add total, 15;
		Jmp whileLoop;
	checkValid:
		mov eax, total;
		cdq;
		idiv two;
		cmp edx, 0;
		Je validID;
	invalid:
		call notValid;
		mov total, 0;
		Jmp done;
	validID:
		call valid;
		Jmp whileLoop;
	done:
	}

	system("pause");
	return 0;
}