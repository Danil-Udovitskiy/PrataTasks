#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Good
{
private:
	std::string name;
	int number;
	float weight;

public:
	Good();
	~Good();

	Good(std::string gName, int gNumber, float gWeight);
	friend std::ostream& operator<<(std::ostream& os, const Good& t);

	std::string getName();
	int getNumber();
	float getWeight();
	float getWeightOfAllGoods();


};





class Store
{
private:
	std::vector<Good> goods;
	bool isAvailable = true;

	//��� ������� ��������, ������� ���������� � ������������ � ��������� ������ �� �����
	void readDataFromFile(std::ifstream& dataFile);

public:
	Store(std::ifstream& dataFile); //��� �� ��������� ������ �� ����� � �����
	
	/*void sortByName();
	void sortByNumber();
	void sortBySingleGoodWeight();
	void sortByAllGoodsWeight();
	void showByName(std::string name);
	void showByNumber(int mix, int max);
	void showBySingleGoodWeight(float min, float max);
	void showByAllGoodsWeight(float min, float max);
	void showAllGoods();
	void showStoreState();
	bool tryBuyGood(std::string name, int count);*/
	
	~Store(); //��� �� ������� ���� � ���������� ������ �� ������ � ����

};

