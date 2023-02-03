#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

class Good
{
private:
	std::string name;
	int number;
	float weight;

public:

	Good(std::string gName, int gNumber, float gWeight);

	friend std::ostream& operator<<(std::ostream& os, const Good& t);
	friend std::ostream& operator<(std::ostream& os, const Good& t);

	std::string getName();
	int getNumber();
	float getWeight();
	float getWeightOfAllGoods();

	void reduceQuantityGood(int count);

	virtual ~Good(); //the destructor is defined as virtual so that the memory is correctly freed in the function of reading from the file of the class Store
};



class Store
{
private:
	std::vector<Good> goods;
	bool isAvailable;

	//this is a helper function that is called in the constructor and reads data from the file
	void readDataFromFile(std::ifstream& dataFile);

public:
	Store(std::ifstream& dataFile); //read data from file to class

	void sortByName();
	void sortByNumber();
	void sortBySingleGoodWeight();
	void sortByAllGoodsWeight();
	void showByName(std::string name);
	void showByNumber(int min, int max);
	void showBySingleGoodWeight(float min, float max);
	void showByAllGoodsWeight(float min, float max);
	void showAllGoods();
	void showAllGoodsByName();

	void showStoreState();
	bool tryBuyGood(std::string name, int count);

	~Store(); //create a file and write the data from the class to the file
};

void showMenu();
