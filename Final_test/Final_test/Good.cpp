#include "Good.h"

Good::Good()//constructor
{
	number = 0;
	weight = 0;
	//weights.push_back(weight);
}

Good::Good(std::string gName, int gNumber, float gWeight) //constructor with arguments
{
	name = gName;
	number = gNumber;
	weight = gWeight;
	//weights.push_back(weight);
}

//show data
std::ostream& operator<<(std::ostream& os, const Good& t) //operator<<
{
	os << "Name - " << t.name << "\n";
	os << "Number - " << t.number << "\n";
	os << "Weight - " << t.weight << "\n";

	return os;
}


std::string Good::getName() //name
{
	return name;
}

int Good::getNumber() //number
{
	return number;
}

float Good::getWeight() //weight
{
	return weight;
}

float Good::getWeightOfAllGoods()
{
	float sum = 0.0f;
	sum = number * weight;
	return sum;
}

Good::~Good()
{
}









//+++++++++++++++++++++++++++++++++++++

void Store::readDataFromFile(std::ifstream& dataFile) //функция считывания из файла (без типа возврата std::ifstream )
{
	std::vector<Good> products;
	Good temp;
	std::string temp_name;
	int temp_number;
	float temp_weight;


	//Input
	while (dataFile >> temp_name && dataFile >> temp_number && dataFile >> temp_weight && !dataFile.eof())
	{
		//Good
		dataFile >> temp_name;
		dataFile >> temp_number;
		dataFile >> temp_weight;

		products.push_back(temp);
	}

}


Store::Store(std::ifstream& dataFile)//конструктор 
{
	if (dataFile.is_open())
	{
		std::cout << "FILE OPEN\n"; // << dataFile << "\n";
		readDataFromFile(dataFile);
	}
}

Store::~Store()
{
}