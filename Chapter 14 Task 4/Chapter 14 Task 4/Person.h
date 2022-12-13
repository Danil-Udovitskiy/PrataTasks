#pragma once

#include <iostream>
#include <string>

class Person
{
private:
	std::string name;
	std::string second_name;


public:
	Person();
	Person(const std::string n, const std::string s_n);
	virtual ~Person();
	virtual void Show();

};

