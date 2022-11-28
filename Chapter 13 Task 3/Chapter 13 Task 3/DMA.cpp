#include "Base.h"

DMA::DMA(const std::string& s, int wCode, int maxS, const std::string& modelN2) :Base(s, wCode)
{
	maxSpeed = maxS;
	modelName2 = modelN2;
}

void DMA::View() const
{
	Base::View();
	std::cout << "Max speed : " << maxSpeed << "\n";
	std::cout << "Model name car : " << modelName2 << "\n";

}