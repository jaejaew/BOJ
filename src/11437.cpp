#define MAXN	100001
#define MAXH	18
#define ROOT	1
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, M;
struct Node {
	int parent[MAXH];
	int height;
	vector<int> child;
	bool visited;
} node[MAXN];

void dfs(int v, int h) {
	node[v].visited = true;
	node[v].height = h;

	for (const int& e : node[v].child) {
		if (!node[e].visited) {
			dfs(e, h + 1);
			node[e].parent[0] = v;
		}
	}
}

int LCA(int u, int v) {
	if (node[u].height > node[v].height)	swap(u, v);
	int dff = node[v].height - node[u].height;

	for (int i = 0; dff > 0; i++) {
		if (dff & 1)
			v = node[v].parent[i];
		dff >>= 1;
	}

	if (u != v) {
		for (int i = MAXH-1; i >= 0; --i) {
			if (node[u].parent[i] != node[v].parent[i]) {
				u = node[u].parent[i];
				v = node[v].parent[i];
			}
		}
		u = node[u].parent[0];
	}
	return u;
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/11437.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		node[v1].child.push_back(v2);
		node[v2].child.push_back(v1);
	}

	dfs(ROOT, 0);

	for (int i = 1; i < MAXH; i++) {
		for (int j = 1; j <= N; j++) {
			node[j].parent[i] = node[node[j].parent[i - 1]].parent[i - 1];
		}
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		cout << LCA(v1, v2) << '\n';
	}

}