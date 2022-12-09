#include "String2.h"
#include <string.h> // for strcat_s

#pragma warning(disable:4996)

String::String()
{
	len = 0;
	num_strings++; //increment the counter of objects 
}


String::String(const char* s)
{
	len = std::strlen(s) + 1; // set the length + 1 

	str.reset(new char[len]); // allocate memory for a new string 
	strcpy_s(str.get(), len, s); // copying a string

	num_strings++;       //increment the counter of objects
}


String::String(const String& st)
{
	num_strings++; // handle static member update
	len = st.len + 1; // set the length by 1 more to enter another line ending character

	//now there is no need to allocate one more character for the end of the string, since len already has an extra byte
	str.reset(new char[len]); // allocate memory for a new string 
	strcpy_s(str.get(), len, st.str.get()); // copy the string to a new location 
}


String:: ~String()
{
	--num_strings;
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

	len = st.len + 1;
	str.reset(new char[len]);
	
	//this option is better
	strcpy_s(str.get(), len, st.str.get());

	return *this;
}



String operator+(const String& st1, const String& st2) // overload + by reference
{
	String sum;

	sum.len = (strlen(st1.str.get()) + strlen(st2.str.get())) + 1;

	sum.str.reset(new char[sum.len]); // allocate memory for a new string

	strcat(strcpy(sum.str.get(), st1.str.get()), st2.str.get());

	//strcat adds adds a copy of the character string pointed to by st2.str to the end of the string,
	//pointed to by strcpy(sum.str, st1.str)

	return sum;
}



String& String::operator=(const char* s) // Assigning a C-string to a String object
{
	len = std::strlen(s) + 1;

	str.reset(new char[len]); // allocate memory for a new string
	strcpy_s(str.get(), len, s); // copying a string

	return *this;
}


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

	int size = strlen(str.get());
	for (int i = 0; i < size; i++)
	{
		if (str[i] == ch)
			count++;
	}

	return count;
}


void String::stringlow()

{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}

}



// Read and write access to individual characters in a non-const String object
char& String::operator [] (int i)
{
	return str[i];
}

// Read-only access to individual characters in a const String object
const char& String:: operator [] (int i) const
{
	return str[i];
}

// overloaded operation ==
bool operator==(const String& stl, const String& st2)
{
	return (std::strcmp(stl.str.get(), st2.str.get()) == 0);
}



