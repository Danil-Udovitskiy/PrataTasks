#include "String2.h"
#include <string.h> // for strcat_s

#pragma warning(disable:4996)

String::String()
{
	len = 0;
	str = new char[1];
	str[0] = '\0'; // line

	//spent a lot of time to find the missing increment here 
	//and getting negative output of destructors without  increment
	num_strings++; //increment the counter of objects 
}


String::String(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];     //+1 is needed for a null character, a sign of the end of a string
	strcpy_s(str, strlen(s) + 1, s);  // create a string based on the parameter value
	str[len] = '\0';    //just in case, if the string is too big, forcibly rewrite the last character, if suddenly there is no end in the string

	num_strings++;       //increment the counter of objects

	//std::cout << num_strings << " : " << str << " object created\n"; //for debugging
}


String::String(const String& st)
{
	num_strings++; // handle static member update
	len = st.len; // same length
	str = new char[len + 1]; // memory allocation
	strcpy_s(str, strlen(st.str) + 1, st.str); // copy the string to a new location
}


String:: ~String()
{
	//std::cout << str << " object deleted "; //for debugging
	--num_strings;
	//std::cout << num_strings << " left\n"; //for debugging
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



String operator+(const String& st1, const String& st2) // overload + by reference
{
	String sum;
	delete sum.str;
	sum.len = strlen(st1.str) + strlen(st2.str);
	sum.str = new char[sum.len + 1];

	strcat(strcpy(sum.str, st1.str), st2.str); 
	//strcat adds adds a copy of the character string pointed to by st2.str to the end of the string,
	//pointed to by strcpy(sum.str, st1.str)

	//strcpy copies the contents of st1.str to sum.str (sum.str beforehand has the size(st1.str + st2.str) +1)
	return sum;
}



String& String::operator=(const char* s) // Assigning a C-string to a String object
{
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];  
	strcpy_s(str, strlen(s) + 1, s);
	str[len] = '\0'; 
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

	int size = strlen(str);
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
	return (std::strcmp(stl.str, st2.str) == 0);
}



