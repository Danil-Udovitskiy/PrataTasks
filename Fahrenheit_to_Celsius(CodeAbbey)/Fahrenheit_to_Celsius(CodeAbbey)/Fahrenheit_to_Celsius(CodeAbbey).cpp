// Fahrenheit_to_Celsius(CodeAbbey).cpp 

#include <iostream>

//Fahrenheit (°F) to Celsius (°C) conversion formula
//(Fahrenheit — 32) : 1,8 = Celsius

int main()
{
	int size = 0, a = 0;
	std::cout << "Enter number of pairs of variables : ";
	std::cin >> size;

	std::cout << "Enter temperatures convert fahrenheit to celsius  : ";
	for (int i = 0; i < size; i++)
	{
		std::cin >> a;
		double result = (a - 32) / 1.8;
		std::cout << "Celsius = " << round(result) << "\n";
	}
}
