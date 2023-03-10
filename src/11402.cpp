/* Lucas Thm */

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll N, K, M;

ll power(ll k, ll p) {
	if (p == 0) return 1;

	ll x = power(k, p >> 1) % M;
	x *= x;
	x %= M;
	if (p & 1) x = x *= (k % M);
	return x % M;
}

ll comb(ll n, ll k) {
	ll tmp = 1LL, kp = 1LL;
	for (ll i = n; i != n - k; --i) 
		tmp = (tmp * (i % M)) % M;
	for (ll i = k; i != 0; --i) 
		kp = (kp * (i % M)) % M;
	return (tmp * power(kp, M - 2)) % M;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/11401.txt", "r", stdin);
	cin >> N >> K >> M;
	if (K > N - K) K = N - K;

	cout << comb(N, K) << '\n';
}