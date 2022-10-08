
/*
#ifndef JOIN_H
#define JOIN_H


#include <vector>
#include <string>

template<typename T2>
std::string join(std::vector<T2> numbers, std::string joinStr)
{
	std::string resStr;
	//std::vector<T2>::iterator itS = numbers.rbegin();
	auto itS = numbers.rbegin();
	for (itS = numbers.rbegin(); itS != numbers.rend(); itS++)
	{
		T2 curPiece =  *itS;
		resStr += curPiece;
		if (itS != numbers.end() - 1)
		{
			resStr += joinStr;
		}
	}

	return resStr;
}

#endif //!JOIN_H
*/

#ifndef JOIN_H
#define JOIN_H

#include <string>
#include <vector>
#include <sstream>

template<typename T>
std::string join(std::vector<T> items, std::string joinStr) {
	std::ostringstream out;
	for (size_t i = 0; i < items.size(); i++) {
		out << items[i];
		if (i < items.size() - 1) {
			out << joinStr;
		}
	}

	return out.str();
}

#endif // !JOIN_H
