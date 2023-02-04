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
	//intext[0] = toupper(intext[0]);


	bool isLower = true;

	for (int i = 0; i < intext.size(); i++)
	{
		//add space after comma only if missing
		if (intext[i] == ',' && intext[i + 1] != ' ' && intext[i + 2] != ' ') //++&& intext[i + 2] != ' '
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
			isLower = true;
			//break;
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

		//all letters are lowercase except for 1 character and except character after dot + space(a. A)
		if (isLower == true && isalpha(intext[i]))
		{
			intext[i] = toupper(intext[i]); 
			isLower = false;
		}

		//to lower case
		else
		{
			intext[i] = tolower(intext[i]);
		}

		//to uppercase after a dot with a space
		if (intext[i] == '.' && intext[i + 1] == ' ')
		{
			intext[i + 2] = toupper(intext[i + 2]);
			isLower = true;
		}
		


		//Doesnt work
		//++++
		//remove duplicate coma
		//if (intext[i] == ',' && intext[i + 1] == ',') // || intext[i] == ',' && intext[i + 2] == ','
		//{
		//	intext.erase(i + 1, 1);
		//}
		////remove duplicate dot
		//else if (intext[i] == '.' && intext[i + 1] == '.') // || intext[i] == '.' && intext[i + 2] == '.'
		//{
		//	intext.erase(i + 1, 1);
		//}
		////remove duplicate space
		//else if (intext[i] == ' ' && intext[i + 1] == ' ')
		//{
		//	intext.erase(i + 1, 1);
		//}

	}


	cout << intext << endl; //formatted text output

}