#pragma once
#include <iostream>
//Listing 12.10
//Without declaring a Queue class, as the <queue> template will be used

class Customer
{
private:
	long arrive; // the moment the client appears
	int processtime; // customer service time
public:
	Customer() { arrive = processtime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
typedef Customer Item;
