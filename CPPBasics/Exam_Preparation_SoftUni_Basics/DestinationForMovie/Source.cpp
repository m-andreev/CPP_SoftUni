#include <iostream>
#include <string>
using namespace std;

int main()
{
	double movieBudget; cin >> movieBudget;
	string destination; getline(cin >> ws, destination);
	string season; cin >> season;
	int days; cin >> days;

	double price = 0.0;

	if (destination == "Dubai")
	{
		if (season == "Winter")
		{
			price = 45000;
		}
		else if (season == "Summer")
		{
			price = 40000;
		}
	}
	else if (destination == "Sofia")
	{
		if (season == "Winter")
		{
			price = 17000;
		}
		else if (season == "Summer")
		{
			price = 12500;
		}
	}
	else if (destination == "London")
	{
		if (season == "Winter")
		{
			price = 24000;
		}
		else if (season == "Summer")
		{
			price = 20250;
		}
	}

	double finalSum = days * price;

	if (destination == "Dubai")
	{
		finalSum = finalSum - (0.30 * finalSum);
	}
	if (destination == "Sofia")
	{
		finalSum = finalSum + (0.25 * finalSum);
	}

	cout.setf(ios::fixed);
	cout.precision(2);
	if (movieBudget >= finalSum)
	{
		cout << "The budget for the movie is enough! We have " << movieBudget - finalSum << " leva left!" << endl;
	}
	else
	{
		cout << "The director needs " << finalSum - movieBudget << " leva more!" << endl;
	}

	return 0;
}