#pragma once

#include <stdexcept>

using namespace std;

template <typename E> class DLinkedList;	// forward declaration to be used when declaring DNode

template <typename E>
class DNode {					            // doubly linked list node
private:
	E elem;					               // node element value
	DNode<E> *prev;				         // previous node in the list
	DNode<E> *next;				         // next node in the list
	friend class DLinkedList<E>;		   // provide SLinkedList access
};

template <typename E>
class DLinkedList {	                  // a doubly linked list
public:
	DLinkedList();				            // empty list constructor
	~DLinkedList();				         // destructor
	bool empty() const;			         // is list empty?
	E& front();							// get front element
	E& back();							// get back element
	void addFront(const E& e);		      // add to front of list
	void addBack(const E& e);		      // add to back of list
	void removeFront();			         // remove from front
	void removeBack();			         // remove from back
	int size() const;					// list size
	void swapFirstAndLast();
private:                               // local type definitions
	int     n;							// number of items
	DNode<E>* header;				         // header sentinel
	DNode<E>* trailer;                  // trailer sentinel
protected:
	void add(DNode<E>* v, const E& e);     // insert new node before v
	void remove(DNode<E>* v);              // remove node v
};

template <typename E>
DLinkedList<E>::DLinkedList() {        // constructor
	n = 0;							// initially empty
	header = new DNode<E>;              // create sentinels
	trailer = new DNode<E>;
	header->next = trailer;             // have them point to each other
	trailer->prev = header;
}

template <typename E>
bool DLinkedList<E>::empty() const	   // is list empty?
{
	return (header->next == trailer);
}

template <typename E>
E& DLinkedList<E>::front() 	// return front element
{
	if (empty()) throw length_error("empty list");
	return header->next->elem;
}

template <typename E>
E& DLinkedList<E>::back() 	// get back element
{
	if (empty()) throw length_error("empty list");
	return trailer->prev->elem;
}

template <typename E>
DLinkedList<E>::~DLinkedList() {	      // destructor
	while (!empty()) removeFront();     // remove all but sentinels
	delete header;				            // remove the sentinels
	delete trailer;
}

template <typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e) {
	DNode<E>* u = new DNode<E>;               // create a new node for e
	u->elem = e;
	u->next = v;				                  // link u in between v
	u->prev = v->prev;				            // ...and v->prev
	v->prev->next = u;
	v->prev = u;
	n++;
}

template <typename E>
void DLinkedList<E>::addFront(const E& e)	   // add to front of list
{
	add(header->next, e);
}

template <typename E>
void DLinkedList<E>::addBack(const E& e)	   // add to back of list
{
	add(trailer, e);
}

template <typename E>
void DLinkedList<E>::remove(DNode<E>* v) {	// remove node v
	DNode<E>* u = v->prev;				         // predecessor
	DNode<E>* w = v->next;				         // successor
	u->next = w;				                  // unlink v from list
	w->prev = u;
	delete v;
	n--;
}

template <typename E>
void DLinkedList<E>::removeFront()		// remove from font
{
	if (empty()) throw length_error("empty list");
	remove(header->next);
}

template <typename E>
void DLinkedList<E>::removeBack()		// remove from back
{
	if (empty()) throw length_error("empty list");
	remove(trailer->prev);
}

template <typename E>
int DLinkedList<E>::size() const {				// list size
	return n;
}

template <typename E>
void DLinkedList<E>::swapFirstAndLast()
{
	try
	{
		if (n == 0)
		{
			throw "There are no elements in the list so length_error exception is thrown";
		}	
		else if (n == 1)
		{
			throw "There is 1 element in the list so it will print twice";
		}
		else if (n == 2)
		{
			DNode<E> * temp = new DNode<E>;

			temp->prev = header;
			temp->next = trailer->prev;

			header->next->prev = trailer->prev;
			header->next->next = trailer;
			header->next = trailer->prev;
			trailer->prev->next = trailer->prev->prev;
			trailer->prev->prev = header;
			trailer->prev = header->next->next;
		}
		else
		{
			DNode<E> * temp1 = header->next;
			DNode<E> * temp2 = header->next->next;
			DNode<E> * temp3 = trailer->prev->prev;

			header->next->next = trailer;
			header->next->prev = temp3;
			header->next = trailer->prev;
			trailer->prev->prev = header;
			trailer->prev->next = temp2;
			temp2->prev = trailer->prev;
			temp3->next = temp1;
			trailer->prev = temp1;

		}
	}
	catch(const char* e)
	{
		cout << e << endl;
	}
}