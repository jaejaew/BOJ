#define MAXN 51
#define SPACE 0
#define WALL 1

#include <iostream>
#include <queue>

using namespace std;

int N, M, R, C, D;
int room[MAXN][MAXN];
queue<pair<int, int> > q;
bool cleaned[MAXN][MAXN];
int cnt;
const int rd[4] = {2, 3, 0, 1};
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

inline const bool can_move(const int x, const int y) {
    return x >= 0 && y >= 0 && x < N && y < M && room[x][y] == SPACE;
}

inline const bool can_move_to_current_direction(const int x, const int y, const int d) {
    int reverse_d = rd[d];
    const int nx = x + dx[reverse_d], ny = y + dy[reverse_d];
    return can_move(nx, ny);
}

inline const int next_direction(const int d) {
    return (d + 3) & 0x3;   //  (d+3)&0x3 == (d+3)%4 == (d-1)%4
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("../input", "r", stdin);

    cin >> N >> M;
    cin >> R >> C >> D;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    q.push(make_pair(R, C));
    while(!q.empty()) {
        const pair<int, int> pos = q.front();
        const int x = pos.first, y = pos.second;
        q.pop();

        // 1. clean this room if not cleaned
        if(!cleaned[x][y]){
            cleaned[x][y] = true;
            cnt++;
        }

        bool exists_uncleaned_room = false;
        for (int d = 0; d < 4; d++) {
            const int nx = x + dx[d], ny = y + dy[d];
            if (can_move(nx, ny) && room[nx][ny] == SPACE && !cleaned[nx][ny]) {
                // there is an uncleaned room among 4 near rooms
                exists_uncleaned_room = true;
                break;
            }
        }

        if(exists_uncleaned_room == false) {
            // 2. no uncleaned room
            if (can_move_to_current_direction(x, y, D)) {
                const int reverse_d = rd[D];
                const int nx = x + dx[reverse_d], ny = y + dy[reverse_d];
                if(room[nx][ny] == SPACE) {
                    q.push(make_pair(nx, ny));
                }
            }
        }
        else {
            // 3. uncleaned room exists
            D = next_direction(D);
            const int nx = x + dx[D], ny = y + dy[D];
            if(can_move(nx, ny) && room[nx][ny] == SPACE && !cleaned[nx][ny]) {
                q.push(make_pair(nx, ny));
            }
            else{
                q.push(make_pair(x, y));
            }
        }
    }

    cout << cnt << '\n';
}
