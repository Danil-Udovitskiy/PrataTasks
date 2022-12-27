// Chapter 16 Task 1.cpp

#include <iostream>
#include <string>


bool palindrom(std::string & w)
{
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

    std::cout << palindrom(word);

}
