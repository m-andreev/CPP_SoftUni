#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
using namespace std;

void createVec(list<int>& vec , istringstream& stream)
{
	int number = 0;
	while (stream >> number)
	{
		vec.push_front(number);
	}
}

int main()
{
	string trackA;
	getline(cin, trackA);

	string trackB;
	getline(cin, trackB);

	string trackC = trackA + ' ' + trackB;
	istringstream input1(trackC);

	list<int> mainTrack;
	createVec(mainTrack, input1);

	//sort(mainTrack.begin(), mainTrack.end());
	mainTrack.sort();
	//for (int x : mainTrack)
	//	cout << x << " ";

	for (auto it = mainTrack.begin(); it != mainTrack.end(); it++)
	{
		string var = "";
		var = to_string((*it));
		int found = trackA.find(var);
		if (found != std::string::npos)
		{
			cout << "A";
		}
		else
		{
			cout << "B";
		}
	}
	cout << endl;

	//sort(mainTrack.rbegin(), mainTrack.rend());

	for (auto it = mainTrack.rbegin(); it != mainTrack.rend(); it++)
		cout << *it << " ";

	if (trackA == "" && trackB == "")
	{
		cout << "";
	}

	mainTrack.clear();

	return 0;
}