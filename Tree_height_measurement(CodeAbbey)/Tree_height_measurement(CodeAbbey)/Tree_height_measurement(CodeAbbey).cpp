// Tree_height_measurement(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <math.h>

int main()
{
	int size = 0;
	std::cout << "Enter the number of trees to find their height : ";
	std::cin >> size;

	std::vector <int>results;

	for (int i = 0; i < size; i++)
	{
		double D = 0.0;
		//std::cout << "Enter distance : ";
		std::cin >> D;

		double B = 0.0;
		//std::cout << "Enter B angle: ";
		std::cin >> B;

		double angleB = 180 - B; // find the real angle B

		double angleA = 180 - (angleB + 90); //find angle A

		double radians = (angleA * 3.14) / 180; //convert to radians for the tangent function

		double H = D * std::tan(radians); //height

		results.push_back(round(H));
	}

	for (int i = 0; i < results.size(); i++)
	{
		std::cout << results[i] << " ";
	}
}