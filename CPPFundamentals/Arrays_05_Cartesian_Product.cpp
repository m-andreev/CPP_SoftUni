#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int* arr1 = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	int m = n * n;
	int* arr2 = new int[m];

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			arr2[i] = arr1[i] * arr1[j];
			cout << arr2[i] << " ";
		}
	}

	

	return 0;
}