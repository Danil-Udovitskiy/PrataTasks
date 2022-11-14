#include "Stock.h"
//Listing 10.8 (pg 506-507)

//constructors

Stock::Stock() // default constructor
{
	strcpy_s(company, strlen(company) + 1, company);
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}


Stock::Stock(const char* со, int n, double pr) // constructor with arguments
{
	strcpy_s(company, strlen(со) + 1, со);
	company[29] = '\0';

	if (n < 0)
	{
		std::cerr << " The number of packets cannot be negative for "
			<< company << " installed in 0. \n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
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
	os << " Company : " << st.company;
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