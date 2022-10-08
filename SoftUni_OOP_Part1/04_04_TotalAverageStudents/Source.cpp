#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <list>
using namespace std;

class Student {
	string name;
	string surname;
	double totalAverage;

public:

	void read(istream& istr);

	void print(ostream& ostr);

	double getTotalAverage();
};

void Student::read(istream & istr)
{
	istr >> name >> surname >> totalAverage;
}


void Student::print(ostream & ostr)
{
	ostr << name << " " << surname <<" "<< totalAverage<<endl;

}

double Student::getTotalAverage() 
{
	return totalAverage;
}

int main()
{
	int studentsNum; cin >> studentsNum;
	if (studentsNum <= 0)
	{
		cout << "Invalid input" << endl;
		return 0;
	}

	vector<Student> students;
	students.resize(studentsNum);

	for (size_t i = 0; i < studentsNum; i++)
	{
		students[i].read(cin);
	}
	
	double grandTotalAverage = 0;

	for (size_t i = 0; i < studentsNum; i++)
	{
		students[i].print(cout);
		grandTotalAverage += students[i].getTotalAverage();
	}

	cout << grandTotalAverage / studentsNum<<endl;

	return 0;
}
