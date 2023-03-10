#define MAXN	1'000'100

#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>

using namespace std;

int S[MAXN];
int dp[MAXN];
int LIS[MAXN];
stack<int> st;
int main(void) {
	freopen("./input/12015.txt", "r", stdin);
	int N;
	int max = 0;
	memset(S, 0, sizeof(S));

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> S[i];

	int len = 1;
	LIS[0] = S[0];
	dp[0] = 1;

	for (int i = 0; i < N; i++) {
		if (S[i] > LIS[len - 1]) {
			LIS[len++] = S[i];
			dp[i] = len;
			continue;
		}
		int idx = lower_bound(LIS, LIS + len, S[i]) - LIS;
		LIS[idx] = S[i];
		dp[i] = idx + 1;
	}

	cout << len;
	for (int i = N - 1; i >= 0; i--) {
		if (dp[i] == len) {
			st.push(i);
			len--;
		}
	}

	cout << '\n';
	while (!st.empty()) {
		cout << S[st.top()] << ' ';
		st.pop();
	}
}