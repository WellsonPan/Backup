#include <iostream>
#include "SingleLinkedList.h"

using namespace std;

class PolyArray
{
public:
	PolyArray();
	PolyArray(double coeffArray[], int arraysize);  // degree = arraysize -1;
	PolyArray(const PolyArray& poly);
	~PolyArray();
	double evaluate(const double& x) const;
private:
	double *coeff;     // coefficients of polynomial function
	int n;            // degree of polynomial function 

};

PolyArray::PolyArray() {   // default constructor
	n = 0;
	coeff = new double[n + 1];  // dynamically create an array of size 1
	coeff[0] = 0.0;
}

double PolyArray::evaluate(const double& x) const
{
	double total = 0.0;
	for (int i = 0; i < n; i++)
	{
		total += coeff[i] * pow(x, i);
	}
	return total;
}

PolyArray::PolyArray(double coeffArray[], int arraySize)
{
	n = arraySize;
	coeff = new double[arraySize];
	for (int index = 0; index < arraySize; index++)
	{
		coeff[index] = coeffArray[index];
	}
}

PolyArray::PolyArray(const PolyArray& poly)
{
	n = poly.n;
	coeff = new double[(poly.n)];
	for (int index = 0; index < poly.n; index++)
	{
		coeff[index] = poly.coeff[index];
	}
}

PolyArray::~PolyArray()
{
	delete[] coeff;
}

/**********************************************************************************************************************************************
**********************************************************************************************************************************************/

class PolyTerm {
private:
	int _order;
	double _coeff;

public:
	void setOrder(int order) {
		_order = order;
	}
	void setCoeff(double coeff) {
		_coeff = coeff;
	}
	int getOrder() {
		return _order;
	}
	double getCoeff() {
		return _coeff;
	}

};

int main()
{
	// polynomial function y = 3.5*x^7 + 2.2 using array
	// this function is the same as 2.2*x^0 + 0*x^1 + 0*x^2 + 0*x^3 + 0*x^4 + 0*x^5 + 0*x^6 + 3.5*x^7

	cout << "Array Answer" << endl;
	double coeffArray[8] = { 2.2, 0, 0, 0, 0, 0, 0, 3.5 };
	PolyArray polyArray(coeffArray, 8);
	cout << polyArray.evaluate(1.0) << endl;
	cout << polyArray.evaluate(2.0) << endl;
	cout << endl;

	// polynomial function y = 3.5*x^7 + 2.2 using linked list 
	SLinkedList<PolyTerm> polyLinkedList;

	PolyTerm polyterm1, polyterm2;

	polyterm1.setOrder(0);
	polyterm1.setCoeff(2.2);

	polyterm2.setOrder(7);
	polyterm2.setCoeff(3.5);

	polyLinkedList.addFront(polyterm1);
	polyLinkedList.addFront(polyterm2);

	// develop your initialization part here

	cout << "Linked List Answer" << endl;
	cout << polyLinkedList.evaluate(1.0) << endl;
	cout << polyLinkedList.evaluate(2.0) << endl;
	cout << endl;

	system("pause");
	return 0;
}