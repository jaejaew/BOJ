#define MAXN	505

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int board[MAXN][MAXN];
int dp[MAXN][MAXN];
bool visited[MAXN][MAXN];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int N, M;
int cnt;

inline bool canMove(int i, int j) {
	return (i >= 0) && (i < M) && (j >= 0) && (j < N);
}
int getDist(int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	else if (x == 0 && y == 0) return 1;
	dp[x][y] = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (canMove(nx, ny) && board[x][y] < board[nx][ny])
			dp[x][y] += getDist(nx, ny);
	}
	return dp[x][y];
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/1520.txt", "r", stdin);
	memset(dp, -1, sizeof(dp));

	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	cout << getDist(M - 1, N - 1);
}