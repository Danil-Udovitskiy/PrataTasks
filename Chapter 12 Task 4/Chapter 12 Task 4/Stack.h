#pragma once

//class declaration for a stack ATD
typedef unsigned long Item;

class Stack
{
private:

	enum { MAX = 10 }; // class-specific constant
	Item* pitems; // stores the elements of the stack 
	int size; // number of elements on the stack
	int top; // index for the top element of the stack

public:

	Stack(int n = 10); //constructor creates a stack with n elements
	Stack(const Stack& st); // copy constructor
	~Stack(); // destructor
	bool isempty() const;
	bool isfull() const;

	// push() returns false if the stack is already full,
	// and true otherwise
	bool push(const Item& item); // adding an element to the stack

	// pop() returns false if the stack is already empty,
	// and true otherwise
	bool pop(Item& item); // popping an element from the stack

	Stack& operator= (const Stack& st); // operator overload =
};