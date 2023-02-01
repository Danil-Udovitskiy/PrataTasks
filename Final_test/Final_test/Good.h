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
	//удален конструктор по умолчанию, поскольку товар без данных быть не может 
	virtual ~Good(); //деструктор определен виртуальным чтобы в функции чтения из файла класса Стор правильно освобождалась память

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
	bool isAvailable;

	//это функция помощник, которая вызывается в конструкторе и считывает данные из файла
	void readDataFromFile(std::ifstream& dataFile);

public:
	Store(std::ifstream& dataFile); //тут мы считываем данные из файла в класс
	
	void sortByName();
	void sortByNumber();
	void sortBySingleGoodWeight();
	void sortByAllGoodsWeight();
	void showByName(std::string name);
	void showByNumber(int min, int max);
	void showBySingleGoodWeight(float min, float max);
	void showByAllGoodsWeight(float min, float max);
	void showAllGoods();


	/*void showStoreState(); //11.Показать информацию о возможности покупки товаров. 
	bool tryBuyGood(std::string name, int count);*/
	
	~Store(); //тут мы создаем файл и записываем данные из класса в файл

};


void showMenu();
