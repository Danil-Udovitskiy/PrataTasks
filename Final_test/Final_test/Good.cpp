#include "Good.h"


Good::Good(std::string gName, int gNumber, float gWeight) //constructor with arguments
{
	name = gName;
	number = gNumber;
	weight = gWeight;
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

void Good::reduceQuantityGood(int count)
{
	number = number - count;
}

Good::~Good()
{
}



//+++++++++++++++++++++++++++++++++++++

void Store::readDataFromFile(std::ifstream& dataFile)
{
	std::string temp_isAvailable;//добавил переменную и в зависимости от входа инициализируется

	std::string temp_name;
	int temp_number;
	float temp_weight;

	dataFile >> temp_isAvailable; //читаем один раз + не нужен еоф
	//Input
	while (dataFile >> temp_name && dataFile >> temp_number && dataFile >> temp_weight)//!dataFile.eof()
	{
		if (temp_isAvailable == "true")
		{
			isAvailable = true;
		}
		else if (temp_isAvailable == "false")
		{
			isAvailable = false;
			break;
		}


		Good temp(temp_name, temp_number, temp_weight);
		goods.push_back(temp);
	}
	dataFile.close();
}




Store::Store(std::ifstream& dataFile)//конструктор
{
	if (dataFile.is_open())
	{
		std::cout << "FILE OPEN\n"; // << dataFile << "\n";
		readDataFromFile(dataFile);
	}
	else
	{
		std::cout << "FILE NOT OPEN\n";
	}
}


Store::~Store()
{
	//text file for output
	std::string second = "StoreInfoUpdated.txt";

	std::ofstream fout; //create an ofstream object
	fout.open(second); //для добавления данных, а не удаление и запись (second, std::ofstream::app)

	if (fout.is_open())
	{
		std::cout << "FILE OPEN\n";
		
		for (int i = 0; i < goods.size(); i++)
		{
			fout << goods.at(i) << "\n";
		}
	}
	else
	{
		std::cout << "FILE NOT OPEN\n";
	}
	fout.close();

}





void Store::sortByName()
{
	std::sort(goods.begin(), goods.end(), [](Good& good1, Good& good2) {
		return good1.getName() < good2.getName(); });
}


void Store::sortByNumber()
{
	std::sort(goods.begin(), goods.end(), [](Good& good1, Good& good2) {
		return good1.getNumber() < good2.getNumber(); });
}


void Store::sortBySingleGoodWeight()
{
	std::sort(goods.begin(), goods.end(), [](Good& good1, Good& good2) {
		return good1.getWeight() < good2.getWeight(); });
}

void Store::sortByAllGoodsWeight()
{
	std::sort(goods.begin(), goods.end(), [](Good& good1, Good& good2) {
		return good1.getWeightOfAllGoods() < good2.getWeightOfAllGoods(); });
}


void Store::showByName(std::string name)
{
	for (auto i : goods)
	{
		if (i.getName() == name)
		{
			std::cout << i;
		}
	}

	std::cout << "No good with this name\n";
}


void Store::showByNumber(int min, int max)
{
	for (auto i : goods)
	{
		if (i.getNumber() >= min && i.getNumber() <= max)
		{
			std::cout << i;
		}
	}

	std::cout << "No goods in this range\n";
}


void Store::showBySingleGoodWeight(float min, float max)
{
	for (auto i : goods)
	{
		if (i.getWeight() >= min && i.getWeight() <= max)
		{
			std::cout << i;
		}
	}

	std::cout << "No goods in this range\n";
}


void Store::showByAllGoodsWeight(float min, float max)
{
	for (auto i : goods)
	{
		if (i.getWeightOfAllGoods() >= min && i.getWeightOfAllGoods() <= max)
		{
			std::cout << i;
		}
	}

	std::cout << "No goods in this range\n";
}




void Store::showAllGoods()
{
	for (int i = 0; i < goods.size(); i++)
	{
		std::cout << goods.at(i);
	}
}




void Store::showStoreState()
{
	if (isAvailable == true)
	{
		std::cout << "Store is opened\n";
	}
	else
	{
		std::cout << "Store isn't opened\n";
	}
}





void showMenu()
{
	//system("cls");
	std::cout << "1. Show all goods\n";
	std::cout << "2. Sort by good name\n";
	std::cout << "3. Sort by number of goods\n";
	std::cout << "4. Sort by weight of one unit\n";
	std::cout << "5. Sort by total weight\n";
	std::cout << "6. Show product information by name\n";
	std::cout << "7. Show product information in the quantity range\n";
	std::cout << "8. Show information about goods in the range of weight of one unit of goods\n";
	std::cout << "9. Show information about goods in the range of the total weight of the goods\n";
	std::cout << "10. Show information about all goods\n";
	std::cout << "11. Show information about the possibility of buying goods\n";
	std::cout << "12. Buy goods\n";
	std::cout << "13. Exit\n";
}


bool Store::tryBuyGood(std::string name, int count)
{
	for (auto &i : goods)
	{
		if (i.getName() == name && i.getNumber() >= count && isAvailable == true)
		{
			std::cout << "Can buy this good\n";
			i.reduceQuantityGood(count);
			return true;
		}
	}
	std::cout << "Can't buy this good\n";
	return false;
}