#include <iostream>
#include <tgmath.h>
using namespace std;

int main()
{
	int N; cin >> N;/// num of days
	double M; cin >> M;/// num of kilometers for first day of running
	double totalKilometers = M;
	int daysCounter = N;
	double totalRunnedKilometers = M;

	while (totalRunnedKilometers < 1000||daysCounter != 0)
	{
		double K;cin >> K;/////coefficient of increasing or decreasing running
		K = (double)K/100; //// making it in percentage
		totalKilometers = (double)totalKilometers + (K * totalKilometers);
		totalRunnedKilometers += totalKilometers;
		daysCounter--;
		if (totalRunnedKilometers >= 1000 || daysCounter == 0)
		{
			break;
		}
	}
	if (totalRunnedKilometers < 1000)
	{
		cout << "Sorry Mrs. Ivanova, you need to run " << ceil(1000 - totalRunnedKilometers) << " more kilometers" << endl;
	}
	else
	{
		cout << "You've done a great job running " << ceil(totalRunnedKilometers - 1000) << " more kilometers!" << endl;
	}
	return 0;
}