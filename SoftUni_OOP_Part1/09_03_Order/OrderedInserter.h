#ifndef ORDERED_INSERTER_H
#define ORDERED_INSERTER_H

#include "Company.h"
#include <vector>

class OrderedInserter {
	std::vector<const Company*>& vec;
public:
	OrderedInserter(std::vector<const Company*>& vect) : vec(vect) {}

	void insert(const Company* c)
	{
		auto insertIterator = vec.begin();
		while (insertIterator != vec.end() && c->getId() > (*insertIterator)->getId()) {
			insertIterator++;
		}
		vec.insert(insertIterator, c);
	}

};


#endif //!ORDERED_INSERTER_H
