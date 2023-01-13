﻿// Chapter_17_Task_6.cpp 


#include <iostream>
#include "Emp.h"
#include <fstream>
#include <string>


int main()
{
	const int MAX = 10;

	//check the first run of the program
	std::string file = "Data.txt";


	std::ifstream fin;
	fin.open(file);
	char ch;

	if (fin.is_open())
	{
		std::cout << "FILE OPEN  - NOT FIRST START " << file << "\n";
		
		// Display initial content
		std::cout << "Here are the current contents of the " << file << " file: \n";
		while (fin.get(ch))
			std::cout << ch;
		fin.close();
	}
	else
	{
		std::cerr << "FILE NOT OPEN - FIRST START  " << file << "\n";
	}




	// Adding new data
	std::ofstream fout;
	fout.open(file, std::ios_base::out | std::ios_base::app); // create a file with the ability to append data to the end of the file

	if (!fout.is_open())
	{
		std::cerr << "FILE FOR OUTPUT NOT OPEN   " << file << "\nSTOP\n";
		return 1;
	}


	//++
	//read data(input)
	std::cout << "Enter data (enter a blank line to quit):\n";

	Abstr_emp* pc[MAX];

	for (int i = 0; i < MAX; i++)
	{
		std::cout << "Employee - 1  Manager - 2  Fink - 3  Highfink - 4: ";
		int choice;
		std::cin >> choice;

		switch (choice)
		{
		case 1:
		{
			pc[i] = new employee;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		}

		case 2:
		{
			pc[i] = new manager;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		}

		case 3:
		{
			pc[i] = new fink;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		}

		case 4:
		{
			pc[i] = new highfink;
			pc[i]->SetAll();
			pc[i]->WriteAll(fout);
			break;
		}

		default:
		{
			std::cout << "Incorrect input, repeat 1 - 4\n";
			i--;
			break;
		}
		}//switch end


	}
	fout.close();



	// Display changed file
	fin.clear();
	
	fin.open(file);
	// check open
	if (!fin.is_open())
	{
		std::cerr << "FILE NOT OPEN   " << file << "\nSTOP\n";
		return 1;
	}
	//show
	if (fin.is_open())
	{
		std::cout << "Here are the new contents of the " << file << " file:\n";
		while (fin.get(ch))
			std::cout << ch;
		fin.close();
	}

	

	return 0;

}