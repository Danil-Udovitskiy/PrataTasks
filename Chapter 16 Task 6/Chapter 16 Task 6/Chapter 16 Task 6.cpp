// Chapter 16 Task 6.cpp

//Listing 12.12
#include <iostream>
#include <cstdlib> // rand() srand() 
#include <ctime> // time() 


const int MIN_PER_HR = 60;

bool newcustomer(double x); // is there a new client?


int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	// Preparation 
	std::srand(std::time(0)); // random initialization of rand()
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: "; // enter the maximum queue size


	int qs;
	cin >> qs;
	Queue line(qs); // queue can contain up to qs people

	cout << "Enter the number of simulation hours: "; // enter the number of emulated hours
	int hours; // emulation clock
	cin >> hours;

	// Emulation will run one cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // the number of cycles
	cout << "Enter the average number of customers per hour: ";

	// Enter the number of clients per hour
	double perhour; // average number of occurrences per hour 
	cin >> perhour;

	double min_per_cust; // average time between spawns
	min_per_cust = MIN_PER_HR / perhour;
	Item temp; // new client data
	long turnaways = 0; // not allowed in the full queue
	long customers = 0; // attached to the queue
	long served = 0; // serviced during emulation
	long sum_line = 0; // total queue length
	int wait_time = 0; // time until the ATM is free
	long line_wait = 0; // total time in the queue


	// Start Simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) // there is an incoming client
		{
			if (line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle); // cycle = arrival time
				line.enqueue(temp);// adding a newcomer to the queue
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


	// Output results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl; // accepted by clients
		cout << " customers served: " << served << endl; // clients served
		cout << " turnaways: " << turnaways << endl; 	// no clients accepted
		cout << "average queue size: "; // average queue size
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: " // average wait time (minutes)
			<< (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers! \n";
	cout << "Done!\n";
	return 0;
}



// x = average time in minutes between clients
// return true if a client is showing up at this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}

