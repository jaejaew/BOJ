#define MAXEDG	100'100
#define MAXVTX	10'100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long ll;

int V, E;
int parent[MAXVTX];
bool visited[MAXVTX];
vector<pair<int, int>> vertex[MAXVTX];

struct Edge {
	int u;
	int v;
	int cost;
	void init(int _u, int _v, int _c) {
		u = _u, v = _v, cost = _c;
	}
	const bool operator<(const Edge& e) {
		return cost < e.cost;
	}
	const bool operator>(const Edge& e) {
		return cost > e.cost;
	}
} edge[MAXEDG];

void sortEdge() {
	sort(edge, edge + MAXEDG);
}

int find(int x) {
	int& p = parent[x];
	if (p < 0) return x;
	return p = find(p);
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

void Krulskal_init() {
	memset(parent, -1, sizeof(parent));
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		edge[i].init(u, v, c);
	}
}
int Kruskal() {		//	O(ElogE)
	Krulskal_init();
	int edgeIDX = 0;
	int cost = 0;

	sortEdge();
	for (int i = 0; i < V - 1; i++) {
		while (find(edge[edgeIDX].u) == find(edge[edgeIDX].v)) edgeIDX++;
		weightedUnion(edge[edgeIDX].u, edge[edgeIDX].v);
		cost += edge[edgeIDX].cost;
	}
	return cost;
}

void Prim_init() {
	memset(visited, 0, sizeof(visited));
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		vertex[u].push_back({ v, c });
		vertex[v].push_back({ u, c });
	}
}
int Prim() {	//	O(ElogV)
	Prim_init();
	priority_queue<pair<int, int>> q;	//	<-cost, dst>
	int cost = 0;

	visited[1] = true;
	for (int i = 0; i < vertex[1].size(); i++)
		q.push({ -vertex[1][i].second, vertex[1][i].first });
	
	for (int v = 0; v < V - 1; v++) {
		while (visited[q.top().second]) q.pop();
		pair<int, int> t = q.top(); q.pop();
		int nv = t.second;
		int nc = -t.first;
		cost += nc;

		visited[nv] = true;
		for(int i=0; i<vertex[nv].size(); i++)
			q.push({ -vertex[nv][i].second, vertex[nv][i].first });
	}
	return cost;
}


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/1197.txt", "r", stdin);


//	cout << Kruskal();
	cout << Prim();
	

}