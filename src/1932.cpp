#define MAXN 505

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int tri[MAXN][MAXN];
int cache[MAXN][MAXN];
int N;

int getSum(int i, int j) {
	if (cache[i][j] >= 0) return cache[i][j];
	if (i == 0) return cache[i][j] = tri[i][j];

	int lu = j > 0 ? getSum(i - 1, j - 1) : -1;
	int u = getSum(i - 1, j);

	return cache[i][j] = (max(lu, u) + tri[i][j]);
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/1932.txt", "r", stdin);
	memset(cache, -1, sizeof(cache));

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, getSum(N - 1, i));
	cout << ans;

}