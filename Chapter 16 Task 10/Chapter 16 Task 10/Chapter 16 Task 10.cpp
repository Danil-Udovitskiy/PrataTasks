// Chapter 16 Task 10.cpp 

//Listing 16.9
//using STL functions
#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm>
#include <memory>

struct Review {
	std::string title;
	int rating;

	// add the price member to the Review
	double price;
};


bool operator<(const std::shared_ptr<Review>& rl, const std::shared_ptr<Review>& r2);
bool worseThan(const std::shared_ptr<Review>& rl, const std::shared_ptr<Review>& r2);
bool FillReview(Review* rr);
void ShowReview(std::shared_ptr<Review> rr);

// add a function to compare prices
bool worseThan_price(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);


int main()
{
	using namespace std;

	// Use a vector of objects to store input
	// shared_ptr<Review> instead of a vector of Review objects. //vector<Review> books;

	vector <shared_ptr<Review>> books;

	Review temp;


	while (FillReview(&temp))
	{
		shared_ptr<Review> temp1(new Review(temp));//(temp)

		books.push_back(temp1);
	}

	//Create another vector of pointers shared_ptr, initialized with original vector
	//sorting will be done with the new vector - (new_books)
	vector <shared_ptr<Review>> new_books(books);


	if (books.size() > 0)
	{
		cout << "\nThank you. You entered the "
			<< books.size() << " packs of data\n";


		bool indicator = true;
		while (indicator == true) 
		{
			cout << "\nHow to Show ?\n"
				<< "1 - in original order;\n"
				<< "2 - in alphabetical order;\n"
				<< "3 - in ascending order of rating;\n"
				<< "4 - in ascending order of price;\n"
				<< "5 - in descending order of price;\n"
				<< "6 - exit.\n\n";

			int choice;
			cin >> choice;
			while ((choice < 1) && (choice > 5))
			{
				cout << "Wrong input. Repeat: ";
				cin >> choice;
			}

			switch (choice)
			{
			case 1:
			{
				cout << "\nRating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			}
			case 2:
			{
				sort(new_books.begin(), new_books.end());
				cout << "Sorted by title:\nRating\tBook\tPrice\n";
				// List of books sorted by title
				for_each(new_books.begin(), new_books.end(), ShowReview);
				break;
			}
			case 3:
			{
				sort(new_books.begin(), new_books.end(), worseThan);
				cout << "Sorted by rating:\nRating\tBook\tPrice\n";
				// List of books sorted by rating
				for_each(new_books.begin(), new_books.end(), ShowReview);
				break;
			}
			case 4:
			{
				cout << "Sorted by price low-hi:\nRating\tBook\tPrice\n";
				// List of books sorted by price low-hi
				sort(new_books.begin(), new_books.end(), worseThan_price);
				for_each(new_books.begin(), new_books.end(), ShowReview);
				break;
			}
			case 5:
			{
				cout << "Sorted by price hi-low:\nRating\tBook\tPrice\n";
				// List of books sorted by price hi-low
				sort(new_books.begin(), new_books.end(), worseThan_price);
				for_each(new_books.rbegin(), new_books.rend(), ShowReview); //using rbegin/rend to reverse show
				break;
			}
			default:
			{
				indicator = false;
				break;
			}
			}
		}
	}


	else
	{
		cout << "No entries. ";
	}
	cout << "Bye.\n";
	return 0;
}





bool operator<(const std::shared_ptr<Review>& rl, const std::shared_ptr<Review>& r2)
{
	if (rl->title < r2->title)
		return true;
	else if (rl->title == r2->title && rl->rating < r2->rating)
		return true;
	//Add price comparison
	else if (rl->title == r2->title && rl->rating == r2->rating && rl->price < r2->price)
		return true;
	else
		return false;
}


bool worseThan(const std::shared_ptr<Review>& rl, const std::shared_ptr<Review>& r2)
{
	if (rl->rating < r2->rating)
		return true;
	else
		return false;
}


bool FillReview(Review* rr) //function takes object by pointer
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr->title);
	if (rr->title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr->rating;
	if (!std::cin)
		return false;

	//++
	std::cout << "Enter book price: ";
	std::cin >> rr->price;
	if (!std::cin)
		return false;

	// Delete the rest of the input line
	while (std::cin.get() != '\n')
		continue;
	return true;
}


void ShowReview(std::shared_ptr<Review> rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}


bool worseThan_price(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	if (r1->price < r2->price)
		return true;
	else
		return false;
}
