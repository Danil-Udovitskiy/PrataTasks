// Chapter_18_Task_4.cpp

#include <iostream> 
#include <list> 
#include <iterator> 
#include <algorithm> 


int main()
{
	using std::list;
	using std::cout;
	using std::endl;


	list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	
	// named lambda
	auto show = [](int n) {std::cout << n << " "; };

	cout << "Original lists:\n"; // source lists
	for_each(yadayada.begin(), yadayada.end(), show );
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), show);
	cout << endl;


	// anonymous lambdas to replace the functor
	auto hundred = 100;
	yadayada.remove_if([&hundred](int n) {return n > hundred; });

	auto two_hundred = 200;
	etcetera.remove_if([&two_hundred](int n) {return n > two_hundred; });


	cout << "Trimmed lists:\n"; // truncated lists
	for_each(yadayada.begin(), yadayada.end(), show);
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), show);
	cout << endl;

	return 0;
}

