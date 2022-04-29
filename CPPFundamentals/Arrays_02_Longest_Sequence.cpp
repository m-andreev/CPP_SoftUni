#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int* arr1 = new int[n];

	int seqNum = 0;
	int seqCount = 1;
	
	int maxSeqNum = 0;
	int maxSeqCount = 0;

	for (size_t i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	for (size_t i = 0; i < n; i++)
	{
		int buff = arr1[0];
		if (arr1[i] == arr1[i+1])
		{
			seqNum = arr1[i];
			seqCount++;
		}
		else
		{
			if (seqCount >= maxSeqCount)
			{
				maxSeqCount = seqCount;
				maxSeqNum = seqNum;
			}
			seqNum = arr1[i];
			seqCount = 1;
		}
	}

	
	////We need to do it one more time !!!!
	
	if (seqCount >= maxSeqCount)
	{
		maxSeqCount = seqCount;
		maxSeqNum = seqNum;
	}

	for (int i = 0; i < maxSeqCount; i++)
	{
		cout << maxSeqNum << " ";
	}

	delete[] arr1;

	return 0;
}