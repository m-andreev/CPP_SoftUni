#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"
#include <sstream>
#include <string>
#include <vector>
#include<set>
#include <vector>

// Place your code here

Company* parseUniqueCompanies(const std::string& input, int & numCompanies, std::string(&unique_func)(const Company&))
{
	std::vector<Company> companies;
	std::set<std::string> uniqueId;

	std::istringstream istr(input);
	

	

	while (true)
	{
		std::string compLine;

		std::getline(istr, compLine);

		if (!(bool)istr)
		{
			break;
		}

		std::istringstream line(compLine);

		

		int id;
		std::string name;

		line >> id >> name;

		Company curC(id, name);
		
		std::string idUnique = unique_func(curC);

		if (uniqueId.find(idUnique) != uniqueId.end())
			continue;

		uniqueId.insert(idUnique);

		companies.push_back(curC);
       
	
	}

	Company* retComp = new Company[companies.size()];

	numCompanies = 0;

	
	for (;numCompanies < companies.size(); numCompanies++)
		retComp[numCompanies] = companies[numCompanies];

	return retComp;
}

#endif // !PARSE_COMPANIES_H