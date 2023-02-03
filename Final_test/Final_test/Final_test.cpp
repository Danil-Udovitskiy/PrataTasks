// Final_test.cpp 

#include <iostream>
#include "Good.h"
#include <fstream>


int main()
{
	//text file for input (pre-created)
	std::string first = "StoreInfo.txt";

	//open file
	std::ifstream fin; //create an ifstream object
	fin.open(first);

	Store obj(fin);

	bool work = true;

	while (work)
	{
		showMenu();

		int choice;
		std::cout << "\nEnter your operation:\n";
		std::cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
		{
			obj.showAllGoodsByName();
			system("pause");
			break;
		}
		case 2:
		{
			obj.sortByName();
			obj.showAllGoods();
			system("pause");
			break;
		}
		case 3:
		{
			obj.sortByNumber();
			obj.showAllGoods();
			system("pause");
			break;
		}
		case 4:
		{
			obj.sortBySingleGoodWeight();
			obj.showAllGoods();
			system("pause");
			break;
		}
		case 5:
		{
			obj.sortByAllGoodsWeight();
			obj.showAllGoods();
			system("pause");
			break;
		}
		case 6:
		{
			std::string name;
			std::cout << "Enter name :";
			std::cin >> name;
			obj.showByName(name);
			system("pause");
			break;
		}
		case 7:
		{
			int min = 0, max = 0;
			std::cout << "Enter min and max numbers :";
			std::cin >> min >> max;
			obj.showByNumber(min, max);
			system("pause");
			break;
		}
		case 8:
		{
			float min = 0, max = 0;
			std::cout << "Enter min and max single weight :";
			std::cin >> min >> max;
			obj.showBySingleGoodWeight(min, max);
			system("pause");
			break;
		}
		case 9:
		{
			float min = 0, max = 0;
			std::cout << "Enter min and max total weights :";
			std::cin >> min >> max;
			obj.showByAllGoodsWeight(min, max);
			system("pause");
			break;
		}
		case 10:
		{
			obj.showAllGoods();
			system("pause");
			break;
		}
		case 11:
		{
			obj.showStoreState();
			system("pause");
			break;
		}
		case 12:
		{
			std::string name;
			std::cout << "Enter name of good :";
			std::cin >> name;
			int number;
			std::cout << "Enter number of good :";
			std::cin >> number;

			obj.tryBuyGood(name, number);
			system("pause");
			break;
		}
		case 13:
		{
			work = false;
			break;
		}
		default:
		{
			std::cout << "Error choice\nPress enter to continue\n";
			std::cin.ignore();
			getchar();
			break;
		}
		}

	}

}



