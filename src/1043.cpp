#define MAXN	55

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

vector<int> party[MAXN];
int N, M;
int root;
int parent[MAXN];

int find(int x) {
	int& p = parent[x];
	if (p < 0) return x;
	return p = find(p);
}
void mUnion(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;

	if (-parent[x] > -parent[y]) {
		parent[x] += parent[y];
		parent[y] = x;
	}
	else {
		parent[y] += parent[x];
		parent[x] = y;
	}
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/1043.txt", "r", stdin);
	memset(parent, -1, sizeof(parent));
	cin >> N >> M;
	int num;	cin >> num;
	for (int i = 0; i < num; i++) {
		int v;	cin >> v;
		if (i == 0) root = v;
		else mUnion(root, v);
	}

	for (int i = 0; i < M; i++) {
		cin >> num;
		int prev;
		for (int j = 0; j < num; j++) {
			int now;	cin >> now;
			party[i].push_back(now);
			if (j > 0) mUnion(now, prev);
			prev = now;
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) 
		if (find(party[i][0]) != find(root)) 
			ans++;
	cout << ans;
	
}