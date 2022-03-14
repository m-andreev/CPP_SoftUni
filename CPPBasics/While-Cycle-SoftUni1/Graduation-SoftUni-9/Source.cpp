#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
	string student;
	getline(cin >> ws, student);

	int grades = 1; //// Pishem go predi da vyvedem che counter = 1
	double totalGradesSum = 0.0;
	double average = 0.0;
	int fail = 0;

	while (grades <= 12)
	{
		double grade;
		cin >> grade;

		if (grade >= 4.00)
		{
			totalGradesSum += grade;
			grades++;
		}
		else
		{
			fail++;
		}

		if (fail >= 2)
		{
			cout << student << " has been excluded at " << grades<< " grade"<<endl;
			break;
		}
	}
	average = totalGradesSum / 12 ;

	if (grades >= 12)
	{
		cout << setprecision(2) << fixed << student << " graduated.Average grade : " << average << endl;
	}
}