#include <iostream>
#include <ctime>
using namespace std;

int ran, index = 0;
unsigned short x, y, z;

void random()
{
	srand(time(0));
	ran = (rand() % 14) + 2;
}

void print()
{
	unsigned short z = 1 << 15;
	unsigned short t;
	for (int i = 1; i <= 16; ++i)
	{
		t = y & z;
		if (t == 0)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
		if (i % 4 == 0)
		{
			cout << " ";
		}
		y = y << 1;
	}
	cout << endl;
}

void elevatorPrompt()
{
	cout << "Elevator will stop at floors no. ";
}

void printFloors()
{
	cout << index << " ";
}

void newline()
{
	cout << endl;
}

int main()
{
	_asm {
		mov ax, 0000000000000000b;
	forloop:
		cmp index, 10;
		Je exitforloop;
		call random;
		mov x, 0000000000000001b;
		cmp ran, 2;
		Je two;
		cmp ran, 3;
		Je three;
		cmp ran, 4;
		Je four;
		cmp ran, 5;
		Je five;
		cmp ran, 6;
		Je six;
		cmp ran, 7;
		Je seven;
		cmp ran, 8;
		Je eight;
		cmp ran, 9;
		Je nine;
		cmp ran, 10;
		Je ten;
		cmp ran, 11;
		Je eleven;
		cmp ran, 12;
		Je twelve;
		cmp ran, 13;
		Je thirteen;
		cmp ran, 14;
		Je fourteen;
		cmp ran, 15;
		Je fifteen;
		cmp ran, 16;
		Je sixteen;
	two:
		shl x, 1;
		or ax, x;
		inc index;
		Jmp forloop;
	three:
		shl x, 2;
		or ax, x;
		inc index;
		Jmp forloop;
	four:
		shl x, 3;
		or ax, x;
		inc index;
		Jmp forloop;
	five:
		shl x, 4;
		or ax, x;
		inc index;
		Jmp forloop;
	six:
		shl x, 5;
		or ax, x;
		inc index;
		Jmp forloop;
	seven:
		shl x, 6;
		or ax, x;
		inc index;
		Jmp forloop;
	eight:
		shl x, 7;
		or ax, x;
		inc index;
		Jmp forloop;
	nine:
		shl x, 8;
		or ax, x;
		inc index;
		Jmp forloop;
	ten:
		shl x, 9;
		or ax, x;
		inc index;
		Jmp forloop;
	eleven:
		shl x, 10;
		or ax, x;
		inc index;
		Jmp forloop;
	twelve:
		shl x, 11;
		or ax, x;
		inc index;
		Jmp forloop;
	thirteen:
		shl x, 12;
		or ax, x;
		inc index;
		Jmp forloop;
	fourteen:
		shl x, 13;
		or ax, x;
		inc index;
		Jmp forloop;
	fifteen:
		shl x, 14;
		or ax, x;
		inc index;
		Jmp forloop;
	sixteen:
		shl x, 15;
		or ax, x;
		inc index;
		Jmp forloop;
	exitforloop:
		mov y, ax;
		call print;
		call elevatorPrompt;
		mov index, 16;
		mov z, 1000000000000000b;
	forloop2:
		cmp index, 0;
		Je endloop;
		mov ax, y;
		and ax, z;
		cmp ax, 0;
		Jne printIndex;
		dec index;
		shl y, 1;
		Jmp forloop2;
	printIndex:
		call printFloors;
		dec index;
		shl y, 1;
		Jmp forloop2;
	endloop:
		call newline;
	}

	system("pause");
	return 0;
}