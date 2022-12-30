// Chapter 16 Task 3.cpp 

//Listing 16.3

#include <iostream> 
#include <string> 
#include <cstdlib> 
#include <ctime> 
#include <cctype> 

//++
#include <vector>
#include <fstream>


int main()
{
	using std::string;

	std::ifstream file("d:\\File\\Hello.txt"); // open file for reading

	//or we can create ifstream object and then open file for reading
	//std::ifstream file;
	//file.open("d:\\File\\Hello.txt");

	std::vector <string> wordlist; 

	if (file.is_open()) // call the is_open() method
	{
		std::cout << "FILE OPEN!\n\n" << std::endl;

		string next; // object to which the words are written in turn

		while (file >> next) //use the >> operator (same as when reading from the console)
		{
			wordlist.push_back(next); //fill vector with data (words) from file
		}

		const int NUM = wordlist.size(); //get size of vector after adding all data(words) from file to it



		using std::cout;
		using std::cin;
		using std::tolower;
		using std::endl;
		std::srand(std::time(0));
		char play;
		std::cout << "Will you play a word game? <y/n> "; // start the word game
		cin >> play;
		play = tolower(play);

		while (play == 'y')
		{
			string target = wordlist[std::rand() % NUM];
			int length = target.length();
			string attempt(length, '-');
			string badchars;
			int guesses = 6;
			std::cout << "Guess my secret word. It has " << length
				<< " letters, and you guess\n"
				<< "one letter at a time. You get " << guesses
				<< " wrong guesses.\n";
			std::cout << "Your word: " << attempt << endl; // word output

			while (guesses > 0 && attempt != target)
			{
				char letter;
				std::cout << "Guess a letter: ";
				cin >> letter;
				if (badchars.find(letter) != string::npos
					|| attempt.find(letter) != string::npos)
				{
					std::cout << "You already guessed that. Try again.\n";
					continue;
				}
				int loc = target.find(letter);
				if (loc == string::npos)
				{
					std::cout << "Oh, bad guess !\n";
					--guesses;
					badchars += letter; // add to string
				}
				else
				{
					std::cout << "Good guess!\n";
					attempt[loc] = letter;
					// Check if the letter appears again
					loc = target.find(letter, loc + 1);
					while (loc != string::npos)
					{
						attempt[loc] = letter;
						loc = target.find(letter, loc + 1);
					}
				}
				std::cout << "Your word: " << attempt << endl;
				if (attempt != target)
				{
					if (badchars.length() > 0)
						std::cout << "Bad choices: " << badchars << endl;
					std::cout << guesses << " bad guesses left\n";
				}
			}
			if (guesses > 0)
				std::cout << "That's right!\n";
			else
				std::cout << "Sorry, the word is " << target << " . \n";
			std::cout << "Will you play another? <y/n> ";
			cin >> play;
			play = tolower(play);
		}
		std::cout << "Bye\n";

	}

	else
	{
		std::cout << "FILE NOT OPEN!\n\n" << std::endl;
		return -1;
	}

	file.close(); // close the file
	return 0;
}