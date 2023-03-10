#include<iostream>
#include<cstring>
using namespace std;

long long pinary[100][2];

int main(void) {
	int N, i;
	cin >> N;

	memset(pinary, 0, sizeof(pinary));
	pinary[1][0] = 0;	pinary[1][1] = 1;
	for (i = 2; i <= N; i++) {
		pinary[i][0] = pinary[i - 1][0] + pinary[i - 1][1];
		pinary[i][1] = pinary[i - 1][0];
	}
	cout << pinary[N][0] + pinary[N][1];
}