#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	string inp;
	getline(cin, inp);
	istringstream input(inp);

	char c;


	while (input >> c)
	{
		for (size_t i = 0; i < alphabet.length(); i++)
		{
			if (c == alphabet[i])
			{
				alphabet.erase(i, 1); //position , number of the chars , that u want deleted.
			}
		}
	}

	cout << alphabet << endl;


	return 0;
}