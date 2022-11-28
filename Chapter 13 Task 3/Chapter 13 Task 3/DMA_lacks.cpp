#include "Base.h"

DMA_lacks::DMA_lacks(const std::string& s, int wCode, double pRice) :BaseABC(s, wCode)
{
	price = pRice;
}

void DMA_lacks::View() const
{
	BaseABC::View();
	std::cout << "Price: " << price << "\n";

}