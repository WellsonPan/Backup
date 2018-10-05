#include <iostream>
using namespace std;

int two = 2, three = 3, five = 5, numDrinks, numSandwich, sandwichType, bill;
char drinkType;

void getDrink()
{
	cout << "How many drinks? ";
	cin >> numDrinks;
	cout << "\tWhat kind of drink(S=Soda, W=Water)? ";
	cin >> drinkType;
}

void getSandwich()
{
	cout << "How many sandwiches? ";
	cin >> numSandwich;
	cout << "\tWhat size of sandwich(10/12 inches)? ";
	cin >> sandwichType;
}

void displayBill()
{
	cout << "Your total bill = $" << bill << endl;
}

int main()
{
	cout << "---------------7-11 Convenient Store---------------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda(S)...............................$2" << endl;
	cout << "\tWater(W)..............................$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 inches.............................$3" << endl;
	cout << "\t12 inches.............................$5" << endl;

	_asm {
		call getDrink;
		call getSandwich;
		mov eax, numDrinks;
		cmp drinkType, 'S';
		Je soda;
		mov bill, eax;
		Jmp sandwich;
	soda:
		imul two;
		mov bill, eax;
	sandwich:
		mov eax, numSandwich;
		cmp sandwichType, 10;
		Je ten;
		imul five;
		add bill, eax;
		Jmp done;
	ten:
		imul three;
		add bill, eax;
	done:
		call displayBill;
	}

	system("pause");
	return 0;
}