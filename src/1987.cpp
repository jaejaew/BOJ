#define MAXN	20
#define OFFSET	'A'
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int R, C;
char board[MAXN][MAXN];
int dist;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
ll ALL_VISITED = (1LL << 26) - 1;
inline bool canMove(int i, int j) {
	return i >= 0 && i < R && j >= 0 && j < C;
}

void dfs(int x, int y, ll visited, int level) {
	if (level > dist) dist = level;
	if (visited == ALL_VISITED) return;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (canMove(nx, ny)) {
			ll mark = (1 << (board[nx][ny] - OFFSET));
			if (!(visited & mark)) {
				ll next_visited = visited | mark;
				dfs(nx, ny, next_visited, level + 1);
			}
		}
	}

}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/1987.txt", "r", stdin);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> board[i][j];

	ll visited = 1 << (board[0][0] - OFFSET);
	dfs(0, 0, visited, 0);
	cout << dist + 1;
}