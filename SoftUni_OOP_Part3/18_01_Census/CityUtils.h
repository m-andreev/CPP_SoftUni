#ifndef CITY_UTILS_H
#define CITY_UTILS_H

#include "City.h"

#include <iostream>
#include <vector>
#include <map>

const City* initCity(std::string name, size_t population)  {
	const City* obj;

	City* city = new City(name, population);

	return city;
}

std::map<size_t , const City* > groupByPopulation(std::vector<const City*> & cities, size_t & totalPopulation) {

	std::map<size_t, const City* > citiesByPopulation;
	totalPopulation = 0;

	for (auto city : cities) {
		totalPopulation += city->getPopulation();
		citiesByPopulation[city->getPopulation()] = city;

	}

	return citiesByPopulation;
}

#endif //!CITY_UTILS_H