#define MAXN 55

#include<iostream>

using namespace std;

bool a[MAXN][MAXN];
bool visited[MAXN][MAXN];

void init(int M, int N, int K) {
	int r, c;
	memset(a, 0, sizeof(a));	memset(visited, 0, sizeof(a));
	for (int i = 0; i < K; i++) {
		cin >> r >> c;
		a[r][c] = true;
	}
		
}

void dfs(int r, int c) {
	static int dx[4] = { 0, 1, 0, -1 };
	static int dy[4] = { 1, 0, -1, 0 };
	
	int nrow, ncol;
	visited[r][c] = true;
	for (int d = 0; d < 4; d++) {
		nrow = r + dx[d];	ncol = c + dy[d];
		if (a[nrow][ncol] && !visited[nrow][ncol])
			dfs(nrow, ncol);
	}
}
int run(int M, int N) {
	int cnt = 0;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (a[i][j] && !visited[i][j]) {
				dfs(i, j);
				cnt++;
			}
	return cnt;
}
int main(void) {
	freopen("input.txt", "r", stdin);
	int T, M, N, K;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> M >> N >> K;
		init(M, N, K);
		cout << run(M, N) << endl;
	}
}