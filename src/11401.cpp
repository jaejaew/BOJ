#define DIV	1'000'000'007

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll N, K;

ll power(int k, int p) {
	if (p == 0) return 1;

	ll x = power(k, p >> 1);
	x *= x;
	x %= DIV;
	if (p & 1) x = x *= k;
	return x % DIV;
}
int comb(int n, int k) {
	ll tmp = 1, kp = 1;
	for (int i = n; i != n - k; --i) tmp = (tmp * i) % DIV;
	for (int i = k; i != 0; --i) kp = (kp * i) % DIV;
	return (tmp * power(kp, DIV - 2)) % DIV;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/11401.txt", "r", stdin);
	cin >> N >> K;
	if (K > N - K) K = N - K;

	cout << comb(N, K) << '\n';
}