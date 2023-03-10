#define MAXN			1010
#define MAXM			10100

#include<iostream>
#include<cstring>

using namespace std;

class Node {
private:
	int size;
	int edge[MAXM];
public:
	Node() {
		size = 0;
		memset(edge, 0, sizeof(edge));
	};
	void insert(int e) {
		edge[size++] = e;
	}
	void sort() {
		int tmp;
		for (int i = size - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (edge[j] > edge[j + 1]) {
					tmp = edge[j];
					edge[j] = edge[j + 1];
					edge[j + 1] = tmp;
				}
			}
		}
	}
	int getSize() {
		return size;
	}
	int getEdge(int i) {
		return edge[i];
	}
} node[MAXN];
class Queue {
private:
	int front, rear;
	int a[2*MAXN];
public: 
	Queue() {
		front = rear = 0;
		memset(a, 0, sizeof(a));
	}
	~Queue() {
		front = rear = 0;
	}
	void push(int e) {
		a[rear++] = e;
	}
	int pop() {
		if (empty()) 
			return -1;
		return a[front++];
	}
	bool empty() { return front == rear; }
} q;
bool visited[MAXN];

void DFS(int v) {
	int size = node[v].getSize();
	int curVtx;
	visited[v] = true;
	cout << v << ' ';

	for (int i = 0; i < size; i++) {
		curVtx = node[v].getEdge(i);
		if (visited[curVtx])
			continue;
		else DFS(curVtx);
	}
	return;
}

void BFS(int _v) {
	int v, curVtx;
	int size;

	visited[_v] = true;
	q.push(_v);
	while ((v = q.pop()) != -1) {
		size = node[v].getSize();
		for (int i = 0; i < size; i++) {
			curVtx = node[v].getEdge(i);
			if (visited[curVtx])
				continue;
			visited[curVtx] = true;
			q.push(curVtx);
		}
		cout << v << ' ';
	}
	return;
}
int main(void) {
	int tc;
//	freopen("input.txt", "r", stdin);
	int N, M, V;
	int s, e;
//	int T;
//	cin >> T;
//	for (tc = 1; tc <= T; tc++) {
		cin >> N >> M >> V;
		memset(visited, 0, sizeof(visited));
		q = Queue();
		memset(node, 0, sizeof(node));
		for (int i = 1; i <= M; i++) {
			cin >> s >> e;
			node[s].insert(e);
			node[e].insert(s);
		}
		for (int i = 1; i <= N; i++)
			node[i].sort();
		DFS(V);
		cout << endl;

		memset(visited, 0, sizeof(visited));
		BFS(V);
		cout << endl;
//	}
	return 0;
}