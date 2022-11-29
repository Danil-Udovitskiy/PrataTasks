// Chapter 13 Task 4.cpp 

#include <iostream>
#include "Port.h"


int main()
{
	std::cout << "Port objects\n";
	std::cout << "\nconstructor with arguments\n";
	Port shirt("Gallo", "tawny", 8); //constructor with arguments
	shirt.Show();					 // Show function
	std::cout << shirt << "\n";		 // operator<<


	std::cout << "\ndefault values of constructor\n";
	Port pants; // default values of constructor
	pants.Show();
	std::cout << pants << "\n";


	//operation = 
	std::cout << "\noperation =\n";
	pants = shirt;
	pants.Show();
	std::cout << pants << "\n";


	//copy constructor
	std::cout << "\ncopy constructor\n";
	Port copy = Port(shirt);
	copy.Show();
	std::cout << copy << "\n";


	//operator +=
	std::cout << "\noperator +=\n";
	copy.operator+=(5);
	copy.Show();


	//operator -=
	std::cout << "\noperator -=\n";
	copy.operator-=(2);
	copy.operator-=(200); // subtracts from bottles if possible
	copy.Show();
	std::cout << "\nBottleCount "<< copy.BottleCount(); // BottleCount()



	std::cout << "\n\nVintagePort objects\n";
	//default constructor
	std::cout << "\ndefault constructor\n";
	VintagePort shirt1;
	shirt1.Show();
	std::cout << "\noperatoin <<\n";
	std::cout << shirt1 << "\n";

	
	//constructor with arguments
	std::cout << "\nconstructor with arguments\n";
	VintagePort pants1( "ruby", 5, "Hek", 1992);
	pants1.Show();


	//operation = 
	std::cout << "\noperation =\n";
	shirt1 = pants1;
	shirt1.Show();
	std::cout << shirt1 << "\n";


	//copy constructor
	std::cout << "\ncopy constructor\n";
	VintagePort copy1 = VintagePort(pants1);
	copy.Show();
	std::cout << copy << "\n";
}



