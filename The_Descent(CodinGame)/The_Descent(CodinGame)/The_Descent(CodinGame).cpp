// The_Descent(CodinGame).cpp 

#include <iostream>
#include <vector>

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
	// game loop
	while (1)
	{
		std::vector<int> heights;
		for (int i = 0; i < 8; i++)
		{
			int mountain_h; // represents the height of one mountain.
			cin >> mountain_h;

			heights.push_back(mountain_h); // fill vector by values
		}

		int maxValue = heights[0];
		int index_to_fire = 0;
		for (int i = 1; i < heights.size(); i++)
		{
			if (heights[i] > maxValue)  // find the largest value
			{
				maxValue = heights[i];
				index_to_fire = i;		// assign the index of the largest value
			}
		}

		std::cout << index_to_fire << std::endl; // display the index of the largest element (for attack the mountain N)
	}
}