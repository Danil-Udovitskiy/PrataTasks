// Power_of_Thor_Episode_1(Codingame).cpp 

#include <iostream>

using namespace std;

int main()
{
    //point coordinates (to be reached)
    int light_x; // the X position of the light of power
    int light_y; // the Y position of the light of power

    //character starting positions
    int initial_tx; // Thor's starting X position
    int initial_ty; // Thor's starting Y position

    cin >> light_x >> light_y >> initial_tx >> initial_ty; cin.ignore();

    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move.

        cin >> remaining_turns; cin.ignore();


        if (initial_ty > 17 && initial_tx > 39)
        {
            return 1;
        }


        else if (initial_ty < light_y && initial_tx < light_x) // check for height, then for width
        {
            std::cout << "SE" << std::endl; //southeast down to the right we go (diagonal along the Y and X axes)
            initial_ty++;
            initial_tx++;
        }

        else if (initial_ty < light_y && initial_tx == light_x) // height check (the width is the same)
        {
            std::cout << "S" << std::endl;  //south (down south only on the y axis)
            initial_ty++;
        }

        else if (initial_ty == light_y && initial_tx < light_x) // check for width (height is the same)
        {
            std::cout << "E" << std::endl; //east (right to east only on the X axis)
            initial_tx++;
        }

        else if (initial_ty > light_y && initial_tx > light_x)
        {
            std::cout << "NW" << std::endl; //northwest (up to the left along the Y and X axes)
            initial_ty--;
            initial_tx--;
        }

        else if (initial_ty > light_y && initial_tx == light_x)
        {
            std::cout << "N" << std::endl; //north (up y-axis)
            initial_ty--;
        }

        else if (initial_ty == light_y && initial_tx > light_x)
        {
            std::cout << "W" << std::endl; //west (left on the x-axis)
            initial_tx--;
        }

        else if (initial_ty > light_y && initial_tx < light_x)
        {
            std::cout << "NE" << std::endl; //northeast (up on the y-axis to the right on the x-axis)
            initial_ty--;
            initial_tx++;
        }


        else if (initial_ty < light_y && initial_tx > light_x)
        {
            std::cout << "SW" << std::endl; //southwest (down the y-axis to the left on the x-axis)
            initial_ty++;
            initial_tx--;
        }

    }
}