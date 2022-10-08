/*
#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <sstream>
#include <string>


bool tryParse(std::string str, int & num)
{
	std::istringstream istr(str);
	char c;
	//int number = 0;
	int counter = 0;
	bool parseSuccess = false;
	while (istr >> c)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		{
			return parseSuccess;
		}
		else if (c >= '0' && c <= '9')
		{
			if (counter == 0)
			{
				parseSuccess = true;
				num = ((int)(c) - 48);
				counter++;
			}
			else
			{
				parseSuccess = true;
				num = num * 10 + ((int)(c)-48);
				counter++;
			}
		}
	}
	return parseSuccess;
}
*/

#ifndef TRY_PARSE_H
#define TRY_PARSE_H

#include <string>
#include <sstream>

bool tryParse(std::string s, int& result) {
	std::istringstream sIn(s);

	int parsed;
	bool parseSuccess = (bool)(sIn >> parsed);

	result = parsed;

	return parseSuccess;
}

#endif // TRY_PARSE_H