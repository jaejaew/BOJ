#define MAXN 1010

#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

bool visited[MAXN];

class Node {
public:
    vector<int> a;
    //    Node(){a=vector<int>(100);}
    bool empty() { return a.empty(); }
    void push(int e) { a.push_back(e); }
} node[MAXN];

void dfs(int v) {
    vector<int>::iterator it;
    if (visited[v]) return;
    visited[v] = true;

    for (it = node[v].a.begin(); it != node[v].a.end(); it++) {
        if (!visited[(*it)])
            dfs((*it));
    }

}

int main(void) {
    //   freopen("./input/11724.txt", "r", stdin);
    int N, M;
    int s, e;
    int cnt = 0;
    cin >> N >> M;

    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < M; i++) {
        cin >> s >> e;
        node[s].push(e);
        node[e].push(s);
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }


    cout << cnt << '\n';
    return 0;
}