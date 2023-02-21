#include "Good.h"

std::ostream& operator<< (std::ostream& out, const Good& good)
{
	out << good.price << " " << good.weight;
	return out;
}