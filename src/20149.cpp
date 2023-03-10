#define ERR		1e-9

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

struct Line {
	pair<double, double> p1, p2;
} line[2];

int ccw(pair<double, double>& a, pair<double, double>& b, pair<double, double>& c) {
	double vec1 = a.first * b.second + b.first * c.second + c.first * a.second;
	double vec2 = a.second * b.first + b.second * c.first + c.second * a.first;

	if (abs(vec1 - vec2) < ERR) return 0;
	else if (vec1 < vec2) return -1;
	else return 1;
}
bool lineIntersects(Line& l1, Line& l2) {
	pair<double, double>& a = l1.p1, b = l1.p2, c = l2.p1, d = l2.p2;
	int abc = ccw(a, b, c), abd = ccw(a, b, d);
	int cda = ccw(c, d, a), cdb = ccw(c, d, b);

	if (abc * abd == 0 && cda * cdb == 0) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return a <= d && c <= b;
	}
	return abc * abd <= 0 && cda * cdb <= 0;
}

int main(void) {
//	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/20149.txt", "r", stdin);

	int N = 2;
	for (int i = 0; i < N; i++) {
		double x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		line[i].p1 = { x1, y1 };
		line[i].p2 = { x2, y2 };
	}

	bool flag = lineIntersects(line[0], line[1]);
	cout << (flag ? 1 : 0) << '\n';
	if (flag) {
		double m[2], c[2];
		pair<double, double> ans;
		double ix, iy;
		for (int i = 0; i < 2; i++) {
			m[i] = (line[i].p2.second - line[i].p1.second) \
				/ (line[i].p2.first - line[i].p1.first);
			c[i] = line[i].p2.second - line[i].p2.first * m[i];
		}
		if (m[0] == m[1]) {
			if (line[0].p1 > line[0].p2) swap(line[0].p1, line[0].p2);
			if (line[1].p1 > line[1].p2) swap(line[1].p1, line[1].p2);
			if (line[0].p2 == line[1].p1) ans = line[0].p2;
			else if (line[0].p1 == line[1].p2) ans = line[0].p1;			
		}
		else {
			ans.first = ix = -((c[1] - c[0]) / (m[1] - m[0]));
			ans.second = iy = m[0] * ix + c[0];
		}
		
		printf("%.11lf %.11lf", ans.first, ans.second);
	}
	

}