#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;

	/**int units = n % 10;
	int tens = n / 10 % 10;
	int hundreds = n / 100 % 10;
	int thousands = n / 1000 % 10;*/

	for (int a = 1; a < 9; a++)
	{
		for (int b = 9; b > a; b--)
		{
			for (int c = 1; c < 9; c++)
			{
				for (int d = 8; d > c; d--)
				{
					int sum = a + b + c + d;
					int multiply = a * b * c * d;
					if ((sum == multiply)&&(n%10==5))
					{
						cout << a << b << c << d << endl;
						return 0;
					}
					if ((multiply / sum) == 3 && (n%3==0))
					{
						cout << d << c << b << a << endl;
						return 0;
					}
					else
					{
						cout << "Nothing found" << endl;
						return 0;
					}
				}
			}
		}
		return 0;
	}
}