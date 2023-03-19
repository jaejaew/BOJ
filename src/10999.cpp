#define MAXN	1'000'100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

ll A[MAXN];
int N, M, K;

class SegTree {
private:
	ll data[MAXN << 2];
	ll lazy[MAXN << 2];
public:
	void init(int node, int start, int end) {
		if (start == end)	//	leaf
			data[node] = A[start];
		else {
			int mid = start + ((end - start) >> 1);
			init(node << 1, start, mid);
			init(node << 1 | 1, mid + 1, end);
			data[node] = data[node << 1] + data[node << 1 | 1];
		}
	}

	void update_tree(int node, int start, int end, int index, const ll diff) {
		if (index < start || index > end) return;
		data[node] += diff;
		if (start != end) {
			int mid = start + ((end - start) >> 1);
			update_tree(node << 1, start, mid, index, diff);
			update_tree(node << 1 | 1, mid + 1, end, index, diff);
		}
	}
	void update(int index, ll val) {
		ll diff = val - A[index];
		A[index] = val;
		update_tree(1, 1, N, index, diff);
	}

	void update_lazy(int node, int start, int end) {
		if (lazy[node] != 0) {
			data[node] += (end - start + 1) * lazy[node];
			if (start != end) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void update_range(int node, int start, int end, const int left, const int right, const ll diff) {
		update_lazy(node, start, end);
		if (left > end || right < start) return;
		if (left <= start && end <= right) {
			data[node] += (end - start + 1) * diff;
			if (start != end) {
				lazy[node << 1] += diff;
				lazy[node << 1 | 1] += diff;
			}
			return;
		}
		int mid = start + ((end - start) >> 1);
		update_range(node << 1, start, mid, left, right, diff);
		update_range(node << 1 | 1, mid + 1, end, left, right, diff);
		data[node] = data[node << 1] + data[node << 1 | 1];
	}

	ll query(int node, int start, int end, const int left, const int right) {
		// sum of [left, right]
		update_lazy(node, start, end);
		if (left > end || right < start) return 0;
		if (left <= start && end <= right) return data[node];
		int mid = start + ((end - start) >> 1);
		ll lsum = query(node << 1, start, mid, left, right);
		ll rsum = query(node << 1 | 1, mid + 1, end, left, right);
		return lsum + rsum;
	}

	ll getSum(const int left, const int right) {
		return query(1, 1, N, left, right);
	}
} segtree;


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/10999.txt", "r", stdin);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	segtree.init(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			segtree.update_range(1, 1, N, b, c, d);
		}
		else cout << segtree.getSum(b, c) << '\n';
	}
	/*for (int i = 0; i < M + K; i++) {
		int a, b, c;	ll d;
		cin >> a >> b >> c;

		if (a == 1) {
			cin >> d;
			segtree.update(b - 1, c, d);
		}
		else
			cout << segtree.range(b - 1, c) << "\n";
	}*/

	return 0;
}