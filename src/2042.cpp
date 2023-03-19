/* 구간 합 구하기 */

#define MAXN	1'000'100
#define MAXM	10'100
#define MAXK	10'100
#define POINT	1
#define RANGE	2

#include<iostream>
#include<cstring>
#include<vector>
#include<map>


using namespace std;
typedef long long ll;

int N, M, K;
//	N: # of numbers
//	M: # of point query
//	K: # of range sum query

ll A[MAXN];

class SegTree {
public:
	ll data[MAXN << 1];

	void init() {
		for (int i = 0; i < N; i++) 
			data[N + i] = A[i];
		for (int i = N - 1; i > 0; i--)
			data[i] = data[i << 1] + data[i << 1 | 1];
	}
	void change(int i, ll val) {
		data[i += N] = val;
		while (i >>= 1)
			data[i] = data[i << 1] + data[i << 1 | 1];
	}
	ll range(int l, int r) {
		//	[s, e)
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
	freopen("./input/2042.txt", "r", stdin);
	

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	segtree.init();

	for (int i = 0; i < M + K; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		switch (a) {
		case POINT: segtree.change(b - 1, c); break;
		case RANGE: cout << segtree.range(b - 1, c) << "\n"; break;
		}
	}
	return 0;
}