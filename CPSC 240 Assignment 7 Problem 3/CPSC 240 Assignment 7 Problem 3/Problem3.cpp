#include <iostream>
#include <iomanip>
using namespace std;

char drink;
int sandwich;
float drinkTotal, sandwichTotal, a = 2.25, b = 1.75, c = 3.45, d = 5.25, drinkAmount, sandwichAmount, total;

void printMenu()
{
	cout << "----------------- 7-11 Convenient Store -----------------" << endl;
	cout << "Drinks" << endl;
	cout << " Soda(S)............................................$" << a << endl;
	cout << " Water(W)...........................................$" << b << endl;
	cout << "Sandwiches" << endl;
	cout << " 10 inches..........................................$" << c << endl;
	cout << " 12 inches..........................................$" << d << endl;
}

void ask()
{
	cout << "How many drinks? ";
	cin >> drinkAmount;
	cout << "\tWhat kind of drink(S=Soda, W=Water)? ";
	cin >> drink;
	cout << "How many Sandwiches? ";
	cin >> sandwichAmount;
	cout << "\tWhat size sandwich (10/12 inches)? ";
	cin >> sandwich;
}

void print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Your total bill = " << total << endl;
}

int main()
{
	_asm {
		call printMenu;
		call ask;
		
		cmp drink, 'S';
		Je soda;
		fld drinkAmount;
		fld b;
		fmul;
		fstp drinkTotal;
	soda:
		fld drinkAmount;
		fld a;
		fmul;
		fstp drinkTotal;
		
		cmp sandwich, 10;
		Je tenInch;
		fld sandwichAmount;
		fld d;
		fmul;
		fstp sandwichTotal;
	tenInch:
		fld sandwichAmount;
		fld c;
		fmul;
		fstp sandwichTotal;

		fld drinkTotal;
		fld sandwichTotal;
		fadd;
		fstp total;

		call print;
	}

	system("pause");
	return 0;
}