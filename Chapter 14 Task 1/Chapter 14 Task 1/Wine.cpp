#include "Wine.h"

Wine::Wine()
{
	//name does not need to be initialized with a default value, because string type initialized initially (in advance)
	year = 0;
	Pair< ArrayInt, ArrayInt >obj;
	
	objects = obj;
}



Wine::Wine(const char* l, int y)
{
	// Initialize label with value l, number of years - y,
	// array objects of size - y are created

	name = l;
	year = y;
	ArrayInt first(y);
	
	objects = Pair< ArrayInt, ArrayInt > (first, first);

}


Wine::Wine(const char* l, int y, const int yr[], const int bot[])
{
	// Initialize label with value l, number of years - y,
	// harvest years - y[], number of bottles - bot []

	name = l;
	year = y;
	ArrayInt first(yr, y);
	ArrayInt second(bot, y);

	objects = Pair < ArrayInt, ArrayInt >(first, second);

}


Wine::~Wine()
{
}



void Wine::Show() // output
{
	std::cout << name << " - name\n";
	std::cout << year << " - year\n";

	std::cout << "Year\t" << "Bottles\n";
	for (int i = 0; i < year; i++) 
	{
		std::cout << objects.first()[i]<<"\t"; //operator [] for first 
		std::cout << objects.second()[i] << "\n"; //operator [] for second
	}
}



void Wine::GetBottles()
{
	//for a Wine object of a given age, prompts the user to enter the appropriate values
	//for crop year and number of bottles

	std::cout << "Enter " << name << " data for " << year << " year(s): \n";
	
	for (int i = 0; i < year; i++) 
	{
		std::cout << "Enter year: ";
		std::cin >> objects.first()[i]; //cin in first valarray (object)
		std::cout << "Enter bottles for that year: ";
		std::cin >> objects.second()[i]; //cin in second valarray (object)
	}
}




std::string& Wine::Label()
{
	//returns a link to the name of the drink (Wine)
	return name;
}


int Wine::sum()
{
	//returns the total number of bottles in the second valarray<int> object from the Pair object
	return objects.second().sum();
}