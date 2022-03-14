#include <iostream>
using namespace std;

int main()
{
	int beginInterval, endInterval, magicNumber;
	cin >> beginInterval >> endInterval >> magicNumber;
	int counter = 0;

	for (int i = beginInterval; i <= endInterval; i++)
	{
		for (int j = beginInterval; j <= endInterval; j++)
		{
			counter++;
			if (i + j == magicNumber)
			{
				cout << "Combination N:" << counter <<" (" << i << " + "<< j <<" = "<<i + j<<")" << endl;
				return 0;
			}
		}
	}
	cout << counter << " combinations - neither equals " << magicNumber << endl;

	return 0;
}