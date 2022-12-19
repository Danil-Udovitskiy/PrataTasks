#include "Tv.h"

//Listing 15.2
// tv.cpp - методы для класса Тѵ (методы Remote являются встроенными) 

bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}
bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}
void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}
void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}
void Tv::settings() const
{
	std::cout << "TV is " << (state == Off ? "Off" : "On") << "\n"; // выключен или включен 
	if (state == On)
	{
		std::cout << "Volume setting = " << volume << "\n"; // уровень громкости 
		std::cout << "Channel setting = " << channel << "\n"; // номер канала 
		std::cout << "Mode = " 
			<< (mode == Antenna ? "antenna" : "cable") << "\n"; // антенна или кабель 
		std::cout << "Input = "
			<< (input == TV ? "TV" : "DVD") << "\n"; // вход: TV или DVD 
	}
}


