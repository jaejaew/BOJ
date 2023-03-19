#define MAXN	100
#define INFLEN	999999
#include<iostream>
#include<cstring>

bool maze[MAXN][MAXN];
int len[MAXN][MAXN];
using namespace std;
int N, M;

inline bool canMove(int x, int y) {
	if (x < 0 || x >= N) return false;
	if (y < 0 || y >= M) return false;
	return true;
}

void DFS(int r, int c) {
	const static int dx[4] = { 0, 1, 0, -1 };
	const static int dy[4] = { 1, 0, -1, 0 };
	int nRow, nCol;
	for (int d = 0; d < 4; d++) {
		nRow = r + dx[d];	nCol = c + dy[d];
		if (canMove(nRow, nCol) && maze[nRow][nCol]) {
			if (len[r][c] + 1 < len[nRow][nCol]) {
				len[nRow][nCol] = len[r][c] + 1;
				DFS(nRow, nCol);
			}
		}
	}
}
int main(void) {
//	freopen("./input/2178.txt", "r", stdin);
	string str;
	cin >> N >> M;

	fill(&len[0][0], &len[MAXN - 1][MAXN], INFLEN);
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++)
			maze[i][j] = str[j] == '1' ? true : false;
	}

	len[0][0] = 1;
	DFS(0, 0);
	cout << len[N - 1][M - 1];
	return 0;
}