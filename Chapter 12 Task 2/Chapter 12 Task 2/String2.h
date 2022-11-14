#pragma once
#include <iostream>
#include <cstring>


class String
{
private:

	char* str; // pointer to string
	int len; // string length
	static int num_strings; // number of objects
	static const int CINLIM = 80; // input limit for sin

public:

	String(); // default constructor
	String(const char* s); //constructor
	String(const String& st); //copy constructor
	~String(); //destructor

	
	// Friendly functions 
	friend std::ostream& operator<<(std::ostream& os, const String& st); //overloaded operation <<
	friend std::istream& operator>>(std::istream& is, String& st); //overloaded operation >>
	friend bool operator==(const String& stl, const String& st2); // overloaded operation ==

	//a) Overload the + operator to combine two strings into one.
	friend String operator+(const String& a, const String& b); // operator overload + by reference 

	//c) a member function of stringup() that converts all alphabetic characters in a string to uppercase.
	void stringup();

	//d) a member function that takes an argument of type char and returns the number of times the character appears in the string.
	// first i made with int argument int has(int a);
	int has(char a);  

	//b) a member function of stringlow() that converts all alphabetic characters in a string to lowercase.
	void stringlow();

	String& operator= (const String& st); // prototype of assignment operator overload
	String& operator= (const char* s); // overload prototype of C-string assignment operator to String object 

	char& operator [] (int i); // read-write char for non-const String objects
	const char& operator [] (int i) const; //// For use with const String objects

};