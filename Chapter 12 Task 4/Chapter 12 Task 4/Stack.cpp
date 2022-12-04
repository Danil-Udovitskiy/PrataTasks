#include "Stack.h"

Stack::Stack(int n) //create a stack with n elements (or 10 elements by default)
{

	if (n >= MAX || n < 0)
	{
		pitems = new Item[MAX];
		size = MAX;
	}

	else 
	{
		pitems = new Item[n];
		size = n;
	}
	top = 0;
}



Stack::Stack(const Stack& st) // copy constructor
{

	pitems = new Item[st.size];
	for (int i = 0; i < st.size; i++)
		pitems[i] = st.pitems[i];
	size = st.size; 
	top = st.top;

}



Stack::~Stack() // destructor
{
	delete[]pitems;
}



Stack& Stack::operator= (const Stack& st)  // operator overload =
// Assigning a Stack object to a Stack object
{
	// check if the object is assigned to itself
	if (this == &st)
		return *this;

	delete[] pitems;

	size = st.size;
	top = st.top;
	pitems = new Item[st.size];
	for (int i = 0; i < st.size; i++)
		pitems[i] = st.pitems[i];
	return *this;
}




//By using listing 10.11 (pg 516-517)
bool Stack::isempty() const
{
	return top == 0;
}


bool Stack::isfull() const
{
	return top == size;
}


bool Stack::push(const Item& item)
{
	if (top < size)
	{
		pitems[top++] = item;
		return true;
	}
	else
		return false;
}


bool Stack::pop(Item& item)
{
	if (top > 0)
	{
		item = pitems[--top];
		return true;
	}
	else
		return false;
}