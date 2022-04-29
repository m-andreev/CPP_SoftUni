#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int index1(int index)
{
	return index = index + 1;
}

int charToInt(char c)
{
	c = c - '0';
	return c;
}

void convertInMinutes(int number[] , istringstream& input , int buses)
{
	string current;
	for (size_t i = 0; i < buses; i++)
	{
		int hours, minutes, totalMinutes;
		input >> current;
		hours = (charToInt(current[0]) * 10) + (charToInt(current[1]));
		minutes = (charToInt(current[2])) * 10 + (charToInt(current[3]));
		totalMinutes = (hours * 60) + minutes;
		number[i] = totalMinutes;

		//!!!???///Done
	}
	//for (size_t i = 0; i < buses; i++)
	//	cout << number[i] << " ";
}

int stringToIntConvertion(string current)
{
	int hours, minutes, totalMinutes;
	hours = (charToInt(current[0]) * 10) + (charToInt(current[1]));
	minutes = (charToInt(current[2])) * 10 + (charToInt(current[3]));
	totalMinutes = (hours * 60) + minutes;
	return totalMinutes;
}

int calculation(int busTime[],int length , int trainTime)
{
	int leastWaitTime = INT_MAX;
	int specialIndex = 0;
	int waitTime = INT_MAX;
	for (size_t i = 0; i < length; i++)
	{
		if (trainTime >= busTime[i])
		{
			waitTime = trainTime - busTime[i];
			if (waitTime <= leastWaitTime)
			{
				leastWaitTime = waitTime;
				specialIndex = index1(i);
			}
		}
		else if (trainTime < busTime[i])
		{
			waitTime = (1440 - busTime[i]) + trainTime ;
			if (waitTime <= leastWaitTime)
			{
				leastWaitTime = waitTime;
				specialIndex = index1(i);
			}
		}
	}
	return specialIndex;
}

int main()
{
	int buses; cin >> buses;

	string busTimes;
	getline(cin>>ws , busTimes);
	istringstream busTimes1(busTimes);

	string trainTime;
	getline(cin , trainTime);
	int trainTime1 = stringToIntConvertion(trainTime);
	//cout << trainTime1 << endl;

	int* number = new int[buses];
	convertInMinutes(number , busTimes1, buses); // buses times in int

	cout<<calculation(number, buses, trainTime1)<<endl;

	return 0;
}