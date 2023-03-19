#define MAXN 

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<deque>

using namespace std;

typedef long long ll;

void parse(const string& str, deque<string>& ret, const string& del) {
	int s_pos = str.find_first_not_of(del, 0);
	int e_pos = str.find_first_of(del, s_pos);

	while (e_pos != string::npos) {
		ret.push_back(str.substr(s_pos, e_pos - s_pos));
		s_pos = str.find_first_not_of(del, e_pos);
		e_pos = str.find_first_of(del, s_pos);
	}
}

string solve(deque<string>& arr, string& cmd) {
	bool reversed = false;
	for (int i = 0; i < cmd.size(); i++) {
		if (cmd[i] == 'D') {
			if (arr.empty()) return "error";
			if (!reversed) arr.pop_front();
			else arr.pop_back();
		}
		else {
			reversed ^= true;
		}
	}
	string ans = "[";
	if (!reversed)
		for (deque<string>::iterator it = arr.begin(); it != arr.end(); it++) {
			ans += *it;
			if (next(it) != arr.end()) ans.push_back(',');
		}
	else
		for (deque<string>::reverse_iterator rit = arr.rbegin(); rit != arr.rend(); rit++) {
			ans += *rit;
			if (next(rit) != arr.rend()) ans.push_back(',');
		}
	ans.push_back(']');
	return ans;
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/5430.txt", "r", stdin);

	int T;	cin >> T;
	for (int t = 0; t < T; t++) {
		string cmd;	cin >> cmd;
		int N;	cin >> N;
		string arr;	cin >> arr;
		deque<string> parsed;
		parse(arr, parsed, string("[,]"));
		cout << solve(parsed, cmd) << '\n';
	}
}