#define MAXN    51

#define UP      0
#define RIGHT   1
#define DOWN    2
#define LEFT    3

#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int N, M, R, C, L;
int cnt;
int tunnel[MAXN][MAXN];
bool visited[MAXN][MAXN];
bool access[4][8] = {
    {false, true, true, false, false, true, true, false},   // UP
    {false, true, false, true, false, false, true, true},   // RIGHT
    {false, true, true, false, true, false, false, true},   // DOWN
    {false, true, false, true, true, true, false, false}    // LEFT
};  // [direction][next_type]
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int> > q;

inline bool in_range(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < M;
}
bool can_move(int x, int y, int direction) {
    return in_range(x, y) && !visited[x][y] && tunnel[x][y] > 0 && access[direction][tunnel[x][y]];
}

void init() {
    cnt = 0;
    memset(tunnel, 0, sizeof(tunnel));
    memset(visited, false, sizeof(visited));
    q = queue<pair<int, int> >();

    cin >> N >> M >> R >> C >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> tunnel[i][j];
}

void start() {
    q.push(make_pair(R, C));

    for (int timestamp = 1; timestamp <= L; timestamp++){
        while (!q.empty()) {
            pair<int, int> pos = q.front();
            int x = pos.first, y = pos.second;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (can_move(nx, ny, d)) {
                    visited[nx][ny] = true;
                    cnt++;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}
int main(int argc, char** argv)
{
    // cin.tie(nullptr)->sync_with_stdio(false);
    int test_case;
    int T;
    // freopen("../input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        init();
        start();
        cout << '#' << test_case << ' ' << cnt << '\n';
    }

    return 0;  // 정상종료시 반드시 0을 리턴해야합니다.
}