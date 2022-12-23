#pragma once
#include <iostream> 
//Listing 15.1
// Тѵ and Remote classes 


class Tv
{
public:

	friend class Remote; // Remote has access to the private part of TV
	enum { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	Tv(int s = Off, int mc = 125) : state(s), volume(5),
		maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() { state = (state == On) ? Off : On; }
	bool ison() const { return state == On; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void settings() const; // display all settings

	//d. Add a method to the Tv class to switch the new Remote member.
	// This method should only work if the TV is on.
	void  switchRemoteMode(Remote& t);

private:

	int state; // On / Off 
	int volume; // volume levels
	int maxchannel; // maximum number of channels
	int channel; // current channel
	int mode; // terrestrial or cable television
	int input; // TV / DVD
};




