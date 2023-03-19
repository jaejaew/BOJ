#define MAXN 100'100

#include<iostream>
#include<cstring>

using namespace std;

int S[MAXN];

int main(void) {
//	freopen("./input/input_1912.txt", "r", stdin);
	int T, N, max;
	bool negOnly;
//	cin >> T;

	memset(S, 0, sizeof(S));
//	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		negOnly = true;
		max = (- 1) * MAXN;
		for (int i = 0; i < N; i++) {
			cin >> S[i];
			if (S[i] >= 0) negOnly = false;
			if (S[i] > max) max = S[i];
		}

		if (negOnly) cout << max << endl;
		else {
			max = (-1) * MAXN;

			int start = 0, end, sum;
			while (start < N) {
				sum = S[start];
				if (sum > max) max = sum;

				end = start + 1;
				while (sum >= 0) {
					sum += S[end];
					if (sum > max) max = sum;
					end++;
					if (end >= N) break;
				}
				start = end;
			}
			cout << max << endl;
		}
//	}	
}