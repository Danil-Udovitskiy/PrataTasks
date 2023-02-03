// Maximum_of_array(CodeAbbey).cpp 

#include <iostream>

int main()
{
    const int size = 300;
    int array[size];

    int number;
    std::cout << "Enter values: ";

    for (int i = 0; i < size; i++)
    {
        std::cin >> number;
        array[i] = number;
    }

    int min = array[0];
    int max = array[0];

    for (int i = 0; i < size; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }

        if (max < array[i])
        {
            max = array[i];
        }
    }

    //std::cout << "maximal = " << max << " " << "minimal = " << min << "\n";
    std::cout << max << " " << min << "\n";
}
