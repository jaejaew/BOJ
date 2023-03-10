
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

struct Line {
	pair<ll, ll> p1, p2;
} line[2];

int ccw(pair<ll, ll>& a, pair<ll, ll>& b, pair<ll, ll>& c) {
	ll vec1 = a.first * b.second + b.first * c.second + c.first * a.second;
	ll vec2 = a.second * b.first + b.second * c.first + c.second * a.first;
	if (vec1 - vec2 < 0) return -1;
	else if (vec1 - vec2 > 0) return 1;
	else return 0;
}

bool lineIntersects() {
	int abc = ccw(line[0].p1, line[0].p2, line[1].p1);
	int abd = ccw(line[0].p1, line[0].p2, line[1].p2);
	int cda = ccw(line[1].p1, line[1].p2, line[0].p1);
	int cdb = ccw(line[1].p1, line[1].p2, line[0].p2);

	if (abc * abd == 0 && cda * cdb == 0) {
		if (line[0].p1 > line[0].p2)	swap(line[0].p1, line[0].p2);
		if (line[1].p1 > line[1].p2)	swap(line[1].p1, line[1].p2);
		return line[0].p1 <= line[1].p2 && line[1].p1 <= line[0].p2;
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
//	freopen("./input/17386.txt", "r", stdin);

	for (int i = 0; i < 2; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		line[i].p1 = { x1, y1 };
		line[i].p2 = { x2, y2 };
	}

	cout << (lineIntersects() ? 1 : 0);

}