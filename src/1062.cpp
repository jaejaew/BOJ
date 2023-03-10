#define MAXN 55

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<set>

using namespace std;

typedef long long ll;

int N, K;
string S = "antatica";
int ans;
int words[MAXN];

void dfs(int level, int cnt, int mask) {
	if (cnt <= 0) {
		int ret = 0;
		for (int i = 0; i < N; i++)
			if (!(words[i] & ~mask)) ret++;
		ans = max(ret, ans);
		return;
	}
	if (level + cnt > 26) return;	//	'a': 0, 'z': 25
	if (level >= 26) return;

	char now = 'a' + level;
	if (!(now == 'a' || now == 'n' || now == 't' || now == 'i' || now == 'c'))
		dfs(level + 1, cnt - 1, mask | (1 << level));
	dfs(level + 1, cnt, mask);	//	not include 'a'+level

}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	cin >> N >> K;
	
	int mask = 0;
	for (const char& c : S)
		mask |= (1 << (c - 'a'));

	K -= 5;	// antic

	for (int i = 0; i < N; i++) {
		string tmp;	cin >> tmp;
		for (char c : tmp)
			words[i] |= (1 << (c - 'a'));
	}

	if (K >= 0)
		dfs(0, K, mask);

	cout << ans;
}