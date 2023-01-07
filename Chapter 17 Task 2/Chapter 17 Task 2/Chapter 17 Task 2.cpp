// Chapter 17 Task 2.cpp 

#include <iostream>
#include <fstream>

//console input "Chapter 17 Task 2" Text
//because of the spaces in the title of programm file

int main(int argc, char* argv[])
{
	if (argc == 1)  //if the file name is not passed on the command line (substituted automatically)
	{
		std::cerr << "Name of file    " << *argv << "\nSTOP\n";
		return 1;
	}


	std::ofstream fout; //create an ofstream object
	fout.open(argv[1]); //create and open a file with the name of the second command line argument

	if (fout.is_open())
	{
		std::cout << "FILE OPEN\n" << "Write symbols please:\n";
		//copy keyboard input
		char ch;
		while (std::cin.get(ch)) //read via cin.get so that the words are separated by a newline character
		{
			fout << ch;
		}
	}
	else
	{
		std::cerr << "FILE NOT OPEN   " << argv[1] << "\nSTOP\n";
		return 1;
	}

	fout.close();
	return 0;
}