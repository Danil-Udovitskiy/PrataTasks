#pragma once
#include <iostream>

//Listing 10.7 (pg 505- 506)

class Stock
{
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	void set_tot() { total_val = shares * share_val; }

public:
	Stock();
	Stock(const char* со, int n = 0, double pr = 0.0);
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;

	friend std::ostream& operator<<(std::ostream& os, const Stock& st); //operator overload <<
};
