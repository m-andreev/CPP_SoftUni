#include <iostream>
#include <string>
using namespace std;

int main()
{
	int width, length;
	cin >> length >> width;
	int pieces = length * width; /// total Pieces
	string command = " ";

	int nextPieces = 0;
	

	while (pieces > 0 && command != "STOP")
	{
		getline(cin >> ws, command);
		if (command != "STOP")
		{
			nextPieces = stoi(command);
			pieces -= nextPieces;
		}
	}

		if (command == "STOP")
		{
			cout << pieces <<" pieces are left."<< endl;
		}
		else
		{
			cout << "No more cake left! You need " << abs(pieces) << " pieces more." << endl;
		}
	    return 0;
}