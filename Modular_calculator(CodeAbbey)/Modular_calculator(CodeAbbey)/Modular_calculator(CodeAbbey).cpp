// Modular_calculator(CodeAbbey).cpp 

#include <iostream>

int main()
{
    int value = 0;
    std::cout << "enter first value :";
    std::cin >> value;

    char ch = ' ';
    int number = 0;

    while (ch != '%')
    {
        //std::cout << "enter char : ";
        std::cin >> ch;
        //std::cout << "enter next value :";
        std::cin >> number;

        if (ch == '*')
        {
            value = value * number;
        }
        else if (ch == '+')
        {
            value = value + number;
        }
        else if (ch == '%')
        {
            value = value % number;
        }
    }
    std::cout << value << "\n";
}