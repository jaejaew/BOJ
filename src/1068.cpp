#define MAXN 51

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<set>

using namespace std;

typedef long long ll;

struct TreeNode {
	int id;
	int parent;
	set<int> child;
} treeNode[MAXN];



int N;
int root;
int del;
int ans;

void dfs(int node) {
	if (treeNode[node].child.empty()) {
		ans++;
		return;
	}

	for (const int& c : treeNode[node].child)
		if (c != del)
			dfs(c);
}
int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/XXXX.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;	cin >> p;
		treeNode[i].id = i;
		treeNode[i].parent = p;
		if (p >= 0) 
			treeNode[p].child.insert(i);
		else root = i;
	}

	cin >> del;
	if (treeNode[del].parent == -1) {
		cout << 0;
		return 0;
	}
	treeNode[treeNode[del].parent].child.erase(del);
	dfs(root);
	cout << ans;
}