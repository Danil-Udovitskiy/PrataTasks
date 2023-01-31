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
	
}



