// Savings_calculator(Code_Abbey).cpp 

#include<iostream>
#include<vector>

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    double S = 0.0; // initial amount
    double R = 0.0; // required amount
    double P = 0.0; // %

    std::vector<int>results;

    //int years = 0;
    for (int i = 0; i < size; i++)
    {
        std::cin >> S >> R >> P;

        int years = 0;

        // Profit_per_year = (S * P) / 100

        while (S < R) // increase the initial sum until we get the required (years too)
        {
            S += S * (P / 100);
            S = static_cast<int>(S * 100); //or S = (int)(S * 100);
            S = (S / 100);

            years++;
        }
        results.push_back(years);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}