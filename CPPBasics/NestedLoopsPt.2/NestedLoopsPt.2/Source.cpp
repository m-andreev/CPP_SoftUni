#include <iostream>
using namespace std;

int main()
{
	int n;cin >> n;
	int current = 1;
	bool isBigger = false;

	for (int rows = 1; rows <= n; rows++)
	{
		for (int cols = 1; cols <= rows; cols++)
		{
			if (current > n)
			{
				isBigger = true;
				break;
			}
			cout << current << " ";
			current++;
		}
		if (isBigger)
		{
			break;
		}
		cout << endl;
	}

	return 0;
}