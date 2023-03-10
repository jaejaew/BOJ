#define MAXN	1010

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, M;
int mat[MAXN][MAXN];
int res;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

class Queue {
public:
	pair<int, int> data[MAXN*MAXN];
	int l, r;

	void init() {
		l = r = 0;
	}
	void push(int x, int y) {
		data[r++] = { x, y };
	}
	pair<int, int> top() {
		return data[l];
	}
	void pop() {
		l++;
	}
	bool empty() {
		return l == r;
	}
} q[2];

inline bool canMove(int x, int y) {
	return x >= 0 && y >= 0 && x < N && y < M;
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/7576.txt", "r", stdin);

	cin >> M >> N;
	q[0].init(); q[1].init();
	res = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;
			mat[i][j] = tmp;
			if (tmp == 1) q[0].push(i, j);
			if (tmp == -1 || tmp == 1) res--;
		}
	}

	int cnt = -1, i = 0;
	while (!q[i].empty() || !q[i ^ 1].empty()) {
		cnt++;
		while (!q[i].empty()) {
			pair<int, int> p = q[i].top();
			q[i].pop();
			int x = p.first, y = p.second;
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (canMove(nx, ny) && mat[nx][ny] == 0) {
					mat[nx][ny] = 1;
					q[i ^ 1].push(nx, ny);
					--res;
				}
			}
		}
		i ^= 1;
	}

	cout << ((res == 0) ? cnt : (-1)) << '\n';
}