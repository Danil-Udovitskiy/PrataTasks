// Chapter_17_Task_3.cpp

#include <iostream>
#include <fstream>

// Text.txt pre-created
// WriteTo.txt may or may not be pre-created
// console input Chapter_17_Task_3 Text.txt WriteTo.txt

int main(int argc, char* argv[])
{
	//if less than 3 arguments passed
	if (argc < 3)
	{
		std::cerr << "Name of file    " << *argv << "\nSTOP\n";
		return 1;
	}

	std::ifstream fin; //create an ofstream object
	fin.open(argv[1]); //create and open a file with the name of the second command line argument

	// check if the file to be copied from is open
	if (!fin.is_open()) 
	{
		std::cerr << "FILE NOT OPEN   " << argv[1] << "\nSTOP\n";
		return 1;
	}


	std::ofstream fout; //create an ofstream object
	fout.open(argv[2]); //create and open a file with the name of the second command line argument
	
	// check if the file to be copied to is open
	if (fout.is_open())
	{
		//copying
		char ch;
		while (fin.get(ch)) //read via fin.get so that the words are separated by a newline character
		{
			fout << ch;
		}
	}
	else
	{
		std::cerr << "FILE NOT OPEN   " << argv[2] << "\nSTOP\n";
		return 1;
	}


	fout.close();
	fin.close();

	return 0;
}