#pragma once
#include <iostream>
#include <string>
#include <valarray>
#include"Pair.h"


class Wine
{
private:

	std::string name;
	int year;

	Pair< std::valarray<int>, std::valarray<int> > objects;



public:
	
	Wine();
	Wine(const char* l, int y);
	
	
	//Wine(const char* l, int ó, const int yr[], const int bot[]);

	//void GetBottles();

	//std::string& Label();
	//int sum();



	void Show();
	virtual ~Wine();


};

