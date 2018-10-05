#include<iostream>
using namespace std;

int main()
{
	int x = 11, y = 7, z = 85;
	int *ptr;

	cout << "Here are the values of x, y, and z:\n";
	cout << x << " " << y << " " << z << endl;

	ptr = &x;
	*ptr *= 2;

	ptr = &y;
	*ptr *= 2;

	ptr = &z;
	*ptr *= 2;

	cout << "Once again, here are the values of x, y, and z:\n";
	cout << x << " " << y << " " << z << endl;

	system("pause");
	return 0;
}