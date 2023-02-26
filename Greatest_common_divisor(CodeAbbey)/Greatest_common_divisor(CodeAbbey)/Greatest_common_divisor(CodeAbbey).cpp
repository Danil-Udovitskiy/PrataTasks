// Greatest_common_divisor(CodeAbbey).cpp 

#include<iostream>
#include <vector>
int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    std::vector<int>gcd_results;
    std::vector<int>lcm_results;

    for (int i = 0; i < size; i++)
    {
        int a = 0, b = 0;
        //std::cout << "enter a ";
        std::cin >> a;

        //std::cout << "enter b ";
        std::cin >> b;

        int tempA = a;
        int tempB = b;

        while ((a * b) > 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }

        int gcd = a + b;
        gcd_results.push_back(gcd);

        int lcm = (tempA * tempB) / gcd;
        lcm_results.push_back(lcm);
    }

    for (int i = 0; i < gcd_results.size(); i++)
    {
        std::cout << "(" << gcd_results[i] << " " << lcm_results[i] << ")" << " ";
    }
}