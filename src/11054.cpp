#define MAXN 1010

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N;
int dp[MAXN];
int rdp[MAXN];
int A[MAXN];
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/11054.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		dp[i] = rdp[i] = 1;
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < i; j++)
			if (A[j] < A[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;

	for (int i = N - 1; i >= 0; i--)
		for (int j = N - 1; j > i; j--)
			if (A[i] > A[j] && rdp[i] < rdp[j] + 1)
				rdp[i] = rdp[j] + 1;

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = max(ans, dp[i] + rdp[i]);

	cout << --ans;
}