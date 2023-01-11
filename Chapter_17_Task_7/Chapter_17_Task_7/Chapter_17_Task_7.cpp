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

    fill_data.write((char*)&len, sizeof(std::size_t)); // save length (size)
    fill_data.write(str.data(), len) << "\n"; // save characters (content)
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

    /*
    // Восстановить содержимое файла
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in | ios_base:: binary);
    if (!fin.is_open())
    {
        cerr << "Could not open file for input. \n";
        //не удается открыть файл для ввода
        exit(EXIT_FAILURE);
    }

    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file:\n";
    // строки, прочитанные из файла
    for_each(vistr.begin(), vistr.end(), ShowStr);*/

    return 0;
}
