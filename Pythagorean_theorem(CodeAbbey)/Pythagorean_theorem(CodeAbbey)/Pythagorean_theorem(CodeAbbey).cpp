// Pythagorean_theorem(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	std::vector<char>angles;

	int a = 0;
	int b = 0;
	int c = 0;


	for (int i = 0; i < size; i++)
	{

		std::cout << "enter 3 values : ";
		std::cin >> a >> b >> c;

		if ((c * c) < ((a * a) + (b * b)))
		{
			angles.push_back('A');
		}
		else if ((c * c) > ((a * a) + (b * b)))
		{
			angles.push_back('O');
		}
		else if ((c * c) == ((a * a) + (b * b)))
		{
			angles.push_back('R');
		}
	}


	for (int i = 0; i < angles.size(); i++)
	{
		std::cout << angles[i] << " ";
	}
}