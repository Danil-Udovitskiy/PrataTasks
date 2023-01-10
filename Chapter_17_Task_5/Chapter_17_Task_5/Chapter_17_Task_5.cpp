// Chapter_17_Task_5.cpp 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <fstream>

int main()
{
    //two text files for input
    std::string first = "mat.dat.txt";
    std::string second = "pat.dat.txt";
    
    //text file for output
    std::string third = "matnpat.dat.txt";

 
    //open files
    std::ifstream fin; //create an ifstream object
    fin.open(first);

    std::ifstream fin2; //create an ifstream object
    fin2.open(second);

    std::ofstream fout; //create an ifstream object
    fout.open(third);

    if (fin.is_open() && fin2.is_open() && fout.is_open())
    {
        std::cout << "FILE OPEN   " << first << "\n";
        std::cout << "FILE OPEN   " << second << "\n";
        std::cout << "FILE OPEN   " << third << "\n";


        //First container 
        std::vector <std::string> Mat;

        std::string name;

        //Input
        while (fin >> name && !fin.eof())
        {
            Mat.push_back(name);
        }

        //Sort
        sort(Mat.begin(), Mat.end());


        //Second container 
        std::vector<std::string> Pat;

        //Input
        while (fin2 >> name && !fin2.eof())
        {
            Pat.push_back(name);
        }

        //Sort
        sort(Pat.begin(), Pat.end());


        //Create a third container that combines these two lists, excludes
        //duplicatesand displays the contents of this container.
        //std::set_union doing it

        std::vector<std::string> Names;

        Names.resize(Mat.size() + Pat.size());
        std::set_union(Mat.begin(), Mat.end(), Pat.begin(), Pat.end(), Names.begin());

        //Output
        for (int i = 0; i < Names.size(); i++)
        {
            fout << Names.at(i) << "\n";
        }
    }


    // check if the 1 file to be copied from is open
    else if (!fin.is_open())
    {
        std::cerr << "FILE NOT OPEN   " << first << "\nSTOP\n";
        return 1;
    }
    // check if the 2 file to be copied from is open
    else if (!fin2.is_open())
    {
        std::cerr << "FILE NOT OPEN   " << second << "\nSTOP\n";
        return 1;
    }
    // check if the 3 file to be copied to is open
    else if (!fout.is_open())
    {
        std::cerr << "FILE NOT OPEN   " << third << "\nSTOP\n";
        return 1;
    }

    fin.close();
    fin2.close();
    fout.close();
}