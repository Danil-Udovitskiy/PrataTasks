// Chapter 14 Task 3.cpp

//Listing 14.12
//multiple inheritance

#include <iostream>
#include <cstring>
#include "Worker.h"

const int SIZE = 5;
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	//the error was that I just created an array of pointers to the Worker, 
	//without using the Queue template

	Queue<Worker*> lolas[SIZE]; //created a queue of pointers to the Worker
	
	
	return 0;
}