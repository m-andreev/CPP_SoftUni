#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>

// Place your code here

using namespace std;

vector<string> operator+(const vector<string>& first, const vector<string>& second)
{
	vector<string> result;
	result.resize(first.size());

	for (int i = 0; i < result.size(); i++)
	{
		result[i] = first[i] + " " + second[i];
	}

	return result;
}

#endif // !SUMOFVECTORS_H

