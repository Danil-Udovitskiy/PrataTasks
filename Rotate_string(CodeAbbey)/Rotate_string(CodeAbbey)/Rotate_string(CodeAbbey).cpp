// Rotate_string(CodeAbbey).cpp 

#include <iostream>
#include <vector>
#include <string>

int main()
{
    int size = 0;
    std::cout << "Enter size : ";
    std::cin >> size;

    std::vector <std::string>results;

    for (int i = 0; i < size; i++)
    {
        int number = 0;
        //std::cout << "enter number : ";
        std::cin >> number;
        std::cin.ignore();

        std::string str;
        //std::cout << "enter symbols : ";
        std::getline(std::cin, str);

        std::string result;

        if (number > 0)
        {
            std::string temp = str.substr(0, number);
            str.erase(0, number);
            result = str + temp;
        }
        else
        {
            int a = number + str.size();
            std::string temp = str.substr(a, str.size());
            str.erase(a, str.size());
            result = temp + str;
        }

        results.push_back(result);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}