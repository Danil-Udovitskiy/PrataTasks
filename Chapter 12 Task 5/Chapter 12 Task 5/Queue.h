#pragma once

//Listing 12.10.queue.h
// queue.h Ч интерфейс дл€ очереди 

// ќчередь, содержаща€ элементы Customer 
class Customer
{
private:
	long arrive; // момент по€влени€ клиента 
	int processtime; // врем€ обслуживани€ клиента 
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
	// ќпределени€ области действи€ класса 
	// Node - вложенна€ структура, локальна€ дл€ данного класса 
	struct Node { Item item; struct Node* next; };
	enum { Q_SIZE = 10 };

	// «акрытые члены класса 
	Node* front; // указатель на начало Queue 
	Node* rear; // указатель на конец Queue 
	int items; // текущее количество элементов в Queue 
	const int qsize; // максимальное количество элементов в Queue 
	// ”преждающие объ€влени€ дл€ предотвращени€ открытого копировани€ 
	Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }

public:
	Queue(int qs = Q_SIZE); // создание очереди с предельным размером qs 
	~Queue();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item); // добавление элемента в конец 
	bool dequeue(Item& item); // удаление элемента из начала 
};
