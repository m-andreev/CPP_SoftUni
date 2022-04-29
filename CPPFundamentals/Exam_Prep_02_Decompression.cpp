#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int main()
{
	string inp;
	getline(cin, inp);

	istringstream stream1(inp);
	ostringstream ostream1;

	char c;
	int multiplier = 0;

	while (stream1 >> c)
	{
			if (c >= '0' && c <= '9')
			{
				int number = c - '0';

				multiplier *= 10;
				multiplier += number;
			}
			else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			{
			    if(multiplier != 0)
				{
				   string variable;
				   for(int i=0; i <multiplier;i++)
				   {
				       variable = variable + c;
				       
				   }
				   ostream1 << variable;
				   multiplier = 0;
				}
				else
				{
				    ostream1<<c;
				}
			}
	}
	
	cout << ostream1.str() << endl;

	return 0;
}