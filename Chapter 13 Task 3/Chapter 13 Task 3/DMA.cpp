#include "Base.h"

DMA::DMA(const std::string& s, int wCode, int maxS, const std::string& modelN2) :BaseABC(s, wCode)
{
	maxSpeed = maxS;
	modelName2 = modelN2;
}

void DMA::View() const
{
	BaseABC::View();
	std::cout << "Max speed : " << maxSpeed << "\n";
	std::cout << "Model name car : " << modelName2 << "\n";

}