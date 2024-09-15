// Fibonacci_divisibility(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <math.h>
#include <cfenv>

//input data :
//3
//17 12 61
//
//answer :
//9 12 15

int main()
{
    double number = 0;

    std::vector<double>Fibonachi(2);
    Fibonachi[0] = 0;
    Fibonachi[1] = 1;


    for (int i = 2; i < 100; i++)
    {
        number = (Fibonachi[i - 2] + Fibonachi[i - 1]);
        Fibonachi.push_back(number);
    }

    int size = 0;
    std::vector<int>Indexes;

    std::cout << "Enter size : ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        double value = 0;
        //std::cout << "enter value : ";
        std::cin >> value;

        for (int i = 2; i < Fibonachi.size(); i++)
        {
          if (std::fmod(Fibonachi[i], value) == 0)
          {
            Indexes.push_back(i);
            break;
          }
        }
    }

    for (int i = 0; i < Indexes.size(); i++)
    {
        std::cout << Indexes[i] << " ";
    }
}