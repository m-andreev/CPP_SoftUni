#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <memory>
#include <list>

using namespace std;

class Range {
    int from, to;
public:
    Range() = default;
    Range(int from_, int to_) : from(from_), to(to_) {}

    int getFrom() const { return this->from;  }
    int getTo() const { return this->to; }
    int checkNumber(int number) { return number >= from && number <= to; }

};


int main()
{
    list<shared_ptr<Range>> ranges;


    /// Reading ranges
    string line;
    while (getline(cin, line) && line != ".") {
        istringstream istr(line);

        int from, to;
        istr >> from >> to;

        ranges.push_back(make_shared<Range>(from, to));
    }

    ///Reading numbers
 
    while (getline(cin, line) && line != ".") {
        istringstream istr2(line);

        int number;
        istr2 >> number;

        bool inIt = false;
        list<shared_ptr<Range>>::iterator it = ranges.begin();
        while (it != ranges.end()) {
            Range* ptr = it->get(); /// Vzima syotvetniqt element ot syotvetnata poziciq ?!
            it++;

            if (ptr->checkNumber(number)) {
                inIt = true;
                break;
            }

        }

        cout <<( inIt ? "in" : "out" )<< endl;

    }


    

    return 0;
}