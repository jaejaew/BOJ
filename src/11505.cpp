#define MAXN	1'000'100
#define MOD		1'000'000'007
#define UPD		1
#define RNG		2

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef unsigned long long ll;

ll A[MAXN];

int N, M, K;

class Segtree {
public:
	ll data[MAXN << 1];

	void init() {
		for (int i = 0; i < N; i++)
			data[i + N] = A[i];

		for (int i = N - 1; i != 0; i--)
			data[i] = (data[i << 1] * data[i << 1 | 1]) % MOD;
	}
	void update(int i, ll x) {
		ll old = data[i += N];
		data[i] = x;

		while (i >>= 1) {
			data[i] = (data[i << 1] * data[i << 1 | 1]) % MOD;
		}
	}
	ll range(int l, int r) {
		ll ret = 1LL;
		for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
			if (l & 1) ret = (ret * data[l++]) % MOD;
			if (r & 1) ret = (ret * data[--r]) % MOD;
		}
		return ret;
	}
} segtree;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/11505.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	segtree.init();

	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		switch (a) {
		case UPD: segtree.update(b - 1, c); break;
		case RNG: cout << segtree.range(b - 1, c) << "\n"; break;
		}
	}
}