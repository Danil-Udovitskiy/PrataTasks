// Chapter_17_Task_6.cpp 


#include <iostream>
#include "Emp.h"
#include <fstream>
#include <string>


int main()
{
	const int MAX = 10;
	Abstr_emp* pc[MAX];

	//check the first run of the program
	std::string file = "Data.txt";


	std::ifstream fin;
	fin.open(file); 


	int count = 0;

	if (fin.is_open())
	{
		// Display initial content
		std::cout << "FILE OPEN  - NOT FIRST START\nHere are the current contents of the " << file << " file: \n";

		char ch;
		int classtype;
		while ((fin >> classtype).get(ch)) // newline character separates integer from data

		{
			Abstr_emp* pt;
			switch (classtype)
			{

			case Abstr_emp::classkind::Employee: //determine the type of the object by the case
			{
				pt = new employee; //create an object
				pc[count] = pt; //assign an object to an array element
				pt->ReadAll(fin); //read function that reads the required fields
				break;
			}

			case Abstr_emp::classkind::Manager:
			{
				pt = new manager;
				pc[count] = pt;
				pt->ReadAll(fin); //read object
				break;
			}

			case Abstr_emp::classkind::Fink:
			{
				pt = new fink;
				pc[count] = pt;
				pt->ReadAll(fin); //read object
				break;
			}

			case Abstr_emp::classkind::Highfink:
			{
				pt = new highfink;
				pc[count] = pt;
				pt->ReadAll(fin); //read object
				break;
			}

			default:
			{
				break;
			}
			}
			count++;
		}
		fin.close();

	}
	else
	{
		std::cerr << "FILE NOT OPEN - FIRST START  " << file << "\n";
	}

	//call the show method on all objects
	for (int j = 0; j < count; j++)
	{
		pc[j]->ShowAll();
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
	if (count != MAX)
	{
		std::cout << "\n\nEnter data :\n";
	}

	int i;
	for (i = count; i < MAX; i++)
	{
		std::cout << "\n0 - quit\n Employee - 1  Manager - 2  Fink - 3  Highfink - 4: ";
		int choice;
		std::cin >> choice;

		if (choice == 0)
		{
			break;
		}

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
			std::cout << "Incorrect input, repeat 0 - 4\n";
			i--;
			break;
		}
		}//switch end

	}
	fout.close();


	//call the show method on all new objects
	for (int k = count; k < i; k++)
	{
		pc[k]->ShowAll(); 
	}

	
	return 0;

}