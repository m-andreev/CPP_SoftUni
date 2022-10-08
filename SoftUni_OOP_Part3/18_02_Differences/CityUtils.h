#ifndef CITYUTILS_H
#define CITYUTILS_H

#include "Includes.h"
#include <iostream>

std::istream& operator >>(std::istream& istr, City& c) {
	unsigned int censusYear;
	std::string name;
	size_t population;

	//std::cin >> name >> population >> censusYear;
	istr >> name>> population >> censusYear;

	c = City(censusYear, name, population);

	return istr;
}



	

#endif //!CITYUTILS_H
