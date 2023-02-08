// Card_names(CodeAbbey).cpp 

#include <iostream>
#include <string>

int main()
{
	std::string suits[] = { "Clubs", "Spades", "Diamonds", "Hearts" };
	std::string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

	int card_number = 0;

	int size = 0;
	std::cout << "Enter number of tests: ";
	std::cin >> size;
	
	for (int i = 0; i < size; i++)
	{
		//std::cout << "enter card number : ";
		std::cin >> card_number;

		if (card_number >= 0 && card_number < 52)
		{
			int suit_value = card_number / 13;
			int rank_value = card_number % 13;

			std::cout << ranks[rank_value] << "-of-" << suits[suit_value] << " ";
		}
		else
		{
			std::cout << "wrong value\n";
		}
	}
}