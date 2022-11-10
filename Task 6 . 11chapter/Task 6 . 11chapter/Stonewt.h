#pragma once
#include <iostream>

class Stonewt
{
public:

    enum { Lbs_per_stn = 14 };      // ������ �� �����
    Stonewt(double lbs);            // ����������� ��� ���� ������
    Stonewt(int stn, double lbs);   // ����������� ��� ������ � ���
    Stonewt();                      // ����������� �� ���������
    ~Stonewt();                     // ����������


    //���������� �������� ���������
    friend bool operator > (const Stonewt& t1, const Stonewt& t2);  //���������� >
    friend bool operator >= (const Stonewt& t1, const Stonewt& t2); //���������� >=
    friend bool operator < (const Stonewt& t1, const Stonewt& t2);  //���������� <
    friend bool operator <= (const Stonewt& t1, const Stonewt& t2); //���������� <=
    friend bool operator == (const Stonewt& t1, const Stonewt& t2); //���������� ==
    friend bool operator != (const Stonewt& t1, const Stonewt& t2); //���������� !=

    //���������� �������� ������ � ����� 
    friend std::ostream& operator << (std::ostream& os, const Stonewt& t);
    friend std::istream& operator >> (std::istream& is, Stonewt& t);


private:

    int stone;                      // ����� ������
    double pds_left;                // ���� �����
    double poundsByDouble;          // ��� � ���� ������
    int poundsByInt;                // ��� � ��� ������
};

