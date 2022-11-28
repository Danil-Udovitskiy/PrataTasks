#pragma once
#include <iostream>

class Port // �������� 
{
private:

	char* brand;
	char style[20]; // ��������, tawny (����������), 
	// ruby (���������), vintage (��������) 
	int bottles;
public:

	Port(const char* br = "none", const char* st = "none", int b = 0);
	Port(const Port& p); // ����������� ����������� 
	virtual ~Port() { delete[] brand; }

	Port& operator= (const Port& p);
	Port& operator+=(int b); // ��������� b � bottles 
	Port& operator-= (int b); // �������� b �� bottles, ���� ��� �������� 

	int BottleCount() const { return bottles; }

	virtual void Show() const;

	friend std::ostream& operator<<(std::ostream& os, const Port& p);

};
