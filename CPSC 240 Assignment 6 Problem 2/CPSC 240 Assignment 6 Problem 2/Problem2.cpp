#include <iostream>
using namespace std;

int a[5] = {9, 3, 22, 8, 1};
int i, j, n;

void printOrg()
{
	cout << "Original array a: ";
}

void printSorted()
{
	cout << "Sorted array a: ";
}

void newline()
{
	cout << endl;
}

void printArray()
{
	for (int k = 0; k < 5; k++)
	{
	cout << a[k] << " ";
	}
}

int main()
{
	_asm {
		call printOrg;
		call printArray;
		mov i, 0;
	forloop:
		cmp i, 4;
		Jge endloop;
		mov j, 0;
		mov ebx, 0;
		mov eax, i;
		mov n, 4;
		sub n, eax;
		mov ecx, n;
	forloop2:
		cmp j, ecx;
		Jge endloop2;
		mov ecx, [a + ebx];
		cmp ecx, [a + ebx + 4];
		Jg switcher;
	contforloop2:
		inc j;
		add ebx, 4;
		Jmp forloop2;
	switcher:
		xchg [a + ebx + 4], ecx;
		mov [a + ebx], ecx;
		Jmp contforloop2;
	endloop2:
		inc i;
		Jmp forloop;
	endloop:
		call newline;
		call printSorted;
		call printArray;
		call newline;
	}

	system("pause");
	return 0;
}