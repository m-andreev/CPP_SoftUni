#include <iostream>
using namespace std;

int main()
{
	int N; cin >> N; /// the number  , which will be divided to all the !digits! from 1111 to 9999

	for (int number = 1111; number < 10000; number++)
	{
		
		////// 2438 ---> units -> 8 , tens -> 3 , hundreds -> 4 , thousands -> 2
		
		int units = number % 10;
		int tens = number / 10 % 10;
		int hundreds = number / 100 % 10;
		int thousands = number / 1000 % 10;

		////// 2438 ---> units -> N%8==0 , tens -> N%3==0 , hundreds -> N%4==0 , thousands -> N%2==0 ---> S.N.
		if (units != 0 && tens != 0 && hundreds != 0 && thousands != 0) /// These must be different from 0
		{
			if (N % units == 0 && N % tens == 0 && N % hundreds == 0 && N % thousands == 0)
			{
				cout << number << " ";
			}
		}
	}
	return 0;
}
