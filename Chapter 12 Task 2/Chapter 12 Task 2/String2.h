#pragma once
#include <iostream>
#include <cstring>

class String
{
private:

	char* str; // указатель на строку 
	int len; // длина строки 
	static int num_strings; // количество объектов 

public:

	String(); // конструктор по умолчанию
	String(const char* s); // конструктор 
	~String(); //деструктор 

	// Дружественная функция 
	friend std::ostream& operator<<(std::ostream& os, const String& st);


	//String(const String&);        //прототип конструктора копии
	//String& operator= (const String&); //прототип перегрузки операции присваивания

};