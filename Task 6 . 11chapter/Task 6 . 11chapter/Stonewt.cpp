#include "Stonewt.h"


Stonewt::Stonewt(double lbs)
{
    stone = int(lbs) / Lbs_per_stn;    // integer division
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    poundsByDouble = lbs;
    poundsByInt = int(lbs);
}


Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    poundsByDouble = stn * Lbs_per_stn + lbs;
    poundsByInt = int(stn * Lbs_per_stn + lbs);
}


Stonewt::Stonewt()
{
    stone = poundsByInt = poundsByDouble = pds_left = 0;
}

Stonewt::~Stonewt()
{
}


//перегрузка операций сравнения
bool operator > (const Stonewt& t1, const Stonewt& t2)
{
    return t1.poundsByDouble > t2.poundsByDouble;
}


bool operator >= (const Stonewt& t1, const Stonewt& t2)
{
    return t1.poundsByDouble >= t2.poundsByDouble;
}


bool operator < (const Stonewt& t1, const Stonewt& t2)
{
    return t1.poundsByDouble < t2.poundsByDouble;
}


bool operator <= (const Stonewt& t1, const Stonewt& t2)
{
    return t1.poundsByDouble <= t2.poundsByDouble;
}


bool operator == (const Stonewt& t1, const Stonewt& t2)
{
    return t1.poundsByDouble == t2.poundsByDouble;
}


bool operator != (const Stonewt& t1, const Stonewt& t2)
{
    return t1.poundsByDouble != t2.poundsByDouble;
}


std::ostream& operator << (std::ostream& os, const Stonewt& t)
{
    os << t.stone << " stone " << int(t.pds_left) << " pounds. (by stone + int)\n"; //int(t.pds_left)
    os << "or " << t.stone << " stone " << t.pds_left << " pounds. (by stone + double)\n";
    os << "or " << t.poundsByDouble << " pounds. (by double)\n";

    return os;
}


std::istream& operator >> (std::istream& is, Stonewt& t)
{
    is >> t.poundsByDouble;

    //выполняю изменение 
    t.stone = t.poundsByDouble / t.Lbs_per_stn;
    t.pds_left = int(t.poundsByDouble) % t.Lbs_per_stn + t.poundsByDouble - int(t.poundsByDouble);
    t.poundsByInt = int(t.pds_left);

    return is;
}

