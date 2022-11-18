#include "Queue.h" 
#include <cstdlib> // (��� stdlib.h) ��� rand() 


//Listing 12.11.queue.cpp
// queue.cpp � ������ ������� Queue � Customer 

// ������ ������ Queue 
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL; // ��� nullptr 
	items = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != NULL) // ���� ������� �� �����	
	{
		temp = front;			// ���������� ������ ���������� �������� 
		front = front->next;	// ������������� ��������� �� ��������� ������� 
		delete temp;			// �������� ����������� ���������� �������� 
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}


// ���������� �������� � ������� 
bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;
	Node* add = new Node; // �������� ���� 

	// ��� ��������� ���������� �������� new ���������� ���������� std::bad_alloc 
	add->item = item; // ��������� ���������� �� ���� 
	add->next = NULL; // ��� nullptr; 
	items++;
	if (front == NULL) // ���� ������� �����,
		front = add;   // ������� ���������� � ������ 
	else
		rear->next = add; // ����� �� ���������� � ����� 
	rear = add; 	// ��������� ����� ��������� �� ����� ���� 
	return true;
}

// ��������� �������� front � ���������� item � ��� �������� �� ������� 
bool Queue::dequeue(Item& item)
{
	if (front == NULL)
		return false;
	item = front->item; // � item ��������� ������ ������� �� ������� 
	items--;
	Node* temp = front; // ���������� �������������� ������� �������� 
	front = front->next; // ����� ��������� ������ �� ��������� ������� 
	delete temp; // �������� ����������� ������� �������� 
	if (items == 0)
		rear = NULL;
	return true;
}


// ����� ������ Customer 
// ��� ��������� ������� ����������� ������ ��� ��������, � ����� 
// ������������ ���������� ��������� ������� �� ��������� 1-3 
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}