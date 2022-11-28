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
	std::string tempName;// название модели
	int tempWCode; // винкод

	char kind; //выбор объекта


	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter enter vehicle name: "; // ввод названия авто
		getline(cin, tempName);
		cout << "Enter win code "; // ввод вин-кода
		cin >> tempWCode;


		cout << "Enter 1 for Base Car or "
			<< "2 for DMA-lacks Car: "; // 1 — Base Car; 2 — DMA-lacks Car (со стоимостью или без)

		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2 : ";
		if (kind == '1')
			p_clients[i] = new Base(tempName, tempWCode);
		else
		{
			double tempPrice; // стоимость
			cout << "Enter price: $"; // ввод стоимости автомобиля
			cin >> tempPrice;

			p_clients[i] = new DMA_lacks(tempName, tempWCode, tempPrice);
		}
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