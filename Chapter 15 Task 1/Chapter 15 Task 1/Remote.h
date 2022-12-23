#pragma once
#include "Tv.h"

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
