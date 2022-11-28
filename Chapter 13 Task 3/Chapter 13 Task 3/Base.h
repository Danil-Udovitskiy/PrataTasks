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




class DMA_lacks :public::Base
{
private:
	double price;

public:

	DMA_lacks(const std::string& s = "Car No Name", int winCode = 0000, double price = 0.0);
	virtual void View() const;

	virtual ~DMA_lacks() {};
};

