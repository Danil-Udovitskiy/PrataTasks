#include "Base.h"

Base::Base(const std::string& s, int wCode)
{
	modelName = s;
	winCode = wCode;
}

void Base::View() const
{
	std::cout << "Car: " << modelName << "\n";
	std::cout << "Win code: " << winCode << "\n";
}