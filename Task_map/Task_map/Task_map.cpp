// Task_map.cpp 

#include <iostream>
#include <map>
#include <string>
#include "Good.h"

void showMenu();

int main()
{
	std::map<std::string, Good>goods;

	Good obj;

	bool work = true;

	while (work)
	{
		showMenu();

		int choice;
		std::cout << "\nEnter your operation:\n";
		std::cin >> choice;
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cout << "Enter correct operation : ";
			std::cin >> choice;
		}

		system("cls");

		switch (choice)
		{
		case 1:
		{
			std::string name;
			double price;
			double weight;


			std::cout << "Enter name : ";
			std::cin >> name;

			std::cout << "Enter price : ";
			std::cin >> price;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "Enter correct price again : ";
				std::cin >> price;
			}

			obj.price = price;

			std::cout << "Enter weight : ";
			std::cin >> weight;
			while (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "Enter correct weight again : ";
				std::cin >> weight;
			}
			obj.weight = weight;

			goods.insert(make_pair(name, obj));

			system("cls");
			break;
		}
		case 2:
		{
			std::string name;
			std::cout << "Enter name to delete : ";
			std::cin >> name;

			system("cls");

			auto it = goods.find(name);
			if (it != goods.end())
			{
				goods.erase(name);
				std::cout << "Good " << name << " deleted\n\n";
			}
			else
			{
				std::cout << "No item with this name\n\n";
			}

			break;
		}
		case 3:
		{
			if (goods.empty())
			{
				std::cout << "Its no goods.\n\n";
			}
			else
			{
				for (auto i = goods.begin(); i != goods.end(); i++)
				{
					std::cout << i->first << " " << i->second << "\n";
				}
				std::cout << "\n";
			}

			break;
		}
		case 4:
		{
			std::string name;
			std::cout << "Enter name to find : ";
			std::cin >> name;

			system("cls");
			auto it = goods.find(name);
			if (it != goods.end())
			{
				std::cout << it->first << "\n";
				std::cout << it->second << "\n\n";
			}
			else
			{
				std::cout << "No item with this name\n\n";
			}

			break;
		}
		case 5:
		{
			work = false;
			break;
		}
		default:
		{
			std::cout << "Wrong input\nPress enter to continue\n\n";
			std::cin.ignore(INT_MAX, '\n');
			break;
		}
		}

	}
}


void showMenu()
{
	std::cout << "Press 1 to ADD good\n";
	std::cout << "Press 2 to DELETE good\n";
	std::cout << "Press 3 to SHOW ALL goods\n";
	std::cout << "Press 4 to FIND good\n";
	std::cout << "Press 5 to EXIT\n";
}
