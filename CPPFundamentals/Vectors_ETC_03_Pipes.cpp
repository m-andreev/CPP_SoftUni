#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

3
3 2 2
5 4 3

*/

int main()
{
	int numPipes; cin >> numPipes;

	int* checkup = new int[numPipes];
	int* installation = new int[numPipes];
	int* lifetime = new int[numPipes];

	for (size_t i = 0; i < numPipes; i++)
	{
		cin >> checkup[i];
	}
	
	for (size_t i = 0; i < numPipes; i++)
	{
		cin >> installation[i];
	}

	for (size_t i = 0; i < numPipes; i++)
	{
		int armotization = installation[i] - checkup[i]; /// 2,2,1; 
		int lifetime1 = installation[i] / armotization;
		lifetime[i] = lifetime1; /// 2,2,3;
	}

	for (size_t i = 0; i < numPipes; i++)
	{
		cout << lifetime[i] <<" ";
	}

	delete []checkup;
	delete []installation;
	delete []lifetime;

	return 0;
}