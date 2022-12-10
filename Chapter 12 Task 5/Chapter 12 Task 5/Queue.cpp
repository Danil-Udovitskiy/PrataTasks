#include "Queue.h" 
#include <cstdlib> // for rand() 


//Listing 12.11.queue.cpp
//methods of the Queue and Customer classes

// Queue class methods
Queue::Queue(int qs) : qsize(qs)
{	
	items = 0;
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


// Adding an element to the queue
bool Queue::enqueue(const Item& item)
{
	if (isfull())
		return false;

	std::shared_ptr<Node> add;
	add.reset(new Node);

	// On failure, the new operation throws a std::bad_alloc exception
	add->item = item; // inserting pointers to nodes
	items++;

	if (front == NULL) // if the queue is empty
	{
		front = add;   // element is placed at the beginning
	}

	else
	{
		rear->next = add; // otherwise it is placed at the end
	}
	rear = add; 	// end pointer points to new node

	return true;
}

// Putting the front element into the item variable and removing it from the queue
bool Queue::dequeue(Item& item)
{
	if (front == NULL)
		return false;
	item = front->item; // item is loaded with the first element from the queue
	items--;
	
	front = front->next; // shift the start pointer to the next element

	if (items == 0)
		rear= NULL;
	return true;
}


// Customer class method
// When a client appears, the moment of his arrival is fixed, 
// and the time maintenance is randomly selected from the range 1-3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}