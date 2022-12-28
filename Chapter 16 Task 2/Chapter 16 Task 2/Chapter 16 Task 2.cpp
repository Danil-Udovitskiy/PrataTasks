// Chapter 16 Task 2.cpp 

#include <iostream>
#include <string>
#include <cctype>

bool palindrom(std::string& w)
{
    int size = w.size();
    for (int i = 0; i < size; i++)

    {
        if (isupper(w[i]))
        {
            w[i] = tolower(w[i]);
        }

        else if (ispunct(w[i])) 
        {
            w.erase(w.begin() + i); // remove the element
            size--; // reduce the string size (because 1 element was removed)
            i--; // return the counter 1 position back
        }

        else if (isspace(w[i]))
        {
            w.erase(w.begin() + i);
            size--;
            i--;
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
