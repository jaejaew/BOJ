#include <iostream>
#define MAXN 101
#define MAXDIGIT 101
using namespace std;

typedef long long ll;

int N, M, K;
int dp[MAXN][MAXN][MAXDIGIT];   //  dp[n][m] represents big integer with max digit 101
bool visited[MAXN][MAXN];       //  dp[n][m] has already been calculated?
int result[MAXDIGIT];

void bigIntToArray(int n, int a[]) {
    for (int digit = 0; n > 0; digit++, n/=10)
        a[digit] = n % 10;
}

void getComb(int n, int m) {
    if (n <= 0 || m <= 0 || n < m) {
        visited[n][m] = true;
        return;
    }
    if (visited[n][m])
        return;
    if (visited[n-1][m-1])
        getComb(n - 1, m - 1);
    if (visited[n-1][m])
        getComb(n - 1, m);

    // dp[n][m] = dp[n-1][m-1] + dp[n-1][m]
    // using bigIntToArray function    
}

int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("../input", "r", stdin);

    cin >> N >> M;
    if(M > N-M)
        M = N - M;
    cout << getComb(N, M) << '\n';
}
