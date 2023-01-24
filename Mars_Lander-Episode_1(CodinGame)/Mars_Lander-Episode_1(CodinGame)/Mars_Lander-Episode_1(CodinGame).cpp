// Mars_Lander-Episode_1(CodinGame).cpp 

#include <iostream>
#include <string>

using namespace std;


int main()
{
    int surface_n; // the number of points used to draw the surface of Mars.
    cin >> surface_n; cin.ignore();
    for (int i = 0; i < surface_n; i++)
    {
        int land_x; // X coordinate of a surface point. (0 to 6999)
        int land_y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> land_x >> land_y; cin.ignore();
    }

    // game loop
    while (1)
    {
        int x;
        int y; // height
        int h_speed; // the horizontal speed (in m/s), can be negative.
        int v_speed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> x >> y >> h_speed >> v_speed >> fuel >> rotate >> power; cin.ignore();


        // 2 integers: rotate power. rotate is the desired rotation angle (should be 0 for level 1), power is the desired thrust power (0 to 4).

        if (v_speed > -40)// landing speed cannot be more than 40 meters per second (we limit the maximum speed)
        // minimum speed during landing can be limited to 18 m/s for the smoothest possible docking with the surface if (v_speed > -18), but in this case more fuel will be used
        {
            //up to speed -40 the engine is off (landing occurs due to natural fall)
            std::string power_engine = " 0";
            cout << rotate << power_engine << endl; //display the angle and power of the engine
        }
        else
        {
            // at speeds of 40 or more, the motor runs at full power to compensate for inertia
            std::string power_engine = " 4";
            cout << rotate << power_engine << endl; //display the angle and power of the engine
        }

    }
}
