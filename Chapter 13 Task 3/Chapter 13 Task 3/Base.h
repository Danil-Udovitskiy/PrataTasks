#pragma once
#include <iostream>
#include <string>

class Base
{
private:

	std::string modelName;
	int winCode;

public:

	Base(const std::string& s = "Car No Name", int winCode = 0000);
	virtual void View() const;

	virtual ~Base() {};
};
