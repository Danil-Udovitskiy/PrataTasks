// Cloud_altitude_measurement(CodeAbbey).cpp 

#include <iostream>
#include <math.h>
#include <vector>

double radians(double X);

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    std::vector<int>results;

    for (int i = 0; i < size; i++)
    {
        int D1 = 0;
        //std::cout << "Enter D1 : ";
        std::cin >> D1;

        double angleA = 0;
        //std::cout << "Enter angleA : ";
        std::cin >> angleA;

        double angleB = 0;
        //std::cout << "Enter angleB : ";
        std::cin >> angleB;

        // find corners
        double angleABC = 180 - angleB;

        double angleACB = 180 - (angleA + angleABC);

        double angleCDB = 90.0; //right angle

        double angleBСD = 180 - (angleCDB + angleB);


        //length of the hypotenuse

        double AC = D1 * (std::sin(radians(angleABC)) / std::sin(radians(angleACB)));

        std::cout << AC << "\n";


        //leg length (distance D1+D2)

        double AB = AC * std::sin(radians(angleA));

        results.push_back(AB);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}

double radians(double X)
{
  return(X * 3.14) / 180;
}
