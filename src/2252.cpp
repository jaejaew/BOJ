#define MAXN 32001

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;

int N, M;
vector<int> edges[MAXN];
int indeg[MAXN];
queue<int> q;
vector<int> ans;
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;	cin >> A >> B;
		indeg[B]++;
		edges[A].push_back(B);
	}

	for (int i = 1; i <= N; i++) 
		if (!indeg[i]) 
			q.push(i);

	while (!q.empty()) {
		int x = q.front();	q.pop();
		ans.push_back(x);

		for (const int& e : edges[x])
			if (--indeg[e] == 0)
				q.push(e);
	}

	for (const int& i : ans) cout << i << ' ';
}