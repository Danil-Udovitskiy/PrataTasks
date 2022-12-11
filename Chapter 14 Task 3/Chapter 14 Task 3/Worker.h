#pragma once

//Listing 12.10.queue.h

template <typename Tp> //template definition QueueTp 

class Queue
{
private:
	// Class scope definitions
	// Node - nested structure, local to this class
	struct Node { Tp item; struct Node* next; };
	enum { Q_SIZE = 10 };

	// Private class members
	Node* front; // pointer to the beginning of the Queue
	Node* rear;  // pointer to end of Queue

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
	bool enqueue(const Tp& item); // adding an element to the end
	bool dequeue(Tp& item); // remove element from start
};























