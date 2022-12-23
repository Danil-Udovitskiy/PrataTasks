#include "Tv.h"
#include "Remote.h"

//Listing 15.2
// methods for class Tv (remote methods are built-in) 
// + methods set_remote_mode for TV and Remote 
// + method show_remote_mode for Remote

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
	std::cout << "TV is " << (state == Off ? "Off" : "On") << "\n"; // On / Off
	if (state == On)
	{
		std::cout << "Volume setting = " << volume << "\n"; // volume level
		std::cout << "Channel setting = " << channel << "\n"; // number of channel
		std::cout << "Mode = " 
			<< (mode == Antenna ? "antenna" : "cable") << "\n"; // antenna / cable
		std::cout << "Input = "
			<< (input == TV ? "TV" : "DVD") << "\n"; // input: TV / DVD
	}
}



void Tv::switchRemoteMode(Remote& t)
{
	if (state == On)
	{
		t.switchRemoteMode();
	}
	else
	{
		std::cout << "Remote mode selection is not available. (TV is off)\n";
	}

};



