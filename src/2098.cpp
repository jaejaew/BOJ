#define MAXN	16
#define INF		(99999999.999999)

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<math.h>

using namespace std;

typedef long long ll;

pair<double, double> cities[MAXN];
double W[MAXN][MAXN];
double cache[MAXN][1 << MAXN];
int N;

double dp(int here, int visited) {
	double& ret = cache[here][visited];
	if (ret != 0) return ret;
	if (visited == (1 << N) - 1)
		// all vertices visited, go to start point
		return ret = W[here][0];

	ret = INF;
	for (int there = 1; there < N; there++) {
		if (!(visited & (1 << there))) {
			// can visit there
			int next_visited = visited | (1 << there);
			ret = min(ret, dp(there, next_visited) + W[here][there]);
		}
	}
	return ret;
}

inline double power(double x, int p) {
	return x * x;
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
		freopen("./input/16991.txt", "r", stdin);

//	cin >> N;
	scanf("%d", &N);
	memset(cache, 0, sizeof(cache));

	for (int i = 0; i < N; i++) {
		double x, y;
	//	cin >> x >> y;
		scanf("%lf %lf", &x, &y);
		cities[i] = { x, y };
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) W[i][j] = INF;
			if (i < j)
				W[i][j] = sqrt(power((cities[i].first - cities[j].first), 2) +
					pow((cities[i].second - cities[j].second), 2));
			else // i > j
				W[i][j] = W[j][i];
		}
	}

	printf("%.9lf \n", dp(0, 1));
//	cout << dp(0, 1) << '\n';
}