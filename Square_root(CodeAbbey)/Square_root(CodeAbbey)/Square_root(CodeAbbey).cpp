// Square_root(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    //           r + X / r
    //    r : = ------------
    //             2


    int X = 0;  // Value from which find the root
    int N = 0;  // number of steps

    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    std::vector <double>results;

    for (int i = 0; i < size; i++)
    {
        //std::cout << "Enter value to get square : ";
        std::cin >> X;

        //std::cout << "Enter steps : ";
        std::cin >> N;

        double r = 1; //first approach

        for (int i = 0; i < N; i++)
        {
            r = (r + X / r) / 2;
        }
        results.push_back(r);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << std::setprecision(14) << results[i] << " ";
    }
}