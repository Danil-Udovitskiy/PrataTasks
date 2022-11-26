#pragma once
#include <iostream>

// Base class
class Cd 
{ // represents a CD

private:

	char performers[50]; // name singer
	char label[20]; // name label
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

	char main_track[50]; 

public:

	Classic (const char* main_tr, const char* s1, const char* s2, int n, double x);
	Classic ();
	
	//~Classic(); //we don't need an explicit destructor beacouse of virtual destructor in base class
	
	void Report() const;
};

