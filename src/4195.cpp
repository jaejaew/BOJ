#define MAXF	200'100
#define MAXLEN	21
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

int F;
int parent[MAXF];
int strCnt;

struct TrieNode {
	map<char, TrieNode*> child;
	int strIdx;
} trieNode[MAXF];
int trieNodeCnt;
TrieNode* getTrieNode() {
	TrieNode* ptr = &trieNode[trieNodeCnt++];
	ptr->child.clear();
	ptr->strIdx = -1;
	return ptr;
}

class Trie {
public:
	TrieNode* root;

	void init() {
		root = getTrieNode();
	}

	int insert(string s) {
		TrieNode* ptr = root;
		for (const char& c : s) {
			if (ptr->child.find(c) == ptr->child.end())
				ptr->child[c] = getTrieNode();
			ptr = ptr->child[c];
		}
		return (ptr->strIdx = strCnt++);
	}

	int find(string s) {
		TrieNode* ptr = root;
		for (const char& c : s) {
			if (ptr->child.find(c) == ptr->child.end())
				return -1;
			ptr = ptr->child[c];
		}
		return ptr->strIdx;
	}
} trie;

map<string, int> nametoIDX;

int find(int x) {
	int& p = parent[x];
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


void init() {
	memset(parent, -1, sizeof(parent));
	trieNodeCnt = 0;	strCnt = 0;
//	trie.init();
	nametoIDX.clear();
}


int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	freopen("./input/4195.txt", "r", stdin);

	int T;

	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> F;
		for (int i = 0; i < F; i++) {
			string a, b;
			cin >> a >> b;
			int ia, ib;
			if (nametoIDX.find(a) == nametoIDX.end()) nametoIDX[a] = strCnt++;
			if (nametoIDX.find(b) == nametoIDX.end()) nametoIDX[b] = strCnt++;
			ia = nametoIDX[a];	ib = nametoIDX[b];

		//	if ((ia = trie.find(a)) == -1) ia = trie.insert(a);
		//	if ((ib = trie.find(b)) == -1) ib = trie.insert(b);

			weightedUnion(ia, ib);
			cout << -parent[find(ia)] << '\n';
		}
	}

}