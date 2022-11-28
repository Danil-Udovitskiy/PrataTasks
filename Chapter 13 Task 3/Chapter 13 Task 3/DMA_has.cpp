#include "Base.h"

DMA_has::DMA_has(const std::string& s, int wCode, double wT) :BaseABC(s, wCode)
{
	weight = wT;
}

void DMA_has::View() const
{
	BaseABC::View();
	std::cout << "Weight: " << weight << "\n";

}