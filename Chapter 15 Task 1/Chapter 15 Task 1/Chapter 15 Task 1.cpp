// Chapter 15 Task 1.cpp 

#include <iostream>

//Listing 15.3

#include "tv.h" 
int main()
{
	Tv s42; 
	std::cout << "Initial settings for 42\" TV:\n"; // initial TV settings 42
	s42.settings();
	s42.onoff();
	s42.chanup();

	std::cout << "\nAdjusted settings for 42\" TV:\n"; // adjusted TV settings 42
	s42.settings();
	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);


	std::cout << "\n\nRemote mode before change\n\n";
	grey.show_remote_mode(); // show remote mode before change
	s42.set_remote_mode(grey); // testing set remote mode to INTERACTIVE


	std::cout << "\n\nRemote mode after change\n\n";
	grey.show_remote_mode(); // show remote mode after change

	
	//Testing remote mode with TV off
	std::cout << "\n\nTV 45\n";
	Tv s45;
	Remote grey1;
	std::cout << "\nRemote mode while TV 45 off\n\n";
	s45.set_remote_mode(grey1);
	grey1.show_remote_mode();


	std::cout << "\n42\" settings after using remote:\n"; // TV settings 42 after using the remote
	s42.settings();
	Tv s58(Tv::On);
	s58.set_mode();
	grey.set_chan(s58, 28);
	std::cout << "\n58\" settings:\n"; // TV settings 58 
	s58.settings();

	return 0;
}
