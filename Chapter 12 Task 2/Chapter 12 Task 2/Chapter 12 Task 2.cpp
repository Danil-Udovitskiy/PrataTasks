// Chapter 12 Task 2.cpp 

#include <iostream> 
#include "string2.h" 

// Инициализация статического члена класса 
int String::num_strings = 0;

int main()
{
	String sl(" and I am a C++ student.");
	String s2 = " Please enter your name: "; // ввод имени 
	String s3;

	std::cout << s2; // перегруженная операция << 




	/*cin >> s3; // перегруженная операция >> 

	s2 = "My name is " + s3; // перегруженные операции =, + 
	std::cout << s2 << " . \n";
	s2'= s2 + si;

	s2.stringup(); // преобразование строки в верхний регистр 
	std::cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it.\n";
	
	si = "red"; // String(const char *) , 
	// тогда String & operator= (const Strings) 
	String rgb[3] = { String(si), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light: "; // ввод цвета 
	
	String ans;
	bool success = false;

	while (cin >> ans)
	{
		ans.stringlow(); // преобразование строки в нижний регистр 
		for (int i = 0; i < 3; i + +)
		{
			if (ans == rgb[i]) // перегруженная операция == 
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again! \n";
	}
	cout << "Bye\n";*/

	return 0;
}