#include <iostream>
using namespace std;

int main()
{
	double change ;
	cin >> change;

	int coinsToInt = change * 100;

	int coinCounter = 0;

	while (coinsToInt > 0)
	{
		if (coinsToInt >= 200)
		{
			coinCounter++;
			coinsToInt -= 200;
		}
		else if (coinsToInt >= 100)
		{
			coinCounter++;
			coinsToInt -= 100;
		}
		else if (coinsToInt >= 50)
		{
			coinCounter++;
			coinsToInt -= 50;
		}
		else if (coinsToInt >= 20)
		{
			coinCounter++;
			coinsToInt -= 20;
		}
		else if (coinsToInt >= 10)
		{
			coinCounter++;
			coinsToInt -= 10;
		}
		else if (coinsToInt >= 5)
		{
			coinCounter++;
			coinsToInt -= 5;
		}
		else if (coinsToInt >= 2)
		{
			coinCounter++;
			coinsToInt -= 2;
		}
		else if (coinsToInt >= 1)
		{
			coinCounter++;
			coinsToInt -= 1;
		}
	}
	cout << coinCounter << endl;
	return 0;
}