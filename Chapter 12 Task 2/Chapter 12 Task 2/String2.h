#pragma once
#include <iostream>
#include <cstring>

class String
{
private:

	char* str; // ��������� �� ������ 
	int len; // ����� ������ 
	static int num_strings; // ���������� �������� 

public:

	String(); // ����������� �� ���������
	String(const char* s); // ����������� 
	~String(); //���������� 

	// ������������� ������� 
	friend std::ostream& operator<<(std::ostream& os, const String& st);


	//String(const String&);        //�������� ������������ �����
	//String& operator= (const String&); //�������� ���������� �������� ������������

};