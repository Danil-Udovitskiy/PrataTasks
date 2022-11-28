#include "Base.h"

DMA_lacks::DMA_lacks(const std::string& s, int wCode, double pRice) :Base(s, wCode)
{
	price = pRice;
}

void DMA_lacks::View() const
{
	Base::View();
	std::cout << "Price: " << price << "\n";

}