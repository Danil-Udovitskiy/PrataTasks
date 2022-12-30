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



    //After reduce (sort +  get size) and using for_each
    std::cout << reduce(arr, size) << "\n";

    std::for_each(std::begin(arr), std::end(arr), show);


}

