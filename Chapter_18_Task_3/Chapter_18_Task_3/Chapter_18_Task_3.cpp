// Chapter_18_Task_3.cpp 

#include <iostream>
#include <string>

//template<typename... Args> // Args — это пакет параметров шаблона 
//void show_listl(Args... args) // args — это пакет параметров функции 


// Definition for 0 parameters - end call
void show_list()
{
    std::cout << "0 arg to show_list function\n";
}

// Definition for 1 parameter
template<typename T>
void show_list(T value)
{
    std::cout << value << '\n';
}


// Definition for 1 or more parameters
template<typename T, typename... Args>
void show_list(T value, Args... args)

{
    std::cout << value << ", ";
    show_list(args...);
}


int main()
{
    int n = 14;
    double x = 2.71828;
    std::string mr = "Mr. String objects!";

    show_list();
    show_list(n, x);
    show_list(x * x, '!', 7, mr);
    show_list('S', 80, "sweet", 4.5);

    return 0;

}
