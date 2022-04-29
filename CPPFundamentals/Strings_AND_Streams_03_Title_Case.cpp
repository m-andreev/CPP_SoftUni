#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string line;
	getline(cin, line);

	istringstream input1(line);
	ostringstream output;

	char c;
	int flag = 1;
	
	int index = 0;
	
	while (index < line.length())
	{
		char c = line[index];
		index++;
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		{
			if (flag)
			{
				if (c >= 'a' && c <= 'z')
				{
					c = c - 32;
				}
				flag = 0;
			}
		}
		else
		{
			flag = 1;
		}
	    output << c ;
	}
	cout << output.str() << endl;

	return 0;
}