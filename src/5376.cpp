#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef long long ll;

int N;

bool parse(const string& src, vector<string>& ret, const string& del) {
	int S, E;
	S = src.find_first_not_of(del, 0);
	E = src.find_first_of(del, S);

	while (S != string::npos || E != string::npos) {
		ret.push_back(src.substr(S, E - S));
		S = src.find_first_not_of(del, E);
		E = src.find_first_of(del, S);
	}
}

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	int r;
	while (y != 0) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

int power(int x, int p) {
	int ret = 1;
	while (p--) ret *= x;
	return ret;
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	cin >> N;
	while (N--) {
		string num;	cin >> num;
		vector<string> ret;
		string del = "()";
		parse(&num[2], ret, del);

		int dend, dsor;		//	dend / dsor
		if (ret.size() == 1) {
			dend = stoi(ret[0]);
			dsor = power(10, ret[0].size());
		}
		else {
			string tmp_dsor = "";
			for (int i = 0; i < ret[1].size(); i++)	tmp_dsor.push_back('9');
			for (int i = 0; i < ret[0].size(); i++) tmp_dsor.push_back('0');
			dsor = stoi(tmp_dsor);
			dend = stoi(ret[0] + ret[1]) - stoi(ret[0]);
		}
		int r = gcd(dend, dsor);
		dend /= r, dsor /= r;
		cout << dend << '/' << dsor << '\n';
	}

}