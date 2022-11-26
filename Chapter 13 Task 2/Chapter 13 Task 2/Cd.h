#pragma once
#include <iostream>

// Base class
class Cd
{ // represents a CD

private:

	char *performers; // pointer name singer
	char *label; // pointer name label
	int selections; // number of collections
	double playtime; // playback time in minutes

public:

	Cd(const char* s1, const char* s2, int n, double x); // constructor with arguments

	//according to the condition of the task - remove the extra method
	//we dont use this constructor in task - Cd(const Cd& d); 

	Cd(); // default constructor
	virtual ~Cd(); // virtual destructor
	virtual void Report() const; // displays all information about the CD

	Cd& operator= (const Cd& d); // prototype of assignment operator overload
};


// derived class
class Classic :public Cd // inheritance from a class Cd
{
private:

	char *main_track; //pointer to char

public:

	Classic(const char* main_tr, const char* s1, const char* s2, int n, double x);
	Classic();
	~Classic(); //we need an explicit destructor because we are deleting a private field of the derived class

	void Report() const;

	//+
	Classic& operator= (const Classic& d); 
};
