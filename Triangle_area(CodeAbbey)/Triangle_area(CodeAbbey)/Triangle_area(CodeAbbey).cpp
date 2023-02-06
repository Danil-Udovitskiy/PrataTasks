// Triangle_area(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;

	std::vector<double>areas;

	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int x3 = 0;
	int y3 = 0;

	for (int i = 0; i < size; i++)
	{

		std::cout << "enter 6 values : ";
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		int result1 = x1 - x3;
		int result2 = y1 - y3;
		int result3 = x2 - x3;
		int result4 = y2 - y3;

		int total_result1 = result1 * result4;
		int total_result2 = result2 * result3;

		double s = 0.5 * abs((double)(total_result1 - total_result2));

		areas.push_back(s);
	}


	for (int i = 0; i < areas.size(); i++)
	{
		std::cout << std::setprecision(8) << areas[i] << " ";
	}
}