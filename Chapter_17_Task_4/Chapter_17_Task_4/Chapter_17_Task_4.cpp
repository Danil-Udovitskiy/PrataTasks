// Chapter_17_Task_4.cpp 

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	//two text files for input (pre-created)
	std::string first = "File1.txt"; //"C:\\Users\\user\\Desktop\\PrataTasks\\Chapter_17_Task_4\\Debug\\File1.txt";
	std::string second = "File2.txt"; //"C:\\Users\\user\\Desktop\\PrataTasks\\Chapter_17_Task_4\\Debug\\File2.txt";
	
	//text file for output
	std::string third = "File3.txt";

	//open files
	std::ifstream fin; //create an ifstream object
	fin.open(first);

	std::ifstream fin2; //create an ifstream object
	fin2.open(second);

	std::ofstream fout; //create an ofstream object
	fout.open(third);


	//Checking if all files were opened successfully
	if (fin.is_open() && fin2.is_open() && fout.is_open())
	{
		std::cout << "FILE OPEN   " << first << "\n";
		std::cout << "FILE OPEN   " << second << "\n";
		std::cout << "FILE OPEN   " << third << "\n";

		std::string temp;

		while (!fin.eof() || !fin2.eof()) //loop runs until one of the files is equal to end
		{
			if (!fin.eof())
			{
				std::getline(fin, temp); //read from the first file
				fout << temp << " "; //write string 
				
				//if second file eof - write new line
				if (fin2.eof())
				{
					std::cout << std::endl;
				}
			}

			if (!fin2.eof())
			{
				std::getline(fin2, temp); //read from the second file
				fout << temp << std::endl; //write string 
			}

		}
	}

	// check if the 1 file to be copied from is open
	else if (!fin.is_open())
	{
		std::cerr << "FILE NOT OPEN   " << first << "\nSTOP\n";
		return 1;
	}
	// check if the 2 file to be copied from is open
	else if (!fin2.is_open())
	{
		std::cerr << "FILE NOT OPEN   " << second << "\nSTOP\n";
		return 1;
	}
	// check if the 3 file to be copied to is open
	else if (!fout.is_open())
	{
		std::cerr << "FILE NOT OPEN   " << third << "\nSTOP\n";
		return 1;
	}

	fin.close();
	fin2.close();
	fout.close();
}





