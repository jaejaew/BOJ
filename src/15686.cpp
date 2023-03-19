#define MAXN	55
#define MAXM	15

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, M;
int ans = (1LL << 31) - 1;
vector<pair<int, int>> house, chck;
vector<int> sel_chck;

inline int getDist(const pair<int, int>& h, const pair<int, int>& c) {
	return abs(h.first - c.first) + abs(h.second - c.second);
}

int getDistSum() {
	int ret = 0;
	for (int i = 0; i < house.size(); i++) {
		int _min = (1LL << 31) - 1;
		for (int j = 0; j < sel_chck.size(); j++) {
			_min = min(_min, getDist(house[i], chck[sel_chck[j]]));
		}
		ret += _min;
	}
	return ret;
}

void dfs(int level) {
	if (sel_chck.size() == M) {
		ans = min(ans, getDistSum());
		return;
	}
	if (sel_chck.size() + chck.size() - level < M) return;

	dfs(level + 1);	//	not include
	sel_chck.push_back(level);
	dfs(level + 1);
	sel_chck.pop_back();
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/15686.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int k;	cin >> k;
			if (k == 1) house.push_back({ i, j });
			else if (k == 2) chck.push_back({ i, j });
		}
	}
	dfs(0);
	cout << ans;
}