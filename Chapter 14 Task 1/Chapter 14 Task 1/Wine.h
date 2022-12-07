#pragma once
#include <iostream>
#include <string>
#include <valarray>
#include"Pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine
{
private:

	std::string name;
	int year;

	Pair< ArrayInt, ArrayInt > objects;

public:
	
	Wine();
	Wine(const char* l, int y);
	Wine(const char* l, int ó, const int yr[], const int bot[]);
	
	virtual ~Wine();

	void GetBottles();
	std::string& Label();
	int sum();
	void Show();
};

