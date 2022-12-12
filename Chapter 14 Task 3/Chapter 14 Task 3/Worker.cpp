#include "Worker.h"

//Listing 12.11.queue.cpp
//methods of the Queue with template application


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



//+++
// Методы Worker
Worker::~Worker()
{
}

// Защищенные методы
void Worker::Data() const
{
	std::cout << "Name: " << fullname << "\n"; // имя и фамилия
	std::cout << "Employee ID: " << id << "\n";  // идентификатор
}
void Worker::Get()
{
	std::getline(std::cin, fullname);
	std::cout << "Enter worker's ID: "; // ввод идентификатора работчика
	std::cin >> id;
	while (std::cin.get() != '\n')
		continue;
}
