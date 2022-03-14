#include <iostream>
#include <string>
using namespace std;

int main()
{


	for (size_t hours = 0; hours < 24; hours++)
	{
		for (size_t minutes = 0; minutes < 60; minutes++)
		{
			cout << hours << ":" << minutes << endl;
		}
	}
	return 0;
}