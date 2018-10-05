#include <iostream>
using namespace std;

int a[3][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
int index, total = 0;


void printTotal()
{
	cout << "There are a total of " << total << " shirts" << endl;
}

void printMedium()
{
	cout << "There are a total of " << total << " medium shirts" << endl;
}

int main()
{
	_asm {
		mov index, 0;
		mov total, 0;
		mov ebx, 0;
	forloopa:
		cmp index, 18;
		Je endloop;
		mov eax, [a + ebx];
		add total, eax;
		inc index;
		add ebx, 4;
		Jmp forloopa;
	endloop:
		call printTotal;

		mov index, 0;
		mov total, 0;
		mov ebx, 0;
	forloopb:
		cmp index, 6;
		Je endloopb;
		mov eax, [a + ebx];
		add total, eax;
		add ebx, 4;
		mov eax, [a + ebx];
		add total, eax;
		add ebx, 20;
		inc index;
		Jmp forloopb;
	endloopb:
		call printMedium;


		mov index, 0;
		mov total, 0;
		mov ebx, 0;
	}

	system("pause");
	return 0;
}