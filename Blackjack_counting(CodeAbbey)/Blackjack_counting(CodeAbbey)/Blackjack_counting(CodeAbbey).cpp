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

	for (int i = 0; i < size; i++)
	{
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


			//1 or 11
			if (str[i] == 'A' && sum > 10)
			{
				a = 1;
				results.push_back(a);
			}
			else if (str[i] == 'A' && sum < 11)
			{
				a = 11;
				results.push_back(a);
			}

			sum += a;
		}

		int sum2 = 0;

		for (int i = 0; i < results.size(); i++)
		{
			sum2 += results[i];
		}

		total_results.push_back(sum2);
	}

	for (int i = 0; i < total_results.size(); i++)
	{
		if (total_results[i] > 21)
		{
			std::cout << "Bust ";
		}
		else
		{
			std::cout << total_results[i] << " ";
		}
	}
}