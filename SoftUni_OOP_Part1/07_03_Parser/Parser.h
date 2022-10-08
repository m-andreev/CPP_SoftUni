#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <sstream>
#include <istream>
#include <string>
using namespace std;

template<typename T >
class Parser {
	istream& in;
	string stop;
public:
	Parser(std::istream& in_, std::string stopLine)
		: in(in_), stop(stopLine) {}

	bool readNext(T& next) {
		std::string line;
		std::getline(this->in, line);

		if (line != this->stop) {
			std::istringstream lineIn(line);
			lineIn >> next;
			return true;
		}
		else {
			return false;
		}
	}


};


#endif //!PARSER_H

