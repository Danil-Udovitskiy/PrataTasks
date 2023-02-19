// Fibonacci_sequence(CodeAbbey).cpp

#include <iostream>
#include <vector>

int main()
{
    int range = 1000;


    std::vector<double>Fibonachi(2);
    Fibonachi[0] = 0;
    Fibonachi[1] = 1;

    double number = 0;

    for (int i = 2; i < 100; i++)
    {
        number = (Fibonachi[i - 2] + Fibonachi[i - 1]);
        Fibonachi.push_back(number);
    }

    double value = 0.0;
    std::cout << "Enter value : "; //2111485077978050 test data from 16 symbols max
    std::cin >> value;

    for (int i = 0; i < Fibonachi.size(); i++)
    {
        if (value == Fibonachi[i])
        {
            std::cout << "index of value = " << i << " ";
            break;
        }
    }
}