// Combinations_counting(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <iomanip>
#include <ios>



double Fact(double N)
{
    //if(std::abs(N) <= N * 0.00001)
    if (N == 0.0)
    {
        return  0;
    }
    //if (std::abs(N) <= N * 1.00001)
    if (N == 1.0)
    {
        return  1;
    }
    return N * Fact(N - 1);
}

int main()
{
    std::vector<double>results;

    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        double N = 0;
        std::cout << "Enter N :";
        std::cin >> N;

        double K = 0;
        std::cout << "Enter K :";
        std::cin >> K;

        double c = Fact(N) / (Fact(N - K));

        double result = round(c / 2);

        results.push_back(result);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout.setf(std::ios_base::fixed);
        std::cout << std::setprecision(0) << results[i] << " "; 
    }
}