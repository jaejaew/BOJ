#define MAXN	100'100
#define MAXH	20
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

struct Node {
	int parent[MAXH];
	int maxlen[MAXH];
	int minlen[MAXH];
	int height;
	bool visited;
	vector<pair<int, int>> child;
} node[MAXN];
int N, K;

void dfs(int v, int h) {
	Node* ptr = &node[v];
	ptr->visited = true;
	ptr->height = h;

	for (const pair<int, int>& e : ptr->child) {
		Node* c = &node[e.first];
		if (!c->visited) {
			dfs(e.first, h + 1);
			c->parent[0] = v;
			c->maxlen[0] = e.second;
			c->minlen[0] = e.second;
		}
	}
}

pair<int, int> LCA(int u, int v) {
	int _min = (1LL << 30) - 1, _max = 0;
	if (node[u].height > node[v].height) swap(u, v);

	int dff = node[v].height - node[u].height;
	for (int i = MAXH - 1; i >= 0; --i) {
		if (!dff) break;
		if (dff & (1 << i)) {
			_min = min(_min, node[v].minlen[i]);
			_max = max(_max, node[v].maxlen[i]);
			v = node[v].parent[i];
			dff -= (1 << i);
		}
	}

	if (u != v) {
		for (int i = MAXH - 1; i >= 0; --i) {
			if (node[u].parent[i] != node[v].parent[i]) {
				_min = min(_min, min(node[u].minlen[i], node[v].minlen[i]));
				_max = max(_max, max(node[u].maxlen[i], node[v].maxlen[i]));
				u = node[u].parent[i];
				v = node[v].parent[i];
			}
		}
		_min = min(_min, min(node[u].minlen[0], node[v].minlen[0]));
		_max = max(_max, max(node[u].maxlen[0], node[v].maxlen[0]));
	}

	return { _min, _max };
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/3176.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		node[A].child.push_back({ B, C });
		node[B].child.push_back({ A, C });
	}

	dfs(1, 0);

	for (int i = 1; i < MAXH; i++) {
		for (int j = 1; j <= N; j++) {
			node[j].parent[i] = node[node[j].parent[i - 1]].parent[i - 1];
			node[j].maxlen[i] = max(node[j].maxlen[i - 1], node[node[j].parent[i - 1]].maxlen[i - 1]);
			node[j].minlen[i] = min(node[j].minlen[i - 1], node[node[j].parent[i - 1]].minlen[i - 1]);
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int D, E;
		cin >> D >> E;
		pair<int, int> res = LCA(D, E);
		cout << res.first << ' ' << res.second << '\n';
	}
}