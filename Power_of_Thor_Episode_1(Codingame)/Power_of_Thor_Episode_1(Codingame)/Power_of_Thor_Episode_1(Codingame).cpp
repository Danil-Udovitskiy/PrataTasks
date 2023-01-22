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

    // current character position
    int current_X;
    int current_Y;


    //initialize the current position with the starting position of the character
     //further decrease or increase the values until it reaches equality with the data of the endpoint 

    current_X = initial_tx;
    current_Y = initial_ty;



    // game loop
    while (1) {
        int remaining_turns; // The remaining amount of turns Thor can move.
        
        cin >> remaining_turns; cin.ignore();


        if (initial_ty > 17 && initial_tx > 39)
        {
            return 1;
        }


        else if (current_Y < light_y && current_X < light_x) //проверка по высоте, потом по ширине 
        {
            std::cout << "SE" << std::endl; //юго-восток  вниз вправо идем (диагональ по У и Х осям)
            current_Y++;
            current_X++;
        }

        else if (current_Y < light_y && current_X == light_x) // проверка по высоте (ширина одинаковая)
        {
            std::cout << "S" << std::endl;  //юг (вниз на юг только по У оси)
            current_Y++;
        }

        else if (current_Y == light_y && current_X < light_x) // проверка по ширине (высота одинаковая)
        {
            std::cout << "E" << std::endl; //восток (вправо на восток только по Х оси)
            current_X++;
        }

        else if (current_Y > light_y && current_X > light_x)
        {
            std::cout << "NW" << std::endl; //северо-запад (вверх влево по осям У и Х)
            current_Y--;
            current_X--;
        }

        else if (current_Y > light_y && current_X == light_x)
        {
            std::cout << "N" << std::endl; //север (вверх по оси У)
            current_Y--;
        }

        else if (current_Y == light_y && current_X > light_x)
        {
            std::cout << "W" << std::endl; //запад (влево по оси Х)
            current_X--;
        }

        else if (current_Y > light_y && current_X < light_x)
        {
            std::cout << "NE" << std::endl; //северо-восток (вверх по оси У вправо по оси Х)
            current_Y--;
            current_X++;
        }


        else if (current_Y < light_y && current_X > light_x)
        {
            std::cout << "SW" << std::endl; //юго-запад (вниз по оси У влево по оси Х)
            current_Y++;
            current_X--;
        }

    }
}