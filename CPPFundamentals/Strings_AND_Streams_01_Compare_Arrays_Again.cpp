#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void cinArr(vector<int>& vec , istringstream & stream)
{
	int curNum;
	while (stream >> curNum)
	{
		vec.push_back(curNum);
	}
}

bool comparisonOfArrs(vector<int>& vec1 , vector<int>& vec2)
{
	if (vec1.size() != vec2.size())
		return false;
	

	for (size_t i = 0; i < vec1.size(); i++)
	{
		if (vec1[i] != vec2[i])
			return false;
	}
	return true;
}

int main()
{
	string line1 , line2;
	getline(cin, line1);
	getline(cin, line2);
	
	istringstream input1(line1);
	istringstream input2(line2);

	vector<int>vec1, vec2;
	cinArr(vec1 , input1);
	cinArr(vec2, input2);

	cout << ( comparisonOfArrs(vec1, vec2) ? "equal" : "not equal" )<< endl;


	return 0;
}