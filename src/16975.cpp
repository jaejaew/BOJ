#define MAXN	100100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll A[MAXN];
class SegTree {
private:
	ll tree[MAXN << 2];
	ll lazy[MAXN << 2];

	void update_lazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			tree[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

public:
	void init(int node, int start, int end) {
		if (start == end) {
			tree[node] = A[start];
			return;
		}
		int mid = start + ((end - start) >> 1);
		init(node << 1, start, mid);
		init(node << 1 | 1, mid + 1, end);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	void update_range(int node, int start, int end, int left, int right, ll x) {
		update_lazy(node, start, end);
		if (left > end || right < start) return;
		if (left <= start && end <= right) {
			tree[node] += (end - start + 1) * x;
			if (start != end) {
				lazy[node << 1] += x;
				lazy[node << 1 | 1] += x;
			}
			return;
		}
		int mid = start + ((end - start) >> 1);
		update_range(node << 1, start, mid, left, right, x);
		update_range(node << 1 | 1, mid + 1, end, left, right, x);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	ll query(int node, int start, int end, int x) {
		update_lazy(node, start, end);
		if (start == end) return tree[node];
		int mid = start + ((end - start) >> 1);
		return (x <= mid ? query(node << 1, start, mid, x) : query(node << 1 | 1, mid + 1, end, x));
	}
} segtree;

int N, M;
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/16975.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	segtree.init(1, 1, N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int cmd;	cin >> cmd;
		if (cmd == 1) {
			ll i, j, k;	cin >> i >> j >> k;
			segtree.update_range(1, 1, N, i, j, k);
		}
		else {
			int x;	cin >> x;
			cout << segtree.query(1, 1, N, x) << '\n';
		}
	}
}