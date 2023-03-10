#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

typedef long long ll;

int N;

map<string, int> ext;

void parse(const string& src, vector<string>& ret, const string& del) {
	int Spos = src.find_first_not_of(del, 0);
	int Epos = src.find_first_of(del, Spos);

	while (Spos != string::npos || Epos != string::npos) {
		ret.push_back(src.substr(Spos, Epos - Spos));
		Spos = src.find_first_not_of(del, Epos);
		Epos = src.find_first_of(del, Spos);
	}
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string name;	cin >> name;
		vector<string> v;
		parse(name, v, ".");
		ext[v.back()]++;
	}

	for (auto it : ext)
		cout << it.first << ' ' << it.second << '\n';
}