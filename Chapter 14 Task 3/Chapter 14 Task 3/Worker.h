#pragma once
#include <iostream>
#include <string>

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


// Queue class methods
template <typename Tp>
Queue<Tp>::Queue(int qs) : qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}


template <typename Tp>
Queue<Tp>::~Queue()
{
	Node* temp;
	while (front != NULL) // while the queue is not empty
	{
		temp = front; // store the address of the initial element
		front->next;  // reset the pointer to the next element
		delete temp;  // remove the previous initial element - (front)
	}
}


template <typename Tp>
bool Queue<Tp>::isempty() const
{
	return items == 0;
}


template <typename Tp>
bool Queue<Tp>::isfull() const
{
	return items == qsize;
}


template <typename Tp>
int Queue<Tp>::queuecount() const
{
	return items;
}



// Adding an element to the queue
template <typename Tp>
bool Queue<Tp>::enqueue(const Tp& item)
{
	if (isfull())
		return false;

	Node* add = new Node;

	// On failure, the new operation throws a std::bad_alloc exception
	add->item = item; // inserting pointers to nodes
	add->next = NULL; // or nullptr; 
	items++;

	if (front == NULL) // if the queue is empty
		front = add;// element is placed at the beginning
	else
		rear->next = add;// otherwise it is placed at the end

	rear = add; // end pointer points to new node
	return true;
}



// Putting the front element into the item variable and removing it from the queue
template <typename Tp>
bool Queue<Tp>::dequeue(Tp& item)
{
	if (front == NULL)
		return false;
	item = front->item; // item is loaded with the first element from the queue
	items--;


	Node* temp = front; // store the location of the first element

	front = front->next; // shift the start pointer to the next element

	delete temp; // remove the previous first element

	if (items == 0)
		rear = NULL;
	return true;
}



class Worker // abstract base class
{
private:

	std::string fullname;
	long id;

protected:

	virtual void Data() const;
	virtual void Get();

public:

	Worker() : fullname("no one"), id(0L) {}
	Worker(const std::string& s, long n): fullname(s), id(n) {}

	virtual ~Worker() = 0; // pure virtual function
	virtual void Set() = 0;
	virtual void Show() const = 0;
};



class Waiter : virtual public Worker
{
private:

	int panache;

protected:

	void Data() const;
	void Get();

public:

	Waiter() : Worker(), panache(0) {}
	Waiter (const std::string& s, long n, int p = 0): Worker(s, n), panache(p) {}
	Waiter(const Worker& wk, int p = 0): Worker(wk), panache(p) {}
	
	void Set();
	void Show() const;
};



class Singer : virtual public Worker
{
protected:

	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();

private:

	static const char* pv[Vtypes]; // string equivalents of voice types
	int voice;

public:

	Singer() : Worker(), voice(other) {}
	Singer(const std:: string & s, long n, int v = other): Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other): Worker(wk), voice(v) { }

	void Set();
	void Show() const;
};



// Multiple Inheritance
class SingingWaiter : public Singer, public Waiter
{
protected:

	void Data() const;
	void Get();

public:
	SingingWaiter() {}

	SingingWaiter(const std::string& s, long n, int p = 0, int v = other)
		: Worker(s, n), Waiter(s, n, p), Singer(s, n, v) {}
	
	SingingWaiter(const Worker& wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk, p), Singer(wk, v) {}
	
	SingingWaiter(const Waiter& wt, int v = other)
		: Worker(wt), Waiter(wt), Singer(wt, v) {}
	
	SingingWaiter(const Singer& wt, int p = 0)
		: Worker(wt), Waiter(wt, p), Singer(wt) {}

	void Set();
	void Show() const;
};