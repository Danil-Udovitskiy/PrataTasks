// Chapter 16 Task 5.cpp 

#include <iostream>
#include <algorithm> // std::sort()


template <class T>
void show(T n)
{
    std::cout << n << " ";
}


template <class T>
int reduce(T ar[], int n)
{
    std::sort(ar, ar + n);

    auto result = std::unique(&ar[0], &ar[n]);

    n = result - &ar[0];

    //std::for_each(&ar[0], result, show<T>); //perform explicit type inference of the show<T> template parameter
    
    //std::cout << "\nsize = ";
    return n; // return array size
}



int main()
{
    std::cout << "Long array\n";
    const int size = 6;
    long arr[size]{ 10,10,30,30,50,40 };

    std::for_each(std::begin(arr), std::end(arr), show<long>);


    //After reduce (sort +  get size + unique) and using for_each
    std::cout << "\n\nreduce\n";
    std::cout << reduce(arr, size) << "\n";

    std::cout << "size = " << reduce(arr, size) << "\n";

    int size_new = reduce(arr, size);
    
    //std::for_each(std::begin(arr), &arr[0] + size_new, show);


    std::cout << "\nString array\n";
    const int size2 = 6;
    std::string arrS[size2]{ "aa","bb","bb","gg","cc","dd" };

    std::for_each(std::begin(arrS), std::end(arrS), show<std::string>);


    //After reduce (sort +  get size + unique) and using for_each
    std::cout << "\n\nreduce\n";
    std::cout << reduce(arrS, size2) << "\n";
}


