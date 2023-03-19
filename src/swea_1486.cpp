#include <iostream>
#include <cstring>
#include <algorithm>

#define MAXN 21
using namespace std;

int N, B;
int H[MAXN];
int tail_sum[MAXN];
int ans;

void init() {
    memset(H, 0, sizeof(H));
    memset(tail_sum, 0, sizeof(tail_sum));
    cin >> N >> B;
    for (int i = 0; i < N; i++)
        cin >> H[i];
    sort(H, H + N);
    reverse(H, H + N);

    tail_sum[N - 1] = H[N - 1];
    for (int i = N - 1; i > 0; i--) {
        tail_sum[i - 1] = H[i - 1] + tail_sum[i];
    }
    ans = (1 << 26) - 1;
}

void dfs(int depth, int height) {
    if (height + tail_sum[depth] < B)
        return;
    if (depth == N) {
        if (height - B < ans) {
            ans = height - B;
        }
        return;
    }

    dfs(depth + 1, height);             // H[depth] not included
    dfs(depth + 1, height + H[depth]);  // H[depth] included
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("../input.txt", "r", stdin);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        init();
        dfs(0, 0);
        cout << '#' << t << ' ' << ans << '\n';
    }
}
