#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <sstream>
using namespace std;

vector<int> createArray()
{
    vector<int> vec1;
    string line;

    getline(cin, line);
    istringstream istr(line);

    int currNum = 0;
    while (istr >> currNum)
    {
        vec1.push_back(currNum);
    }
    return vec1;
}

vector<int> func(vector<int>& trackA, vector<int>& trackB)
{
    vector<int>order;
    while (!(trackA.empty() && trackB.empty()))
    {
        if (trackA.empty())
        {
            cout << 'B';
            order.push_back(trackB.back());
            trackB.pop_back();
            continue;
        }
        else if (trackB.empty()) {
            cout << 'A';
            order.push_back(trackA.back());
            trackA.pop_back();
            continue;
        }

        if (trackA.back() < trackB.back())
        {
            cout << 'A';
            order.push_back(trackA.back());
            trackA.pop_back();
        }
        else
        {
            cout << 'B';
            order.push_back(trackB.back());
            trackB.pop_back();
        }
    }
    cout << endl;

    return order;
}



int main()
{
    vector<int> track1 = createArray();
    vector<int> track2 = createArray();

    vector<int> track3 = func(track1, track2);

    for (auto x : track3)
        cout << x << " ";
    cout << endl;

    while (!track3.empty())
    {
        cout << track3.back() << ' ';
        track3.pop_back();
    }

    return 0;
}