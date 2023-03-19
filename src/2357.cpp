#define MAXN	100'100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N, M;
int A[MAXN];
class SegTree {
public:
	int data[MAXN << 1];
	bool isMax;

	void init(bool _isMax) {
		isMax = _isMax;
		for (int i = 0; i < N; i++)
			data[i + N] = A[i];
		for (int i = N - 1; i != 0; i--)
			data[i] = _isMax ? max(data[i << 1], data[i << 1 | 1]) : min(data[i << 1], data[i << 1 | 1]);

	}
	
	int range(int l, int r) {
		int ret = isMax ? 0 : (1LL << 30) - 1;
		for (l += N, r += N; l != r; l >>= 1, r >>= 1) {
			if (l & 1)
				if (isMax) ret = max(ret, data[l++]);
				else ret = min(ret, data[l++]);
			if (r & 1)
				if (isMax) ret = max(ret, data[--r]);
				else ret = min(ret, data[--r]);
		}
		return ret;
	}

} minsegT, maxsegT;

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/2357.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	minsegT.init(false);	maxsegT.init(true);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << minsegT.range(a - 1, b) << "\n";// << ' ' << maxsegT.range(a - 1, b) << "\n";
	}
}