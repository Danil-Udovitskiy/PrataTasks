// Linear_function(CodeAbbey).cpp 

#include <iostream>
#include <vector>

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    //input
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    //results
    int a = 0;
    int b = 0;

    std::vector<int> resultA;
    std::vector<int> resultB;

    for (int i = 0; i < size; i++)
    {
        std::cin >> x1 >> y1 >> x2 >> y2;

        a = (y2 - y1) / (x2 - x1);
        b = y1 - a * x1;

        resultA.push_back(a);
        resultB.push_back(b);
    }

    for (int i = 0; i < resultA.size(); i++)
    {
        std::cout << "(" << resultA[i] << " " << resultB[i] << ") ";
    }
}