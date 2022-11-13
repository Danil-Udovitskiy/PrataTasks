#pragma once
#include <iostream>
#include <cstring>



class String
{
private:

	char* str; // указатель на строку 
	int len; // длина строки 
	static int num_strings; // количество объектов 
	static const int CINLIM = 80; // предел ввода для сіn

public:

	String(); // конструктор по умолчанию
	String(const char* s); // конструктор 
	~String(); //деструктор 
	String(const String& st); //конструктор копирования 

	// Дружественная функция 
	friend std::ostream& operator<<(std::ostream& os, const String& st);
	friend std::istream& operator>>(std::istream& is, String& st);

	String& operator= (const String& st); //прототип перегрузки операции присваивания 
	String& operator= (const char* s); // прототип перегрузки операции присваивания С-строки объекту String 
	 

	friend String operator+(const String& a, const String& b); // перегрузка оператора + по ссылке 



};