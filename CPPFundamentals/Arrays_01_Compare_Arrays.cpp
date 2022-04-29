#include <iostream>
#include <string>
using namespace std;

void createArray()
{

}

bool areEqual(int arr1[], int length1, int arr2[], int length2)
{
	if (length1 != length2)
	{
		return false;
	}

	for (int i = 0; i < length1; i++)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}

int main()
{
	int n; cin >> n;
	int* arr1 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	int m; cin >> m;
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr2[i];
	}

	cout << (areEqual(arr1, n, arr2, m) ? "equal" : "Not equal") << endl;
    
	delete[] arr1;
	delete[] arr2;
	return 0;
}