#define MAXN	500'500

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, M;
int A[MAXN];

class SegTree {
private:
	int tree[MAXN << 2];
	int lazy[MAXN << 2];
public:
	void init(int node, int start, int end) {
		if (start == end) {
			tree[node] = A[start];
			return;
		}
		else {
			int mid = start + ((end - start) >> 1);
			init(node << 1, start, mid);
			init(node << 1 | 1, mid + 1, end);
			tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
		}
	}

	void update_lazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			if ((end - start + 1) & 1) tree[node] ^= lazy[node];
			if (start != end) {
				lazy[node << 1] ^= lazy[node];
				lazy[node << 1 | 1] ^= lazy[node];
			}
			lazy[node] = 0;
			return;
		}
	}

	void update_range(int node, int start, int end, int left, int right, int k) {
		update_lazy(node, start, end);
		if (left > end || right < start) return;
		if (left <= start && end <= right) {
			if ((end - start + 1) & 1) tree[node] ^= k;
			if (start != end) {
				lazy[node << 1] ^= k;
				lazy[node << 1 | 1] ^= k;
			}
			return;
		}
		int mid = start + ((end - start) >> 1);
		update_range(node << 1, start, mid, left, right, k);
		update_range(node << 1 | 1, mid + 1, end, left, right, k);
		tree[node] = tree[node << 1] ^ tree[node << 1 | 1];
	}

	int query(int node, int start, int end, int left, int right) {
		update_lazy(node, start, end);
		if (left > end || right < start) return 0;
		if (left <= start && end <= right) return tree[node];
		int mid = start + ((end - start) >> 1);
		int lxor = query(node << 1, start, mid, left, right);
		int rxor = query(node << 1 | 1, mid + 1, end, left, right);
		return lxor ^ rxor;
	}

	int query(int node, int start, int end, int x) {
		update_lazy(node, start, end);
		if (start == end) return tree[node];
		int mid = start + ((end - start) >> 1);
		return (x <= mid ? query(node << 1, start, mid, x) : query(node << 1 | 1, mid + 1, end, x));
	}
} segtree;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/14245.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	segtree.init(1, 1, N);

	cin >> M;
	for (int m = 0; m < M; m++) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int i, j, k;	cin >> i >> j >> k;
			segtree.update_range(1, 1, N, i + 1, j + 1, k);
		}
		else {
			int x;	cin >> x;
			cout << segtree.query(1, 1, N, x + 1) << '\n';
			//	int i, j;	cin >> i >> j;
			//	cout << segtree.query(1, 1, N, i + 1, j + 1) << '\n';
		}
	}
}