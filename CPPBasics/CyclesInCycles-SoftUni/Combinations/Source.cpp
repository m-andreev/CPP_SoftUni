#include <iostream>
using namespace std;

int main()
{
	int number; cin >> number;
	int combination = 0;

	for (int x1 = 0; x1 <= number; x1++)
	{
		for (int x2 = 0; x2 <= number; x2++)
		{
			for (int x3 = 0; x3 <= number; x3++)
			{
				if (x1 + x2 + x3 == number)
				{
					combination++;
				}
			}
		}
	}
	cout << combination << endl;
	return 0;
}