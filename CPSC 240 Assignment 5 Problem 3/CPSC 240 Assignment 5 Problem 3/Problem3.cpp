#include <iostream>
using namespace std;

unsigned short a = 0x6A2f;
char bin[16] = "";
int on = 0, b = 0;
int off[16];

void hexToBin()
{
	unsigned short x = 1 << 15;
	unsigned short t;
	for (int i = 1; i <= 16; ++i)
	{
		t = a & x;
		if (t == 0)
		{
			cout << 0;
			bin[i-1] = '0';
			off[b] = 17 - i;
			b++;
		}
		else
		{
			cout << 1;
			bin[i-1] = '1';
			on++;
		}
		if (i % 4 == 0)
		{
			cout << " ";
		}
		a = a << 1;
	}
	cout << endl;
}

void numOn()
{
	cout << on << " sprinklers are ON" << endl;
}

void defective()
{
	cout << "Defective sprinklers: ";
	for (int i = 0; i < b; i++)
	{
		cout << off[i] << " ";
	}
	cout << endl;
}

int main()
{
	_asm {
		call hexToBin;
		call numOn;
		call defective;
	}
	system("pause");
	return 0;
}