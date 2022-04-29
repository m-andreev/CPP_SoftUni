#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

/*
name age height
Joro 25 182
Oroj 25 182
youngerJoro 18 182
end
age
*/


int findIndex(const vector<string>& data, const string& query)
{
	int queryColumn = 0;
	for (string colName : data)
	{
		if (colName == query)
			return queryColumn;
		queryColumn++;
	}
	return -1;
}

int main()
{
	vector<string> columns; /// first line
	vector< vector<string> >data;
	string query; /// the name of our column , which we need to process

	////read the name of columns
	string buf;
	getline(cin, buf);

	istringstream columnStream(buf);
	string colBuf;
	while (columnStream >> colBuf)
		columns.push_back(colBuf);

	size_t numberOfColumns = columns.size(); ///num of cols

	while (true)
	{
		getline(cin, buf);
		if (buf == "end")
			break;

		istringstream inputStream(buf);
		string itemBuf;
		vector<string> curLine;

		while (inputStream >> itemBuf)
			curLine.push_back(itemBuf);

		data.push_back(curLine);

	}

	cin >> query;

	int queryColumn = findIndex(columns, query);

	vector<string> queryData;
	vector<unsigned> countData;

	for (vector<string>& row : data)
	{
		////row[queryColumn] !
		string curData = row[queryColumn];

		int dataIndex = findIndex(queryData, curData);
		if (dataIndex == -1)
		{
			queryData.push_back(curData);
			countData.push_back(1);
		}
		else
		{
			countData[dataIndex]++;
		}
	}

	unsigned maxOccurences = 0;
	int maxOccurencesIndex = 0;
	int curIndex = 0;
	for (unsigned curOccurency : countData)
	{
		if (curOccurency > maxOccurences)
		{
			maxOccurences = curOccurency;
			maxOccurencesIndex = curIndex;
		}
		curIndex++;
	}

	cout << queryData[maxOccurencesIndex] << " " << countData[maxOccurencesIndex] << endl;



	return 0;
}