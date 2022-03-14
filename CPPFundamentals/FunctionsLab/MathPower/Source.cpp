#include <iostream>
#include <cmath>
using namespace std;

int powerFunc(int a, int b)
{
	return pow(a, b);
}

int main()
{
	int m; cin >> m;
	int n; cin >> n;

	cout << powerFunc(m, n);

	return 0;
}