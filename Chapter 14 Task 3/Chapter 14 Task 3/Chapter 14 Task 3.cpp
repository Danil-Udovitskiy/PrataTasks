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
	Worker* lolas[SIZE]; //created a queue of pointers to the Worker


	//testing the creation of the Waiter object from the ABS Worker
	int ct;
	for (ct = 0; ct < SIZE; ct++)
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
		case 'w': lolas[ct] = new Waiter;
			break;

		case 's': lolas[ct] = new Singer;
			break;

		case 't': lolas[ct] = new SingingWaiter;
			break;
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\nHere is your staff:\n"; // output the list of employees
	int i;
	for (i = 0; i < ct; i++)
	{
		cout << endl;
		lolas[i]->Show();
	}
	for (i = 0; i < ct; i++)
		delete lolas[i];


	cout << "Bye.\n";
	return 0;
}

