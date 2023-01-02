// Chapter 16 Task 8.cpp 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    //First container 

    std::vector <std::string> Mat;

    int count = 1;
    std::cout << "Enter Mat friends names\n" << "Enter " << count << " name : ";

    std::string name;

    //Input
    while (std::cin >> name && name != "q")
    {
        count++;
        Mat.push_back(name);
        std::cout << "Enter " << count << " name : ";
    }

    //Sort
    sort(Mat.begin(), Mat.end());

    //Output
    std::cout << "\nMats friends : \n";
    for (int i = 0; i < Mat.size(); i++)
    {
        std::cout << Mat.at(i) << "\n";
    }



    //Second container 
    std::vector<std::string> Pat;

    count = 1;
    std::cout << "\nEnter Pat friends names\n" << "Enter " << count << " name : ";

    //Input
    while (std::cin >> name && name != "q")
    {
        count++;
        Pat.push_back(name);
        std::cout << "Enter " << count << " name : ";
    }

    //Sort
    sort(Pat.begin(), Pat.end());

    //Output
    std::cout << "\nPats friends : \n";
    for (int i = 0; i < Pat.size(); i++)
    {
        std::cout << Pat.at(i) << "\n";
    }
}
