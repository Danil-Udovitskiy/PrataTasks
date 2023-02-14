// Arithmetic_progression(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    int begin = 0;    // start of progression
    int step = 0;     // progression step (difference)
    int end = 0;     // the number of first terms to sum

    std::vector<int>results;

    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        std::cin >> begin >> step >> end;

        sum = (2 * begin + step * (end - 1)) * end / 2;
        results.push_back(sum);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}