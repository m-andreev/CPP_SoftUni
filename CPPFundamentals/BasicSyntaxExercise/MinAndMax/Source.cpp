#include <iostream>
#include <limits.h>
using namespace std;

int main()
{
	int min = INT_MAX;
	int max = INT_MIN;

	int N; cin >> N;
	for (int rotation = 1; rotation <= N; rotation++)
	{
		int number; cin >> number;
		if (min > number) 
		{ 
			min = number;
		}
		if (max < number)
		{
			max = number;
		}
	}
	cout << min << " " << max << endl;

	return 0;
}