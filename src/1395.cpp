#define MAXN	100100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

class SegTree {
private:
	int tree[MAXN << 2];
	int lazy[MAXN << 2];
public:
	void init(int node, int start, int end) {
		if (start == end) tree[node] = 0;
		else {
			int mid = start + ((end - start) >> 1);
			init(node << 1, start, mid);
			init(node << 1 | 1, mid + 1, end);
			tree[node] = tree[node << 1] + tree[node << 1 | 1];
		}
	}
	void update_lazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			if(lazy[node] & 1)
				tree[node] = (end - start + 1) - tree[node];
			if (start != end) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void update_range(int node, int start, int end, int left, int right) {
		update_lazy(node, start, end);
		if (left > end || right < start) return;
		if (left <= start && end <= right) {
			tree[node] = (end - start + 1) - tree[node];
			if (start != end) {
				lazy[node << 1]++;
				lazy[node << 1 | 1]++;
			}
			return;
		}
		int mid = start + ((end - start) >> 1);
		update_range(node << 1, start, mid, left, right);
		update_range(node << 1 | 1, mid + 1, end, left, right);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}

	int query(int node, int start, int end, int left, int right) {
		update_lazy(node, start, end);
		if (left > end || right < start) return 0;
		if (left <= start && end <= right) return tree[node];
		int mid = start + ((end - start) >> 1);
		int lsum = query(node << 1, start, mid, left, right);
		int rsum = query(node << 1 | 1, mid + 1, end, left, right);
		return lsum + rsum;
	}
} segtree;
int N, M;
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/1395.txt", "r", stdin);

	cin >> N >> M;
	segtree.init(1, 1, N);

	for (int i = 0; i < M; i++) {
		int o, s, t;
		cin >> o >> s >> t;
		if (o == 0) segtree.update_range(1, 1, N, s, t);
		else cout << segtree.query(1, 1, N, s, t) << '\n';
	}
}