#define MAXN	1'000'100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll A[MAXN];
int N, Q;

class SegTree {
public:
	ll data[MAXN << 1];

	void init() {
		memset(data, 0, sizeof(data));
	}

	void update(int i, ll x) {
		data[i += N] += x;
		while (i >>= 1)
			data[i] = data[i << 1] + data[i << 1 | 1];
	}

	ll range(int l, int r) {
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
		freopen("./input/12837.txt", "r", stdin);

	cin >> N >> Q;

	segtree.init();
	for (int i = 0; i < Q; i++) {
		ll cmd, p, q;
		cin >> cmd >> p >> q;
		if (cmd == 1)
			segtree.update(p - 1, q);
		else
			cout << segtree.range(p - 1, q) << "\n";
	}

}