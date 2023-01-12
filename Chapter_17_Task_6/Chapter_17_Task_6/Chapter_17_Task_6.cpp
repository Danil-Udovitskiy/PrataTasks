// Chapter_17_Task_6.cpp 


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
	std::string name;
	while (getline(std::cin, name) && name.size() > 0)
	{
		fout << name << std::endl;
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

	//array of pointers to employee
	employee* pc[MAX];










	std::cout << "Employee\n\n";
	employee em("Trip", "Harris", "Thumper");
	std::cout << em << "\n";
	em.ShowAll();


	std::cout << "\n\nManager\n\n";
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	std::cout << ma << "\n";
	ma.ShowAll();


	std::cout << "\n\nFink\n\n";
	fink fi("Matt", "Oggs", "Oiler", "JunoBarr");
	std::cout << fi << "\n";
	fi.ShowAll();


	std::cout << "\n\nHighfink\n\n";
	highfink hf(ma, "Curly Kew");
	hf.ShowAll();


	std::cout << "\n\nPress a key for next phase:\n";

	std::cin.get();
	highfink hf2;
	hf2.SetAll();
	std::cout << "Using an abstr_emp * pointer:\n";
	// Using a pointer abstr_emp * 
	Abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };
	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();




	return 0;

}