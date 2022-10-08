#ifndef CITYDIFF_H
#define CITYDIFF_H

#include "Includes.h"
#include "City.h"

#include <iostream>
#include <string>


class CityDiff {
	City city1;
	City city2;
public:
	CityDiff(const City& city1_, const City& city2_) : city1(city1_), city2(city2_) {}

	friend std::ostream& operator<<(std::ostream& ostr, const CityDiff& cityDiff) {

		//ostr << cityDiff.city1.getName() << " - " << cityDiff.city2.getName() << std::endl;
		if (cityDiff.city1.getName() == cityDiff.city2.getName())
		{
			cityDiff.printSameCityDiff(ostr);
		}
		else
		{
			cityDiff.printCityDiff(ostr);
		}
		
		return ostr;

		/*
		Sofia (2018 vs. 2011)
        population: +708409
        Gabrovo (2015) vs. NewYork (2013)
        population: -8495455
		*/
	}

	void printSameCityDiff(std::ostream& ostr) const {
		ostr << city1.getName() << " (" << city1.getCensusYear() << " vs. " << city2.getCensusYear() << ")" << std::endl;
		int diff = city1.getPopulation() - city2.getPopulation();
		if(diff>=0)
		ostr << "population: " <<"+"<< (int)city1.getPopulation() - (int)city2.getPopulation() << std::endl;
		else
		ostr << "population: "  << (int)city1.getPopulation() - (int)city2.getPopulation() << std::endl;
	}
	void printCityDiff(std::ostream& ostr) const {
		ostr << city1.getName() << " (" << city1.getCensusYear() << ")" << " vs. " << city2.getName() << " (" << city2.getCensusYear() << ")" << std::endl;
		int diff = city1.getPopulation() - city2.getPopulation();
		if (diff >= 0)
			ostr << "population: " << "+" << (int)city1.getPopulation() - (int)city2.getPopulation() << std::endl;
		else
			ostr << "population: "  << (int)city1.getPopulation() - (int)city2.getPopulation() << std::endl;
	}
};

CityDiff operator-(const City& city1, const City& city2) {
	CityDiff obj1(city1, city2);
	return obj1;
}



#endif //!CITYDIFF_H
