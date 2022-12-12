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




// Worker methods
Worker::~Worker()
{
}

// Protected methods
void Worker::Data() const
{
	std::cout << "Name: " << fullname << "\n"; // first and last name
	std::cout << "Employee ID: " << id << "\n";  // identifier
}
void Worker::Get()
{
	std::getline(std::cin, fullname);
	std::cout << "Enter worker's ID: "; // enter worker ID
	std::cin >> id;
	while (std::cin.get() != '\n')
		continue;
}





// Waiter methods
void Waiter ::Set()
{
	std::cout << "Enter waiter's name: "; // enter the name and surname of the waiter
	Worker::Get();
	Get();
}

void Waiter::Show() const
{
	std::cout << "Category: waiter\n"; // category: waiter
	Worker::Data();
	Data();
}


// Protected methods
void Waiter::Data() const
{
	std::cout << "Panache rating: " << panache << "\n"; // style index
}


void Waiter::Get()
{
	std::cout << "Enter waiter's panache rating: ";
	// Enter waiter style index
	std::cin >> panache;
	while (std::cin.get() != '\n')
		continue;
}






// Singer methods
const char* Singer::pv[Singer::Vtypes] = { "other", "alto", "contralto",
"soprano", "bass", "baritone", "tenor" };

void Singer::Set()
{
	std::cout << "Enter singer's name: "; // Entering the name and surname of the singer
	Worker::Get();
	Get();
}


void Singer::Show() const
{
	std::cout << "Category: singer\n"; // Category: singer
	Worker::Data();
	Data();
}


// Protected methods
void Singer::Data() const
{
	std::cout << "Vocal range: " << pv[voice] << "\n"; // vocal range
}


void Singer::Get()
{
	std::cout << "Enter number for singer's vocal range:\n";
	// Enter the singer's vocal range number
	int i;
	for (i = 0; i < Vtypes; i++)
	{
		std::cout << i << " : " << pv[i] << " ";
		if (i % 4 == 3)
			std::cout << "\n";
	}
	if (i % 4 != 0)
		std::cout << '\n';
	std::cin >> voice;
	while (std::cin.get() != '\n')
		continue;
}





// SingingWaiter methods
void SingingWaiter::Data() const
{
	Singer::Data();
	Waiter::Data();
}


void SingingWaiter::Get()
{
	Waiter::Get();
	Singer::Get();
}


void SingingWaiter::Set()
{
	std::cout << "Enter singing waiter's name: ";
	// Entering the name and surname of the singing waiter
	Worker::Get();
	Get();
}


void SingingWaiter::Show() const
{
	std::cout << "Category: singing waiter\n"; // category: singing waiter
	Worker::Data();
	Data();
}


