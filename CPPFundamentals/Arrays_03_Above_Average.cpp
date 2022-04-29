#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int* arr1 = new int[n];
	int sum = 0;
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	for (size_t i = 0; i < n; i++)
	{
		sum += arr1[i];
	}

	int average = sum / n;
	for (size_t i = 0; i < n; i++)
	{
		if (arr1[i] >= average)
		{
			cout << arr1[i] << " ";
		}
	}

	return 0;
}