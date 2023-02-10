// Array_сounters(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{

    int size = 0;// M
    std::cout << "enter size: ";
    std::cin >> size;

    std::vector<int>numbers;


    int range = 0; // N
    std::cout << "enter range : ";
    std::cin >> range;

    std::vector<int> counters(20);

    int number = 0;


    for (int i = 0; i < size; i++)
    {
        std::cin >> number;
        numbers.push_back(number);
    }

    for (int i = 0; i < size; i++)
    {
        //iterate over the vector (over all values)
        int index = numbers[i] - 1; //refer to element 0, then subtract 1 from VALUE
        //numbers[i] value itself no more than 20
        //fill from element 0, so numbers[i]-1
        counters[index]++;
    }

    for (int i = 0; i < counters.size(); i++)
    {
        if (counters[i] != 0)
        {
            std::cout << counters[i] << " ";
        }
    }

}