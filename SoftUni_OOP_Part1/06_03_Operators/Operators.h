#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Place your code here

vector<string>& operator<<(vector<string>& vec, const string& str)
{
	vec.push_back(str);
	return vec;
}

string operator + (const string& str, int i)
{
	ostringstream res;

	res << str << i;

	return res.str();
}

ostream & operator << (ostream & ostr , const vector<string> & vec)
{
	for (size_t idx=0;idx<vec.size();idx++)
	{
		ostr << vec[idx];
		if(idx < vec.size()-1)
			ostr << endl;
		
		
	}
	return ostr;
}



#endif // !OPERATORS_H
