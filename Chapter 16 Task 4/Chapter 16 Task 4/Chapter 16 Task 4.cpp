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
    
    return n; // return array size
}

int main()
{
    const int size = 6;
    long arr[size]{ 10,10,30,30,50,40 };

    std::for_each(std::begin(arr), std::end(arr), show);
   


    //After reduce (sort +  get size + unique) and using for_each
    std::cout << "\n\nreduce\n";
    std::cout << "size = " << reduce(arr, size) << "\n";

    int size_new = reduce(arr, size);

    std::for_each(std::begin(arr), &arr[0] + size_new, show);

}


