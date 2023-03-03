// Blackjack_counting(CodeAbbey).cpp 

#include<iostream>
#include <vector>
#include <string>

int main()
{
	int size = 0;
	std::cout << "enter size : ";
	std::cin >> size;
	std::cin.ignore();

	std::vector<int>total_results;

	int counterA;

	std::vector<int>numbersOfA;

	for (int i = 0; i < size; i++)
	{
		counterA = 0;

		std::cout << "enter text : ";
		std::string str;
		std::getline(std::cin, str);

		std::vector<int>results;

		int sum = 0;

		for (int i = 0; i < str.size(); i++)
		{
			int a = 0;
			if (str[i] == '2')
			{
				a = 2;
				results.push_back(a);
			}
			else if (str[i] == '3')
			{
				a = 3;
				results.push_back(a);
			}
			else if (str[i] == '4')
			{
				a = 4;
				results.push_back(a);
			}
			else if (str[i] == '5')
			{
				a = 5;
				results.push_back(a);
			}
			else if (str[i] == '6')
			{
				a = 6;
				results.push_back(a);
			}
			else if (str[i] == '7')
			{
				a = 7;
				results.push_back(a);
			}
			else if (str[i] == '8')
			{
				a = 8;
				results.push_back(a);
			}
			else if (str[i] == '9')
			{
				a = 9;
				results.push_back(a);
			}
			else if (str[i] == 'T' || str[i] == 'J' || str[i] == 'Q' || str[i] == 'K')
			{
				a = 10;
				results.push_back(a);
			}

			sum += a; //plus everything except A character

			if (str[i] == 'A')
			{
				counterA++;
			}
		}

		numbersOfA.push_back(counterA);

		int sum2 = 0;

		for (int i = 0; i < results.size(); i++)
		{
			sum2 += results[i];
		}

		total_results.push_back(sum2);
	}

	for (int i = 0; i < total_results.size(); i++)
	{
		//1 block
		if (total_results[i] < 11 && numbersOfA[i] == 1)
		{
			std::cout << total_results[i] + 11 << " ";
		}
		else if (total_results[i] < 21 && (numbersOfA[i] == 0 || numbersOfA[i] == 1))
		{
			if (numbersOfA[i] == 1)
				std::cout << total_results[i] + 1 << " ";
			else
				std::cout << total_results[i] << " ";
		}

		//2 block
		else if (total_results[i] < 10 && numbersOfA[i] == 2)
		{
			std::cout << total_results[i] + 12 << " ";
		}
		else if (total_results[i] < 20 && (numbersOfA[i] == 0 || numbersOfA[i] == 2))
		{
			if (numbersOfA[i] == 2)
				std::cout << total_results[i] + 2 << " ";
			else
				std::cout << total_results[i] << " ";
		}

		//3 block
		else if (total_results[i] < 9 && numbersOfA[i] == 3)
		{
			std::cout << total_results[i] + 13 << " ";
		}
		else if (total_results[i] < 19 && (numbersOfA[i] == 0 || numbersOfA[i] == 3))
		{
			if (numbersOfA[i] == 3)
				std::cout << total_results[i] + 3 << " ";
			else
				std::cout << total_results[i] << " ";
		}

		//4 block
		else if (total_results[i] < 8 && numbersOfA[i] == 4)
		{
			std::cout << total_results[i] + 14 << " ";
		}
		else if (total_results[i] < 18 && (numbersOfA[i] == 0 || numbersOfA[i] == 4))
		{
			if (numbersOfA[i] == 4)
				std::cout << total_results[i] + 4 << " ";
			else
				std::cout << total_results[i] << " ";
		}

		//5 блок
		else if (total_results[i] > 21)
		{
			std::cout << "Bust ";
		}
	}
}