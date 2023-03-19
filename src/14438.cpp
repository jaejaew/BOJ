#define MAXN	100'100
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;
int N, M;
ll A[MAXN];

class SegTree {
public:
	ll data[MAXN << 1];
	void init() {
		for (int i = 0; i < N; i++)
			data[i + N] = A[i];
		for (int i = N - 1; i != 0; --i)
			data[i] = min(data[i << 1], data[i << 1 | 1]);
	}

	void update(int i, ll x) {
		data[i += N] = x;
		while (i >>= 1)
			data[i] = min(data[i << 1], data[i << 1 | 1]);
	}

	ll range(int l, int r) {
		ll ret = (1 << 30) - 1;
		for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
			if (l & 1) ret = min(ret, data[l++]);
			if (r & 1) ret = min(ret, data[--r]);
		}
		return ret;
	}
} segtree;
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/14438.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	segtree.init();

	cin >> M;
	for (int q = 0; q < M; q++) {
		ll cmd, i, j;
		cin >> cmd >> i >> j;
		if (cmd == 1)
			segtree.update(i - 1, j);
		else
			cout << segtree.range(i - 1, j) << "\n";
	}

}