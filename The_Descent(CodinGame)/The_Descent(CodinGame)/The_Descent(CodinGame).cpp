// The_Descent(CodinGame).cpp 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

int main()
{

	std::vector<int> heights;
	// game loop
	while (1)
	{
		for (int i = 0; i < 8; i++)
		{
			int mountain_h; // represents the height of one mountain.
			cin >> mountain_h;

			heights.push_back(mountain_h); // fill vector by values
		}

		std::sort(heights.rbegin(), heights.rend());

		std::cout << heights[0]; // output 0 index element of vector (the largest - as a result of sorting)

		heights.clear();
	}
}