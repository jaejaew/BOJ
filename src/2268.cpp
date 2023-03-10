#define MAXN	1'000'100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int A[MAXN];
int N, M;

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
		while(i>>=1)	
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
		freopen("./input/2268.txt", "r", stdin);

	cin >> N >> M;
	segtree.init();

	for (int q = 0; q < M; q++) {
		ll cmd, i, j;
		cin >> cmd >> i >> j;
		if (cmd == 0) {
			if (i > j) swap(i, j);
			cout << segtree.range(i - 1, j) << "\n";
		}
		else
			segtree.update(i - 1, j);
	}
}