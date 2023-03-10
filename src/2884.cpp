#include<iostream>

using namespace std;

int main(void) {
	int H, M, carry=0;
	cin >> H >> M;

	M += 15;
	if (M >= 60) {
		M -= 60;
		carry = 1;
	}

	H = H - 1 + carry;
	if (H < 0)
		H += 24;
	cout << H << ' ' << M << endl;

	return 0;
}