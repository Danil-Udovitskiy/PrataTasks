// Chapter 13 Task 3.cpp 

#include <iostream>
#include <string>
#include "Base.h"


const int objects = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	std::shared_ptr<BaseABC> p_clients; //smart pointer 

	std::string tempName; // brand name
	int tempWCode; // wincode

	int kind; // object selection



	for (int i = 0; i < objects; i++)
	{
		cout << "Enter vehicle name: "; // enter the name of the car
		getline(cin, tempName);
		cout << "Enter win code "; // enter VIN code
		cin >> tempWCode;

		// 1 - DMA-lacks Car (со стоимостью авто)
		// 3 - DMA-has Car (с весом авто)
		// 3 - DMA Car (с максимальной скоростью авто и названием модели)

		cout << "Enter 1 for DMA-lacks Car:\n"
			<< "or 2 for DMA-has Car:\n"
			<< "or 3 for DMA Car:\n";


		while (cin >> kind)
		{
			switch(kind)
			{

			case 1:
			{
			 //we cant create ABC class object, beacouse of clear function
			 //p_clients[i] = new Base(tempName, tempWCode);

			 double tempPrice; // price
			 cout << "Enter price: $ "; // entering the cost of the car
			 cin >> tempPrice;

			 p_clients.reset(new DMA_lacks(tempName, tempWCode, tempPrice));

			 break;
			}

			case 2:
			{
			 double tempWeight; // weight
			 cout << "Enter weight: kg "; // entering the weight of the car
			 cin >> tempWeight;

			 p_clients.reset(new DMA_has(tempName, tempWCode, tempWeight));

			 break;
			}

			case 3:
			{
			 int tempMaxSpeed;// max speed
			 cout << "Enter max speed : "; // entering the max speed of the car
			 cin >> tempMaxSpeed;

			 std::string tempName2;// name model
			 cout << "Enter name2 : "; // entering the name model of the car
			 cin >> tempName2;

			 p_clients.reset(new DMA(tempName, tempWCode, tempMaxSpeed, tempName2));

			 break;
			}

			}

			//break FOR cycle
			if (kind < 1 || kind > 3)
			{
				std::cout << "Wrong input. Enter either 1 or 2 or 3 : ";
			}
			else
			{
				break;
			}
		}


			while (cin.get() != '\n');
			continue;
		
	}


	cout << endl;
	for (int i = 0; i < objects; i++)
	{
		p_clients.get()->View();
		cout << endl;
	}


	cout << "Done.\n";
	return 0;
}

