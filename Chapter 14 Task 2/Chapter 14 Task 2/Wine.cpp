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

	//обращаемся к объектам унаследованного класса при помощи оператора разрешения контекста ::
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
