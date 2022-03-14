#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double availableBudget; cin >> availableBudget;
	int numOfStays; cin >> numOfStays;
	double stayPrice; cin >> stayPrice;
	double additionPercentage; cin >> additionPercentage;

	additionPercentage /= 100;

	double additionMoney = additionPercentage * availableBudget;

	if (numOfStays > 7)
	{
		stayPrice = stayPrice - (stayPrice * 0.05);
	}

	double totalSum = (double)additionMoney + (stayPrice * numOfStays);

	cout.setf(ios::fixed);
	cout.precision(2);

	if (availableBudget >= totalSum)
	{
		cout << "Ivanovi will be left with " << availableBudget - totalSum << " leva after vacation."<<endl;
	}
	else
	{
		cout << totalSum - availableBudget << " leva needed." << endl;
	}

	return 0;
}