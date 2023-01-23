// Temperatures(CodinGame).cpp 

#include <iostream>
#include <vector>
#include <math.h> //abs

using namespace std;


int main()
{
    std::vector<int> temperatures;

    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();

    if (n > 0)  // No temperature check
    {
        for (int i = 0; i < n; i++)
        {
            int t; // a temperature expressed as an integer ranging from -273 to 5526
            cin >> t; cin.ignore();
            temperatures.push_back(t);
        }

        int result = temperatures[0]; // closest value to 0

        for (int i = 1; i < n; i++)
        {
            //For this part: If two numbers are equally close to zero, a positive integer should be considered closest to zero (for example, if the temperatures are -5 and 5, then 5 is displayed).

            //input data : n = 3
            //vec[0] = -5; vec[1] = 5; vec[2] = -5
            //abs returns +, i.e. if temperatures[0] = -5 (negative) is equal to -abs (5 preceded by minus "-")
            //then a positive value is assigned instead of a negative value due to the minus sign "-" before abs

            //check for closest value to 0 and make positive integer closest to 0
            //FIRST option
            //negative result equals negative 
            if (abs(result) > abs(temperatures[i]) || result == -abs(temperatures[i]))
            {
                result = temperatures[i];
            }

            //SECOND option
            //positive result equals positive
            //if (abs(result) > abs(temperatures[i]) || abs(result) == temperatures[i])

        }
        cout << result << endl;
    }

    else
    {
        cout << "0" << endl;
    }
}