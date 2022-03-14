#include <iostream>
using namespace std;

int main()
{
	int numOfDancers; cin >> numOfDancers;
	double points; cin >> points;
	string season; cin >> season;
	string location; cin >> location;

	double moneyPrize = 0;

	if (location == "Bulgaria")
	{
		moneyPrize = (double)points * numOfDancers;
		if (season == "summer")
		{
			moneyPrize = (double)moneyPrize - (0.05 * moneyPrize);
		}
		else if (season == "winter")
		{
			moneyPrize = (double)moneyPrize - (0.08 * moneyPrize);
		}
	}
	else if (location == "Abroad")
	{
		moneyPrize = (double)points * numOfDancers + (0.5 * (points * numOfDancers));
		if (season == "summer")
		{
			moneyPrize = (double)moneyPrize - (0.10 * moneyPrize);
		}
		else if (season == "winter")
		{
			moneyPrize = (double)moneyPrize - (0.15 * moneyPrize);
		}
	}

	double CharityMoney = (double)0.75 * moneyPrize;
	double moneyAfterCharity = (double)moneyPrize - CharityMoney;
	double moneyPerDancer = moneyAfterCharity / numOfDancers;

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << "Charity - " << CharityMoney << endl;
	cout << "Money per dancer - " << moneyPerDancer<< endl;

	return 0;
}