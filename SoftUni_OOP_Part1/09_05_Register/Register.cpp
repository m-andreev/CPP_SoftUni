#include "Register.h"

Register::Register(size_t numCompanies) : companiesArray(new Company[numCompanies]), numAdded(0) {} ////konstruktor

void Register::add(const Company& c) {
	this->companiesArray[this->numAdded] = c; /// dobavqme nova kompaniq
	this->numAdded++; /// uvelichavame broikata na kompaniite (v klasa)
}

Company Register::get(int companyId) const {
	for (size_t i = 0; i < this->numAdded; i++) ////obhojdame vektora s novodobavenite kompanii  
	{
		if (this->companiesArray[i].getId() == companyId) //// ako tekushtoto ID na kompaniq ot vektora e == na novoto za proverka "companyID" ...
		{
			return this->companiesArray[i]; /// vryshtame kompaniqta (obektyt ot vektora)
		}
	}

	// NOTE: this code should never be reached if the input is correct
	return Company();
}

Register::~Register() {              ///destruktor
	delete[] this->companiesArray;
}