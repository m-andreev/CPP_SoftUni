#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <iomanip>
using namespace std;

class EuqlidianDistance {
	double x1, y1,x2,y2;
	double distance;
	
public:

	void input();
	double calc();
	void output();


};

void EuqlidianDistance::input()
{
	cin >> x1 >> y1 >> x2 >> y2;
}

double EuqlidianDistance::calc()
{
	distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
	return distance;
}

void EuqlidianDistance::output()
{
	cout.setf(ios::fixed);
	cout.precision(3);
	cout << calc();
}


int main()
{
	EuqlidianDistance d1;
	d1.input();
	d1.output();


	return 0;
}

/*

Write a program to calculate the (Euclidean) distance between two points p1 {x1, y1} and p2 {x2, y2}.

3 4 ///x1 y1
6 8 ///x2 y2

Output:
5.000
*/