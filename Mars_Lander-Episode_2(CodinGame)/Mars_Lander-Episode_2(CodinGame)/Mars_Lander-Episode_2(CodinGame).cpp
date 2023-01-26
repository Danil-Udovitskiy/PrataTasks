// Mars_Lander-Episode_2(CodinGame).cpp 
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


        std::string power_engine;

        if (v_speed > -40 && h_speed < 16)// vertical landing speed is limited to 40 meters per second
        //if the horizontal speed is less than 16 meters per second, then we change the angle to move to the allowed plane for landing
        {
            power_engine = " 3";
            rotate = -20;
            cout << rotate << power_engine << endl;
        }
        else
        {
            power_engine = " 4";
            rotate = 0;
            cout << rotate << power_engine << endl;
        }

        //if the horizontal speed is greater than the maximum allowable (20), then change the angle in the opposite direction 
        if (h_speed > 20)
        {

            rotate = 50;

            if (y < 1400) //if the height is less than 1400, then align the ship
            {
                rotate = 0;
            }
            cout << rotate << power_engine << endl;
        }
        else //if the horizontal speed is less than 20 meters per second - no change
        {

            cout << rotate << power_engine << endl; //display the angle and power of the engine
        }

    }
}