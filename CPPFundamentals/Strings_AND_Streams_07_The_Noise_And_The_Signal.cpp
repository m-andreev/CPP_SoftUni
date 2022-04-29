#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string line;
	getline(cin, line);

	istringstream input1(line);

	string piece;
	int index = 0;

	string maxNoise = "";

	while (input1 >> piece)
	{
		string noise = "";
		for (index = 0; index < piece.length(); index++)
		{
			char c = piece[index];
			if (!(c >= '0' && c <= '9'))
			{
				noise += c;
			}
		}
		
		if (noise.length() == maxNoise.length())
		{
			if (noise < maxNoise)
			{
				maxNoise = noise;
			}
		}
		if (noise.length() > maxNoise.length())
			maxNoise = noise;
		if (noise == "")
		{
			maxNoise = "no noise";
		}
		index = 0;
	}
	cout << maxNoise << endl;

	return 0;
}