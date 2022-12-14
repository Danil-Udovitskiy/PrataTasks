#pragma once
#include <iostream>

//Listing 10.7 (pg 505- 506)

class Stock
{

private:

	std::shared_ptr<char[]> company; //smart pointer shared_ptr correctly implements move semantics

	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }

	static int num; // number of objects

public:

	Stock(); 
	Stock(const char* co, int n = 0, double pr = 0.0);
	~Stock(); //added destructor for class objects 

	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;

	friend std::ostream& operator<<(std::ostream& os, const Stock& st); //operator overload <<
};
