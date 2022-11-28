#include "Base.h"

BaseABC::BaseABC(const std::string& s, int wCode)
{
	modelName = s;
	winCode = wCode;
}

void BaseABC::View() const
{
	std::cout << "Car: " << modelName << "\n";
	std::cout << "Win code: " << winCode << "\n";
}



