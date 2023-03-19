#define MAXN	100'100

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int parent[MAXN];
int gates[MAXN];
int G, P;

int find(int x) {
	int& p = parent[x];
	if (p == x) return x;
	return (p = find(p));
}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
//	freopen("./input/10775.txt", "r", stdin);
	memset(parent, 0, sizeof(parent));
	cin >> G >> P;

	for (int i = 1; i <= G; i++)
		parent[i] = i;

	for (int i = 1; i <= P; i++) {
		cin >> gates[i];
	}

	int ans = 0;

	for (int i = 1; i <= P; i++) {
		int g = find(gates[i]);
		if (g <= 0) break;
		parent[g] = parent[g - 1];
		ans++;
	}

	cout << ans;
}