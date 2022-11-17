// Chapter 12 Task 4.cpp 

#include <iostream>

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

	Stack(int n = 10); // creates a stack with n elements
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

	Stack& operator= (const Stack& st); // in the process
};


//++
Stack::Stack(int n) //create a stack with n elements (10 elements by default)
{
	pitems = new Item[MAX];
	size = n;
	top = 0;	
}




//++
Stack::Stack(const Stack& st) // copy constructor
{ 
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
		pitems[i] = st.pitems[i];
}



Stack::~Stack() // destructor
{
	delete[]pitems;
}


//By using listing 10.11 (pg 516-517)
bool Stack::isempty() const
{
	return top == 0;
}


bool Stack::isfull() const
{
	return top == MAX;
}


bool Stack::push(const Item& item)
{
	if (top < MAX)
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







int main()
{
	using namespace std;
	Stack st; // create a stack of 10 elements

	Stack st2 = Stack(st); //use the copy constructor

	//code testing by Listing 10.12 (pg 517-518)
	char ch;
	unsigned long ро;
	cout << " Please enter A to add an order.\n"
		<< " P - for order processing, Q - for exit.\n ";

	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}
		switch (ch)
		{
		case 'A':
		case 'a': cout << " Enter order number to add : ";
			cin >> ро;

			if (st.isfull())
				cout << " Stack is already full\n";
			else
				st.push(ро);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << " Stack is already empty\n";
			else
			{
				st.pop(ро);
				cout << " Order N# " << ро << " pushed out\n";
			}
			break;
		}
		cout << "\n Please enter A to add an order.\n"
			<< " P - for order processing, Q - for exit.\n";
	}


	cout << " All the best !\n";
	return 0;
}