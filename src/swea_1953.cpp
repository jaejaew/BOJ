#define MAXN    51
 
#include<iostream>
#include<queue>
#include<cstring>
 
using namespace std;
 
int N, M, R, C, L;
int cnt;
int tunnel[MAXN][MAXN];
bool visited[MAXN][MAXN];
 
const bool access_out[8][4] = {
    {false, false, false, false},
    {true, true, true, true},
    {true, false, true, false},
    {false, true, false, true},
    {true, true, false, false},
    {false, true, true, false},
    {false, false, true, true},
    {true, false, false, true}
};  // [type][direction to out]
 
const bool access_in[4][8] = {
    {false, true, true, false, false, true, true, false},   // UP
    {false, true, false, true, false, false, true, true},   // RIGHT
    {false, true, true, false, true, false, false, true},   // DOWN
    {false, true, false, true, true, true, false, false}    // LEFT
};  // [direction from prev position][type]
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
 
queue<pair<pair<int, int>, int> > q;
 
inline bool in_range(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}
bool can_move(int x, int y, int direction) {
    return in_range(x, y) && !visited[x][y] && access_in[direction][tunnel[x][y]];
}
 
void init() {
    cnt = 0;
    memset(tunnel, 0, sizeof(tunnel));
    memset(visited, false, sizeof(visited));
    q = queue<pair<pair<int, int>, int> >();
 
    cin >> N >> M >> R >> C >> L;
    visited[R][C] = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> tunnel[i][j];
}
 
void start() {
    q.push(make_pair(make_pair(R, C), 1));
 
    while (!q.empty()) {
        pair<int, int> pos = q.front().first;
        int timestamp = q.front().second;
        q.pop();
 
        if (timestamp > L) continue;
        cnt++;
        int x = pos.first, y = pos.second;
 
        for (int d = 0; d < 4; d++) {
            if (!access_out[tunnel[x][y]][d])
                continue;
            int nx = x + dx[d], ny = y + dy[d];
            if (can_move(nx, ny, d)) {
                visited[nx][ny] = true;
                q.push(make_pair(make_pair(nx, ny), timestamp + 1));
            }
        }
    }
     
}
int main(int argc, char** argv)
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int test_case;
    int T;
   // freopen("./input.txt", "r", stdin);
    cin >> T;
 
    for (test_case = 1; test_case <= T; ++test_case) {
        init();
        start();
        cout << '#' << test_case << ' ' << cnt << '\n';
    }
 
    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}