#ifndef ARRAY_OF_POINTERS_H
#define ARRAY_OF_POINTERS_H

#include <vector>
#include <memory>
#include "Company.h"

class ArrayOfPointers {
	std::vector<std::shared_ptr<Company> > pointers;
public:
	void add(Company* c)
	{
		this->pointers.push_back(std::shared_ptr<Company>(c));
	}

	size_t getSize()
	{
		return this->pointers.size();
	}

	Company* get(size_t index) const
	{
		return this->pointers.at(index).get();
	}
};


#endif //!ARRAY_OF_POINTERS_H