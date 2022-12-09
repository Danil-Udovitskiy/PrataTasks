#include "Stock.h"
//Listing 10.8 (pg 506-507)

//constructors

Stock::Stock() // default constructor
{
	//if object doesn't have name 

	shares = 0;
	share_val = 0.0;
	total_val = 0.0;

	num++;
}


Stock::Stock(const char* co, int n, double pr) // constructor with arguments
{
	//if object has name
	
	int len = strlen(co) + 1;
	company.reset(new char[len]); 
	strcpy_s(company.get(), len, co);
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
	if (st.company != nullptr)
	{
		os << " Company : " << st.company << "\n";
	}
	else
	{
		os << " Company : no name " << "\n";
	}

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