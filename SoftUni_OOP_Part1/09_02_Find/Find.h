#ifndef FIND_H
#define FIND_H

#include "Company.h"
#include <vector>


Company* find(std::vector<Company*>  companies, int searchId)
{
	for (Company* companyPtr : companies)
	{
		if (companyPtr->getId() == searchId)
		{
			return companyPtr;
		}
	}
	return nullptr;
}


#endif //!FIND_H