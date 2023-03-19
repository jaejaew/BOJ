/* 16%에서 틀림 대체 왜???? */

#define MAXN	3003

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N;
ll parent[MAXN];

struct Line {
	pair<ll, ll> p1, p2;
} line[MAXN];


ll ccw(const pair<ll, ll>& a, const pair<ll, ll>& b, const pair<ll, ll>& c) {
	ll vec1 = a.first * b.second + b.first * c.second + c.first * a.second;
	ll vec2 = a.second * b.first + b.second * c.first + c.second * a.first;
	if (vec1 - vec2 < 0) return -1;
	else if (vec1 - vec2 > 0) return 1;
	else return 0;
}

bool lineIntersects(Line& l1, Line& l2) {
	pair<ll, ll>& a = l1.p1, b = l1.p2;
	pair<ll, ll>& c = l2.p1, d = l2.p2;
	int abc = ccw(a, b, c), abd = ccw(a, b, d);
	int cda = ccw(c, d, a), cdb = ccw(c, d, b);

	if (abc * abd == 0 && cda * cdb == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return a <= d && c <= b;
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

ll find(int x) {
	ll& p = parent[x];
	if (p < 0) return x;
	return p = find(p);
}
void weightedUnion(int x, int y) {
	x = find(x);	y = find(y);
	if (x == y) return;

	if (-parent[x] > -parent[y]) {
		parent[x] += parent[y];
		parent[y] = x;
	}
	else {
		parent[y] += parent[x];
		parent[x] = y;
	}
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/2162.txt", "r", stdin);
	memset(parent, -1, sizeof(parent));

	cin >> N;


	for (int i = 0; i < N; i++) {
		ll x1, y1, x2, y2;	cin >> x1 >> y1 >> x2 >> y2;
		line[i].p1 = { x1, y1 };
		line[i].p2 = { x2, y2 };
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (lineIntersects(line[i], line[j]))
				weightedUnion(i, j);
		}
	}


	ll size = 0, _max = 0;
	for (int i = 0; i < N; i++)
		if (parent[i] > 0) parent[i] = find(parent[i]);

	for (int i = 0; i < N; i++) {
		if (parent[i] < 0) {
			++size;
			_max = max(_max, -parent[i]);
		}
	}
	cout << size << '\n';
	cout << _max << '\n';

}