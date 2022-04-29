#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

int main()
{
	string line;
	getline(cin, line);

	istringstream input1(line);
	string piece;

	int index = 0;
	int maxNumber = INT_MIN;

	while (input1 >> piece)
	{
		string numb = "";
		int num = 0;
		for (index = 0; index < piece.length(); index++)
		{
			char c = piece[index];
			if (c >= '0' && c <= '9')
			{
				numb += c;
			}
		}
		index = 0;
		num = stoi(numb);
		if (num >= maxNumber)
			maxNumber = num;
	}
	cout << maxNumber << endl;

	return 0;
}