// Reverse_string(CodeAbbey).cpp 

#include <iostream>
#include <string>
#include <algorithm>

//1 variant 
int main()
{
	std::string str;
	std::cout << "Enter string: ";
	getline(std::cin, str);

	for (int i = str.size()-1; i >= 0; i--)
	{
		std::cout << str[i];
	}
	std::cout << "\n";
}


//2 variant (with reverse)
//int main()
//{
//	std:: string str;
//
//	std::cout << "Enter string: ";
//	getline(std::cin, str);
//
//	reverse(str.begin(), str.end());
//	std::cout << str << "\n";
//}


 


