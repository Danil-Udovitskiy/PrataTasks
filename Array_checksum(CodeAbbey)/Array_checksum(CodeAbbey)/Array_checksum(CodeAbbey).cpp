// Array_checksum(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
    int size = 0;
    std::cout << "Enter size: ";
    std::cin >> size;

    int number = 0;

    std::vector<int>numbers;

    for (int i = 0; i < size; i++)
    {
        std::cin >> number;
        number %= 10000007;         // prevent overflow
        numbers.push_back(number);
    }

    int sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
        sum *= 113;
        sum %= 10000007;
    }

    std::cout << "sum = " << sum << "\n";
}