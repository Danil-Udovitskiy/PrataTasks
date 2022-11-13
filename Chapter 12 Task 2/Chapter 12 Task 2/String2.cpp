#include "String2.h"

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0'; // ������
}


String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];        //+1 �����  ��� ����-�������, �������� ����� ������
	strcpy_s(str, strlen(s) + 1, s);  //������ ������ �� ��������� �������� ���������
	str[len] = '\0';                //�� ������ ������, ���� ������ ����� ������� �������, �������� ��������� ��������� ������, ���� ����� ����� � ������ �� ��������

	num_strings++;       //���������� ������� ��������

	std::cout << num_strings << " : " << str << " object created\n";
}




String:: ~String()
{
	std::cout << str << " object deleted ";
	--num_strings;
	std::cout << num_strings << " left\n";
	delete[] str;
}

std::ostream& operator<<(std::ostream& os, const String& st)
{
	os << st.str;
	return os;
}