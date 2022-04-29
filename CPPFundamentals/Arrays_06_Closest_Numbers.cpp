#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main()
{
	int n; cin >> n;
	int* arr1 = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	sort(arr1, arr1 + n); // 1 105 10 100 3 => 1,3,10,100,105
	
	int closestNumValue = INT_MAX;

	if (n == 1)
	{
		closestNumValue = 0;
	}

	for (size_t i = 0; i < n; i++)
	{
		if (i != n - 1)
		{
			int diff = abs(arr1[i] - arr1[i + 1]);
			if (diff <= closestNumValue)
			{
				closestNumValue = diff;
			}
		}
	}
	cout << closestNumValue;

	delete[] arr1;
	return 0;
}