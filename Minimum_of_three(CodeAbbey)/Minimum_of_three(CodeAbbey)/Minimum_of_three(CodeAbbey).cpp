// Minimum_of_three(CodeAbbey).cpp 

#include <iostream>

 int main()
 {
 	int size = 0, first = 0, second = 0, third = 0;
 
    std::cout << "Enter numbers of pairs to get min: ";
 	std::cin >> size;
 
 	for (int i = 0; i < size; i++)
 	{
 		std::cout << "Enter 3 values :";
 		std::cin >> first >> second >> third;

        if (first < second && first < third)
 		{
 			std::cout << "Min is " << first << "\n";
 		}
 		else if (second < first && second < third)
 		{
 			std::cout << "Min is " << second << "\n";
 		}
 		else //if (third < first && third < second)
 		{
 			std::cout << "Min is " << third << "\n";
 		}
 	}
 }


 //shorter version
 /* min = a;
if (min > b)
min = b;
if (min > c)
min = c;
 output min*/