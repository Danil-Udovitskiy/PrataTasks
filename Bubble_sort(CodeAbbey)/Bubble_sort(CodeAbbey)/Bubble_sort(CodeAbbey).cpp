// Bubble_sort(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
	//test data1
	//int N = 8;
	//3 1 4 1 5 9 2 6
	//output 5 8

	//test data2
	//int N = 23;
	//4 9 8 21 7 18 5 23 11 1 17 2 12 22 15 6 3 20 10 14 16 13 19
	//output 15 108



	int N = 0;
	std::cout << "Enter N(size) : ";
	std::cin >> N;

	int number = 0;

	std::vector<int>all_numbers;

	for (int i = 0; i < N; i++)
	{
		std::cin >> number;
		all_numbers.push_back(number);
	}


	int swap = 0;
	int move = 0;

	for (int i = N - 1; i > 0; i--)
	{
		move++;

		bool ind = false;
		for (int j = 0; j < i; j++)
		{
			if (all_numbers[j] > all_numbers[j + 1])
			{
				int t = all_numbers[j];
				all_numbers[j] = all_numbers[j + 1];
				all_numbers[j + 1] = t;

				ind = true;

				swap++;
			}
		}
		if (ind == false)
		{
			break;
		}
	}

	std::cout << move << " " << swap << "\n";
}