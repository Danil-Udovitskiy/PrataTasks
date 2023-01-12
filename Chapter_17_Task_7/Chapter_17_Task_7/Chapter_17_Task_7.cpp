// Chapter_17_Task_7.cpp 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>


void ShowStr(const std::string& str)
{
    std::cout << str << "\n";
}


class Store //functor class defines operator()()
{
private:
    //const or reference data member cause implicit copy assignment operator to be deleted
    std::ofstream& fill_data;

public:
    Store(std::ofstream& fout) : fill_data(fout) {}; //indicates an ifstream object
    void operator()(const std::string& str); //indicates the string to be written
};

void Store::operator()(const std::string& str)
{
    //write down the size of the string first, and then its content
    int len = str.size(); //size

    fill_data.write((char*)&len, sizeof(int)); // save length (size)
    fill_data.write(str.data(), len); // save characters (content)
}


//ifstream and vector string
void GetStrs(std::ifstream& str, std::vector<std::string>& vistr)
{
    int len;

    while (str.read((char*)&len, sizeof(int))) // save length (size)
    {
        std::string temp;
        for (int i = 0; i < len; i++)
        {
            char ch_temp;
            str.read((char*)&ch_temp, sizeof(char)); //read character via read using temporary variable char

            temp.push_back(ch_temp); //write character to string temp
        }
        
        vistr.push_back(temp); // put the read line into a vector
    }
}



int main()
{
    using namespace std;
    vector<string> vostr;
    string temp;

    // Get strings 
    cout << "Enter strings (empty line to quit) :\n"; // request for string input
    while (std::getline(std::cin, temp) && temp[0] != '\0')
        vostr.push_back(temp);

    cout << "Here is your input. \n"; // output of entered strings 
    for_each(vostr.begin(), vostr.end(), ShowStr);



    
    // Save to file
    ofstream fout("strings.dat.txt", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store (fout));
    fout.close();

    
    // Restore the contents of the file
    vector<string> vistr;
    ifstream fin("strings.dat.txt", ios_base::in | ios_base:: binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input. \n";
        //can't open file for input
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    // lines read from the file
    for_each(vistr.begin(), vistr.end(), ShowStr);

    return 0;
}
