#define MAXN	100'100

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
int N;
int parent[MAXN];
pii coIDX[3][MAXN];
//priority_queue<pair<int, pii>> edge;	//	<cost, <u, v>>

struct Edge {
	int cost;
	int u, v;

	const bool operator<(const Edge& e) const {
		return cost < e.cost;
	}
};

class PQ {
#define parent	(i>>1)
#define left	(i<<1)
#define right	(i<<1|1)
private:
	int size;
	Edge data[MAXN << 2];
public:
	void init() {
		size = 0;
	}
	void push(pair<int, pii> e) {
		int cost = -e.first;
		int u = e.second.first;
		int v = e.second.second;
		data[++size] = { -cost, u, v };

		for (int i = size; parent != 0; i >>= 1) {
			if (data[parent] < data[i])
				swap(data[parent], data[i]);
			else break;
		}
	}

	pair<int, pii> top() {
		return { data[1].cost, {data[1].u, data[1].v} };
	}

	void pop() {
		data[1] = data[size--];
		for (int i = 1; left <= size; ) {
			int maxChild = ((left == size) || data[right] < data[left]) ? left : right;
			if (data[i] < data[maxChild]) {
				swap(data[i], data[maxChild]);
				i = maxChild;
			}
			else break;
		}
	}

#undef parent
#undef left
#undef right
} edge;
int find(int x) {
	int& p = parent[x];
	if (p < 0) return x;
	else return p = find(p);
}

void weightedUnion(int x, int y) {
	x = find(x); y = find(y);
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

void init() {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/2887.txt", "r", stdin);
	memset(parent, -1, sizeof(parent));
	cin >> N;

	for (int i = 0; i < N; i++) {
		int co[3];
		for (int j = 0; j < 3; j++) {
			cin >> co[j];
			coIDX[j][i] = { co[j], i };
		}
	}

	for (int i = 0; i < 3; i++)
		sort(coIDX[i], coIDX[i] + N);

	for (int i = 0; i < 3; i++) {
		for (int j = 1; j < N; j++) {
			// <cost, <u, v>>
			int cost = abs(coIDX[i][j].first - coIDX[i][j - 1].first);
			int u = coIDX[i][j - 1].second;
			int v = coIDX[i][j].second;
			edge.push({ -cost, {u, v} });
		}
	}
}

int main(void) {
	init();		

	int cost = 0;
	for (int i = 0; i < N - 1; i++) {
		while (find(edge.top().second.first) == find(edge.top().second.second)) edge.pop();
		pair<int, pii> t = edge.top(); edge.pop();
		cost += (-t.first);
		weightedUnion(t.second.first, t.second.second);
	}
	cout << cost;
	
}