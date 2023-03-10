#define MAXN 8

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long ll;

int N, M;
int mat[MAXN][MAXN];
int tmp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int num_wall;
vector<pair<int, int>> space;
vector<pair<int, int>> virus;
queue<pair<int, int>> q;

const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

inline bool canMove(int x, int y) {
	return x >= 0 && x < N&& y >= 0 && y < M;
}
int bfs(vector<pair<int, int>>& v) {
	int ret = 0;
	memset(visited, 0, sizeof(visited));

	for (const pair<int, int>& vi : virus) {
		q.push({ vi.first, vi.second });
		visited[vi.first][vi.second] = true;
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();	ret++;
		
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (canMove(nx, ny) && !visited[nx][ny] && tmp[nx][ny] == 0) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
	return ret;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/14502.txt", "r", stdin);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mat[i][j];
			tmp[i][j] = mat[i][j];
			if (mat[i][j] == 0) space.push_back({ i, j });
			if (mat[i][j] == 1) num_wall++;
			if (mat[i][j] == 2) virus.push_back({ i, j });
		}
	}

	int ans = (1<<30);
	for (int one = 0; one < space.size(); one++) {
		for (int two = one + 1; two < space.size(); two++) {
			for (int thr = two + 1; thr < space.size(); thr++) {
				vector<int> v = { one, two, thr };
				for (const int& e : v)
					tmp[space[e].first][space[e].second] = 1;

				int tmp_ans = 0;
				tmp_ans = bfs(virus);
				ans = min(ans, tmp_ans);

				for (const int& e : v)
					tmp[space[e].first][space[e].second] = 0;
			}
		}
	}

	cout << (N * M) - ans - (num_wall + 3);
}