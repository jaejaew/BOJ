#define MAXN 10100

#include<iostream>
#include<cstring>
#include<math.h>

using namespace std;

bool era[MAXN];

void check(int n) {
	int r = n / 2;
	while (r > 0) {
		if (era[r]) {
			/* r is prime number */
			if (era[n - r]) {
				cout << r << ' ' << n - r << '\n';
				return;
			}
		}
		r--;
	}
}

int main(void) {
	freopen("./input/9020.txt", "r", stdin);
	int T, N;

	memset(era, true, sizeof(era));
	era[0] = era[1] = false;

	for (int i = 2; i < MAXN; i++) {
		if (era[i] == false) 
			continue;
		for (int j = i * i; j < MAXN; j += i)
			era[j] = false;
	}
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N;
		check(N);
	}

	return 0;
}