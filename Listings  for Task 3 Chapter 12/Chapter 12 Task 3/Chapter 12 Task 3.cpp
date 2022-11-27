// Chapter 12 Task 3.cpp 
//Listing 10.9

#include <iostream>
#include "Stock.h"

// Initialize a static class member
int Stock::num = 0;

const int STKS = 4;
int main()
{
	using std::cout;
	using std::ios_base;

	//create an array of initialized objects
	Stock stocks[STKS] = {
	Stock("NanoSmart", 12, 20.0) ,
	Stock("Boffo Objects ", 200, 2.0),
	Stock("Monolitic Obelisks", 130, 3.25) ,
	Stock("Fleep Enterprises", 60, 6.5) };

	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);
	cout << " Share packages :\n";

	int st;
	for (st = 0; st < STKS; st++)
	std::cout<<stocks[st]; //using operator <<

	//creating a pointer to 1 element of an array of objects Stock
	const Stock* top = &stocks[0]; // or const Stock *top = (address) stocks first element pointer 

	for (st = 1; st < STKS; st++)
	top = &top->topval(stocks[st]);

	cout << "\n The biggest package : \n" << *top; //using operator <<
	
	return 0;
	
}
