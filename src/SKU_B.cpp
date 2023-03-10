#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <string>

#define MAXLEN 1000000

using namespace std;

string S;
vector<string> tokens;
set<char> separaters;

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("../input", "r", stdin);

    char tmpS[MAXLEN];
    cin.getline(tmpS, MAXLEN);

    S = string(tmpS);
    string sep = "<>&|()";
    for (int i = 0; i < sep.size(); i++)
        separaters.insert(sep[i]);

    int len = S.size();
    int start_pos = 0;
    bool successive_sep = false;
    for (int i = 0; i < len; i++) {
        const char c = S[i];
        if (c == ' ')
            continue;
            
        if (separaters.find(c) == separaters.end()) {
            // c is not a separater
            continue;
        }

        int end_pos = i;
        tokens.push_back(S.substr(start_pos, end_pos - start_pos));
        start_pos = end_pos;

        char tmp_str[1];
        tmp_str[0] = c;
        tokens.push_back(tmp_str);
    }
    tokens.push_back(S.substr(start_pos, len - start_pos));

    for(int i=0; i<tokens.size(); i++) {
        cout << tokens[i] << ' ';
    }
    cout << '\n';
}
