// Chapter_18_Task_2.cpp 

#include <iostream>
#include "Cpmv.h"

int main()
{
	Cpmv first;
	first.Display();

	std::string word1 = "hi";
	std::string word2 = "bye";

	Cpmv second(word1, word2);
	second.Display();


}
