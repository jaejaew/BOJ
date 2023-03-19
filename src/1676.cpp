#include<iostream>

#define MIN(x, y) ((x) < (y) ? (x) : (y))
using namespace std;

int get_exp_sum(int n, int a) {
	/* k is a power of a s.t. k <= n */
	int k = a;
	int exp_sum = 0;
	while (k <= n) {
		exp_sum += (n / k);
		k *= a;
	}
	return exp_sum;
}

int main(void) {
	int N;
	cin >> N;
	cout << MIN(get_exp_sum(N, 2), get_exp_sum(N, 5)) << endl;
	return 0;
}