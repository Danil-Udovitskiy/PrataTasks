// Chapter 16 Task 2.cpp 

#include <iostream>
#include <string>
#include <cctype>

bool palindrom(std::string& w)
{
    int size = w.size();
    for (int i = 0; i < size; i++)
    {
       if (w[i] == toupper(w[i]))
        {
            w[i] = tolower(w[i]);
        }
   }


    std::string temp = w;
    std::reverse(w.begin(), w.end());

    if (temp == w)
    {
        std::cout << "palindrome\n";
        return true;
    }
    else
    {
        std::cout << "no palindrome\n";
        return false;
    }
}


int main()
{
    std::string word;
    std::cout << "Enter word : ";
    std::cin >> word;

    std::cout << palindrom(word) << "\n";

}
