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

        std::string temp;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            else
            {
                temp.push_back(str[i]);
            }
        }

        int first = 0;
        int second = 0;
        int winner = 0;

        for (int i = 0; i < temp.size(); i += 2)
        {
            if (temp[i] == temp[i + 1])
            {
                continue;
            }

            if ((temp[i] == 'R' && temp[i + 1] == 'S') || (temp[i] == 'S' && temp[i + 1] == 'P') || (temp[i] == 'P' && temp[i + 1] == 'R'))
            {
                first++;
            }
            else
            {
                second++;
            }
        }

        if (first > second)
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