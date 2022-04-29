#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	string line;
	getline(cin, line);

	string numsTogether = "";
	char c = ' ';

	while (c != '.')
	{
		for (int i = 0; i < line.length(); i++)
		{
			c = line[i];
			if (c >= '0' && c <= '9')
			{
				numsTogether += c;
			}
		}
	}
	int var = stoi(numsTogether);

	double result = sqrt(var);
	cout << result << endl;


	return 0;
}