#include <iostream>
#include <string>
#include <sstream>
using namespace std;



int main()
{
	string line;
	getline(cin , line);

	istringstream input1(line);

	int bracketCount = 0;
	char c;

	while (input1 >> c)
	{
		switch (c)
		{
		case '(':bracketCount++; break;
		case ')':bracketCount--; break;
		}
	}
	if (bracketCount != 0)
		cout << "incorrect" << endl;
	else if(bracketCount == 0)
		cout << "correct" << endl;

	return 0;
}