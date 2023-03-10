#define MAXN 100100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef long long ll;

struct Coord {
	ll x, y;
} coord[MAXN], band[MAXN];
ll N;
struct compX {
	const bool operator()(const Coord& a, const Coord& b) const {
		return a.x < b.x;
	}
};

struct compY {
	const bool operator()(const Coord& a, const Coord& b) const {
		return a.y < b.y;
	}
};

inline ll square(ll a) {
	return a * a;
}

inline ll getDist(Coord& p1, Coord& p2) {
	return square(p1.x - p2.x) + square(p1.y - p2.y);
}

ll bruteForce(Coord P[], int s, int e) {
	ll ret = 1LL << 30;
	for (int i = s; i < e; i++)
		for (int j = i + 1; j < e; j++)
			ret = min(ret, getDist(P[i], P[j]));
	return ret;
}
ll closest(Coord* P, int s, int e) {
	if (e - s <= 3)
		return bruteForce(P, s, e);

	int mid = s + ((e - s) >> 1);
	ll d = min(closest(P, s, mid), closest(P, mid, e));
	vector<Coord> v;

	for (int i = s; i < e; i++)
		if (square(P[i].x - P[mid].x) <= d)
			v.push_back(P[i]);
	sort(v.begin(), v.end(), compY());

	for (int i = 0; i < v.size(); i++)
		for (int j = i+1; j < v.size() && j < i + 7; j++)
			d = min(d, getDist(v[i], v[j]));
	return d;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/2261.txt", "r", stdin);

	cin >> N;
	for (ll i = 0; i < N; i++)
		cin >> coord[i].x >> coord[i].y;

	sort(coord, coord + N, compX());
	cout << closest(coord, 0, N);

}