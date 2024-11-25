// Josephus_problem(CodeAbbey).cpp 

#include<iostream>
#include <vector>

int main()
{
    int N = 0;
    std::cout << "Enter N : ";
    std::cin >> N;

    int K = 0;
    std::cout << "Enter K : ";
    std::cin >> K;

    std::vector<int>numbers;

    int counter = 0;
    int zerosInVec = 0; //can't be more than N-1

    for (int i = 0; i < N; i++)
    {
        numbers.push_back(i + 1);
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = 0; j < numbers.size(); j++)
        {
            if (numbers[j] != 0)
            {
                counter++;

                if (counter % K == 0)
                {
                    numbers[j] = 0;
                    zerosInVec++;
                }
            }
        }
        if (zerosInVec == N - 1)
        {
            break;
        }
    }


    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] != 0)
        {
            std::cout << numbers[i] << "\n";
            break;
        }
    }
}