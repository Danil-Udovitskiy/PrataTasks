// Bubble_sort(CodeAbbey).cpp 

#include <iostream>

int main()
{
	//test data1
	//int N = 8;
	//int a[] = { 3, 1, 4, 1, 5, 9, 2, 6};
	//output 5 8

	//test data2
	int N = 23;
	int a[] = { 4, 9, 8, 21, 7, 18, 5, 23, 11, 1, 17, 2, 12, 22, 15, 6, 3, 20, 10, 14, 16, 13, 19 };
	//output 15 108

	int swap = 0;
	int move = 0;

	for (int i = N - 1; i > 0; i--)
	{
		move++;

		bool ind = false;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;

				ind = true;

				swap++;
			}
		}
		if (ind == false)
		{
			break;
		}
	}

	std::cout << move << " " << swap << "\n";
}