#include "Tv.h"
// methods for class Remote


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


void Remote::switchRemoteMode()
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