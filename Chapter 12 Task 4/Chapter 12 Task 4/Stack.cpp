#include "Stack.h"

Stack::Stack(int n) //create a stack with n elements (10 elements by default)
{
	pitems = new Item[MAX];
	size = n;
	top = 0;


	//or I can use size to allocate memory for 10 elements on the stack, 
	//but then size would need to be initialized first with the value of the formal argument n
	/*size = n;
	top = 0;
	pitems = new Item[n]; // or new Item[size]*/
}



Stack::Stack(const Stack& st) // copy constructor
{
	/*size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
		pitems[i] = st.pitems[i];*/


	//or I can use MAX to allocate memory for 10 elements on the stack, 
	//but then size would need to be initialized first with the value of the formal argument n
	pitems = new Item[MAX];
	for (int i = 0; i < MAX; i++)
		pitems[i] = st.pitems[i];
	size = MAX; //size can also have a value of MAX, bacause in any case, the stack is created for 10 elements
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

	size = st.size; // or size = st.MAX or size = MAX
	top = st.top;
	pitems = new Item[size]; // or new Item[MAX]
	for (int i = 0; i < size; i++) //  or i < MAX;
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
	return top == MAX; //or top == size
}


bool Stack::push(const Item& item)
{
	if (top < MAX) //or top < size
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