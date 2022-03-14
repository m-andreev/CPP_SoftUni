#include <iostream>
using namespace std;

void smallestNum(int a , int b, int c)
{
	if (a <= b && a <= c)
	{
		cout << a << endl;
	}
	else if (b <= a && b <= c)
	{
		cout << b << endl;
	}
	else if (c <= a && c <= b)
	{
		cout << c << endl;
	}
}

int main()
{
	int m; cin >> m;
	int n; cin >> n;
	int p; cin >> p;

	smallestNum(m, n, p);

	return 0;
}