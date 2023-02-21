// Task_map.cpp 

#include <iostream>
#include <map>
#include <string>

void showMenu();


int main()
{
    std::map<std::string, int>goods;

    showMenu();

    bool work = true;

    while (work)
    {

        showMenu();

        int choice;
        std::cout << "\nEnter your operation:\n";
        std::cin >> choice;

        system("cls");

        switch (choice)
        {
        case 1:
        {
            std::string name;
            int price;

            std::cout << "Enter name : ";
            std::cin >> name;
            std::cout << "Enter price : ";
            std::cin >> price;

            goods.emplace(name, price);

            system("cls");
            break;
        }
        case 2:
        {
            std::string name;
            std::cout << "Enter name to delete : ";
            std::cin >> name;

            goods.erase(name);
            system("cls");
            break;
        }
        case 3:
        {
            if (goods.empty())
            {
                std::cout << "Its no goods.\n";
            }
            else
            {
                for (auto i = goods.begin(); i != goods.end(); i++)
                {
                    std::cout << i->first << " " << i->second << "\n";
                }
                std::cout << "\n";
            }
            break;
        }
        case 4:
        {
            std::string name;
            std::cout << "Enter name to find : ";
            std::cin >> name;

            auto it = goods.find(name);
            if (it != goods.end())
            {
                std::cout << it->first << "\n";
                std::cout << it->second << "\n";
            }
            else
            {
                std::cout << "No good with this name\n\n";
            }
            break;
        }
        case 5:
        {
            work = false;
            break;
        }
        default:
        {
            std::cout << "Error choice\nPress enter to continue\n";
            std::cin.ignore(INT_MAX, '\n');
            break;
        }
        }

    }
}

void showMenu()
{
    std::cout << "Press 1 to ADD good\n";
    std::cout << "Press 2 to DELETE good\n";
    std::cout << "Press 3 to SHOW ALL goods\n";
    std::cout << "Press 4 to FIND good\n";
    std::cout << "Press 5 to EXIT\n";
}