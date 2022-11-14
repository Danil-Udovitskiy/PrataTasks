#pragma once
#include <iostream>
#include <cstring>


class String
{
private:

	char* str; // ��������� �� ������ 
	int len; // ����� ������ 
	static int num_strings; // ���������� �������� 
	static const int CINLIM = 80; // ������ ����� ��� �n

public:

	String(); // ����������� �� ���������
	String(const char* s); // ����������� 
	~String(); //���������� 
	String(const String& st); //����������� ����������� 

	// ������������� ������� 
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& is, String& st); 

	String& operator= (const String& st); //�������� ���������� �������� ������������ 
	String& operator= (const char* s); // �������� ���������� �������� ������������ �-������ ������� String 
	 
	//�) ����������� �������� + ��� ����������� ���� ����� � ����.
	friend String operator+(const String& a, const String& b); // ���������� ��������� + �� ������ 
	
	//+++++++++++++++++++++++++++

	// �) �������� ������� - ���� stringup(), ������� ����������� ��� ��������� ������� � ������ � ������� �������.
	void stringup();

	//�) �������� ������� - ����, ������� ��������� �������� ���� char � ���������� ���������� ���, ������� ������ ���������� � ������.
	int has(char a);  //int has(int a);

};