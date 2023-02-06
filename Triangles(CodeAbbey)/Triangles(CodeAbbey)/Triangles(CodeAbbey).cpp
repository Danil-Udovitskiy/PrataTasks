// Triangles(CodeAbbey).cpp 

//For a triangle to exist, the sum of two sides of a triangle must always be greater than the third side.
//a + b > c, b + c > a, a + c > b

#include <iostream>
#include <vector>
int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	std::vector<int>answers;

	int a = 0;
	int b = 0;
	int c = 0;

	for (int i = 0; i < size; i++)
	{

		std::cout << "enter 3 values : ";
		std::cin >> a >> b >> c;

		if ((a + b) > c && (b + c) > a && (a + c) > b)
		{
			answers.push_back(1);
		}
		else
		{
			answers.push_back(0);
		}
	}


	for (int i = 0; i < answers.size(); i++)
	{
		std::cout << answers[i] << " ";
	}
}