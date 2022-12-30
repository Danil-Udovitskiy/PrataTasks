// Chapter 16 Task 4.cpp 
#include <iostream>
#include <algorithm> // std::sort()

void show(int n)
{ 
    std::cout << n << " ";
}

int reduce(long ar[], int n)
{
    std::sort(ar, ar + n);

    auto result = std::unique(&ar[0], &ar[n]); //pass the start and end of the range to unique

    n = result - &ar[0]; //subtract 1 element from the end of the resulting range
    
    std::for_each(&ar[0], result, show); //display the result after sorting and removing duplicate elements

    std::cout << "\nsize = ";
    return n; // return array size
}

int main()
{
    const int size = 6;
    long arr[size]{ 10,10,30,30,50,40 };

    for (int i = 0; i < size; ++i)
    {
        show(arr[i]);
    }



    //After reduce (sort +  get size + unique) and using for_each
    std::cout << "\n\nreduce\n";
    std::cout << reduce(arr, size) << "\n";

}

