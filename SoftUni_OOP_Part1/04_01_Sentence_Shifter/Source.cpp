#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <queue>
using namespace std;


/*
class Sequence {
public:
	typedef vector<string> Sentence;
	Sentence sent;

	Sequence(istream& stream);

	Sentence getShiftedSentence(size_t index);

	void print(ostream& ostr);
	static void print(ostream& ostr , const Sentence & seq);
};
Sequence::Sequence(istream& istr)
{
	string buf;
	getline(istr, buf);

	istringstream sstr(buf);

	while (sstr >> buf)
	{
		sent.push_back(buf);
	}
}

void Sequence::print(ostream& ostr, const Sentence & seq)
{
	string str;
	for (size_t i = 0; i < seq.size(); i++)
	{
		ostr << seq[i] << endl;
	}

}

void Sequence::print(ostream& ostr)
{
	print(ostr , sent);
}

Sequence::Sentence Sequence::getShiftedSentence(size_t index) /// size_t index e shifter-yt
{
	Sentence ret;

	ret = sent;

	for (; index; index--) ///dokato indeksyt e != 0
	{
		ret.insert(ret.begin(), ret.back()); ///// insert(kyde , kakvo )
		ret.pop_back(); /// vadim elementa i go slagame v nachaloto
	}
	return ret; /// vryshtame vektora
}

int main()
{
	Sequence seq(cin);

	size_t shifter; cin >> shifter;

	Sequence::Sentence res = seq.getShiftedSentence(shifter);
	Sequence::print(cout, res);

	return 0;
}


*/






 //this works too XD
int main()
{
	string line;
	getline(cin >> ws, line);

	istringstream istr(line);

	int shifter; cin >> shifter;

	list<string> sentence;
	list<string> reversedSentence;

	string piece;
	while (istr >> piece)
	{
		sentence.push_back(piece);
	}

	for (int i = 0; i < shifter; i++)
	{
		string p1 = sentence.back();
		sentence.pop_back();
		reversedSentence.push_back(p1);
			///sentence.push_front(p1);
	}

	for (list<string>::reverse_iterator itL = reversedSentence.rbegin(); itL != reversedSentence.rend(); itL++)
	{
		cout << *itL << endl;
	}

	while (!sentence.empty())
	{
		cout << sentence.front() << endl;
		sentence.pop_front();
	}


	return 0;
}