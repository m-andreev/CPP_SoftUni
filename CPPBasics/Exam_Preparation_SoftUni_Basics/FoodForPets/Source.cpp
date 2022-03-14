#include <iostream>
using namespace std;

int main()
{
	int days; cin >> days;
	double allFoodKilograms; cin >> allFoodKilograms;

	double catFood = 0;
	double dogFood = 0;
	double biscuits = 0;

	double dogFoodSummer = 0;
	double catFoodSummer = 0;


	for (int i = 1; i <= days; i++)
	{
		cin >> dogFood;
		dogFoodSummer += dogFood;
		cin >> catFood;
		catFoodSummer += catFood;
		double EatenFoodForTheDay = dogFood + catFood;
		if (i % 3 == 0)
		{
			biscuits = EatenFoodForTheDay - (0.9 * EatenFoodForTheDay);
		}
	}

	double totalEatenFood = dogFoodSummer + catFoodSummer;

	cout << "Total eaten biscuits: "<<biscuits<<"gr." << endl;
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << (totalEatenFood / allFoodKilograms)*100 << "% of the food has been eaten." << endl;
	cout << (dogFoodSummer / totalEatenFood)*100 << "% eaten from the dog." << endl;
	cout << (catFoodSummer / totalEatenFood)*100 << "% eaten from the cat." << endl;

	return 0;
}