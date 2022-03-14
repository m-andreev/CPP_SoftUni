#include <iostream>
#include <string>
using namespace std;

int main()
{
	int numOfFloors; cin >> numOfFloors;
	int numOfRooms; cin >> numOfRooms;
	int counter = 0;

	for (int i = numOfFloors; i >= 1; i--)
	{
		for (int j = 0; j < numOfRooms; j++)
		{
			if (numOfFloors == i)
			{
				cout << "L" << i << j << " ";
				counter++;
			}
			if (i % 2 == 0 && i != numOfFloors)
			{
				cout << "O" << i << j << " ";
				counter++;
			}
			if (i % 2 != 0 && i != numOfFloors)
			{
				cout << "A" << i << j << " ";
				counter++;
			}
		}
		cout << endl;
	}

	return 0;
}