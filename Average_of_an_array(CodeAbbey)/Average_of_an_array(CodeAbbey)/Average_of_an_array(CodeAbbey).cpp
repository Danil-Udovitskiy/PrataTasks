// Average_of_an_array(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
	
	//int size = 0;
	double size = 0.0;
	std::cout << "Enter number of values : ";
	std::cin >> size;

	std::vector<int> vec(size);
	//vec.resize(size);


	int number = 0;
	std::cout << "Enter numbers : ";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cin >> number;
		vec[i] = number;
	}


	//int sum = 0;
	double sum = 0.0;
	for (int i = 0; i < vec.size(); i++)
	{
		sum = sum + vec[i];
	}


	double avarage = sum / size;
	std::cout << "avarage = " << round(avarage) << "\n";
}

