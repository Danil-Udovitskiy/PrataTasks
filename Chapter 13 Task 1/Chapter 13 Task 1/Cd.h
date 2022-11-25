#pragma once
#include <iostream>

// ������� ����� 
class Cd 
{ // ������������ �������-���� 

private:

	char performers[50];
	char label[20];
	int selections; // ���������� ��������� 
	double playtime; // ����� ��������������� � ������� 

public:

	Cd(const char* s1, const char* s2, int n, double x);
	
	//Cd(const Cd& d);
	
	Cd();
	virtual ~Cd();
	void Report() const; // ������� ��� ������ � �������-����� 
	
	//Cd& operator= (const Cd& d);
};

