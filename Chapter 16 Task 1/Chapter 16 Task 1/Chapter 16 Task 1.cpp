// Chapter 16 Task 1.cpp

#include <iostream>
#include <string>


bool palindrom(std::string & w)
{
    std::string temp = w;
    std::reverse(w.begin(), w.end());

    if (temp == w)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    std::string word;
    std::cout << "Enter word : ";
    std::cin >> word;


    if (palindrom(word))
    {
        std::cout << "palindrome\n";
    }
    else
    {
        std::cout << "no palindrome\n";
    }

}
