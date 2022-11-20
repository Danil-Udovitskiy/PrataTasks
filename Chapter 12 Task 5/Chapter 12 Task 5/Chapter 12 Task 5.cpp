// Chapter 12 Task 5.cpp 

//Listing 12.12.bank.срр
// bank.срр -- использование интерфейса Queue 

#include <iostream> 
#include <cstdlib> // for rand() and srand() 
#include <ctime> // for time() 
#include "Queue.h" 


const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new client?


int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	
	// Preparation
	std::srand(std::time(0)); // random initialization rand()
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: "; // enter the maximum queue size
	
	int qs;
	cin >> qs;
	Queue line(qs); // queue can contain up to qs people

	int hours = 100; // enter the number of simulated hours given by the task condition - (Use at least a 100-hour simulation period.)

	// The emulation will run one cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // the number of cycles
	double perhour = 0.0;       // number of customers per hour

	double min_per_cust; // average time between spawns
	Item temp;  // new client data
	long turnaways = 0; // not allowed in the full queue
	long customers = 0; // attached to the queue
	long served = 0; // serviced during emulation
	double sum_line = 0; // total queue length
	int wait_time = 0; // time until the ATM is free
	long line_wait = 0; // total time in the queue
	

	//I add a variable to calculate the average waiting time
	int avarage_wait_time = 0; // average client wait time
	

	//Add a loop with a 1 minute wait condition
	while (avarage_wait_time < 1) // condition for a total wait time of 1 minute
	{
		min_per_cust = MIN_PER_HR / perhour; //initialize variable to generate client spawn
		//first return from the function newcustomer = false (default) , that is the client does not appear

		// Start Simulation
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{
			if (newcustomer(min_per_cust)) // client approached
			{
				if (line.isfull())
					turnaways++;
				else
				{
					customers++;
					temp.set(cycle); // cycle = arrival time
					line.enqueue(temp); // adding a newcomer to the queue
				}
			}


			if (wait_time <= 0 && !line.isempty())
			{
				line.dequeue(temp); // serving the next client
				wait_time = temp.ptime(); // during wait_time minutes
				line_wait += cycle - temp.when();
				served++;
			}

			if (wait_time > 0)
				wait_time--;
			sum_line += line.queuecount();
		}

		avarage_wait_time = (double)line_wait / served; //divide the total waiting time by serviced during emulation
		perhour++; // increase the number of clients per hour (increments until the wait time is 1 minute)
		
	}


	//removed the condition for checking the presence of clients, since in this case it does not make sense
	// Output results

	cout << "\nUsing 100 hours simulation period\n";
	cout << " customers accepted : " << customers << endl;
	cout << " customers served : " << served << endl;
	cout << " sum_line : " << sum_line << endl;
	cout << " turnaways : " << turnaways << endl;

	cout << " customers per hour: " << perhour << endl;
	cout << " average wait time: " << avarage_wait_time << " minute\n";

	cout << "\nDone!\n";
	return 0;
}


// x = average time in minutes between clients
// return true if a client is showing up at this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}



