// Chapter_18_Task_4.cpp

//Error in the task about Lissting 16.5 
/*
//Listing 16.5 
#include <iostream> 
#include <string> 
#include <memory> 

class Report
{
private:
	std::string str;
public:
	Report(const std::string s) : str(s)
	{
		std::cout << "Object created!\n";
	}

	~Report() { std::cout << "Object deleted!\n"; }
	void comment() const { std::cout << str << "\n"; }
};

int main()
{
	{
		std::auto_ptr<Report> ps(new Report("using auto_ptr"));
		ps->comment(); // using the -> operation to call a member function
	}

	{
		std::shared_ptr<Report> ps(new Report("using shared_ptr"));
		ps->comment();
	}

	{
		std::unique_ptr<Report> ps(new Report("using unique_ptr"));
		ps->comment();
	}
	return 0;
}*/



//Required listing 16.15
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
void outint(int n) { std::cout << n << " "; }

int main()
{
	using std::list;
	using std::cout;
	using std::endl;

	TooBig<int> f100(100); // limit value = 100
	int vals[10] = { 50, 100, 90, 180, 60, 210, 415, 88, 188, 201 };
	list<int> yadayada(vals, vals + 10); // range constructor
	list<int> etcetera(vals, vals + 10);

	// Instead, in C++11, you can use the following code:
	// list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	// list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
	
	cout << "Original lists:\n"; // source lists
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;

	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;



	yadayada.remove_if(f100);		// use named function object

	etcetera.remove_if(TooBig<int>(200)); // constructing a functional object 

	cout << "Trimmed lists:\n"; // truncated lists
	for_each(yadayada.begin(), yadayada.end(), outint);
	cout << endl;
	for_each(etcetera.begin(), etcetera.end(), outint);
	cout << endl;

	return 0;
}

