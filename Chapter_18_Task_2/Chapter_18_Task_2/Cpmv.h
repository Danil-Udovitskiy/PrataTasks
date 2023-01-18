#pragma once
#include <string>

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp); // copy constructor
	//Cpmv(Cpmv&& mv);
	~Cpmv();

	Cpmv& operator=(const Cpmv& cp); // assignment operation with copy
	//Cpmv& operator=(Cpmv&& mv);
	Cpmv operator+(const Cpmv& obj) const; // operator+()

	void Display() const;
};

