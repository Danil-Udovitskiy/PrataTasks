#pragma once

//header file for abstr_emp class and its child classes
#include <iostream> 
#include <string> 

class Abstr_emp
{
private:
	std::string fname; // name abstr_emp 
	std::string lname; // last name abstr_emp 
	std::string job;

public:

	Abstr_emp();
	Abstr_emp(const std::string& fn, const std::string& ln, const std::string& j);

	virtual void ShowAll() const;	// outputs all data with names
	virtual void SetAll();			// requests values from the user
	
	friend std::ostream& operator<<(std::ostream& os, const Abstr_emp& e);  // Displays only first and last name

	virtual ~Abstr_emp() = 0; // virtual base class
};



