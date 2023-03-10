#define MAXN 27
#define OFFSET ('A'-1)

#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int N;
struct Node {
	char c;
	int lc;
	int rc;
} tree[MAXN << 2];

void dfs(int node, int order) {
	if (node < 0 || node > N) return;
	if (tree[node].c == 0) return;
	if (order == 0)
		cout << tree[node].c;

	if (tree[node].lc != 0)
		dfs(tree[node].lc, order);

	if (order == 1)
		cout << tree[node].c;

	if (tree[node].rc != 0)
		dfs(tree[node].rc, order);

	if (order == 2)
		cout << tree[node].c;
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/1991.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		char ch; cin >> ch;
		int node = ch - OFFSET;
		char lc, rc;	cin >> lc >> rc;
		tree[node].c = ch;
		if (tree[node].lc != '.')
			tree[node].lc = lc - OFFSET;

		if (tree[node].rc != '.')
			tree[node].rc = rc - OFFSET;
	}

	for (int i = 0; i < 3; i++) {
		dfs(1, i);
		cout << '\n';
	}

}