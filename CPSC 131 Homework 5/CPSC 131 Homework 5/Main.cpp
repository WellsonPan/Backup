#include <iostream>
#include <string>
#include "DLinkedList.h"

using namespace std;

int main()
{
	DLinkedList<string> names;

	string name1 = "Brenda", name2 = "Wellson";
	names.addFront(name1);
	names.addBack(name2);

	names.swapFirstAndLast();

	cout << names.front() << endl;
	cout << names.back() << endl;

	system("pause");
	return 0;
}