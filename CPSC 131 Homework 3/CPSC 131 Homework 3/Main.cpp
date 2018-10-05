#include <iostream>
#include <string>
using namespace std;

template <typename filler>
class GenericArray {
private:
	filler *ptr;
	int size;
public:
	GenericArray(filler[], int);
	~GenericArray();
	void print()
	{
		for (int index = 0; index < size; index++)
		{
			cout << *(ptr + 0) << " ";
		}
		cout << endl;
	};
};

template <typename filler>
GenericArray<filler>::GenericArray(filler array[], int arraysize){
	ptr = array;
	size = arraysize;
}

template <typename filler>
GenericArray<filler>::~GenericArray(){
	delete[] ptr;
}

int main() {
	// using integer data type
	int arraya[5] = { 1, 2, 3, 4, 5 };
	GenericArray<int>a(arraya, 5);
	a.print();

	// using float data type
	float arrayb[5] = { 1.012, 2.324, 3.141, 4.221, 5.327 };
	GenericArray<float>b(arrayb, 5);
	b.print();

	// using string data type
	string arrayc[] = { "Ch1", "Ch2", "Ch3", "Ch4", "Ch5" };
	GenericArray<string>c(arrayc, 5);
	c.print();

	system("pause");
	return 0;
}