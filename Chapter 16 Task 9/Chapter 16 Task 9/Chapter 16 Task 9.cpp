// Chapter 16 Task 9.cpp

#include <iostream>
#include <vector>

#include <cstdlib> // rand()
#include <ctime> // time()

#include <list>

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

}
