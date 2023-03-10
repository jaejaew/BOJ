#define MAXN 8
#include<iostream>
using namespace std;

int N, M;
int path[MAXN];
void dfs(int level) {
	if (level == M) {
		for (int i = 0; i < M; i++)
			cout << path[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = level==0 ? 1 : path[level-1]; i <= N; i++) {
		path[level] = i;
		dfs(level + 1);
	}
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	cin >> N >> M;
	dfs(0);
}