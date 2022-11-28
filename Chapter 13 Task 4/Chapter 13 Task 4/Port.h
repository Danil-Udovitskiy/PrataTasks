#pragma once
#include <iostream>

class Port // портвейн 
{
private:

	char* brand;
	char style[20]; // например, tawny (золотистый), 
	// ruby (рубиновый), vintage (марочный) 
	int bottles;
public:

	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p); // конструктор копирования 
	virtual ~Port() { delete[] brand; }

	Port& operator= (const Port& p);
	Port& operator+=(int b); // добавляет b к bottles 
	Port& operator-= (int b); // вычитает b из bottles, если это возможно 

	int BottleCount() const { return bottles; }

	virtual void Show() const;

	friend std::ostream& operator<<(std::ostream& os, const Port& p);

};
