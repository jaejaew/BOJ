#define MAXN	1'000'100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, M;
int parent[MAXN];

int find(int x) {
	int& p = parent[x];
	if (p < 0) return x;
	else return p = find(p);
}

void weightedUnion(int x, int y) {
	x = find(x);	y = find(y);
	if (x == y) return;

	if (-parent[x] > -parent[y]) {
		/* a set containing x is bigger */
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
		freopen("./input/1717.txt", "r", stdin);

	cin >> N >> M;
	memset(parent, -1, sizeof(parent));

	for (int i = 0; i < M; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			weightedUnion(a, b);
		}
		else {
			cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
		}
	}
}