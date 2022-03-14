#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	double freeSpaceWidth, freeSpaceLength, freeSpaceHeight;
	cin >> freeSpaceWidth >> freeSpaceLength >> freeSpaceHeight;
	double freeSpace = freeSpaceWidth * freeSpaceLength * freeSpaceHeight;
	double occupiedSpace = 0.0;
	double freeSpaceCopy = freeSpace;
	int numBoxes = 0;

	string command = "";

	while ((freeSpace>=0 ) || (command != "Done"))
	{
		if (freeSpace < 0)
		{
			break;
		}
		cin >> command;
		if (command == "Done")
		{
			break;
		}

		numBoxes = stoi(command);
		freeSpace -= numBoxes;
	}

	if (command == "Done")
	{
		cout << freeSpace << " Cubic meters left." << endl;
	}
	else if(freeSpace<0)
	{
		cout << "No more free space! You need " << abs(freeSpace) << " Cubic meters more." << endl;
	}
	return 0;
}