#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int maxElement = INT_MIN;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		sum += num; //// Sum of every number
		if (maxElement < num)
		{
			maxElement = num;
		}
	}

	sum = sum - maxElement; ///// Making sum to be equal to itself without the maxElement, before creating diff!!!
	int diff = abs(sum - maxElement); //// Difference between sum and maxElement

	
	if (sum == maxElement)
	{
		cout << "Yes" << endl;
		cout << "Sum = " << sum << endl;
	}
	else
	{
		cout << "No" << endl;
		cout << "Diff = " << diff << endl;
	}
	return 0;
}