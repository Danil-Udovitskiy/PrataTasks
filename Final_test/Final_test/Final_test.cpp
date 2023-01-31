// Final_test.cpp 

#include <iostream>
#include "Good.h"
#include <fstream>



int main()
{
	//чтение из одного файла, запись в другой

	//text file for input (pre-created)
	std::string first = "StoreInfo.txt";

	//text file for output
	std::string second = "StoreInfoUpdated.txt";

	//open files
	std::ifstream fin; //create an ifstream object
	fin.open(first);

	std::ofstream fout; //create an ofstream object
	fout.open(second);

	Store obbj(fin);
	





	/*Good obj("ddd", 10, 1.34);
	std::cout << obj << "\n";


	//returns the product name
	std::cout << "getName() " << obj.getName() << "\n";
	//returns the number of product units
	std::cout << "getNumber() " << obj.getNumber() << "\n";
	//returns the weight of the item
	std::cout << "getWeight() " << obj.getWeight() << "\n";

	std::cout << "\n";
	Good obj2("aaa", 5, 3.3);
	std::cout << obj2 << "\n";

	std::cout << "Weight of all goods " << obj.getWeightOfAllGoods() << "\n";*/
}



