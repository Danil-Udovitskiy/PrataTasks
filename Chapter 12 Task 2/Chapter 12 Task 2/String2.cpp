#include "String2.h"
#include <string.h> // for strcat_s

#pragma warning(disable:4996)

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

std::istream& operator>>(std::istream& is, String& st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}



String& String::operator= (const String& st)
{
	if (this == &st)
		return *this;
	delete[] str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, strlen(st.str) + 1, st.str);
	return *this;
}


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++

String operator+(const String& st1, const String& st2) //���������� + �� ������ 
{
	String sum;
	delete sum.str;
	sum.len = strlen(st1.str) + strlen(st2.str);
	sum.str = new char[strlen(st1.str) + strlen(st2.str) + 1]; // new char[st1.len] + 1;

	strcat(strcpy(sum.str, st1.str), st2.str); 
	//strcat ��������� ��������� ����� ���������� ������, �� ������� ��������� st2.str � ����� ������,
	//�� ������� ��������� strcpy(sum.str, st1.str)

	//strcpy �������� ���e������ st1.str � sum.str (sum.str ������� ����� ������ (st1.str + st2.str) +1)

	return sum;
}


String& String::operator=(const char* s) // ������������ �-������ ������� String 
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];  //+1 �����  ��� ����-�������, �������� ����� ������
	strcpy_s(str, strlen(s) + 1, s); //������ ������ �� ��������� �������� ���������
	str[len] = '\0';  //+ �� ������ ������, ���� ������ ����� ������� �������, �������� ��������� ��������� ������, ���� ����� ����� � ������ �� ��������
	return *this;

}


String::String(const String& st) //����������� �����������
{
	num_strings++; // ��������� ���������� ������������ ����� 
	len = st.len; // ����� �� �� 
	str = new char[len + 1]; // ��������� ������ 
	strcpy_s(str, strlen(st.str) + 1, st.str); // ����������� ������ � ����� ����� 
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void String::stringup()
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (islower(str[i]))
		{
			str[i] = toupper(str[i]);
		}
	}

}


int String::has(char ch)
{
	int count = 0;

	int size = strlen(str);
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ch)
			count++;
	}

	return count;
}

