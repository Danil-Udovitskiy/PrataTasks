// Modulo_and_time_difference(CodeAbbey).cpp 

#include<iostream>

int all_hours(int day, int hour)
{
    return (day * 24) + hour;
}

int all_seconds(int hour, int minute, int second)
{
    return(hour * 60 * 60) + (minute * 60) + second;
}

int main()
{
    int size = 0;
    std::cout << "Enter number of pairs : ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        int days1 = 0;
        int hours1 = 0;
        int minutes1 = 0;
        int seconds1 = 0;

        int total_hours1 = 0;
        int total_sec1 = 0;
        //std::cout << "enter for first : ";
        std::cin >> days1 >> hours1 >> minutes1 >> seconds1;

        //get hours and convert to seconds
        total_hours1 = all_hours(days1, hours1);
        total_sec1 = all_seconds(total_hours1, minutes1, seconds1);


        int days2 = 0;
        int hours2 = 0;
        int minutes2 = 0;
        int seconds2 = 0;

        int total_hours2 = 0;
        int total_sec2 = 0;
        //std::cout << "enter for second : ";
        std::cin >> days2 >> hours2 >> minutes2 >> seconds2;

        //get hours and convert to seconds
        total_hours2 = all_hours(days2, hours2);
        total_sec2 = all_seconds(total_hours2, minutes2, seconds2);

        int difference = total_sec2 - total_sec1;

        //show convert back difference
        std::cout << "(" << difference / 86400 << " "; //days (86400 sec in day
        difference = difference % 86400;
        std::cout << difference / 3600 << " "; // hours (3600 sec in hour)
        difference = difference % 3600;
        std::cout << difference / 60 << " "; //minutes (60 sec in minute)
        difference = difference % 60;
        std::cout << difference << ") "; //seconds
    }
}