#include "Wine.h"

Wine::Wine()
{
	//name; класс пустой по умолчанию не надо инициализировать
	year = 0;
}



Wine::Wine(const char* l, int y)
{
	name = l;
	year = y;
}

Wine::~Wine()
{
}




void Wine::Show() // output
{
	std::cout << name << " - name\n";
	std::cout << year << " - year\n";

}