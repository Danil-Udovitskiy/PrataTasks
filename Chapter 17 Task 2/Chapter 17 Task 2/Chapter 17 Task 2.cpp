// Chapter 17 Task 2.cpp 

#include <iostream>


int main(int argc, char* argv[])
{
	if (argc == 1)  //if the file name is not passed on the command line (substituted automatically)
	{
		std::cerr << "Name of file    " << *argv << "\n";
		return 1;
	}
}