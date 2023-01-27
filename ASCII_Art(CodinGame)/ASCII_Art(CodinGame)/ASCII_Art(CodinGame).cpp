// ASCII_Art(CodinGame).cpp

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
	int l;
	cin >> l; cin.ignore();
	int h;
	cin >> h; cin.ignore();
	string t;
	getline(cin, t);

	for (int i = 0; i < h; i++)
	{
		string row;
		getline(cin, row);

		for (int j = 0; j < t.size(); ++j)
		{
			char x = t[j]; // read the contents of the string into a char variable character by character
			int index = 0;

			//should be converted to uppercase on output
			if (isalpha(x)) // if the character is in the range A-Z (65 - 90) / a-z
				//isalpha returns true /false
			{
				index = ((toupper(x) - 65) * l); // convert to uppercase then subtract the initial character of the ASCII alphabet (code 65) - 'A'
			}
			else
			{
				//if the character is out of range, then display the sign - ? (last character of input text)
				// ###
				//   #
				//  ##
				//
				//  #
				// ASCII range 65 - 90 includes 26 values
				//accordingly, the alternative character will be placed after the letter block
				index = (26 * l);
			}

			//return the substring contained in - ( row )  from position index to position - ( l ) (i.e. 4 elements following index)
			cout << row.substr(index, l);
		}
		cout << endl;
	}
}