#pragma once
#include <iostream>

// Базовый класс 
class Cd 
{ // представляет компакт-диск 

private:

	char performers[50];
	char label[20];
	int selections; // количество сборников 
	double playtime; // время воспроизведения в минутах 

public:

	Cd(const char* s1, const char* s2, int n, double x);
	
	//Cd(const Cd& d);
	
	Cd();
	virtual ~Cd();
	void Report() const; // выводит все данные о компакт-диске 
	
	//Cd& operator= (const Cd& d);
};

