#include <iostream>
using namespace std;

int area(int m , int n)
{
	int area = m * n;
	return area;
}

int main()
{
	int a; cin >> a;
	int b; cin >> b;

	cout << area(a, b);

	return 0;
}