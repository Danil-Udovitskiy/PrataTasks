// Horse-Racing_Duals(CodinGame).cpp 

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    std::vector<int> powers;

    int n; 
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) 
    {
        int pi;
        cin >> pi; cin.ignore();
        powers.push_back(pi);
    }
  
    sort(powers.begin(), powers.end()); // sort the vector to correctly compare values in the future
    // because min_difference can be set to a larger value than will be farther among pairs of numbers


    int min_difference = abs(powers[0] - powers[1]); // difference between first two elements (serves as minimum value)
    int current_difference = 0;


    for (int i = 1; i < powers.size() - 1; i++) // the loop is limited by the penultimate value of the vector, since we will refer to its last element in the last iteration
    // in the case of i < powers.size() , when accessing powers[i + 1], the vector will be out of bounds
    
    {
        current_difference = abs(powers[i] - powers[i + 1]); //difference between 2 and 3 vector elements (3/4, 4/5 ...)
        
        if (current_difference < min_difference) // if the difference between the first two elements is greater than the current one
        {
            min_difference = current_difference; // update the minimum difference value
        }
    }

    cout << min_difference << endl;
}