// Chapter 12 Task 2.cpp 

#include <iostream> 
#include "string2.h" 

// Initialize a static class member
int String::num_strings = 0;

int main()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: "; // name input
	String s3;

	std::cout << s2; // overloaded operation <<

	std::cin >> s3; // overloaded operation >>

	s2 = "My name is " + s3; // overloaded operations =, +
	std::cout << s2 << " .\n";
	
	s2 = s2 + s1;


	//+++from this code changes
	s2.stringup(); // convert string to uppercase
	
	std::cout << "The string\n" << s2 << "\ncontains " << s2.has('A') // s2.has('A'/65)
		<< " 'A' characters in it.\n";

	
	s1 = "red"; // String(const char *)
	
	// String & operator= (const Strings) 
	String rgb[3] = { String(s1), String("green"), String("blue") };
	std::cout << "Enter the name of a primary color for mixing light: "; // color input 
	
	String ans;
	bool success = false;

	while (std::cin >> ans)
	{
		ans.stringlow(); // convert string to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) // overloaded operation ==
			{
				std::cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			std::cout << "Try again! \n";
	}
	std::cout << "Bye\n";

	return 0;
}