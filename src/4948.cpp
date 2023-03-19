#define MAXN    125000
#define PRIME   1
#define COMPO   2
#define UNKNOWN 0
#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

char valid[2 * MAXN];
bool isPrime(const int n) {
    if (valid[n] == PRIME)
        return true;
    else if (valid[n] == COMPO)
        return false;
    else { /* UNKNOWN */
        int i;
        int sq = floor(sqrt(n));
        for (i = 2; i <= sq; i++) {
            if (n % i == 0) { /* composition */
                valid[n] = COMPO;
                return false;
            }
        }
        valid[n] = PRIME;
        return true;
    }
}
int main(void) {
    int N;
    int cnt;

    memset(valid, 0, sizeof(valid));
    while (true) {
        cin >> N;
        if (N == 0) break;
        cnt = 0;
        for (int i = N + 1; i <= 2 * N; i++)
            if (isPrime(i)) cnt++;
        cout << cnt << '\n';
    }
}