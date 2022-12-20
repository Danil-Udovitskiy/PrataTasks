#include "Tv.h"

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



void Remote::show_remote_mode() const
{
	if (remote_mode == NORMAL)
	{
		std::cout << "Remote control mode: normal\n";
	}
	else
	{
		std::cout << "Remote control mode: interactive\n";
	}
}



void Tv::set_remote_mode(Remote& t)
{
	if (state == On)
	{
		t.set_remote_mode();
	}
	else
	{
		std::cout << "Remote mode selection is not available. (TV is off)\n";
	}

};


void Remote::set_remote_mode()
{
	if (remote_mode == NORMAL)
	{
		remote_mode = INTERACTIVE;
	}
	else
	{
		remote_mode = NORMAL;
	}
}
