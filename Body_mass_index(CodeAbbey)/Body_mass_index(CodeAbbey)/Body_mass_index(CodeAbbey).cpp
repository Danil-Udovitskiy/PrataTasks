// Body_mass_index(CodeAbbey).cpp 

#include <iostream>
#include <string>
#include <vector> 

int main()
{
	int size = 0, weight = 0;
	double height = 0.0;

	std::cout << "Enter cycles number: ";
	std::cin >> size;

	std::vector<std::string>results;

	for (int i = 0; i < size; i++)
	{
		double BMI = 0.0;
		std::cout << "Enter 2 values (weight, height) :";
		std::cin >> weight >> height;

		BMI = weight / (height * height);

		if (BMI < 18.5)
		{
			results.push_back("under");
		}
		else if (18.5 <= BMI && BMI < 25.0)
		{
			results.push_back("normal");
		}

		else if (25.0 <= BMI && BMI < 30.0)
		{
			results.push_back("over");
		}
		else if (30.0 <= BMI)
		{
			results.push_back("obese");
		}

	}


	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
	std::cout << "\n";

}