#pragma once
#include <iostream>

class Stonewt
{
public:

    enum { Lbs_per_stn = 14 };      // фунтов на стоун
    Stonewt(double lbs);            // конструктор для дабл фунтов
    Stonewt(int stn, double lbs);   // конструктор для стоуна и лбс
    Stonewt();                      // конструктор по умолчанию
    ~Stonewt();                     // деструктор


    //перегрузка операций сравнения
    friend bool operator > (const Stonewt& t1, const Stonewt& t2);  //перегрузка >
    friend bool operator >= (const Stonewt& t1, const Stonewt& t2); //перегрузка >=
    friend bool operator < (const Stonewt& t1, const Stonewt& t2);  //перегрузка <
    friend bool operator <= (const Stonewt& t1, const Stonewt& t2); //перегрузка <=
    friend bool operator == (const Stonewt& t1, const Stonewt& t2); //перегрузка ==
    friend bool operator != (const Stonewt& t1, const Stonewt& t2); //перегрузка !=

    //перегрузка операций вывода и ввода 
    friend std::ostream& operator << (std::ostream& os, const Stonewt& t);
    friend std::istream& operator >> (std::istream& is, Stonewt& t);


private:

    int stone;                      // целые стоуны
    double pds_left;                // дабл фунты
    double poundsByDouble;          // вес в дабл фунтах
    int poundsByInt;                // вес в инт фунтах
};

