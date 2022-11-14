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
	 
	//а) Перегрузите операцию + для объединения двух строк в одну.
	friend String operator+(const String& a, const String& b); // перегрузка оператора + по ссылке 
	
	//+++++++++++++++++++++++++++

	// в) Напишите функцию - член stringup(), которая преобразует все буквенные символы в строке в верхний регистр.
	void stringup();

	//г) Напишите функцию - член, которая принимает аргумент типа char и возвращает количество раз, которое символ появляется в строке.
	int has(char a);  //int has(int a);

};