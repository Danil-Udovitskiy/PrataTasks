// Chapter_17_Task_7.cpp 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


void ShowStr(const std::string& str)
{
    std::cout << str << "\n";
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



    /*
    // Сохранить в файле
    ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();


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
