#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double strawBerriesPrice; cin >> strawBerriesPrice;
	double raspberriesPrice = 0.50 * strawBerriesPrice;
	double bananasPrice = 0.20*raspberriesPrice;
	double orangesPrice = 0.60*raspberriesPrice; 

	double bananas; cin >> bananas;
	double oranges; cin >> oranges;
	double raspberries; cin >> raspberries;
	double strawberries; cin >> strawberries;

	double totalSum = (double)(bananas * bananasPrice) + (oranges * orangesPrice) + (raspberries * raspberriesPrice) + (strawberries * strawBerriesPrice);

	cout.setf(ios::fixed);
	cout.precision(2);
	cout << totalSum << endl;

	return 0;
}