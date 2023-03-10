#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll A, B, C;
ll power(ll x, ll p) {
	if (p == 0) return 1;
	if (p == 1) return x;

	ll ret = power(x, p >> 1);
	ret *= ret;
	ret %= C;
	if (p & 1) ret *= x;
	ret %= C;

	return ret;
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/1629.txt", "r", stdin);

	cin >> A >> B >> C;
	cout << power(A, B);
}