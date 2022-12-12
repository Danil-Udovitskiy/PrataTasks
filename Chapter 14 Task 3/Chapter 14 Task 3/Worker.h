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



//+++
class Worker // абстрактный базовый класс
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

	virtual ~Worker() = 0; // чистая виртуальная функция
	virtual void Set() = 0;
	virtual void Show() const = 0;
};


//++
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


//+++
class Singer : virtual public Worker
{
protected:

	enum { other, alto, contralto, soprano, bass, baritone, tenor };
	enum { Vtypes = 7 };
	void Data() const;
	void Get();

private:

	static const char* pv[Vtypes]; // строковые эквиваленты видов голосов 
	int voice;

public:

	Singer() : Worker(), voice(other) {}
	Singer(const std:: string & s, long n, int v = other): Worker(s, n), voice(v) {}
	Singer(const Worker& wk, int v = other): Worker(wk), voice(v) { }

	void Set();
	void Show() const;
};
