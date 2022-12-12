// Chapter 14 Task 3.cpp

//Листинг 14.12
// workmi.срр — множественное наследование

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
	Worker* lolas[SIZE]; //создал очередь указателей на Worker


	//тестирую создание объекта Waiter от АБС Worker
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n" // ввод категории работника; 
			<< "w: waiter  s: singer (q - exit) "; // w - официант, s - певец, 
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter w / s : ";
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
		}
		cin.get();
		lolas[ct]->Set();
	}
	cout << "\nHere is your staff:\n"; // вывод списка работников 
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

