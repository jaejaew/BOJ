#define MAXN	808
#define INF		(1<<30)
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
using namespace std;

typedef long long ll;

vector<pair<ll, int>> edges[MAXN];
int N, E;

ll getDist(int s, int e) {
	priority_queue<pair<ll, int>> pq;
	ll dist[MAXN];
	memset(dist, 0, sizeof(dist));
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	dist[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()) {
		int cost = -pq.top().first, now = pq.top().second;
		pq.pop();
		if (cost > dist[now]) continue;

		for (const pair<int, int>& p : edges[now]) {
			if (dist[p.second] > dist[now] + p.first) {
				dist[p.second] = dist[now] + p.first;
				pq.push({ -dist[p.second], p.second });
			}
		}
	}

	return dist[e];
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/1504.txt", "r", stdin);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int u, v, c;	cin >> u >> v >> c;
		edges[u].push_back({ c, v });
		edges[v].push_back({ c, u });
	}

	int v1, v2; cin >> v1 >> v2;
	ll d12 = getDist(v1, v2);
	ll d12n = getDist(1, v1) + d12 + getDist(v2, N);
	ll d21n = getDist(1, v2) + d12 + getDist(v1, N);
	ll ans = min(d12n, d21n);
	if (ans >= INF) ans = -1;
	cout << ans;
}