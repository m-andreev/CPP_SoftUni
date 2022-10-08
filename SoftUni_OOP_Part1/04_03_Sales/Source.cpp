#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <list>
using namespace std;

class Sales {
	string town;
	string product;
	double price;
	double quantity;

	map<string, pair<string, vector<double>>> m1; /// Sofia beer 1.20 160

public:
	Sales();
private:
	void input(size_t & n);
	void output();
};

void Sales::input(size_t & n)
{
	for (size_t i = 0; i < n; i++)
	{
		string inp;
		getline(cin >> ws, inp);
		istringstream istr(inp);
		istr >> town >> product >> price >> quantity;
		vector<double> temp1;
		temp1.push_back(price); temp1.push_back(quantity); temp1.push_back(price * quantity);

		map<string, pair<string, vector<double>>>::iterator mapIt1 = m1.find(town);

		if (mapIt1 == m1.end())
		{
			m1[town] = (pair<string, vector<double>>(product, temp1));
		}
		else
		{
			///for(int i=0;i<temp1.size();i++)
			m1[town].second[2] += temp1[2];
		}
	

	}
	
}

void Sales::output()
{
	cout.setf(ios::fixed);
	cout.precision(2);

	for (map<string, pair<string, vector<double>>>::iterator mapIt = m1.begin(); mapIt != m1.end(); mapIt++)
	{
		cout << mapIt->first << " -> " << mapIt->second.second[2]<<endl;
	}
}

Sales::Sales()
{
	size_t iterations; cin >> iterations;
	input(iterations);
	output();
}


int main()
{
	Sales obj1;

	return 0;
}

/*

5
Sofia beer 1.20 160
Varna chocolate 2.35 86
Sofia coffee 0.40 853
Varna apple 0.86 75.44
Plovdiv beer 1.10 88


Output:

Plovdiv -> 96.80
Sofia -> 533.20
Varna -> 266.98


*/
