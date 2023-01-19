// Chapter_18_Task_3.cpp 

#include <iostream>
#include <string>

//template<typename... Args> // Args - template parameter pack
//void show_listl(Args... args) // args - function parameter pack


// Definition for 1 parameter
template<typename T>
//void show_list(T value)
long double sum_values(const T& value)
{
    return value;
}


// Definition for 1 or more parameters
template<typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{
    long double sum;
    sum = value + sum_values(args...);
    return  sum;
}


int main()
{
    std::cout << sum_values(5, 2.344, -4, 3.1) << "\n"; // 1 + parameters

    return 0;
}
