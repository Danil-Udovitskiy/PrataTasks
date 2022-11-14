#include "String2.h"
#include <string.h> // for strcat_s

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
	str = new char[len + 1];        //+1 нужен  дл€ нуль-символа, признака конца строки
	strcpy_s(str, strlen(s) + 1, s);  //создаЄм строку на основании значени€ параметра
	str[len] = '\0';                //на вс€кий случай, если строка будет слишком большой, насильно перепишем последний символ, если вдруг конца в строке не окажетс€

	num_strings++;       //наращиваем счЄтчик объектов

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
	//strcat добавл€ет добавл€ет копию символьной строки, на которую указывает st2.str в конец строки,
	//на которую указывает strcpy(sum.str, st1.str)

	//strcpy копирует содeржимое st1.str в sum.str (sum.str заранее имеет размер (st1.str + st2.str) +1)

	return sum;
}


String& String::operator=(const char* s) // ѕрисваивание —-строки объекту String 
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];  //+1 нужен  дл€ нуль-символа, признака конца строки
	strcpy_s(str, strlen(s) + 1, s); //создаЄм строку на основании значени€ параметра
	str[len] = '\0';  //+ на вс€кий случай, если строка будет слишком большой, насильно перепишем последний символ, если вдруг конца в строке не окажетс€
	return *this;

}


String::String(const String& st) //конструктор копировани€
{
	num_strings++; // обработка обновлени€ статического члена 
	len = st.len; // длина та же 
	str = new char[len + 1]; // выделение пам€ти 
	strcpy_s(str, strlen(st.str) + 1, st.str); // копирование строки в новое место 
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

