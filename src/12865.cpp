#define MAXN	10100
#define MAXM	10010

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long ll;

struct Item {
	int weight;
	int value;
} item[MAXN];
int itemCnt;
int N, K;

int dp[MAXN][MAXM];

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int w, v, k;
		cin >> w >> v >> k;
		for (int j = 1; k > 0; j <<= 1) {
			int jx = min(j, k);
			itemCnt++;
			item[itemCnt].weight = w * jx;
			item[itemCnt].value = v * jx;
			k -= jx;
		}
	}

	for (int i = 1; i <= itemCnt; i++) {
		for (int k = 0; k <= K; k++) {
			if (k < item[i].weight) dp[i][k] = dp[i - 1][k];
			else dp[i][k] = max(dp[i - 1][k], dp[i - 1][k - item[i].weight] + item[i].value);
		}
	}
	cout << dp[itemCnt][K];
}