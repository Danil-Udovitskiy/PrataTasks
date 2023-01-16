// Chapter_18_Task_1.cpp 

#include <iostream>
#include <initializer_list>


double average_list(std::initializer_list<double> list)
{
	double average = 0;
	for (auto i = list.begin(); i != list.end(); i++)
	{
		std::cout << *i << " ";
		average += *i;
	}
	std::cout << "\nAverage = ";
	return average;
}



int main()
{
	// The double list is derived from the contents of the list
	auto q = average_list({ 15.4, 10.7, 9.0 });
	std::cout << q << std::endl;

	// The int list is derived from the contents of the list
	std::cout << average_list({ 20, 30, 19, 17, 45, 38 }) << std::endl;


	// Принудительное использование списка double 
	//auto ad = average_list<double>({ 'A', 70, 65.33 });
	//std::cout << ad << std::endl;

	return 0;
}