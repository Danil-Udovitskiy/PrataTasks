// Chapter 15 Task 4.cpp 

//Листинг 15.16.use_sales.срр
// use_sales.cpp -- вложенные исключения 
#include <iostream> 
#include "Sales.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	double valsl[12] =
	{
	1220, 1100, 1122, 2212, 1232, 2334,
	2884, 2393, 3302, 2922, 3002, 3544
	};
	double vals2[12] =
	{
	12, 11, 22, 21, 32, 34,
	28, 29, 33, 29, 32, 35
	};
	
	Sales salesl(2011, valsl, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);
	
	
	cout << "First try block: \n"; // первый блок try 
	try
	{
		int i;
		cout << "Year = " << salesl.Year() << endl; // год 
		for (i = 0; i < 12; ++i)
		{
			cout << salesl[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl; // год 
		cout << "Label = " << sales2.Label() << endl; // метка 
		for (i = 0; i <= 12; ++i)
		{
			cout << sales2[i] << ' ';
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "End of try block 1.\n"; // конец первого блока try 
	}


	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl; // компания 
		cout << "bad index: " << bad.bi_val() << endl; // недопустимый индекс 
	}
	catch (Sales:: bad_index & bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl; // недопустимый индекс 
	}

	
	
	
	cout << "\nNext try block: \n"; // второй блок try 
	try
	{
		sales2[2] = 37.5;
		salesl[20] = 23345;
		cout << "End of try block 2.\n"; // конец второго блока try 
	}


	catch (LabeledSales::nbad_index& bad)
	{
		cout << bad.what();
		cout << "Company: " << bad.label_val() << endl; // компания 
		cout << "bad index: " << bad.bi_val() << endl; // недопустимый индекс 
	}
	catch (Sales::bad_index& bad)
	{
		cout << bad.what();
		cout << "bad index: " << bad.bi_val() << endl; // недопустимый индекс 
	}


	cout << "done\n";
	return 0;
}

