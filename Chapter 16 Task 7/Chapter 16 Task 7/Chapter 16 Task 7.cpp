// Chapter 16 Task 7.cpp 

#include <iostream>
#include <algorithm>
#include <vector>


std::vector<int> Lotto(int values, int size)
{

    std::vector<int>a (size); // create a vector of 6 elements (0 by default)

    sort(a.begin(), a.end()); // sort 

    return a; // return object vector<int>
}

int main()
{
    std::vector<int> winners;
    winners = Lotto(51, 6);

    for (int i = 0; i < winners.size(); i++)
    {
        std::cout << "#" << i + 1 << " = " << winners.at(i) << "\n"; // use the at() function to refer to the cells
    }
}