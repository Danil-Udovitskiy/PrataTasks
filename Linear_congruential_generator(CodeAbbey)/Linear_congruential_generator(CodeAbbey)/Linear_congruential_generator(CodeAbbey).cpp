// Linear_congruential_generator(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
    int A = 0;
    int C = 0;
    int M = 0;
    int X0 = 0; // initial member
    int N = 0; // serial number of a member that needs to be calculated

    int size = 0;
    std::cout << "Enter number of tests : ";
    std::cin >> size;

    std::vector<int>results;

    for (int i = 0; i < size; i++)
    {

        std::cout << "Enter numbers : ";
        std::cin >> A >> C >> M >> X0 >> N;

        for (int j = 0; j < N; j++)
        {
            //Xnext = (A * Xcur + C) % M
            X0 = (A * X0 + C) % M; // We get the current (new) X0 based on the previous X0
        }
        results.push_back(X0);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}