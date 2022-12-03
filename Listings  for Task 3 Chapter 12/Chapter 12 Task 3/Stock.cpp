#include "Stock.h"
//Listing 10.8 (pg 506-507)

//constructors

Stock::Stock() // default constructor
{
	//if object doesn't have name 
	company = new char[1]; // dynamic memory allocation
	company[0] = '\0'; 

	shares = 0;
	share_val = 0.0;
	total_val = 0.0;

	num++;
}


Stock::Stock(const char* co, int n, double pr) // constructor with arguments
{
	//if object has name
	
	// the size of the selected string company was not large enough to fit all characters + '\0' at the end
	company = new char[strlen(co) + 1]; //allocate the amount of dynamic memory equal to the size of the array co
	strcpy_s(company, strlen(co) + 1, co); //copy the contents of co to company(which in turn is a pointer to the char)
	num++;


	if (n < 0)
	{
		std::cerr << " The number of packets cannot be negative for "
			<< company << " installed in 0. \n";
		shares = 0;
	}
	else
	{
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	--num;
	std::cout << "dectr " << num << "\n";
	delete[] company; // delete all objects 
}


//other methods
void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		std::cerr << " The number of purchased packages cannot be negative. "
			<< " Transaction aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0)
	{
		cerr << " The number of packages sold cannot be negative. "
			<< " Transaction aborted.\n ";
	}
	else if (num > shares)
	{
		cerr << " You can not sell more than what you own ! "
			<< " Transaction aborted.\n ";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}


void Stock::update(double price)
{
	share_val = price;
	set_tot();
}


std::ostream& operator<<(std::ostream& os, const Stock& st) // operator overload <<
{
	os << " Company : " << st.company << "\n";
	os << " Packages : " << st.shares << "\n";
	os << " Package price : $" << st.share_val << "\n";
	os << " Total cost : $" << st.total_val << "\n";
	return os;
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
	{
		return s;
	}
	else
		return *this;
}