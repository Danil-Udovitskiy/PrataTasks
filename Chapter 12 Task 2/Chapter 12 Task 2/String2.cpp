#include "String2.h"
#pragma warning(disable:4996)

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0'; // строка
}


String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];        //+1 нужен  для нуль-символа, признака конца строки
	strcpy_s(str, strlen(s) + 1, s);  //создаём строку на основании значения параметра
	str[len] = '\0';                //на всякий случай, если строка будет слишком большой, насильно перепишем последний символ, если вдруг конца в строке не окажется

	num_strings++;       //наращиваем счётчик объектов

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

String operator+(const String& st1, const String& st2) //перегрузка + по ссылке 
{
	String sum;
	delete sum.str;
	sum.len = strlen(st1.str) + strlen(st2.str);
	sum.str = new char[strlen(st1.str) + strlen(st2.str) + 1]; // new char[st1.len] + 1;

	strcat(strcpy(sum.str, st1.str), st2.str);

	return sum;
}


String& String::operator=(const char* s) // Присваивание С-строки объекту String 
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, strlen(s) + 1, s);
	return *this;
}


String::String(const String& st) //конструктор копирования
{
	num_strings++; // обработка обновления статического члена 
	len = st.len; // длина та же 
	str = new char[len + 1]; // выделение памяти 
	strcpy_s(str, strlen(st.str) + 1, st.str); // копирование строки в новое место 
}