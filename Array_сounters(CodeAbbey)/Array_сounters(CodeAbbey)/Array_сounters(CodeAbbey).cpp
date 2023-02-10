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
        if (numbers[i] == 1)
        {
            counters[0]++;
        }
        else if (numbers[i] == 2)
        {
            counters[1]++;
        }
        else if (numbers[i] == 3)
        {
            counters[2]++;
        }
        else if (numbers[i] == 4)
        {
            counters[3]++;
        }
        else if (numbers[i] == 5)
        {
            counters[4]++;
        }
        else if (numbers[i] == 6)
        {
            counters[5]++;
        }
        else if (numbers[i] == 7)
        {
            counters[6]++;
        }
        else if (numbers[i] == 8)
        {
            counters[7]++;
        }
        else if (numbers[i] == 9)
        {
            counters[8]++;
        }
        else if (numbers[i] == 10)
        {
            counters[9]++;
        }
        else if (numbers[i] == 11)
        {
            counters[10]++;
        }
        else if (numbers[i] == 12)
        {
            counters[11]++;
        }
        else if (numbers[i] == 13)
        {
            counters[12]++;
        }
        else if (numbers[i] == 14)
        {
            counters[13]++;
        }
        else if (numbers[i] == 15)
        {
            counters[14]++;
        }
        else if (numbers[i] == 16)
        {
            counters[15]++;
        }
        else if (numbers[i] == 17)
        {
            counters[16]++;
        }
        else if (numbers[i] == 18)
        {
            counters[17]++;
        }
        else if (numbers[i] == 19)
        {
            counters[18]++;
        }
        else if (numbers[i] == 20)
        {
            counters[19]++;
        }
    }

    for (int i = 0; i < counters.size(); i++)
    {
        if (counters[i] != 0)
        {
            std::cout << counters[i] << " ";
        }
    }

}