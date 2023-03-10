#define MAXN	100'100


#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, Q;
ll A[MAXN];

class SegTree {
public:
	ll data[MAXN << 1];

	void init() {
		for (int i = 0; i < N; i++)
			data[i + N] = A[i];
		for (int i = N - 1; i != 0; --i)
			data[i] = data[i << 1] + data[i << 1 | 1];
	}

	void update(int i, ll x) {
		data[i += N] = x;
		while (i >>= 1)
			data[i] = data[i << 1] + data[i << 1 | 1];
	}

	ll range(int l, int r) {
		// sum of [l, r)
		ll ret = 0LL;
		for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
			if (l & 1) ret += data[l++];
			if (r & 1) ret += data[--r];
		}
		return ret;
	}
} segtree;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/1275.txt", "r", stdin);

	cin >> N >> Q;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	segtree.init();

	for (int i = 0; i < Q; i++) {
		int x, y, a;
		ll b;
		cin >> x >> y >> a >> b;

		if (x > y) swap(x, y);
		cout << segtree.range(x - 1, y) << "\n";
		segtree.update(a - 1, b);
	}
}