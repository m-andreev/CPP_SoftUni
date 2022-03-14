#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int allTournaments, Points;
	cin>> allTournaments>> Points;

	string title;
	int allPoints = 0;

	int winCounter=0;


	for (size_t i = 1; i <= allTournaments; i++)
	{
		cin >> title;
		if (title == "W")
		{
			Points += 2000;
			allPoints += 2000;
			winCounter++;
		}
		else if (title == "F")
		{
			Points += 1200;
			allPoints += 1200;
		}
		else if (title == "SF")
		{
			Points += 720;
			allPoints += 720;
		}
	}
	
	int averagePoints = (double)allPoints / allTournaments;
	double winPercentage = (double)winCounter / allTournaments * 100.0;

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << "Final points: " << Points << endl;
	cout << "Average points: " << averagePoints << endl;
	cout <<winPercentage << "%" << endl;

	return 0;
}