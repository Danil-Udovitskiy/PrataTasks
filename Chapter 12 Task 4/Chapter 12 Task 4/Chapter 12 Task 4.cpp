// Chapter 12 Task 4.cpp 

#include <iostream>
#include <cctype>
#include "Stack.h"


int main()
{
	using namespace std;
	Stack st1; // create a stack of 10 elements

	Stack st2 = Stack(st1); //use the copy constructor

	st2 = st1; // use operation of overloaded operation =
	
	// create a stacks of 10 elements (default)
	Stack st3(-1); 
	Stack st4(15);
	
	// create a stacks of 5 elements
	Stack st(5);
	Stack second (st);


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

			if (second.isfull())
				cout << " Stack is already full\n";
			else
				second.push(ро);
			break;

		case 'P':
		case 'p':
			if (second.isempty())
				cout << " Stack is already empty\n";
			else
			{
				second.pop(ро);
				cout << " Order N# " << ро << " pushed out\n";
			}
			break;

		default:
			std::cout << " Unknown\n";
			break;
		}
		
		cout << "\n Please enter A to add an order.\n"
			<< " P - for order processing, Q - for exit.\n";
	}


	cout << " All the best !\n";
	return 0;
}