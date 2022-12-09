#pragma once

//Listing 12.10.queue.h
// queue.h — queue interface
#include <memory>

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
class Queue
{
private:
	// Class scope definitions
	// Node - nested structure, local to this class
	//struct Node { Item item; struct Node* next; };
	
	struct Node { Item item; std::unique_ptr<struct Node> next; };//smart pointer
	
	enum { Q_SIZE = 10 };

	// Private class members
	//Node* front; // pointer to the beginning of the Queue
	//Node* rear; // pointer to end of Queue

	std::unique_ptr<Node> front; //smart pointer
	std::unique_ptr<Node> rear; //smart pointer

	int items; // current number of elements in the Queue
	const int qsize; // maximum number of elements in the Queue
	// Forward declarations to prevent open copy
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }

public:
	Queue(int qs = Q_SIZE); // create queue with size limit qs
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item); // adding an element to the end
	bool dequeue(Item& item); // remove element from start
};
