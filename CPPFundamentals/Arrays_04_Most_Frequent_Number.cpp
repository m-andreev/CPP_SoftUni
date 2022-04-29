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

	int* numbers = new int[10] {};/// 0,1,2,3 ...9
	
	for (size_t i = 0; i < n; i++)
	{
		int currNum = arr1[i]; /// currNum = 4 for example
		numbers[currNum]++; /// numbers[4]++ :)
	}

	int maxCount = 0;
	int mostFrNum = 0;

	for (size_t i = 0; i < 10; i++)
	{
		if (numbers[i] > maxCount)
		{
			maxCount = numbers[i];
		}
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (numbers[i] == maxCount)
		{
			cout<<i<< " ";
		}
	}

	delete[] arr1;

	return 0;
}