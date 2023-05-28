#define N 1000000

int segtree[N<<1|1]; /* should define as 2N*/

/* return max value within [l, r) */
int query(int l, int r) {
    int ret = -1;
    for (l += N, r += N; l != r; l>>=1, r>>=1) {
        if (l&1) {
            /* Do Task */
            l++;
        }
        if (r&1) {
            --r;
            /* Do Task */
        }
    }
    return ret;
}

void update(int i, int v) {
    segtree[i + N] = v;
    while(i>>=1)
        segtree[i] /* something with (segtree[i<<1], segtree[i<<1|1]) */;
}

void init() {
    /* We can use the range [N, 2N] as an array*/
    for (int i = 0; i < N; i++)
        segtree[i + N] /* = initialize as you want */;

    for (int i = N - 1; i != 0; i--)
        segtree[i] /* = something with (segtree[i<<1], segtree[i<<1|1]) */;
}
