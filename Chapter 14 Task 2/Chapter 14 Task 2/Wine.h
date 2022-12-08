#pragma once
#pragma once
#include <iostream>
#include <string>
#include <valarray>
#include"Pair.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine:private std::string, private  PairArray // private ArrayInt = private std::valarray<int>
{
private:

	int year;

public:

	Wine();
	Wine(const char* l, int y);
	Wine(const char* l, int ó, const int yr[], const int bot[]);

	virtual ~Wine();

	//void GetBottles();
	//const std::string& Label(); //const link to string
	//int sum();

	void Show();
};
