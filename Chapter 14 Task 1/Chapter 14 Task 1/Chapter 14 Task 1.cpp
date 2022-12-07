// Chapter 14 Task 1.cpp 
#include <iostream>
#include "Wine.h"
// wine class using include

int main()
{


	using std::cin;
	using std::cout;
	using std::endl;
	cout << "Enter name of wine: "; // Enter name of wine
	char lab[50];
	cin.getline(lab, 50);
	cout << "Enter number of years: "; // enter number of vintage years (grape)
	int yrs;
	cin >> yrs;
	

	Wine holding(lab, yrs); // save name, years,
							// create arrays from yrs elements
	
	holding.GetBottles();	// suggestion to enter year and number of bottles
	holding.Show();			// show data of object
	
	//Empty object with default constructor
	std::cout << "\nEmpty object\n";
	Wine holding1;
	holding1.Show();
	std::cout << "\n";


	const int YRS = 3;
	int y[YRS] = { 1993, 1995, 1998 };
	int b[YRS] = { 48, 60, 72 };


	// Create a new object, initialization
	// using data from arrays y and b
	Wine more("Gushing Grape Red", YRS, y, b); // using Wine(const char* l, int у, const int yr[], const int bot[]);
	more.Show(); 
	cout << "Total bottles for " << more.Label() // using Label() 
		<< ": " << more.sum() << endl;			 // using sum() 
	cout << "Bye\n";
	
	
	return 0;
}