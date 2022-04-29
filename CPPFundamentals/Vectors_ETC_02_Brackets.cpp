#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int curvedCounter = 0;
int squareCounter = 0;
int curlyCounter = 0;
int index = 0;
char buff = ' ';
string line;

bool isBracketAllowed(char c)
{
	while (index < line.size())
	{
		if (c == '{')
		{
			if (index == 0)
			{
				curlyCounter++;
				return true;
			}
			if (buff == '[' || buff == '(')
			{
				return false;
			}
			else
			{
				curlyCounter++;
				return true;
			}
		}
		if (c == '[')
		{
			if (index == 0)
			{
				squareCounter++;
				return true;
			}
			if (buff == '(' )
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		if (c == '(')
		{
			if (index == 0)
			{
				curvedCounter++;
				return true;
			}
			if (buff == '(')
			{
				return false;
			}
			else
			{
				return true;
			}
		}

		/////ClosingBrackets

		if (c == '}')
		{
			if (index == 0)
			{
				curlyCounter--;
				return false;
			}
			if (buff == '(' || buff == '[')
			{
				return false;
			}
			else
			{
				curlyCounter--;
				return true;
			}
		}
		if (c == ']')
		{
			if (index == 0)
			{
				squareCounter--;
				return false;
			}
			if (buff == '(' || buff == '{' || buff == '}')
			{
				return false;
			}
			else
			{
				squareCounter--;
				return true;
			}
		}
		if (c == ')')
		{
			if (index == 0)
			{
				curvedCounter--;
				return false;
			}
			if (buff != '(')
			{
				return false;
			}
			else
			{
				curvedCounter--;
				return true;
			}
		}

		if (curvedCounter == 0 && curlyCounter == 0 && squareCounter == 0)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
}

bool isItCorrect(istringstream& input1)
{
	char c;
	while (input1 >> c)
	{
		switch (c)
		{
		    case '(':
		    case '{':
		    case '[':
			if (isBracketAllowed(c) == false)
			{
				return false;
		    }
			break;

		    case ')':
		    case '}':
		    case ']':
			if (isBracketAllowed(c) == false)
			{
				return false;
			}
			break;

		    default:return false;
		}
		buff = c;
		index++;
	}
	return true;
}

int main()
{
	getline(cin, line);

	istringstream input1(line);

	cout << (isItCorrect(input1) ? "valid" : "invalid" )<< endl;

	return 0;
}