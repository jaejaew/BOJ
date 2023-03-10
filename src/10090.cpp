#define MAXN 100100

#include<iostream>
#include<cstring>

using namespace std;

int N;
int A[MAXN], buffer[MAXN];
long long cnt;

void merge(int s, int e) {
    if (s == e) return;
    long long m = (s + e) / 2;
    long long i = s, j = m + 1, k = s;
    while (i <= m && j <= e) {
        if (A[i] < A[j]) {
            buffer[k++] = A[i++];
        }
        else {
            cnt += (m - i + 1);
            buffer[k++] = A[j++];
        }
    }

    while (i <= m) {
        buffer[k++] = A[i++];
    }
    while (j <= e) {
        buffer[k++] = A[j++];
        //    cnt += (m-i+1);
    }

    for (int l = s; l <= e; l++)
        A[l] = buffer[l];
    //    cout << "start: " << s << ", end: " << e << '\n';
    //    cout << "cnt: " << cnt << '\n';
}
void mergeSort(int s, int e) {
    int m = (s + e) / 2;
    if (s >= e) return;
    mergeSort(s, m);
    mergeSort(m + 1, e);
    merge(s, e);
}
long long run() {
    mergeSort(0, N - 1);
    return cnt;
}

void init() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cnt = 0;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;

    freopen("./input/10090.txt", "r", stdin);

    init();
    cout << run() << '\n';

    return 0;
}