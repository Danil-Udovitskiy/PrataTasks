// Chapter 13 Task 3.cpp 

#include <iostream>
#include <string>
#include "Base.h"


const int CLIENTS = 4;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;


	Base* p_clients[CLIENTS];
	std::string tempName;
	int tempWCode;
	//char kind;


	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter enter vehicle name: "; // ввод названия авто
		getline(cin, tempName);
		cout << "Enter win code "; // ввод вин-кода
		cin >> tempWCode;

		p_clients[i] = new Base(tempName, tempWCode);

		while (cin.get() != '\n')
			continue;
	}


	cout << endl;
	for (int i = 0; i < CLIENTS; i++)
	{
		p_clients[i]->View();
		cout << endl;
	}


	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i]; // освобождение памяти 
	}
	cout << "Done.\n";
	return 0;
}