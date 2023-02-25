// Prime_numbers_generation(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        int number = 0;
        //std::cout << "enter index to get number : ";
        std::cin >> number;

        int limit = 2750159;//200 000 th prime number

        std::vector<int>sieve;
        for (int i = 0; i <= limit; i++) //Fill the vector with numbers for the sieve
        {
            sieve.push_back(i);
        }

        //Sieve work
        for (int i = 2; i <= limit; i++)
        {
            if (sieve[i] != 0)
            {
                //If the current number is not equal to 0, we start looking for complex numbers from it
                for (int j = i * 2; j <= limit; j += i)
                {
                    //And reset their cells to no longer check them in the loop
                    sieve[j] = 0;
                }
            }
        }

        std::vector<int>simple_numbers;
        //push only primes (only primes and zeros left in the initial vector)
        for (int i = 1; i <= limit; i++)
        {
            if (sieve[i] != 0)//If the current number is not equal to 0 - push into a vector of primes
            {
                simple_numbers.push_back(sieve[i]);
            }
        }

        //output the number under the given index
        for (int i = 0; i < simple_numbers.size(); i++)
        {
            if (i == number) //if index equals output value 
            {
                std::cout << simple_numbers[i] << " ";
                break;
            }
        }
    }
}