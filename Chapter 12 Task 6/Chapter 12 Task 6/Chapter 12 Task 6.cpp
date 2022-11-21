// Chapter 12 Task 6.cpp 

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
	Queue first_line(qs); // queue can contain up to qs people

	//adding second queue 
	cout << "Enter maximum size of second queue: "; // enter the maximum second queue size
	int qs2;
	cin >> qs2;
	Queue second_line(qs2); // second queue can contain up to qs people


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

		
		//I add a variable indicator to which queue to add
		bool is_to_first = false;

		//I add a variable indicator from which queue to read
		bool is_from_first = false;


		// Start Simulation
		for (int cycle = 0; cycle < cyclelimit; cycle++)
		{

			//inside the loop, when a new client arrives, we check which of the queues has fewer people
			//if the first is less than the second, then put it in the first
			//otherwise in the second
			


			if (newcustomer(min_per_cust)) // client approached
			{
				if (first_line.isfull() && second_line.isfull()) // ++ && second_line.isfull() - check if both queues are full
					turnaways++;
				else
				{
					//I put out the identical code before the if so that there are no repetitions
					customers++;
					temp.set(cycle); // cycle = arrival time
					
					//then check if the first queue is less than the second
					//+ boolean variable, if the queues are equal, selects where to add the client (if the last addition was in the first place, then the indicator takes the value of true and goes to elc - adding a new client to the second queue and vice versa)
					if ((first_line.queuecount() < second_line.queuecount()) || (first_line.queuecount() == second_line.queuecount() && is_to_first == false))
					
					//if the first queue < the second, then add a new client to queue 1 (and the last addition was to the second one) 

					{
						first_line.enqueue(temp); // adding a newcomer to the queue
						is_to_first = true; //indicator of adding a client from the queue
					}

					else  //if the second queue is < the first, then add a new client to queue 2
					{
						second_line.enqueue(temp);
						is_to_first = false; //indicator of adding a client from the queue
					}
				}
			}




			



			//when we read (remove from the queue), we need an indicator
			
			if (wait_time <= 0 && (!first_line.isempty() || !second_line.isempty()))
			{

				//I put out the identical code before the if so that there are no repetitions

				wait_time = temp.ptime(); // during wait_time minutes
				line_wait += cycle - temp.when();
				served++;


				//this is the reverse logic, from the first queue, deletion occurs first of all from queue 1 (respectively, the > sign)
				//then check if the first queue is greater than the second
				//+ boolean variable if the queues are equal selects where to remove the client from (if the last removal was from the first queue, then the indicator takes the value of true and goes to elc - removing the client from the second queue and vice versa)

				if ((first_line.queuecount() > second_line.queuecount()) || (first_line.queuecount() == second_line.queuecount() && is_from_first == false))
				{
					first_line.dequeue(temp); // serving the next client

					is_from_first = true; //indicator of removing the client from the queue
				}

				else
				{
					second_line.dequeue(temp); // serving the next client

					is_from_first = false; //indicator of removing the client from the queue
				}
			}
			

			
			if (wait_time > 0)
				wait_time--;


			sum_line += first_line.queuecount(); //increase total queue size 1
			sum_line += second_line.queuecount(); //increase total queue size 2

		}

		avarage_wait_time = (double)line_wait / served; //divide the total waiting time by serviced during emulation
		perhour++; // increase the number of clients per hour (increments until the wait time is 1 minute)
	}





	//Added the condition for checking the presence of clients
	// Output results

	if (customers > 0)
	{
		cout << "\nUsing 100 hours simulation period\n";
		cout << " customers accepted : " << customers << endl;
		cout << " customers served : " << served << endl;
		cout << " sum_line : " << sum_line << endl;
		cout << " turnaways : " << turnaways << endl;

		cout << " customers per hour: " << perhour << endl;
		cout << " average wait time: " << avarage_wait_time << " minute\n";
	}
	else
	{
		cout << "No customers! \n";
	}

	cout << "\nDone!\n";
	return 0;
}


// x = average time in minutes between clients
// return true if a client is showing up at this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}