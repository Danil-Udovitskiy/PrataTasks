#include "Wine.h"

Wine::Wine() :std::string("No_name") //инициализирую стринг, для наглядности работы разыменования в методе Show - (const std::string&)(*this)
{
	//name does not need to be initialized with a default value, because string type initialized initially (in advance)
	year = 0;
}


Wine::Wine(const char* l, int y):std::string (l), PairArray(ArrayInt(y), ArrayInt(y))
{
	year = y;
}


Wine::Wine(const char* l, int y, const int yr[], const int bot[]) :std::string(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y))
{
	year = y;
}


Wine::~Wine()
{
}



void Wine::Show() // output
{

	std::cout << "Wine: " << (const std::string&)(*this) << "\n"; //приводим к типу ссылки на стринг и отображаем содержимое 
	std::cout << year << " - year\n";

	//refer to objects of the inherited class using the context resolution operator ::
	if (PairArray::first().size() > 0 && PairArray::second().size() > 0)
	{
		std::cout << "Year\t" << "Bottles\n";
		for (int i = 0; i < year; i++)
		{
			std::cout << PairArray::first()[i] << "\t"; //operator [] for first 
			std::cout << PairArray::second()[i] << "\n"; //operator [] for second
		}
	}
}



void Wine::GetBottles()
{
	//for a Wine object of a given age, prompts the user to enter the appropriate values
	//for crop year and number of bottles

	std::cout << "Enter " << (const std::string&)(*this); //cast to string reference type and display content
	std::cout << " data for " << year << " - year(s)\n";

	for (int i = 0; i < year; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> PairArray::first()[i]; //cin in first valarray (object)
		std::cout << "Enter bottles for that year: ";
		std::cin >> PairArray::second()[i]; //cin in second valarray (object)
	}
}



const std::string& Wine::Label()
{
	//to access the internal string object "name", we perform type casting 
	//The Wine type is derived from string, so the Wine object can be cast to string
	return (const std::string &)(*this); //return a reference to the inherited string object that is in the calling Wine object
}


int Wine::sum()
{
	//returns the total number of bottles in the second valarray<int> object from the Pair object
	return PairArray::second().sum();
}
