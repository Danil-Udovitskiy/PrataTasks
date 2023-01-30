// Final_test.cpp 

#include <iostream>
#include <string>

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

	~Good() {};

};


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




int main()
{
	Good obj("ddd", 10, 1.34);
	std::cout << obj << "\n";


	//returns the product name
	std::cout << "getName() " << obj.getName() << "\n";
	//returns the number of product units
	std::cout << "getNumber() " << obj.getNumber() << "\n";
	//returns the weight of the item
	std::cout << "getWeight() " << obj.getWeight() << "\n";

	std::cout << "\n";
	Good obj2("aaa", 5, 3.3);
	std::cout << obj2 << "\n";

	std::cout << "Weight of all goods " << obj.getWeightOfAllGoods() << "\n";


}

