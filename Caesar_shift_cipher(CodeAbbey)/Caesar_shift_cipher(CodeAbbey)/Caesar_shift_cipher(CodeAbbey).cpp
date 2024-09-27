// Caesar_shift_cipher(CodeAbbey).cpp 

#include <iostream>
#include <string>
#include <vector>

int main()
{
    int size = 0;
    int K = 0;

    std::cout << "Enter size and K : ";
    std::cin >> size >> K;
    std::cin.ignore();

    std::vector<std::string>results;

    for (int i = 0; i < size; i++)
    {
        std::string str;
        std::getline(std::cin, str);

        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z')
            {
                if (str[j] - K < 65)
                {
                    str[j] = (str[j] - K) + 26;
                }
                else
                {
                    str[j] = str[j] - K;
                }
            }
        }

        results.push_back(str);
    }

    for (int i = 0; i < results.size(); i++)
    {
        std::cout << results[i] << " ";
    }
}