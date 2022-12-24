// Chapter 15 Task 4.cpp 

//Listing 15.16
//nested exceptions
#include <iostream> 
#include "Sales.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	double vals1[12] =
	{
	1220, 1100, 1122, 2212, 1232, 2334,
	2884, 2393, 3302, 2922, 3002, 3544
	};
	double vals2[12] =
	{
	12, 11, 22, 21, 32, 34,
	28, 29, 33, 29, 32, 35
	};
	
	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);
	
	
	cout << "First try block: \n"; // first try block
	try
	{
		int i;
		cout << "Year = " << sales1.Year() << endl; // year
		for (i = 0; i < 12; ++i)
		{
			cout << sales1[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl; // year
		cout << "Label = " << sales2.Label() << endl; // label
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n"; // end of first try block
	}



	catch (Sales::bad_index& bad)
	{
		try {
			// using dynamic_cast, check if the type nbad_index is a successor of bad_index
			LabeledSales::nbad_index& nbad = dynamic_cast<LabeledSales::nbad_index&> (bad); // use nbad
			cout << "Company: " << nbad.label_val() << endl; // company
		}

		// handler for inner try block
		catch (std::bad_cast&) //failed to cast to a child type (perform dynamic_cast), i.e. bad is not LabeledSales::nbad_index
		{
			cout << bad.what(); //which object has an invalid index 
			cout << "bad index: " << bad.bi_val() << endl; // invalid index (use bad as Sales::bad_index)
		}
	}




	
	
	
	cout << "\nNext try block: \n"; // second try block
	try {
		sales2[2] = 37.5;
		sales1[20] = 23345;
		cout << "End of try block 2.\n"; // end of second try block
	}


	catch (Sales::bad_index& bad)
	{

		try 
		{
			LabeledSales::nbad_index& nbad = dynamic_cast<LabeledSales::nbad_index&> (bad);
			cout << "Company: " << nbad.label_val() << endl;
		}

		//if it was not possible to cast to a child type(execute dynamic_cast) in try block, we go into the catch find out which object has the wrong index
		//and under what number it is stored
		catch (std::bad_cast&)  
		{
			cout << bad.what();
			cout << "bad index: " << bad.bi_val() << endl;
		}
	}


	cout << "done\n";
	return 0;
}

