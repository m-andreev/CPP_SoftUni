#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"
#include <vector>

// Place your code here

void removeInvalid(std::list<Company*> & companies) {

	std::list<Company*>::iterator it = companies.begin() ;

	while ( it != companies.end() )
	{
		Company* cur = *it; /// current company "cur" = "*(it)"
		if (cur->getId() < 0)
		{
			it = companies.erase(it);
			delete cur;
		}
		else
		{
			it++;
		}

	}
}

#endif // !REMOVE_INVALID_H
