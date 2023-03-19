#define MAXN	1010

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N;
int ans;
int house[MAXN][3];
int cost[MAXN][3];
int range_sum[MAXN];	//	range sum [i:]


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/1149.txt", "r", stdin);

	cin >> N;
	ans = (1LL << 31) - 1;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			cin >> house[i][j];


	for (int i = 1; i <= N; i++) {
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + house[i][0];
		cost[i][1] = min(cost[i - 1][2], cost[i - 1][0]) + house[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + house[i][2];
	}

	for (int i = 0; i < 3; i++)
		ans = min(ans, cost[N][i]);

	cout << ans;
}