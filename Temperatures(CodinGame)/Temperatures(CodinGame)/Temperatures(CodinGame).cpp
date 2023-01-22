// Temperatures(CodinGame).cpp 

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h> //abs

using namespace std;


int main()
{
    std::vector<int> temperatures;

    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int t; // a temperature expressed as an integer ranging from -273 to 5526
        cin >> t; cin.ignore();
        temperatures.push_back(abs(t));
    }

    sort(temperatures.begin(), temperatures.end());
    int result = temperatures[0];

    cout << result << std::endl;
}



