#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
I am the night. Dark Night! No, not the knight
night
day
*/

int main()
{
	string line;
	getline(cin, line);

	string findWord;
	getline(cin, findWord);

	string replaceWord;
	getline(cin, replaceWord);

	int index = 0;
	int foundIndex = line.find(findWord); // the number of the index where the word is found.

	while (foundIndex != string::npos) /// while foundIndex != of error
	{
		line.replace(foundIndex, findWord.length(), replaceWord); //(pos where to start replacing , length of the replacement , the replace word)
		foundIndex = foundIndex + replaceWord.length(); //we change foundIndex to be after the replacement
		foundIndex = line.find(findWord, foundIndex); //we change foundIndex to equals the new findWord , we are looking for
	}
	cout << line << endl;



	return 0;
}