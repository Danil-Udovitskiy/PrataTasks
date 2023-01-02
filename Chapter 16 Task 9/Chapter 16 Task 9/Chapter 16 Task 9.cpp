// Chapter 16 Task 9.cpp

#include <iostream>
#include <vector>

#include <cstdlib> // rand()
#include <ctime> // time(), clock()

#include <list>
#include <algorithm> //sort()

int main()
{
    srand(time(0)); // to generate different values

	//a. Create a large object vi0 of type vector<int> using rand() to set initial values.
    
	std::vector <int> vi0;

	//Fill vec random values
    for (int i = 0; i < 5; i++)
    {
		//int a = rand();
		//vi0.push_back(a);
		vi0.push_back(rand());
    }

	//Show random values in vec
	std::cout << "vi0\n";
	for (int i = 0; i < vi0.size(); i++)
	{
		std::cout << vi0.at(i) << "\n";
	}


	//b. Create a second vi object of type vector<int> and an object li of type list<int>
	// same size as original and initialize them with values source vector.

	//Created vi initialized with vector v (size + values)
    std::vector <int> vi(vi0);

	//Show random values in vec (values of vi0)
    std::cout << "\nvi\n";
    for (int i = 0; i < vi.size(); i++)
    {
		
        std::cout << vi.at(i)<< "\n";
    }


	//Created list li initialized with vector v (size + values)
    std::list <int> li(vi0.begin(), vi0.end());

	//Show random values in list (values of vi0)
	std::cout << "\nli\n";
	for (auto i = li.begin(); i != li.end(); i++)
	{
		std::cout << *i << "\n";
	}



	//c. Measure the time it takes a program to sort vi using the sort() algorithm from the STL
	// then the time needed to sort the li using the list sort() method.

	//vector
	clock_t start = clock();

	std::sort(vi.begin(), vi.end());

	std::cout << "\nvi + sort\n";
	for (int i = 0; i < vi.size(); i++)
	{

		std::cout << vi.at(i) << "\n";
	}

	clock_t end = clock();

	std::cout << "time STL sort() vector - " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

	//list
	start = clock();
	li.sort();
	
	std::cout << "\nli + sort\n";
	for (auto i = li.begin(); i != li.end(); i++)
	{
		std::cout << *i << "\n";
	}

	end = clock();
	std::cout << "time list sort() method - " << (double)(end - start) / CLOCKS_PER_SEC << "\n";



	//d. Reinstall li with the unsorted contents of vi0
	// Measure the running time of a mixed operation of copying li to vi,
	//sorting vi, and copying the result back to li.


	//we can use copy instead of assign 
	//but first clear - li.clear();
	//and than - copy(vi0.begin(), vi0.end(), std::back_inserter(li));

	//Reinstalling li with the unsorted content of vi0
	li.assign(vi0.begin(), vi0.end());

	std::cout << "\nli\n";
	for (auto i = li.begin(); i != li.end(); i++)
	{
		std::cout << *i << "\n";
	}

	//Measure the running time of a mixed operation of copying li to vi, sorting vi, and copying the result back to li.
	start = clock();

	//Copy li to vi
	vi.assign(li.begin(), li.end());
	std::cout << "\nCopy li to vi\n";

	for (int i = 0; i < vi.size(); i++)
	{

		std::cout << vi.at(i) << "\n";
	}

	//Sort vi
	std::sort(vi.begin(), vi.end());
	std::cout << "\nSort vi 2\n";
	for (int i = 0; i < vi.size(); i++)
	{

		std::cout << vi.at(i) << "\n";
	}

	//Copy the result back to li
	li.assign(vi.begin(), vi.end());


	std::cout << "\nCopy the result back to li\n";
	for (auto i = li.begin(); i != li.end(); i++)
	{
		std::cout << *i << "\n";
	}



	end = clock();
	std::cout << "time list copy+sort+copy back " << (double)(end - start) / CLOCKS_PER_SEC << "\n";



}
