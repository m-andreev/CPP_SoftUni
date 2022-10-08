#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"
#include <memory>
#include <utility>
#include <string>
#include <vector>

// Place your code here

std::shared_ptr<Company> makeCompany(std::vector<std::string> & properties)
{
	int id = std::stoi(properties[0]);
	std::string name = properties[1];
	std::vector<std::pair<char, char> > employees;

	for (int idx = 2; idx < properties.size(); idx++)
	{
		std::pair<char, char> thePair( ((char)properties[idx][0]), ((char)properties[idx][1]) );
		employees.push_back(thePair);
	}

	return std::shared_ptr<Company>(new Company(id, name, employees));
}

#endif // !MAKE_COMPANY_H
