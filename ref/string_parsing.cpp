#include <iostream>
#include <cstring>

#define endl "\n"
using namespace std;

void parseString(const string& str, string& delimeter, vector<string>& subStrings) {
    string::size_type bPos = str.find_first_not_of(delimeter, 0);
    string::size_type ePos = str.find_first_of(delimeter, 0);

    while(string::npos != bPos || string::npos != ePos) {
        subStrings.push_back(str.substr(bPos, ePos - bPos));
        bPos = str.find_first_not_of(delimeter, ePos);
        ePos = str.find_first_of(delimeter, bPos);
    }
}
int main(int argc, char *argv[]) {
    string str = string("Hello World!.\n It is too\thard to parse string in C++.");
    string del = string(" \n\t.");
    vector<string> subStrings;

    parseString(str, del, subStrings);
    for (const auto & e : subStrings)
        cout << e << endl;
    return 0;
}