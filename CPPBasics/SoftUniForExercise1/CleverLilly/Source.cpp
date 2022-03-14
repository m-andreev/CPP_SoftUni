#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int LillysAge , toyPrice;
	double wMachine;
	cin >> LillysAge >> wMachine >> toyPrice;

	double money = 0.0;
	double moneyForBirthday = 10.0;


	for (size_t i = 1; i <= LillysAge; i++)
	{
		if (i % 2 == 0)
		{
			money += moneyForBirthday;
			moneyForBirthday += 10;
			money -= 1;
		}
		else
		{
			money += toyPrice;
		}
	}
	
	double diff = money - wMachine;
	cout.setf(ios::fixed);
	cout.precision(2);
	if (diff >= 0)
	{
		cout << "Yes! " <<diff<< endl;
	}
	else
	{
		cout << "No! " << abs(diff) << endl;
	}

	return 0;
}