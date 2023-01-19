// Chapter_18_Task_4.cpp

//Listing 16.15
#include <iostream> 
#include <list> 
#include <iterator> 
#include <algorithm> 

template<class T> // functor class defines operator()()
class TooBig
{
private:
	T cutoff;
public:
	TooBig(const T& t) : cutoff(t) {}
	bool operator () (const T& v) { return v > cutoff; }
};


int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100); // limit value = 100
	
	list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	
	cout << "Original lists:\n"; // source lists
	for_each(yadayada.begin(), yadayada.end(), [](int n) {std::cout << n << " "; });
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), [](int n) {std::cout << n << " "; });
	cout << endl;


	yadayada.remove_if(f100);		// use named function object

	etcetera.remove_if(TooBig<int>(200)); // constructing a functional object 

	cout << "Trimmed lists:\n"; // truncated lists
	for_each(yadayada.begin(), yadayada.end(), [](int n) {std::cout << n << " "; });
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), [](int n) {std::cout << n << " "; });
	cout << endl;

	return 0;
}

