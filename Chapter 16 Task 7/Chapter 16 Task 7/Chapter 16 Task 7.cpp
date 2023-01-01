// Chapter 16 Task 7.cpp 

#include <iostream>
#include <algorithm> //random_shuffle
#include <vector>
#include <ctime>

std::vector<int> Lotto(int values, int size)
{
    srand(time(0)); //to generate unique numbers

    std::vector<int> a; //create a vector

    //push all values into the vector a (1-51)
    for (int i = 1; i <= values; i++)
    {
        a.push_back(i);
    }

    //do shuffling in random order
    random_shuffle(a.begin(), a.end());

    //copy the shuffled values from vector a to the new vector b (required range)
    std::vector<int> b(a.begin(), a.begin() + size);
    
    //sort new vector
    sort(b.begin(), b.begin());

    return b; //return object vector<int> (copy of vector b)
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