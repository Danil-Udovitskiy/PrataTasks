// Rock_paper_scissors(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <string>

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;
    std::cin.ignore();

    std::vector <int>results;

    for (int i = 0; i < size; i++)
    {
        std::string str;
        //std::cout << "enter words :";
        std::getline(std::cin, str);

        int value2 = -2;

        std::string temp = str.substr(value2 + str.size(), str.size());

        int winner = 0;

        if ((temp[0] == 'R' && temp[1] == 'S') || (temp[0] == 'S' && temp[1] == 'P') || (temp[0] == 'P' && temp[1] == 'R'))
        {
            winner = 1;
        }
        else
        {
            winner = 2;
        }
        results.push_back(winner);
    }


    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}