#include <iostream>

using namespace std;

int N, M, K;

bool isPossible() {
    return N + M - 1 <= K;
}

void printArray() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << i + j + 1 << ' ';
        }
        cout << '\n';
    }
}
int main(void) {
    // freopen("../input", "r", stdin);

    cin >> N >> M >> K;

    if (isPossible()) {
        cout << "YES" << '\n';
        printArray();
    }
    else {
        cout << "NO" << '\n';
    }
}
