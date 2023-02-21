#pragma once
#include <iostream>

struct  Good
{
public:
	double price = 0.0;
	double weight = 0.0;

	friend std::ostream& operator<< (std::ostream& out, const Good& point);
};