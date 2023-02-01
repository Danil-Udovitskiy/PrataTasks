// Final_test.cpp 

#include <iostream>
#include "Good.h"
#include <fstream>


int main()
{
	//text file for input (pre-created)
	std::string first = "StoreInfo.txt";

	//text file for output
	std::string second = "StoreInfoUpdated.txt";

	//open files
	std::ifstream fin; //create an ifstream object
	fin.open(first);


	Store obbj(fin);
	obbj.showAllGoods();

	obbj.sortByName();
	std::cout << "\nsort name\n";
	obbj.showAllGoods();

	obbj.sortByNumber();
	std::cout << "\nsort number\n";
	obbj.showAllGoods();

	obbj.sortBySingleGoodWeight();
	std::cout << "\nsort single weight\n";
	obbj.showAllGoods();

	obbj.sortByAllGoodsWeight();
	std::cout << "\nsort all weight\n";
	obbj.showAllGoods();

	std::cout << "\nshow by name\n";
	obbj.showByName("gggg"); //Banana

	std::cout << "\nshow by number\n";
	obbj.showByNumber(1, 2);

	std::cout << "\nshow by weight\n";
	obbj.showBySingleGoodWeight(120, 300);

	std::cout << "\nshow by all weight\n";
	obbj.showByAllGoodsWeight(117, 200);

	
	std::cout << "\nshow menu\n";
	showMenu();

	std::cout << "\nshow store state\n";
	obbj.showStoreState();

	std::cout << "\ntry buy good\n";
	obbj.tryBuyGood("Banana", 6);
	obbj.tryBuyGood("Banana", 5);
	obbj.showAllGoods();

}



