#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int numOfDaysSantaIsGone; cin >> numOfDaysSantaIsGone;
	int leftFoodKG; cin >> leftFoodKG;
	double foodPerDayD1KG; cin >> foodPerDayD1KG;
	double foodPerDayD2KG; cin >> foodPerDayD2KG;
	double foodPerDayD3KG; cin >> foodPerDayD3KG;

	double totalEatenFood = (numOfDaysSantaIsGone*foodPerDayD1KG) + (numOfDaysSantaIsGone*foodPerDayD2KG) + (numOfDaysSantaIsGone*foodPerDayD3KG);

	if (leftFoodKG >= totalEatenFood)
	{
		cout << floor(leftFoodKG - totalEatenFood) << " kilos of food left." << endl;
	}
	else if (leftFoodKG < totalEatenFood)
	{
		cout << ceil(totalEatenFood - leftFoodKG)<< " more kilos of food are needed." << endl;
	}

	return 0;
}