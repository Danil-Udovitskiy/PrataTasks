#pragma once
#include <iostream>

class Port // port
{
private:

	char* brand;
	char style[20]; 
	int bottles;

public:

	Port(const char* br = "none", const char* st = "none", int b = 0); // constructor with arguments
	Port(const Port& p); // copy constructor
	virtual ~Port() { delete[] brand; } // virtual dectructor

	Port& operator= (const Port& p); //operation =
	Port& operator+=(int b); // adds b to bottles
	Port& operator-= (int b); // subtracts b from bottles if possible

	int BottleCount() const { return bottles; } // method for bottles

	virtual void Show() const; // virtual Show

	friend std::ostream& operator<<(std::ostream& os, const Port& p); // operator <<

};



class VintagePort : public Port // style  = "vintage" 
{
private:

	char* nickname;
	int year;

public:

	VintagePort(); // default constructor
	VintagePort(const char* br, int b, const char* nn, int y); // constructor with arguments
	VintagePort(const VintagePort& vp);  // copy constructor
	~VintagePort() { delete[] nickname; } // dectructor
	
	VintagePort& operator=(const VintagePort& vp); //operation =
	
	void Show() const; // non virtual Show
	
	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vp); // operator <<
};
