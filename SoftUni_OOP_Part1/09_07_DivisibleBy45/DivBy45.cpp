#include <iostream>
#include <string>

#include "BigInt.h"

using namespace std;

unsigned sumOfDigits(const string& numDigits)
{
	unsigned result = 0;
	for (size_t i = 0; i < numDigits.length(); i++)
	{
		result += (numDigits[i] - '0');
	}
	return result;
}

bool divisibleBy45(BigInt& number) {
	string numStr = number.getDigits();

	// 45 = 9 * 5 
	//divisible by 5 => the sum of the digits is divisible by 9

	if (numStr[numStr.length() - 1] == '5' ||
		numStr[numStr.length() - 1] == '0')
	{
		if (sumOfDigits(numStr) % 9 == 0)
			return true;
	}
	return false;
}


int main()
{
	string start, finish;

	cin >> start >> finish;

	BigInt from(start), to(finish);

	for (BigInt cur = from; cur < to; cur = cur + BigInt(1))
	{
		if (divisibleBy45(cur))
		{
			cout << cur << endl;
		}
	}

	return 0;
}