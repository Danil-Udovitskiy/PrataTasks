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


class Remote
{
private:
	
	int mode; // TV or DVD control
	
	//b. Add a member variable to the Remote class that describes the mode of the remote
	//remote control - normal or interactive.
	int remote_mode; //normal or interactive

public:

	//a. Make them mutual friends.
	friend class Tv; // Tv has access to the closed part of Remote


	// modified constructor with new member variable,
	// which is initialized to rm or takes the default NORMAL mode
	Remote(int m = Tv::TV, int rm = NORMAL) : mode(m), remote_mode(rm) {};

	bool volup(Tv& t) { return t.volup(); }
	bool voldown(Tv& t) { return t.voldown(); }
	void onoff(Tv& t) { t.onoff(); }
	void chanup(Tv& t) { t.chanup(); }
	void chandown(Tv& t) { t.chandown(); }
	void set_chan(Tv& t, int c) { t.channel = c; }
	void set_mode(Tv& t) { t.set_mode(); }
	void set_input(Tv& t) { t.set_input(); }


	//++
	enum { NORMAL, INTERACTIVE };

	//c. Added a Remote method that displays the mode.
	void show_remote_mode() const;

	//d. Function to switch remote mode
	void switchRemoteMode();
	 
};



