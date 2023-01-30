// Text_formatting(CodinGame).cpp 

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	string intext;
	getline(cin, intext);

	cerr << intext << "\n"; //input data display

	// Capitalize the first letter
	intext[0] = toupper(intext[0]);


	for (int i = 0; i < intext.size(); i++)
	{
		//add space after comma only if missing
		if (intext[i] == ',' && intext[i + 1] != ' ')
		{
			intext.insert(i + 1, std::string(" "));
		}

		// Capitalize the letter after the dot and add a space after the dot
		//and add a space after the dot only if it's missing
		//also add a space if point is not the last index
		else if (intext[i] == '.' && i != intext.size() - 1 && intext[i + 1] != ' ')
		{
			intext[i + 1] = toupper(intext[i + 1]);
			intext.insert(i + 1, std::string(" "));
		}

		//remove duplicate space
		else if (intext[i] == ' ' && intext[i + 1] == ' ')
		{
			intext.erase(i + 1, 1);
		}


		//capital letter after dot and space
		else if (intext[i] == '.' && i != intext.size() - 1 && intext[i + 1] == ' ')
		{

			intext[i + 2] = toupper(intext[i + 2]);
			intext.erase(i - 1, 1);
		}

		//remove space before comma
		else if (intext[i] == ',' && intext[i - 1] == ' ')
		{
			intext.erase(i - 1, 1);

		}
		//remove space before dot
		else if (intext[i] == '.' && intext[i - 1] == ' ')
		{
			intext.erase(i - 1, 1);
		}


	}

	cout << intext << endl; //formatted text output

}

