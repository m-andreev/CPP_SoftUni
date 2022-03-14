#include <iostream>
using namespace std;

int main()
{
	int firstNum; cin >> firstNum; ////beginning
	int secondNum; cin >> secondNum; ////ending

	for (int number = firstNum; number <= secondNum; number++)
	{
		int units = number % 10;
		int tens = number / 10 % 10;
		int hundreds = number / 100 % 10;
		int thousands = number / 1000 % 10;

		if (units % 2 != 0 && tens % 2 != 0 && hundreds % 2 != 0 && thousands % 2 != 0)
		{
			cout << number << " ";
		}
	}
	return 0;
}