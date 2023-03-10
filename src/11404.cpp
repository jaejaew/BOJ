#define MAXN	101
#define INF		(1LL<<60)
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, M;
ll dist[MAXN][MAXN];
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/11404.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dist[i][j] = (i == j ? 0 : INF);

	for (int i = 0; i < M; i++) {
		ll u, v, c;	cin >> u >> v >> c;
		dist[u][v] = min(dist[u][v], c);
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) dist[i][j] = 0;
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

}