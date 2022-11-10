// Task 6 . 11chapter.cpp 
// Задание 6 (Глава 11.).cpp 

#include <iostream>
#include "Stonewt.h"

using namespace std;


int main()
{
    const int SIZE = 6; //массив из шести объектов Stonewt с инициализацией в объявлении первых трех

    Stonewt eleven(11, 0); //создаю объект типа Stonewt на 11 стоунов
    cout << eleven << "\n";

    Stonewt arr[SIZE]{ 20, 202.2,  800.5 }; //инициализация объектов в pounds (инт либо дабл типа)


    for (int i = 3; i < SIZE; i++) //цикл для заполнения 4-6 ячеек вручную 
    {
        std::cout << "Enter value of  pounds " << i + 1 << " element : ";
        std::cin >> arr[i];
    }


    Stonewt min = arr[0];
    for (int i = 0; i < SIZE; ++i) //поиск мин значения
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }


    Stonewt max = arr[0];
    for (int i = 0; i < SIZE; ++i) //поиск макс значения
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }


    int biggerThan11 = 0;
    for (int i = 0; i < SIZE; ++i) // подсчет количества элементов больше eleven
    {
        if (arr[i] >= eleven)
        {
            ++biggerThan11;
        }
    }

    cout << "\nMin element : " << min << "\n";
    cout << "Max element : " << max << "\n";
    cout << "The number of elements is more than 11 stones: " << biggerThan11 << "\n";

    return 0;
}