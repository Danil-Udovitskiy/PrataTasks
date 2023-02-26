// Solid_integer(CodinGame).cpp 

#include<iostream>
#include<string>

//Solid Integer

//if the number contains 0, then return true
bool isZeroInNumber(int a)
{
    bool isZero = false;//whether the number has 0 in it or not

    std::string str = std::to_string(a);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            isZero = true;
        }
    }

    return isZero;
}

int main()
{
    int n = 0;
    std::cin >> n;

    std::cerr << n << std::endl;

    //number of hard numbers found
    int solid = 0;


    int i = 0;//number counter (next solid after n)

    while (solid != n)
    {
        i++;
        // check if the number contains 0 or not
        //if there is no 0, then increase the hard number by 1
        if (isZeroInNumber(i) == false)
        {
            solid++;
        }
    }
    std::cout << i << std::endl;
}