/*
#ifndef SPLIT_H
#define SPLIT_H

#include <sstream>
#include <vector>
#include <string>

template<typename T1>
T1 parse(std::string s) {
	std::istringstream sIn(s);
	T1 t;
	sIn >> t;

	return t;
}

template<typename T1>
std::vector<T1> split(std::string line, char separator)
{
	std::istringstream istr(line);
	std::string curStr;

	std::vector<T1> vec;

	char sep = separator;
	char cur;
	
	while (istr >> cur)
	{
		if (cur == sep)
			vec.push_back(parse<T1>(curStr));

		curStr += cur;
	}

	return vec;
}

#endif //!SPLIT_H
*/

#ifndef SPLIT_H
#define SPLIT_H

#include <vector>
#include <string>
#include <sstream>

template<typename T>
T parse(std::string s) {
	std::istringstream sIn(s);
	T t;
	sIn >> t;

	return t;
}

template<typename T>
std::vector<T> split(std::string s, char separator) {
	std::istringstream sIn(s);
	std::string itemStr;

	std::vector<T> items;
	while (std::getline(sIn, itemStr, separator)) {
		items.push_back(parse<T>(itemStr));
	}

	return items;
}

#endif // !SPLIT_H