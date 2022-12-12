// Chapter 14 Task 3.cpp

//Listing 14.12
//multiple inheritance

#include <iostream>
#include <cstring>
#include "Worker.h"

const int SIZE = 5;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	//the error was that I just created an array of pointers to the Worker, 
	//without using the Queue template


	Queue<Worker*> lolas(SIZE); //created a queue of pointers to the Worker
	Worker* obj = nullptr; //define a Worker type pointer to work with Queue (initialize with nullptr value so as not to allocate memory unnecessarily - (Worker* obj = new Waiter;) )
	
	//testing the creation of the Waiter, Singer and SingingWaiter objects from the ABS Worker
	
	while (!lolas.isfull()) //until the queue template is full, execute input
	{
		char choice;

		cout << "Enter the employee category:\n" // enter the employee category;
			<< "w: waiter  s: singer "
			<< " t: singing waiter (q - exit) ";
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter w / s / t / (q - exit) : ";
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
		case 'w':
		{
			obj = new Waiter; //assign the type of allocated memory to the pointer
			lolas.enqueue(obj); //add to the queue template
			break;
		}

		case 's': 
		{
			obj = new Singer;
			lolas.enqueue(obj);
			break;
		}

		case 't': 
		{
			obj = new SingingWaiter;
			lolas.enqueue(obj);
			break;
		}
		}
		cin.get();
		obj->Set();
	}

	cout << "\nHere is your staff list :\n"; // output the list of employees
	
	//improved display in case of empty / full / partially filled queue template
	if (lolas.isempty())
	{
	std::cout << "\nThe queue of employees is empty\n\n";
	}

	else if (lolas.isfull())
	{
		cout << "\nThe queue of employees is full\n\n";

		while (!lolas.isempty())
		{
			lolas.dequeue(obj);
			obj->Show();
			std::cout << "\n";
		}
	}

	else
	{
		std::cout << "\nThe queue of employees is not empty and not filled to the maximum\n\n";

		while (!lolas.isempty())
		{
			lolas.dequeue(obj);
			obj->Show();
			std::cout << "\n";
		}
	}
	
	cout << "Bye.\n";
	return 0;
}