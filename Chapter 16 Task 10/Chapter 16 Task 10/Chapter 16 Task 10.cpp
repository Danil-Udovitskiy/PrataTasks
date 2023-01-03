// Chapter 16 Task 10.cpp 

//Listing 16.9
//using STL functions
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 

struct Review {
	std::string title;
	int rating;

	// add the price member to the Review
	double price;
};

bool operator<(const Review& rl, const Review& r2);
bool worseThan(const Review& rl, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const Review& rr);

//++++++++++
// add a function to compare prices
bool worseThan_price(const Review& r1, const Review& r2)
{
	if (r1.price < r2.price)
		return true;
	else
		return false;
}

bool betterThan_price(const Review& r1, const Review& r2)
{
	if (r1.price > r2.price) 
		return true;
	else
		return false;
}


int main()
{
	using namespace std;
	vector<Review> books;

	Review temp;

	while (FillReview(temp))
		books.push_back(temp);


	if (books.size() > 0)
	{
		cout << "Thank you. You entered the following "
			<< books.size() << " ratings:\n"
			<< "Rating\tBook\tPrice\n";

		for_each(books.begin(), books.end(), ShowReview);
		sort(books.begin(), books.end());

		cout << "Sorted by title:\nRating\tBook\tPrice\n";
		// List of books sorted by title
		for_each(books.begin(), books.end(), ShowReview);
		sort(books.begin(), books.end(), worseThan);

		cout << "Sorted by rating:\nRating\tBook\tPrice\n";
		// List of books sorted by rating
		for_each(books.begin(), books.end(), ShowReview);

		//++
		cout << "Sorted by price low-hi:\nRating\tBook\tPrice\n";
		// List of books sorted by price low-hi
		sort(books.begin(), books.end(), worseThan_price);
		for_each(books.begin(), books.end(), ShowReview);
		
		//++
		cout << "Sorted by price hi-low:\nRating\tBook\tPrice\n";
		// List of books sorted by price hi-low
		sort(books.begin(), books.end(), betterThan_price);
		for_each(books.begin(), books.end(), ShowReview);
		
		random_shuffle(books.begin(), books.end());

		cout << "After shuffling:\nRating\tBook\n";
		// List of books after shuffling
		for_each(books.begin(), books.end(), ShowReview);
	}
	else
	{
		cout << "No entries. ";
	}
	cout << "Bye.\n";
	return 0;
}



bool operator<(const Review& rl, const Review& r2)
{
	if (rl.title < r2.title)
		return true;
	else if (rl.title == r2.title && rl.rating < r2.rating)
		return true;
	else
		return false;
}
bool worseThan(const Review& rl, const Review& r2)
{
	if (rl.rating < r2.rating)
		return true;
	else
		return false;
}

//++
bool FillReview(Review& rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if (!std::cin)
		return false;

	//++
	std::cout << "Enter book price: ";
	std::cin >> rr.price;
	if (!std::cin)
		return false;

	// Delete the rest of the input line
	while (std::cin.get() != '\n')
		continue;
	return true;
}

//++
void ShowReview(const Review& rr)
{
	//++
	std::cout << rr.rating << "\t" << rr.title << "\t" << rr.price << std::endl;
}