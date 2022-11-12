#pragma once

class Cow
{
private:

	char name[20];
	char* hobby;
	double weight;

public:

	Cow(); // default constructor
	Cow(const char* nm, const char* ho, double wt); // constructor with parameters
	Cow(const Cow& c);  // copy constructor
	~Cow(); // destructor 

	Cow& operator= (const Cow& c); // class assignment operation
	void ShowCow() const; // displaying all data for a Cow class object
};
