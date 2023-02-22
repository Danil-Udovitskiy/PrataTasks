// Bit_count(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    std::vector <double>results;

    for (int i = 0; i < size; i++)
    {
        int value = 0;
        //std::cout << "Enter value : ";
        std::cin >> value;

        int result = 0;

        int bit = sizeof(value) * 8; //size 4(bytes) * 8 = 32 bits

        while (bit--)
        {
            result += value & 1; //sum all bits of the number
            value >>= 1;  //shift number 1 bit to the right
        }
        results.push_back(result);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}