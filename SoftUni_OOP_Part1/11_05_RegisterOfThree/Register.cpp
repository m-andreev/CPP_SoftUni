#include "Register.h"


Register::Register(size_t numCompanies) : numAdded(0) , companiesArray(new Company[numCompanies]) {}

void Register::add(const Company& c)
{
	companiesArray[numAdded] = c;
	numAdded++;

}

Register::~Register() {
	delete[] companiesArray;
}

Company Register::get(int companyId) const {
	size_t cur = 0;
	for (; cur < numAdded; cur++)
	{
		if (companiesArray[cur].getId() == companyId)
		{
			return companiesArray[cur];
		}
		return Company(-1, "invalid");
	}
}

Register& Register::operator=(const Register& other) {
	Company* newC = new Company[other.numAdded];
	size_t idx = 0;
	for (; idx < other.numAdded; idx++) {
		newC[idx] = other.companiesArray[idx];
	}

	delete[] companiesArray;
	companiesArray = newC;
	numAdded = other.numAdded;

	return *this;
}


Register::Register(const Register& other) {
	Company* newC = new Company[other.numAdded];
	size_t idx = 0;
	for (; idx < other.numAdded; idx++) {
		newC[idx] = other.companiesArray[idx];
	}

	///delete[] companiesArray; TUK IMAME DESTRUKTOR , ZA RAZLIKA OT OPERATORA
	companiesArray = newC;
	numAdded = other.numAdded;
}