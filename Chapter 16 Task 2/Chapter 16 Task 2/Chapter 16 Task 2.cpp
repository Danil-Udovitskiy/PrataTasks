// Chapter 16 Task 2.cpp 

#include <iostream>
#include <string>
#include <cctype>

bool palindrom(std::string& w)
{
    std::string temp1 = w;

    int size = temp1.size();
    for (int i = 0; i < size; i++)

    {
        if (isupper(temp1[i]))
        {
            temp1[i] = tolower(temp1[i]);
        }

        else if (ispunct(temp1[i]) || isspace(temp1[i]))
        {
            temp1.erase(temp1.begin() + i); // remove the element from temp string
            size--; // reduce the string size (because 1 element was removed)
            i--; // return the counter 1 position back
        }

    }

    std::string temp = temp1;

    std::reverse(temp.begin(), temp.end());

    if (temp == temp1)
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
