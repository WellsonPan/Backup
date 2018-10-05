#pragma once
#include "ExtendableVector.h"
using namespace std;

template <typename E>
class ExtendableVectorStack {
private:
	// “wrap” the ExtendableVector here along with other variables necessary to implement the public methods
	ExtendableVector<E> stack;

public:
	ExtendableVectorStack()
	{
		stack();
	}// constructor: no need to specify capacity!

	int size()
	{
		return stack.size();
	}// number of items in the stack

	bool empty()
	{
		return stack.empty();
	}// is the stack empty?

	E& top()
	{
		return stack.at(0);
	}// get the top element

	void push(E& e)
	{
		stack.(0, e);
	}// push element onto stack

	void pop()
	{
		stack.erase(0);
	}// pop the stack
};