#include "Range.h"
#include <cassert>
#include <cstring>

Range::Range() :
	rangeFirst(0),
	rangeLength(0),
	valueCounts(nullptr)
{}

Range::~Range() {
	clear();
}


size_t Range::getCount(T value) const {
	size_t rc = 0;
	if ((rangeFirst <= value) && (value < (rangeFirst + rangeLength))) {
		size_t ind = value - rangeFirst;
		rc = valueCounts[ind];
	}
	return rc;
}

void Range::clear() {
	if (valueCounts) {
		delete[] valueCounts;
		rangeFirst = 0;
		rangeLength = 0;
		valueCounts = nullptr;

	}
}

void Range::resize(T first , T size) {
	size_t* new_array = new size_t[size]{};
	if (valueCounts) {
		std::memcpy(new_array + (rangeFirst - first), valueCounts, sizeof(std::size_t) * rangeLength);
		clear();
	}
	rangeFirst = first;
	rangeLength = size;
	valueCounts = new_array;

}

bool Range::empty() const {
	return nullptr == valueCounts;

}

Range::Range(const Range& other) :
        rangeFirst(other.rangeFirst) ,
	    rangeLength(other.rangeLength)
{
	if (!other.empty()) {
		valueCounts = copyValues(other);
	}
	else
	{
		valueCounts = nullptr;
	}
}

Range& Range::operator=(const Range& other) {
	if (&other != this) {
		clear();
		rangeFirst = other.rangeFirst;
		rangeLength = other.rangeLength;
		valueCounts = copyValues(other);
	}
	return *this;
}

void Range::add(T value) {
	if (empty()) {
		resize(value, 1);
	}
	else if(rangeFirst > value)
	{
		resize(value, rangeLength + rangeFirst - value);
	}
	else if ((rangeFirst + rangeLength) <= value) {
		resize(rangeFirst, value - rangeFirst + 1);
	}
	size_t ind = value - rangeFirst;
	++valueCounts[ind];
}