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



//DMA_lacks
class DMA_lacks :public::Base
{
private:
	double price;

public:

	DMA_lacks(const std::string& s = "Car No Name", int winCode = 0000, double price = 0.0);
	virtual void View() const;

	virtual ~DMA_lacks() {};
};



//DMA_has
class DMA_has :public::Base
{
private:
	double weight;

public:

	DMA_has(const std::string& s = "Car No Name", int winCode = 0000, double weight = 0.0);
	virtual void View() const;

	virtual ~DMA_has() {};
};



//DMA
class DMA :public::Base
{
private:
	std::string modelName2;
	int maxSpeed;

public:

	DMA(const std::string& s = "Car No Name", int wCode = 0000, int maxS = 0, const std::string& modelN2 = "Car No Name");
	virtual void View() const;

	virtual ~DMA() {};
};


