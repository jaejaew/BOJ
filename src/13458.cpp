#define MAXN 1'000'000
#include <iostream>


using namespace std;

typedef long long ll;
int N, B, C;
int A[MAXN];
ll cnt;
int main(void) {
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("../input", "r", stdin);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        A[i] -= B;
        if (A[i] >= C){
            int q = A[i] / C;
            cnt += q;
            A[i] -= (C * q);
        }
        if (A[i] > 0) ++cnt;
    }
    cnt += N;

    cout << cnt;
}
