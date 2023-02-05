// Vowel_count(CodeAbbey).cpp 

#include <iostream>
#include <string>
#include <vector>

int main()
{
	int size = 0;
	std::cout << "Enter number of tests : ";
	std::cin >> size;
	std::cin.ignore();

	std::string str;

	std::vector<int>counters;


	for (int i = 0; i < size; i++)
	{
		int count = 0;
		std::cout << "Enter string: ";
		std::getline(std::cin, str);

		for (int j = 0; j < str.size(); j++)
		{

			if (str[j] == 'a'|| str[j] == 'o' || str[j] == 'u' || str[j] == 'i' || str[j] == 'e' || str[j] == 'y')
				count++;
		}
		counters.push_back(count);
	}


	for (auto i : counters)
		std::cout << i << " ";
	std::cout << "\n";
}