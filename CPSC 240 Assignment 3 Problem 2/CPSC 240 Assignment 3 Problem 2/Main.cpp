#include <iostream>
using namespace std;

int score = 0, scoreNum = 0, avg = 0;

void readScore()
{
	cout << "\tEnter your score (-1) to stop: ";
	cin >> score;
}

void displayAvg()
{
	cout << "\t\tYour average is " << avg << endl;
}

int main()
{
	cout << "Let's compute your score's average: " << endl;
	_asm {
	whileLoop:
		call readScore;
		cmp score, -1;
		Je done;
		mov eax, score;
		add avg, eax;
		inc scoreNum;
		Jmp whileLoop;
	done:
		mov eax, avg;
		cdq;
		idiv scoreNum;
		mov avg, eax;
		call displayAvg;
	}

	system("pause");
	return 0;
}