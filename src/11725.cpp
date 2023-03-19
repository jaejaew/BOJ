#define MAXN 100100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>

using namespace std;

typedef long long ll;

int N;
int parent[MAXN];
bool visited[MAXN];
queue<int> q;
vector<int> edges[MAXN];
stack<int> st;
void bfs() {
	visited[1] = true;
	q.push(1);

	while (!q.empty()) {
		int v = q.front();	q.pop();
		for (int e : edges[v]) {
			if (!visited[e]) {
				visited[e] = true;
				q.push(e);
				parent[e] = v;
			}
		}
	}
}

void dfs() {
	visited[1] = true;
	st.push(1);

	while (!st.empty()) {
		int v = st.top();	st.pop();
		for (int e : edges[v]) {
			if (!visited[e]) {
				visited[e] = true;
				st.push(e);
				parent[e] = v;
			}
		}
	}
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int u, v;	cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs();
//	bfs();

	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}