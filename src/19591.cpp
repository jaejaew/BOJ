#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<deque>

using namespace std;

typedef long long ll;

void parse(const string& str, deque<ll>& operands, deque<char>& operators, const string& del) {
	int S, E;
	S = str.find_first_not_of(del, 0);
	E = str.find_first_of(del, S);

	while (S != string::npos || E != string::npos) {
		operands.push_back(stoll(str.substr(S, E - S)));
		if (E != string::npos)
			operators.push_back(str[E]);

		S = str.find_first_not_of(del, E);
		E = str.find_first_of(del, S);
	}
}

inline int pri(char c) {
	if (c == '+' || c == '-') return 0;
	return 1;
}

ll calc(ll x, ll y, char op) {
	switch (op) {
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	}
}


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	string str;	cin >> str;
	deque<ll> nums;
	deque<char> ops;
	string del = "+*-/";

	bool minus = (str[0] == '-');
	parse(str, nums, ops, del);
	if (minus) nums.front() = -nums.front();
	
	while (nums.size() > 1) {
		char fop = ops.front(), bop = ops.back();
		bool b = false;

		ll fret = calc(nums[0], nums[1], ops[0]);
		ll bret = calc(nums[nums.size() - 2], nums[nums.size() - 1], ops.back());

		if (pri(ops.front()) < pri(ops.back()))
			b = true;
		else if (pri(ops.front()) == pri(ops.back()) && fret < bret)
			b = true;

		if (!b) {
			ops.pop_front();
			nums.pop_front();	nums.pop_front();
			nums.push_front(fret);
		}
		else {
			ops.pop_back();
			nums.pop_back();	nums.pop_back();
			nums.push_back(bret);
		}
	}

	cout << nums[0];
}