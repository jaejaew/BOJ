#define MAXN	1010

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int S[MAXN];
int dp[MAXN];
int main(void) {
	freopen("input.txt", "r", stdin);
	int N;
	int max = 0;
	memset(S, 0, sizeof(S));
	fill(&dp[0], &dp[MAXN], 1);
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> S[i];

	for (int i = 1; i < N; i++)
		for (int j = 0; j < i; j++)
			if (S[j] < S[i])
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
	for (int i = 0; i < N; i++)
		if (dp[i] > max)
			max = dp[i];

	cout << max;
}