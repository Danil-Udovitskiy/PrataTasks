// Chapter_17_Task_5.cpp 


#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>


int main()
{
    //three text files for input 
    std::string first = "mat.dat.txt";
    std::string second = "pat.dat.txt";
    std::string third = "matnpat.dat.txt";

    //create 2 of 2D char arrays to fill with data
    const char mat_names[3][10] = { "Alex", "Lolo", "Dan" };
    const char pat_names[3][10] = { "Alex", "Gigi", "Dann"};


    std::ofstream fout1; //create an ofstream object
    fout1.open(first, std::ios_base::out);//open with file mode iosbase::out (open file for writing)

    std::ofstream fout2; //create an ofstream object
    fout2.open(second, std::ios_base::out);

    // check for successful creation and opening of files
    if (fout1.is_open() && fout2.is_open())
    {
        std::cout << "FILE OPEN   " << first << "\n";
        std::cout << "FILE OPEN   " << second << "\n";


        //fill files with array data using the write method
        for (int i = 0; i < 3; i++)
            fout1.write((char*)mat_names[i], sizeof (mat_names[i]));
        for (int i = 0; i < 3; i++)
            fout2.write((char*)pat_names[i], sizeof (pat_names[i]));
    }

	fout1.close();
	fout2.close();



    std::ifstream fin1; //create an ifstream object
    fin1.open(first, std::ios_base::in); //open with file mode iosbase::in (open file for reading)

    std::ifstream fin2; //create an ifstream object
    fin2.open(second, std::ios_base::in); //open with file mode iosbase::in (open file for reading)

    //check if the two files were opened successfully
    if (!fin1.is_open())
    {
        std::cerr << "FILE NOT OPEN   " << first << "\nSTOP\n";
        return 1;
    }

    if (!fin1.is_open())
    {
        std::cerr << "FILE NOT OPEN   " << second << "\nSTOP\n";
        return 1;
    }


   

}