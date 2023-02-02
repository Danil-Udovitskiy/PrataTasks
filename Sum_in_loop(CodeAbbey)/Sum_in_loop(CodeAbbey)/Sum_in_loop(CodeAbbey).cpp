// Sum_in_loop(CodeAbbey)

#include <iostream>

int main()
{
	int size = 0;
	std::cin >> size;

	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		int in = 0;
		std::cin >> in;
		sum += in;
	}
	std::cout << sum << "\n";
}