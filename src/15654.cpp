#define MAXN 8

#include <iostream>

using namespace std;

int nums[MAXN];
int path[MAXN];
bool visited[MAXN];
int N, M;


void printSequence() {
    for (int i = 0; i < M; i++)
        cout << path[i] << ' ';
    cout << '\n';
    return;
}
void dfs(int depth) {
    if (depth == M){
        printSequence();
        return;
    }

    for (int i = 0; i < N; i++){
        if(visited[i]) 
            continue;

        path[depth] = nums[i];
        visited[i] = true;
        dfs(depth + 1);
        visited[i] = false;
    }
}

int main(void) {
    freopen("../input", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    sort(nums, nums + N);

    dfs(0);
}
