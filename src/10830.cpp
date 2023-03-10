#define MAXN	5
#define MAXMAT	100
#include<iostream>
#include<cstring>
#include<vector>
#include<map>

using namespace std;

typedef long long ll;

map<ll, int> memo;
int mat[MAXMAT][MAXN][MAXN];
int A[MAXN][MAXN];
int matCnt;
int N;
ll B;

int mat_prod(int idx1, int idx2) {
	
}

int getPower(ll x) {
	auto it = memo.find(x);
	if (it != memo.end()) return it->second;
	if (x == 1LL) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mat[matCnt][i][j] = A[i][j];
		memo[x] = matCnt;
		return matCnt++;
	}

	int t = getPower(x >> 1);

}

int main(void) {
	cin.tie(NULL)->sync_with_stdio(false);
	//	freopen("./input/10830.txt", "r", stdin);

	cin >> N;
	cin >> B;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];

}