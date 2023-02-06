// Bicycle_race(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <iomanip> 

int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	int s = 0; //distance between points
	double a = 0, b = 0; // speeds of 2 cyclists

	double meet_point = 0.0;
	double meeting_time = 0.0; //meeting time 

	std::vector<double> points;

	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter distance : ";
		std::cin >> s;

		std::cout << "Enter 2 speeds of cyclists : ";
		std::cin >> a >> b;

		meeting_time = s / (a + b);

		meet_point = a * meeting_time;

		points.push_back(meet_point);
	}


	for (int i = 0; i < points.size(); i++)
	{
		//std::cout << "meet point km = " << meet_point << "\n";
		std::cout << std::setprecision(10) << points[i] << " ";
	}
}