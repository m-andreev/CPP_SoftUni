#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int numGroups;
	cin >> numGroups;

	int allClimbers = 0;
	int groupOfClimbers;

	int musalaClimbers = 0;
	int monBlanClimbers = 0;
	int kilimanjaroClimbers = 0;
	int k2Climbers = 0;
	int everestClimbers = 0;

	for (size_t i = 1; i <= numGroups; i++)
	{
		cin >> groupOfClimbers;
		allClimbers += groupOfClimbers;
		if (groupOfClimbers <= 5)
		{
			musalaClimbers += groupOfClimbers;
		}
		else if (groupOfClimbers >= 6&& groupOfClimbers <= 12)
		{
			monBlanClimbers += groupOfClimbers;
		}
		else if (groupOfClimbers >= 13 && groupOfClimbers <= 25)
		{
			kilimanjaroClimbers += groupOfClimbers;
		}
		else if (groupOfClimbers >= 26 && groupOfClimbers <= 40)
		{
			k2Climbers += groupOfClimbers;
		}
		else
		{
			everestClimbers += groupOfClimbers;
		}
	}

	double musalaPercentage = (double)musalaClimbers / allClimbers * 100.0;
	double monBlanPercentage = (double)monBlanClimbers / allClimbers * 100.0;
	double kilimanjaroPercentage = (double)kilimanjaroClimbers / allClimbers * 100.0;
	double k2Percentage = (double)k2Climbers / allClimbers * 100.0;
	double everestPercentage = (double)everestClimbers / allClimbers * 100.0;

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << musalaPercentage << "%" << endl;
	cout << monBlanPercentage << "%" << endl;
	cout << kilimanjaroPercentage << "%" << endl;
	cout << k2Percentage << "%" << endl;
	cout << everestPercentage << "%" << endl;

	return 0;
}